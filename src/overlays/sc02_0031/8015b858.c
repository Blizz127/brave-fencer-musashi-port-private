/* SC02.CD FILE_031 / ov_SC02_031 retail span [8015B858,8015B8F8).
 * Offset 0x33700 at overlay base 80128158. SHA256(span)=21bf35751913b1ffcafb17cb49078bc0e42b46ed0bc7cea7008d2eee4851cb17.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8015b858.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"
s32 func_8014A51C();
void func_801477E8();
void func_80154274();
extern s32 D_800D4BE0;
extern s32 D_8011F730;
typedef struct {
    u8 pad[0xB4]; s32 uB4;
    u8 padB8[4]; u8 uBC;
    u8 padBD[0x109]; u8 u1C6;
    u8 pad1C7[0x75]; s32 u23C, u240;
    u8 u244;
} T;
s32 func_8015B858(T *p) {
    if (p->u1C6 || p->u240) {
        return 0;
    }
    if (func_8014A51C() == 0) {
        return 0;
    }
    p->u23C = p->uB4;
    p->u244 = p->uBC;
    func_801477E8(p, 0xFFF20000);
    func_80154274(p, &D_800D4BE0);
    D_8011F730 |= 2;
    return 1;
}
