/* sc03_0001: func_80183628 from Druthulu/BFM-decomp
 * src/ov_SC03_001/ov_SC03_001_jr_8017AE2C.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0001 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
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
extern void func_80187994(s32, s32, s32, s32);
extern s32 func_80187A64(s32 a0);
extern s32 func_801886A0(s32 a0);
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
extern void func_80187994(s32, s32, s32, s32);
void func_80182EE4(void *a0);
extern void func_80187994(s32, s32, s32, s32);
extern s32 func_801886A0(s32 a0);
extern s32 func_80187A64(s32 a0);
extern void func_80187994(s32, s32, s32, s32);
extern void func_80182EE4(void *a0);

void func_80183628(void *a0)
{
    extern u8 D_801B940C[];
    if (*(u16 *)((s32)a0 + 0x34) == 0) {
        if (func_801886A0(3) == 0) {
            return;
        }
        if (func_80187A64((s32)a0) == 0) {
            return;
        }
        ((void (*)(void *, void *, s32, s32))func_80187994)(a0, D_801B940C, 0, 0x40);
        *(s16 *)((s32)a0 + 0x34) = 1;
        return;
    }
    *(s32 *)(*(s32 *)((s32)a0 + 0xCC) + 0xB0) = 2;
    if (func_80187A64((s32)a0) != 0) {
        func_80182EE4(a0);
    }
}
