"""bfm_plat audio sinks (MUSASHI_AUDIO=bfm_plat): the null backend drains at
the platform clock's audio rate, so a queue-paced SPU never faults on it;
the OpenAL backend (when the OpenAL headers and library are present) plays
through OpenAL Soft's null driver and drains in real time."""
import os
import shutil
import subprocess
import tempfile
import unittest
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
PLAT = ROOT / "pc_port/platform"
CFLAGS = ["-std=c99", "-Wall", "-Wextra", "-Werror", "-O0", "-g"]


def sources():
    return (sorted(str(p) for p in PLAT.glob("bfm_plat*.c")) +
            [str(PLAT / "psyq" / n) for n in
             ("bfm_psyq_compat.c", "bfm_psyq_libgs.c", "bfm_psyq_libgte.c")])


@unittest.skipUnless(shutil.which("cc"), "cc unavailable")
class AudioSinkTests(unittest.TestCase):
    def build(self, out, *extra):
        subprocess.run(["cc", *CFLAGS, "-D_POSIX_C_SOURCE=199309L", "-I", str(PLAT), *sources(),
                        str(ROOT / "tests/bfm_plat_audio_probe.c"), *extra,
                        "-o", str(out), "-ldl", "-lm"],
                       check=True, stdin=subprocess.DEVNULL, timeout=180)

    def test_null_sink_drains_at_the_audio_rate(self):
        with tempfile.TemporaryDirectory(prefix="bfm-audio-") as d:
            probe = Path(d) / "probe"
            self.build(probe)
            run = subprocess.run([str(probe)], capture_output=True, text=True, timeout=60)
            self.assertEqual(run.returncode, 0, run.stderr)
            self.assertIn("OK null", run.stdout)

    @unittest.skipUnless(Path("/usr/include/AL/al.h").is_file(), "OpenAL headers unavailable")
    def test_openal_sink_plays_and_drains(self):
        with tempfile.TemporaryDirectory(prefix="bfm-audio-") as d:
            probe = Path(d) / "probe"
            self.build(probe, "-DPROBE_OPENAL", str(PLAT / "backends/audio_openal.c"), "-lopenal")
            env = dict(os.environ, ALSOFT_DRIVERS="null")
            run = subprocess.run([str(probe)], capture_output=True, text=True, timeout=60, env=env)
            self.assertEqual(run.returncode, 0, run.stderr)
            self.assertIn("OK null", run.stdout)
            self.assertTrue("OK openal" in run.stdout or "SKIP openal" in run.stdout, run.stdout)


if __name__ == "__main__":
    unittest.main()
