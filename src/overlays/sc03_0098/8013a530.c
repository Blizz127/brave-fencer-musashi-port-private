/* sc03_0098: func_8013A530 from Druthulu/BFM-decomp
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
extern short D_800B9A02;
extern void *memcpy(void *, const void *, u32);
extern void func_80015D4C(s32 a0, s32 a1, s32 a2, s32 a3, u8 arg4, u8 arg5, u8 arg6, u16 arg7, u16 arg8);
extern void func_80015F04(s32 a0, s32 a1, s32 a2, s32 a3, u8 arg4, u8 arg5, u8 arg6, u16 arg7, u16 arg8);
extern void func_8013AA24(s32 a0, s32 a1);
void func_8013AA24(s32 a0, s32 a1);

void func_8013A530(int param_1)
{
    int iVar11;
    u16 uVar2;
    int sVar2;
    register u8 bVar1 __asm__("$8");
    int deadlocal[2];
    iVar11 = *(int *)(param_1 + 4);
    uVar2 = *(u16 *)(iVar11 + 0x18);
    sVar2 = uVar2;
    bVar1 = *(u8 *)(iVar11 + 0x22);
    if (uVar2 != 0 && uVar2 < 7) {
        if (uVar2 != 1) {
            if (sVar2 != 0 && sVar2 < 7) {
                register u32 f34 __asm__("$5");
                u32 uVar2b;
                u32 uVar6;
                short sVar5;
                int fc;
                register int zr __asm__("$0");
                int iVar7;
                f34 = *(u16 *)(iVar11 + 0x34);
                uVar6 = f34 + 0x10;
                uVar2b = *(u16 *)(iVar11 + 0x36) + 0x10;
                if (*(u8 *)(iVar11 + 0x20) != 0) {
                    uVar6 = f34 + 0x38;
                }
                sVar5 = (short)((int)((int)*(s16 *)(iVar11 + 0x28) * (uVar6 & 0xffff)) / 0x9a);
                *(s16 *)(param_1 + 8) = sVar5;
                if ((bVar1 & 8) == 0) {
                    *(s16 *)(param_1 + 8) = -sVar5;
                }
                if ((bVar1 & 0x60) == 0 || (bVar1 & 0x80) != 0) {
                    *(s16 *)(param_1 + 8) = -*(s16 *)(param_1 + 8);
                }
                sVar5 = (short)((int)((int)*(s16 *)(iVar11 + 0x2a) * (uVar2b & 0xffff)) / 0x2a);
                *(s16 *)(param_1 + 0xa) = sVar5;
                if ((bVar1 & 0x10) != 0) {
                    *(s16 *)(param_1 + 0xa) = -sVar5;
                }
                __asm__("" :: "r"(bVar1));
                fc = *(s16 *)(param_1 + 0xc);
                iVar7 = fc + zr;
                if (fc < *(s16 *)(param_1 + 0xe)) {
                    int t = iVar7 + 0x400;
                    *(s16 *)(param_1 + 0xc) = (short)t;
                    if (((t << 16) >> 16) > (int)*(s16 *)(param_1 + 0xe)) {
                        *(s16 *)(param_1 + 0xc) = *(s16 *)(param_1 + 0xe);
                    }
                } else if (*(s16 *)(param_1 + 0xe) < fc) {
                    int t = iVar7 - 0x400;
                    __asm__("" :: "r"(iVar7), "r"(t));
                    *(s16 *)(param_1 + 0xc) = (short)t;
                    if (((t << 16) >> 16) < (int)*(s16 *)(param_1 + 0xe)) {
                        *(s16 *)(param_1 + 0xc) = *(s16 *)(param_1 + 0xe);
                    }
                }
                __asm__("" :: "r"(fc));
                func_8013AA24(iVar11, param_1);
            }
        } else {
            int iVar7, iVar8;
            u32 uVar6, uVar4;
            memcpy((void *)(param_1 + 8), (void *)(iVar11 + 0x28), 4);
            uVar6 = ((*(s16 *)(iVar11 + 0x34) + 0x10) * (int)*(s16 *)(param_1 + 8)) >> 0xc;
            uVar4 = ((*(s16 *)(iVar11 + 0x36) + 0x10) * (int)*(s16 *)(param_1 + 0xa)) >> 0xc;
            iVar7 = *(u16 *)(iVar11 + 0x24) - ((uVar6 & 0xffff) >> 1);
            iVar8 = *(u16 *)(iVar11 + 0x26) - ((uVar4 & 0xffff) >> 1);
            func_80015F04((int)(s16)iVar7, (int)(s16)iVar8, (int)(s16)uVar6, (int)(s16)uVar4,
                          0xb3, 0x99, 0x4c, *(u16 *)(iVar11 + 0x1a), 4);
            func_80015F04((int)(s16)(iVar7 + 1), (int)(s16)(iVar8 + 1),
                          (int)(s16)(uVar6 - 2), (int)(s16)(uVar4 - 2),
                          0xe6, 0xcc, 0x73, *(u16 *)(iVar11 + 0x1a), 4);
            func_80015D4C((int)(s16)iVar7, (int)(s16)iVar8, (int)(s16)uVar6, (int)(s16)uVar4,
                          0xff, 0xe6, 0x99, *(u16 *)(iVar11 + 0x1a), 4);
        }
    }
    return;
}
