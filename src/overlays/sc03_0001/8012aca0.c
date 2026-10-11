/* sc03_0001: func_8012ACA0 from Druthulu/BFM-decomp
 * src/ov_SC03_001/ov_SC03_001.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0001 retail words (gcc-2.7.2 -O2). */
typedef unsigned short u16;
typedef signed char s8;
typedef short s16;
typedef int s32;
typedef s32 M2C_UNK;
extern void func_8012AAAC();
extern void func_8012AAAC();
extern void func_8012AAAC();
extern void func_8012AAAC();
extern void func_8012AAAC();
extern void func_8012AAAC(void *arg0);
void func_8012AAAC(void *arg0);
extern void func_8012AAAC();
extern M2C_UNK D_8018D838;

void func_8012ACA0(void *arg0) {
    (*(M2C_UNK **)((s8 *)(arg0) + (0x90))) = &D_8018D838;
    (*(s32 *)((s8 *)(arg0) + (0x94))) = 0;
    (*(s32 *)((s8 *)(arg0) + (0x9C))) = 0;
    (*(s16 *)((s8 *)(arg0) + (0x9A))) = 0;
    (*(u16 *)((s8 *)(arg0) + (0x72))) = (u16) ((*(u16 *)((s8 *)(arg0) + (0x72))) & 0xF9FF);
    ((void (*)(void))func_8012AAAC)();
}
