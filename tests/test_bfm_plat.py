"""bfm_plat platform layer: config, backends, storage, mods, plugins, cheats.

Builds without SDL/OpenAL/GL. The disc images here are synthetic ISO9660
images generated below; no retail data is used.
"""
import os
from pathlib import Path
import shutil
import struct
import subprocess
import tempfile
import unittest
import zlib

ROOT = Path(__file__).resolve().parents[1]
PLAT = ROOT / "pc_port/platform"
CFLAGS = ["-std=c99", "-Wall", "-Wextra", "-Werror", "-pedantic", "-O0", "-g"]
FILE_TEXT = b"Hello from a synthetic disc"


def fnv1a64(data: bytes) -> int:
    h = 0xCBF29CE484222325
    for b in data:
        h ^= b
        h = (h * 0x100000001B3) & 0xFFFFFFFFFFFFFFFF
    return h


def texture_hash(w: int, h: int, pixels) -> str:
    raw = struct.pack("<HH", w, h) + b"".join(struct.pack("<H", p) for p in pixels)
    return "%016x" % fnv1a64(raw)


def bfmi(w: int, h: int, rgba: bytes) -> bytes:
    return b"BFMI" + struct.pack("<HH", w, h) + rgba


# ---------------------------------------------------------- ISO9660 builder

def _both16(v):
    return struct.pack("<H", v) + struct.pack(">H", v)


def _both32(v):
    return struct.pack("<I", v) + struct.pack(">I", v)


def _dirrec(name: bytes, lba: int, size: int, is_dir: bool) -> bytes:
    body = (_both32(lba) + _both32(size) + bytes(7) +
            bytes([2 if is_dir else 0, 0, 0]) + _both16(1) +
            bytes([len(name)]) + name)
    rec = bytes([0, 0]) + body
    if len(rec) % 2:
        rec += b"\0"
    rec = bytes([len(rec)]) + rec[1:]
    return rec


def build_iso(file_data: bytes) -> bytes:
    sectors = [bytes(2048)] * 16
    root_lba, data_lba, file_lba = 18, 19, 20
    pvd = bytearray(2048)
    pvd[0] = 1
    pvd[1:6] = b"CD001"
    pvd[6] = 1
    pvd[156:156 + 34] = _dirrec(b"\0", root_lba, 2048, True)
    term = bytearray(2048)
    term[0] = 255
    term[1:6] = b"CD001"
    root = (_dirrec(b"\0", root_lba, 2048, True) +
            _dirrec(b"\1", root_lba, 2048, True) +
            _dirrec(b"DATA", data_lba, 2048, True))
    data = (_dirrec(b"\0", data_lba, 2048, True) +
            _dirrec(b"\1", root_lba, 2048, True) +
            _dirrec(b"HELLO.TXT;1", file_lba, len(file_data), False))
    sectors += [bytes(pvd), bytes(term), root.ljust(2048, b"\0"),
                data.ljust(2048, b"\0"), file_data.ljust(2048, b"\0")]
    return b"".join(sectors)


