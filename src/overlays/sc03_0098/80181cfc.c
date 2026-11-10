/* sc03_0098: func_80181CFC - probe two table positions, then emit an effect if the actor test passes.
 * Hand-recovered from the retail words (gcc-2.7.2 -O2). */
#include "psx_types.h"
extern u8 *D_80126B78;
extern u8 D_8019E1F8[];
extern u8 D_801152A8[];
extern void func_8012F14C();
extern s32 func_80135888();
extern void func_8012F568();
typedef struct {
    u8 pad0[0x20]; struct { u8 pad[0x12]; s16 h12; } *p20; u8 pad24[0x34];
    s32 f58; u8 pad5c[0x14]; u16 f70;
} Obj;
s32 func_80181CFC(Obj *p, s32 a1) {
    s32 v[2];
    s32 w[2];
    func_8012F14C(D_80126B78 + 0x34, D_8019E1F8, v);
    func_8012F14C(D_80126B78 + 0x34, D_8019E1F8 + 8, w);
    if (func_80135888(p->p20, p->f58, v, w) == 0) {
        return 0;
    }
    func_8012F568(1, (p->f70 & 0xF) ? 0x2001 : 1, p->p20->h12, a1, w, D_801152A8);
    return 1;
}
