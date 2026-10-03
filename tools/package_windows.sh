#!/bin/sh
# Package musashi_native_boot.exe for Windows x64 (cmake/zig-windows.cmake).
#
#   tools/package_windows.sh --binary BUILD-WIN/musashi_native_boot.exe --run N \
#       --deps DEPS --out DIR --status TEXT [--known-issue TEXT ...] \
#       [--exe YOUR/SLUS_007.26 --extracted YOUR/extracted/disc] [--zig ZIG-ROOT] [--public]
#
# Stages bfm-r<N>-<commit>-windows-x64/ (exe, SDL2.dll, OpenAL32.dll, launch.cmd,
# README, licenses, manifest.json with the size and SHA-256 of every file), runs
# tools/retail_guard.py over it and writes a deterministic .zip beside it. DEPS
# holds the approved SDL2/OpenAL Soft packages plus the matching OpenAL source
# (docs/WINDOWS-PORT.md, deps/PROVENANCE.txt). No disc image, BIOS or game data
# is copied; --exe/--extracted feed the guard only.
#
# The output equals the owner-test package contract the launcher was gated
# against (r40, 2026-10-03): launch.cmd honours launcher-managed BFM_DISC /
# BFM_DISC_DIR and returns 66 without a picker when they point nowhere; the
# notice set covers every statically linked runtime component plus the complete
# OpenAL Soft source; manifest.json carries contains_game_data/distribution and
# a playback line that says "UNVERIFIED on real Windows", all of which
# publish-owner-port-package.py requires. Keep them in step.

set -eu

root=$(cd "$(dirname "$0")/.." && pwd)
binary=""
run=""
deps=""
out=""
status=""
issues=""
guard_args=""
zig_root=""
# --public: a binary-only public package (own-code-only lane build required by
# the caller); only the distribution field and the owner-test wording change.
distribution=private-owner-only
kind=owner-test
nl='
'

while [ $# -gt 0 ]; do
    case "$1" in
        --binary) binary=$2; shift 2 ;;
        --run) run=$2; shift 2 ;;
        --deps) deps=$2; shift 2 ;;
        --out) out=$2; shift 2 ;;
        --status) status=$2; shift 2 ;;
        --known-issue) issues="$issues$2$nl"; shift 2 ;;
        --exe) guard_args="$guard_args --exe $2"; shift 2 ;;
        --extracted) guard_args="$guard_args --extracted $2"; shift 2 ;;
        --zig) zig_root=$2; shift 2 ;;
        --public) distribution=public-binary-only; kind=test; shift ;;
        *) echo "package_windows: unknown option $1" >&2; exit 2 ;;
    esac
done
[ -f "$binary" ] && [ -n "$run" ] && [ -d "$deps" ] && [ -n "$out" ] && [ -n "$status" ] || {
    echo "usage: $0 --binary FILE.exe --run N --deps DIR --out DIR --status TEXT [--known-issue TEXT ...] [--zig ZIG-ROOT]" >&2
    exit 2; }
case "$status" in
    *"UNVERIFIED on real Windows"*) ;;
    *) echo "package_windows: --status must say 'UNVERIFIED on real Windows' until a real-Windows gate exists" >&2; exit 2 ;;
esac

sdl="$deps/sdl2/SDL2-2.32.10"
oal="$deps/openal/openal-soft-1.25.1-bin"
oal_src="$deps/openal/openal-soft-1.25.1.tar.bz2"
[ -f "$sdl/x86_64-w64-mingw32/bin/SDL2.dll" ] && [ -f "$oal/bin/Win64/soft_oal.dll" ] && [ -f "$oal/LICENSE-pffft" ] || {
    echo "package_windows: SDL2 2.32.10 / OpenAL Soft 1.25.1 not unpacked under $deps" >&2; exit 2; }
[ -f "$oal_src" ] || {
    echo "package_windows: $oal_src (complete matching OpenAL Soft source) is missing; see deps/PROVENANCE.txt" >&2; exit 2; }
