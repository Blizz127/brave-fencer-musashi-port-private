/* sc03_0001: func_80138C30 from Druthulu/BFM-decomp
 * src/ov_SC03_001/ov_SC03_001_jr_801380E0.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0001 retail words (gcc-2.7.2 -O2). */
typedef unsigned int u32;
typedef short s16;
typedef int s32;
extern void func_8012A568(void (*a0)(void));
extern void func_8012A5F8(void (*a0)(void), s32 a1);

void func_80138C30(void *a0) {
    if (*(s16 *)((s32)a0 + 4) == 4) {
        *(s16 *)((s32)a0 + 4) = 2;
    } else {
        *(u32 *)((s32)a0 + 8) |= 0x800;
    }
}
