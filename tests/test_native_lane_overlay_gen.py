"""Overlay own-code lane, generator side (tools/native_lane_gen.py,
docs/OVERLAY-LANE-DESIGN.md section 3B): the allow file, the strict member
checks (SHA-1, missing file/row, size), the positive origin check, (vram,
digest) dedup with covers, the guest jump-table rule and the platform hook
sites. Synthetic inputs except where noted; no retail bytes are needed
(the end-to-end case is skipped without the user's extract and clang)."""
import hashlib
import json
from pathlib import Path
import shutil
import subprocess
import sys
import tempfile
import unittest

ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(ROOT / "tools"))
import native_lane_gen as g  # noqa: E402

ALLOW = ROOT / "config/lane_own_code_allow_overlay.txt"


def info(member, data, vram=0x80100000, code=None):
    return dict(member=member, path=Path("/nonexistent"), vram=vram, start=0,
                code=code or [(vram, vram + len(data))], data=bytes(data))


class AllowFile(unittest.TestCase):
    def write(self, text):
        d = tempfile.TemporaryDirectory()
        self.addCleanup(d.cleanup)
        p = Path(d.name) / "allow.txt"
        p.write_text(text)
        return p

    def test_parse(self):
        p = self.write("# comment\n\nmain_0003 800cf078\nsc03_0001 0x8012a988  # trailing\n")
        self.assertEqual(g.parse_overlay_allow(p), [("main_0003", 0x800CF078), ("sc03_0001", 0x8012A988)])

    def test_malformed_duplicate_unaligned(self):
        for text in ("800cf078\n", "main_0003 800cf078 extra\n", "main_0003 800cf078\nmain_0003 800CF078\n",
                     "main_0003 800cf07a\n"):
            with self.assertRaises(g.BuildError, msg=text):
                g.parse_overlay_allow(self.write(text))

    def test_tracked_allow_file_is_the_clean_room_sets(self):
        # O1 = main_0003's 24 clean-room functions, O2 = main_0012's 95 (O2 69 + B18 26).
        pairs = g.parse_overlay_allow(ALLOW)
        reg = {(m["region"], m["vram"]): m for m in
               json.loads((ROOT / "provenance/matches.json").read_text())["matches"]}
        for member, vram in pairs:
            m = reg[(member, vram)]
            self.assertTrue(m["origin"].startswith("owner re-derivation, clean room"), (member, hex(vram)))
            self.assertIsNone(g.overlay_origin_problem(m), (member, hex(vram)))
        members = sorted({member for member, _ in pairs})
        self.assertEqual(members, ["main_0003", "main_0012"])
        for member, count in (("main_0003", 24), ("main_0012", 95)):
            listed = sorted(v for mem, v in pairs if mem == member)
            clean = sorted(m["vram"] for m in reg.values() if m["region"] == member
                           and (m.get("origin") or "").startswith("owner re-derivation, clean room"))
            self.assertEqual(len(listed), count, member)
            self.assertEqual(listed, clean, member)


class MemberChecks(unittest.TestCase):
    def setUp(self):
        self._tmp = tempfile.TemporaryDirectory()
        self.root = Path(self._tmp.name)
        (self.root / "config").mkdir()
        (self.root / "ext").mkdir()
        self.data = bytes(range(256)) * 4
        (self.root / "ext/m.bin").write_bytes(self.data)
        self._old = g.ROOT
        g.ROOT = self.root

    def tearDown(self):
        g.ROOT = self._old
        self._tmp.cleanup()

    def yaml(self, sha1):
        (self.root / "config/overlay_main_0099.yaml").write_text(
            (f"sha1: {sha1}\n" if sha1 else "") +
            "options:\n  target_path: ext/m.bin\nsegments:\n  - name: main_0099\n    type: code\n"
            "    start: 0x0\n    vram: 0x80100000\n    subsegments:\n      - [0x0, asm, main_0099]\n"
            "  - [0x400]\n")

    def test_sha1_match(self):
        self.yaml(hashlib.sha1(self.data).hexdigest())
        i = g.member_info("main_0099", strict=True)
        self.assertEqual((i["vram"], i["code"]), (0x80100000, [(0x80100000, 0x80100400)]))

    def test_sha1_mismatch_is_an_error(self):
        self.yaml("0" * 40)
        with self.assertRaisesRegex(g.BuildError, "SHA-1"):
            g.member_info("main_0099", strict=True)
        self.assertIsNone(g.member_info("main_0099"))  # dev builds: stays interpreted

    def test_missing_sha1_config_or_file(self):
        self.yaml(None)
        with self.assertRaisesRegex(g.BuildError, "no sha1"):
            g.member_info("main_0099", strict=True)
        with self.assertRaisesRegex(g.BuildError, "no config/overlay_main_0098.yaml"):
            g.member_info("main_0098", strict=True)
        self.yaml(hashlib.sha1(self.data).hexdigest())
        (self.root / "ext/m.bin").unlink()
        with self.assertRaisesRegex(g.BuildError, "not extracted"):
            g.member_info("main_0099", strict=True)


