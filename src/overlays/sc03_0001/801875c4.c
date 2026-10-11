/* sc03_0001: func_801875C4 from Druthulu/BFM-decomp
 * src/ov_SC03_001/ov_SC03_001_jr_801870B0.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0001 retail words (gcc-2.7.2 -O2). */
typedef int s32;
extern short D_800BA2BA;

s32 func_801875C4(s32 arg0) {
        return *(short *)((char *)&D_800BA2BA + (*(short *)(*(s32 *)(arg0 + 0xd0) + 0x10) << 2));
    }
