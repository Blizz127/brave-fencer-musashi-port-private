/* sc03_0001: func_801378F0 from Druthulu/BFM-decomp
 * src/ov_SC03_001/ov_SC03_001_jr_80135D20.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0001 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef short s16;
typedef int s32;
struct obj;
struct obj {
    u8 pad0[0x4];
    s16 unk4;
    u8 pad6[0x2];
    s32 unk8;
};
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
extern void func_80016714(void *a0, s32 a1);
extern void *memcpy(void *, const void *, unsigned int);
extern void func_8012A568(void (*a0)(void));
extern void func_8012A5F8(void (*a0)(void), s32 a1);
extern s16 D_800B9A02;
extern void *memcpy(void *, const void *, u32);
extern void func_8005C324(int dst, int src, int n) __asm__("memcpy");
extern s16 D_800B9A02;
extern short D_800B9A02;
extern void func_80051DC8(void *a0, void *a1, s32 a2);
extern short D_800B9A02;
extern void func_80051DC8(void *a0, void *a1, s32 a2);
extern short D_800B9A02;
extern void func_80051DC8(void *a0, void *a1, s32 a2);
void func_80137030(s16 a0, s16 a1);
extern short D_800B9A02;
extern void func_80051DC8(void *a0, void *a1, s32 a2);
extern void aGsSortLine(Gline_801372B0 *p, void *ot, s32 z) __asm__("func_80051DC8");
extern void aF80137030(s32 x, s32 y) __asm__("func_80137030");
extern u16 aD800B9A02 __asm__("D_800B9A02");
extern void func_80137614(s32 a0, s32 a1, s32 a2);
extern s32 func_801399A8(void);
extern void func_801377B4(s32 a0, s32 a1, s32 a2);
s32 aF80137614(s32 a0, s32 a1, s32 a2) __asm__("func_80137614");
s32 aF80137614(s32 a0, s32 a1, s32 a2) __asm__("func_80137614");
s32 aF80137614(s32 a0, s32 a1, s32 a2) __asm__("func_80137614");
extern s32 func_801399A8(void);
extern void func_801377B4(s32 a0, s32 a1, s32 a2);
extern void func_801376E8(int a0, int a1);
extern void func_801377B4(s32 a0, s32 a1, s32 a2);
extern void func_80139BE0(s32 a0);
void *aF801376E8(int a0, int a1) __asm__("func_801376E8");
void * aF801376E8(int a0, int a1) __asm__("func_801376E8");
void *aF801376E8(int a0, int a1) __asm__("func_801376E8");
void func_801377B4(s32 a0, s32 a1, s32 a2);
extern void func_80016714(void *a0, s32 a1);
extern void func_8013A860(void);

void func_801378F0(void) {
    extern u8 D_80127520[];
    extern u8 aD801269F0[] __asm__("D_801269F0");
    extern u8 D_80126A28[];
    extern u8 D_8018DAC0[];
    s32 i;
    s32 si;
    s32 di;
    u8 *p;
    func_80016714(D_80127520, 0xBFC);
    i = 0;
    si = 0;
    p = aD801269F0;
    di = 0;
    do {
        func_80016714(p, 0x4C);
        *(u16 *)&D_80126A28[di] = *(u16 *)&D_8018DAC0[si];
        *(u16 *)&D_80126A28[di + 2] = *(u16 *)&D_8018DAC0[si + 2];
        *(u16 *)&D_80126A28[di + 4] = *(u16 *)&D_8018DAC0[si + 4];
        *(u16 *)&D_80126A28[di + 6] = *(u16 *)&D_8018DAC0[si + 6];
        p += 0x4C;
        i += 1;
        si += 8;
        di += 0x4C;
    } while (i < 3);
    func_8013A860();
}
