/* SC02.CD FILE_031 / ov_SC02_031 retail span [80128940,80128998).
 * Offset 0x7E8 at overlay base 80128158. SHA256(span)=0c7720fe33c61043f327e5f349e26bfce163729f2d7f37ae208d19d15165e166.
 * Same shape as the registry-verified MAIN member 0012 carve with only the
 * listed data references retargeted for this member: D_80182D1C->D_801A3234.
 * Oracle MATCH re-earned on this file; Not MAIN10.
 */
#include "psx_types.h"
void func_8001ABBC();
typedef struct { s32 a; void *b; } S;
extern S D_800C7C60;
extern s32 D_800A2E20;
extern void *D_801A3234;
extern s32 D_800AF560;
void func_80128940(void) {
    D_800C7C60.a = 94;
    D_800C7C60.b = &D_800A2E20;
    func_8001ABBC(0, 0, &D_800AF560, D_801A3234, &D_800C7C60);
}
