/* SC02.CD FILE_031 / ov_SC02_031 retail span [801582C0,80158344).
 * Offset 0x30168 at overlay base 80128158. SHA256(span)=e4e773f03bc00be7f7576b624a1e5bb7524fc3e56034618a0346d1ce9925a7fc.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/801582c0.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"
extern s32 D_800D52A8;
void func_80154274();
void func_80154A74();
void func_801585A4();
void func_8016706C();
void func_80146994();
void func_80147324();
void func_80146CA0();
typedef struct {
    u8 pad[0x44];
    u32 flags;
    u8 pad48[0x1AA-0x48];
    u8 f1AA;
} T;
void func_801582C0(T *p) {
    p->f1AA = 0x10;
    p->flags |= 2;
    func_80154274(p, &D_800D52A8);
    func_80154A74(p, 0x15);
    func_801585A4(p);
    func_8016706C(5);
    func_80146994(4, p, 8, 0);
    func_80147324(0x446);
    func_80146CA0(p);
}
