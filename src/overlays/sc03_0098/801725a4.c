/* sc03_0098: func_801725A4 from Druthulu/BFM-decomp
 * src/ov_SC03_098/ov_SC03_098_jr_80171B4C.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0098 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned int u32;
typedef int s32;
extern void func_8012A568(void (*a0)(void));

s32 func_801725A4(u8 *a0) {
    s32 v0 = *(u32 *)((s32)a0 + 0x1F4) | 0x2;
    *(u32 *)((s32)a0 + 0x1F4) = v0;
    return v0;
}
