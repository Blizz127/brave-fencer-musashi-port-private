/* sc03_0001: func_8018069C from Druthulu/BFM-decomp
 * src/ov_SC03_001/ov_SC03_001_jr_8017AE2C.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0001 retail words (gcc-2.7.2 -O2). */
typedef int s32;
extern void func_8012A568(void (*a0)(void));
void func_801805EC(void *a0);
s32 func_80180634(void);
extern s32 func_80180634(void);
extern void func_801805EC(void *a0);

void func_8018069C(void *a0) {
        s32 s0;
        s0 = 1;
        *(s32 *)(*(s32 *)((char *)a0 + 0xCC) + 0xB0) = s0;
        if (func_80180634() != s0) {
            return;
        }
        func_801805EC(a0);
    }
