/* Complete SC02 retail span [8014607C,80146128): three scratchpad stack-switch calls. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8014607C - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"

extern s32 D_801B63F8;

void func_8014607C(void) {
    s32 lane_outgoing_args[4]; /* the 16-byte outgoing-argument area of the retail frame */
    register s32 p __asm__("$3") = 0x1F8003FC;
    __asm__ __volatile__(
        "addu  $8, %0, $zero\n"
        "sw    $sp, 0($8)\n"
        "addiu $8, $8, -4\n"
        "addu  $sp, $8, $zero\n"
        "jal   func_80146128\n"
        "lui   $at, %%hi(D_801B63F8)\n"
        "sw    $v0, %%lo(D_801B63F8)($at)\n"
        "addiu $sp, $sp, 4\n"
        "lw    $sp, 0($sp)\n"
        : "=r"(p) : "0"(p) : "$8", "$31", "memory");
    if (D_801B63F8 != 0) {
        register s32 q __asm__("$3") = 0x1F8003FC;
        __asm__ __volatile__(
            "addu  $8, %0, $zero\n"
            "sw    $sp, 0($8)\n"
            "addiu $8, $8, -4\n"
            "addu  $sp, $8, $zero\n"
            "jal   func_80146360\n"
            "addiu $sp, $sp, 4\n"
            "lw    $sp, 0($sp)\n"
            : "=r"(q) : "0"(q) : "$8", "$31", "memory");
        {
            register s32 r __asm__("$3") = 0x1F8003FC;
            __asm__ __volatile__(
                "addu  $8, %0, $zero\n"
                "sw    $sp, 0($8)\n"
                "addiu $8, $8, -4\n"
                "addu  $sp, $8, $zero\n"
                "jal   func_801463A0\n"
                "addiu $sp, $sp, 4\n"
                "lw    $sp, 0($sp)\n"
                : "=r"(r) : "0"(r) : "$8", "$31", "memory");
        }
    }
}
