/* sc03_0001: func_801554B8 from Druthulu/BFM-decomp
 * src/ov_SC03_001/ov_SC03_001_jr_80154C24.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0001 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef signed char s8;
typedef int s32;
extern s32 func_801659DC();

s32 func_801554B8(void *arg0) {
    s32 var_v0;
    u8 temp_a0;
    temp_a0 = (*(u8 *)((s8 *)(arg0) + (0x1A0)));
    var_v0 = 0;
    if (temp_a0 != (*(u8 *)((s8 *)(arg0) + (0x196)))) {
        if (func_800D02D0(temp_a0) != 0) {
            (*(u8 *)((s8 *)(arg0) + (0x196))) = (u8) (*(u8 *)((s8 *)(arg0) + (0x1A0)));
            func_801659DC(arg0);
            return 0;
        }
        var_v0 = 1;
        return var_v0;
    }
    return var_v0;
}
