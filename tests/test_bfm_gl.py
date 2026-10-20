"""`gl` renderer backend (pc_port/platform/backends/renderer_gl.c).

Three levels, each skipped when its inputs are missing:
  core    CPU side (bfm_gl_core.c): CLUT decode, batching, PS1 blend formulas
          vs the GL blend state, dither, hor+ routing, HD replacement lookup,
          the reference rasteriser, the render-feedback tile map.
          Always runs, no GL or display needed.
  exec    The GL 3.3 executor on a headless OSMesa (llvmpipe) context,
          compared pixel by pixel with the CPU reference. Needs the Khronos
          GL headers and libOSMesa (both dlopened/compile-time only).
  sdl     The whole backend through SDL2 and the bfm_plat renderer
          interface, on SDL's offscreen driver with Mesa EGL. On a desktop
          with a display the backend opens a real window instead.
  msaa    The executor's MSAA (video.msaa) on a real GL 3.3 core context made
          through SDL (a display, else xvfb-run, else offscreen + EGL; no
          OSMesa): the same synthetic scenes on a single-sample and a
          multisampled executor, differing only at polygon edges, with
          resolved readback / snapshot / present; plus, when BFM_GL_BASE_DIR
          names a checkout of the tree before MSAA, msaa = 0 pixel for pixel
          equal to that tree's executor.
Synthetic data only.
"""
import ctypes.util
import os
import re
import shutil
from pathlib import Path
import subprocess
import tempfile
import unittest

ROOT = Path(__file__).resolve().parents[1]
PLAT = ROOT / "pc_port/platform"
CFLAGS = ["-std=c99", "-Wall", "-Wextra", "-Werror", "-pedantic", "-O0", "-g"]
DEPS = Path(os.environ.get("BFM_HOST_DEPS", Path.home() / "opt/host-port-deps/usr"))
DEPS_LIB = DEPS / "lib/x86_64-linux-gnu"
PLATFORM_SOURCES = sorted(str(p) for p in PLAT.glob("bfm_plat*.c")) + [
    str(PLAT / "psyq/bfm_psyq_compat.c"), str(PLAT / "psyq/bfm_psyq_libgs.c"),
    str(PLAT / "psyq/bfm_psyq_libgte.c")]
CORE = [str(PLAT / "backends/gl/bfm_gl_core.c")]
EXEC = [str(PLAT / "backends/gl/bfm_gl_exec.c")]


def gl_include():
    for d in (os.environ.get("BFM_GL_INCLUDE"), DEPS / "include", "/usr/include"):
        if d and (Path(d) / "GL/glcorearb.h").is_file() and (Path(d) / "KHR/khrplatform.h").is_file():
            return str(d)
    return None


def sdl_include():
    for d in (DEPS / "include/SDL2", Path("/usr/include/SDL2")):
        if (d / "SDL.h").is_file():
            return str(d)
    return None


def osmesa_lib():
    env = os.environ.get("BFM_OSMESA")
    if env:
        return env
    for name in ("libOSMesa.so.8", "libOSMesa.so.6", "libOSMesa.so"):
        if (DEPS_LIB / name).is_file():
            return str(DEPS_LIB / name)
    return ctypes.util.find_library("OSMesa")


def sdl_link():
    """(SDL include dir, link args, env) for SDL2: the host-port-deps copy when it is there, else the system's."""
    inc = sdl_include()
    if not inc:
        return None
    if (DEPS_LIB / "libSDL2.so").exists():
        return inc, ["-L", str(DEPS_LIB), f"-Wl,-rpath-link={DEPS_LIB}", "-Wl,--allow-shlib-undefined",
                     "-lSDL2"], {"LD_LIBRARY_PATH": str(DEPS_LIB)}
    return inc, ["-lSDL2"], {}


