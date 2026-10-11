/* sc03_0001: func_80185DC8 from Druthulu/BFM-decomp
 * src/ov_SC03_001/ov_SC03_001_jr_80184F64.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0001 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef int s32;
extern s32 func_8016F1AC(void);
void func_80185950(void *arg0);

void func_80185DC8(void *arg0)
{
    if (func_8016F1AC() == 0) {
        *(s32 *)(*(s32 *)((char *)arg0 + 0xCC) + 0xB0) = 2;
    }
    if (func_80187690(10, 0, 10, 30) || func_80187690(15, 0, 15, 30)) {
        *(u8 *)((char *)arg0 + 0x105) = *(u16 *)((char *)arg0 + 2);
        func_80185950(arg0);
    }
}