def _bcd(v):
    return ((v // 10) << 4) | (v % 10)


def iso_to_raw(iso: bytes) -> bytes:
    out = bytearray()
    for i in range(len(iso) // 2048):
        a = i + 150
        hdr = bytes([_bcd(a // 4500), _bcd((a // 75) % 60), _bcd(a % 75), 2])
        out += b"\0" + b"\xff" * 10 + b"\0" + hdr + bytes(8)
        out += iso[i * 2048:(i + 1) * 2048] + bytes(280)
    return bytes(out)


# --------------------------------------------------------------- PNG writer

def _paeth(a, b, c):
    p = a + b - c
    pa, pb, pc = abs(p - a), abs(p - b), abs(p - c)
    if pa <= pb and pa <= pc:
        return a
    return b if pb <= pc else c


def _filter_row(ftype, row, prev, bpp):
    out = bytearray()
    for i, x in enumerate(row):
        a = row[i - bpp] if i >= bpp else 0
        b = prev[i] if prev else 0
        c = prev[i - bpp] if prev and i >= bpp else 0
        pred = [0, a, b, (a + b) >> 1, _paeth(a, b, c)][ftype]
        out.append((x - pred) & 0xFF)
    return bytes([ftype]) + bytes(out)


def _chunk(t, body):
    return (struct.pack(">I", len(body)) + t + body +
            struct.pack(">I", zlib.crc32(t + body) & 0xFFFFFFFF))


def make_png(w, h, ctype, depth, rows, plte=None, trns=None, interlace=0):
    """rows: list of raw (unfiltered) scanline bytes."""
    channels = {0: 1, 2: 3, 3: 1, 4: 2, 6: 4}[ctype]
    bpp = max(1, channels * depth // 8)
    data, prev = b"", None
    for y, row in enumerate(rows):
        data += _filter_row(y % 5, row, prev, bpp)
        prev = row
    out = b"\x89PNG\r\n\x1a\n"
    out += _chunk(b"IHDR", struct.pack(">IIBBBBB", w, h, depth, ctype, 0, 0, interlace))
    if plte:
        out += _chunk(b"PLTE", plte)
    if trns:
        out += _chunk(b"tRNS", trns)
    out += _chunk(b"tEXt", b"Comment\0ancillary chunks are skipped")
    z = zlib.compress(data)
    out += _chunk(b"IDAT", z[:5]) + _chunk(b"IDAT", z[5:])   # split IDAT
    out += _chunk(b"IEND", b"")
    return out


def _pack_bits(indices, depth):
    out, acc, n = bytearray(), 0, 0
    for i in indices:
        acc = (acc << depth) | i
        n += depth
        if n == 8:
            out.append(acc)
            acc, n = 0, 0
    if n:
        out.append(acc << (8 - n))
    return bytes(out)


def png_cases():
    """(name, png bytes, width, height, expected RGBA bytes)."""
    cases = []
    w, h = 5, 6
    rgba = [[((x * 50) & 255, (y * 40) & 255, (x * y * 7) & 255, (x * 30 + y * 5) & 255)
             for x in range(w)] for y in range(h)]
    flat = lambda px: b"".join(bytes(p) for row in px for p in row)
    cases.append(("rgba8", make_png(w, h, 6, 8, [b"".join(bytes(p) for p in r) for r in rgba]),
                  w, h, flat(rgba)))
    rgb = [[p[:3] for p in r] for r in rgba]
    key = rgb[2][3]
    exp = [[p + ((0,) if p == key else (255,)) for p in r] for r in rgb]
    cases.append(("rgb8_trns", make_png(w, h, 2, 8, [b"".join(bytes(p) for p in r) for r in rgb],
                                        trns=struct.pack(">HHH", *key)), w, h, flat(exp)))
    rows16 = [b"".join(struct.pack(">HHH", p[0] * 257 + 1, p[1] * 257, p[2] * 257) for p in r)
              for r in rgb]
    exp16 = [[p + (255,) for p in r] for r in rgb]
    cases.append(("rgb16", make_png(w, h, 2, 16, rows16), w, h, flat(exp16)))
    grey = [[(x * 60 + y) & 255 for x in range(w)] for y in range(h)]
    cases.append(("grey8", make_png(w, h, 0, 8, [bytes(r) for r in grey]), w, h,
                  flat([[(g, g, g, 255) for g in r] for r in grey])))
    ga = [[((x * 60) & 255, (y * 50) & 255) for x in range(w)] for y in range(h)]
    cases.append(("greyalpha8", make_png(w, h, 4, 8, [b"".join(bytes(p) for p in r) for r in ga]),
                  w, h, flat([[(g, g, g, a) for g, a in r] for r in ga])))
    for depth in (1, 2, 4, 8):
        n = 1 << depth if depth < 8 else 7
        pal = [((i * 37) & 255, (i * 91) & 255, (i * 13) & 255) for i in range(n)]
        idx = [[(x + y * 3) % n for x in range(w)] for y in range(h)]
        alpha = bytes([0] + [200] * (n - 2))     # shorter than palette: rest opaque
        exp = [[pal[i] + ((alpha[i],) if i < len(alpha) else (255,)) for i in r] for r in idx]
        cases.append((f"palette{depth}", make_png(w, h, 3, depth,
                                                  [_pack_bits(r, depth) for r in idx],
                                                  plte=b"".join(bytes(p) for p in pal),
                                                  trns=alpha), w, h, flat(exp)))
    return cases


def read_png_rgb(path):
    """Minimal PNG reader for the port's own screenshots (filter 0 rows)."""
    data = Path(path).read_bytes()
    assert data[:8] == b"\x89PNG\r\n\x1a\n"
    pos, idat, w = 8, b"", 0
    while pos < len(data):
        n, t = struct.unpack(">I4s", data[pos:pos + 8])
        body = data[pos + 8:pos + 8 + n]
        crc = struct.unpack(">I", data[pos + 8 + n:pos + 12 + n])[0]
        assert zlib.crc32(t + body) & 0xFFFFFFFF == crc, t
        if t == b"IHDR":
            w, h, depth, ctype = struct.unpack(">IIBB", body[:10])
            assert (depth, ctype) == (8, 2)
        elif t == b"IDAT":
            idat += body
        pos += 12 + n
    raw = zlib.decompress(idat)
    stride = w * 3
    rows = [raw[y * (stride + 1):(y + 1) * (stride + 1)] for y in range(h)]
    assert all(r[0] == 0 for r in rows)
    return w, h, b"".join(r[1:] for r in rows)


# Known hook sites pinned to their symbols. Changing a site means changing
# this table and its evidence together.
KNOWN_SITES = {
    ("8004923c", "-", "projection"): ("func_8004923C", "high"),
    ("8004921c", "-", "projection"): ("func_8004921C", "high"),
    ("800189a8", "-", "frame_begin"): ("func_800189A8", "high"),
    ("800184f0", "-", "frame_end"): ("func_800184F0", "high"),
    ("80128158", "SC*", "room_enter"): ("func_80128158", "medium"),
    ("80011b7c", "-", "room_exit"): ("func_80011B7C", "low"),
    ("8002b0b4", "-", "save"): ("func_8002B0B4", "medium"),
    ("8002b0b4", "-", "load"): ("func_8002B0B4", "medium"),
}
UNSITED = ["battle_start", "battle_end", "item_get"]

# (vendor/bfm-decomp path, line, text that line must contain): each is
# cited in the sites' evidence strings.
VENDOR_EVIDENCE = [
    ("src/boot.c", 277, "void main(void)"),
    ("src/boot.c", 310, "func_800189A8();"),
    ("src/boot.c", 372, "func_800184F0();"),
    ("src/boot.c", 374, "VSync(*(s32 *)(p + 0xA3E8));"),
    ("src/800.c", 6042, "void func_800189A8(void)"),
    ("src/800.c", 6094, "PadGetState(chan)"),
    ("src/800.c", 5761, "void func_800184F0(void)"),
    ("src/md_MAIN_003/md_MAIN_003_jr_800D1E18.c", 236, "func_800189A8();"),
    ("src/resident/resident.c", 255, "func_80128158();"),
    ("src/resident/resident.c", 261, "func_80011B7C(8);"),
    ("src/boot.c", 950, "void func_80011B7C(arg0)"),
    ("src/800_b.c", 87, "s32 func_8002B0B4(s32 sel, s32 idx, u8 *out)"),
    ("src/800_b.c", 301, "case 13:"),
    ("src/800_b.c", 318, "func_80060614(D_80075CC0, idx * 0x300 + 0x480, 0x300);"),
    ("src/800_b.c", 486, "case 17:"),
    ("src/800_b.c", 487, "case 32:"),
    ("src/800_b.c", 488, "func_80060404(D_80075CC0, idx * 0x300 + 0x480, 0x300);"),
    ("src/800.c", 1787, "func_8004923C(0x3E8);"),
    ("src/shared/ov/func_8017C530.h", 14, "func_8004921C(ofx, ofy);"),
    ("config/symbols.us.txt", 14, "main                             = 0x80010178; // func"),
    ("config/symbols.us.txt", None, "GameModeDispatch                 = 0x80010B40;"),
]


def vendor_root():
    for base in (ROOT, Path("/home/blizz/dev/brave-fencer-musashi-decomp")):
        v = base / "vendor/bfm-decomp"
        if (v / "src/boot.c").is_file():
            return v
    return None


class BfmPlatTests(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        temp = tempfile.TemporaryDirectory(prefix="bfm-plat-")
        cls.addClassCleanup(temp.cleanup)
        cls.tmp = Path(temp.name)
        cls.probe = cls.tmp / "bfm_plat_probe"
        sources = sorted(str(p) for p in PLAT.glob("bfm_plat*.c"))
        subprocess.run(["cc", *CFLAGS, "-I", str(PLAT), *sources,
                        str(ROOT / "tests/bfm_plat_probe.c"), "-o",
                        str(cls.probe), "-ldl", "-lm"],
                       check=True, stdin=subprocess.DEVNULL, timeout=120)
        cls.png_probe = cls.tmp / "bfm_plat_png_probe"
        subprocess.run(["cc", *CFLAGS, "-DBFM_PLAT_WITH_PNG", "-I", str(PLAT),
                        *sources, str(PLAT / "backends/texture_png.c"),
                        str(ROOT / "tests/bfm_plat_probe.c"), "-o",
                        str(cls.png_probe), "-ldl", "-lz", "-lm"],
                       check=True, stdin=subprocess.DEVNULL, timeout=120)
        cls.plugin = cls.tmp / "hello_plugin.so"
        subprocess.run(["cc", *CFLAGS, "-shared", "-fPIC", "-I", str(PLAT),
                        str(ROOT / "pc_port/mods/examples/hello/hello_plugin.c"),
                        "-o", str(cls.plugin)],
                       check=True, stdin=subprocess.DEVNULL, timeout=60)

    def run_probe(self, *args, env=None, probe=None):
        proc = subprocess.run([str(probe or self.probe), *map(str, args)],
                              capture_output=True, text=True, timeout=60,
                              env=env, stdin=subprocess.DEVNULL)
        self.assertEqual(proc.returncode, 0, proc.stdout + proc.stderr)
        self.assertIn("ok " + args[0], proc.stdout)
        return proc.stdout

    def fresh(self, name):
        d = self.tmp / name
        if d.exists():
            shutil.rmtree(d)
        d.mkdir(parents=True)
        return d

    # ------------------------------------------------------------ groups

    def test_hash_matches_reference_fnv1a64(self):
        self.run_probe("hash")
        self.assertEqual("%016x" % fnv1a64(b"foobar"), "85944171f73967e8")

    def test_config_file_args_and_default_path(self):
        d = self.fresh("config")
        env = dict(os.environ, XDG_CONFIG_HOME=str(d / "xdg"))
        env.pop("BFM_PORT_CONFIG", None)
        out = self.run_probe("config", d, env=env)
        self.assertIn(f"path {d}/xdg/bfm-port/config.ini", out)
        env["BFM_PORT_CONFIG"] = "/custom/cfg.ini"
        self.assertIn("path /custom/cfg.ini", self.run_probe("config", d, env=env))
        saved = (d / "saved.ini").read_text()
        self.assertIn("[mod.hello]\ngreeting = hi there", saved)

    def test_renderer_null_backend_and_fallback(self):
        self.run_probe("renderer")

    def test_input_wire_format_hotkeys_and_fast_forward(self):
        self.run_probe("input")

    def test_timing_pacer_with_injected_clock(self):
        self.run_probe("timing")

    def test_audio_null_backend(self):
        self.run_probe("audio")

    def test_storage_iso_raw_bin_and_cue(self):
        d = self.fresh("storage")
        iso = build_iso(FILE_TEXT)
        (d / "game.iso").write_bytes(iso)
        (d / "game.bin").write_bytes(iso_to_raw(iso))
        (d / "game.cue").write_text(
            'FILE "game.bin" BINARY\n  TRACK 01 MODE2/2352\n    INDEX 01 00:00:00\n')
        (d / "saves").mkdir()
        out = self.run_probe("storage", d / "game.iso", FILE_TEXT.decode(), d / "saves")
        self.assertIn("sectors 21 size 2048 tracks 1", out)
        out = self.run_probe("storage", d / "game.bin", FILE_TEXT.decode(), d / "saves")
        self.assertIn("sectors 21 size 2352", out)
        out = self.run_probe("storage", d / "game.cue", FILE_TEXT.decode(), d / "saves")
        self.assertIn("sectors 21 size 2352 tracks 1", out)
        self.assertEqual((d / "saves/bfm_card1.mcd").stat().st_size, 128 * 1024)
        self.assertFalse((d / "saves/bfm_card1.mcd.tmp").exists())

    def test_disc_file_replacement_by_hash(self):
        d = self.fresh("filerep")
        (d / "game.iso").write_bytes(build_iso(FILE_TEXT))
        files = d / "mods/patch/assets/files"
        files.mkdir(parents=True)
        (d / "mods/patch/mod.ini").write_text("[mod]\nname = patch\n")
        out = self.run_probe("file_replace", d / "game.iso", d / "mods")
        self.assertIn("file " + FILE_TEXT.decode(), out)
        (files / ("%016x.txt" % fnv1a64(FILE_TEXT))).write_bytes(b"Patched text")
        out = self.run_probe("file_replace", d / "game.iso", d / "mods")
        self.assertIn("file Patched text", out)

    def test_texture_replacement_same_size_hd_and_dump(self):
        d = self.fresh("tex")
        pixels = [0x1234, 0x0001, 0x7FFF, 0x0000]
        h = texture_hash(2, 2, pixels)
        out = self.run_probe("texture", d / "mods")
        self.assertIn("hash " + h, out)
        self.assertIn("vram 1234 0001 7fff 0000 replaced 0", out)

        tex = d / "mods/hd/assets/textures"
        tex.mkdir(parents=True)
        (d / "mods/hd/mod.ini").write_text("[mod]\nname = hd\n")
        # Same-size replacement: red, opaque black, white, transparent.
        rgba = bytes([255, 0, 0, 255, 0, 0, 0, 255, 255, 255, 255, 255, 0, 0, 0, 0])
        (tex / f"{h}.bfmi").write_bytes(bfmi(2, 2, rgba))
        out = self.run_probe("texture", d / "mods")
        self.assertIn("vram 001f 8000 7fff 0000 replaced 1", out)

        # A later-loading mod with a 2x HD version wins, but the null backend
        # has no HD path, so VRAM keeps the original upload.
        tex2 = d / "mods/zz_hd2x/assets/textures"
        tex2.mkdir(parents=True)
        (d / "mods/zz_hd2x/mod.ini").write_text("[mod]\nname = hd2x\npriority = 200\n")
        (tex2 / f"{h}.bfmi").write_bytes(bfmi(4, 4, bytes(64)))
        out = self.run_probe("texture", d / "mods")
        self.assertIn("vram 1234 0001 7fff 0000 replaced 0", out)

        # Bad-size replacement is ignored.
        (tex2 / f"{h}.bfmi").write_bytes(bfmi(3, 2, bytes(24)))
        out = self.run_probe("texture", d / "mods")
        self.assertIn("vram 1234 0001 7fff 0000 replaced 0", out)

        dump = d / "dump"
        shutil.rmtree(d / "mods")
        self.run_probe("texture", d / "mods", dump)
        dumped = (dump / "textures" / f"{h}.bfmi").read_bytes()
        self.assertEqual(dumped[:8], bfmi(2, 2, b""))
        self.assertEqual(len(dumped), 8 + 16)
        self.assertEqual(dumped[8 + 12:], bytes(4))   # 0x0000 -> transparent

    def test_mods_loader_plugin_cheats_console(self):
        d = self.fresh("mods")
        mods = d / "mods"
        hello = mods / "hello"
        hello.mkdir(parents=True)
        src = ROOT / "pc_port/mods/examples/hello"
        shutil.copy(src / "mod.ini", hello)
        shutil.copy(self.plugin, hello / "hello_plugin.so")
        (hello / "cheats.ini").write_text(
            "[cheat hp_lock]\ndescription = test poke\naddress = 0x80001234\n"
            "value = 0x63\nwidth = 2\nenabled = 1\n"
            "[cheat bad_width]\naddress = 0x80000000\nvalue = 1\nwidth = 3\n")
        (mods / "static").mkdir()
        (mods / "static/mod.ini").write_text(
            "[mod]\nname = static\npriority = 10\nplugin = builtin_static\n")
        (mods / "scripted").mkdir()
        (mods / "scripted/mod.ini").write_text(
            "[mod]\nname = scripted\npriority = 300\nscript = main.lua\n")
        (mods / "scripted/main.lua").write_text("-- placeholder\n")
        (mods / "off").mkdir()
        (mods / "off/mod.ini").write_text("[mod]\nname = off\nenabled = 0\nplugin = nope\n")
        (mods / "evil").mkdir()
        (mods / "evil/mod.ini").write_text("[mod]\nname = evil\nplugin = ../../x\n")
        (mods / "not_a_mod").mkdir()          # no manifest: skipped
        out = self.run_probe("mods", mods)
        lines = [l for l in out.splitlines() if l.startswith("mod ")]
        names = [l.split()[2] for l in lines]
        self.assertEqual(names, ["static", "evil", "hello", "off", "scripted"])
        self.assertIn("mod 2 hello prio=100 enabled=1 plugin=1 script=0 cheats=1", out)
        self.assertIn("mod 1 evil prio=100 enabled=1 plugin=-1", out)
        self.assertIn("mod 3 off prio=100 enabled=0 plugin=0", out)
        self.assertIn("mod 4 scripted prio=300 enabled=1 plugin=0 script=1", out)
        self.assertIn("hello-reply howdy: 0 frames, 0 rooms", out)
        self.assertIn("ok-shutdown", out)

    def test_input_bindings_from_config(self):
        self.run_probe("bindings")

    def test_console_text_front_end(self):
        self.run_probe("console_ui")

    def test_game_event_catalog_and_hook_sites(self):
        self.run_probe("hooks")

    def test_png_decoder_all_color_types_depths_and_filters(self):
        d = self.fresh("png")
        for name, data, w, h, expected in png_cases():
            path = d / f"{name}.png"
            path.write_bytes(data)
            out = self.run_probe("png", path, probe=self.png_probe)
            self.assertIn(f"png {w} {h} {expected.hex()}", out, name)

    def test_png_decoder_refuses_bad_files(self):
        d = self.fresh("pngbad")
        good = png_cases()[0][1]
        bad_crc = bytearray(good)
        bad_crc[30] ^= 0xFF                       # inside IHDR body
        interlaced = make_png(1, 1, 6, 8, [bytes(4)], interlace=1)
        cases = {
            "crc": (bytes(bad_crc), -3),
            "truncated": (good[:-20], -3),
            "signature": (b"NOTAPNG!" + good[8:], -3),
            "interlaced": (interlaced, -2),
            "no_palette": (make_png(1, 1, 3, 8, [b"\0"]), -3),
        }
        for name, (data, code) in cases.items():
            (d / f"{name}.png").write_bytes(data)
            out = self.run_probe("png", d / f"{name}.png", probe=self.png_probe)
            self.assertIn(f"png error {code}", out, name)

    def test_png_texture_replacement_through_mods(self):
        d = self.fresh("pngtex")
        h = texture_hash(2, 2, [0x1234, 0x0001, 0x7FFF, 0x0000])
        tex = d / "mods/pngmod/assets/textures"
        tex.mkdir(parents=True)
        (d / "mods/pngmod/mod.ini").write_text("[mod]\nname = pngmod\n")
        rows = [bytes([255, 0, 0, 255, 0, 0, 0, 255]), bytes([255, 255, 255, 255, 0, 0, 0, 0])]
        (tex / f"{h}.png").write_bytes(make_png(2, 2, 6, 8, rows))
        out = self.run_probe("texture_png", d / "mods", probe=self.png_probe)
        self.assertIn("vram 001f 8000 7fff 0000 replaced 1", out)
        # Without the PNG decoder registered, .png replacements are ignored.
        out = self.run_probe("texture", d / "mods")
        self.assertIn("replaced 0", out)

    def test_known_hook_sites_pinned_to_symbols(self):
        out = self.run_probe("sites")
        sites = {}
        for line in out.splitlines():
            parts = line.split()
            if parts[:1] == ["site"]:
                sites[(parts[1], parts[2], parts[3])] = (parts[4], parts[5])
        self.assertEqual(sites, KNOWN_SITES)
        unsited = [l.split()[1] for l in out.splitlines() if l.startswith("unsited ")]
        self.assertEqual(unsited, UNSITED)
        evidence = " ".join(l for l in out.splitlines() if l.startswith("evidence "))
        for path, line, _ in VENDOR_EVIDENCE:
            if line is not None and path.startswith("src/"):
                self.assertIn(f"{path}:{line}" if path != "src/800_b.c" or line not in (486, 487, 488)
                              else "src/800_b.c:486-488", evidence)
        # The repository file the room-enter evidence cites.
        disp = (ROOT / "src/overlays/main_0012/80128288.c").read_text()
        self.assertIn("D_8017E618[D_800B99F6]();", disp)
        # Repository files the projection evidence cites.
        self.assertIn("ctc2 $a0, $26", (ROOT / "src/main/8004923c.c").read_text())
        off = (ROOT / "src/main/8004921c.c").read_text()
        self.assertIn("ctc2 $a0, $24", off)
        self.assertIn("ctc2 $a1, $25", off)
        self.assertIn("func_8004921C(", (ROOT / "src/main/80052bec.c").read_text())
        self.assertIn("func_8004923C(0x3E8);", (ROOT / "src/main/80014444.c").read_text())

    def test_hook_site_evidence_matches_vendor_source(self):
        v = vendor_root()
        if v is None:
            self.skipTest("vendor/bfm-decomp not present")
        for path, line, text in VENDOR_EVIDENCE:
            lines = (v / path).read_text(errors="replace").splitlines()
            if line is None:
                self.assertTrue(any(text in l for l in lines), (path, text))
            else:
                self.assertIn(text, lines[line - 1], (path, line))

    def test_hook_site_fills_and_frame_actions(self):
        self.run_probe("hook_fills")

    def test_pause_screenshot_and_quit(self):
        d = self.fresh("shots")
        out = self.run_probe("pause_screenshot", d)
        self.assertIn(f"shot {d}/bfm_00000.png", out)
        w, h, rgb = read_png_rgb(d / "bfm_00000.png")
        self.assertEqual((w, h), (4, 2))
        self.assertEqual(rgb.hex(), "ff0000" "00ff00" "0000ff" "ffffff"
                                    "000000" "848484" "080808" "000000")
        w, h, rgb = read_png_rgb(d / "rgb24.png")
        self.assertEqual((w, h), (2, 2))
        self.assertEqual(rgb.hex(), "1f00e003007c" "000010422104")
        # The port's own PNG decoder reads its screenshots back.
        out = self.run_probe("png", d / "bfm_00000.png", probe=self.png_probe)
        self.assertIn("png 4 2 ff0000ff00ff00ff", out)

    def test_widescreen_projection_maths(self):
        from fractions import Fraction as F
        out = self.run_probe("widescreen")
        lines = out.splitlines()
        for num, den in ((4, 3), (16, 9), (16, 10)):
            aspect = F(num, den)
            for w in (256, 320, 368, 512, 640):
                exact = w * aspect / F(4, 3)
                vis = (w * 3 * num + 2 * den) // (4 * den)
                vis += (vis - w) & 1
                # within a pixel, plus at most one for the centring parity bump
                self.assertLessEqual(abs(vis - exact), F(3, 2))
                self.assertIn(f"horplus {num}:{den} {w} visible {vis} x0 {-((vis - w) // 2)} "
                              f"scale 65536 active {int(aspect != F(4, 3))}", lines)
            scale = (4 * den * 65536 + (3 * num) // 2) // (3 * num)
            self.assertLess(abs(F(scale, 65536) - F(4, 3) / aspect), F(1, 65536))
            want = []
            for sx in (-1024, -1, 0, 1, 40, 159, 160, 161, 319, 320, 1023):
                q = (sx - 160) * scale
                q = (q + 32768) >> 16 if q >= 0 else -((-q + 32768) >> 16)
                self.assertLessEqual(abs(160 + q - (160 + (sx - 160) * F(4, 3) / aspect)), F(1, 2))
                want.append(str(160 + q))
            self.assertIn(f"anamorphic {num}:{den} scale {scale} " + " ".join(want), lines)
            for h in (240, 720, 1081):
                ww = (h * num + den // 2) // den
                ww += ww & 1
                self.assertIn(f"window {num}:{den} {h} {ww}", lines)
        self.assertIn("hfov 18181 24158", lines)   # 2*atan(160/1000), 2*atan(214/1000)

    def test_lua_runtime_sample_mod_and_sandbox(self):
        lua_src = ROOT / "tools/third_party/lua/src"
        if not (lua_src / "lua.h").is_file():
            self.skipTest("Lua not fetched (tools/fetch_lua.sh)")
        objdir = self.tmp / "luaobj"
        objdir.mkdir(exist_ok=True)
        lua_c = sorted(str(p) for p in lua_src.glob("*.c") if p.name not in ("lua.c", "luac.c"))
        subprocess.run(["cc", "-std=gnu99", "-O1", "-c", *lua_c], cwd=objdir, check=True,
                       stdin=subprocess.DEVNULL, timeout=300)
        probe = self.tmp / "bfm_plat_lua_probe"
        sources = sorted(str(p) for p in PLAT.glob("bfm_plat*.c"))
        subprocess.run(["cc", *CFLAGS, "-DBFM_PLAT_WITH_LUA", "-I", str(PLAT), "-I", str(lua_src),
                        *sources, str(PLAT / "backends/script_lua.c"),
                        str(ROOT / "tests/bfm_plat_probe.c"), *sorted(map(str, objdir.glob("*.o"))),
                        "-o", str(probe), "-ldl", "-lm"],
                       check=True, stdin=subprocess.DEVNULL, timeout=300)
        d = self.fresh("luamods")
        shutil.copytree(ROOT / "pc_port/mods/examples/lua_hello", d / "lua_hello")
        (d / "luabad").mkdir()
        (d / "luabad/mod.ini").write_text("[mod]\nname = luabad\nscript = main.lua\n")
        (d / "luabad/main.lua").write_text("this is not lua (\n")
        (d / "luaspin").mkdir()
        (d / "luaspin/mod.ini").write_text("[mod]\nname = luaspin\nscript = main.lua\n")
        (d / "luaspin/main.lua").write_text("while true do end\n")
        (d / "luasandbox").mkdir()
        (d / "luasandbox/mod.ini").write_text("[mod]\nname = luasandbox\nscript = main.lua\n")
        (d / "luasandbox/main.lua").write_text("io.open('/etc/passwd')\n")
        (d / "luatest").mkdir()
        (d / "luatest/mod.ini").write_text("[mod]\nname = luatest\npriority = 200\nscript = main.lua\n")
        (d / "luatest/main.lua").write_text("""
local seen = {}
bfm.on("item_get", function(_, p) seen.item = p.item .. "x" .. p.count end)
bfm.on("save", function(_, p) seen.slot = p.slot end)
bfm.on(15, function(name, p) seen.proj = name .. ":" .. p.ofx .. "," .. p.ofy end)
local sub = bfm.on("vsync", function() seen.vsync = true end)
assert(bfm.off(sub))
assert(bfm.read16(0x80003000) == 0x2211)
assert(bfm.read(0x80003000, 2) == "\\x11\\x22")
bfm.write32(0x80003010, 0xDEADBEEF)
bfm.cheat{name = "lua_poke", address = 0x80003020, value = 0x5A, width = 1}
bfm.set_cheat("lua_poke", true)
local sandbox = tostring(io) .. "," .. tostring(os) .. "," .. tostring(require) .. "," .. tostring(load)
bfm.command("luatest", "luatest", function()
  return string.format("item=%s slot=%s proj=%s vsync=%s sandbox=%s mod=%s",
    seen.item, seen.slot, seen.proj, tostring(seen.vsync), sandbox, bfm.mod_name)
end)
bfm.command("luaboom", "luaboom", function() error("boom") end)
bfm.on("frame_end", function() if seen.late == nil then
  seen.late = pcall(bfm.cheat, {name = "late", address = 0, value = 0, width = 1}) end end)
""")
        out = self.run_probe("lua", d, probe=probe)
        self.assertIn("mod lua_hello script=1", out)
        self.assertIn("mod luatest script=1", out)
        self.assertIn("mod luabad script=-1", out)
        self.assertIn("mod luaspin script=-1", out)        # budget stopped the loop
        self.assertIn("mod luasandbox script=-1", out)     # io is not available
        self.assertIn("reply hola: 0 frames, 0 rooms a,b", out)
        self.assertIn("reply hola: 3 frames, 1 rooms", out)
        self.assertIn("luatest item=7x3 slot=2 proj=projection:160,120 vsync=nil "
                      "sandbox=nil,nil,nil,nil mod=luatest", out)
        self.assertIn("ram efbeadde poke 5a", out)
        self.assertIn("turbo 2", out)
        self.assertIn("boom luaboom: script error", out)

    def test_overlay_font(self):
        self.run_probe("font")

    def test_platform_sources_include_no_host_or_psyq_headers(self):
        # Core interfaces stay dependency-free; only backends/ may include
        # PsyCross or device-owner headers.
        banned = ("SDL", "psx/", "PsyX", "libgpu", "libetc", "GL/", "AL/")
        for path in list(PLAT.glob("bfm_plat*.[ch]")) + [PLAT / "bfm_plugin.h"]:
            for line in path.read_text().splitlines():
                if line.startswith("#include"):
                    for b in banned:
                        self.assertNotIn(b, line, f"{path.name}: {line}")

    def test_backends_compile_against_their_dependencies(self):
        backends = PLAT / "backends"
        sdl_inc = Path("/home/blizz/opt/host-port-deps/usr/include")
        for inc in (sdl_inc / "SDL2", Path("/usr/include/SDL2")):
            if (inc / "SDL.h").is_file():
                subprocess.run(["cc", *CFLAGS, "-fsyntax-only", "-D_REENTRANT",
                                "-I", str(inc), "-I", str(inc.parent), "-I",
                                str(inc.parent / "x86_64-linux-gnu"),
                                str(backends / "input_sdl.c")],
                               check=True, stdin=subprocess.DEVNULL, timeout=60)
                break
        for name in ("audio_sdl.c", "disc_pinned.c"):
            subprocess.run(["cc", *CFLAGS, "-fsyntax-only", "-I",
                            str(ROOT / "pc_port/include"), str(backends / name)],
                           check=True, stdin=subprocess.DEVNULL, timeout=60)
        psycross = ROOT / "tools/third_party/psycross/include"
        if not (psycross / "psx/libgpu.h").is_file():
            main_checkout = Path("/home/blizz/dev/brave-fencer-musashi-decomp/"
                                 "tools/third_party/psycross/include")
            psycross = main_checkout
        if not (psycross / "psx/libgpu.h").is_file():
            self.skipTest("PsyCross not fetched (tools/fetch_toolchains.sh)")
        subprocess.run(["cc", "-std=gnu11", "-Wall", "-Wextra", "-Werror",
                        "-fsyntax-only", "-include", "assert.h", "-I",
                        str(psycross), str(backends / "renderer_psycross.c")],
                       check=True, stdin=subprocess.DEVNULL, timeout=60)


if __name__ == "__main__":
    unittest.main()
