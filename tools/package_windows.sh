#!/bin/sh
# Package musashi_native_boot.exe for Windows x64 (cmake/zig-windows.cmake).
#
#   tools/package_windows.sh --binary BUILD-WIN/musashi_native_boot.exe --run N \
#       --deps DEPS --out DIR --status TEXT [--known-issue TEXT ...] \
#       [--exe YOUR/SLUS_007.26 --extracted YOUR/extracted/disc]
#
# Stages bfm-r<N>-<commit>-windows-x64/ (exe, SDL2.dll, OpenAL32.dll, launch.cmd,
# README, licenses, manifest.json with the size and SHA-256 of every file), runs
# tools/retail_guard.py over it and writes the .zip beside it. DEPS holds the
# approved SDL2/OpenAL Soft packages (docs/WINDOWS-PORT.md). No disc image,
# BIOS or game data is copied; --exe/--extracted feed the guard only.

set -eu

root=$(cd "$(dirname "$0")/.." && pwd)
binary=""
run=""
deps=""
out=""
status=""
issues=""
guard_args=""
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
        *) echo "package_windows: unknown option $1" >&2; exit 2 ;;
    esac
done
[ -f "$binary" ] && [ -n "$run" ] && [ -d "$deps" ] && [ -n "$out" ] && [ -n "$status" ] || {
    echo "usage: $0 --binary FILE.exe --run N --deps DIR --out DIR --status TEXT [--known-issue TEXT ...]" >&2
    exit 2; }

sdl="$deps/sdl2/SDL2-2.32.10"
oal="$deps/openal/openal-soft-1.25.1-bin"
[ -f "$sdl/x86_64-w64-mingw32/bin/SDL2.dll" ] && [ -f "$oal/bin/Win64/soft_oal.dll" ] || {
    echo "package_windows: SDL2 2.32.10 / OpenAL Soft 1.25.1 not unpacked under $deps" >&2; exit 2; }

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
mkdir -p "$stage/licenses"

cp "$binary" "$stage/musashi_native_boot.exe"
cp "$sdl/x86_64-w64-mingw32/bin/SDL2.dll" "$stage/"
# OpenAL Soft ships its x64 driver as soft_oal.dll; applications load OpenAL32.dll.
cp "$oal/bin/Win64/soft_oal.dll" "$stage/OpenAL32.dll"

cp "$sdl/LICENSE.txt" "$stage/licenses/SDL2-LICENSE.txt"
cp "$oal/COPYING" "$stage/licenses/OpenAL-Soft-COPYING.txt"
cp "$root/LICENSE-NOTES.md" "$stage/licenses/"
[ -f "$root/tools/third_party/psycross/LICENSE" ] && cp "$root/tools/third_party/psycross/LICENSE" "$stage/licenses/PsyCross-LICENSE.txt"
cat > "$stage/licenses/THIRD-PARTY.txt" <<'TXT'
PsyCross (MIT)              Psy-Q library reimplementation; see PsyCross-LICENSE.txt
SDL2 2.32.10 (zlib)         window, input, audio; SDL2.dll (libsdl.org release build)
OpenAL Soft 1.25.1 (LGPL-2.1)  audio; OpenAL32.dll (the release's bin/Win64/soft_oal.dll),
                            dynamically linked and replaceable; text in OpenAL-Soft-COPYING.txt;
                            source: https://openal-soft.org/ and github.com/kcat/openal-soft
Statically linked by the zig 0.13 toolchain into musashi_native_boot.exe:
  mingw-w64 CRT startup (ZPL / public domain), LLVM compiler-rt and libunwind
  (Apache-2.0 WITH LLVM-exception). The C runtime itself is the system UCRT.
The game is copyrighted by its rights holders and is not included.
TXT

# CRLF: cmd.exe reads labels and goto targets unreliably from LF-only files.
sed 's/$/\r/' > "$stage/launch.cmd" <<'CMD'
@echo off
rem Brave Fencer Musashi native port. Plays from your own disc image (.cue/.bin of
rem the USA disc, SLUS-00726); nothing from the game is in this package.
rem The disc is found in this order: %BFM_DISC% (a .cue or .bin), the one you picked
rem last time, disc\ next to this file, %USERPROFILE%\Games\brave-fencer-musashi\disc;
rem otherwise a file picker asks once and the choice is remembered.
setlocal
set "HERE=%~dp0"
set "CONF=%APPDATA%\bfm-port"
if not exist "%CONF%" mkdir "%CONF%"
set "LOG=%CONF%\last-run.log"
set "DISC=%BFM_DISC%"
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
> "%CONF%\disc.txt" echo %DISC%
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
TXT
} > "$stage/README.txt"
sed -i 's/$/\r/' "$stage/README.txt" "$stage/licenses/THIRD-PARTY.txt"

python3 - "$stage" "$name" "$commit" "$branch" "$status" "$issues" "$imports" <<'PY'
import hashlib, json, os, sys
stage, name, commit, branch, status, issues, imports = sys.argv[1:]
files = []
for dirpath, _, names in os.walk(stage):
    for n in names:
        p = os.path.join(dirpath, n)
        rel = os.path.relpath(p, stage).replace(os.sep, "/")
        if rel == "manifest.json":
            continue
        files.append({"path": rel, "size_bytes": os.path.getsize(p),
                      "sha256": hashlib.sha256(open(p, "rb").read()).hexdigest()})
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
    "disc_inputs": ["your own .cue/.bin of Brave Fencer Musashi (USA, SLUS-00726); "
                    "disc\\ next to launch.cmd, %USERPROFILE%\\Games\\brave-fencer-musashi\\disc, "
                    "or picked on first run"],
    "excluded": ["disc image and all other game data", "BIOS"],
    "launch": "launch.cmd [native port options]",
    "files": files,
}
json.dump(manifest, open(os.path.join(stage, "manifest.json"), "w"), indent=2)
open(os.path.join(stage, "manifest.json"), "a").write("\n")
PY

# shellcheck disable=SC2086
python3 "$root/tools/retail_guard.py" --stage "$stage" $guard_args || {
    echo "package_windows: retail guard failed; no zip written" >&2; exit 1; }
(cd "$out" && python3 -c "
import os, sys, zipfile
name = sys.argv[1]
with zipfile.ZipFile(name + '.zip', 'w', zipfile.ZIP_DEFLATED) as z:
    for d, _, ns in os.walk(name):
        for n in sorted(ns):
            z.write(os.path.join(d, n))
" "$name")
sha256sum "$out/$name.zip"
stat -c '%s bytes' "$out/$name.zip"
