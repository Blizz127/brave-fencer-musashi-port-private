/* Overlay range [8012D664,8012D714) from MAIN.CD member 0012.
 * SHA256(span)=c231a14ec0c5321ffdf04b84a496655f3e7931cf9102a8b21d6134012992c2f6.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8012D664 - byte-exact against retail at -O2 (tools/register_match.py). */
u8 *arg2;
extern u16 D_80126B5E;
extern u16 D_80126B62;
extern u16 D_80126B66;
extern s32 func_800132BC(s32 a0, s32 a1);

int func_8012D664(int arg0, int arg1, int arg2)
{
    extern u16 D_80126B5E;
    extern u16 D_80126B62;
    extern u16 D_80126B66;
    extern s32 func_800132BC(s32 a0, s32 a1);
    extern void func_8012F568(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4, s32 a5);
    extern u8 D_8017E6BC[];

    u16 s[3];
    int ret;
    int t;

    s[0] = (*(unsigned short *)&D_80126B5E);
    s[1] = (*(unsigned short *)&D_80126B62) - 0x40;
    s[2] = (*(unsigned short *)&D_80126B66);
    ret = ((int (*)())func_800132BC)(arg0, s);
    t = arg1 + 0x20;
    if (ret < t * t) {
        func_8012F568(1, 1, 0, arg2, arg0, &D_8017E6BC);
        return 1;
    }
    return 0;
}
