/* sc02_0037: func_8015D738 from Druthulu/BFM-decomp
 * src/ov_SC02_037/ov_SC02_037_jr_8015A3C8.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc02_0037 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
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
extern void func_80149374(s32 a0, s32 a1);
extern void func_80147078(s32 *a0, s16 a1);
extern s32 aF8012E5CC(s32, s32, s32) __asm__("func_8012E5CC");
extern void func_801473EC(s32 *a0);
extern void func_80147A84(s32 arg0);
extern void func_801483E8(unsigned char *self);
extern u16 func_80148800(s32 *a0);
extern s32 func_801488A8(u8 *a0);
extern int func_80148AFC(void *a0);
extern void func_80149374(s32 arg0, s32 arg1);
extern void func_8015DAC4(s32 *a0);
extern u8 func_8014BEF8(void);
extern void func_8015DE24(s32 *a0);
extern void func_8014D738(void);
extern void func_80154A74(s32 a0, s32 a1);
extern void func_80154150(s32 a0, s32 a1);
extern int func_80161208();
extern s32 func_80161208();
void func_80147078(s32 *a0, s16 a1);
extern void func_80147A84(int);
extern void func_80154A74(int, int);
extern void func_80159B70(void *a0);
extern s32 func_80161B84(void *a0);
extern s32 func_80161B18(void *a0);
extern s32 func_801488A8(u8 *a0);
extern void func_80147078(s32 *a0, s16 a1);
extern void func_80159B70(void *a0);
extern int func_80148AFC(void *a0);
extern void func_80154150(s32 a0, s32 a1);
extern void func_80154A74(s32 a0, s32 a1);
extern void func_80146DB8(s32 *a0, s32 *a1);
extern void func_80147A84(s32 a0);
extern void func_801473EC(s32 *a0);
extern void func_8014D738(void);
extern void func_801483E8(unsigned char*);
void func_80154150(s32 a0, s32 a1);
void func_80146DB8(s32 *a0, s32 *a1);
extern void func_80154A74(s32 a0, s32 a1);
extern void func_80147078(s32 *a0, s16 a1);
extern void func_80147078(s32 *a0, s16 a1);
extern void (*D_801862A8[])(void *);
extern void func_80154A74(s32 a0, s32 a1);
extern int func_80148AFC(void *a0);
extern void func_80147A84(s32 a0);
extern void func_801473EC(s32 *a0);
extern void func_80154150(s32 a0, s32 a1);
extern void func_80154150(s32 a0, s32 a1);
extern void func_80154A74(s32 a0, s32 a1);
extern void func_80154A74(s32 a0, s32 a1);
extern void func_80154150(s32 a0, s32 a1);
extern void func_80154A74(s32 a0, s32 a1);
extern void func_80147078(s32 *a0, s16 a1);
extern void func_80147078(s32 *a0, s16 a1);
extern void func_80154A74(s32 a0, s32 a1);
extern void func_80147078(s32 *a0, s16 a1);
extern void func_80147078(s32 *a0, s16 a1);
extern void func_80147078(s32 *a0, s16 a1);
extern void func_80154150(s32 a0, s32 a1);
extern void func_80154150(s32 a0, s32 a1);
extern void func_80146DB8(s32 *a0, s32 *a1);
extern void func_80147078(s32 *a0, s16 a1);
extern void func_801473EC(s32 *a0);
extern void func_80147A84(s32 arg0);
extern int func_80148AFC(void *a0);
extern void func_8014D738(void);
extern int func_80148AFC(void *a0);
extern void func_80146DB8(s32 *a0, s32 *a1);
extern void func_80147A84(s32 a0);
extern void func_801473EC(s32*);
extern void func_8014D738(void);
extern void func_80147078(s32 *a0, s16 a1);
extern void func_80147078(s32 *a0, s16 a1);
extern void func_80147078(s32 *a0, s16 a1);
extern void func_8015C714(void *a0);
void func_8015C714(void *a0);
extern void func_80154150(s32 a0, s32 a1);
extern void func_80154A74(s32 a0, s32 a1);
extern s32 func_80161B18(void *a0);
extern s32 func_80161B84(void *a0);
extern s32 func_801488A8(u8 *a0);
extern void func_80147078(s32 *a0, s16 a1);
extern void func_80159B70(void *a0);
extern void func_80146DB8(s32 *a0, s32 *a1);
extern void func_801473EC(s32 *a0);
extern void func_8014D738(void);
extern void func_80147078(s32 *a0, s16 a1);
extern void func_80159B70(void *a0);
extern s32 func_80161B18(void *a0);
extern s32 func_80161B84(void *a0);
extern s32 func_801488A8(u8 *a0);
extern void func_801473EC(s32 *a0);
extern void func_8014D738(void);
extern void func_80146DB8(s32 *a0, s32 *a1);
extern void func_80147078(s32 *a0, s16 a1);
extern void func_80159B70(void *a0);
extern void func_80154A74(s32 a0, s32 a1);
extern void func_80147078(s32 *a0, s16 a1);
extern void func_80154150(s32 a0, s32 a1);
extern void func_80146DB8(s32 *a0, s32 *a1);
extern void func_80147078(s32 *a0, s16 a1);
extern void func_801473EC(s32 *a0);
extern void func_80147A84(s32 arg0);
extern int func_80148AFC(void *a0);
extern void func_80154150(s32 a0, s32 a1);
extern void func_80159B70(void *a0);
extern void func_80154A74(s32 a0, s32 a1);
extern void func_80147078(s32 *a0, s16 a1);
extern void func_80147078(s32 *a0, s16 a1);
extern void func_80159B70(void *a0);
extern u16 func_80148800(s32 *a0);
extern void func_80146DB8(s32*, s32*);
extern void func_80147078(s32 *a0, s16 a1);
extern void func_80159B70(void*);
extern void *memcpy(void *dst, const void *src, u32 n);
extern void func_80154A74(s32 a0, s32 a1);
extern void func_80147078(s32 *a0, s16 a1);
extern void func_80147078(s32 *a0, s16 a1);
extern void func_80154A74(s32 a0, s32 a1);
extern void func_80154150(s32 a0, s32 a1);
extern s32 func_80161B18(void *a0);
extern s32 func_80161B84(void *a0);
extern void func_80154A74(int, int);
extern s32 func_80161208();
extern void func_80154150(int, int);
extern void func_80149374(int, int);
extern int func_80148AFC(void*);
extern s32 func_80161B18(void *);
extern s32 func_80161B84(void *);
extern u16 func_80148800(s32*);
extern u8 func_8014BEF8(void);
extern s32 func_80165624(s32);
extern s32 func_801488A8(u8*);
extern void func_8014D738(void);
extern s32 func_80161208();
extern void func_80154A74(s32, s32);
extern void func_8015DAC4(s32*);
extern void func_8015DE24(s32*);
extern void func_8015DA5C(s32);
extern void func_8015F948(s32*);
extern void func_800CAF14(void *);
extern void func_80154150(s32, s32);
extern void func_80146DB8(s32*, s32*);
extern void func_80147A84(s32);
extern void func_801473EC(s32*);
extern void func_80149374(s32, s32);
extern void func_80147078(s32*, s16);
extern void func_80159B70(void *);
extern void func_8015C714(void *);
extern void func_801483E8(unsigned char*);
void func_8015DA5C(s32 a0);
void func_8015DAC4(s32 *a0);
void func_8015DE24(s32 *a0);
void func_8015F948(s32 *param_1);
s32 func_80161B18(void *a0);
s32 func_80161B84(void *a0);
s32 func_80165624(s32 a0);

void func_8015D738(void *arg0) {
    extern u8 D_80078E78[];
    extern u8 D_801864EC[];
    extern u8 D_8018626C[];
    extern u8 D_8018627C[];
    u8 *p = D_80078E78;
    s32 s1;
    ((void (*)(void))func_80148AFC)();
    if (func_80161B18(arg0) != 0) return;
    if (func_80161B84(arg0) != 0) return;
    s1 = *(s32 *)((char *)arg0 + 0x178);
    if (s1 != 0) {
        if (*(u16 *)s1 == 0x360) goto block_808;
    }
    __asm__ __volatile__("");
    if (s1 != 0) {
        if (*(u16 *)s1 != 0) goto block_7F4;
    }
    D_801862A8[*(u16 *)arg0](arg0);
    ((void (*)(void *, s32))func_80147078)(arg0, 0);
    func_80159B70(arg0);
    return;
block_7F4:
    if (((s32 (*)(void *))func_80148800)(arg0) & 0x80) {
    block_808:
        ((void (*)(void *, s32))func_80154A74)(arg0, 0x11);
        ((void (*)(void *))func_8015DAC4)(arg0);
        return;
    }
    if ((((s32 (*)(void *))func_80148800)(arg0) & 0x10) && ((s32 (*)(void *))func_8014BEF8)(arg0) != 0) {
        ((void (*)(void *, s32))func_80154A74)(arg0, 0x11);
        ((void (*)(void *))func_8015DE24)(arg0);
        return;
    }
    if ((((s32 (*)(void *))func_80148800)(arg0) & 0x20) && p[0x49] == 0xA) {
        if (((s32 (*)(void *))func_80165624)(arg0) != 0) {
            ((void (*)(void *))func_8015DA5C)(arg0);
            ((void (*)(void *))func_8015F948)(arg0);
            return;
        }
        ((void (*)(void *, s32))func_80154A74)(arg0, 0x11);
        func_800CAF14(arg0);
        return;
    }
    if (((s32 (*)(void *))func_801488A8)(arg0) != 0 && *(u16 *)(*(s32 *)((char *)arg0 + 0x178)) != 0x82) {
        ((void (*)(void *, s32))func_80154150)(arg0, 0x1B);
        ((void (*)(void *, void *))func_80146DB8)(arg0, &D_8018626C);
    } else {
        ((void (*)(void *, s32))func_80154150)(arg0, 0x1A);
        ((void (*)(void *, void *))func_80146DB8)(arg0, &D_8018627C);
    }
    ((void (*)(void *))func_80147A84)(arg0);
    ((void (*)(void *))func_801473EC)(arg0);
    s1 = *(s32 *)((char *)arg0 + 0x178);
    *(s16 *)(s1 + 6) = (s16)((s8)D_801864EC[*(s32 *)((char *)arg0 + 0x234)] + *(u16 *)(*(s32 *)(s1 + 0x78) + 0xc));
    *(s16 *)(s1 + 0xa) = (s16)((s8)D_801864EC[*(s32 *)((char *)arg0 + 0x234) + 1] + *(u16 *)(*(s32 *)(s1 + 0x78) + 0xe));
    *(s16 *)(s1 + 0xe) = (s16)((s8)D_801864EC[*(s32 *)((char *)arg0 + 0x234) + 2] + *(u16 *)(*(s32 *)(s1 + 0x78) + 0x10));
    ((void (*)(void *, void *))func_80149374)(arg0, (void *)(s1 + 4));
    *(s16 *)(*(s32 *)(s1 + 0x20) + 0x12) = (*(u16 *)(*(s32 *)((char *)arg0 + 0x20) + 0x12) + 0x800) & 0xFFF;
    if (((s32 (*)(void *))func_8014D738)(arg0) != 0) {
        D_801862A8[*(u16 *)arg0](arg0);
        ((void (*)(void *, s32))func_80147078)(arg0, 9);
        func_8015C714(arg0);
        return;
    }
    if (func_80161208(arg0) != 0) return;
    ((void (*)(void *))func_801483E8)(arg0);
}
