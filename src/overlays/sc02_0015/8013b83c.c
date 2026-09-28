/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8013B83C - byte-exact against retail at -O0 (tools/register_match.py). */
typedef struct {
        s32 f0;
        u16 f4;
        u16 f6;
        u16 f8;
        u16 fA;
        s32 fC;
        u8  pad[8];
        s32 f18;
    } Ent_8013B83C;
extern s32 D_80190630;
extern s32 D_80190694;

void func_8013B83C(s32 a0, s32 a1, s32 a2) {
                        
    extern Ent_8013B83C D_801DAA08_e[] __asm__("D_80190578");
    extern s32 D_80190614;
    extern s32 D_80190618;
    extern s32 D_8019061C;
    extern s32 D_80190640;
    extern s32 D_80190690;
    extern s32 D_80190698;
    extern s16 D_800B9A0E;
    extern void func_80052D90(s32 a0, void *a1);
    extern void func_8013C08C(void *a0, s32 a1);
    s32 i;

    D_80190630 = 0;
    D_8019061C = 0;
    D_80190618 = 0;
    D_80190614 = 0;
    func_80052D90(0, &D_80190640);
    if (a0 == 0) {
        return;
    }
    D_80190690 = a2 + 500;
    D_80190694 = a2;
    for (i = 0; i < 4; i++) {
        D_801DAA08_e[i].f0 = 0;
        D_801DAA08_e[i].f4 = D_801DAA08_e[i].f6 = D_801DAA08_e[i].f8 = 0x6000;
        D_801DAA08_e[i].fC = 0x100;
        D_801DAA08_e[i].f18 = 0;
    }
    switch (*(u8 *)a0) {
    case 0x42:
        if (D_800B9A0E == 0) {
            func_8013BD74(&D_80190630, a0);
        } else {
            func_8013BD74(&D_80190630, a1);
        }
        D_80190698 = 0;
        break;
    case 0x43:
        func_8013C08C(&D_80190630, a0);
        D_80190698 = 1;
        break;
    case 0x44:
        func_8013C08C(&D_80190630, a0);
        D_80190698 = 2;
        break;
    case 0x45:
        func_8013C08C(&D_80190630, a0);
        D_80190698 = 3;
        break;
    case 0x46:
        func_8013C08C(&D_80190630, a0);
        D_80190698 = 4;
        break;
    case 0x47:
        func_8013C08C(&D_80190630, a0);
        D_80190698 = 5;
        break;
    case 0x48:
        func_8013C08C(&D_80190630, a0);
        D_80190698 = 6;
        break;
    case 0x49:
        func_8013C08C(&D_80190630, a0);
        D_80190698 = 9;
        break;
    case 0x4A:
        func_8013C08C(&D_80190630, a0);
        D_80190698 = 0xC;
        break;
    case 0x4B:
        func_8013C08C(&D_80190630, a0);
        D_80190698 = 0xD;
        break;
    case 0x4C:
        func_8013C08C(&D_80190630, a0);
        D_80190698 = 0xE;
        break;
    case 0x4D:
        func_8013C08C(&D_80190630, a0);
        D_80190698 = 0xF;
        break;
    case 0x4E:
        func_8013C08C(&D_80190630, a0);
        D_80190698 = 0x10;
        break;
    }
}
