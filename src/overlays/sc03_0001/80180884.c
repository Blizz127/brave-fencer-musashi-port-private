/* sc03_0001: func_80180884 from Druthulu/BFM-decomp
 * src/ov_SC03_001/ov_SC03_001_jr_8017AE2C.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0001 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned int u32;
typedef short s16;
typedef int s32;
extern u8 D_80078EBA;
extern void func_8012A568(void (*a0)(void));
extern s32 func_8018766C(s32 arg0, s32 arg1);
extern s32 func_8018766C(s32 arg0, s32 arg1);
extern s32 func_8018766C(s32 arg0, s32 arg1);
extern s32 func_8018766C(s32 arg0, s32 arg1);
extern s32 func_8018766C(s32 arg0, s32 arg1);
extern u8 D_80078EBA;
extern s32 func_8012E57C(s32 a0, s32 a1);
extern s32 func_8018766C(s32 arg0, s32 arg1);
extern u8 D_80078EBA;
extern s32 func_8018766C(s32 arg0, s32 arg1);
extern u8 D_80078EBA;
extern s32 func_8012E57C(s32 a0, s32 a1);
extern s32 func_8018766C(s32 arg0, s32 arg1);
extern u8 D_80078EBA;

void func_80180884(void *a0) {
        s32 v0;
        v0 = func_8012E57C(0x61, 0x8);
        *(s32 *)((char *)a0 + 0xCC) = v0;
        if (D_80078EBA == 3) {
            v0 = 0;
        } else {
            v0 = func_8018766C(0x7, 0x13);
            v0 = (0U < (u32)v0) ? 1 : 0;
        }
        if (v0 != 0) {
            v0 = 1;
        } else {
            v0 = 2;
        }
        *(s16 *)((char *)a0 + 0x2) = v0;
    }
