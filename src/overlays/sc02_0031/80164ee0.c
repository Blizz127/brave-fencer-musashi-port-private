/* SC02.CD FILE_031 / ov_SC02_031 retail span [80164EE0,80164F44).
 * Offset 0x3CD88 at overlay base 80128158. SHA256(span)=1123380f8ff95ca5e5cd535708908c39da58d875e6b079e475926d8e443cfa8b.
 * Same shape as the registry-verified MAIN member 0012 carve with only the
 * listed data references retargeted for this member: D_801843A4->D_801A46CC.
 * Oracle MATCH re-earned on this file; Not MAIN10.
 */
#include "psx_types.h"
void func_80165124();
void func_80146CA0();
extern s32 D_801A46CC;
typedef struct {
    u8 pad[0x2C]; s16 u2c, u2e;
    u8 pad30[0x30]; s16 u60, u62;
    u8 pad64[2]; s16 u66;
} T;
void func_80164EE0(T *p) {
    s32 i;
    for (i = 0x70; i >= 0; i -= 0x10) {
        *(s32 *)((u8 *)&D_801A46CC + i) = 0;
    }
    p->u2e = 0x4000;
    p->u2c = 0x4000;
    p->u60 = 0;
    p->u62 = 0;
    func_80165124(p);
    p->u66 = 0;
    func_80146CA0(p);
}
