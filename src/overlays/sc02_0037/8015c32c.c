/* sc02_0037: func_8015C32C from Druthulu/BFM-decomp
 * src/ov_SC02_037/ov_SC02_037_jr_8015A3C8.c (preprocessed; only the declarations it uses),
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
extern void func_8012E5CC(s32 param_1, u16 param_2, u16 param_3);
extern void *memcpy(void *, const void *, u32);
extern void func_8005C324(int dst, int src, int n) __asm__("memcpy");
extern short D_800B9A02;
extern void func_80051DC8(void *a0, void *a1, s32 a2);
extern void func_80137030(s16 a0, s16 a1);
extern void aGsSortLine(Gline_801372B0 *p, void *ot, s32 z) __asm__("func_80051DC8");
extern void aF80137030(s32 x, s32 y) __asm__("func_80137030");
extern u16 aD800B9A02 __asm__("D_800B9A02");
extern void *memcpy(void *dst, const void *src, u32 n);
extern void func_801466F0(s32 a0, s32 a1, s32 a2, s32 a3, s32 sp5, s32 sp6, s32 sp7, s32 sp8);
extern void aF801466F0(u16 a0, s32 a1, u16 a2, u16 a3, u16 sp5, s32 sp6, s32 sp7, s32 sp8) __asm__("func_801466F0");
extern void aF801466F0(u16 a0, s32 a1, u16 a2, u16 a3, u16 sp5, s32 sp6, s32 sp7, s32 sp8);
extern void func_80146DB8(s32 *a0, s32 *a1);
extern s32 func_80146E98(s32 a0);
extern void func_80147078(s32 *a0, s16 a1);
extern void func_80147324(s32 arg0);
extern s32 aF8012E5CC(s32, s32, s32) __asm__("func_8012E5CC");
extern void func_801473EC(s32 *a0);
extern void func_80147A84(s32 arg0);
extern int func_80148AFC(void *a0);
extern s32 func_801496D4(void *a0);
extern void func_80149704(void);
extern s32 func_80149AA8(s32 *a0);
extern s32 func_80149B54(s32 *a0);
extern s32 func_801498E0(s32 *a0);
extern s32 func_80149954(s32 s0);
extern s32 func_80149A64(s32 *a0);
extern void func_80149AD4(s32 *a0);
extern s32 func_80149B54(s32 * arg0);
extern void func_80149BAC(s32 *a0);
extern s32 func_80149FB0(s32 a0);
extern void func_8014C010(s32 a0, s32 a1);
extern void func_8014CC28(s32 a0);
extern void func_8014D738(void);
extern u16 D_800B99DA;
extern s32 func_8014F3E8(s32 param_1);
extern void func_80147324(s32 a0);
extern s32 func_8014F3E8(s32 a0);
extern void func_8001382C(s32 a0, void *a1, void *a2);
extern void func_8014CC28(s32 a0);
extern s32 func_8014F3E8(s32 a0);
void func_80147078(s32 *a0, s16 a1);
extern void func_80147A84(int);
extern void func_80159BE4(s32);
extern void func_80159BE4(s32 arg0);
extern s32 func_80149FB0(s32 a0);
extern s32 func_801619A4(s32 *a0);
extern s32 func_80149AA8(s32 *a0);
extern void func_80149AD4(s32 *a0);
extern s32 func_80149B54(s32 * arg0);
extern void func_80149BAC(s32 *a0);
extern s32 func_801498E0(s32 *a0);
extern s32 func_80149954(s32 s0);
extern s32 func_80149A64(s32 *a0);
extern void func_800CCCC0(s32 a0);
extern s32 func_801496D4(void *a0);
extern void func_80149704(void);
extern void func_8014C010(s32 a0, s32 a1);
extern void func_80147078(s32 *a0, s16 a1);
extern int func_80148AFC(void *a0);
extern void func_80146DB8(s32 *a0, s32 *a1);
extern void func_80147A84(s32 a0);
extern void func_801473EC(s32 *a0);
extern void func_8014D738(void);
extern void func_8015C6E0(s32 *a0);
void func_80146DB8(s32 *a0, s32 *a1);
extern void func_80147078(s32 *a0, s16 a1);
extern void func_80147078(s32 *a0, s16 a1);
extern void (*D_801862A8[])(void *);
extern s32 func_80149FB0(s32 a0);
extern s32 func_801619A4(s32 *a0);
extern s32 func_801498E0(s32 *a0);
extern s32 func_80149954(s32 s0);
extern s32 func_80149A64(s32 *a0);
extern void func_800CCCC0(s32 a0);
extern int func_80148AFC(void *a0);
extern s32 func_80146E98(s32 a0);
extern void func_80147A84(s32 a0);
extern void func_801473EC(s32 *a0);
extern s32 func_80149AA8(s32 *a0);
extern void func_80147324(s32 arg0);
extern s32 func_80149B54(s32 *a0);
extern void func_80147324(s32 a0);
extern void func_80147078(s32 *a0, s16 a1);
extern s32 func_8015BE94();
extern void func_80147078(s32 *a0, s16 a1);
extern s32 func_8015BE94();
s32 func_8015BE94(s32 *a0);
extern void func_80147078(s32 *a0, s16 a1);
extern void func_8015C0C4(s32 a0);
extern void func_80147078(s32 *a0, s16 a1);
extern void func_80147078(s32 *a0, s16 a1);
extern void func_8015C0C4(s32);
void func_8015C0C4(s32 a0);
extern void func_8001382C(s32 a0, void *a1, void *a2);
extern void func_80146DB8(s32 *a0, s32 *a1);
extern s32 func_80146E98(s32 a0);
extern void func_80147078(s32 *a0, s16 a1);
extern void func_80147324(s32 a0);
extern void func_801473EC(s32 *a0);
extern void func_80147A84(s32 arg0);
extern int func_80148AFC(void *a0);
extern s32 func_80149FB0(s32 a0);
extern void func_8014C010(s32 a0, s32 a1);
extern void func_8014CC28(s32 a0);
extern void func_8014D738(void);
extern s32 func_8014F3E8(s32 a0);
extern s32 func_8015BE94();
extern void func_8015C0C4(s32 a0);
extern u16 D_800B99DA;
extern s32 func_80149FB0(s32 a0);
extern s32 func_801496D4(void*);
extern void func_80149704(void);
extern s32 func_801619A4(s32*);
extern s32 func_80149AA8(s32*);
extern void func_80149AD4(s32*);
extern s32 func_80149B54(s32*);
extern void func_80149BAC(s32*);
extern s32 func_801498E0(s32*);
extern s32 func_80149954(s32);
extern s32 func_80149A64(s32*);
extern void func_800CCCC0(s32 a0);
extern int func_80148AFC(void *a0);
extern void func_8001382C(s32 a0, void *a1, void *a2);
extern void func_80146DB8(s32 *a0, s32 *a1);
extern void func_80147A84(s32 a0);
extern void func_801473EC(s32*);
extern void func_8014C010(s32 a0, s32 a1);
extern void func_80147324(s32 a0);
extern void func_8014D738(void);
extern void func_8014CC28(s32);
extern s32 func_8014F3E8(s32);
extern s32 func_80146E98(s32 a0);
extern void func_80147078(s32 *a0, s16 a1);
extern s32 func_8015BE94();
extern void func_80159BE4(s32 a0);
extern void func_8015C0C4(s32 a0);
extern void func_8015C6E0(s32*);
void func_8015C6E0(s32 *a0);
s32 func_801619A4(s32 *a0);

void func_8015C32C(s32 arg0) {
    extern void (*D_801862A8[])(void *);
    s32 iVar2;
    u32 uVar4;
    s32 vin[4];
    s32 vout[4];
    func_80149FB0(arg0);
    if (((s32 (*)(s32))func_801496D4)(arg0) != 0) {
        D_801862A8[*(u16 *)arg0]((void *)arg0);
        ((void (*)(s32))func_80149704)(arg0);
        return;
    }
    switch (((s32 (*)(s32))func_801619A4)(arg0)) {
    case 0:
    case 1:
    case 6:
        if (((s32 (*)(s32))func_80149AA8)(arg0) != 0) {
            D_801862A8[*(u16 *)arg0]((void *)arg0);
            ((void (*)(s32))func_80149AD4)(arg0);
            return;
        }
        if (((s32 (*)(s32))func_80149B54)(arg0) != 0) {
            D_801862A8[*(u16 *)arg0]((void *)arg0);
            ((void (*)(s32))func_80149BAC)(arg0);
            return;
        }
        break;
    case 3:
        ((void (*)(s32))func_801498E0)(arg0);
        break;
    case 4:
        ((void (*)(s32))func_80149954)(arg0);
        break;
    case 5:
        if (((s32 (*)(s32))func_80149A64)(arg0) != 0) {
            D_801862A8[*(u16 *)arg0]((void *)arg0);
            func_800CCCC0(arg0);
            return;
        }
    }
    if ((func_80148AFC((void *)arg0) & 0xff) != 0) {
        vin[0] = 0;
        vin[1] = 0;
        vin[2] = -0x4000;
        func_8001382C((s32)*(s16 *)(*(s32 *)(arg0 + 0x20) + 0x12), vin, vout);
        *(s32 *)(arg0 + 0x234) += vout[0];
        *(s32 *)(arg0 + 0x238) += vout[1];
        *(s32 *)(arg0 + 0x23c) += vout[2];
    }
    func_8001382C((s16)-*(u16 *)(*(s32 *)(arg0 + 0x20) + 0x12), (void *)(arg0 + 0x234), vout);
    func_80146DB8((s32 *)arg0, vout);
    func_80147A84(arg0);
    ((void (*)(s32))func_801473EC)(arg0);
    if ((D_800B99DA & 3) == 0) {
        func_8014C010(arg0, 1);
        func_80147324(0x65f);
    }
    if (((s32 (*)(s32))func_8014D738)(arg0) != 0) {
        D_801862A8[*(u16 *)arg0]((void *)arg0);
        ((void (*)(s32))func_8015C6E0)(arg0);
        return;
    }
    iVar2 = ((s32 (*)(s32))func_8014CC28)(arg0);
    uVar4 = ((u32 (*)(s32))func_8014F3E8)(arg0);
    if (uVar4 != 0) {
        if ((uVar4 & 0x4000) == 0) {
            if (func_80146E98(arg0) != 0) {
                D_801862A8[*(u16 *)arg0]((void *)arg0);
                func_80147078((s32 *)arg0, 0);
                func_80159BE4(arg0);
            }
        } else {
            func_80147078((s32 *)arg0, 4);
            func_8015C0C4(arg0);
        }
    } else {
        if (iVar2 == 0) {
            D_801862A8[*(u16 *)arg0]((void *)arg0);
            func_80147078((s32 *)arg0, 3);
            ((void (*)(s32))func_8015BE94)(arg0);
        }
    }
}
