/* sc03_0001: func_8018098C from Druthulu/BFM-decomp
 * src/ov_SC03_001/ov_SC03_001_jr_8017AE2C.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0001 retail words (gcc-2.7.2 -O2). */
typedef int s32;
extern void func_8012A568(void (*a0)(void));
void func_801808F0(void *a0);
s32 func_80180938(void);
extern s32 func_80180938(void);
extern void func_801808F0(void*);

void func_8018098C(void *a0) {
    *(s32 *)(*(s32 *)((char *)a0 + 0xCC) + 0xB0) = 1;
    if (func_80180938() == 0) {
        ((void (*)(s32 *))func_801808F0)(a0);
    }
}
