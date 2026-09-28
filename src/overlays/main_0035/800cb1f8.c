/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CB1F8 - byte-exact against retail at -O2 (tools/register_match.py). */


void func_800CB1F8(void *a0) {

    extern void func_8014C1A0(s32 arg0, s32 arg1);
    extern void func_80015978(s32 a0, s32 *a1);
    extern u16 func_80156370(u16 a0);
    extern void func_8014C4AC(s32 a0, s32 a1, s32 a2, s16 *a3, s32 a4);

    s32 iVar1;
    u16 uVar2;
    s16 buf[4];

    iVar1 = *(s32 *)((u8 *)a0 + 0x178);
    if (iVar1 != 0) {
        func_8014C1A0((s32)a0, iVar1);
        func_80015978(iVar1 + 4, (s32 *)buf);
        buf[3] = 0;
        uVar2 = func_80156370(0x29);
        func_8014C4AC(iVar1, 0x29, uVar2, buf, *(s16 *)(*(s32 *)((u8 *)a0 + 0x20) + 0x12));
        *(s32 *)((u8 *)a0 + 0x178) = 0;
    }
}
