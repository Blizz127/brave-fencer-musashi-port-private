/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_801567BC - byte-exact against retail at -O2 (tools/register_match.py). */
struct obj;
struct obj {
    u8 pad0[0x4];
    s16 unk4;
    u8 pad6[0x2];
    s32 unk8;
};
extern s32 D_801151E0[];
extern u8 D_8011DAD8[];
extern s32 func_8014C568(s16 *a0, s16 *a1);

void func_801567BC(s32 a0) {
    s32 obj = a0;
    s32 i = 0;
    u8 *q = D_8011DAD8;
    s32 *p = D_801151E0;
    do {
        if (*p & 1) {
            *(s16 *)(*(s32 *)(obj + 0x20) + 0x12) =
                ((s32 (*)(void *, void *))func_8014C568)((void *)obj, q);
        }
        q += 8;
        i += 1;
        p += 1;
    } while ((u32)i < 3);
}
