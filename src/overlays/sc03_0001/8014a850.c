/* sc03_0001: func_8014A850 from Druthulu/BFM-decomp
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
extern s16 D_800B9A08;
extern u16 *func_80146750(u16 *param_1);
extern void func_80015978(s32 a0, s32 *a1);
extern void func_8012E5CC(s32 param_1, u16 param_2, u16 param_3);
extern void func_8002D4C8(s32 a0, s32 a1);
extern void func_80147364();
extern u16 *func_80146750(u16 *param_1);
extern s16 D_800B9A08;
extern u8 D_801202A0[];
extern u8 D_801202A0[];
extern s16 D_800B9A08;
extern u8 D_801202A0[];
extern void func_80015978(s32 a0, s32 *a1);
extern void func_8014C4AC(s32 a0, s32 a1, s32 a2, s16 *a3, s32 a4);
extern u8 D_801202A0[];
extern u8 D_801202A0[];
extern void func_80015978(s32 a0, s32 *a1);
extern void func_8014C4AC(s32 a0, s32 a1, s32 a2, s16 *a3, s32 a4);
extern void func_80015978(s32 a0, s32 *a1);
extern s32 func_80029AF4(void);
extern void func_8014C4AC(s32 a0, s32 a1, s32 a2, s16 *a3, s32 a4);
extern u8 D_801202A0[];

s32 func_8014A850(s32 param_1) {
    s32 i;
    s32 cnt;
    s16 buf[3];
    s16 out[4];
    s32 x;
    s32 uVar2;
    s16 *po;
    cnt = 0;
    po = out;
    i = 0;
    do {
        s32 e = (s32)&D_801202A0 + i;
        if (*(u16 *)(e + 0) != 0 && *(s32 *)(e + 0x58) != 0 &&
            (*(u16 *)(e + 0x5C) & 0x8000) != 0 && *(u8 *)(e + 0xC1) == 7) {
            x = *(u16 *)(param_1 + 6) - *(u16 *)(e + 6);
            buf[0] = x;
            buf[1] = *(u16 *)(param_1 + 0xA) - (*(u16 *)(e + 0xA) + 0x40);
            buf[2] = *(u16 *)(param_1 + 0xE) - *(u16 *)(e + 0xE);
            if ((((s16)x < 0) ? -(s16)x : (s16)x) < 0x40) {
                if (((buf[2] < 0) ? -buf[2] : buf[2]) < 0x40) {
                    if (((buf[1] < 0) ? -buf[1] : buf[1]) < 0x40) {
                        *(s32 *)(param_1 + 0x18C) = e;
                        func_80015978(param_1 + 4, (s32 *)po);
                        out[3] = 0;
                        uVar2 = func_80029AF4();
                        func_8014C4AC(e, 0x1B, uVar2, po,
                                      (s32)*(s16 *)(*(s32 *)(param_1 + 0x20) + 0x12));
                        return 1;
                    }
                }
            }
        }
        cnt += 1;
        i += 0x10C;
    } while ((u32)cnt < 0x60);
    return 0;
}
