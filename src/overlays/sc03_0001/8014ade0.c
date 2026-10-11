/* sc03_0001: func_8014ADE0 from Druthulu/BFM-decomp
 * src/ov_SC03_001/ov_SC03_001_after.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0001 retail words (gcc-2.7.2 -O2). */
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
extern s32 func_80029178(s32 arg);
extern s32 D_80126B58;
extern void func_80015978(s32 a0, s32 *a1);
extern void func_801466F0(s32 a0, s32 a1, s32 a2, s32 a3, s32 sp5, s32 sp6, s32 sp7, s32 sp8);
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
extern void func_80015978(int a0, int *a1);
extern s32 D_80126B58;
extern s32 D_80126B58;
extern void func_80015978(s32 a0, s32 *a1);
extern void func_80015978(s32 a0, s32 *a1);
extern u8 D_80078E78[];
extern s16 D_800B9A08;
extern u16 *func_80146750(u16 *param_1);
extern void func_80015978(s32 a0, s32 *a1);
extern void func_8012E5CC(s32 param_1, u16 param_2, u16 param_3);
extern void func_8002D4C8(s32 a0, s32 a1);
extern void func_80147364();
extern u16 *func_80146750(u16 *param_1);
extern s16 D_800B9A08;
extern s32 func_80029178(s32 a0);
extern u8 D_80078E78[];
extern s16 D_800B9A08;
extern void func_80015978(s32 a0, s32 *a1);
extern void func_80015978(s32 a0, s32 *a1);
extern s32 func_80029178(s32 a0);
extern s32 func_80029178(s32);
extern s32 func_80029178(s32 arg);
extern s32 func_80029178(s32 a0);
extern s32 func_80029178(s32);
extern void func_80015978(s32 a0, s32 *a1);
extern s32 D_80126B58;
extern s32 D_8011D030;
extern void func_80146AFC(void *a0);
extern s32 D_80126B58;
extern u8 D_80078E78[];
extern s32 func_8016F1C4(void);
extern s32 func_8014B154(s32 *a0);
extern void func_8014BD24(s32 a0, s32 a1);
extern void func_8014BB24(s32 a0, s32 a1, s32 a2);
extern void func_8014BC80(s32 a0, s32 a1);
extern void func_8014BD60(s32 a0, s32 a1);
extern void func_8014B084(void);
extern s32 func_80029178(s32 a0);
void func_8014B084(void);
s32 func_8014B154(s32 *a0);
void func_8014BB24(s32 a0, s32 a1, s32 a2);
void func_8014BC80(s32 a0, s32 a1);
void func_8014BD24(s32 a0, s32 a1);
void func_8014BD60(s32 param_1, s32 param_2);

void func_8014ADE0(s32 a0)
{
    extern s32 D_80078E90;
    u8 *p = D_80078E78;
    s32 temp_s2;
    s32 var_a1;
    if (func_8016F1C4() != 0) {
        return;
    }
    if ((*(u16 *)a0 == 0x1A) || (*(u16 *)a0 == 0x1E) || (*(s32 *)(a0 + 0x44) & 0x10)) {
        return;
    }
    temp_s2 = D_80078E90;
    if (func_8014B154((s32 *)a0) != 0) {
        D_80078E90 = D_80078E90 + 0xAAA8;
    } else {
        D_80078E90 = D_80078E90 + 0x1555;
    }
    if ((*(s16 *)(p + 0x1A) - (temp_s2 >> 16)) > 0) {
        if (p[0x49] == 3) {
            func_8014BD24(a0, 1);
        }
    }
    if (((s16)(*(s16 *)(p + 0x1A) / 60) - (s16)((s16)(temp_s2 >> 16) / 60)) > 0) {
        if (func_8014B154((s32 *)a0) == 0) {
            var_a1 = 4;
        } else if (func_80029178(0x1B) & 0xFF) {
            var_a1 = 0xA;
        } else {
            var_a1 = 4;
        }
        if (*(u16 *)(p + 0x40) != 0) {
            func_8014BB24(a0, var_a1, 0);
        } else if (*(u16 *)(p + 0x3C) != 0) {
            if (*(u16 *)(p + 0x3C) >= 5U) {
                func_8014BC80(a0, 4);
            } else {
                *(u16 *)(p + 0x3C) = 1;
            }
        }
        if (func_8014B154((s32 *)a0) != 0) {
            if (func_80029178(0x1B) & 0xFF) {
                func_8014BD24(a0, 8);
            } else {
                func_8014BD60(a0, 1);
            }
        } else {
            func_8014BD60(a0, 4);
        }
    }
    if (*(s16 *)(p + 0x1A) >= 0x5A0) {
        *(s32 *)(p + 0x18) = 0;
        func_8014B084();
    }
}
