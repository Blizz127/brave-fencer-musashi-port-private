/* SC02.CD member31 [80150A70,80150B28); exact word export. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80150A70 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"

extern s32 D_801B6404;
extern void func_80015978(void *a0, void *a1);

/* B28: C plus the scratchpad switch-back asm; byte-identical (gcc-2.7.2-psx -O2). */
void func_80150A70(u8 *a0) {
    register u8 *s __asm__("$16") = a0;
    if (*(s16 *)(s + 6) != *(s16 *)(s + 0x88) || *(s16 *)(s + 0xA) != *(s16 *)(s + 0x8A) ||
        *(s16 *)(s + 0xE) != *(s16 *)(s + 0x8C)) {
        if ((*(s32 *)(s + 0x44) & 0x40000) == 0) {
            register s32 p __asm__("$6") = 0x1F8003FC;
            __asm__ __volatile__(
                ".set\tnoreorder\n"
                "addu  $8, %0, $zero\n"
                "lw    $9, 0($8)\n"
                "nop\n"
                "sw    $sp, 0($9)\n"
                "addiu $9, $9, -4\n"
                "addu  $sp, $9, $zero\n"
                "jal   func_8014FA70\n"
                "addu  $4, %2, $zero\n"
                "lui   $at, %%hi(D_801B6404)\n"
                "sw    $v0, %%lo(D_801B6404)($at)\n"
                "addiu $sp, $sp, 4\n"
                "lw    $sp, 0($sp)\n"
                ".set\treorder\n"
                : "=r"(p) : "0"(p), "r"(s) : "$4", "$8", "$9", "$31", "memory");
        }
        func_80015978(s + 4, s + 0x88);
    }
}
