/* SC02.CD member35: func_80182404 from Druthulu/BFM-decomp
 * src/ov_SC02_035/ov_SC02_035_jr_8017BEBC.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc02_0035 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef int s32;
typedef struct {
    u8 f0, f1, f2, f3;
    struct { s16 a, b, c, d, e, g; } ent[16];
} Blk_8016CF04;
typedef struct {
    u8 f0, f1, f2, f3;
    struct { s16 a, b, c, d, e, g; } ent[16];
} Blk_8016CF04_8016CF04;
typedef struct {
    s32 op;
    union {
        s32 w;
        void *p;
        s16 h[2];
        u16 uh[2];
    } a;
} Cmd_80178D40;
extern s32 *D_80126B78;
extern void func_8012F14C(s32 a0, s32 a1, s32 a2);
extern s32 func_80135888(s32 a0, s32 a1, s32 a2, s32 a3);
extern u8 D_801152A8[];
extern u8 D_801152A8[];
extern s32 func_80153BD8(s32 a0);
extern s32 func_80153BF0(s32 a0);
extern void func_8012A568(void (*a0)(void));
extern s32 func_8012C658(s32 arg0, s32 arg1, s32 arg2);
extern void func_8012B2CC(s32 a0);
extern void func_8012F14C(s32 a0, s32 a1, s32 a2);
extern s32 func_80135888(s32 a0, s32 a1, s32 a2, s32 a3);
extern s32 func_8012C658(s32 arg0, s32 arg1, s32 arg2);
extern s32 func_8012C658(s32 arg0, s32 arg1, s32 arg2);
extern void func_8012B2CC(s32 a0);
extern void func_8002A04C(s32 a0);
extern void func_8012B2CC(s32 a0);
extern void func_8018016C(s32 a0, s32 a1);
extern void func_8012B2CC(s32 a0);
extern void func_8012C098(void *param_1);
extern void func_8012F14C(s32 a0, s32 a1, s32 a2);
extern s32 func_80135888(s32 a0, s32 a1, s32 a2, s32 a3);
extern void func_8012F568(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4, s32 a5);
extern u8 D_801152A8[];
extern s32 D_80198E04;
extern s32 *D_80126B78;
extern s32 func_80182318_def(s32 a0, s32 a1) __asm__("func_8018016C");
s32 func_80182318_def(s32 a0, s32 a1)
{
    s32 *m;
    s32 b1[2];
    s32 b2[2];
    m = &D_80198E04;
    func_8012F14C((s32)D_80126B78 + 0x34, (s32)m, (s32)b1);
    func_8012F14C((s32)D_80126B78 + 0x34, (s32)(m + 2), (s32)b2);
    if (func_80135888(*(s32 *)(a0 + 0x20), *(s32 *)(a0 + 0x58), (s32)b1, (s32)b2) == 0) {
        return 0;
    }
    func_8012F568(1,
                  (*(u16 *)(a0 + 0x70) & 0xF) != 0 ? 0x2001 : 1,
                  *(s16 *)(*(s32 *)(a0 + 0x20) + 0x12),
                  a1,
                  (s32)b2,
                  (s32)D_801152A8);
    return 1;
}
extern s32 func_8012C658(s32 arg0, s32 arg1, s32 arg2);
extern void func_8012B2CC(s32 a0);
extern s32 func_8012C658(s32 arg0, s32 arg1, s32 arg2);
extern void func_8002A04C(s32 a0);
extern void func_8012B2CC(s32 a0);
extern s32 func_8012C658(s32 arg0, s32 arg1, s32 arg2);
extern s32 func_80153BD8(s32 a0);
extern s32 func_80153BF0(s32 a0);
extern void func_8012C098(void *param_1);

void func_80182404(s32 a0) {
    s32 ent;
    if (*(u16 *)a0 != 0) {
        if (*(s16 *)(a0 + 0x70) == 4) {
            ent = func_8012C658(0x12C, 4, a0);
            if (ent != 0) {
                *(u16 *)(ent + 0x6) = *(u16 *)(a0 + 0x88);
                *(u16 *)(ent + 0x88) = *(u16 *)(a0 + 0x88);
                *(u16 *)(ent + 0xE) = *(u16 *)(a0 + 0x8C);
                *(u16 *)(ent + 0x8C) = *(u16 *)(a0 + 0x8C);
                *(u16 *)(ent + 0xA) = *(u16 *)(a0 + 0x8A) - 0x400;
                *(u16 *)(ent + 0x8A) = *(u16 *)(a0 + 0x8A);
                func_8012B2CC(ent);
            }
        }
        if (func_80153BD8(a0)) {
            func_80153BF0(a0);
        }
        if (*(s32 *)(a0 + 0x78) != 0) {
            func_8002A04C(a0);
        }
        func_8012C098((void *)a0);
    }
}
