/* SC02.CD member35: func_80183E04 from Druthulu/BFM-decomp
 * src/ov_SC02_035/ov_SC02_035_jr_8017BEBC.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc02_0035 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef int s32;
extern s32 *D_80126B78;
extern void func_8012F14C(s32 a0, s32 a1, s32 a2);
extern s32 func_80135888(s32 a0, s32 a1, s32 a2, s32 a3);
extern u8 D_801152A8[];
extern u8 D_801152A8[];
extern void func_8012A568(void (*a0)(void));
extern void func_8012F14C(s32 a0, s32 a1, s32 a2);
extern s32 func_80135888(s32 a0, s32 a1, s32 a2, s32 a3);
extern void func_8012A828(s32*, s32);
extern void func_8012A828(s32*, s32);
extern void func_8012A828(s32*, s32);
extern void func_8012A828(s32*, s32);
extern void func_8018016C(s32 a0, s32 a1);
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
extern void func_8012A828(s32*, s32);
extern void func_8012A828(s32*, s32);
extern void func_8012A828(s32*, s32);
extern void func_8012A828(s32*, s32);
extern void func_8012A828(s32*, s32);
extern void func_8012A828(s32*, s32);
extern void func_8012A828(s32*, s32);
extern void func_8012A828(s32*, s32);
extern void func_8012A828(s32*, s32);
extern void func_8012A828(s32*, s32);
extern void func_8012A828(s32*, s32);
extern void func_8012A828(s32*, s32);
extern void func_8012A828(s32*, s32);
extern void func_8012A828(s32*, s32);
extern void func_8012A828(s32*, s32);
extern void func_8012A828(s32*, s32);
extern void func_8012A828(s32*, s32);
extern void func_8012A828(s32*, s32);
extern void func_8012A828(s32 *a0, s32 a1);
extern s32 D_801BBC6C;
extern void func_8012A828(s32 *a0, s32 a1);
extern s32 D_801BBC6C;
extern void func_8012A828(s32 *a0, s32 a1);
extern s32 D_801BBC6C;

void func_80183E04(void *arg0) {
        *(s16 *)((char *)arg0 + 0x2) = 1;
        *(s16 *)((char *)arg0 + 0x5c) = *(u16 *)(*(s32 *)((char *)arg0 + 0x78) + 0x2);
        func_8012A828(arg0, &D_801BBC6C);
    }
