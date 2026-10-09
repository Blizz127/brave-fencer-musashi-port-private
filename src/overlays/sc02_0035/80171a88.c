/* SC02.CD member35: func_80171A88 from Druthulu/BFM-decomp
 * src/ov_SC02_035/ov_SC02_035_jr_8016AB6C.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc02_0035 retail words (gcc-2.7.2 -O2). */
typedef unsigned int u32;
typedef int s32;
extern void func_8012A568(void (*a0)(void));

s32 func_80171A88(s32 a0) {
    s32 v0;
    v0 = *(s32*)(a0 + 0x200);
    if (!v0) goto ret1;
    *(s32*)(a0 + 0x200) = v0 - 1;
    return (u32)(v0 - 1) < 1;
ret1:
    return 1;
}
