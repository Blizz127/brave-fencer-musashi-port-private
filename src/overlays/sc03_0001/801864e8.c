/* sc03_0001: func_801864E8 from Druthulu/BFM-decomp
 * src/ov_SC03_001/ov_SC03_001_jr_8018631C.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0001 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
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
extern short D_80192970;
extern void func_80187778(s32*, s32);
extern s32 func_8018727C(void *a0, void *a1);
extern s32 func_8018766C(s32 arg0, s32 arg1);
extern void func_80187778(s32 *a0, s32 a1);
extern s32 func_801788B8(s32 a0, s32 a1);
extern s32 func_80186568(void *);
extern short D_80192970;
extern u8 D_80192978;
s32 func_80186568(void *a0);

void func_801864E8(void *a0) {
    s32 v0;
    void *v1;
    if (func_8018727C(a0, &D_80192978) != 0) {
        v0 = func_8018766C(8, 0x14);
        if (v0 != 0) {
            *(s16 *)((char *)a0 + 0x2) = 2;
        } else {
            *(s16 *)((char *)a0 + 0x2) = 1;
        }
        func_80187778((s32 *)a0, (s32)&D_80192970);
        v1 = *(void **)((char *)a0 + 0x68);
        *(s16 *)((char *)v1 + 0xC) = 0x7FFF;
        *(s32 *)((char *)a0 + 0xD4) = func_801788B8((s32)a0, (s32)&func_80186568);
    }
}
