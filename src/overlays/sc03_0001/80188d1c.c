/* sc03_0001: func_80188D1C from Druthulu/BFM-decomp
 * src/ov_SC03_001/ov_SC03_001_jr_80188830.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0001 retail words (gcc-2.7.2 -O2). */
typedef unsigned short u16;
typedef int s32;
extern void func_8012A568(void (*a0)(void));
extern s32 func_80188D68(void *a0);
extern s32 func_80188D68(void *a0);
s32 func_80188D68(void *a0);

s32 func_80188D1C(void *a0) {
    a0 = *(void **)((char *)a0 + 0xCC);
    if (a0 == 0) {
        return 0;
    }
    if (*(u16 *)a0 != 0x61) {
        return 0;
    }
    return func_80188D68(a0);
}
