#!/bin/sh
# Headless live boot of musashi_native_boot: no display, no sound card.
#
#   tools/run_headless_boot.sh --binary BUILD/musashi_native_boot \
#       --disc DIR/extracted/disc [--out DIR] [--timeout SECS]
#       [--capture-every N] [--host-clock] [--no-preload] [-- extra args]
#
# DIR/extracted/disc must hold files/SLUS_007.26, disc.cue and disc.bin (your
# own disc). Everything written goes to --out (default: headless-out/ in the
# repository, git-ignored); it must be outside the repository or ignored: egl.json, alsa.conf, the capture shim,
# out.log, trace/trace.counts, frames.log, frame_*.png, vram_*.png.
#
# What each setting does (see docs/ARCHITECTURE-PORT.md, "Headless live
# boot"). Two of them PAPER OVER REAL ISSUES and are marked WORKAROUND:
#   SDL_VIDEODRIVER=offscreen + Mesa EGL (egl.json, EGL_PLATFORM=surfaceless)
#                     a real GL context without a display (llvmpipe)
#   LIBGL_ALWAYS_SOFTWARE unset
#                     setting it crashes Mesa 25.0's EGL in SDL_CreateWindow
#   ALSA null PCM (alsa.conf, SDL_AUDIODRIVER=alsa)
#                     WORKAROUND: native_boot's audio gate refuses SDL's dummy
#                     and disk drivers on purpose; a null PCM satisfies it
#                     without any real audio output
#   MUSASHI_CODE_IMAGE=<the EXE>
#                     required; without it the run refuses at 80010000 and
#                     prints no reason (the missing print is a real issue)
#   MUSASHI_GUEST_CLOCK=1 (default; --host-clock turns it off)
#                     on a loaded host the host-paced clock ends the run with
#                     a silent IRQ-dispatch refusal in the SPU poll loop
#   LD_PRELOAD Mesa libEGL/libEGL_mesa/libgallium (--no-preload skips)
#                     WORKAROUND: PsyCross GR_Shutdown calls GL after Mesa's
#                     EGL libraries were unloaded and segfaults on every exit
#                     (losing trace.counts); preloading keeps them mapped
#   bfm_swap_capture.so (LD_PRELOAD, BFM_CAPTURE_*)
#                     per-frame non-black counts and periodic PNGs of the
#                     presented frame and PsyCross's VRAM
# BFM_HOST_DEPS (default ~/opt/host-port-deps/usr) supplies the Mesa/SDL/ALSA
# libraries.
set -eu
here=$(cd "$(dirname "$0")" && pwd)
root=$(cd "$here/.." && pwd)
deps=${BFM_HOST_DEPS:-$HOME/opt/host-port-deps/usr}
lib=$deps/lib/x86_64-linux-gnu
binary= disc= out= timeout=600 every=600 guest=1 preload=1
while [ $# -gt 0 ]; do
    case $1 in
    --binary) binary=$2; shift 2 ;;
    --disc) disc=$2; shift 2 ;;
    --out) out=$2; shift 2 ;;
    --timeout) timeout=$2; shift 2 ;;
    --capture-every) every=$2; shift 2 ;;
    --host-clock) guest=0; shift ;;
    --no-preload) preload=0; shift ;;
    --) shift; break ;;
    *) echo "run_headless_boot: unknown option $1" >&2; exit 2 ;;
    esac
done
[ -n "$out" ] || out=$root/headless-out
[ -n "$binary" ] && [ -n "$disc" ] || {
    echo "usage: $0 --binary PATH --disc EXTRACTED_DISC_DIR --out DIR [--timeout S]" >&2; exit 2; }
exe=$disc/files/SLUS_007.26
for f in "$binary" "$exe" "$disc/disc.cue" "$disc/disc.bin" "$lib/libEGL_mesa.so.0"; do
    [ -e "$f" ] || { echo "run_headless_boot: missing $f" >&2; exit 2; }
