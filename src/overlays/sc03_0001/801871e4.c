/* sc03_0001: func_801871E4 from Druthulu/BFM-decomp
 * src/ov_SC03_001/ov_SC03_001_jr_801870B0.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0001 retail words (gcc-2.7.2 -O2). */
typedef unsigned short u16;
typedef int s32;
extern void func_8012A568(void (*a0)(void));
extern s32 func_8012BEE8(s32 a0);
extern s32 func_8012BEE8(s32 a0);
extern void func_80186DAC(void *a0);

void func_801871E4(void *a0) {
    u16 v1;
    v1 = *(u16 *)((char *)a0 + 0x34);
    if (v1 == 0) {
        return;
    }
    if (v1 != 1) {
        return;
    }
    {
        u16 *p = (u16 *)*(s32 *)((char *)a0 + 0x20);
        *(u16 *)((char *)p + 0x12) = *(u16 *)((char *)p + 0x12) + 0x20;
        if (((s32 (*)(void))func_8012BEE8)()) {
            func_80186DAC(a0);
        }
    }
}
