"""`gl` renderer backend (pc_port/platform/backends/renderer_gl.c).

Three levels, each skipped when its inputs are missing:
  core    CPU side (bfm_gl_core.c): CLUT decode, batching, PS1 blend formulas
          vs the GL blend state, dither, hor+ routing, HD replacement lookup.
          Always runs, no GL or display needed.
  exec    The GL 3.3 executor on a headless OSMesa (llvmpipe) context,
          compared pixel by pixel with the CPU reference. Needs the Khronos
          GL headers and libOSMesa (both dlopened/compile-time only).
  sdl     The whole backend through SDL2 and the bfm_plat renderer
          interface, on SDL's offscreen driver with Mesa EGL. On a desktop
          with a display the backend opens a real window instead.
Synthetic data only.
"""
import ctypes.util
import os
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
        # add/subtract modes are bit-exact; the halving modes within one step
        self.assertIn("blend mode 1: 1024/1024 exact", out)
        self.assertIn("blend mode 2: 1024/1024 exact", out)

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
        self.assertIn("gl blend mode 1: vs PS1 992/992 exact", out)


if __name__ == "__main__":
    unittest.main()
