/* SC02.CD FILE_031 / ov_SC02_031 retail span [8015CCD0,8015CD20).
 * Offset 0x34B78 at overlay base 80128158. SHA256(span)=dc82c6620ad9004d4462ddffad4bd82c6e920a4781a2d2f400ed061d3ed7a55f.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8015ccd0.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"
void func_80154150();
void func_801725E0();
void func_80147324();
void func_80146CA0();
typedef struct {
    u8 pad_0[184];
    s16 fB8;
    u8 pad_BA[0x234-0xBA];
    s32 f234;
} T;
void func_8015CCD0(T *p) {
    func_80154150(p, 20);
    p->fB8 = 0;
    func_801725E0(p);
    p->f234 = 15;
    func_80147324(0x6A7);
    func_80146CA0(p);
}
