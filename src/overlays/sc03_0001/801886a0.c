/* sc03_0001: func_801886A0 from Druthulu/BFM-decomp
 * src/ov_SC03_001/ov_SC03_001_jr_801870B0.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0001 retail words (gcc-2.7.2 -O2). */
typedef unsigned short u16;
typedef short s16;
typedef int s32;
extern void func_8012A568(void (*a0)(void));
extern s32 func_8012E57C(s32 a0, s32 a1);
extern s32 func_8012E57C(s32 a0, s32 a1);
extern void func_8012F2E8(s32 a0, s32 a1, s32 a2);
extern s32 func_8012CB64(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4);
s32 aF801848DC(void *a0) __asm__("func_801848DC");
extern s32 func_8012E57C(s32 a0, s32 a1);
extern s32 func_8012E57C(s32 a0, s32 a1);
extern s32 func_8012E57C(s32 a0, s32 a1);
extern s32 func_8012E57C(s32 a0, s32 a1);
extern s32 func_8012E57C(s32 a0, s32 a1);

s32 func_801886A0(s32 a0) {
    void *p;
    p = (void *)func_8012E57C(0x61, (s16)a0);
    if (p == 0) {
        return 1;
    }
    switch (*(u16 *)((char *)p + 2)) {
    case 1:
    case 2:
        *(s16 *)((char *)p + 0x108) = 1;
        return 0;
    case 3:
        *(s16 *)((char *)p + 0x108) = 1;
        return 0;
    case 4:
        *(s16 *)((char *)p + 0x108) = 1;
        return 1;
    }
}