# The runtime notices come from the Zig install that linked the exe.
[ -n "$zig_root" ] || zig_root=$(zig env | python3 -c 'import json, os, sys; print(os.path.dirname(json.load(sys.stdin)["lib_dir"]))')
[ -f "$zig_root/LICENSE" ] && [ -f "$zig_root/lib/libc/mingw/COPYING" ] || {
    echo "package_windows: $zig_root is not a Zig install (pass --zig ZIG-ROOT)" >&2; exit 2; }
ref="$root/tools/windows/licenses-reference"

# Only the imports the port is allowed to have (docs/WINDOWS-PORT.md).
imports=$(objdump -p "$binary" | awk '/DLL Name:/ {print $3}')
for dll in $imports; do
    case "$dll" in
        SDL2.dll|OpenAL32.dll|KERNEL32.dll|USER32.dll|GDI32.dll|SHELL32.dll|ADVAPI32.dll|ole32.dll|\
        OPENGL32.dll|WINMM.dll|IMM32.dll|SETUPAPI.dll|VERSION.dll|api-ms-win-crt-*.dll) ;;
        *) echo "package_windows: unexpected import $dll" >&2; exit 1 ;;
    esac
done
# A stripped link is what drops LIBGTE's rcossin table (cmake/zig-windows.cmake).
objdump -h "$binary" | grep -q '\.debug' && {
    echo "package_windows: $binary carries debug sections; build with the zig-windows toolchain (stripped)" >&2
    exit 1; }

commit=${BFM_PKG_COMMIT:-$(git -C "$root" rev-parse --short=9 HEAD)}
branch=${BFM_PKG_BRANCH:-$(git -C "$root" rev-parse --abbrev-ref HEAD)}
name="bfm-r$run-$commit-windows-x64"
stage="$out/$name"
[ -e "$stage" ] && { echo "package_windows: $stage already exists" >&2; exit 2; }
mkdir -p "$stage/licenses/openal-soft-source"

cp "$binary" "$stage/musashi_native_boot.exe"
cp "$sdl/x86_64-w64-mingw32/bin/SDL2.dll" "$stage/"
# OpenAL Soft ships its x64 driver as soft_oal.dll; applications load OpenAL32.dll.
cp "$oal/bin/Win64/soft_oal.dll" "$stage/OpenAL32.dll"
cmp -s "$oal/bin/Win64/soft_oal.dll" "$stage/OpenAL32.dll"

