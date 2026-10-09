/* SC02.CD member35: func_8017EF48 from Druthulu/BFM-decomp
 * src/ov_SC02_035/ov_SC02_035_jr_8017BEBC.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc02_0035 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef short s16;
typedef int s32;
extern void func_8012A568(void (*a0)(void));
extern s32 func_8012DFD4(s32 a0);
extern void func_8012CBA4(s32 a0);
extern s32 func_8012DFD4(s32);

void func_8017EF48(s32 a0) {
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
