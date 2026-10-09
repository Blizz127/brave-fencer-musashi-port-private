/* SC02.CD member35 [8013B83C,8013BC7C): twin of main_0012 8013B83C (src/overlays/main_0012/8013b83c.c); only the
 * global addresses differ. Byte-identical to the sc02_0035 retail words
 * (gcc-2.7.2 -O0, rodata 0x801BC6B4, B28 inc 107 twin port). */
/* Overlay range [8013B83C,8013B9F0) from MAIN.CD member 0012.
 * SHA256(span)=b1f5a56416783ae456759347911bc8fab8633d7799e4b30cb296d8ab68dabbe9.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8013B83C - byte-exact against retail at -O0 (tools/register_match.py). */
#include "psx_types.h"

/* File-scope declarations from the vendor translation unit. */
typedef struct { s32 f0; u8 pad[0x18]; } E_3B7AC;
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
extern E_3B7AC D_801BE920[];
void func_8013BD74(void *a0, s32 a1);

extern s32 D_801BE9D8;
extern s32 D_801BEA3C;
                    /* size 0x14 */

void func_8013B83C(s32 a0, s32 a1, s32 a2) {
    typedef struct {
        s32 f0;
        u16 f4;
        u16 f6;
        u16 f8;
        u16 fA;
        s32 fC;
        u8  pad[8];
        s32 f18;
    } Ent_8013B83C;                       /* sizeof 0x1C */
    extern Ent_8013B83C D_801DAA08_e[] __asm__("D_801BE920");
    extern s32 D_801BE9BC;
    extern s32 D_801BE9C0;
    extern s32 D_801BE9C4;
    extern s32 D_801BE9E8;
    extern s32 D_801BEA38;
    extern s32 D_801BEA40;
    extern s16 D_800B9A0E;
    extern void func_80052D90(s32 a0, void *a1);
    extern void func_8013C08C(void*, void*);
    s32 i;

    D_801BE9D8 = 0;
    D_801BE9C4 = 0;
    D_801BE9C0 = 0;
    D_801BE9BC = 0;
    func_80052D90(0, &D_801BE9E8);
    if (a0 == 0) {
        return;
    }
    D_801BEA38 = a2 + 500;
    D_801BEA3C = a2;
    for (i = 0; i < 4; i++) {
        D_801DAA08_e[i].f0 = 0;
        D_801DAA08_e[i].f4 = D_801DAA08_e[i].f6 = D_801DAA08_e[i].f8 = 0x6000;
        D_801DAA08_e[i].fC = 0x100;
        D_801DAA08_e[i].f18 = 0;
    }
    switch (*(u8 *)a0) {
    case 0x42:
        if (D_800B9A0E == 0) {
            func_8013BD74(&D_801BE9D8, a0);
        } else {
            func_8013BD74(&D_801BE9D8, a1);
        }
        D_801BEA40 = 0;
        break;
    case 0x43:
        ((void (*)(void *, s32))func_8013C08C)(&D_801BE9D8, a0);
        D_801BEA40 = 1;
        break;
    case 0x44:
        ((void (*)(void *, s32))func_8013C08C)(&D_801BE9D8, a0);
        D_801BEA40 = 2;
        break;
    case 0x45:
        ((void (*)(void *, s32))func_8013C08C)(&D_801BE9D8, a0);
        D_801BEA40 = 3;
        break;
    case 0x46:
        ((void (*)(void *, s32))func_8013C08C)(&D_801BE9D8, a0);
        D_801BEA40 = 4;
        break;
    case 0x47:
        ((void (*)(void *, s32))func_8013C08C)(&D_801BE9D8, a0);
        D_801BEA40 = 5;
        break;
    case 0x48:
        ((void (*)(void *, s32))func_8013C08C)(&D_801BE9D8, a0);
        D_801BEA40 = 6;
        break;
    case 0x49:
        ((void (*)(void *, s32))func_8013C08C)(&D_801BE9D8, a0);
        D_801BEA40 = 9;
        break;
    case 0x4A:
        ((void (*)(void *, s32))func_8013C08C)(&D_801BE9D8, a0);
        D_801BEA40 = 0xC;
        break;
    case 0x4B:
        ((void (*)(void *, s32))func_8013C08C)(&D_801BE9D8, a0);
        D_801BEA40 = 0xD;
        break;
    case 0x4C:
        ((void (*)(void *, s32))func_8013C08C)(&D_801BE9D8, a0);
        D_801BEA40 = 0xE;
        break;
    case 0x4D:
        ((void (*)(void *, s32))func_8013C08C)(&D_801BE9D8, a0);
        D_801BEA40 = 0xF;
        break;
    case 0x4E:
        ((void (*)(void *, s32))func_8013C08C)(&D_801BE9D8, a0);
        D_801BEA40 = 0x10;
        break;
    }
}
