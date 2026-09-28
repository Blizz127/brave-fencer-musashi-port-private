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
extern s32 D_801B7AA0;
extern s32 D_801B7B04;

void func_8013B83C(s32 a0, s32 a1, s32 a2) {
                        
    extern Ent_8013B83C D_801DAA08_e[] __asm__("D_801B79E8");
    extern s32 D_801B7A84;
    extern s32 D_801B7A88;
    extern s32 D_801B7A8C;
    extern s32 D_801B7AB0;
    extern s32 D_801B7B00;
    extern s32 D_801B7B08;
    extern s16 D_800B9A0E;
    extern void func_80052D90(s32 a0, void *a1);
    extern void func_8013C08C(void *a0, s32 a1);
    s32 i;

    D_801B7AA0 = 0;
    D_801B7A8C = 0;
    D_801B7A88 = 0;
    D_801B7A84 = 0;
    func_80052D90(0, &D_801B7AB0);
    if (a0 == 0) {
        return;
    }
    D_801B7B00 = a2 + 500;
    D_801B7B04 = a2;
    for (i = 0; i < 4; i++) {
        D_801DAA08_e[i].f0 = 0;
        D_801DAA08_e[i].f4 = D_801DAA08_e[i].f6 = D_801DAA08_e[i].f8 = 0x6000;
        D_801DAA08_e[i].fC = 0x100;
        D_801DAA08_e[i].f18 = 0;
    }
    switch (*(u8 *)a0) {
    case 0x42:
        if (D_800B9A0E == 0) {
            func_8013BD74(&D_801B7AA0, a0);
        } else {
            func_8013BD74(&D_801B7AA0, a1);
        }
        D_801B7B08 = 0;
        break;
    case 0x43:
        func_8013C08C(&D_801B7AA0, a0);
        D_801B7B08 = 1;
        break;
    case 0x44:
        func_8013C08C(&D_801B7AA0, a0);
        D_801B7B08 = 2;
        break;
    case 0x45:
        func_8013C08C(&D_801B7AA0, a0);
        D_801B7B08 = 3;
        break;
    case 0x46:
        func_8013C08C(&D_801B7AA0, a0);
        D_801B7B08 = 4;
        break;
    case 0x47:
        func_8013C08C(&D_801B7AA0, a0);
        D_801B7B08 = 5;
        break;
    case 0x48:
        func_8013C08C(&D_801B7AA0, a0);
        D_801B7B08 = 6;
        break;
    case 0x49:
        func_8013C08C(&D_801B7AA0, a0);
        D_801B7B08 = 9;
        break;
    case 0x4A:
        func_8013C08C(&D_801B7AA0, a0);
        D_801B7B08 = 0xC;
        break;
    case 0x4B:
        func_8013C08C(&D_801B7AA0, a0);
        D_801B7B08 = 0xD;
        break;
    case 0x4C:
        func_8013C08C(&D_801B7AA0, a0);
        D_801B7B08 = 0xE;
        break;
    case 0x4D:
        func_8013C08C(&D_801B7AA0, a0);
        D_801B7B08 = 0xF;
        break;
    case 0x4E:
        func_8013C08C(&D_801B7AA0, a0);
        D_801B7B08 = 0x10;
        break;
    }
}
