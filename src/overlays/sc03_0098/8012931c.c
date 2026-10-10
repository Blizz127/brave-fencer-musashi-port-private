/* sc03_0098: func_8012931C from Druthulu/BFM-decomp
 * src/ov_SC03_098/ov_SC03_098.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0098 retail words (gcc-2.7.2 -O2). */
typedef int s32;
struct vec;
struct vec {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
    s32 unk14;
    s32 unk18;
};

void func_8012931C(struct vec *a0) {
    a0->unk4 += a0->unk10;
    a0->unk8 += a0->unk14;
    a0->unkC += a0->unk18;
}