# Notices: the dependencies' own texts, the complete OpenAL source, every runtime
# component the Zig toolchain links statically, and the GNU reference texts.
cp "$sdl/LICENSE.txt" "$stage/licenses/SDL2-LICENSE.txt"
cp "$oal/COPYING" "$stage/licenses/OpenAL-Soft-COPYING.txt"
cp "$oal/LICENSE-pffft" "$stage/licenses/OpenAL-PFFFT-LICENSE.txt"
cp "$oal_src" "$stage/licenses/openal-soft-source/"
cp "$root/LICENSE-NOTES.md" "$stage/licenses/"
[ -f "$root/tools/third_party/psycross/LICENSE" ] && cp "$root/tools/third_party/psycross/LICENSE" "$stage/licenses/PsyCross-LICENSE.txt"
cp "$zig_root/LICENSE" "$stage/licenses/Zig-MIT-LICENSE.txt"
cp "$zig_root/lib/libc/mingw/COPYING" "$stage/licenses/mingw-w64-COPYING.txt"
cp "$zig_root/lib/libunwind/LICENSE.TXT" "$stage/licenses/LLVM-libunwind-LICENSE.txt"
cp "$zig_root/lib/libcxx/LICENSE.TXT" "$stage/licenses/LLVM-libcxx-LICENSE.txt"
cp "$zig_root/lib/libcxxabi/LICENSE.TXT" "$stage/licenses/LLVM-libcxxabi-LICENSE.txt"
cp "$zig_root/lib/libc/musl/COPYRIGHT" "$stage/licenses/musl-COPYRIGHT.txt"
cp "$ref/compiler-rt-LICENSE.txt" "$stage/licenses/LLVM-compiler-rt-LICENSE.txt"
cp "$ref/mingw-DISCLAIMER.PD" "$stage/licenses/mingw-w64-DISCLAIMER.PD"
cp "$ref/GCC-RUNTIME-EXCEPTION.txt" "$stage/licenses/"
cp "$ref/GNU-GPL-3.txt" "$stage/licenses/"
{ echo "This is a Windows $kind package; UNVERIFIED on real Windows."
cat <<'TXT'
Game content and BIOS are excluded. The hybrid native-lane/interpreter
disclosure in README.txt still applies.

PsyCross: MIT; PsyCross-LICENSE.txt (unchanged).
SDL2 2.32.10: zlib; SDL2-LICENSE.txt (unchanged upstream notice).
OpenAL Soft 1.25.1: upstream LGPL; OpenAL-Soft-COPYING.txt.
The official Win64 soft_oal.dll is renamed OpenAL32.dll without modification.
Complete matching source is bundled; see OpenAL-SOURCE.txt. PFFFT, fmt and GSL
notices are supplied separately and in the source archive.

Statically linked runtime support from Zig 0.13.0:
- mingw-w64 CRT: mingw-w64-COPYING.txt, mingw-w64-DISCLAIMER.PD,
  mingw-w64-FILE-NOTICES.txt. The per-file notices include public-domain and
  permissively licensed components; ZPL is not asserted for every file.
- Zig compiler-rt: Zig-MIT-LICENSE.txt; math routines derived from musl are
  covered by musl-COPYRIGHT.txt. Zig builtins are not all LLVM compiler-rt.
- LLVM runtime/C++ support: full Apache-2.0 WITH LLVM-exception and legacy
  notices in LLVM-libunwind-LICENSE.txt, LLVM-libcxx-LICENSE.txt and
  LLVM-libcxxabi-LICENSE.txt. LLVM-compiler-rt-LICENSE.txt is also included
  as the LLVM builtin/runtime notice reference, without claiming that every
  covered component survives the stripped link.
- GNU-GPL-3.txt and GCC-RUNTIME-EXCEPTION.txt are provided as GNU runtime
  licence references for the upstream MinGW-built dependency distribution.
The system UCRT/Windows DLLs are imported, not copied into the package.

This package is produced by tools/package_windows.sh from the windows-port
tree; its notice set and launch.cmd contract equal the r40 owner-test package.
No real-Windows qualification, native-only execution or new route gate is claimed.
TXT
} > "$stage/licenses/THIRD-PARTY.txt"

