/* sc03_0001: func_801814C4 from Druthulu/BFM-decomp
 * src/ov_SC03_001/ov_SC03_001_jr_8017AE2C.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0001 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef short s16;
typedef int s32;
extern void func_8012A568(void (*a0)(void));
extern void func_80187778(s32 *a0, s32 a1);
extern s32 func_8018766C(s32 arg0, s32 arg1);
extern void func_80187778(s32*, s32);
extern s32 func_8018766C(s32 arg0, s32 arg1);
extern s32 func_8018766C(s32 arg0, s32 arg1);
extern void func_80187778(s32*, s32);
extern void func_80187778(s32*, s32);
extern s32 func_8018766C(s32 arg0, s32 arg1);
extern s32 func_8018766C(s32 arg0, s32 arg1);
extern s32 func_8018766C(s32 arg0, s32 arg1);
extern s32 func_8018766C(s32 arg0, s32 arg1);
extern s32 func_8018766C(s32 arg0, s32 arg1);
extern s32 func_8018766C(s32 arg0, s32 arg1);
extern s32 func_8018766C(s32 arg0, s32 arg1);
extern s32 func_8018766C(s32 arg0, s32 arg1);
extern s32 func_8018766C(s32 arg0, s32 arg1);
extern s32 func_8018766C(s32 arg0, s32 arg1);
extern void func_80187778(s32*, s32);
extern short D_80191B3C;
extern void func_80187778(s32 *a0, s32 a1);
extern short D_80191B3C;
extern s32 func_8018766C(s32 arg0, s32 arg1);
extern s32 func_8018766C(s32 arg0, s32 arg1);
extern s32 func_8018766C(s32 arg0, s32 arg1);
extern short D_80191B3C;
extern void func_80187778(s32 *a0, s32 a1);

void func_801814C4(s32 *arg0) {
        s32 *s0 = arg0;
        s32 v0, v1;
        *(s32 *)((u8 *)(*(s32 **)((u8 *)s0 + 0xCC)) + 0xB0) = 2;
        v0 = func_8018766C(6, 0x12);
        if (v0 != 0) {
            v1 = 1;
        } else {
            v0 = func_8018766C(0x12, 0x15);
            v1 = (v0 != 0) ? 2 : 0;
        }
        if (v1 != 2) {
            *(s16 *)((u8 *)s0 + 2) = 1;
            func_80187778(s0, (s32)&D_80191B3C);
        }
    }
