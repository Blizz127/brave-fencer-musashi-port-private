/* Overlay range [8012944C,8012956C) from MAIN.CD member 0012.
 * SHA256(span)=2636077d8b15e0073d1a83e48dffd1ffe52e9892271b5e3907b941411809ec49.
 * Word export for the native seam; the C body below is kept
 * byte-identical (wrap only, no rewrite): the cleaned Druthulu/BFM-decomp
 * form (vendor/bfm-decomp, same SLUS-00726 build), re-verified against
 * retail at the recorded optimization by tools/match_function.py. */
#include "psx_types.h"
#include "m2c_macros.h"

/* func_8012944C - 72 words. Promoted from vendor/bfm-decomp
 * (Druthulu, same SLUS-00726 build), split to an address-named file.
 * Values and locals are the loosest that reproduce the bytes; they
 * are not evidence of the original declaration. */
extern s32 D_8005128C;
extern s16 D_80114EE0;
extern u8 D_800B9A78;
extern void func_801298F4(void *arg0);
extern void func_801299C8();

void func_8012944C(void) {
    register s32 base __asm__("$16");   /* $s0 = &D_800B9A78 */
    register short *p __asm__("$17");    /* $s1 = base + 0x1E */
    register s32 i __asm__("$18");        /* $s2 = counter */
    register s32 sh __asm__("$19");       /* $s3 = 0x30000 + i*0x10000 */
    s32 *g = (s32 *)&D_8005128C;
    int v;
    s32 arg;
    if (*g == 0x34420200) {
        *g = 0;
    }
    D_80114EE0 = 1;
    base = (s32)&D_800B9A78;
    i = 0;
    sh = 0x30000;
    p = (short *)(base + 0x1E);
    do {
        v = (u16)p[0xb];
        if (v == 0x7ffe) goto F0;
        if (v < 0x7fff) {
            if (v == 0x7ffd) goto DC;
            goto L504;
        }
        if (v != 0x7fff) goto L504;
        goto L530;
    DC:
        if (i != 0) goto L530;
        func_801299C8(1, 1, base);
        goto L530;
    F0:
        arg = (i << 0x11) >> 0x10;
        func_801299C8(1, arg, base);
        goto L530;
    L504:
        func_801298F4((void *)base);
        arg = sh >> 0x10;
        *p = p[0x12] + p[0xe];
        func_801299C8(1, arg, base);
    L530:
        p += 0x2a;
        sh += 0x10000;
        i += 1;
        base += 0x54;
    } while (i < 2);
}