# CRLF: cmd.exe reads labels and goto targets unreliably from LF-only files.
# This is the launcher-gated contract (0.9.241): BFM_DISC first, then
# BFM_DISC_DIR\disc.cue, and exit 66 with no picker when the launcher supplied
# either and it points nowhere; the picker/fallback search is only for
# standalone starts.
sed 's/$/\r/' > "$stage/launch.cmd" <<'CMD'
@echo off
rem Brave Fencer Musashi native port. Plays from your own disc image (.cue/.bin of
rem the USA disc, SLUS-00726); nothing from the game is in this package.
rem The disc is found in this order: %BFM_DISC% (a .cue or .bin), the one you picked
rem last time, disc\ next to this file, %USERPROFILE%\Games\brave-fencer-musashi\disc;
rem otherwise a file picker asks once and the choice is remembered.
setlocal DisableDelayedExpansion
set "HERE=%~dp0"
set "CONF=%APPDATA%\bfm-port"
if not exist "%CONF%" mkdir "%CONF%"
set "LOG=%CONF%\last-run.log"
rem Launcher-managed data: explicit env paths never fall through to a picker.
set "LAUNCHER_DISC="
if defined BFM_DISC set "LAUNCHER_DISC=1"
if defined BFM_DISC_DIR set "LAUNCHER_DISC=1"
set "DISC=%BFM_DISC%"
if defined DISC if not exist "%DISC%" set "DISC="
if not defined DISC if defined BFM_DISC_DIR if exist "%BFM_DISC_DIR%\disc.cue" set "DISC=%BFM_DISC_DIR%\disc.cue"
if defined LAUNCHER_DISC if not defined DISC goto :missing_launcher_disc
if not defined DISC if exist "%CONF%\disc.txt" set /p DISC=<"%CONF%\disc.txt"
if defined DISC if not exist "%DISC%" set "DISC="
if not defined DISC call :find "%HERE%disc"
if not defined DISC call :find "%USERPROFILE%\Games\brave-fencer-musashi\disc"
if not defined DISC for /f "usebackq delims=" %%F in (`powershell -NoProfile -Command "Add-Type -AssemblyName System.Windows.Forms; $d=New-Object System.Windows.Forms.OpenFileDialog; $d.Title='Choose your Brave Fencer Musashi (USA) .cue or .bin'; $d.Filter='Disc image|*.cue;*.bin'; if($d.ShowDialog() -eq 'OK'){$d.FileName}"`) do set "DISC=%%F"
if not defined DISC (
    echo bfm: No disc image found. Put your Brave Fencer Musashi ^(USA^) .cue and .bin in disc\ next to launch.cmd and start again.
    pause
    exit /b 66
)
> "%CONF%\disc.txt" <nul set /p "=%DISC%"
>> "%CONF%\disc.txt" echo.
rem Playable window, real-time guest clock, errors shown on screen.
if not defined MUSASHI_INTERACTIVE set MUSASHI_INTERACTIVE=1
if not defined MUSASHI_GUEST_CLOCK set MUSASHI_GUEST_CLOCK=1
if not defined MUSASHI_HOLD_WINDOW_MS set MUSASHI_HOLD_WINDOW_MS=3000
if not defined BFM_DEV_MENU (
    if exist "%CONF%\dev-menu-off" (set BFM_DEV_MENU=0) else (set BFM_DEV_MENU=1)
)
if not defined BFM_ROUTE_JOURNAL set "BFM_ROUTE_JOURNAL=%CONF%\route.jsonl"
echo bfm: running musashi_native_boot.exe> "%LOG%"
"%HERE%musashi_native_boot.exe" --disc "%DISC%" %* >> "%LOG%" 2>&1
set STATUS=%ERRORLEVEL%
if "%STATUS%"=="2" findstr /c:"could not start from your disc image" "%LOG%" >nul && del "%CONF%\disc.txt"
exit /b %STATUS%

:missing_launcher_disc
> "%LOG%" echo bfm: Launcher disc inputs are missing; restore the private data pack and retry.
exit /b 66

:find
for %%E in (cue bin) do for %%F in ("%~1\*.%%E") do if not defined DISC set "DISC=%%~fF"
exit /b 0
CMD

{
    echo "Brave Fencer Musashi native port $name (Windows 10/11 x64)"
    echo
    echo "Status: $status"
    [ -n "$issues" ] && { echo; echo "Known issues:"; printf '%s' "$issues" | sed 's/^/  - /'; }
    cat <<'TXT'

What this build is. The port runs the game's own logic as compiled host code
where the decompiled C has been admitted to the native lane, and runs the rest
in the port's interpreter of the original MIPS code. That interpreter is an
interim runtime, not the finished native port. Lane coverage on Windows equals
the Linux build of the same commit (the lane is generated from the same checks).

Your disc (none of the game is included). Put the .cue and .bin dump of your
Brave Fencer Musashi (USA, SLUS-00726) disc in disc\ next to launch.cmd, or pick
it when asked on first start; the choice is remembered in
%APPDATA%\bfm-port\disc.txt. A 2048-byte .iso does not work (no CD-XA data).
No BIOS is needed: the port provides its own kernel services.

Run launch.cmd. Saves: %APPDATA%\bfm-port (memory card bfm_card0.mcd).
Log of the last run: %APPDATA%\bfm-port\last-run.log (a PERF line every 10 s).
Controls and the dev menu are as in the Linux build (controller or keyboard;
Select+Start or F8 opens the dev menu; BFM_DEV_MENU=0 turns it off).

Packaging: tools/package_windows.sh (notice set and launcher disc-env contract
as the r40 owner-test package); UNVERIFIED on real Windows.
Matching OpenAL source and runtime notices are supplied under licenses/.

Launcher owner-data pack: game-root\disc\disc.cue with adjacent disc.bin.
BFM_DISC selects that cue; BFM_DISC_DIR resolves disc.cue without a picker.
Explicit missing launcher data returns 66 without prompting.
TXT
} > "$stage/README.txt"
sed -i 's/$/\r/' "$stage/README.txt"

