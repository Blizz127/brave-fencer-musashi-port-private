/* sc03_0001: func_80180410 from Druthulu/BFM-decomp
 * src/ov_SC03_001/ov_SC03_001_jr_8017AE2C.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0001 retail words (gcc-2.7.2 -O2). */
typedef short s16;
typedef int s32;
extern void func_8012A568(void (*a0)(void));
extern void func_8012E8E0(s32 a0, s32 a1);
extern void func_8012C1B8(void);
extern void func_8012CAE4(void *a0);
extern void func_8012C1B8(void);
extern void func_8012CAE4(void *a0);
extern void func_8001C214(s32, s32);
extern void func_8012C1B8(void);
extern void func_8012CAE4(void *a0);
extern void func_8001C214(s32, s32);
extern void func_8001C214(s32, s32);
extern void func_8012C1B8(void);
extern void func_8012CAE4(void *a0);
extern void func_8012E8E0(s32 a0, s32 a1);
extern void func_8012CAE4(void *a0);
extern void func_8012C1B8(void);
extern void func_8012CAE4(void *a0);
extern void func_8001C214(s32 a0, s32 a1);
extern void func_8001D0E8(s32 a0, s32 a1, s32 a2);
extern void func_8012E8E0(s32 a0, s32 a1);
extern s32 D_801BECE0[];
extern s32 D_80191938[];

void func_80180410(s32 a0) {
        s32 v0;
        v0 = ((s32 (*)(void))func_8012C1B8)();
        *(s32 *)(a0 + 0x20) = v0;
        if (v0 == 0) {
            func_8012CAE4((void *)a0);
            return;
        }
        func_8001C214(v0, (s32)D_801BECE0);
        func_8001D0E8(*(s32 *)(a0 + 0x20), 0x7FFF, 0x7FFF);
        func_8012E8E0(a0, (s32)D_80191938);
        *(s16 *)(a0 + 0x2) = 1;
    }
