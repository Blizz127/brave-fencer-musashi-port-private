/* sc03_0001: func_801829A8 from Druthulu/BFM-decomp
 * src/ov_SC03_001/ov_SC03_001_jr_8017AE2C.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0001 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef int s32;
extern void func_8012A568(void (*a0)(void));
extern void func_80187994(s32, s32, s32, s32);
extern void func_80187994(s32 a0, s32 a1, s32 a2, s32 a3);
extern void func_80187994(s32 a0, s32 a1, s32 a2, s32 a3);
extern s32 func_80187A64(s32 a0);
extern s32 func_801886A0(s32 arg0);
extern s32 func_80187A64(s32 a0);
extern void func_80187994(s32 a0, s32 a1, s32 a2, s32 a3);
extern s32 func_801886A0(s32 arg0);
extern s32 func_80187A64(s32 a0);
extern void func_80187994(s32, s32, s32, s32);
extern s32 func_801886A0(s32 a0);
extern s32 func_80187A64(s32 a0);
extern void func_80187994(s32, s32, s32, s32);
extern s32 func_80187A64(s32);
extern void func_80187994(s32, s32, s32, s32);
extern s32 func_801886A0(s32);
extern void func_80187994(s32 a0, s32 a1, s32 a2, s32 a3);
void func_80182548(void *a0);
extern u8 D_801B936C[];
extern void func_80187994(s32, s32, s32, s32);
extern s32 func_80187A64(s32 a0);
extern s32 func_801886A0(s32 a0);
extern void func_80187994(s32, s32, s32, s32);
extern s32 func_80187A64(s32 a0);
extern s32 func_801886A0(s32 arg0);
extern u8 D_801B936C[];
extern void func_80182548();
extern void func_80187994(s32, s32, s32, s32);

void func_801829A8(void *a0) {
    s32 v0;
    if (*(u16 *)((u8 *)a0 + 0x34) == 0) {
        if ((v0 = func_801886A0(3)) != 0 && (v0 = ((s32 (*)(void *))func_80187A64)(a0)) != 0) {
            ((void (*)(void *, void *, s32, s32))func_80187994)(a0, D_801B936C, 0, 0x80);
            *(u16 *)((u8 *)a0 + 0x34) = 1;
        }
    } else {
        if ((v0 = ((s32 (*)(void *))func_80187A64)(a0)) != 0) {
            func_80182548(a0);
        }
    }
}
