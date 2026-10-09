/* SC02.CD member35: func_80177784 from Druthulu/BFM-decomp
 * src/ov_SC02_035/ov_SC02_035_jr_801734BC.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc02_0035 retail words (gcc-2.7.2 -O2). */
typedef unsigned int u32;
typedef int s32;
extern void func_8012A568(void (*a0)(void));

void *func_80177784(void *a0, s32 a1, s32 a2, s32 a3) {
    *(u32 *)((s32)a0 + 0x0) = (((s32)a0 - 0x14) & 0xFFFFFF) | 0x3000000;
    *(u32 *)((s32)a0 + 0x4) = 0x74808080;
    *(s32 *)((s32)a0 + 0x8) = a1;
    *(s32 *)((s32)a0 + 0xC) = a2;
    return (void *)((s32)a0 + 0x14);
}