class Origin(unittest.TestCase):
    def test_positive_origin(self):
        src = "src/does/not/exist.c"
        self.assertIsNone(g.overlay_origin_problem(dict(origin="owner re-derivation, clean room (x)", source=src)))
        self.assertIsNone(g.overlay_origin_problem(dict(origin="owner-authored", source=src)))
        self.assertRegex(g.overlay_origin_problem(dict(origin="", source=src)), "untagged")
        self.assertRegex(g.overlay_origin_problem(dict(source=src)), "untagged")
        self.assertRegex(g.overlay_origin_problem(dict(origin="matched by hand", source=src)),
                         "not clean-room or owner")
        self.assertRegex(g.overlay_origin_problem(dict(origin="owner edit of vendor-derived C", source=src)),
                         "third-party")


class AllowCandidates(unittest.TestCase):
    def test_missing_row_and_size(self):
        i = g.member_info("main_0003")
        if i is None:
            raise unittest.SkipTest("main_0003 member file not extracted")
        with self.assertRaisesRegex(g.BuildError, "no registry row"):
            g.allow_candidates([("main_0003", 0x800D2D24)], {"main_0003": i}, True)
        # main_0003's vendor-derived 800D2C88: a registry row, but not own code
        with self.assertRaisesRegex(g.BuildError, "origin"):
            g.allow_candidates([("main_0003", 0x800D2C88)], {"main_0003": i}, True)
        i12 = g.member_info("main_0012")
        if i12 is None:
            raise unittest.SkipTest("main_0012 member file not extracted")
        rows = g.allow_candidates(g.parse_overlay_allow(ALLOW), {"main_0003": i, "main_0012": i12}, True)
        self.assertEqual(len(rows), 119)

    def test_size_problem(self):
        i = info("x_0001", b"\0" * 64)
        self.assertIsNone(g.overlay_size_problem(dict(vram=0x80100000, size=16), i, {0x80100000, 0x80100010}))
        self.assertRegex(g.overlay_size_problem(dict(vram=0x80100000, size=18), i, set()), "word multiple")
        self.assertRegex(g.overlay_size_problem(dict(vram=0x80100000, size=0), i, set()), "word multiple")
        self.assertRegex(g.overlay_size_problem(dict(vram=0x80100030, size=32), i, set()), "code subsegments")
        self.assertRegex(g.overlay_size_problem(dict(vram=0x80100000, size=32), i, {0x80100000, 0x80100010}),
                         "overlaps the next registry function 80100010")


class Dedup(unittest.TestCase):
    def test_identical_bytes_one_entry_with_covers(self):
        body = bytes(range(32))
        infos = {"main_0012": info("main_0012", body), "sc01_0000": info("sc01_0000", body),
                 "sc03_0001": info("sc03_0001", bytes(31) + b"\1")}
        src = "src/none.c"
        cands = [dict(region="main_0012", vram=0x80100000, size=32, origin="", source=src),
                 dict(region="sc01_0000", vram=0x80100000, size=32, origin="owner re-derivation, clean room", source=src),
                 dict(region="sc03_0001", vram=0x80100000, size=32, origin="", source=src)]
        kept, dropped = g.dedup_overlays(cands, infos)
        self.assertEqual(len(kept), 2)
        same = next(k for k in kept if k["region"] != "sc03_0001")
        self.assertEqual(same["region"], "sc01_0000")  # clean-room source preferred
        self.assertEqual(same["covers"], ["main_0012", "sc01_0000"])
        self.assertEqual([(d["region"], d["covered_by"]) for d in dropped], [("main_0012", "sc01_0000")])
        other = next(k for k in kept if k["region"] == "sc03_0001")
        self.assertEqual(other["covers"], ["sc03_0001"])


