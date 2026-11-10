/* sc02_0037: func_80148648 from Druthulu/BFM-decomp
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
extern s16 D_800B9A08;
extern u8 D_800B9A64;
extern void func_8002D4C8(s32 a0, s32 a1);
extern short D_800B9A08;
extern void *memcpy(void *, const void *, unsigned int);
extern void func_8012A568(void (*a0)(void));
extern void func_8012A5F8(void (*a0)(void), s32 a1);
extern s16 D_800B9A02;
extern void func_8012E5CC(s32 param_1, u16 param_2, u16 param_3);
extern void func_80015978(s32 a0, s32 *a1);
extern void *memcpy(void *, const void *, u32);
extern s32 func_80146A6C(s32 a0, void *a1, s32 a2, s32 a3, s32 a4, s32 a5, s32 a6);
extern void func_8005C324(int dst, int src, int n) __asm__("memcpy");
extern short D_800B9A02;
extern void func_80051DC8(void *a0, void *a1, s32 a2);
extern void func_80137030(s16 a0, s16 a1);
extern void aGsSortLine(Gline_801372B0 *p, void *ot, s32 z) __asm__("func_80051DC8");
extern void aF80137030(s32 x, s32 y) __asm__("func_80137030");
extern u16 aD800B9A02 __asm__("D_800B9A02");
extern void func_8002D4C8(int, int);
extern s32 D_80126B58;
extern void func_8002D4C8(s32 a0, s32 a1);
extern void *memcpy(void *dst, const void *src, u32 n);
extern void func_80015978(s32 a0, s32 *a1);
extern s32 D_80126B58;
extern void *memcpy(void *dst, const void *src, u32 n);
extern void func_80015978(s32 a0, s32 *a1);
extern void func_801466F0(s32 a0, s32 a1, s32 a2, s32 a3, s32 sp5, s32 sp6, s32 sp7, s32 sp8);
extern u16 *func_80146750(u16 *param_1);
extern u16 *func_8014680C(short *param_1);
extern void aF801466F0(u16 a0, s32 a1, u16 a2, u16 a3, u16 sp5, s32 sp6, s32 sp7, s32 sp8)
    __asm__("func_801466F0");
void aF801466F0(u16 a0, s32 a1, u16 a2, u16 a3, u16 sp5, s32 sp6, s32 sp7, s32 sp8) __asm__("func_801466F0");
unsigned short *func_80146750(unsigned short *a0);
unsigned short *func_8014680C(short *param_1);
extern s32 D_8011D030;
extern s32 func_80146A6C(s32 a0, void *a1, s32 a2, s32 a3, s32 a4, s32 a5, s32 a6);
extern s32 func_80146A6C(s32 a0, void *a1, s32 a2, s32 a3, s32 a4, s32 a5, s32 a6);
extern s32 D_8011D030;
extern void func_80146AFC(void*);
void aF80146A6C(s16 a0, s32 a1, s16 a2, s16 a3, u16 a4, s32 a5, s32 a6) __asm__("func_80146A6C");
void aF80146A6C(s16 a0, s32 a1, s16 a2, s16 a3, u16 a4, s32 a5, s32 a6) __asm__("func_80146A6C");
void aF80146A6C(s16 a0, s32 a1, s16 a2, s16 a3, u16 a4, s32 a5, s32 a6) __asm__("func_80146A6C");
s32 aF80146AFC(void *arg0) __asm__("func_80146AFC");
s32 aF80146AFC(void *arg0) __asm__("func_80146AFC");
s32 aF80146AFC(void *arg0) __asm__("func_80146AFC");
extern void *memcpy(void *dst, const void *src, u32 n);
extern void *memcpy(void *dst, const void *src, u32 n);
extern void func_80147364();
extern void func_80147364();
extern s16 D_800B9A08;
extern s32 D_80126B58;
extern void func_80015978(s32, s32*);
extern s32 aF8012E5CC(s32, s32, s32) __asm__("func_8012E5CC");
extern void func_8002D4C8(s32 a0, s32 a1);
void aF80147364(u16 param_1, u16 param_2) __asm__("func_80147364");
void aF80147364(u16 param_1, u16 param_2) __asm__("func_80147364");
extern void func_80015978(int a0, int *a1);
extern s32 D_80126B58;
extern s32 D_80126B58;
extern u8 D_800B9A64;
extern s32 func_80014DC0();
extern s32 func_80014D68();
extern s32 func_80014D94();
extern s32 func_80014CF8();
extern void func_800120DC();
extern s32 func_800CF8B4();

void func_80148648(s32 a0, s32 a1) {
    s32 v;
    if (D_800B9A64 == 0) {
        s32 b = a1 & 0xFF;
        *(u8 *)(a0 + 0xA9) = func_80014DC0(b);
        *(s16 *)(a0 + 0xAA) = func_80014D68(b);
        *(s16 *)(a0 + 0xAC) = func_80014D94(b);
        {
            s32 r4 = func_80014CF8(b, 4);
            s32 r5 = func_80014CF8(b, 5);
            *(s16 *)(a0 + 0xAE) = (r4 & 0xFF) | ((r5 & 0xFF) << 8);
        }
    } else {
        *(u8 *)(a0 + 0xA9) = 0x41;
        func_800120DC(a0 + 0xAA, a0 + 0xAC);
    }
    if (*(u8 *)(a0 + 0x1C5) != 0) {
        *(s16 *)(a0 + 0xAA) = 0;
        *(s16 *)(a0 + 0xAC) = 0;
        *(u16 *)(a0 + 0xAE) = 0x8080;
    }
    if (func_800CF8B4() == 0) {
        u16 mode = *(u16 *)(a0 + 0x0);
        if (mode != 0x1E && mode != 0x1A) {
            *(s16 *)(a0 + 0xAA) = 0;
            *(s16 *)(a0 + 0xAC) = 0;
            *(u16 *)(a0 + 0xAE) = 0x8080;
        }
    }
    {
        s32 act = *(u8 *)(a0 + 0xA9);
        if (act == 0x53 || (act >= 0x54 && act == 0x73)) {
            if ((*(u16 *)(a0 + 0xAA) & 0xF000) != 0) {
                *(u8 *)(a0 + 0xA9) = 0x41;
            }
        }
    }
    if (*(s32 *)(a0 + 0x1B0) != 0) {
        s32 vAA = *(u16 *)(a0 + 0xAA);
        s32 vAE = *(u16 *)(a0 + 0xAE);
        s32 vAC = *(u16 *)(a0 + 0xAC);
        s32 t;
        t = ((vAA & 0x2000) << 2) | ((vAA & 0x8000) >> 2);
        t = t | (vAA & 0x5FFF);
        *(s16 *)(a0 + 0xAA) = t;
        t = ((vAC & 0x2000) << 2) | ((vAC & 0x8000) >> 2);
        t = t | (vAC & 0x5FFF);
        *(s16 *)(a0 + 0xAC) = t;
        if ((vAE & 0xFF) != 0x80) {
            vAE = (~(vAE & 0xFF) & 0xFF) | (vAE & 0xFF00);
        }
        *(s16 *)(a0 + 0xAE) = vAE;
    }
}
