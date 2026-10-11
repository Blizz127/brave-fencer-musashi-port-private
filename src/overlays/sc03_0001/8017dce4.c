/* sc03_0001: func_8017DCE4 from Druthulu/BFM-decomp
 * src/ov_SC03_001/ov_SC03_001_jr_8017AE2C.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0001 retail words (gcc-2.7.2 -O2). */
typedef unsigned short u16;
typedef short s16;
typedef int s32;
extern void func_8012A568(void (*a0)(void));
extern s32 func_8012B608(s32 a0, s32 a1, s32 a2);
extern s32 func_8012B744(void *a0, void *a1);
extern s32 func_8012B744(void *a0, void *a1);
extern s32 func_8012CBCC(s32 a0);
extern s32 func_8012E544(s32 a0);
extern void func_8012B1B4(s32 a0, s32 a1);
extern void func_8012B1B4(s32 a0, s32 a1);
extern s32 func_8012B608(s32 a0, s32 a1, s32 a2);
extern s32 func_8012B744(void *a0, void *a1);
extern s32 func_8012CBCC(s32 a0);
extern s32 func_8012E544(s32 a0);
extern s16 D_80191020;
extern void func_8012B1B4(s32 a0, s32 a1);
extern s32 func_8012CBCC(s32 a0);
extern void func_8012C218(void *a0);
extern s32 func_8012E544(s32 a0);
extern void func_8012C218(void *a0);
extern void func_8012B1B4(s32 a0, s32 a1);
extern s32 func_8012CBCC(s32 a0);
extern s32 func_8012B744(void *a0, void *a1);
extern s32 func_8012B608(s32 a0, s32 a1, s32 a2);
extern s16 D_80191020;
typedef struct { s16 vx, vy, vz, pad; } TmpVec_8017DCE4;

void func_8017DCE4(s32 a0)
{
    register s32 pv __asm__("$16") = a0;
    s32 s1;
    s32 flags;
    TmpVec_8017DCE4 tmp;
    s32 v0;
    s1 = func_8012E544(0xAD);
    if (s1 == 0) {
        func_8012C218((void *)pv);
        return;
    }
    func_8012B1B4(pv, (s32)&D_80191020);
    flags = func_8012CBCC(pv);
    if (flags & 0x6000) {
        *(s16 *)(pv + 0x16) = -6;
    }
    if (flags & 0x8000) {
        *(s32 *)(pv + 4) += *(s32 *)(pv + 0x10);
        *(s32 *)(pv + 8) += *(s32 *)(pv + 0x14);
        *(s32 *)(pv + 0xC) += *(s32 *)(pv + 0x18);
    }
    tmp.vx = *(u16 *)(s1 + 6) + 0x20;
    tmp.vz = *(u16 *)(s1 + 0xE) + 0x20;
    v0 = func_8012B744((void *)(pv + 4), &tmp);
    {
        s32 r = func_8012B608(*(s16 *)(*(s32 *)(pv + 0x20) + 0x12), v0, 4);
        *(u16 *)(*(s32 *)(pv + 0x20) + 0x12) =
            *(u16 *)(*(s32 *)(pv + 0x20) + 0x12) + r;
    }
}
