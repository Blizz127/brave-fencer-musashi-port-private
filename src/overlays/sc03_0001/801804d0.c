/* sc03_0001: func_801804D0 from Druthulu/BFM-decomp
 * src/ov_SC03_001/ov_SC03_001_jr_8017AE2C.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0001 retail words (gcc-2.7.2 -O2). */
typedef unsigned int u32;
typedef short s16;
typedef int s32;
extern s32 func_80029504(void);
extern void func_8001C810(s32 a0, s32 a1);
extern void func_8012A568(void (*a0)(void));
extern void func_8012E8E0(s32 a0, s32 a1);
extern void func_8012C1B8(void);
extern void func_8012CAE4(void *a0);
extern void func_8001C810(s32 a0, s32 a1);
extern void func_8012C1B8(void);
extern void func_8012CAE4(void *a0);
extern s32 func_80029504(void);
extern void func_8012C1B8(void);
extern void func_8012CAE4(void *a0);
extern s32 func_80029504(void);
extern s32 func_80029504(void);
extern s32 func_80029504(void);
extern s32 func_80029504(void);
extern s32 func_80029504(void);
extern void func_8012C1B8(void);
extern void func_8012CAE4(void *a0);
extern void func_8012E8E0(s32 a0, s32 a1);
extern void func_8012CAE4(void *a0);
extern void func_8012C1B8(void);
extern void func_8012CAE4(void *a0);
extern void func_8001D0E8(s32 a0, s32 a1, s32 a2);
extern void func_8012E8E0(s32 a0, s32 a1);
extern s32 func_80029504(void);
extern void func_8012C1B8(void);
extern void func_8012CAE4(void *a0);
extern void func_8001C810(s32 a0, s32 a1);
extern void func_8001D0E8(s32 a0, s32 a1, s32 a2);
extern void func_8012E8E0(s32 a0, s32 a1);
extern s32 D_801BE978[];
extern s32 D_80191948[];

void func_801804D0(s32 a0) {
    s32 v0;
    if ((u32)(func_80029504() - 0x181) < 0x55) {
        func_8012CAE4((void *)a0);
        return;
    }
    *(s32 *)(a0 + 0x20) = v0 = ((s32 (*)(void))func_8012C1B8)();
    if (v0 == 0) {
        func_8012CAE4((void *)a0);
        return;
    }
    func_8001C810(v0, (s32)D_801BE978);
    *(s32 *)(*(s32 *)(a0 + 0x20) + 4) |= 0x8000;
    func_8001D0E8(*(s32 *)(a0 + 0x20), 0x7FFF, 0x7FFF);
    func_8012E8E0(a0, (s32)D_80191948);
    *(s16 *)(a0 + 0x2) = 1;
    return;
}
