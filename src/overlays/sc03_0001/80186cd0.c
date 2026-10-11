/* sc03_0001: func_80186CD0 from Druthulu/BFM-decomp
 * src/ov_SC03_001/ov_SC03_001_jr_8018631C.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0001 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned int u32;
typedef int s32;
extern u8 D_80078EAE;

s32 func_80186CD0(s32 arg0) {
    if ((u32)(arg0 - 900) < 110u) {
        return 0x65;
    }
    if ((u32)(arg0 - 100) < 30u) {
        return 0x28;
    }
    if (D_80078EAE == 1) {
        return 0xF;
    }
    return 0x10;
}
