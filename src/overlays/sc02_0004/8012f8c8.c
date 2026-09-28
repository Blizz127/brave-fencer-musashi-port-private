/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8012F8C8 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_80131CA8(int a0, int a1);
extern void func_80131170();
extern void func_80131CA8();
extern void func_80131170(s32 a0, s32 a1, s32 a2);
extern u8 D_8017E058[];

void func_8012F8C8(u8* arg0) {
    *(u8*)(arg0 + 0xC1) = 7;
    if (*(u32*)(arg0 + 0xB4) & 0x80) {
        ((void (*)(void*, void*, s32))func_80131170)(arg0, D_8017E058, 0xB);
    }
    ((void (*)(void*, s32))func_80131CA8)(arg0, 0x16);
}
