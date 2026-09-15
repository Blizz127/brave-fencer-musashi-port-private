/* Exact retail word export for [80061B58,80061C60); EXE and assembly verified. */
/* Verified byte-exact against retail by tools/match_function.py
 * (66/66 words at 0x80061B58). Types and signatures are whatever
 * reproduces the bytes; they are not evidence of the original
 * declaration. */
#include "psx_types.h"

void func_8005CEA8(s32);
extern s32 D_80078C3C;
extern s32 D_80078C40;
extern s32 D_80078C44;
extern s32 D_80078C48;
extern s32 D_80078C4C;
extern s32 D_80078C50;
extern s32 D_80078C54;
extern s32 D_80078C58;
extern volatile s32 D_80078C5C;
extern volatile s32 D_80078C60;
extern volatile s32 D_80078C64;
extern volatile s32 D_80078C68;
extern volatile s32 D_80078C6C;
extern volatile s32 D_80078C70;
extern volatile s32 D_80078C74;
extern volatile s32 D_80078C78;

void func_80061B58(void) {
    func_8005CEA8(D_80078C3C);
    func_8005CEA8(D_80078C40);
    func_8005CEA8(D_80078C44);
    func_8005CEA8(D_80078C48);
    func_8005CEA8(D_80078C4C);
    func_8005CEA8(D_80078C50);
    func_8005CEA8(D_80078C54);
    func_8005CEA8(D_80078C58);
    D_80078C5C = D_80078C60 = D_80078C64 = D_80078C68 = 0;
    D_80078C6C = D_80078C70 = D_80078C74 = D_80078C78 = 0;
}
