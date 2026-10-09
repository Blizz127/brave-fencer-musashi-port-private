/* SC02.CD member35: func_801722CC from Druthulu/BFM-decomp
 * src/ov_SC02_035/ov_SC02_035_jr_80171B4C.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc02_0035 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef short s16;
typedef int s32;
extern s32 func_80172664(s32 *a0);
extern void func_8012A568(void (*a0)(void));
extern s32 func_80172664(s32 *a0);
s32 func_80172664(s32 *a0);

void func_801722CC(s32 *a0) {
    if (func_80172664(a0) == 0) {
        *(s16 *)((u8 *)a0 + 0xAC) = 0x40;
        *(s16 *)((u8 *)a0 + 0xAA) = 0x40;
    }
}
