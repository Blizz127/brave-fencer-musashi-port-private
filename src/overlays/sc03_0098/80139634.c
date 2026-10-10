/* sc03_0098: func_80139634 from Druthulu/BFM-decomp
 * src/ov_SC03_098/ov_SC03_098_jr_801380E0.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0098 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef int s32;
extern void func_8012A5F8(void (*a0)(void), s32 a1);
extern void func_80059888(void *a0, s32 a1, s32 a2, s32 a3);
extern void func_80059888(void *a0, s32 a1, s32 a2, s32 a3);

void func_80139634(void *a0) {
    s16 sp[4];
    sp[0] = *(u16 *)((u8 *)a0 + 0x38);
    sp[1] = *(u16 *)((u8 *)a0 + 0x3A);
    sp[2] = 0x38;
    sp[3] = 0x30;
    func_80059888(&sp[0], 0, 0, 0);
}