done
out=$(realpath -m "$out")
# never write into the tracked tree (checked before anything is created)
if git -C "$root" rev-parse --is-inside-work-tree >/dev/null 2>&1; then
    case $out/ in
    "$root"/*) git -C "$root" check-ignore -q "$out/" || {
        echo "run_headless_boot: --out is inside the repository and not ignored" >&2; exit 2; } ;;
    esac
fi
mkdir -p "$out"

printf '{"file_format_version":"1.0.0","ICD":{"library_path":"%s/libEGL_mesa.so.0"}}\n' "$lib" > "$out/egl.json"
printf 'pcm.!default {\n    type null\n}\n' > "$out/alsa.conf"

shim=$out/bfm_swap_capture.so
cc -std=c99 -O2 -shared -fPIC -I"$root/pc_port/platform" "$here/headless/bfm_swap_capture.c" \
    "$root/pc_port/platform/bfm_plat_image.c" -o "$shim" -ldl
vram_off=$(nm "$binary" 2>/dev/null | awk '$3 == "vram" && ($2 == "B" || $2 == "b") {print $1; exit}')

pre=$shim
if [ "$preload" = 1 ]; then
    gallium=$(ls "$lib"/libgallium-*.so 2>/dev/null | head -1)
    pre="$lib/libEGL.so.1:$lib/libEGL_mesa.so.0${gallium:+:$gallium}:$shim"
fi
clock=
[ "$guest" = 1 ] && clock=MUSASHI_GUEST_CLOCK=1

echo "run_headless_boot: $binary -> $out (timeout ${timeout}s, guest clock $guest, preload $preload)"
cd "$out"
set +e
env -u LIBGL_ALWAYS_SOFTWARE -u DISPLAY -u WAYLAND_DISPLAY \
    LD_LIBRARY_PATH="$lib" LD_PRELOAD="$pre" \
    SDL_VIDEODRIVER=offscreen EGL_PLATFORM=surfaceless __EGL_VENDOR_LIBRARY_FILENAMES="$out/egl.json" \
    SDL_AUDIODRIVER=alsa ALSA_CONFIG_PATH="$out/alsa.conf" XDG_RUNTIME_DIR="$out" \
    MUSASHI_CODE_IMAGE="$exe" MUSASHI_BOOT_AUTO_START=1 MUSASHI_HOLD_WINDOW_MS=0 \
    MUSASHI_TRACE_REFUSAL=1 MUSASHI_TRACE_FUNCS="$out/trace" $clock \
    BFM_CAPTURE_DIR="$out" BFM_CAPTURE_EVERY="$every" BFM_CAPTURE_VRAM_OFFSET="$vram_off" \
    timeout "$timeout" "$binary" "$exe" "$disc/disc.cue" "$disc/disc.bin" "$@" > "$out/out.log" 2>&1
status=$?
set -e

echo "exit: $status$( [ $status = 124 ] && echo ' (timeout)')"
grep -m1 "EXECUTION_BOUNDARY" out.log || true
grep -m1 "RUN_REFUSED\|CHECKPOINT_REFUSED" out.log || true
grep -m1 "CPU_BOUNDARY" out.log | cut -c1-120 || true
for m in TITLE_LOAD SCENE1_REACHED RENDER_ENTER CALL_80159C84; do
    n=$(grep -c "native_boot: $m" out.log || true)
    [ "$n" -gt 0 ] && echo "marker $m: $n (first: $(grep -m1 "native_boot: $m" out.log | cut -c1-90))"
done
if [ -s frames.log ]; then
    echo "frames presented: $(wc -l < frames.log)"
    awk '$3 > 0 {print "first non-black frame: " $1 " at " $2 " s (" $3 " px of " $4 "x" $5 ")"; exit}' frames.log
fi
if [ -s trace.counts ]; then
    echo "traced functions: $(($(wc -l < trace.counts) - 1)), top:"
    sed -n 2,11p trace.counts
elif [ -s trace ]; then
    echo "traced functions (first entries): $(($(wc -l < trace) - 1))"
fi
exit 0
