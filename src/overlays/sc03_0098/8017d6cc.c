/* sc03_0098: func_8017D6CC from Druthulu/BFM-decomp
 * src/ov_SC03_098/ov_SC03_098_jr_8017AE2C.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0098 retail words (gcc-2.7.2 -O2). */
typedef int s32;
extern void func_80146C3C();
extern void func_800D22E4(s32 a0);
extern void func_80146C3C(void);
extern void func_8012A568(void (*a0)(void));
extern void func_80146C3C(void);
extern void func_80146C3C(void);
extern void func_800D22E4(s32 a0);
extern void func_80146C3C(void);
extern void func_8017D728(void *a0);
void func_8017D728(void *a0);

void func_8017D6CC(void *a0)
{
    s32 t;
    t = *(s32 *)((s32)a0 + 0x1C);
    *(s32 *)((s32)a0 + 0x1C) = t + 1;
    if (t < 0xA) {
        ((void (*)(void))func_800D22E4)();
        func_8017D728(a0);
    } else {
        ((void (*)(void *))func_80146C3C)(a0);
    }
}
