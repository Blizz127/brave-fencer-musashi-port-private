#!/usr/bin/env python3
"""DEV-ONLY stale-resume audit (never committed, never in a release build): compiled only with
-DMUSASHI_LANE_RESUME_AUDIT=1. Each guest call from native code classifies the resume pc it consumes:
zero, the retail jal at resume-8 targets this callee (match), a jalr there (unverifiable), or stale.
Reports at the run's execution boundary. Anchored, count-checked edits of a scratch export.
  patch_resume_audit.py TREE"""
import sys
from pathlib import Path

root = Path(sys.argv[1])


def rep(path, old, new):
    p = root / path
    s = p.read_text()
    if s.count(old) != 1:
        sys.exit(f"{path}: anchor x{s.count(old)}: {old[:80]!r}")
    p.write_text(s.replace(old, new))


AUDIT = r'''#ifdef MUSASHI_LANE_RESUME_AUDIT
/* DEV-ONLY: classify the resume pc a guest call consumes. Retail: the word
 * at resume - 8 is the jal to this callee, or a jalr; anything else means a
 * stale value (IRQ-GAP-D011 P1 counter). A stale jalr-site value cannot be
 * told apart from a fresh one. */
static uint64_t g_ra_calls, g_ra_zero, g_ra_jal, g_ra_jalr, g_ra_stale;
static struct { uint32_t resume, target, n; } g_ra_pair[64];
static unsigned g_ra_npair;
static void lane_resume_audit(MusashiBootMemory *memory, uint32_t resume, uint32_t target) {
    uint32_t w = 0, k;
    ++g_ra_calls;
    if (!resume) { ++g_ra_zero; return; }
    if (musashi_boot_read32(memory, resume - 8u, &w)) {
        if ((w >> 26) == 3u && ((((resume - 8u) & 0xF0000000u) | ((w & 0x03FFFFFFu) << 2)) == target)) {
            ++g_ra_jal;
            return;
        }
        if ((w >> 26) == 0u && (w & 0x3Fu) == 9u) { ++g_ra_jalr; return; }
    }
    ++g_ra_stale;
    for (k = 0; k < g_ra_npair; ++k)
        if (g_ra_pair[k].resume == resume && g_ra_pair[k].target == target) { ++g_ra_pair[k].n; return; }
    if (g_ra_npair < 64u) {
        g_ra_pair[g_ra_npair].resume = resume;
        g_ra_pair[g_ra_npair].target = target;
        g_ra_pair[g_ra_npair].n = 1u;
        ++g_ra_npair;
    }
}
void musashi_lane_resume_audit_report(void) {
    unsigned k;
    fprintf(stderr, "native_boot: LANE_RESUME_AUDIT guest_calls=%llu resume_zero=%llu jal_match=%llu jalr=%llu "
            "stale=%llu pairs=%u\n", (unsigned long long)g_ra_calls, (unsigned long long)g_ra_zero,
            (unsigned long long)g_ra_jal, (unsigned long long)g_ra_jalr, (unsigned long long)g_ra_stale, g_ra_npair);
    for (k = 0; k < g_ra_npair; ++k)
        fprintf(stderr, "native_boot: LANE_RESUME_STALE resume=%08x target=%08x calls=%u\n",
                g_ra_pair[k].resume, g_ra_pair[k].target, g_ra_pair[k].n);
}
#endif
uint32_t musashi_native_guest_call(uint32_t target, unsigned argc,'''

rep("pc_port/mips_formatter.c", "uint32_t musashi_native_guest_call(uint32_t target, unsigned argc,", AUDIT)
rep("pc_port/mips_formatter.c",
    "    resume = musashi_lane_resume_pc;\n    musashi_lane_resume_pc = 0;\n",
    "    resume = musashi_lane_resume_pc;\n    musashi_lane_resume_pc = 0;\n"
    "#ifdef MUSASHI_LANE_RESUME_AUDIT\n    lane_resume_audit(active->memory, resume, target);\n#endif\n")
rep("pc_port/native_boot.c",
    "#ifdef MUSASHI_NATIVE_LANE_TABLE\n    lane_overlay_report();\n#endif\n",
    "#ifdef MUSASHI_NATIVE_LANE_TABLE\n    lane_overlay_report();\n#endif\n"
    "#ifdef MUSASHI_LANE_RESUME_AUDIT\n    { extern void musashi_lane_resume_audit_report(void); musashi_lane_resume_audit_report(); }\n#endif\n")
print("audit patch applied to", root)
