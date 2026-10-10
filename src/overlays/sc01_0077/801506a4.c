/* SC02.CD member35 [801506A4,80150820): twin of main_0012 801506A4 (src/overlays/main_0012/801506a4.c); only the
 * global addresses differ. Byte-identical to the sc02_0035 retail words
 * (gcc-2.7.2 -O2, B28 inc 104 twin port). */
/* Overlay range [801506A4,80150820) from MAIN.CD member 0012.
 * SHA256(span)=738fd1954aefd94024d6a3ac2fbbfcb627bc620094eb57be86986d277a34e11e.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801506A4 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"

/* File-scope declarations from the vendor translation unit. */
struct Ent_801506A4 {
    unsigned short unk0;    /* 0x0 */
    char pad[0x5A];
    unsigned short unk5C;   /* 0x5C */
    char pad2[0x12];
    short unk70;            /* 0x70 */
};
extern s16 D_80078EB4;

extern void func_80147324(s32 a0);
extern void func_8014ACE8(void *a0, s32 a1, s32 a2);
extern void func_8014ADA8(s32 a0, s32 a1);
extern void func_8014BB24(s32 a0, s32 a1, s32 a2);



s32 func_801506A4(s32 arg0, s32 arg1) {

    extern u16 aD80078EB4 __asm__("D_80078EB4");
    extern void func_80150820(s32, s32);
    extern void func_8015086C(int);
    extern unsigned short D_8018877C[];
    extern unsigned short D_80188784[];
    extern unsigned short D_8018878C[];

    int mode;

    mode = ((struct Ent_801506A4 *)arg1)->unk0;
    ((struct Ent_801506A4 *)arg1)->unk5C |= 1;
    switch (mode) {
    case 0x31:
        ((void(*)(int))func_80147324)(0x452);
        ((void(*)(int, unsigned))func_8014ADA8)(((int)arg0), D_8018877C[((struct Ent_801506A4 *)arg1)->unk70]);
        ((void(*)(int, int, unsigned))func_8014ACE8)(((int)arg0), 3, D_8018877C[((struct Ent_801506A4 *)arg1)->unk70]);
        break;
    case 0x32:
        if ((*(unsigned short*)&aD80078EB4) != 0) {
            ((void(*)(int))func_80147324)(0x452);
            ((void(*)(int, unsigned, int))func_8014BB24)(((int)arg0), D_80188784[((struct Ent_801506A4 *)arg1)->unk70], 1);
            ((void(*)(int, int, unsigned))func_8014ACE8)(((int)arg0), 2, D_80188784[((struct Ent_801506A4 *)arg1)->unk70]);
        }
        break;
    case 0x33:
        ((void(*)(int))func_80147324)(0x452);
        ((void (*)(int, unsigned))func_80150820)(((int)arg0), D_8018878C[((struct Ent_801506A4 *)arg1)->unk70]);
        break;
    case 0xC5:
    case 0x27B:
        ((void(*)(int))func_80147324)(0x452);
        func_8015086C(((int)arg0));
        break;
    }
}
