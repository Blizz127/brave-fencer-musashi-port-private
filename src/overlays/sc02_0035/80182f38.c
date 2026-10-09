/* SC02.CD member35: func_80182F38 from Druthulu/BFM-decomp
 * src/ov_SC02_035/ov_SC02_035_jr_8017BEBC.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc02_0035 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef int s32;
extern void func_8012A568(void (*a0)(void));
extern s32 func_80047948(s32 a0);
extern s32 func_8004787C(s32 a0);
extern void func_8012B2CC(s32 a0);
extern s32 func_80047948(s32 a0);
extern s32 func_8004787C(s32 a0);
extern s32 func_80047948(s32 a0);
extern s32 func_8004787C(s32 a0);
extern s32 func_80047948(s32 a0);
extern s32 func_80047948(s32 a0);
extern s32 func_8004787C(s32 a0);
extern s32 func_80047948(s32 a0);
extern s32 func_8004787C(s32 a0);
extern void func_8012A828(s32*, s32);
extern void func_8012A828(s32*, s32);
extern void func_8012B2CC(s32 a0);
extern void func_8012B23C(void *a0);
extern void func_8012A828(s32*, s32);
extern void func_8012C1B8(void);
extern void func_8012CAE4(void *a0);
extern void func_8001CA1C(s32 a0, s32 a1);
extern void func_8012A828(s32*, s32);
extern s32 func_8004787C(s32 a0);
extern s32 func_8004787C(s32 a0);
extern void func_8012CAE4(void *a0);
extern void func_8012B2CC(s32 a0);
extern void func_8012B23C(void *a0);
extern s32 func_8004787C(s32 a0);
extern void func_8018016C(s32 a0, s32 a1);
extern s32 func_8004787C(s32 a0);
extern s32 func_8004787C(s32 a0);
extern void func_8012B23C(void *a0);
extern s32 func_80047948(s32 a0);
extern void func_8012B23C(void *a0);
extern void func_8012B2CC(s32 a0);
extern s32 func_80182318_def(s32 a0, s32 a1) __asm__("func_8018016C");
s32 func_80182318_def(s32 a0, s32 a1);
extern void func_8012A828(s32*, s32);
extern void func_8012CAE4(void *a0);
extern void func_8012A828(s32*, s32);
extern void func_8012B23C(void *a0);
extern void func_8012B2CC(s32 a0);
extern void func_8012A828(s32*, s32);
extern s32 func_8004787C(s32 a0);
extern s32 func_80047948(s32 a0);
extern s32 func_8004787C(s32 a0);
extern s32 func_80047948(s32 a0);
extern void func_8012A828(s32*, s32);
extern s32 func_8004787C(s32 a0);
extern s32 func_80047948(s32 a0);
extern void func_8012A828(s32*, s32);
extern void func_8012A828(s32*, s32);
extern void func_8012A828(s32*, s32);
extern void func_8012B2CC(s32 a0);
extern void func_8012B23C(void *a0);
extern void func_8012B14C(s32 a0, s32 a1);
extern void func_8012A828(s32*, s32);
extern void func_8012A828(s32*, s32);
extern void func_8012A828(s32*, s32);
extern void func_8012A828(s32*, s32);
extern void func_8012A828(s32*, s32);
extern void func_8012A828(s32*, s32);
extern void func_8012A828(s32*, s32);
extern void func_8012A828(s32*, s32);
extern void func_8012A828(s32*, s32);
extern void func_8012C1B8(void);
extern void func_8012CAE4(void *a0);
extern void func_8001CA1C(s32 a0, s32 a1);
extern void func_8012A828(s32*, s32);
extern void func_8012B23C(void *a0);
extern void func_8012B2CC(s32 a0);
extern void func_8012B14C(s32 a0, s32 a1);
extern s32 func_8004787C(s32 a0);
extern s32 func_80047948(s32 a0);

void func_80182F38(s32 param_1)
{
    extern u8 D_8019C4F8[];
    extern u8 D_8019C510[];
    extern u8 D_8019C528[];
    s32 v0;
    v0 = ((s32 (*)(void))func_8012C1B8)();
    *(s32 *)(param_1 + 0x20) = v0;
    if (v0 == 0) {
        ((void (*)(s32))func_8012CAE4)(param_1);
    } else {
        func_8001CA1C(v0, (s32)D_8019C4F8);
        ((void (*)(s32, s32))func_8012A828)(param_1, (s32)D_8019C510);
        *(s16 *)(*(s32 *)(param_1 + 0x20) + 0x12) =
            *(u16 *)(*(s32 *)(*(s32 *)(param_1 + 0x64) + 0x20) + 0x12);
        func_8012B23C((void *)param_1);
        func_8012B2CC(param_1);
        func_8012B14C(param_1, (s32)D_8019C528);
        *(s16 *)(param_1 + 2) = 1;
        *(s16 *)(param_1 + 0xA) = *(u16 *)(param_1 + 0xA) - 0x90;
        *(s16 *)(param_1 + 6) =
            *(u16 *)(param_1 + 6) -
            (func_8004787C(*(s16 *)(*(s32 *)(param_1 + 0x20) + 0x12)) >> 8);
        *(s16 *)(param_1 + 0xE) =
            *(u16 *)(param_1 + 0xE) -
            (func_80047948(*(s16 *)(*(s32 *)(param_1 + 0x20) + 0x12)) >> 8);
    }
}
