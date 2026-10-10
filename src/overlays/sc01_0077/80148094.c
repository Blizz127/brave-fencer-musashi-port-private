/* sc01_0077: func_80148094 from Druthulu/BFM-decomp
 * src/ov_SC01_077/ov_SC01_077_after.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc01_0077 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef short s16;
typedef int s32;
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
extern void func_80013F3C(s32 a0);
extern void func_80012558(s32 a0, s32 a1);
extern void func_80013F3C(s32 a0);
extern void func_80012558(s32 a0, s32 a1);
extern void func_80013F3C(s32 a0);
extern void func_80012558(s32 a0, s32 a1);
extern void func_800484EC(s32 a0, s32 a1, s32 a2);
extern s32 func_8004CFEC(s32 a0, s32 a1);
extern s32 func_80047B3C(s32 a0);
extern void func_80013F3C(s32 a0);
extern void func_80012558(s32 a0, s32 a1);
extern void func_800484EC(s32 a0, s32 a1, s32 a2);
extern s32 func_80012A60(s32 a0, s32 a1);

void func_80148094(int param_1, short *param_2, int *param_3) {
    s32 s4 = *(int *)(param_1 + 0x20);
    s32 out[3];
    s32 buf[8];
    s32 bp;
    s32 t1;
    int sVar1;
    int fac;
    int r;
    if (*param_2 != 0 || param_2[2] != 0) {
        t1 = func_8004CFEC(-(int)param_2[2], -(int)*param_2) + 0x400;
        bp = (s32)buf;
        func_80013F3C(bp);
        func_80012558(bp, (s32)*(short *)(s4 + 0x12));
        func_800484EC(bp, param_1 + 0x24, (s32)out);
        sVar1 = (s16)func_80012A60((s16)t1, (s16)(func_8004CFEC(out[2], out[0]) + 0x400));
        out[0] = *(int *)(param_1 + 0x24);
        if (out[0] < 0) out[0] = -out[0];
        out[2] = *(int *)(param_1 + 0x2c);
        if (out[2] < 0) out[2] = -out[2];
        {
            int q = func_80047B3C((int)*param_2 * (int)*param_2 + (int)param_2[2] * (int)param_2[2]);
            if (q < 0) q += 0x3f;
            fac = func_8004CFEC((int)param_2[1], q >> 6);
        }
        if (sVar1 < 0x200) {
            __asm__("" :: "r"(fac));
            if (out[0] == out[2]) {
                r = *(int *)(param_1 + 0x24) * -fac;
                if (r < 0) r += 0x3ff;
                out[0] = r >> 10;
                out[1] = 0;
                r = *(int *)(param_1 + 0x2c) * -fac;
                if (r < 0) r += 0x3ff;
                out[2] = r >> 10;
            } else if (out[0] > out[2]) {
                r = *(int *)(param_1 + 0x24) * -fac;
                if (r < 0) r += 0x3ff;
                out[0] = r >> 10;
                out[1] = 0;
                out[2] = *(int *)(param_1 + 0x2c);
            } else {
                out[0] = *(int *)(param_1 + 0x24);
                out[1] = 0;
                r = *(int *)(param_1 + 0x2c) * -fac;
                if (r < 0) r += 0x3ff;
                out[2] = r >> 10;
            }
        } else if (sVar1 >= 0x201) {
            if (out[0] == out[2]) {
                r = *(int *)(param_1 + 0x24) * -fac;
                if (r < 0) r += 0x3ff;
                out[0] = *(int *)(param_1 + 0x24) + (r >> 10);
                out[1] = 0;
                r = *(int *)(param_1 + 0x2c) * -fac;
                if (r < 0) r += 0x3ff;
                out[2] = *(int *)(param_1 + 0x2c) + (r >> 10);
            } else if (out[0] > out[2]) {
                r = *(int *)(param_1 + 0x24) * -fac;
                if (r < 0) r += 0x3ff;
                out[0] = *(int *)(param_1 + 0x24) + (r >> 10);
                out[1] = 0;
                out[2] = *(int *)(param_1 + 0x2c);
            } else {
                out[0] = *(int *)(param_1 + 0x24);
                out[1] = 0;
                r = *(int *)(param_1 + 0x2c) * -fac;
                if (r < 0) r += 0x3ff;
                out[2] = *(int *)(param_1 + 0x2c) + (r >> 10);
            }
        } else {
            out[0] = *(int *)(param_1 + 0x24);
            out[1] = 0;
            out[2] = *(int *)(param_1 + 0x2c);
        }
        param_3[0] = out[0];
        param_3[1] = out[1];
        param_3[2] = out[2];
        return;
    }
    param_3[0] = *(int *)(param_1 + 0x24);
    param_3[1] = *(int *)(param_1 + 0x28);
    param_3[2] = *(int *)(param_1 + 0x2c);
}
