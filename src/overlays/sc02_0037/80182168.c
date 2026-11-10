/* sc02_0037: func_80182168 from Druthulu/BFM-decomp
 * src/ov_SC02_037/ov_SC02_037_jr_8017AE2C.c (preprocessed; only the declarations it uses),
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
extern void func_8012A828(s32 a0, void * a1);
extern void func_8012B23C(s32 a0);
extern void func_8012C1B8(void);
extern void func_8012CAE4(void *a0);
extern s32 func_8012C658(s32 arg0, s32 arg1, s32 arg2);
extern s16 D_800B9A02;
extern void func_8012E5CC(s32 param_1, u16 param_2, u16 param_3);
extern void *memcpy(void *, const void *, u32);
extern void func_8012A828(s32 a0, void *a1);
extern void func_8005C324(int dst, int src, int n) __asm__("memcpy");
extern short D_800B9A02;
extern void func_80051DC8(void *a0, void *a1, s32 a2);
extern void func_80137030(s16 a0, s16 a1);
extern void aGsSortLine(Gline_801372B0 *p, void *ot, s32 z) __asm__("func_80051DC8");
extern void aF80137030(s32 x, s32 y) __asm__("func_80137030");
extern u16 aD800B9A02 __asm__("D_800B9A02");
extern void func_8001CA1C(s32 a0, s32 a1);
extern s32 func_8005C49C(void);
extern s32 func_8012C658(s32 a0, s32 a1, s32 a2);
extern void *memcpy(void *dst, const void *src, u32 n);
extern s32 D_80127098;
extern s32 D_80127094;
extern s32 D_80127090;
extern void func_801466F0(s32 a0, s32 a1, s32 a2, s32 a3, s32 sp5, s32 sp6, s32 sp7, s32 sp8);
extern void aF801466F0(u16 a0, s32 a1, u16 a2, u16 a3, u16 sp5, s32 sp6, s32 sp7, s32 sp8) __asm__("func_801466F0");
extern void aF801466F0(u16 a0, s32 a1, u16 a2, u16 a3, u16 sp5, s32 sp6, s32 sp7, s32 sp8);
extern s32 aF8012E5CC(s32, s32, s32) __asm__("func_8012E5CC");
extern s32 D_80127090;
extern s32 D_80127094;
extern s32 D_80127098;
extern int func_8005C49C(void);
extern void func_801466F0(s32, s32, s32, s32, s32, s32, s32, s32);
extern s32 aD_80127090 __asm__("D_80127090");
extern s32 aD_80127094 __asm__("D_80127094");
extern s32 aD_80127098 __asm__("D_80127098");
extern void *memcpy(void *dst, const void *src, unsigned int n);
extern void func_8012CAE4(void *a0);
extern void func_8012A828(s32 a0, void *a1);
extern s32 func_8005C49C(void);
extern s32 func_8005C49C(void);
extern void func_8012C1B8(void);
extern void func_8012A828(s32 a0, void *a1);
extern int func_8005C49C(void);
extern short D_800B9A02;
extern void func_8012A828(s32 a0, void *a1);
extern void func_8012A828(s32, void *);
extern void func_8012A828(s32, void*);
extern s32 func_8012C658(s32 arg0, s32 arg1, s32 arg2);
extern void func_8012CAE4(void *a0);
extern void func_8012A828(s32, void*);
extern void func_8012B23C(s32);
extern s32 func_8012C658(s32 arg0, s32 arg1, s32 arg2);
extern s32 func_8005C49C(void);
extern void func_8012A828(s32, void*);
extern void func_8012A828(s32, void*);
extern s32 func_8005C49C(void);
extern void func_8012A828(s32, void*);
extern void func_8012A828(s32, void*);
extern s32 func_8005C49C(void);
extern void func_8012A828(s32, void*);
s32 func_8012C658(s32 arg0, s32 arg1, s32 arg2);
extern void func_8012B23C(s32);
extern void func_8012A828(s32, void*);
extern void func_8012A828(s32, void*);
extern void func_8012A828(s32, void*);
extern void func_8012A828(s32, void*);
extern void func_8012A828(s32, void*);
extern void func_8012A828(s32, void*);
extern void func_8012A828(s32, void*);
extern void func_8012A828(s32, void*);
extern void func_8012A828(s32, void*);
extern void func_8012C1B8(void);
extern void func_8012CAE4(void *a0);
extern void func_8001CA1C(s32 a0, s32 a1);
extern void func_8012A828(s32, void*);
extern void func_8012B23C(s32);
extern void func_8012C1B8(void);
extern void func_8012CAE4(void *a0);
extern void func_8001CA1C(s32 a0, s32 a1);
extern void func_8012A828(s32, void*);
extern s32 func_8005C49C(void);
extern void func_8012B23C(s32);

void func_80182168(s32 a0) {
    extern void func_8012C1B8(void);
    extern void func_8012CAE4(void *a0);
    extern void func_8012B23C(s32);
    extern u16 D_801C12EC[];
    extern u16 D_801C12EE[];
    extern u16 D_801C12F0[];
    extern void func_8001CA1C(s32 a0, s32 a1);
    extern void func_8012A828(s32, void*);
    extern s32 func_8012C658(s32 arg0, s32 arg1, s32 arg2);
    extern s32 func_8005C49C(void);
    extern u8 D_801C1050[];
    extern u8 D_801C1110[];
    extern u8 D_801C1198[];
    extern u8 D_801C1258[];
    extern u8 D_801C133C[];
    extern u8 D_801C1360[];
    extern u8 D_801C1014[];
    extern u8 D_801C134C[];
    extern u8 D_801C1358[];
    s32 v0;
    s16 sVar1;
    u32 uVar3;
    u32 uVar5;
    v0 = ((s32 (*)(void))func_8012C1B8)();
    *(s32 *)(a0 + 0x20) = v0;
    if (v0 == 0) {
        func_8012CAE4((void *)a0);
        return;
    }
    ((void (*)(void *))func_8012B23C)((void *)a0);
    *(u16 *)(a0 + 0x12) = D_801C12EC[*(s16 *)(a0 + 0xFC) * 4];
    *(u16 *)(a0 + 0x16) = D_801C12EE[*(s16 *)(a0 + 0xFC) * 4];
    *(u16 *)(a0 + 0x1A) = D_801C12F0[*(s16 *)(a0 + 0xFC) * 4];
    switch (*(s16 *)(a0 + 0x70)) {
    case 0:
        func_8001CA1C(*(s32 *)(a0 + 0x20), (s32)D_801C1050);
        ((void (*)(s32, s32))func_8012A828)(a0, (s32)D_801C1110);
        *(s16 *)(a0 + 2) = 1;
        *(u16 *)(*(s32 *)(a0 + 0x20) + 0x18) = 0x2000;
        *(u16 *)(*(s32 *)(a0 + 0x20) + 0x1A) = 0x2000;
        break;
    case 1:
        func_8001CA1C(*(s32 *)(a0 + 0x20), (s32)D_801C1198);
        ((void (*)(s32, s32))func_8012A828)(a0, (s32)D_801C1258);
        *(s16 *)(a0 + 2) = 4;
        *(u32 *)(*(s32 *)(a0 + 0x20) + 4) |= 0x80000000;
        *(s32 *)(a0 + 0x1C) = 8;
        *(u16 *)(*(s32 *)(a0 + 0x20) + 0x1C) = 0x3C00;
        *(u16 *)(*(s32 *)(a0 + 0x20) + 0x18) = 0x3C00;
        *(u16 *)(*(s32 *)(a0 + 0x20) + 0x1A) = 0x3C00;
        *(u8 *)(a0 + 0xC0) = 1;
        *(u8 **)(a0 + 0x58) = D_801C133C;
        *(u16 *)(a0 + 0x5C) = 0x8000;
        *(s16 *)(a0 + 0xAE) = -9;
        *(u8 **)(a0 + 0xBC) = D_801C1360;
        *(u32 *)(a0 + 0xB4) = 0;
        *(u8 **)(a0 + 0x78) = D_801C1014;
        *(u32 *)(a0 + 0xC4) |= 2;
        uVar3 = func_8012C658(0x12F, 4, a0);
        *(u32 *)(a0 + 0xCC) = uVar3;
        break;
    case 2:
        func_8001CA1C(*(s32 *)(a0 + 0x20), (s32)D_801C1050);
        ((void (*)(s32, s32))func_8012A828)(a0, (s32)D_801C1110);
        *(s16 *)(a0 + 2) = 6;
        *(u16 *)(*(s32 *)(a0 + 0x20) + 0x18) = 0x2000;
        *(u16 *)(*(s32 *)(a0 + 0x20) + 0x1A) = 0x2000;
        break;
    case 3:
        func_8001CA1C(*(s32 *)(a0 + 0x20), (s32)D_801C1198);
        ((void (*)(s32, s32))func_8012A828)(a0, (s32)D_801C1258);
        *(s16 *)(a0 + 2) = 7;
        *(u16 *)(*(s32 *)(a0 + 0x20) + 0x18) = 0x3C00;
        *(u16 *)(*(s32 *)(a0 + 0x20) + 0x1A) = 0x3C00;
        *(s32 *)(a0 + 0x1C) = 6;
        break;
    case 4:
        func_8001CA1C(*(s32 *)(a0 + 0x20), (s32)D_801C134C);
        ((void (*)(s32, s32))func_8012A828)(a0, (s32)D_801C1358);
        *(s16 *)(a0 + 2) = 8;
        *(u32 *)(*(s32 *)(a0 + 0x20) + 4) |= 0x8000000;
        *(u16 *)(*(s32 *)(a0 + 0x20) + 0x1C) = 0x3C00;
        *(u16 *)(*(s32 *)(a0 + 0x20) + 0x18) = 0x3C00;
        *(u16 *)(*(s32 *)(a0 + 0x20) + 0x1A) = 0x3C00;
        break;
    case 5:
        func_8001CA1C(*(s32 *)(a0 + 0x20), (s32)D_801C1050);
        ((void (*)(s32, s32))func_8012A828)(a0, (s32)D_801C1110);
        *(s16 *)(a0 + 2) = 9;
        *(u16 *)(a0 + 0xFE) = *(u16 *)(*(s32 *)(a0 + 0x64) + 0x36);
        *(u32 *)(*(s32 *)(a0 + 0x20) + 4) |= 0x80000000;
        *(s16 *)(a0 + 0x100) = *(s16 *)(*(s32 *)(a0 + 0x64) + 0xFE) * 6;
        sVar1 = *(s16 *)(*(s32 *)(a0 + 0x64) + 0x70);
        if (sVar1 == 5) {
            *(s16 *)(a0 + 0x12) = (func_8005C49C() % 0x60) - 0x30;
            *(s16 *)(a0 + 0x16) = (func_8005C49C() % 0x60) - 0x60;
            sVar1 = (func_8005C49C() % 0x60) - 0x40;
        } else {
            if (sVar1 != 6) {
                break;
            }
            *(s16 *)(a0 + 0x12) = (func_8005C49C() % 0x60) - 0x30;
            *(s16 *)(a0 + 0x16) = (func_8005C49C() % 0x20) - 0x20;
            sVar1 = (func_8005C49C() % 0x60) - 0x50;
        }
        *(s16 *)(a0 + 0x1A) = sVar1;
    }
    uVar5 = func_8005C49C();
    *(u32 *)(a0 + 0x94) = uVar5 & 0xF;
    *(u32 *)(*(s32 *)(a0 + 0x20) + 4) |= 0x50000000;
    *(u16 *)(*(s32 *)(a0 + 0x20) + 0x2C) |= 0x10;
}
