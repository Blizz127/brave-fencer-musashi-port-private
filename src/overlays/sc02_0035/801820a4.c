/* SC02.CD member35: func_801820A4 from Druthulu/BFM-decomp
 * src/ov_SC02_035/ov_SC02_035_jr_8017BEBC.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc02_0035 retail words (gcc-2.7.2 -O2). */
typedef unsigned short u16;
typedef int s32;
extern void func_8012A568(void (*a0)(void));
extern void func_8012C218(void *a0);
extern s32 func_8012D624(void *a0, s32 a1, s32 a2);
extern void func_8012C218(void *a0);
extern void func_8018016C(s32 a0, s32 a1);
extern s32 func_80182318_def(s32 a0, s32 a1) __asm__("func_8018016C");
s32 func_80182318_def(s32 a0, s32 a1);
extern void func_8012C218(void *a0);
extern void func_8012C218(void *a0);
extern s32 func_8012D624(void *a0, s32 a1, s32 a2);
extern void func_8012C218(void *a0);
extern void func_8012B370(void *a0);

void func_801820A4(void *a0) {
    extern void (*D_8019C534[])(void *);
    u16 temp;
    s32 a1;
    D_8019C534[*(u16 *)((s32)a0 + 0x2)](a0);
    if (*(u16 *)((s32)a0 + 0x0) != 0) {
        *(u16 *)((s32)a0 + 0xa) = *(u16 *)((s32)a0 + 0xa) - 0x40;
        temp = *(u16 *)(*(s32 *)((s32)a0 + 0x20) + 0x18);
        a1 = (s32)(temp << 16) >> 24;
        if (func_8012D624(a0, a1, 0x14) == 1) {
            func_8012C218(a0);
        } else {
            *(u16 *)((s32)a0 + 0xa) = *(u16 *)((s32)a0 + 0xa) + 0x40;
            func_8012B370(a0);
        }
    }
}
