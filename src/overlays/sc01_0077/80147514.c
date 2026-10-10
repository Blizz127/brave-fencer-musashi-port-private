/* sc01_0077: func_80147514 from Druthulu/BFM-decomp
 * src/ov_SC01_077/ov_SC01_077_after.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc01_0077 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef short s16;
typedef int s32;
struct V4s80147514;
struct V4s80147514 { s16 a, b, c, d; };
typedef struct {
    s32 op;
    union {
        s32 w;
        void *p;
        s16 h[2];
        u16 uh[2];
    } a;
} Cmd_80178D40;
typedef struct Rec801466F0 {
    u16 unk0;
    u16 unk2;
    u16 unk4;
    u16 unk6;
    s32 unk8;
    s32 unkC;
    s32 unk10;
} Rec801466F0;
extern s32 D_80126B58;
extern void func_8002D4C8(s32 a0, s32 a1);
extern s32 D_80126B58;
extern void func_80015978(s32 a0, s32 *a1);
extern void func_801466F0(s32 a0, s32 a1, s32 a2, s32 a3, s32 sp5, s32 sp6, s32 sp7, s32 sp8);
extern void func_801466F0(s32 a0, s32 a1, s32 a2, s32 a3,
                          s32 sp5, s32 sp6, s32 sp7, s32 sp8);
extern u16 *func_80146750(u16 *param_1);
extern u16 *func_8014680C(short *param_1);
extern void aF801466F0(u16 a0, s32 a1, u16 a2, u16 a3, u16 sp5, s32 sp6, s32 sp7, s32 sp8)
    __asm__("func_801466F0");
void aF801466F0(u16 a0, s32 a1, u16 a2, u16 a3, u16 sp5, s32 sp6, s32 sp7, s32 sp8) __asm__("func_801466F0");
unsigned short *func_80146750(unsigned short *a0);
unsigned short *func_8014680C(short *param_1);
extern s32 D_8011D030;
extern s32 func_80146A6C(s32 a0, void *a1, s32 a2, s32 a3, s32 a4, s32 a5, s32 a6);
extern s32 func_80146A6C(s32 a0, void *a1, s32 a2, s32 a3, s32 a4, s32 a5, s32 a6);
extern s32 D_8011D030;
extern void func_80146AFC(void*);
void aF80146A6C(s16 a0, s32 a1, s16 a2, s16 a3, u16 a4, s32 a5, s32 a6) __asm__("func_80146A6C");
void aF80146A6C(s16 a0, s32 a1, s16 a2, s16 a3, u16 a4, s32 a5, s32 a6) __asm__("func_80146A6C");
void aF80146A6C(s16 a0, s32 a1, s16 a2, s16 a3, u16 a4, s32 a5, s32 a6) __asm__("func_80146A6C");
extern s32 D_8011D030;
s32 aF80146AFC(void *arg0) __asm__("func_80146AFC");
s32 aF80146AFC(void *arg0) __asm__("func_80146AFC");
s32 aF80146AFC(void *arg0) __asm__("func_80146AFC");
extern void func_80147364();
extern void func_80147364();
extern s16 D_800B9A08;
extern s32 D_80126B58;
extern void func_80015978(s32, s32*);
extern s32 aF8012E5CC(s32, s32, s32) __asm__("func_8012E5CC");
extern void func_8002D4C8(s32 a0, s32 a1);
void aF80147364(u16 param_1, u16 param_2) __asm__("func_80147364");
void aF80147364(u16 param_1, u16 param_2) __asm__("func_80147364");
extern s32 func_80012C6C(s32 a0, s32 a1, s32 a2);
extern s32 func_800129CC(s32 a0, s32 a1);

void func_80147514(s32 arg0) {
    s16 buf[8];
    *(struct V4s80147514 *)buf = *(struct V4s80147514 *)(arg0 + 0x120);
    if (((u16)buf[0] | (u16)buf[1] | (u16)buf[2]) == 0) {
        buf[1] = -0xFFF;
    }
    if (*(s16 *)(arg0 + 0x12E) != 0) {
        buf[0] = (u16)buf[0] + *(u16 *)(arg0 + 0x128);
        buf[1] = (u16)buf[1] + *(u16 *)(arg0 + 0x12A);
        buf[2] = (u16)buf[2] + *(u16 *)(arg0 + 0x12C);
    }
    *(s16 *)(arg0 + 0x118) = func_80012C6C(*(s16 *)(arg0 + 0x118), buf[0], 8);
    *(s16 *)(arg0 + 0x11A) = func_80012C6C(*(s16 *)(arg0 + 0x11A), buf[1], 8);
    *(s16 *)(arg0 + 0x11C) = func_80012C6C(*(s16 *)(arg0 + 0x11C), buf[2], 8);
    buf[0] = *(u16 *)(arg0 + 0x118);
    buf[1] = *(u16 *)(arg0 + 0x11A);
    buf[2] = *(u16 *)(arg0 + 0x11C);
    func_800129CC((s32)buf, arg0 + 0x100);
}
