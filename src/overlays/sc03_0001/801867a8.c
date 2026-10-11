/* sc03_0001: func_801867A8 from Druthulu/BFM-decomp
 * src/ov_SC03_001/ov_SC03_001_jr_8018631C.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0001 retail words (gcc-2.7.2 -O2). */
typedef short s16;
typedef int s32;
extern void func_8012A568(void (*a0)(void));
extern s32 func_801788B8(s32 arg0, s32 arg1);
extern void func_80187778(s32 *a0, s32 a1);
extern s32 func_8018766C(s32 arg0, s32 arg1);
extern void func_80187778(s32*, s32);
extern s32 func_8018766C(s32 a0, s32 a1);
extern s32 func_8018727C(void *a0, void *a1);
extern s32 func_801788B8(s32 a0, s32 a1);
extern s32 func_8018766C(s32 arg0, s32 arg1);
extern s32 func_8018766C(s32 arg0, s32 arg1);
extern void func_80187778(s32 *a0, s32 a1);
extern void func_80187778(s32*, s32);
extern s32 func_8018727C(void *a0, void *a1);
extern s32 func_8018766C(s32 arg0, s32 arg1);
extern void func_80187778(s32 *a0, s32 a1);
extern s32 func_801788B8(s32 a0, s32 a1);
extern void func_80187778(s32 *a0, s32 a1);
extern short D_801929E8;
extern s32 func_8018766C(s32 arg0, s32 arg1);
extern s32 func_8018766C(s32 a0, s32 a1);
extern void func_80187778(s32*, s32);
extern short D_801929E8;
extern void func_80187778(s32*, s32);

void func_801867A8(void *a0) {
    extern short D_801929E8;
    extern short D_801929F0;
    extern void func_80186828(void);
    if (func_8018727C(a0, &D_801929F0) != 0) {
        if (func_8018766C(11, 23) != 0) {
            *(s16 *)((char *)a0 + 2) = 1;
        } else {
            *(s16 *)((char *)a0 + 2) = 2;
        }
        func_80187778((s32 *)a0, (s32)&D_801929E8);
        *(s16 *)(*(s32 *)((char *)a0 + 0x68) + 0xC) = 0x7FFF;
        *(s32 *)((char *)a0 + 0xD4) = func_801788B8((s32)a0, (s32)func_80186828);
    }
}
