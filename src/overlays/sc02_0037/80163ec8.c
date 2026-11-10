/* sc02_0037: func_80163EC8 from Druthulu/BFM-decomp
 * src/ov_SC02_037/ov_SC02_037_jr_8015A3C8.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc02_0037 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef short s16;
typedef int s32;
typedef struct { u8 b[8]; } Blk8;
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
extern s32 func_80012F74(s32, s32, s32, s32);
extern void *memcpy(void *, const void *, unsigned int);
extern s32 func_80012F74(s32, s32, s32, s32);
extern void func_8012A568(void (*a0)(void));
extern void func_8012A5F8(void (*a0)(void), s32 a1);
extern s16 D_800B9A02;
extern void func_8012E5CC(s32 param_1, u16 param_2, u16 param_3);
extern void func_80015978(s32 a0, s32 *a1);
extern void *memcpy(void *, const void *, u32);
extern void func_8005C324(int dst, int src, int n) __asm__("memcpy");
extern short D_800B9A02;
extern void func_80051DC8(void *a0, void *a1, s32 a2);
extern void func_80137030(s16 a0, s16 a1);
extern void aGsSortLine(Gline_801372B0 *p, void *ot, s32 z) __asm__("func_80051DC8");
extern void aF80137030(s32 x, s32 y) __asm__("func_80137030");
extern u16 aD800B9A02 __asm__("D_800B9A02");
extern void *memcpy(void *dst, const void *src, u32 n);
extern s32 D_80127098;
extern s32 D_80127094;
extern s32 D_80127090;
extern void func_801466F0(s32 a0, s32 a1, s32 a2, s32 a3, s32 sp5, s32 sp6, s32 sp7, s32 sp8);
extern void aF801466F0(u16 a0, s32 a1, u16 a2, u16 a3, u16 sp5, s32 sp6, s32 sp7, s32 sp8) __asm__("func_801466F0");
extern void aF801466F0(u16 a0, s32 a1, u16 a2, u16 a3, u16 sp5, s32 sp6, s32 sp7, s32 sp8);
extern s32 func_80146994(s32 a0, s32 a1, s32 a2, s32 a3);
extern s32 func_80146994(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
extern void func_80146CA0(void *a0);
extern void func_80146E90(s32 *a0, s32 a1);
extern void func_80147324(s32 arg0);
extern void func_80015978(s32, s32*);
extern s32 aF8012E5CC(s32, s32, s32) __asm__("func_8012E5CC");
extern s32 D_80127090;
extern s32 D_80127094;
extern s32 D_80127098;
extern void func_80015978(int a0, int *a1);
extern s32 func_800CF8B4();
extern u16 func_80148800(s32 *a0);
extern void func_80149350(s32 arg0);
extern void func_801599A4(void *a0);
extern u16 func_80156370(u16 a0);
extern void func_8014C4AC(s32 a0, s32 a1, s32 a2, s16 *a3, s32 a4);
extern void func_80162CCC();
extern void func_8014AD30(s32 a0, u16 *a1, s32 a2, s32 a3);
extern void func_8014C010(s32 a0, s32 a1);
extern s32 func_8014CA00(s32 a0);
extern u16 D_800B99DA;
extern void func_80147324(s32 a0);
extern void func_8015BDD0(s32 *a0);
extern void func_8015BF48(s32 *a0);
extern int func_80161208();
extern s32 func_80161208();
extern u16 func_80156370(u16 param_1);
extern void func_8015BDD0(s32 *a0);
extern void func_8014C010(s32 a0, s32 a1);
void func_80161CD0(s32 a0, s32 a1);
extern s32 func_80146994(s32 a0, s32 a1, s32 a2, s32 a3);
extern s32 func_800CF8B4(void);
extern void func_80146E90(s32 *a0, s32 a1);
extern void func_80146CA0(void *a0);
extern s32 func_80146994(s32 a0, s32 a1, s32 a2, s32 a3);
extern void func_80147324(s32 arg0);
extern s32 func_80146994(s32 a0, s32 a1, s32 a2, s32 a3);
extern void func_80147324(s32 a0);
void func_8015BDD0(s32 *a0);
extern void func_80146CA0(void *a0);
void func_8015BF48(s32 *a0);
extern void func_80146CA0(void *a0);
extern void func_80146CA0(void *a0);
extern void func_80146CA0(void *a0);
extern void func_80146E90(s32 *a0, s32 a1);
extern void func_80147324(s32 a0);
extern void func_8014C010(s32 a0, s32 a1);
extern u16 D_800B99DA;
extern void func_8014C010(s32 a0, s32 a1);
extern void func_80147324(s32 a0);
extern void func_80146E90(s32 *a0, s32 a1);
extern void func_80146CA0(void *a0);
extern void func_80146E90(s32 *a0, s32 a1);
extern void func_80146CA0(void *a0);
extern void func_8014C010(s32 a0, s32 a1);
extern void func_80146CA0(void *a0);
extern void func_80146E90(s32 *a0, s32 a1);
extern void func_80147324(s32 arg0);
extern void func_80146CA0(void *a0);
extern void func_80146CA0(void *a0);
extern void func_80146CA0(void *a0);
extern void func_80147324(s32 a0);
extern u16 func_80148800(s32 *a0);
extern void func_80146E90(s32 *a0, s32 a1);
extern void *memcpy(void *dst, const void *src, u32 n);
extern void func_80146CA0(void *a0);
extern s32 func_80161208();
extern void func_80146CA0(void *a0);
extern u16 func_80148800(s32*);
extern s32 func_80161208();
extern void func_80146CA0(void *a0);
extern s32 func_80161208();
extern void func_8014C4AC(s32 a0, s32 a1, s32 a2, s16 *a3, s32 a4);
extern void func_80146CA0(void *a0);
extern s32 func_80161208();
extern s32 func_80146994(s32 a0, s32 a1, s32 a2, s32 a3);
extern void func_80146CA0(void *a0);
extern s32 func_80161208();
extern s32 func_80146994(s32 a0, s32 a1, s32 a2, s32 a3);
extern void func_80146CA0(void *a0);
extern s32 func_80161208();
extern void func_80149350(s32 arg0);
extern void func_80015978(s32 a0, s32 *a1);
extern void func_8014C4AC(s32 a0, s32 a1, s32 a2, s16 *a3, s32 a4);
extern s32 func_80161208();
extern void func_80015978(s32 a0, s32 *a1);
extern void func_8014C4AC(s32 a0, s32 a1, s32 a2, s16 *a3, s32 a4);
extern void func_80146CA0(void *a0);
extern s32 func_800CF8B4(void);
extern s32 func_80161208();
extern void func_80146CA0(void *a0);
extern s32 func_80146994(s32 a0, s32 a1, s32 a2, s32 a3);
extern void func_80146CA0(void *a0);
extern void func_801466F0(s32 a0, s32 a1, s32 a2, s32 a3, s32 sp5, s32 sp6, s32 sp7, s32 sp8);
extern void func_80147324(s32 a0);
extern s32 func_80161208();
extern void func_80146E90(s32 *a0, s32 a1);
extern void func_80147324(s32 arg0);
extern void func_80146CA0(void *a0);
extern u16 func_80148800(s32*);
extern void func_80146E90(s32*, s32);
extern void func_80147324(s32 a0);
extern void func_80146CA0(void *a0);
extern void func_801466F0(s32, s32, s32, s32, s32, s32, s32, s32);
extern s32 func_80161208();
extern s32 func_80161208();
extern void func_80147324(s32 a0);
extern void func_80146CA0(void *a0);
extern void func_80146CA0(void *a0);
extern void func_80147324(s32 arg0);
extern void func_80146CA0(void *a0);
extern void func_80147324(s32 a0);
extern void func_801466F0(s32 a0, s32 a1, s32 a2, s32 a3, s32 sp5, s32 sp6, s32 sp7, s32 sp8);
extern void func_80146CA0(void *a0);
extern s32 func_80161208();
extern void func_80146CA0(void *a0);
extern s32 func_80161208();
extern void func_80146CA0(void *a0);
extern s32 func_80161208();
extern s32 func_80161208();
extern void func_80147324(s32 arg0);
extern void func_80146E90(s32 *a0, s32 a1);
extern void func_80146CA0(void *a0);
extern u16 func_80148800(s32 *a0);
extern s32 func_800CF8B4();
extern s32 func_80161208();
extern void func_80146CA0(void *a0);
extern s32 func_80161208();
extern void func_80146CA0(void *a0);
extern s32 func_80161208();
extern void func_80146CA0(void *a0);
extern s32 func_80161208();
extern void func_80146CA0(void *a0);
extern s32 func_80161208();
extern void func_80146CA0(void *a0);
extern u16 func_80148800(s32 *a0);
extern s32 func_80161208();
extern void func_80146E90(s32 *a0, s32 a1);
extern void func_80146CA0(void *a0);
extern void func_80146CA0(void *a0);
extern void func_80146CA0(void *a0);
extern s32 func_80161208();
extern void func_80146E90(s32 *a0, s32 a1);
extern void func_80147324(s32 a0);
extern void func_8016130C(void*, s32);
void aF80161208(void *a0) __asm__("func_80161208");
void aF80161208(void *a0) __asm__("func_80161208");
extern void func_8016130C(void *a0, s32 a1);
extern void func_801599A4(void*);
extern void func_8015BDD0(s32*);
extern void func_8015BF48(s32*);
s32 aF8016130C(void *a0, s32 a1) __asm__("func_8016130C");
s32 aF8016130C(void *a0, s32 a1) __asm__("func_8016130C");
s32 aF8016130C(void *a0, s32 a1) __asm__("func_8016130C");
void func_801599A4(void *a0);
void func_8015BDD0(s32 *a0);
void func_8015BF48(s32 *a0);
extern void func_801599A4(void*);
extern void func_8015BDD0(s32*);
extern void func_8015BF48(s32*);
extern void func_8016191C(void *a0, s32 a1);
extern void func_801599A4(void *a0);
extern void func_8014C010(s32 a0, s32 a1);
extern void func_8015BF48(s32 *a0);
extern void func_8014C010(s32 a0, s32 a1);
extern void func_801599A4(void *a0);
extern void func_8015BF48(s32 *a0);
void func_8014C010(s32 a0, s32 a1);
extern void func_8014C010(int a0, int a1);
int aF8016191C(int param_1, unsigned int param_2) __asm__("func_8016191C");
int aF8016191C(int param_1, unsigned int param_2) __asm__("func_8016191C");
extern void func_801599A4(void *a0);
extern void func_801599A4(void *a0);
void func_801599A4(void *a0);
extern void func_80147324();
extern void func_80147324(s32 arg0);
extern int func_800CF8B4();
extern void func_80147324(int arg0);
void aF80161CD0(int param_1, unsigned int param_2) __asm__("func_80161CD0");
void aF80161CD0(int param_1, unsigned int param_2) __asm__("func_80161CD0");
extern void func_80147324(s32 arg0);
extern void func_80016714(void *a0, s32 a1);
extern void func_80016714(void *a0, s32 a1);
extern void func_80016714(void *a0, s32 a1);
extern void func_80016714(void *a0, s32 a1);
extern void func_80016714(void *a0, s32 a1);
extern void func_80016714(void *a0, s32 a1);
void aF80162CCC(u8 *a0) __asm__("func_80162CCC");
void aF80162CCC(u8 *a0) __asm__("func_80162CCC");
void func_80162D88(s32 *a0);
extern s32 aD_80127090 __asm__("D_80127090");
extern s32 aD_80127094 __asm__("D_80127094");
extern s32 aD_80127098 __asm__("D_80127098");
extern s32 aD_80127090 __asm__("D_80127090");
extern s32 aD_80127094 __asm__("D_80127094");
extern s32 aD_80127098 __asm__("D_80127098");
extern s32 aD_80127090 __asm__("D_80127090");
extern s32 aD_80127094 __asm__("D_80127094");
extern s32 aD_80127098 __asm__("D_80127098");
extern s32 aD_80127090 __asm__("D_80127090");
extern s32 aD_80127094 __asm__("D_80127094");
extern s32 aD_80127098 __asm__("D_80127098");
extern u16 func_80156370(u16 a0);
extern void *memcpy(void *dst, const void *src, unsigned int n);
extern void func_8014AD30(s32 a0, u16 *a1, s32 a2, s32 a3);
extern void func_80015978(s32 a0, s32 *a1);
extern void func_80015978(s32 a0, s32 *a1);
extern void *memcpy(void *, const void *, u32);
extern void func_80015978(s32 a0, s32 *a1);
extern void *memcpy(void *, const void *, u32);
extern void func_80015978(s32 a0, s32 *a1);
extern s32 func_80146994(s32 a0, s32 a1, s32 a2, s32 a3);
extern void func_80146CA0(void *a0);
extern void func_80146E90(s32 *a0, s32 a1);
extern void func_80147324(s32 a0);
extern u16 func_80148800(s32 *a0);
extern void func_80149350(s32 arg0);
extern void func_8014AD30(s32 a0, u16 *a1, s32 a2, s32 a3);
extern s32 func_8014CA00(s32 a0);
extern u16 func_80156370(u16 a0);
extern void func_80162D88(s32 *a0);
u8 func_801656D0(s32 a0, s32 a1);

void func_80163EC8(s32 param_1)
{
    extern Blk8 D_801C7E28;
    extern u16 D_800B99DA;
    extern u8 func_801656D0(s32 a0, s32 a1);
    extern s32 func_80012F74(s32 a0, s32 a1, s32 a2, s32 a3);
    extern void func_80015978(s32 a0, s32 *a1);
    extern void func_8014C4AC(s32 a0, s32 a1, s32 a2, s16 *a3, s32 a4);
    Blk8 in;
    u16 out[4];
    s16 buf[4];
    s32 psVar6;
    s32 iVar8;
    s32 iVar7;
    s32 uVar5;
    u16 uVar4;
    u8 uVar3;
    in = D_801C7E28;
    psVar6 = *((s32 *) (param_1 + 0x4c));
    iVar8 = *((s32 *) (param_1 + 0x20));
    func_80162D88((s32 *) param_1);
    if ((*((s32 *) (psVar6 + 0x184))) == 0)
    {
        *((s16 *) (psVar6 + 0x18a)) = 0;
        *((s16 *) (psVar6 + 0x188)) = 0;
        *((s32 *) (psVar6 + 0x44)) = (*((s32 *) (psVar6 + 0x44))) & (~0x20);
        func_80146CA0((void *) param_1);
        func_80146CA0((void *) param_1);
        return;
    }
    if ((*((s16 *) ((*((s32 *) (psVar6 + 0x184))) + 0x36))) == (*((u16 *) (psVar6 + 0x194))))
    {
        goto LAB_matched;
    }
    *((s32 *) (psVar6 + 0x184)) = 0;
    *((s16 *) (psVar6 + 0x18a)) = 0;
    *((s16 *) (psVar6 + 0x188)) = 0;
    *((s32 *) (psVar6 + 0x44)) = (*((s32 *) (psVar6 + 0x44))) & (~0x20);
    func_80146CA0((void *) param_1);
    func_80146CA0((void *) param_1);
    return;
    LAB_matched:
    *((s16 *) (psVar6 + 0x18a)) = (*((u16 *) (psVar6 + 0x18a))) + 1;
    if ((D_800B99DA & 3) == 0)
    {
        if ((*((s16 *) (psVar6 + 0x188))) >= (*((u8 *) (param_1 + 0x67))))
        {
            *((s16 *) (psVar6 + 0x188)) = (*((s16 *) (psVar6 + 0x188))) - (*((u8 *) (param_1 + 0x67)));
        }
        else
        {
            *((s16 *) (psVar6 + 0x188)) = 0;
        }
        if ((*((s16 *) (psVar6 + 0x188))) < 0)
        {
            *((s16 *) (psVar6 + 0x188)) = 0;
        }
    }
    *((s16 *) (param_1 + 0x66)) = (*((u16 *) (param_1 + 0x66))) + 0x40;
    uVar5 = func_80148800((s32 *) psVar6);
    if ((uVar5 & 0x80) != 0)
    {
        *((s16 *) (param_1 + 0x66)) = 0;
        uVar3 = func_801656D0(psVar6, func_8014CA00(*((s32 *) (psVar6 + 0x184))) & 0xff);
        *((s16 *) (psVar6 + 0x188)) = (*((u16 *) (psVar6 + 0x188))) + uVar3;
        *((s16 *) (iVar8 + 0x1a)) = 0x4000;
        *((s16 *) (iVar8 + 0x18)) = 0x4000;
        *((s32 *) (iVar8 + 0x48)) = *((s16 *) (param_1 + 0x58));
        *((s32 *) (iVar8 + 0x4c)) = *((s16 *) (param_1 + 0x5a));
        *((s32 *) (iVar8 + 0x50)) = *((s16 *) (param_1 + 0x5c));
        ((void (*)(s32, s32, s32)) func_80149350)(param_1, (s32) (&in), (s32) out);
        *((s16 *) (param_1 + 0x6)) = out[0];
        *((s16 *) (param_1 + 0xa)) = out[1];
        *((s16 *) (param_1 + 0xe)) = out[2];
    }
    if (0x80 < (*((s16 *) (psVar6 + 0x188))))
    {
        *((s16 *) (psVar6 + 0x188)) = 0x80;
    }
    if ((*((s16 *) (psVar6 + 0x188))) >= 0x80)
    {
        iVar7 = *((s32 *) (psVar6 + 0x184));
        if (iVar7 != 0)
        {
            func_80015978(iVar7 + 4, (s32 *) buf);
            buf[3] = 0;
            uVar4 = func_80156370(0xe);
            func_8014C4AC(iVar7, 0xe, uVar4, buf, *((s16 *) (iVar8 + 0x12)));
            func_80146994(0x33, param_1, 0, iVar7);
        }
    }
    else
    {
        if (((*((s16 *) (psVar6 + 0x18a))) < 0x80) && ((*((u16 *) psVar6)) != 0x19))
        {
            goto LAB_end;
        }
        iVar7 = *((s32 *) (psVar6 + 0x184));
        if (iVar7 != 0)
        {
            func_80015978(iVar7 + 4, (s32 *) buf);
            buf[3] = 0;
            uVar4 = func_80156370(0x21);
            func_8014C4AC(iVar7, 0x21, uVar4, buf, *((s16 *) (iVar8 + 0x12)));
            if (((*((s32 *) (iVar7 + 0xb4))) & 0x40000) != 0)
            {
                func_8014AD30(param_1, (u16 *) buf, 0, *((s16 *) (iVar7 + 0x60)));
            }
        }
    }
    uVar5 = func_8014CA00(iVar7);
    *((s32 *) (psVar6 + 0x184)) = uVar5;
    if (0x1e < ((u32) uVar5))
    {
        *((s32 *) (psVar6 + 0x184)) = 0;
    }
    func_80146E90((s32 *) param_1, 0x20);
    *((s32 *) (psVar6 + 0x44)) = (*((s32 *) (psVar6 + 0x44))) & (~0x20);
    func_80147324(0x449);
    func_80146CA0((void *) param_1);
    func_80146CA0((void *) param_1);
    LAB_end:
    uVar4 = func_80012F74(*((s16 *) (iVar8 + 0x1a)), 0x1800, 3, 1);
    *((s16 *) (iVar8 + 0x1a)) = uVar4;
    *((s16 *) (iVar8 + 0x18)) = uVar4;
    uVar4 = func_80012F74(*((s16 *) (param_1 + 0x6)), *((s16 *) (param_1 + 0x58)), 8, 1);
    *((s16 *) (param_1 + 0x6)) = uVar4;
    uVar4 = func_80012F74(*((s16 *) (param_1 + 0xa)), *((s16 *) (param_1 + 0x5a)), 8, 1);
    *((s16 *) (param_1 + 0xa)) = uVar4;
    uVar4 = func_80012F74(*((s16 *) (param_1 + 0xe)), *((s16 *) (param_1 + 0x5c)), 8, 1);
    *((s16 *) (param_1 + 0xe)) = uVar4;
}
