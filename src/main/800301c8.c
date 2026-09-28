/* Exact retail word export [800301C8,80030470); verified against pinned EXE and asm. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_800301C8 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"

#ifndef NULL
#define NULL ((void *)0)
#endif
/* Types from vendor/bfm-decomp/src/800_shared.h. */
typedef struct {
    s16 unk00;
    s16 unk02;
    s16 unk04;
    s16 unk06;
    s16 unk08;
    s16 unk0A;
    s16 unk0C;
    s16 unk0E;
    u8  unk10;
    u8  unk11;
    u8  unk12;
    u8  unk13;
    s32 unk14;
} Rsc24;                       /* 0x18 */

typedef struct {               /* 0x18 stride; D_800A463C + k*0x18 */
    s32 unk00;
    u8  unk04[0x14];
} Ent24;

typedef struct {              /* base 0x80064D49, stride 0x0C */
    u8  unk00;
    u8  pad[11];
} Elm12;


/* Elm12 / Ent24 / Rsc24 live in src/800_shared.h, which src/800_b.c includes.  The guard makes
 * this draft compile STANDALONE (match_one adds only common.h) while emitting nothing once it is
 * spliced into the TU -- a C89 typedef redefinition is a hard gcc-2.7.2 error (cookbook §423),



/* Every one of these is copied verbatim from src/800_b.c's own file-scope block (~L3489-3505,
 * above the stub), so the spliced draft re-declares nothing incompatibly. */
extern Elm12 D_80064D49[];
extern u8    D_80064D4A[];
extern Ent24 D_800A463C[];
extern Rsc24 D_800A4640[];
extern s16   D_800A4642[];
extern s16   D_800A4644[];
extern s16   D_800A4648[];
extern s32   D_800A464C[];
extern u8    D_800A4650[];
extern s32   D_800A46BC;
extern s32   D_800A46C0;
extern s32   D_800A46C4;
extern s16   D_800A46CC;
extern s16   D_800A46CE[];
extern s16   D_800A46D0;
extern s16   D_800C5328[];
extern s16   D_800C532A[];
extern u8    D_8006AEF4;

/* not declared anywhere in src/800_b.c */
extern s32 (*D_8006AA14[])(void);
extern s32   func_80041A50();

extern void func_800301A4(void);
extern void func_80031A98(void);
extern int  func_80037CD8(void *arg);
extern void func_800415A8(s32);

int func_800301C8(int entry, s32 a1, s32 a2) {
    /* block scope, exactly as func_8002FF0C does two functions up: src/800_b.c declares this
     * symbol `extern s16 D_800A46D2[]` FURTHER DOWN the TU (L3733), and the ARRAY spelling makes
     * cse cache the address in a callee-saved register (`la $s1`) across the func_800415A8 call
     * for both the read and the write -- the target keeps two independent %hi/%lo accesses,
     * which only the scalar spelling emits. */
    extern s16 D_800A46D2;
    s16 *p;
    s32 bs;
    s32 e;
    s32 b;
    s32 h;
    s32 k;
    register s32 k2 __asm__("$17");
    s32 vab;
    u8  fl;
    s32 ret;
    s32 v;

    if (D_800A46CC == 0) {
        D_800A46C4 = 0;
        D_800A46CE[0] = D_80064D49[entry].unk00;
        D_800A46C0 = a2;
        D_800A46BC = a1;
        b = D_800A46CE[0];
        k = b * 24;
        h = *(s16 *)((u8 *)D_800A4644 + k);
        *(s32 *)((u8 *)D_800A464C + k) = a1;
        if (h != 0) {
            if (h != D_80064D4A[entry * 12]) {
                s32 n = *(s16 *)((u8 *)D_800A4648 + k);
                D_800C532A[n * 2] = -1;
                __asm__("");
                *(s16 *)((u8 *)D_800A4644 + k) = 0;
                *(s16 *)((u8 *)D_800A4648 + k) = 0;
            }
        }
        {
            register s32 m3 __asm__("$2");
            m3 = (b << 1) + b;
            k2 = m3 << 3;
        }
        if (D_800A4650[k2] == 0) {
            s32 n = *(s16 *)((u8 *)D_800A4640 + k2);
            D_800C5328[n * 2] = -1;
            func_80031A98();
            func_800415A8(*(s16 *)((u8 *)D_800A4642 + k2));
        }
        __asm__("" : "=r"(p) : "0"(&D_800A46D0));
        e = entry;
        __asm__("" : "=r"(e) : "0"(e));
        *p = e;
        *(s16 *)((u8 *)D_800A4640 + k2) = e;
        D_800A4650[k2] = 1;
        vab = func_80041A50(a1, -1, *(s32 *)((u8 *)D_800A463C + k2));
        bs = (s32)p - 0x98;
        {
            register s32 adr __asm__("$16");
            adr = k2 + bs;
            D_800A46D2 = vab;
            *(s16 *)(adr + 0xA) = vab;
        }
        if ((s16)vab == -1) {
            D_800A4650[k2] = 1;
            return 1;
        }
        if (func_80037CD8((void *)func_800301A4) == 0) {
            D_800A46CC = 1;
            return 0;
        }
        fl = D_8006AEF4;
        fl |= 2;
        D_8006AEF4 = fl;
        if (fl & 1) {
            D_800A46CC = 2;
            return 0;
        }
        D_800A46CC = 3;
        return 0;
    } else {
        ret = D_8006AA14[D_800A46CC]();
        if (ret != 0) {
            v = D_800A46D2;
            if (v >= 0) {
                func_800415A8(v);
                D_800A46D2 = -1;
                *(s16 *)((u8 *)D_800A4642 + D_800A46CE[0] * 24) = -1;
            }
        }
        return ret;
    }
}
