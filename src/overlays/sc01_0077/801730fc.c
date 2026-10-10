/* sc01_0077: func_801730FC from Druthulu/BFM-decomp
 * src/ov_SC01_077/ov_SC01_077_jr_80171B4C.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc01_0077 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef int s32;
struct S801730FC;
struct S801730FC {
    u8 pad[0xB8];
    u16 unkB8;
};
extern void func_80147060(u8 * a0);
extern void func_80154150(s32 a0, s32 a1);
extern void func_80154150(int, int);
void func_80154150(s32 a0, s32 a1);
extern void func_80147060(u8 *a0);
extern void func_8012A568(void (*a0)(void));
extern void func_80171A1C(u8 *a0);
extern s32 func_80174650(s32);
extern s32 func_80174650(s32);
extern s16 D_80126B30;
extern void func_80147060(u8 *a0);
extern void func_80171A1C(u8 *a0);
extern s16 D_80126B30;
extern void func_80171A1C(u8 *a0);
extern s32 func_80174650(s32);
extern s16 D_80126B30;
extern void func_80147060(u8 *a0);
extern void func_80171A1C(u8 *a0);
extern void func_80171A1C(u8 *a0);
extern s32 func_80174650(s32);
extern s16 D_80126B30;
extern s16 D_80126B30;
extern void func_80147060(u8 *a0);
extern void func_80171A1C(u8 *a0);
extern s16 D_80126B30;
extern s16 D_80126B30;
extern void func_80171A1C(u8 *a0);
extern void func_80171A1C(u8 *a0);
extern s32 func_80174650(s32);
extern void func_80147060(u8 *a0);
extern void func_80171A1C(u8 *a0);
extern void func_80171A1C(u8 *a0);
extern s32 func_80174650(s32);
extern s16 D_80126B30;
extern void func_80147060(u8 *a0);
extern void func_80171A1C(u8 *a0);
extern void func_80171A1C(u8 *a0);
extern s32 func_80174650(s32);
extern s16 D_80126B30;
extern void func_80147060(u8 *a0);
extern void func_80171A1C(u8 *a0);
extern void func_80171A1C(u8 *a0);
extern s32 func_80174650(s32);
extern s16 D_80126B30;
extern s32 func_80174650(s32);
extern s32 func_80174650(s32);
extern s16 D_80126B30;
extern s32 func_80174650(s32);
extern s16 D_80126B30;
extern s32 func_80174650(s32);
extern s16 D_80126B30;
extern s16 D_80126B30;
extern void func_80171A1C(u8 *a0);
extern void func_801730FC(struct S801730FC *a0);
extern void func_80171A1C(u8 *a0);
extern void func_80147060(u8 *a0);
extern void func_80154150(s32 a0, s32 a1);
extern s32 func_80174650(s32);
extern s16 D_80126B30;

void func_801730FC(struct S801730FC *a0) {
    if (a0->unkB8 & 0x8000) {
        func_80171A1C((u8 *)a0);
        if (D_80126B30 != 0) {
            func_80147060(a0);
            func_80154150(a0, 0);
        }
        func_80174650((s32)a0);
    }
}
