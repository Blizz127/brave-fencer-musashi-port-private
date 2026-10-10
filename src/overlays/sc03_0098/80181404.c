/* sc03_0098: func_80181404 from Druthulu/BFM-decomp
 * src/ov_SC03_098/ov_SC03_098_jr_8017D898.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0098 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef short s16;
typedef int s32;
extern void func_8012A568(void (*a0)(void));
extern s32 func_8012B030(u8 *a0);
extern s32 func_8012B030(u8 *a0);

void func_80181404(s32 *a0) {
        *(s32 *)((s32)a0 + 0x1C) = 1;
        *(s16 *)((s32)a0 + 0x2) = 0x4;
        ((void (*)(void))func_8012B030)();
    }