def with_display(tmp, cmd, env):
    """cmd and env arranged so a GL 3.3 core context can open: as they are under a display, else under xvfb-run,
    else SDL's offscreen driver with Mesa EGL. None when none of those exists."""
    if os.environ.get("DISPLAY") or os.environ.get("WAYLAND_DISPLAY"):
        return cmd, env
    xvfb = shutil.which("xvfb-run")
    if xvfb:
        return [xvfb, "-a", "-s", "-screen 0 1280x960x24", *cmd], env
    egl = DEPS_LIB / "libEGL_mesa.so.0"
    if egl.exists():
        vendor = tmp / "50_mesa.json"
        vendor.write_text('{"file_format_version":"1.0.0","ICD":{"library_path":"%s"}}' % egl)
        env = dict(env, SDL_VIDEODRIVER="offscreen", __EGL_VENDOR_LIBRARY_FILENAMES=str(vendor),
                   EGL_PLATFORM="surfaceless")
        env.pop("LIBGL_ALWAYS_SOFTWARE", None)
        return cmd, env
    return None


class GlRendererTests(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        temp = tempfile.TemporaryDirectory(prefix="bfm-gl-")
        cls.addClassCleanup(temp.cleanup)
        cls.tmp = Path(temp.name)

    def build(self, name, extra, sources, libs=()):
        out = self.tmp / name
        subprocess.run(["cc", *CFLAGS, *extra, "-I", str(PLAT), *PLATFORM_SOURCES, *sources,
                        "-o", str(out), *libs, "-ldl", "-lm"],
                       check=True, stdin=subprocess.DEVNULL, timeout=180)
        return out

    def run_bin(self, cmd, env=None):
        proc = subprocess.run(cmd, capture_output=True, text=True, timeout=300,
                              env=env, stdin=subprocess.DEVNULL)
        self.assertEqual(proc.returncode, 0, proc.stdout + proc.stderr)
        return proc.stdout

    def test_core(self):
        probe = self.build("gl_core", [], CORE + [str(ROOT / "tests/bfm_gl_probe.c")])
        out = self.run_bin([str(probe), "core"])
        self.assertIn("ok core", out)
        # every PS1 semi-transparency mode is bit-exact, over any stored byte
        for m in range(4):
            self.assertIn(f"blend mode {m}: 1024/1024 exact", out)
        self.assertIn("blend any stored byte: 32768/32768 exact vs PS1", out)

    def test_exec_osmesa(self):
        inc, lib = gl_include(), osmesa_lib()
        if not inc or not lib:
            self.skipTest("GL headers or libOSMesa not available")
        probe = self.build("gl_exec", ["-DBFM_GL_PROBE_EXEC", "-I", inc],
                           CORE + EXEC + [str(ROOT / "tests/bfm_gl_probe.c")])
        env = dict(os.environ, LD_LIBRARY_PATH=str(DEPS_LIB), LIBGL_ALWAYS_SOFTWARE="1")
        out = self.run_bin([str(probe), "exec", lib], env=env)
        if "skip exec" in out:
            self.skipTest(out.strip())
        self.assertIn("ok exec", out)
        self.assertIn("textures 4/8/15-bit: 3072 texels, 3072 exact", out)
        for m in range(4):
            self.assertIn(f"gl blend mode {m}: vs PS1 992/992 exact", out)
        self.assertIn("gl present 5-bit display: 239 33 255", out)
        # mask bit and render feedback, all 16 bits vs the reference rasteriser
        for line in ("gl mask 1x: 6144 px bit-exact", "gl mask 3x: 6144 px bit-exact",
                     "gl feedback 4-bit + CLUT: 1024 px bit-exact",
                     "gl feedback frame buffer: 76800 px bit-exact",
                     "gl whole VRAM 1x: 524288 px bit-exact",
                     "gl whole VRAM 3x: 524288 px bit-exact"):
            self.assertIn(line, out)

    def test_exec_vs_controller(self):
        # tests/bfm_gl_ctl_probe.c: one GP0 stream through native_boot's cpu
        # rasteriser (gpu_controller.c) and through bridge -> batch -> the GL
        # executor; at 1x every opaque pixel off a polygon edge must match
        # bit for bit, semi-transparent ones within the 8-bit blend step
        inc, lib = gl_include(), osmesa_lib()
        if not inc or not lib:
            self.skipTest("GL headers or libOSMesa not available")
        ctl = None
        for d in ([Path(os.environ["BFM_GPU_CONTROLLER_DIR"])]
                  if os.environ.get("BFM_GPU_CONTROLLER_DIR") else []) + [ROOT / "pc_port"]:
            if (d / "gpu_controller.c").is_file() and (d / "include/musashi_gpu_controller.h").is_file():
                ctl = d
                break
        if not ctl:
            self.skipTest("gpu_controller.c not available (BFM_GPU_CONTROLLER_DIR)")
        probe = self.build("gl_ctl", ["-I", inc, "-I", str(ctl / "include")],
                           CORE + EXEC + [str(ctl / "gpu_controller.c"),
                                          str(ROOT / "tests/bfm_gl_ctl_probe.c")])
        env = dict(os.environ, LD_LIBRARY_PATH=str(DEPS_LIB), LIBGL_ALWAYS_SOFTWARE="1")
        out = self.run_bin([str(probe), lib, "1", "6"], env=env)
        if "skip exec" in out:
            self.skipTest(out.strip())
        self.assertIn("ok ctl", out)
        self.assertIn("opaque non-edge differences: 0; semi coverage/mask/>1-step: 0", out)
        for kind in ("TILE", "SPRT"):   # rects: no edge rule, so the whole row is equal
            self.assertRegex(out, r"%s +no +(\d+) +\1 " % kind)

    def test_bench_runs(self):
        # tools/gl_bench: builds at -O2 -Werror and runs a tiny frame set
        if not gl_include() or not (DEPS_LIB / "libOSMesa.so.8").exists():
            self.skipTest("GL headers or libOSMesa not available")
        env = dict(os.environ, BFM_HOST_DEPS=str(DEPS), TMPDIR=str(self.tmp))
        out = self.run_bin(["sh", str(ROOT / "tools/gl_bench/run.sh"), "--frames", "2",
                            "--prims", "400", "--scales", "1,2", "--feedback", "--mask",
                            "--size", "320x240"], env=env)
        if out.startswith("skip"):
            self.skipTest(out.strip())
        self.assertIn("ok bench", out)
        self.assertNotIn("FAIL", out)

    def test_headless_boot_script(self):
        # tools/run_headless_boot.sh: the capture shim builds; the script
        # refuses missing inputs and an --out inside the tracked tree
        script = ROOT / "tools/run_headless_boot.sh"
        shim = self.tmp / "cap.so"
        subprocess.run(["cc", "-std=c99", "-Wall", "-Wextra", "-Werror", "-O2", "-shared", "-fPIC",
                        "-I", str(PLAT), str(ROOT / "tools/headless/bfm_swap_capture.c"),
                        str(PLAT / "bfm_plat_image.c"), "-o", str(shim), "-ldl"],
                       check=True, stdin=subprocess.DEVNULL, timeout=60)
        proc = subprocess.run(["sh", str(script), "--binary", str(self.tmp / "nope"),
                               "--disc", str(self.tmp)], capture_output=True, text=True,
                              timeout=60, stdin=subprocess.DEVNULL)
        self.assertEqual(proc.returncode, 2)
        self.assertIn("missing", proc.stderr)
        if not (DEPS_LIB / "libEGL_mesa.so.0").exists():
            return
        disc = self.tmp / "disc"
        (disc / "files").mkdir(parents=True, exist_ok=True)
        for f in ("files/SLUS_007.26", "disc.cue", "disc.bin"):
            (disc / f).write_bytes(b"synthetic")
        fake = self.tmp / "fake_boot"
        fake.write_text("#!/bin/sh\nexit 0\n")
        fake.chmod(0o755)
        inside = ROOT / "pc_port/.headless-guard-test"
        try:
            proc = subprocess.run(["sh", str(script), "--binary", str(fake), "--disc", str(disc),
                                   "--out", str(inside)], capture_output=True, text=True,
                                  timeout=60, stdin=subprocess.DEVNULL,
                                  env=dict(os.environ, BFM_HOST_DEPS=str(DEPS)))
            self.assertEqual(proc.returncode, 2, proc.stdout + proc.stderr)
            self.assertIn("not ignored", proc.stderr)
            self.assertFalse(inside.exists())   # refused before creating anything
        finally:
            if inside.exists():
                shutil.rmtree(inside)
        # a scratch --out runs the fake binary and summarises
        out = self.tmp / "hl"
        proc = subprocess.run(["sh", str(script), "--binary", str(fake), "--disc", str(disc),
                               "--out", str(out), "--timeout", "20"], capture_output=True,
                              text=True, timeout=120, stdin=subprocess.DEVNULL,
                              env=dict(os.environ, BFM_HOST_DEPS=str(DEPS)))
        self.assertEqual(proc.returncode, 0, proc.stdout + proc.stderr)
        self.assertIn("exit: 0", proc.stdout)
        for f in ("egl.json", "alsa.conf", "bfm_swap_capture.so", "out.log"):
            self.assertTrue((out / f).exists(), f)

    def test_sdl_backend(self):
        inc, sdl = gl_include(), sdl_include()
        if not inc or not sdl or not (DEPS_LIB / "libSDL2.so").exists():
            self.skipTest("SDL2 / GL headers not available")
        smoke = self.build(
            "gl_sdl", ["-DBFM_PLAT_WITH_GL", "-D_REENTRANT", "-I", inc, "-I", sdl],
            CORE + EXEC + [str(PLAT / "backends/renderer_gl.c"), str(ROOT / "tests/bfm_gl_sdl_smoke.c")],
            ["-L", str(DEPS_LIB), f"-Wl,-rpath-link={DEPS_LIB}", "-Wl,--allow-shlib-undefined", "-lSDL2"])
        env = dict(os.environ, LD_LIBRARY_PATH=str(DEPS_LIB))
        if not os.environ.get("DISPLAY") and not os.environ.get("WAYLAND_DISPLAY"):
            egl = DEPS_LIB / "libEGL_mesa.so.0"
            if not egl.exists():
                self.skipTest("no display and no Mesa EGL for SDL's offscreen driver")
            vendor = self.tmp / "50_mesa.json"
            vendor.write_text('{"file_format_version":"1.0.0","ICD":{"library_path":"%s"}}' % egl)
            # (LIBGL_ALWAYS_SOFTWARE here crashes Mesa 25.0's EGL inside
            # SDL_CreateWindow; without it Mesa falls back to llvmpipe itself)
            env.update(SDL_VIDEODRIVER="offscreen", __EGL_VENDOR_LIBRARY_FILENAMES=str(vendor),
                       EGL_PLATFORM="surfaceless")
            env.pop("LIBGL_ALWAYS_SOFTWARE", None)
        out = self.run_bin([str(smoke)], env=env)
        if out.startswith("skip"):
            self.skipTest(out.strip())
        self.assertIn("ok gl_sdl", out)
        borrowed = self.run_bin([str(smoke), "borrow"], env=env)
        self.assertIn("ok gl_sdl", borrowed)

    def test_sdl_backend_msaa(self):
        # tests/bfm_gl_sdl_smoke.c in its msaa mode, one process per setting: the renderer reads video.msaa from the
        # config at open, logs "GL_MSAA requested=N effective=M", and StoreImage of an edge row returns resolved
        # blends with MSAA on and only the two flat colours with it off
        inc, link = gl_include(), sdl_link()
        if not inc or not link:
            self.skipTest("SDL2 / GL headers not available")
        sdl, ldflags, extra = link
        smoke = self.build("gl_sdl_msaa", ["-DBFM_PLAT_WITH_GL", "-D_REENTRANT", "-I", inc, "-I", sdl],
                           CORE + EXEC + [str(PLAT / "backends/renderer_gl.c"),
                                          str(ROOT / "tests/bfm_gl_sdl_smoke.c")], ldflags)
        wrapped = with_display(self.tmp, [str(smoke)], dict(os.environ, **extra))
        if not wrapped:
            self.skipTest("no display, no xvfb-run and no Mesa EGL for SDL's offscreen driver")
        blended = {}
        for n in (0, 4):
            env = dict(wrapped[1], HOME=str(self.tmp), XDG_CONFIG_HOME=str(self.tmp / "xdg"))   # no user config.ini
            proc = subprocess.run([*wrapped[0], "msaa", str(n)], capture_output=True, text=True, timeout=300,
                                  env=env, stdin=subprocess.DEVNULL)
            self.assertEqual(proc.returncode, 0, proc.stdout + proc.stderr)
            if proc.stdout.startswith("skip"):
                self.skipTest(proc.stdout.strip())
            self.assertIn("ok gl_sdl_msaa", proc.stdout)
            m = re.search(r"msaa backend requested=%d: row y=40: (\d+) red, (\d+) black, (\d+) blended red, 0 other"
                          % n, proc.stdout)
            self.assertTrue(m, proc.stdout)
            blended[n] = int(m[3])
            if n:
                self.assertRegex(proc.stderr, r"GL_MSAA requested=4 effective=[2-9]\d*\n")
            else:
                self.assertNotIn("GL_MSAA", proc.stderr)   # a field of 0 and no config key: not a word
        self.assertEqual(blended[0], 0)
        self.assertGreater(blended[4], 0)

    def msaa_probe_output(self, base_dir=None):
        """Output of tests/bfm_gl_msaa_probe.c: built against this tree, or (base_dir) against that checkout's
        pre-MSAA executor with -DBFM_MSAA_PROBE_BASE, which prints only the msaa = 0 scene hashes. Skips the test
        when the inputs or a GL context are missing."""
        inc, link = gl_include(), sdl_link()
        if not inc or not link:
            self.skipTest("SDL2 / GL headers not available")
        sdl, ldflags, extra = link
        if base_dir:
            plat = Path(base_dir) / "pc_port/platform"
            sources = sorted(str(p) for p in plat.glob("bfm_plat*.c")) + [
                str(plat / "psyq/bfm_psyq_compat.c"), str(plat / "psyq/bfm_psyq_libgs.c"),
                str(plat / "psyq/bfm_psyq_libgte.c"), str(plat / "backends/gl/bfm_gl_core.c"),
                str(plat / "backends/gl/bfm_gl_exec.c")]
            out = self.tmp / "gl_msaa_base"
            subprocess.run(["cc", *CFLAGS, "-DBFM_MSAA_PROBE_BASE", "-D_REENTRANT", "-I", inc, "-I", sdl,
                            "-I", str(plat), *sources, str(ROOT / "tests/bfm_gl_msaa_probe.c"), "-o", str(out),
                            *ldflags, "-ldl", "-lm"], check=True, stdin=subprocess.DEVNULL, timeout=180)
        else:
            out = self.build("gl_msaa", ["-D_REENTRANT", "-I", inc, "-I", sdl],
                             CORE + EXEC + [str(ROOT / "tests/bfm_gl_msaa_probe.c")], ldflags)
        wrapped = with_display(self.tmp, [str(out)], dict(os.environ, **extra))
        if not wrapped:
            self.skipTest("no display, no xvfb-run and no Mesa EGL for SDL's offscreen driver")
        text = self.run_bin(wrapped[0], env=wrapped[1])
        if re.search(r"^skip msaa", text, re.M):
            self.skipTest(text.strip().splitlines()[-1])
        return text

    def test_msaa_sdl(self):
        out = self.msaa_probe_output()
        self.assertIn("ok msaa", out)
        # polygons: only edge pixels change (no interior pixel does), and edge pixels hold resolved blends
        self.assertRegex(out, r"msaa flat@1x eff=\d+ scale=1: diff=[1-9]\d* interior_diff=0 \(max delta 0\) "
                              r"edge_diff=[1-9]\d* blended=[1-9]\d* ")
        self.assertRegex(out, r"msaa gouraud@1x eff=\d+ scale=1: diff=[1-9]\d* interior_diff=0 ")
        # the same, drawn into scene slot 0 (the frame buffer: how the game draws)
        self.assertRegex(out, r"msaa flat@1x/scene eff=\d+ scale=1: diff=[1-9]\d* interior_diff=0 \(max delta 0\) "
                              r"edge_diff=[1-9]\d* blended=[1-9]\d* ")
        self.assertRegex(out, r"msaa gouraud@1x/scene eff=\d+ scale=1: diff=[1-9]\d* interior_diff=0 ")
        self.assertRegex(out, r"msaa textured@1x/scene eff=\d+ scale=1: diff=[1-9]\d* interior_diff=0 .* bluish=0\n")
        # no bleed: the texture's magenta frame never shows
        self.assertRegex(out, r"msaa textured@1x eff=\d+ scale=1: diff=[1-9]\d* interior_diff=0 .* bluish=0\n")
        self.assertRegex(out, r"msaa textured@2x eff=\d+ scale=2: .* bluish=0\n")
        self.assertRegex(out, r"msaa flat@2x eff=\d+ scale=2: diff=[1-9]\d* interior_diff=0 ")
        # pixel-aligned rects, sprites, fills and copies are not touched
        self.assertRegex(out, r"msaa aligned eff=\d+: whole image identical")
        self.assertRegex(out, r"msaa aligned/scene eff=\d+: whole image identical")
        # a mask-check draw over a mask-set triangle keeps exactly its samples (per-sample stencil)
        self.assertRegex(out, r"msaa mask eff=0: .*: 0 px differ, 0 blended edge px, stencil_builds=0")
        self.assertRegex(out, r"msaa mask eff=[2-9]\d*: .*: 0 px differ, [1-9]\d* blended edge px, stencil_builds=1")
        self.assertRegex(out, r"msaa mask/scene eff=0: .*: 0 px differ, 0 blended edge px, stencil_builds=0")
        self.assertRegex(out, r"msaa mask/scene eff=[2-9]\d*: .*: 0 px differ, [1-9]\d* blended edge px, "
                              r"stencil_builds=1")
        # snapshot, readback and present see the resolved image
        self.assertRegex(out, r"msaa feedback eff=\d+: .*: 0 of 4096 px differ")
        self.assertRegex(out, r"msaa feedback/scene eff=\d+: .*: 0 of 4096 px differ")
        self.assertRegex(out, r"msaa readback/scene eff=\d+: 16-bit readback equals the resolved RGBA image")
        self.assertRegex(out, r"msaa readback eff=\d+: 16-bit readback equals the resolved RGBA image")
        self.assertRegex(out, r"msaa present eff=\d+ scale=1: diff=[1-9]\d* interior_diff=0 ")
        # clamps and the memory fit
        self.assertRegex(out, r"msaa clamp: request 16 -> \d+")
        self.assertRegex(out, r"msaa fit: 8 samples at 1x held \d+; at 5x")

    def test_msaa_off_matches_base(self):
        # msaa = 0 is the executor as it was: every scene's single-sample image, at 1x and 2x, hashes the same on a
        # checkout from before MSAA (BFM_GL_BASE_DIR, e.g. a worktree of the commit this work started from)
        base = os.environ.get("BFM_GL_BASE_DIR")
        if not base or not (Path(base) / "pc_port/platform/backends/gl/bfm_gl_exec.c").is_file():
            self.skipTest("set BFM_GL_BASE_DIR to a checkout of the tree before MSAA")
        new = dict(re.findall(r"^HASH (\S+) (\w+)$", self.msaa_probe_output(), re.M))
        old = dict(re.findall(r"^HASH (\S+) (\w+)$", self.msaa_probe_output(base), re.M))
        self.assertEqual(len(old), 24, old)   # 6 scenes x 1x/2x x VRAM target/scene slot
        self.assertEqual(new, old)


if __name__ == "__main__":
    unittest.main()
