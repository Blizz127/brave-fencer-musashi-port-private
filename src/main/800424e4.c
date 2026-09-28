/* Exact retail word export for [800424E4,80042580); EXE and assembly verified. */
/* Sony PsyQ library routine (vendor/bfm-decomp keeps it as INCLUDE_ASM); C written from the retail disassembly. */
#include "psx_types.h"

/* func_800424E4 - byte-exact against retail at -O2 (tools/register_match.py). */

extern volatile s32 D_8006CBB8;
extern char D_80073514[];
extern void func_8005CD48(char *);
extern void func_8005CF48(s32);
extern void func_8005CF58(s32, s32);
void func_800424E4(s32 target, s32 timeout)
{
    volatile s32 cnt = timeout << 15;

    while (D_8006CBB8 < target) {
        if (--cnt == -1) {
            func_8005CD48(D_80073514);
            func_8005CF48(0);
            func_8005CF58(3, 0);
            return;
        }
    }
}
