/* SC02.CD member35: func_80183258 from Druthulu/BFM-decomp
 * src/ov_SC02_035/ov_SC02_035_jr_8017BEBC.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc02_0035 retail words (gcc-2.7.2 -O2). */
typedef unsigned short u16;
typedef int s32;
extern void func_8012A568(void (*a0)(void));
extern void func_8018016C(s32 a0, s32 a1);
extern s32 func_80182318_def(s32 a0, s32 a1) __asm__("func_8018016C");
s32 func_80182318_def(s32 a0, s32 a1);
extern void (*D_801B977C[])(void);
extern void func_80183F2C(void *a0);
void func_80183F2C(void *a0);

void func_80183258(void *a0) {
    D_801B977C[*(u16 *)((s32)a0 + 0x2)]();
    if (*(u16 *)((s32)a0 + 0x0) != 0) {
        *(s32 *)((s32)a0 + 0xE8) = *(s32 *)((s32)a0 + 0xE8) + 1;
        if ((*(s32 *)((s32)a0 + 0xE8) & 0xF) == 0) {
            func_80183F2C(a0);
        }
    }
}
