/* sc01_0077: func_80182268 from Druthulu/BFM-decomp
 * src/ov_SC01_077/ov_SC01_077_jr_80182268.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc01_0077 retail words (gcc-2.7.2 -O2). */
typedef unsigned short u16;
typedef signed char s8;
typedef int s32;
extern void func_8012A568(void (*a0)(void));
extern void func_8012C218(void *a0);
extern s32 D_801270CC;

void func_80182268(void *a0) {
    s32 t;
    t = (s8)(*(u16 *)((s32)a0 + 0x70) >> 8);
    switch (t) {
    case 0:
    case 1:
    case 2:
    case 5:
    case 6:
        func_8012C098(a0);
        break;
    case 4:
        D_801270CC -= 1;
    case 3:
    case 7:
        func_8012C218(a0);
        break;
    }
}
