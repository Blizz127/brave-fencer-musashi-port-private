/* sc03_0098: func_801567BC from Druthulu/BFM-decomp
 * src/ov_SC03_098/ov_SC03_098_jr_80154C24.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0098 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned int u32;
typedef short s16;
typedef int s32;
struct obj;
struct obj {
    u8 pad0[0x4];
    s16 unk4;
    u8 pad6[0x2];
    s32 unk8;
};
extern s32 D_801151E0[];
extern s32 D_801151E0[];
extern u8 D_8011DAD8[];
extern s32 D_801151E0[];
extern s32 func_8014C568(s16 *a0, s16 *a1);

void func_801567BC(s32 a0) {
    s32 obj = a0;
    s32 i = 0;
    u8 *q = D_8011DAD8;
    s32 *p = D_801151E0;
    do {
        if (*p & 1) {
            *(s16 *)(*(s32 *)(obj + 0x20) + 0x12) =
                ((s32 (*)(void *, void *))func_8014C568)((void *)obj, q);
        }
        q += 8;
        i += 1;
        p += 1;
    } while ((u32)i < 3);
}
