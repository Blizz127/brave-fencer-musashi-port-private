/* SC02.CD member31 [8014FA04,8014FA70); exact word export. The C body is
 * the canonical indirect scratch-call form (as main_0012 8014FA04, which
 * differs only in the global), re-verified byte-identical against retail. */
#include "psx_types.h"
/* func_8014FA04 - byte-exact against retail at -O2 (tools/register_match.py). */
extern int D_801B6404;

s32 func_8014FA04(s32 a0)
{
    s32 lane_outgoing_args[4]; /* the 16-byte outgoing-argument area of the retail frame */
    if (*(s32 *)(a0 + 68) & 0x40000) {
        return 0;
    }
    {
        register s32 p __asm__("$5") = 0x1F8003FC;
        register s32 arg __asm__("$4") = a0;
        __asm__ __volatile__(
            "addu  $8, %0, $zero\n"
            "lw    $9, 0($8)\n"
            "nop\n"
            "sw    $sp, 0($9)\n"
            "addiu $9, $9, -4\n"
            "addu  $sp, $9, $zero\n"
            "jal   func_8014FA70\n"
            "lui   $at, %%hi(D_801B6404)\n"
            "sw    $v0, %%lo(D_801B6404)($at)\n"
            "addiu $sp, $sp, 4\n"
            "lw    $sp, 0($sp)\n"
            : "=r"(p) : "0"(p), "r"(arg) : "$8", "$9", "$31", "memory");
    }
    return D_801B6404;
}
