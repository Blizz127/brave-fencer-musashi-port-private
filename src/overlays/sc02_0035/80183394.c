/* SC02.CD member35: func_80183394 from Druthulu/BFM-decomp
 * src/ov_SC02_035/ov_SC02_035_jr_8017BEBC.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc02_0035 retail words (gcc-2.7.2 -O2). */
typedef unsigned short u16;
typedef short s16;
typedef int s32;
extern s32 func_8005C49C(void);
extern int func_8005C49C(void);
extern void func_8012A568(void (*a0)(void));
extern s32 func_8005C49C(void);
extern s32 func_8005C49C(void);
extern s32 func_8005C49C(void);
extern s32 func_8005C49C(void);
extern s32 func_8005C49C(void);
extern void func_8018016C(s32 a0, s32 a1);
extern s32 func_8005C49C(void);
extern s32 func_8005C49C(void);
extern s32 func_80182318_def(s32 a0, s32 a1) __asm__("func_8018016C");
s32 func_80182318_def(s32 a0, s32 a1);
extern s32 func_8005C49C(void);
extern s32 func_8005C49C(void);
extern s32 func_8005C49C(void);
extern s32 func_8005C49C(void);
extern s32 func_8005C49C(void);
extern s32 func_8005C49C(void);
extern s32 func_8005C49C(void);
extern void func_8012B200(void *a0);

void func_80183394(void *a0) {
    s16 r;
    s16 t;
    r = func_8005C49C();
    *(u16 *)((s32)a0 + 0x104) = *(u16 *)((s32)a0 + 0xFC);
    t = r;
    func_8012B200(a0);
    if (*(u16 *)((s32)a0 + 0x70) & 1) {
        *(s32 *)((s32)a0 + 0x1C) = (s16)(r % 1800) + 0xE10;
    } else {
        *(s32 *)((s32)a0 + 0x1C) = (s16)(r % 60) + 0x78;
    }
    *(s16 *)((s32)a0 + 0xFE) = t % 32 + 0xA;
    *(s16 *)((s32)a0 + 0x2) = 2;
}