python3 - "$stage" "$name" "$commit" "$branch" "$status" "$issues" "$imports" "$oal_src" "$zig_root" "$distribution" <<'PY'
import hashlib, json, os, pathlib, re, sys, tarfile
stage, name, commit, branch, status, issues, imports, oal_src, zig_root, distribution = sys.argv[1:]
lic = os.path.join(stage, "licenses")
sha = lambda b: hashlib.sha256(b).hexdigest()

# fmt and GSL notices come from the exact source archive we ship; check it is 1.25.1.
with tarfile.open(oal_src) as t:
    base = "openal-soft-1.25.1/"
    cmake = t.extractfile(base + "CMakeLists.txt").read().decode()
    assert re.search(r"project\(OpenAL[\s\S]*?VERSION\s+1\.25\.1\b", cmake, re.I), "not the 1.25.1 source"
    assert t.extractfile(base + "COPYING").read() == open(os.path.join(lic, "OpenAL-Soft-COPYING.txt"), "rb").read()
    assert t.extractfile(base + "LICENSE-pffft").read() == open(os.path.join(lic, "OpenAL-PFFFT-LICENSE.txt"), "rb").read()
    for rel, out in [("fmt-11.2.0/LICENSE", "OpenAL-fmt-LICENSE.txt"), ("gsl/LICENSE", "OpenAL-GSL-LICENSE.txt")]:
        open(os.path.join(lic, out), "wb").write(t.extractfile(base + rel).read())

# Every copyright/licence comment block in the mingw-w64 tree Zig links from.
# A superset on purpose: a stripped exe does not identify each CRT object.
blocks = {}
for p in sorted(pathlib.Path(zig_root, "lib", "libc", "mingw").rglob("*")):
    if not p.is_file():
        continue
    text = p.read_text(errors="replace")
    for block in re.findall(r"/\*[\s\S]*?\*/", text):
        if re.search(r"copyright|public domain|redistribution|permission.*granted|license|DISCLAIMER\.PD", block, re.I):
            blocks.setdefault(block, []).append(str(p.relative_to(zig_root)))
open(os.path.join(lic, "mingw-w64-FILE-NOTICES.txt"), "w").write(
    "Copyright/licence comment blocks from mingw-w64 shipped in Zig 0.13.0.\n"
    "This is a conservative superset; no per-object linkage claim is made.\n\n"
    + "\n\n".join("Files: " + ", ".join(paths) + "\n" + block for block, paths in blocks.items()))

