/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8012E28C - byte-exact against retail at -O2 (tools/register_match.py). */
#define AddPrim func_80058C6C
#define GetTPage func_80058B40
extern s32 AddPrim(s32, void *);
extern void *func_80010A08(s32);
extern s32 D_800A651C;
extern s16 D_800B9A02;
extern s32 GetTPage(s32, s32, s32, s32);
extern s32 func_8005A600(s32, s32, s32, s32, s32);

void func_8012E28C(s32 arg0, s32 arg1) {
    void *temp_v0;
    s32 temp_v1;
    s32 base;
    if (arg0 > 0) {
        base = *(s32 *)((s8 *)&D_800A651C + ((u16)D_800B9A02 * 0x14)) + (arg0 * 4);
        temp_v0 = func_80010A08(0xC);
        temp_v1 = GetTPage(0, arg1, 0, 0);
        func_8005A600((s32)temp_v0, 0, 0, (u16)temp_v1, 0);
        AddPrim(base, temp_v0);
    }
}
