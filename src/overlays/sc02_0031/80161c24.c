/* SC02.CD FILE_031 / ov_SC02_031 retail span [80161C24,80161C98).
 * Offset 0x39ACC at overlay base 80128158. SHA256(span)=a041a8261c33ca97797b4c336de67dd5bfed2d519c57fdfae3ea8e065174f993.
 * Same shape as the registry-verified MAIN member 0012 carve with the data
 * array retargeted for this member: D_80180E38->D_801816C0 (+0x888 block).
 * Oracle MATCH re-earned on this file; Not MAIN10.
 */
#include "psx_types.h"
void func_80147324();
typedef struct { u16 a, b; } E;
extern E D_801816C0[];
typedef struct { u8 pad[0xDA]; u8 uDA; } T;
void func_80161C24(T *p, u32 a1) {
    if (a1 >= 8) {
        return;
    }
    if (p->uDA) {
        func_80147324(D_801816C0[a1].a);
        p->uDA = 0;
        return;
    }
    func_80147324(D_801816C0[a1].b);
    p->uDA = 1;
}
