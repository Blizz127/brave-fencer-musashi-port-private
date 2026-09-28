/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80135168 - byte-exact against retail at -O2 (tools/register_match.py). */
extern s32 D_8019F9B8;
int func_80134A74(int param_1, s16 param_2, s16 param_3, int param_4);
extern s16 *D_8017F694;
extern int D_8019F9B8;
extern u16 D_8019F9C8;
extern int func_80134A74(int, s16, s16, int);

int func_80135168(u16 arg0, u16 *p1, u16 *p2)
{
     


    extern u8 D_8017F68C;
    extern u8 D_8017F690;
    extern u8 D_8017F698;
    register s16 *pb0 __asm__("$8");
    register s16 *pac __asm__("$6");
    register s16 *pb8 __asm__("$7");
    u16 *pb4;
    u16 a, b;
    int a1v, a2v, d94;

    pb0 = (*(s16 * *)&D_8017F690);
    __asm__ __volatile__("" : : "r"(pb0));

    a = p2[0]; pac = (*(s16 * *)&D_8017F68C); pb0[0] = a; b = p1[0]; pb8 = (*(s16 * *)&D_8017F698); pac[0] = b; pb8[0] = a - b;
    a = p2[1]; pb0[1] = a; b = p1[1]; pac[1] = b; pb8[1] = a - b;
    a = p2[2]; pb0[2] = a; b = p1[2]; pac[2] = b; pb8[2] = a - b;

    a1v = pac[0]; a2v = pac[2]; d94 = D_8019F9B8;
    __asm__ __volatile__("" ::: "memory");
    D_8019F9C8 = 0;
    if (func_80134A74(arg0, a1v, a2v, d94)) {
        pb4 = (*(u16 * *)&D_8017F694);
        p2[0] = pb4[0];
        p2[1] = pb4[1];
        p2[2] = pb4[2];
        p2[3] = D_8019F9C8;
        return 1;
    }
    return 0;
}
