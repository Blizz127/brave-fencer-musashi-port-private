/* SC02.CD FILE_031 / ov_SC02_031 retail span [80136DFC,80136EC4).
 * Offset 0xECA4 at overlay base 80128158. SHA256(span)=9d1d1b52f4b501107e935807215708758578e84494189c63ff6cd378bc6f031e.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80136dfc.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"
void func_800153CC();
extern s16 D_80126B5E;
extern s16 D_80126B62;
extern s16 D_80126B66;
extern u16 D_80126CC4;
typedef struct { u8 pad[0x12]; s16 u12; } S;
extern S *D_80126B78;
void func_80136DFC(void) {
    func_800153CC(0xA, D_80126B5E, 0x110, 0x3C, 4, 0);
    func_800153CC(0xB, D_80126B62, 0x110, 0x44, 4, 0);
    func_800153CC(0xC, D_80126B66, 0x110, 0x4C, 4, 0);
    func_800153CC(0xD, D_80126B78->u12, 0x110, 0x54, 4, 0);
    func_800153CC(0xE, D_80126CC4, 0x110, 0x5C, 4, 0);
}
