/* sc03_0001: func_80183D78 from Druthulu/BFM-decomp
 * src/ov_SC03_001/ov_SC03_001_jr_8017AE2C.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0001 retail words (gcc-2.7.2 -O2). */
typedef unsigned short u16;
typedef short s16;
typedef int s32;
extern void func_8012A568(void (*a0)(void));
extern void func_80187778(s32 *a0, s32 a1);
extern void func_80187778(s32*, s32);
extern void func_80187778(s32*, s32);
extern void func_80187778(s32*, s32);
extern void func_80187994(s32, s32, s32, s32);
extern void func_80187994(s32 a0, s32 a1, s32 a2, s32 a3);
extern void func_80187994(s32 a0, s32 a1, s32 a2, s32 a3);
extern s32 func_80187A64(s32 a0);
extern s32 func_801886A0(s32 arg0);
extern s32 func_80187A64(s32 a0);
extern void func_80187994(s32 a0, s32 a1, s32 a2, s32 a3);
extern s32 func_801886A0(s32 arg0);
extern s32 func_80187A64(s32 a0);
extern void func_80187778(s32*, s32);
extern void func_80187778(s32 *a0, s32 a1);
extern void func_80187778(s32 *a0, s32 a1);
extern void func_80187778(s32*, s32);
extern void func_80187778(s32 *a0, s32 a1);
extern void func_80187778(s32 *a0, s32 a1);
extern void func_80187994(s32, s32, s32, s32);
extern void func_80187778(s32 *a0, s32 a1);
extern void func_80187778(s32 *a0, s32 a1);
extern s32 func_801886A0(s32 a0);
extern s32 func_80187A64(s32 a0);
extern void func_80187994(s32, s32, s32, s32);
extern s32 func_80187A64(s32);
extern void func_80187994(s32, s32, s32, s32);
extern s32 func_801886A0(s32);
extern void func_80187778(s32 *a0, s32 a1);
extern void func_80187778(s32*, s32);
extern void func_80187994(s32 a0, s32 a1, s32 a2, s32 a3);
extern void func_80187994(s32, s32, s32, s32);
extern void func_80187778(s32 *a0, s32 a1);
extern void func_80187778(s32*, s32);
extern s32 func_80187A64(s32 a0);
extern s32 func_801886A0(s32 a0);
extern void func_80187778(s32*, s32);
extern void func_80187994(s32, s32, s32, s32);
extern s32 func_80187A64(s32 a0);
extern s32 func_801886A0(s32 arg0);
extern void func_80187994(s32, s32, s32, s32);
extern s32 func_80187A64(s32 a0);
extern void func_80187994(s32 a0, s32 a1, s32 a2, s32 a3);
extern s32 func_801886A0(s32 a0);
extern s32 func_80187A64(s32 a0);
extern s32 func_801886A0(s32 a0);
extern void func_80187994(s32, s32, s32, s32);
extern void func_80187778(s32 *a0, s32 a1);
extern void func_80187994(s32, s32, s32, s32);
extern void func_80187994(s32, s32, s32, s32);
extern void func_80187778(s32 *a0, s32 a1);
extern void func_80187778(s32 *a0, s32 a1);
extern s32 func_801886A0(s32 a0);
extern s32 func_80187A64(s32 a0);
extern void func_80187994(s32, s32, s32, s32);
extern s32 func_80187A64(s32 a0);
extern void func_80187994(s32 a0, s32 a1, s32 a2, s32 a3);
extern s32 func_801886A0(s32 a0);
extern void func_80187778(s32*, s32);
extern void func_80187778(s32*, s32);
extern void func_80187994(s32, s32, s32, s32);
extern void func_80187994(s32, s32, s32, s32);
extern s32 func_80187A64(s32 a0);
extern s32 func_801886A0(s32 arg0);
extern void func_80187994(s32, s32, s32, s32);
extern s32 func_80187A64(s32 a0);
extern s32 func_801886A0(s32 arg0);
extern short D_80192320;
extern short D_801B9434;
extern void func_80187778(s32*, s32);
extern void func_80187994(s32, s32, s32, s32);

void func_80183D78(s32 a0) {
    if (*(u16*)(a0 + 0x34) == 0) {
        if (func_80187A64(a0) != 0) {
            *(s16*)(a0 + 0x34) = 1;
            func_80187994(a0, (s32)&D_801B9434, 1, 0x60);
        }
    } else {
        if (func_801886A0(0x2) != 0) {
            if (func_80187A64(a0) != 0) {
                *(s16*)(a0 + 0x2) = 1;
                func_80187778((s32*)a0, (s32)&D_80192320);
            }
        }
    }
}
