/* sc03_0001: func_8014C8C8 from Druthulu/BFM-decomp
 * src/ov_SC03_001/ov_SC03_001_after.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0001 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef short s16;
typedef int s32;
struct S8;
struct UnalignedPair;
struct packed_word;
union word_bytes;
struct up;
struct S8 { u32 a; u32 b; } __attribute__((packed, aligned(1)));
struct UnalignedPair {
    int a;
    int b;
} __attribute__((packed, aligned(1)));
struct packed_word { int w; } __attribute__((packed, aligned(1)));
union word_bytes {
    struct packed_word pw;
    u8 b[4];
};
struct up { int a; int b; } __attribute__((packed));
typedef struct { s16 a; s16 b; s16 c; s16 d; } S8;
struct PW8017E6D8 { int w; } __attribute__((packed, aligned(1)));
struct W4 { u32 w; } __attribute__((packed, aligned(1)));
typedef struct { u8 d[4]; } __attribute__((packed, aligned(1))) B4;
typedef struct { u8 d[4]; } __attribute__((packed, aligned(1))) B4_80165140;
typedef struct { u8 d[8]; } __attribute__((packed, aligned(1))) B8_80165140;
typedef struct {
    s32 op;
    union {
        s32 w;
        void *p;
        s16 h[2];
        u16 uh[2];
    } a;
} Cmd_80178D40;
typedef struct { s32 a, b; s8 c; } __attribute__((packed, aligned(1))) Rec9;
typedef struct Rec801466F0 {
    u16 unk0;
    u16 unk2;
    u16 unk4;
    u16 unk6;
    s32 unk8;
    s32 unkC;
    s32 unk10;
} Rec801466F0;
struct PW8017C290 { int w; } __attribute__((packed, aligned(1)));
struct PW8017E72C { int w; } __attribute__((packed, aligned(1)));
typedef struct { u8 d[4]; } __attribute__((packed, aligned(1))) B4_8018EDB0;
typedef struct { u8 d[4]; } __attribute__((packed, aligned(1))) B4_8018F060;
typedef struct { u8 d[8]; } __attribute__((packed, aligned(1))) B8_8018EDB0;
typedef struct { u8 d[8]; } __attribute__((packed, aligned(1))) B8_8018F060;
typedef struct { u16 a, b, c, d; } V4U_8014C4AC;
typedef struct { u8 b[4]; } __attribute__((packed, aligned(1))) Blk4_E960;
typedef struct { u8 b[4]; } __attribute__((packed, aligned(1))) Block4;
extern s32 D_80126B58;
extern void func_8002D4C8(s32 a0, s32 a1);
extern s32 D_80126B58;
extern u16 D_801152B8;
extern u16 D_8012693A;
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
extern s16 D_800B9A08;
extern void func_80015978(s32 a0, s32 *a1);
extern void func_8014C4AC(s32 a0, s32 a1, s32 a2, s16 *a3, s32 a4);
extern void func_80015978(s32 a0, s32 *a1);
extern void func_8014C4AC(s32 a0, s32 a1, s32 a2, s16 *a3, s32 a4);
extern void func_80015978(s32 a0, s32 *a1);
extern void func_8014C4AC(s32 a0, s32 a1, s32 a2, s16 *a3, s32 a4);
extern s32 D_80126B58;
extern s32 D_8011D030;
extern void func_80146AFC(void *a0);
extern s32 D_80126B58;
extern s32 D_80126B58;
extern s32 D_80126B58;
extern s32 D_80126B58;
extern s16 D_800B9A08;
extern void func_80015978(s32 a0, s32 *a1);
extern void func_80146AFC(void *a0);
extern s32 D_8011D030;
extern void func_8014C4AC(s32 a0, s32 a1, s32 a2, s16 *a3, s32 a4);
s32 aF8014C4AC(s32 a0, s32 a1, s32 a2, s16 *a3, s32 a4) __asm__("func_8014C4AC");
s32 aF8014C4AC() __asm__("func_8014C4AC");

extern void func_80015978(s32 a0, s32 *a1);

void func_8014C8C8(s32 dst, s32 * src)
{
    *(struct up *)(dst + 0x15c) = *(struct up *)(src + 0);
    *(s16 *)(dst + 0x162) = 0;
}
