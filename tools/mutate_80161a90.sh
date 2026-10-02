#!/bin/sh
# Mutation check for the main_0012 80161A90 overlay probe patterns.
# Usage: tools/mutate_80161a90.sh BUILD_DIR   (a configured -DMUSASHI_NATIVE_LANE=ON build)
# Edits src/overlays/main_0012/80161a90.c one mutant at a time, rebuilds the probe,
# runs the probe on that entry only, prints the DIFFERENT / cycle-different counts,
# and restores the file with git checkout (aborts if it was dirty beforehand).
set -u
B=$1; F=src/overlays/main_0012/80161a90.c
cd "$(dirname "$0")/.." || exit 2
git diff --quiet -- $F || { echo "refusing: $F is modified"; exit 2; }
trap 'git checkout -q -- $F' EXIT INT TERM
run() { # name sed-expr
  git checkout -q -- $F; sed -i "$2" $F
  if git diff --quiet -- $F; then echo "$1: MUTATION DID NOT APPLY"; return; fi
  nice -n 10 cmake --build "$B" -j4 --target musashi_native_lane_overlay_probe >/dev/null 2>&1 || { echo "$1: build failed"; return; }
  out=$(B=$B python3 tools/mutate_80161a90_run.py 2>&1)
  d=$(echo "$out" | grep -c 'positive: DIFFERENT')
  echo "$1: probe DIFFERENT=$d; $(echo "$out" | grep '^overlay_cycles: main_0012__func_80161A90 .*same=' | sed 's/.*80161a90 //')"
}
run "timer-- -> timer -= 2" 's/obj->timer--;/obj->timer -= 2;/'
run "mode compare #1 (D_80078EC0) ==6 -> ==7" '0,/== 6;/s//== 7;/'
run "mode compare #2 (gs->mode) ==6 -> ==7" 's/(gs->mode \& 0x7F) == 6/(gs->mode \& 0x7F) == 7/'
run "0x7F -> 0xFF (both masks)" 's/0x7F/0xFF/g'
run "0x7F -> 0xFF (first mask only)" '0,/0x7F/s//0xFF/'
run "0x7F -> 0xFF (second mask only)" 's/(gs->mode \& 0x7F)/(gs->mode \& 0xFF)/'
run "0x3B -> 0x3C" 's/0x3B/0x3C/'
run "drop the decrement" 's/obj->timer--;/;/'
git checkout -q -- $F
