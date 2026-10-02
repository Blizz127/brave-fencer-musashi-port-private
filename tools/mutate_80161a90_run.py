#!/usr/bin/env python3
"""Run the overlay probe for main_0012 80161A90 only (helper of mutate_80161a90.sh; env B=build dir)."""
import os, subprocess, sys
sys.path.insert(0, "tests")
import test_native_lane_overlay as t
p = t.load_plan("main_0012")
env = dict(os.environ, OVERLAY_PROBE_ONLY="80161A90")
r = subprocess.run([os.environ["B"] + "/musashi_native_lane_overlay_probe", "extracted/disc/files/SLUS_007.26",
                    "main_0012", str(p["file"]), f"{p['vram']:x}", f"{p['start']:x}", f"{p['load_off']:x}",
                    f"{p['load_end']:x}"], capture_output=True, text=True, env=env)
sys.stdout.write(r.stdout + r.stderr)
