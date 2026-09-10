/* SC02 resident retail span [8015FBE0,8015FCC8). Offset 0x37A88 at base 80128158.
 * SHA256(span)=a1eca0eee72a5ca0b6f32b11267b2625cfceb0d4e964c101451f10130cd829c9.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_80180A1C->D_8018730C.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
#include "psx_types.h"
typedef void (*CB)();
extern CB D_8018730C[];
void func_80147078();
void func_80159B70();
void func_80154150();
void func_80154A74();
void func_80146A6C();
void func_80147324();
void func_801553A8();
void func_801553C0();
void func_80146CA0();
extern u8 D_80078EC1;
extern s16 D_801270C0;
extern u8 D_800B9A17;
typedef struct { u16 idx; u8 pad[0x182]; s32 u184; } T;
void func_8015FBE0(T *p) {
    if (p->u184 < 0) {
        D_8018730C[p->idx](p);
        func_80147078(p, 0);
        func_80159B70(p);
    } else {
        D_80078EC1 = 0;
        func_80154150(p, 0x20);
        func_80154A74(p, 0x18);
        func_80146A6C(0x16, p, 0, 0, 0, 0, 0);
        func_80147324(0x44F);
        func_801553A8(p);
        func_801553C0(p);
        D_801270C0 = 2;
        D_800B9A17 = 0;
        func_80146CA0(p);
    }
}
