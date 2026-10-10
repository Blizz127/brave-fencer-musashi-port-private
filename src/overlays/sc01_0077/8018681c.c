/* sc01_0077: func_8018681C from Druthulu/BFM-decomp
 * src/ov_SC01_077/ov_SC01_077_jr_80183CF4.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc01_0077 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef short s16;
typedef int s32;
typedef struct { u8 b[8]; } Blk8;
extern void func_8012A568(void (*a0)(void));
extern Blk8 D_801D5610;

void func_8018681C(s32 a0) {
    if (*(s16 *)((s32)a0 + 0x70) == 4) {
        *(Blk8 *)((s32)a0 + 0x50) = D_801D5610;
    }
}
