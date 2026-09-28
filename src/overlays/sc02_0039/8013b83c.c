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
extern s32 D_801A0D90;
extern s32 D_801A0DF4;

void func_8013B83C(s32 a0, s32 a1, s32 a2) {
                        
    extern Ent_8013B83C D_801DAA08_e[] __asm__("D_801A0CD8");
    extern s32 D_801A0D74;
    extern s32 D_801A0D78;
    extern s32 D_801A0D7C;
    extern s32 D_801A0DA0;
    extern s32 D_801A0DF0;
    extern s32 D_801A0DF8;
    extern s16 D_800B9A0E;
    extern void func_80052D90(s32 a0, void *a1);
    extern void func_8013C08C(void *a0, s32 a1);
    s32 i;

    D_801A0D90 = 0;
    D_801A0D7C = 0;
    D_801A0D78 = 0;
    D_801A0D74 = 0;
    func_80052D90(0, &D_801A0DA0);
    if (a0 == 0) {
        return;
    }
    D_801A0DF0 = a2 + 500;
    D_801A0DF4 = a2;
    for (i = 0; i < 4; i++) {
        D_801DAA08_e[i].f0 = 0;
        D_801DAA08_e[i].f4 = D_801DAA08_e[i].f6 = D_801DAA08_e[i].f8 = 0x6000;
        D_801DAA08_e[i].fC = 0x100;
        D_801DAA08_e[i].f18 = 0;
    }
    switch (*(u8 *)a0) {
    case 0x42:
        if (D_800B9A0E == 0) {
            func_8013BD74(&D_801A0D90, a0);
        } else {
            func_8013BD74(&D_801A0D90, a1);
        }
        D_801A0DF8 = 0;
        break;
    case 0x43:
        func_8013C08C(&D_801A0D90, a0);
        D_801A0DF8 = 1;
        break;
    case 0x44:
        func_8013C08C(&D_801A0D90, a0);
        D_801A0DF8 = 2;
        break;
    case 0x45:
        func_8013C08C(&D_801A0D90, a0);
        D_801A0DF8 = 3;
        break;
    case 0x46:
        func_8013C08C(&D_801A0D90, a0);
        D_801A0DF8 = 4;
        break;
    case 0x47:
        func_8013C08C(&D_801A0D90, a0);
        D_801A0DF8 = 5;
        break;
    case 0x48:
        func_8013C08C(&D_801A0D90, a0);
        D_801A0DF8 = 6;
        break;
    case 0x49:
        func_8013C08C(&D_801A0D90, a0);
        D_801A0DF8 = 9;
        break;
    case 0x4A:
        func_8013C08C(&D_801A0D90, a0);
        D_801A0DF8 = 0xC;
        break;
    case 0x4B:
        func_8013C08C(&D_801A0D90, a0);
        D_801A0DF8 = 0xD;
        break;
    case 0x4C:
        func_8013C08C(&D_801A0D90, a0);
        D_801A0DF8 = 0xE;
        break;
    case 0x4D:
        func_8013C08C(&D_801A0D90, a0);
        D_801A0DF8 = 0xF;
        break;
    case 0x4E:
        func_8013C08C(&D_801A0D90, a0);
        D_801A0DF8 = 0x10;
        break;
    }
}
