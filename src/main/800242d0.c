/* Main-exec range [800242D0,800243EC) from the SLUS executable.
 * SHA256(span)=dbaf9f93feba204363bde06ff94a2aba533095cd11c14519dbc0968ac03d9e83.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_800242D0 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"

extern u16 D_80063858;
extern u16 D_8006386C;
/* SAME spelling as the already-banked func_800241C0 uses at file scope: gcc-2.7.2
 * rejects a conflicting redeclaration at file scope AND at block scope, so match it.
 * Only the ADDRESS is taken here (t4 is a `register s16 *`), so the element type of
 * the decl does not reach codegen. */
extern s16 D_80063870[];

void func_800242D0(s32 arg0, u16* arg1, s32 arg2) {
    s32 frame_pad[1];
    register s32 t0 __asm__("$8");
    register s32 t1 __asm__("$9");
    s32 v0;
    register s32 v1 __asm__("$3");
    register s32 a3 __asm__("$7");
    register s16* t4 __asm__("$12");
    register u16* t2 __asm__("$10");
    register s32 t3 __asm__("$11");
    register s32 divisor __asm__("$4");
    (void)&frame_pad;

    t0 = arg2 & 0xFFAF;
    arg2 = arg2 & 0x80;
    t1 = arg0;
    if (arg2 != 0) {
        t0 = 4;
    }
    v0 = t0 - 1;
    t0 = v0;
    __asm__ __volatile__("" : "=r"(t0) : "0"(t0));
    if ((v0 << 16) >= 0) {
        t4 = D_80063870;
        t2 = &D_80063858;
        t3 = 2;
        v1 = t1 << 16;
        do {
            v0 = (t0 << 16) >> 15;
            divisor = *(s16*)(v0 + (s32)t4);
            v1 = v1 >> 16;
            v0 = v1 / divisor;
            a3 = v0;
            if (((a3 << 16) >> 16) != 0) {
                v1 = divisor;
                __asm__ __volatile__("" : "=r"(v1) : "0"(v1));
                *(u16*)arg1 = *(u16*)((((a3 << 16) >> 16) << 1) + (s32)t2);
                t1 -= a3 * v1;
            } else {
                *(u16*)arg1 = *(u16*)t2;
            }
            arg1 += 1;
            if (arg2 != 0) {
                v0 = (t0 << 16) >> 16;
                if (v0 == t3) {
                    *(u16*)arg1 = D_8006386C;
                    arg1 += 1;
                }
            }
            v0 = t0 - 1;
            t0 = v0;
            __asm__ __volatile__("" : "=r"(t0) : "0"(t0));
            v1 = t1 << 16;
        } while ((v0 << 16) >= 0);
    }
    *(s16*)arg1 = -1;
}
