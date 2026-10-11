/* sc03_0001: func_801807B8 from Druthulu/BFM-decomp
 * src/ov_SC03_001/ov_SC03_001_jr_8017AE2C.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0001 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef int s32;
extern u8 D_80078EBA;
extern void func_8012A568(void (*a0)(void));
extern s32 func_8018766C(s32 arg0, s32 arg1);
extern s32 func_8018766C(s32 arg0, s32 arg1);
extern s32 func_8018766C(s32 arg0, s32 arg1);
extern s32 func_8018766C(s32 arg0, s32 arg1);
extern s32 func_8018766C(s32 arg0, s32 arg1);
extern u8 D_80078EBA;
void func_80180770(void *a0);
extern s32 func_8018766C(s32 arg0, s32 arg1);
extern u8 D_80078EBA;
extern void func_80180770(void *a0);

void func_801807B8(void *a0) {
    s32 v0;
    *(s32 *)(*(s32 *)((s32)a0 + 0xcc) + 0xb0) = 1;
    if (D_80078EBA == 3) {
        v0 = 0;
    } else {
        v0 = func_8018766C(7, 0x13) != 0;
    }
    if (!v0) {
        func_80180770(a0);
    }
}
