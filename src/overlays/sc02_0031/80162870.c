/* SC02 resident retail span [80162870,801628F4). Offset 0x3A718 at base 80128158.
 * SHA256(span)=b49d7dd853c479081636a4801dedf0f44c9704870e197ef4e2a7d15af0c46ff5.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_80180F18->D_80187808.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
#include "psx_types.h"
void func_8001CB6C();
void func_80162968();
void func_80162ACC();
extern s32 D_800B5CB8;
extern s32 D_80187808;
extern void *D_800B5CEC;
extern u8 D_800B5CDF;
extern s32 D_800B5CBC;
typedef struct { u8 pad[8]; void *p8; } T;
void func_80162870(T *p) {
    p->p8 = &D_800B5CB8;
    func_8001CB6C(&D_800B5CB8, &D_80187808, 0x250, 0x1A0);
    D_800B5CEC = (u8 *)p + 0xC;
    D_800B5CDF = 0x14;
    D_800B5CBC |= 0x60000000;
    func_80162968(p);
    func_80162ACC(p);
}