dll_sha = sha(open(os.path.join(stage, "OpenAL32.dll"), "rb").read())
src_sha = sha(open(oal_src, "rb").read())
open(os.path.join(lic, "OpenAL-SOURCE.txt"), "w").write(f"""OpenAL Soft 1.25.1 matching source and replacement information

The bundled OpenAL32.dll is the unmodified bin/Win64/soft_oal.dll from:
https://openal-soft.org/openal-binaries/openal-soft-1.25.1-bin.zip
SHA256 of OpenAL32.dll: {dll_sha}
Its embedded FileVersion/ProductVersion and ALSOFT string identify 1.25.1.
It was verified byte-for-byte against the upstream Windows release archive.

The complete upstream 1.25.1 source (including CMake build files and notices)
is supplied alongside the binary in:
openal-soft-source/{os.path.basename(oal_src)}
SHA256: {src_sha}
Original source URL:
https://openal-soft.org/openal-releases/openal-soft-1.25.1.tar.bz2
Release: https://github.com/kcat/openal-soft/releases/tag/1.25.1
No Debian patches or unrelated version have been substituted.

See OpenAL-Soft-COPYING.txt, OpenAL-PFFFT-LICENSE.txt,
OpenAL-fmt-LICENSE.txt and OpenAL-GSL-LICENSE.txt.
OpenAL Soft is dynamically linked. You may modify/rebuild it and replace
OpenAL32.dll beside musashi_native_boot.exe with a compatible Win64 build.
Extract the supplied source; follow its README and CMakeLists.txt to configure
and build for x86-64 Windows using a C++20 compiler. The exact upstream binary
build is not claimed to be reproduced by this packaging check.
The replacement library must export the compatible OpenAL API.
""")

files = []
for dirpath, _, names in os.walk(stage):
    for n in names:
        p = os.path.join(dirpath, n)
        rel = os.path.relpath(p, stage).replace(os.sep, "/")
        if rel == "manifest.json":
            continue
        files.append({"path": rel, "size_bytes": os.path.getsize(p), "sha256": sha(open(p, "rb").read())})
files.sort(key=lambda f: f["path"])
manifest = {
    "package": name, "target": "Windows x64 (10/11)",
    "source_commit": commit, "source_branch": branch,
    "toolchain": "zig 0.13.0 (x86_64-windows-gnu, UCRT), cmake/zig-windows.cmake",
    "build_type": "RelWithDebInfo (stripped)", "native_lane": True,
    "runtime": "hybrid: native lane + interim MIPS interpreter",
    "playback": status,
    "known_issues": [i for i in issues.splitlines() if i],
    "imports": imports.split(),
    "disc_inputs": ["Existing owner-only data pack: game-root/disc/disc.cue, adjacent disc.bin; "
                    "launcher sets absolute BFM_DISC and BFM_DISC_DIR. No game data bundled. "
                    "Standalone starts: disc\\ next to launch.cmd, %USERPROFILE%\\Games\\brave-fencer-musashi\\disc, "
                    "or picked on first run"],
    "excluded": ["disc image and all other game data", "BIOS"],
    "launch": "launch.cmd [native port options]",
    "packaging_revision": "licenses1-discenv1",
    "contains_game_data": False,
    "distribution": distribution,
    "files": files,
}
json.dump(manifest, open(os.path.join(stage, "manifest.json"), "w"), indent=2)
open(os.path.join(stage, "manifest.json"), "a").write("\n")
PY

# shellcheck disable=SC2086
python3 "$root/tools/retail_guard.py" --stage "$stage" $guard_args || {
    echo "package_windows: retail guard failed; no zip written" >&2; exit 1; }
# Deterministic zip: fixed timestamps, 0644, sorted paths, one build-id root.
(cd "$out" && python3 -c "
import os, sys, zipfile
name = sys.argv[1]
paths = sorted(os.path.join(d, n) for d, _, ns in os.walk(name) for n in ns)
with zipfile.ZipFile(name + '.zip', 'w', zipfile.ZIP_DEFLATED, compresslevel=9) as z:
    for p in paths:
        info = zipfile.ZipInfo(p.replace(os.sep, '/'), (2026, 10, 3, 0, 0, 0))
        info.compress_type = zipfile.ZIP_DEFLATED
        info.external_attr = 0o100644 << 16
        z.writestr(info, open(p, 'rb').read(), compresslevel=9)
" "$name")
sha256sum "$out/$name.zip"
stat -c '%s bytes' "$out/$name.zip"
