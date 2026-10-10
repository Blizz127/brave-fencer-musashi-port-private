/* SC02.CD member35: func_80182150 from Druthulu/BFM-decomp
 * src/ov_SC02_035/ov_SC02_035_jr_8017BEBC.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc02_0035 retail words (gcc-2.7.2 -O2). */
typedef unsigned short u16;
typedef short s16;
typedef int s32;
extern void func_8012A568(void (*a0)(void));
extern u16 D_80126B96;
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
extern s32 func_8012D624(void *a0, s32 a1, s32 a2);
extern void func_8012C218(void *a0);

void func_80182150(void *a0) {
    extern void (*D_8019C694[])(void *);
    extern u16 D_80126B96;
    u16 *q;
    D_8019C694[*(u16 *)((s32)a0 + 0x2)](a0);
    if (*(u16 *)((s32)a0 + 0x0) != 0) {
        *(s16 *)((s32)a0 + 0xa) = *(u16 *)((s32)a0 + 0xa) - 0x40;
        if (func_8012D624(a0, 0x10, 0x16) == 1) {
            q = &D_80126B96;
            *q |= 0x200;
            func_8012C218(a0);
        } else {
            *(s16 *)((s32)a0 + 0xa) = *(u16 *)((s32)a0 + 0xa) + 0x40;
        }
    }
}
