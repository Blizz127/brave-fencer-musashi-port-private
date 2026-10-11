/* sc03_0001: func_8017EEE4 from Druthulu/BFM-decomp
 * src/ov_SC03_001/ov_SC03_001_jr_8017AE2C.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0001 retail words (gcc-2.7.2 -O2). */
typedef int s32;
extern void func_80178CBC(s32*, s32);
extern short D_80191438;

void func_8017EEE4(void * arg0) {
        *(short *)((char *)arg0 + 0x2) = 4;
        ((void (*)(s32, s32))func_80178CBC)((int)arg0, (int)&D_80191438);
    }
