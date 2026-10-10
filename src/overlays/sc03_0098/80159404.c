/* sc03_0098: func_80159404 from Druthulu/BFM-decomp
 * src/ov_SC03_098/ov_SC03_098_jr_801588CC.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0098 retail words (gcc-2.7.2 -O2). */
typedef unsigned short u16;
typedef int s32;

s32 func_80159404(s32 a0, s32 a1) {
    s32 a2 = *(s32 *)((s32)a0 + 0x20);
    u16 v1 = *(u16 *)((s32)a0 + 0x236);
    u16 v0 = *(u16 *)((s32)a2 + 0x12);
    *(u16 *)((s32)a2 + 0x12) = (v0 + v1) & 0xFFF;
    return (*(s32 *)((s32)a0 + 0x234) -= a1);
}
