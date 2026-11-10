/* sc02_0037: func_80146750 from Druthulu/BFM-decomp
 * src/ov_SC02_037/ov_SC02_037_jr_801458E0.c (preprocessed; only the declarations it uses),
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
typedef struct Rec801466F0 {
    u16 unk0;
    u16 unk2;
    u16 unk4;
    u16 unk6;
    s32 unk8;
    s32 unkC;
    s32 unk10;
} Rec801466F0;
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
extern void *memcpy(void *dst, const void *src, u32 n);
extern void *memcpy(void *dst, const void *src, u32 n);
extern void func_801466F0(s32 a0, s32 a1, s32 a2, s32 a3, s32 sp5, s32 sp6, s32 sp7, s32 sp8);
extern u16 *func_80146750(u16 *param_1);
extern u16 *func_8014680C(short *param_1);
extern void aF801466F0(u16 a0, s32 a1, u16 a2, u16 a3, u16 sp5, s32 sp6, s32 sp7, s32 sp8)
    __asm__("func_801466F0");
void aF801466F0(u16 a0, s32 a1, u16 a2, u16 a3, u16 sp5, s32 sp6, s32 sp7, s32 sp8) __asm__("func_801466F0");
extern unsigned short D_8011FD10;
extern int D_8011FA1C;
extern unsigned short D_8011F9D6;
extern unsigned short D_8011F9DA;
extern unsigned short D_8011F9DE;
extern int D_8011FA20;
extern int D_8011FA24;
unsigned short *func_8014680C(short *param_1);

unsigned short *func_80146750(unsigned short *a0)
{
    int a6;
    register unsigned short *a7 __asm__("7");
    int a5;
    unsigned short *v1;
    unsigned short *v0;
    a6 = 0x8;
    a7 = &D_8011FD10;
    v1 = a7;
    a5 = 0x340;
    do {
        v0 = v1;
        if (*v0 != 0) {
            a7 = (unsigned short *)((char *)a7 + 0x68);
            v1 = (unsigned short *)((char *)v1 + 0x68);
            a6 = a6 + 1;
            a5 = a5 + 0x68;
        } else {
            *(int *)((char *)&D_8011FA1C + a5) = *(int *)((char *)a0 + 0x8);
            *v1 = *a0;
            *(unsigned short *)((char *)&D_8011F9D6 + a5) = *(unsigned short *)((char *)a0 + 0x2);
            *(unsigned short *)((char *)&D_8011F9DA + a5) = *(unsigned short *)((char *)a0 + 0x4);
            *(unsigned short *)((char *)&D_8011F9DE + a5) = *(unsigned short *)((char *)a0 + 0x6);
            *(int *)((char *)&D_8011FA20 + a5) = *(int *)((char *)a0 + 0xC);
            *(int *)((char *)&D_8011FA24 + a5) = *(int *)((char *)a0 + 0x10);
            return a7;
        }
    } while (a6 < 0x14);
    return (unsigned short *)0;
}
