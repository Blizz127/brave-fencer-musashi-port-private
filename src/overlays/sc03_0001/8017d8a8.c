/* sc03_0001: func_8017D8A8 from Druthulu/BFM-decomp
 * src/ov_SC03_001/ov_SC03_001_jr_8017AE2C.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0001 retail words (gcc-2.7.2 -O2). */
typedef unsigned short u16;
typedef short s16;
typedef int s32;
extern void func_8012A568(void (*a0)(void));
extern s32 func_8012B608(s32 a0, s32 a1, s32 a2);
extern s32 func_8012B744(void *a0, void *a1);
extern void func_8012A828(s32, s32);
s32 func_8017D5F0(s32 a0, s32 a1);
extern s32 func_8012B744(void *a0, void *a1);
extern void func_8012A828(s32 a0, s32 a1);
extern s32 func_8012CBCC(s32 a0);
extern s32 func_8012E544(s32 a0);
extern s32 func_8017D5F0(s32 a0, s32 a1);
extern void func_8012B1B4(s32 a0, s32 a1);
extern s16 D_80191010;
extern void func_8012B1B4(s32 a0, s32 a1);
extern s32 func_8012B608(s32 a0, s32 a1, s32 a2);
extern s32 func_8012B744(void *a0, void *a1);
extern void func_8012A828(s32 a0, s32 a1);
extern s32 func_8012CBCC(s32 a0);
extern s32 func_8012E544(s32 a0);
extern s32 func_8017D5F0(s32 a0, s32 a1);
extern s16 D_80191020;
extern s16 D_80191018;
extern s16 D_8019101C;
extern s16 D_80191010;
extern s16 D_801BE398;

void func_8017D8A8(s32 param_1) {
    s32 pv = param_1;
    s32 s0;
    s32 v0;
    s32 s2;
    func_8012B1B4(pv, (s32)&D_80191020);
    s0 = func_8012CBCC(pv);
    if (s0 & 0x6000) {
        *(s16 *)(pv + 0x16) = -4;
    }
    v0 = func_8012E544(0xAD);
    if (v0 != 0) {
        if (func_8017D5F0(pv, v0) != 0) {
            s0 |= 0x8000;
        }
    }
    if (s0 & 0x8000) {
        s16 cnt = (s16)(*(u16 *)(pv + 0x104) + 1) & 0x3F;
        *(u16 *)(pv + 0x104) = cnt;
        if (cnt < 0x1F) {
            *(u16 *)(*(s32 *)(pv + 0x20) + 0x12) += 0x200;
        } else {
            *(u16 *)(*(s32 *)(pv + 0x20) + 0x12) -= 0x200;
        }
    } else {
        *(u16 *)(pv + 0x104) = 0;
    }
    s2 = pv + 4;
    {
        s16 *p = &D_80191018;
        s32 t = (s32)func_8012B744((void *)s2, p);
        s32 r = func_8012B608(*(s16 *)(*(s32 *)(pv + 0x20) + 0x12), t, 4);
        *(u16 *)(*(s32 *)(pv + 0x20) + 0x12) =
            *(u16 *)(*(s32 *)(pv + 0x20) + 0x12) + r;
        {
            s32 dx = *(s16 *)(pv + 6) - *p;
            s32 dy = *(s16 *)(pv + 0xE) - D_8019101C;
            if (dx * dx + dy * dy < 0x400) {
                *(s16 *)(pv + 2) = 3;
                func_8012A828(pv, (s32)&D_801BE398);
                v0 = (s32)func_8012B744((void *)s2, &D_80191010);
                *(s16 *)(*(s32 *)(pv + 0x20) + 0x12) = (s16)v0;
            }
        }
    }
}
