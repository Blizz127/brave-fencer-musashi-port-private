/* sc03_0001: func_8017F750 from Druthulu/BFM-decomp
 * src/ov_SC03_001/ov_SC03_001_jr_8017AE2C.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0001 retail words (gcc-2.7.2 -O2). */
typedef unsigned short u16;
typedef int s32;
extern void func_8012A568(void (*a0)(void));
extern s32 D_801EE950[];
extern s32 D_801EE968[];

void func_8017F750(void *a0, s32 a1) {
    s32 v1;
    s32 *a2;
    v1 = ((u16 *)a0)[3] >> 12;
    a2 = (s32 *)D_801EE950[v1];
    a2[1] &= 0x7FFFFFFF;
    D_801EE968[v1 * 16] = a1;
    ((u16 *)a2)[4] = ((u16 *)a0)[0];
    ((u16 *)a2)[5] = ((u16 *)a0)[1];
    ((u16 *)a2)[6] = ((u16 *)a0)[2];
    ((u16 *)a2)[9] = (((u16 *)a0)[3] & 0xF) << 10;
}
