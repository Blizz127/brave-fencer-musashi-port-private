/* SC02.CD FILE_031 / ov_SC02_031 retail span [80172414,8017248C).
 * Offset 0x4A2BC at overlay base 80128158. SHA256(span)=7a63f14ef2f038606fde49dfe25c962bf94cf77c527f2b8860d56a36687eae30.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80172414.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"
void func_80161C24();
void func_8014C010();
extern u16 D_800B99DA;
typedef struct {
    u8 pad[0x2C]; s32 u2C;
    u8 pad30[0x88]; u16 b8;
    u8 padBA[0xB4]; u16 u16E;
} T;
void func_80172414(T *p) {
    if (p->b8 & 0x2000) {
        func_80161C24(p, p->u16E);
    }
    if (p->u2C < (s32)0xFFF90000) {
        if ((D_800B99DA & 7) == 0) {
            func_8014C010(p, 2);
        }
    }
}
