/* SC02.CD member35: func_8017F874 from Druthulu/BFM-decomp
 * src/ov_SC02_035/ov_SC02_035_jr_8017BEBC.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc02_0035 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef short s16;
typedef int s32;
extern void func_8012A568(void (*a0)(void));
extern s32 func_8012B030(u8 *a0);
extern s32 func_8012B030(u8 *a0);

void func_8017F874(s32 arg0) {
        *(s32 *)(arg0 + 0x1c) = 1;
        *(s16 *)(arg0 + 0x2) = 0x4;
        ((s32 (*)(void *))func_8012B030)((void *)arg0);
    }
