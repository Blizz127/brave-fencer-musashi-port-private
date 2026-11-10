/* sc02_0037: func_80173EF8 from Druthulu/BFM-decomp
 * src/ov_SC02_037/ov_SC02_037_jr_80171B4C.c (preprocessed; only the declarations it uses),
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
extern s32 func_80029178(s32);
extern void *memcpy(void *, const void *, unsigned int);
extern void func_8012A568(void (*a0)(void));
extern void func_8012A5F8(void (*a0)(void), s32 a1);
extern s16 D_800B9A02;
extern void func_8012E5CC(s32 param_1, u16 param_2, u16 param_3);
extern void *memcpy(void *, const void *, u32);
extern void func_8005C324(int dst, int src, int n) __asm__("memcpy");
extern short D_800B9A02;
extern void func_80051DC8(void *a0, void *a1, s32 a2);
extern void func_80137030(s16 a0, s16 a1);
extern void aGsSortLine(Gline_801372B0 *p, void *ot, s32 z) __asm__("func_80051DC8");
extern void aF80137030(s32 x, s32 y) __asm__("func_80137030");
extern u16 aD800B9A02 __asm__("D_800B9A02");
extern s32 func_800D0EC4(void);
extern s32 func_80029178(s32 arg);
extern void func_80029124(s32, s32);
extern void func_80029514(s32);
extern void func_80145EE8(s32 param_1);
extern void *memcpy(void *dst, const void *src, u32 n);
extern s32 D_80127098;
extern s32 D_80127094;
extern s32 D_80127090;
extern void func_801466F0(s32 a0, s32 a1, s32 a2, s32 a3, s32 sp5, s32 sp6, s32 sp7, s32 sp8);
extern void aF801466F0(u16 a0, s32 a1, u16 a2, u16 a3, u16 sp5, s32 sp6, s32 sp7, s32 sp8) __asm__("func_801466F0");
extern void aF801466F0(u16 a0, s32 a1, u16 a2, u16 a3, u16 sp5, s32 sp6, s32 sp7, s32 sp8);
extern void func_80147060(u8 * a0);
extern s32 aF8012E5CC(s32, s32, s32) __asm__("func_8012E5CC");
extern s32 D_80127090;
extern s32 D_80127094;
extern s32 D_80127098;
extern s32 func_80029178(s32 a0);
extern void func_80029124(s32 a0, s32 a1);
extern void func_801466F0(s32, s32, s32, s32, s32, s32, s32, s32);
extern s32 aD_80127090 __asm__("D_80127090");
extern s32 aD_80127094 __asm__("D_80127094");
extern s32 aD_80127098 __asm__("D_80127098");
extern void *memcpy(void *dst, const void *src, unsigned int n);
extern void func_80147060(u8 *a0);
extern void func_80171A1C(u8 *a0);
extern void func_80147060(u8 *a0);
extern void func_80171A1C(u8 *a0);
extern void func_80171A1C(u8 *a0);
extern void func_80147060(u8 *a0);
extern void func_80171A1C(u8 *a0);
extern void func_80171A1C(u8 *a0);
extern void func_80147060(u8 *a0);
extern void func_80171A1C(u8 *a0);
extern void func_80171A1C(u8 *a0);
extern void func_80171A1C(u8 *a0);
extern void func_80147060(u8 *a0);
extern void func_80171A1C(u8 *a0);
extern void func_80171A1C(u8 *a0);
extern void func_80147060(u8 *a0);
extern void func_80171A1C(u8 *a0);
extern void func_80171A1C(u8 *a0);
extern void func_80147060(u8 *a0);
extern void func_80171A1C(u8 *a0);
extern void func_80171A1C(u8 *a0);
extern void func_80171A1C(u8 *a0);
extern void func_80171A1C(u8 *a0);
extern void func_80147060(u8 *a0);
extern void func_80171A1C(u8 *a0);
extern void func_80171A1C(u8 *a0);
extern void func_80147060(u8 *a0);
extern void func_80171A1C(u8 *a0);
extern void func_80171A1C(u8 *a0);
extern void func_80171A1C(u8 *a0);
extern void func_80171A1C(u8 *a0);
extern void func_80147060(u8 *a0);
extern void func_80171A1C(u8 *a0);
extern void func_80171A1C(u8 *a0);
extern void func_80147060(u8 *a0);
extern void func_80171A1C(u8 *a0);
extern void func_80171A1C(u8 *a0);
extern void func_80147060(u8 *a0);
extern void func_80171A1C(u8 *a0);
extern void func_80171A1C(u8 *a0);
extern void func_80171A1C(u8 *a0);
extern void func_80147060(u8 *a0);
extern void func_80171A1C(u8 *a0);
extern s16 D_80126B3A;
extern s32 func_800D0EC4(void);
extern void func_80171A1C(u8 *a0);
extern void func_80171A1C(u8 *a0);
extern void func_80171A1C(u8 *a0);
extern void func_80171A1C(u8 *a0);
extern s16 D_80126938;
extern s16 D_80126B3A;
extern void func_80147060(u8 *a0);
extern void func_800D128C(s32, s32);
extern void func_80029124(s32, s32);
extern void func_80029514(s32);
extern void func_80174158(s32 a0);
extern void func_8002A088(s32);
extern void func_8002A2D4(s32);
extern void func_8002A544(s32);
extern void func_8002A7B4(s32);
extern s32 func_80029178(s32 arg);
extern s32 func_80174188(s32 a0);
extern void func_801741A8(s32 a0);
extern s32 func_800D0EC4(void);
extern void func_800D0F0C(s32, s32);
extern void func_80145EE8(s32);
extern void func_80171A1C(u8 *a0);
void func_80174158(s32 a0);
s32 func_80174188(s32 a0);
void func_801741A8(s32 _arg0);

void func_80173EF8(void *param_1)
{
    if ((*(u16 *)((s32)param_1 + 0xB8) & 0x8000) == 0) {
        return;
    }
    D_80126938 = 1;
    ((void (*)(void))func_80147060)();
    switch (D_80126B3A) {
    case 0:
        break;
    case 0x70:
        func_800D128C((u8)D_80126B3A, 0);
        break;
    case 0x78:
        func_80029124(0x8A, 1);
        func_80029514(0xC8);
        ((void (*)(void *))func_80174158)(param_1);
        func_8002A088(0x64);
        func_8002A2D4(0x20);
        func_8002A544(0x20);
        func_8002A7B4(0x18);
        break;
    case 0x79:
        func_80029124(0x8B, 1);
        func_80029514(0x258);
        ((void (*)(void *))func_80174158)(param_1);
        func_8002A088(0xA0);
        func_8002A2D4(0x28);
        func_8002A544(0x40);
        func_8002A7B4(0x30);
        break;
    case 0x7A:
        func_80029124(0x8C, 1);
        func_80029514(0x384);
        ((void (*)(void *))func_80174158)(param_1);
        func_8002A088(0xF0);
        func_8002A2D4(0x30);
        func_8002A544(0x60);
        func_8002A7B4(0x48);
        break;
    case 0x7B:
        func_80029124(0x8D, 1);
        func_80029514(0x4B0);
        ((void (*)(void *))func_80174158)(param_1);
        func_8002A088(0x140);
        func_8002A2D4(0x40);
        func_8002A544(0x80);
        func_8002A7B4(0x60);
        break;
    case 0x7C:
        if ((u8)func_80029178(0x11D) == 0) {
            ((void (*)(void *))func_80174188)(param_1);
        }
        func_8002A088(0x190);
        func_8002A2D4(0x50);
        func_8002A544(0xA0);
        func_8002A7B4(0x80);
        ((void (*)(void *))func_801741A8)(param_1);
        func_80029124(0x8E, 1);
        break;
    default:
        func_800D0F0C(func_800D0EC4(), (s32)D_80126B3A);
        break;
    }
    func_80145EE8(0);
    ((void (*)(void *))func_80171A1C)(param_1);
}
