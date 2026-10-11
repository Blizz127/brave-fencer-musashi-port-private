/* sc03_0001: func_80161774 from Druthulu/BFM-decomp
 * src/ov_SC03_001/ov_SC03_001_jr_8015C32C.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0001 retail words (gcc-2.7.2 -O2). */
typedef unsigned short u16;
typedef unsigned int u32;
typedef short s16;
typedef int s32;
extern s32 func_8004CFEC(s32 a0, s32 a1);
extern s32 func_8014A6C4(s32 a0);
extern void func_801599A4(void *a0);
extern void func_8014C010(s32 a0, s32 a1);
extern s32 func_8004CFEC(s32 dx, s32 dy);
extern void func_8015BDD0(s32 *a0);
extern void func_8015BF48(s32 *a0);
extern int func_80161208();
extern s32 func_80161208();
extern void func_8015BDD0(s32 *a0);
extern void func_80161D20(int param_1, u32 param_2);
extern void func_8014C010(s32 a0, s32 a1);
extern void func_8014C010(s32 a0, s32 a1);
extern s32 func_80161208();
extern s32 func_80161208();
extern s32 func_80161208();
extern s32 func_80161208();
extern s32 func_80161208();
extern s32 func_80161208();
extern s32 func_80161208();
extern s32 func_80161208();
extern s32 func_80161208(void);
void func_8015F2F0(s32 *a0);
extern s32 func_80161208(void);
extern s32 func_80161208(void);
extern void func_801599A4(void *a0);
extern s32 func_80161208();
extern s32 func_80161208();
extern s32 func_80161208();
extern s32 func_80161208();
extern s32 func_80161208();
extern s32 func_80161208();
extern s32 func_80161208();
extern s32 func_80161208();
extern s32 func_80161208();
extern s32 func_80161208();
extern s32 func_80161208();
extern void func_8016130C(void*, s32);
void aF80161208(void *a0) __asm__("func_80161208");
void aF80161208(void *a0) __asm__("func_80161208");
extern void func_8016130C(void *a0, s32 a1);
extern void func_801599A4(void*);
extern void func_8015BDD0(s32*);
extern void func_8015BF48(s32*);
s32 aF8016130C(void *a0, s32 a1) __asm__("func_8016130C");
s32 aF8016130C(void *a0, s32 a1) __asm__("func_8016130C");
s32 aF8016130C(void *a0, s32 a1) __asm__("func_8016130C");
extern void func_801599A4(void*);
extern void func_8015BDD0(s32*);
extern void func_8015BF48(s32*);
extern void func_801599A4(void *a0);
extern void func_8015BF48(s32 *a0);
extern void func_8015F2F0(s32 *a0);
extern void func_8014C010(s32 a0, s32 a1);
extern void func_80161D20(int param_1, u32 param_2);
extern s32 func_8014A6C4(s32 a0);
extern s32 func_8004CFEC(s32 a0, s32 a1);
extern void func_801599A4(void *a0);
extern void func_8014C010(s32 a0, s32 a1);
extern void func_80161D20();
extern void func_8015BF48(s32 *a0);
extern s32 func_8014A6C4(s32 a0);
extern void func_8015F2F0(s32 *a0);
extern s32 func_8004CFEC(s32 a0, s32 a1);
extern s16 D_801152B0;
extern s16 D_801152B4;
extern void func_8014C010(s32 a0, s32 a1);
extern void func_80161D20(int param_1, u32 param_2);
extern void func_801599A4(void *a0);
extern void func_8015BF48(s32 *a0);
extern s32 func_8014A6C4(s32 a0);
extern void func_8015F2F0(s32*);
extern s32 func_8004CFEC(s32 x, s32 y);
extern void func_8014C010(s32 a0, s32 a1);
extern void func_80161D20();
extern void func_801599A4(void *a0);
extern void func_8015BF48(s32 *a0);
extern s32 func_8014A6C4(s32 a0);
extern void func_8015F2F0(s32 *a0);
extern s16 D_801152B0;
extern s16 D_801152B4;
void func_80161D20(int param_1, u32 param_2);

s32 func_80161774(int a0, u32 a1)
{
    s32 v1;
    s16 v2;
    if ((a1 & 1) != 0) {
        func_8014C010((s32)a0, 1);
        v1 = *(u16 *)((s32)a0 + 0x16E);
        func_80161D20((s32)a0, v1);
        return 1;
    }
    if ((a1 & 0x4000) != 0) {
        func_801599A4(a0);
        func_8015BF48((s32 *)a0);
        func_8014C010((s32)a0, 1);
        v1 = *(u16 *)((s32)a0 + 0x16E);
        func_80161D20((s32)a0, v1);
        return 2;
    }
    if ((a1 & 0x2000) != 0) {
        func_8014C010((s32)a0, 1);
        v1 = *(u16 *)((s32)a0 + 0x16E);
        func_80161D20((s32)a0, v1);
        return 4;
    }
    if ((a1 & 0x8000) != 0) {
        v1 = *(u16 *)((s32)a0 + 0x16C);
        if (v1 != 0x15) {
            return 0;
        }
        v1 = func_8014A6C4((s32)a0);
        if (v1 == 0) {
            return 0;
        }
        func_801599A4(a0);
        func_8015F2F0((s32 *)a0);
        v2 = func_8004CFEC(D_801152B0, D_801152B4);
        *(s16 *)(*(s32 *)((s32)a0 + 0x20) + 0x12) = v2;
        return 8;
    }
    return 0;
}
