/* SC02.CD FILE_031 / ov_SC02_031 retail span [80157AC8,80157B74).
 * Offset 0x2F970 at overlay base 80128158. SHA256(span)=18407fef9ba17811e97436ac7aa92099293a674858670139a96977b9f6ea883e.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80157ac8.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"
void func_80147AD4();
void func_801473EC();
s32 func_80161208();
void func_8016706C();
void func_80154274();
void func_80146CA0();
void func_80155FF8();
void func_801725A4();
extern s32 D_800D51AC;
typedef struct {
    u8 pad[0x2C]; s32 u2C;
    u8 pad30[0x14]; s32 flags;
    u8 pad48[0x162]; u8 u1AA;
} T;
void func_80157AC8(T *p) {
    p->flags |= 2;
    func_80147AD4(p, 0, 0, 0x10000);
    func_801473EC(p);
    if (func_80161208(p) == 0) {
        if (p->u2C > 0) {
            func_8016706C(4);
            func_8016706C(5);
            func_80154274(p, &D_800D51AC);
            func_80146CA0(p);
        } else {
            func_80155FF8(p, p->u1AA);
            func_801725A4(p);
        }
    }
}
