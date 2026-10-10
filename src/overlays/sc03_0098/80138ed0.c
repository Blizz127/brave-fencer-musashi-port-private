/* sc03_0098: func_80138ED0 from Druthulu/BFM-decomp
 * src/ov_SC03_098/ov_SC03_098_jr_801380E0.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0098 retail words (gcc-2.7.2 -O2). */
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
extern s32 func_8013914C(s32 a0, s32 a1);
extern void func_800599B8(u16 *);
extern u16 D_80127C0C[];
extern s32 D_80127548[];
s32 func_8013914C(s32 a0, s32 a1);

s32 func_80138ED0(u8 *param_1, u32 param_2, u8 *param_3)
{
    u16 local[4];
    u16 uVar1;
    s32 result;
    u16 uVar4;
    u8 *pbVar7;
    u8 *pb;
    u16 *base;
    u16 *p;
    s32 iVar2;
    u32 s0acc;
    u32 tmp;
    s32 shift;
    pb = param_3;
    uVar1 = *(u8 *)(param_1 + 0x23) & 0xf;
    result = ((s32 (*)(u8 *, u16 *))func_8013914C)(param_1, local);
    if (result != 0) {
        return 1;
    }
    uVar4 = local[0] - *(u16 *)(param_1 + 0x38);
    pbVar7 = pb + (param_2 & 0xffff) * 0xc;
    base = D_80127C0C + uVar4;
    iVar2 = 0;
    if (uVar4 % 3 != 0) {
        u32 pv = uVar1;
        p = base;
        do {
            shift = 6;
            do {
                tmp = (s0acc & 0xffff) << 4;
                s0acc = tmp | pv;
                if ((((s32)*pbVar7 >> shift) & 1) == 0) {
                    s0acc = tmp;
                }
                shift++;
            } while (shift < 8);
            *p = *p | (s0acc << 8);
            p++;
            shift = 2;
            do {
                tmp = (s0acc & 0xffff) << 4;
                s0acc = tmp | pv;
                if ((((s32)*pbVar7 >> shift) & 1) == 0) {
                    s0acc = tmp;
                }
                shift++;
            } while (shift < 6);
            *p = s0acc;
            p += 0x35;
            iVar2++;
            pbVar7++;
        } while (iVar2 < 0xc);
        iVar2 = 0;
    } else {
        u32 pv = uVar1;
        p = base;
        do {
            shift = 4;
            do {
                tmp = (s0acc & 0xffff) << 4;
                s0acc = tmp | pv;
                if ((((s32)*pbVar7 >> shift) & 1) == 0) {
                    s0acc = tmp;
                }
                shift++;
            } while (shift < 8);
            *p = s0acc;
            p++;
            shift = 2;
            do {
                tmp = (s0acc & 0xffff) << 4;
                s0acc = tmp | pv;
                if ((((s32)*pbVar7 >> shift) & 1) == 0) {
                    s0acc = tmp;
                }
                shift++;
            } while (shift < 4);
            *p = s0acc & 0xff;
            p += 0x35;
            iVar2++;
            pbVar7++;
        } while (iVar2 < 0xc);
        iVar2 = 0;
    }
    {
        u16 *src = base;
        s32 dcount;
        s32 df;
        s32 decoy;
        s32 c36;
        u16 tv;
        register s32 *dp __asm__("$4");
        register u16 *ba __asm__("$5");
        dp = D_80127548;
        dcount = *dp;
        c36 = 0x24;
        __asm__ ("" : : "r"(c36), "r"(dcount));
        df = c36 - dcount;
        tmp = (df << 1) + df;
        tmp = tmp << 4;
        dp = dp + 1;
        ba = (u16 *)(tmp + (u8 *)dp);
        __asm__ ("" : "=r"(decoy) : "r"(ba));
        __asm__ ("" : : "r"(decoy));
        {
            register u16 *dst __asm__("$4");
            dst = ba;
            do {
                tv = *src; src++;
                *dst = tv; dst++;
                tv = *src; src += 0x35;
                *dst = tv; dst++;
                iVar2++;
            } while (iVar2 < 0xc);
        }
    }
    local[2] = 2;
    local[3] = 0xc;
    func_800599B8(local);
    return 0;
}
