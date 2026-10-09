/* SC02.CD member35: func_80172894 from Druthulu/BFM-decomp
 * src/ov_SC02_035/ov_SC02_035_jr_80171B4C.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc02_0035 retail words (gcc-2.7.2 -O2). */
typedef short s16;
typedef int s32;
struct S8_80172894;
struct S8_80172894 { s16 m[4]; };
extern void func_8012A568(void (*a0)(void));
extern void func_80174684(void *);
extern void func_80174684(void *);
extern s16 D_80126B30;
extern void func_80174684(void *);
extern s16 D_80126B30;
extern s32 func_801728E4();
s32 func_801728E4(void *a0);

void func_80172894(void *a0) {
    *(struct S8_80172894 *)&D_80126B30 = *(struct S8_80172894 *)a0;
    func_80174684((void *)func_801728E4);
}
