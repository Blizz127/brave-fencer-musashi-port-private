/* sc01_0077: func_80173220 from Druthulu/BFM-decomp
 * src/ov_SC01_077/ov_SC01_077_jr_80171B4C.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc01_0077 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed char s8;
typedef short s16;
typedef int s32;
typedef s32 M2C_UNK;
typedef struct {
    s32 op;
    union {
        s32 w;
        void *p;
        s16 h[2];
        u16 uh[2];
    } a;
} Cmd_80178D40;
extern void func_80147324(s32 arg0);
extern void func_80019064(void *a0);
extern void func_80147324(s32 a0);
extern void func_80147324(int a);
extern void func_8012A568(void (*a0)(void));
extern void func_80171A1C(u8 *a0);
extern s32 func_80174650(s32);
extern s32 func_80174650(s32);
extern void func_80171A1C(u8 *a0);
extern void func_80171A1C(u8 *a0);
extern s32 func_80174650(s32);
extern void func_80171A1C(u8 *a0);
extern void func_80171A1C(u8 *a0);
extern s32 func_80174650(s32);
extern void func_80171A1C(u8 *a0);
extern void func_80171A1C(u8 *a0);
extern void func_80171A1C(u8 *a0);
extern s32 func_80174650(s32);
extern void func_80171A1C(u8 *a0);
extern void func_80171A1C(u8 *a0);
extern s32 func_80174650(s32);
extern void func_80171A1C(u8 *a0);
extern void func_80171A1C(u8 *a0);
extern s32 func_80174650(s32);
extern void func_80171A1C(u8 *a0);
extern void func_80171A1C(u8 *a0);
extern s32 func_80174650(s32);
extern s32 func_80174650(s32);
extern s32 func_80174650(s32);
extern s32 func_80174650(s32);
extern s32 func_80174650(s32);
extern void func_80171A1C(u8 *a0);
extern void func_80171A1C(u8 *a0);
extern s32 func_80174650(s32);
extern void func_80171A1C(u8 *a0);
extern void func_80019064(void *a0);
extern void func_80147324(s32 a0);
extern void func_80171A1C(u8 *a0);
extern s32 func_80174650(s32);
extern M2C_UNK D_8018A094;

void func_80173220(void * arg0)
{
    if ((*(u16 *)((s8 *)(arg0) + (0xB8))) & 0x4000) {
        func_80147324(0x516);
        func_80019064(&D_8018A094);
    }
    if ((*(u16 *)((s8 *)(arg0) + (0xB8))) & 0x8000) {
        func_80171A1C(arg0);
        func_80174650(arg0);
    }
}
