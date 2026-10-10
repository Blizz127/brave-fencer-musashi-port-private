/* sc03_0098: func_80180AD8 from Druthulu/BFM-decomp
 * src/ov_SC03_098/ov_SC03_098_jr_8017D898.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0098 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef short s16;
typedef int s32;
extern void func_8012A568(void (*a0)(void));
extern s32 func_8012DFD4(s32 a0);
extern void func_8012CBA4(s32 a0);
extern s32 func_8012DFD4(s32);

void func_80180AD8(s32 a0) {
    s32 t;
    func_8012CBA4(a0);
    t = *(s32 *)(a0 + 0x1C) - 1;
    *(s32 *)(a0 + 0x1C) = t;
    if (t == 0) {
        *(s32 *)(a0 + 0x1C) = 0x6;
        *(s16 *)(a0 + 0x2) = 0x2;
    }
    ((void (*)(u8 *))func_8012DFD4)((u8 *)a0);
}
