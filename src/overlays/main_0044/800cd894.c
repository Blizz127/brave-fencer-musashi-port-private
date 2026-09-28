/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CD894 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_80015978(s32 a0, s32 *a1);
extern s32 func_80135260(s32 a0, s32 a1, s32 a2, s32 a3);
extern u8 D_801202A0[];
typedef struct {
    u16 unk00;
    u8 pad02[0x1E];
    s32 unk20;
    u8 pad24[0x34];
    s32 unk58;
    u8 pad5C[0xB0];
} Ent_CD894;

s32 func_800CD894(void *a0) {
    u8 sp10[8];
    s32 sp18;
    s32 i;
    register s32 tag __asm__("$2");
    Ent_CD894 *base = (Ent_CD894 *)D_801202A0;

    __builtin_memcpy(sp10, (u8 *)a0 + 0x44, 8);
    func_80015978((s32)a0 + 4, &sp18);
    for (i = 0; i < 0x60; i++) {
        Ent_CD894 *e = base + i;
        tag = 0x200;
        if (e->unk00 == tag) {
            s32 f58 = e->unk58;
            if (f58 != 0) {
                s32 f20 = e->unk20;
                if (f20 != 0 && func_80135260(f20, f58, sp10, &sp18) != 0) {
                    return 1;
                }
            }
        }
    }
    return 0;
}