class JumpTable(unittest.TestCase):
    def test_jr_not_ra(self):
        words = [0x27BDFFE8, 0x00400008, 0x00000000, 0x03E00008, 0x00000000]  # jr $v0 ... jr $ra
        i = info("x_0001", b"".join(w.to_bytes(4, "little") for w in words))
        self.assertEqual(g.guest_jump_table(i, 0x80100000, 20), (0x80100004, 2))
        self.assertIsNone(g.guest_jump_table(i, 0x8010000C, 8))  # jr $ra only
        jalr = info("x_0001", (0x0040F809).to_bytes(4, "little"))  # jalr $v0 is a call
        self.assertIsNone(g.guest_jump_table(jalr, 0x80100000, 4))


class HookSites(unittest.TestCase):
    def test_platform_sites_are_entry_hooks(self):
        sites = g.plat_hook_sites()
        for pc in (0x8014BC80, 0x8014BD60, 0x800D0F0C, 0x800D128C, 0x80011B7C, 0x80128158):
            self.assertIn(pc, sites)
        kinds = g.hooked_pcs()
        self.assertEqual(kinds.get(0x8014BC80), "entry")
        self.assertEqual(kinds.get(0x800D0F0C), "entry")
        # A site at a PsyQ entry's own PC (SetGeomScreen/SetGeomOffset) leaves
        # the HLE entry installed: the hook fires before the lane runs.
        blocked = set(g.psyq_hooked(kinds))
        self.assertNotIn(0x8004921C, blocked)
        self.assertNotIn(0x8004923C, blocked)
        without = {pc: k for pc, k in kinds.items() if pc not in sites or k == "hard"}
        self.assertEqual(blocked, set(g.psyq_hooked(without)))


class EndToEnd(unittest.TestCase):
    """The generator's release mode over the tracked allow file (needs clang
    and the user's main_0003 extract)."""

    def test_release_overlay_report(self):
        clang = shutil.which("clang")
        if not clang or g.member_info("main_0003") is None or g.member_info("main_0012") is None:
            raise unittest.SkipTest("needs clang and the main_0003/main_0012 extracts")
        with tempfile.TemporaryDirectory() as d:
            only = Path(d) / "only.txt"
            only.write_text("80011b7c\n80010bb4\n")  # a hook site and one native caller
            r = subprocess.run([sys.executable, str(ROOT / "tools/native_lane_gen.py"), "--out", d,
                                "--clang", clang, "--jobs", "2", "--own-code-only", "--only", str(only),
                                "--overlay-allow", str(ALLOW)], capture_output=True, text=True, timeout=900)
            self.assertEqual(r.returncode, 0, r.stderr[-2000:])
            rep = json.loads((Path(d) / "report.json").read_text())
            ovl = rep["overlay"]
            self.assertEqual((ovl["members"], ovl["candidates"]), (["main_0003", "main_0012"], 119))
            rules = {f["vram"]: f["rule"] for f in ovl["functions"]}
            # D-011: the CD retry loop charges its retail cost and is admitted
            self.assertIsNone(rules["800d2a24"])
            for f in ovl["functions"]:
                self.assertEqual(f["covers"], [f["member"]])
                self.assertRegex(f["digest"], "^[0-9a-f]{16}$")
                self.assertEqual(f["rule"] is None, f["admitted"])
            table = (Path(d) / "native_lane_table.c").read_text()
            body = table.split("lane_call_func_80011B7C__", 1)
            if len(body) == 2:  # 80010bb4 admitted: its call to the hook site is a thunk
                self.assertIn("musashi_native_guest_call(0x80011B7Cu", body[1].split("\n}\n", 1)[0])
            # an allow-listed pair without a registry row fails the build
            bad = Path(d) / "bad.txt"
            bad.write_text("main_0003 800d2d24\n")
            r = subprocess.run([sys.executable, str(ROOT / "tools/native_lane_gen.py"), "--out", d,
                                "--clang", clang, "--own-code-only", "--overlay-allow", str(bad)],
                               capture_output=True, text=True, timeout=900)
            self.assertEqual(r.returncode, 2)
            self.assertIn("no registry row", r.stderr)


if __name__ == "__main__":
    unittest.main()
