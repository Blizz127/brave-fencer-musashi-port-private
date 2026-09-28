/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80150528 - byte-exact against retail at -O2 (tools/register_match.py). */
extern u8 D_801202A0[];
extern int func_80135A4C();
extern s32 func_80135A4C(s32 a0, s32 a1, s32 *a2, s32 a3);

s32 func_80150528(void *arg0, void *arg1, void *arg2)
{
    u8 *p = D_801202A0;
     




    if (p < D_801202A0 + 0x6480) {
        do {
            if (*(u16*)p != 0) {
                if ((*(u16*)(p + 0x5C) & 0x80) != 0) {
                    if (*(s32*)(p + 0x58) != 0) {
                        if (((s32 (*)(s32, s32, s32, s32))func_80135A4C)(
                                *(s32*)(p + 0x20), *(s32*)(p + 0x58),
                                (s32)arg1, (s32)arg2) != 0) {
                            *(s32*)((u8*)arg0 + 0x1A4) = (s32)p;
                            return 1;
                        }
                    }
                }
            }
            p += 0x10C;
        } while (p < D_801202A0 + 0x6480);
    }
    return 0;
}
