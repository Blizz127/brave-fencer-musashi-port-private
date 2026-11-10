/* sc02_0037: func_8013A2BC from Druthulu/BFM-decomp
 * src/ov_SC02_037/ov_SC02_037_jr_801380E0.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc02_0037 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef short s16;
typedef int s32;
typedef struct { u32 attr; s16 x0, y0, x1, y1; u8 r, g, b, code; } Gline_801372B0;
typedef struct { s16 x, y, z, pad; } SVEC_80167AE0;
typedef struct { s16 x, y, z, pad; } SVEC_8016A290;
typedef void (*code)(unsigned short *);
struct Fr {
    u8 matrix[0x20];
    SVEC_80167AE0 v[4];
    struct { u8 r, g, b, pad; } col[4];
    u32 code;
};
struct Fr_80167AE0 {
    u8 matrix[0x20];
    SVEC_80167AE0 v[4];
    struct { u8 r, g, b, pad; } col[4];
    u32 code;
};
struct Fr_8016A290 {
    SVEC_8016A290 center;
    SVEC_8016A290 diff;
    s32 pos[3];
    s32 _pad1c;
    s16 mtx[32];
    SVEC_8016A290 v[4];
    struct { u8 r, g, b, pad; } col[4];
    u32 code;
};
typedef struct { s16 x, y, z, pad; } SVec_801670E4;
typedef struct {
               u16 cx, cy, cz;
               u16 _p06;
               u16 a8[4];
               s32 pos[3];
               s32 _p1C;
               SVec_801670E4 v[4];
               struct { u8 r, g, b, cd; } col[4];
               u32 code;
               s32 _p54;
               u8 m1[0x20];
               u8 m2[0x20];
} Fr_801670E4;
extern void *memcpy(void *, const void *, unsigned int);
extern void func_8012A568(void (*a0)(void));
extern void func_8012A5F8(void (*a0)(void), s32 a1);
extern s16 D_800B9A02;
extern void *memcpy(void *, const void *, u32);
extern void func_8005C324(int dst, int src, int n) __asm__("memcpy");
extern short D_800B9A02;
extern void func_80051DC8(void *a0, void *a1, s32 a2);
extern void func_80137030(s16 a0, s16 a1);
extern void aGsSortLine(Gline_801372B0 *p, void *ot, s32 z) __asm__("func_80051DC8");
extern void aF80137030(s32 x, s32 y) __asm__("func_80137030");
extern u16 aD800B9A02 __asm__("D_800B9A02");
extern s32 D_80127524;
extern s32 D_80127528;
extern s32 D_80127524;
void func_80138C30(void *a0);
extern s32 D_80127524;
extern s32 D_80127528;
extern void func_80138C30(void *a0);

void func_8013A2BC(s32 a0) {
    s32 s0 = a0;
    s32 *v1;
    s32 *p;
    s32 v0;
    v1 = *(s32 **)(s0 + 0x40);
    if (v1 == 0 || *(u16 *)(s0 + 0x18) == 0 || *(s16 *)v1 == 4) {
        p = &D_80127524;
        if (*p == s0) {
            v0 = D_80127528;
            D_80127528 = 0;
            *p = v0;
            if (v0 != 0) {
                *(s16 *)(D_80127524 + 0x1A) = 1;
                __asm__ __volatile__("" : : : "memory");
                ((void (*)(s32))func_80138C30)(*p);
            }
        }
        if ((*(s32 *)(s0 + 8) & 0x8000) == 0) {
            *(s16 *)(s0 + 4) = 0xD;
        } else {
            *(s16 *)(s0 + 4) = 0xE;
        }
    }
}
