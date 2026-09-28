"""Test-runner environment shims.

Homebrew can leave the *unversioned* SDL2 include tree without `SDL_main.h`
(`/home/linuxbrew/.linuxbrew/include/SDL2`), while a versioned `sdl2-compat`
keg keeps a complete copy. `tools/run_tests.sh` already prefers the versioned
CMake config for the native smoke build, but the compiled probes resolve their
include flags from `pkg-config`/`sdl2-config`, which point at the incomplete
tree. That mismatch made every probe including `<SDL.h>` fail to compile with
`fatal error: SDL_main.h: No such file or directory` — not a code failure.

Prepend the complete include directory to `CPATH` so the child compilers find
it after the (still first-searched) unversioned directory. This is a no-op on a
host whose unversioned tree is complete or whose keg is absent.
"""
from __future__ import annotations

import os
from pathlib import Path

_UNVERSIONED = Path("/home/linuxbrew/.linuxbrew/include/SDL2")
_CELLAR = Path("/home/linuxbrew/.linuxbrew/Cellar")


def _prefer_complete_sdl_include() -> None:
    if (_UNVERSIONED / "SDL_main.h").is_file():
        return
    for candidate in sorted(_CELLAR.glob("sdl2*/**/include/SDL2")):
        if (candidate / "SDL_main.h").is_file():
            os.environ["CPATH"] = (
                str(candidate) + os.pathsep + os.environ.get("CPATH", "")
            )
            return


_prefer_complete_sdl_include()


def _prefer_host_port_deps() -> None:
    dep_inc = Path("/home/blizz/opt/host-port-deps/usr/include")
    dep_lib = Path("/home/blizz/opt/host-port-deps/usr/lib/x86_64-linux-gnu")
    if dep_inc.is_dir():
        os.environ["CPATH"] = (
            str(dep_inc) + os.pathsep +
            str(dep_inc / "x86_64-linux-gnu") + os.pathsep +
            os.environ.get("CPATH", "")
        )
    if dep_lib.is_dir():
        pulse_lib = dep_lib / "pulseaudio"
        ld_parts = [str(dep_lib)]
        if pulse_lib.is_dir():
            ld_parts.append(str(pulse_lib))
        os.environ["LIBRARY_PATH"] = (
            str(dep_lib) + os.pathsep +
            os.environ.get("LIBRARY_PATH", "")
        )
        os.environ["LD_LIBRARY_PATH"] = (
            os.pathsep.join(ld_parts) + os.pathsep +
            os.environ.get("LD_LIBRARY_PATH", "")
        )
    tmp_dir = Path("/home/blizz/tmp")
    tmp_dir.mkdir(parents=True, exist_ok=True)
    os.environ.setdefault("TMPDIR", str(tmp_dir))
    import tempfile
    tempfile.tempdir = str(tmp_dir)


_prefer_host_port_deps()
