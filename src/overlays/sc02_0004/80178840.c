/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80178840 - byte-exact against retail at -O2 (tools/register_match.py). */
struct S80131E00;
struct S80131E00 {
    char pad[0xB0];
    s32 field_B0;
};
extern void func_80019064(void *a0);
extern void func_80131E00(struct S80131E00 *a0, s32 a1);

void func_80178840(int param_1) {

    extern int D_80181520;
    extern int D_8018152C[];
    register int p __asm__("$16");
    register int s1byte __asm__("$17");
    p = param_1;
    if ((*(unsigned short *)(p + 0x5c) & 1) != 0) {
        s1byte = *(unsigned char *)(p + 0x5e);
        if (s1byte == 0xc) {
            ((void (*)(int))func_80019064)((int)&D_80181520);
        }
        ((void (*)(int, int))func_80131E00)(p, D_8018152C[s1byte]);
    }
}
