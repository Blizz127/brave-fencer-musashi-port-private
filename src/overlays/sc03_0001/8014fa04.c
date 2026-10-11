/* Overlay range [8014FA04,8014FA70) from MAIN.CD member 0012.
 * SHA256(span)=3f378be053345d7c1392377a38a58e020565cbb7d820de05247f0b153b160d93.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8014FA04 - byte-exact against retail at -O2 (tools/register_match.py). */
extern int D_801ED4DC;

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
            "lui   $at, %%hi(D_801ED4DC)\n"
            "sw    $v0, %%lo(D_801ED4DC)($at)\n"
            "addiu $sp, $sp, 4\n"
            "lw    $sp, 0($sp)\n"
            : "=r"(p) : "0"(p), "r"(arg) : "$8", "$9", "$31", "memory");
    }
    return D_801ED4DC;
}
