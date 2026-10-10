/* sc01_0077: func_8013E22C from Druthulu/BFM-decomp
 * src/ov_SC01_077/ov_SC01_077.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc01_0077 retail words (gcc-2.7.2 -O2). */
typedef short s16;
typedef int s32;
struct VecA;
struct VecB;
struct VecA {
    s16 unk0;
    s16 unk2;
    s16 unk4;
    s16 unk6;
    s16 unk8;
    s16 unkA;
};
struct VecB {
    s16 unk0;
    s16 unk2;
    s16 unk4;
};
extern void func_800492FC(s32 *a0, s32 *a1);

s32 func_8013E22C(struct VecA *a0, struct VecB *a1) {
    s32 d[3];
    s32 sq[3];
    d[0] = a0->unk2 - a1->unk0;
    d[1] = a0->unk6 - a1->unk2;
    d[2] = a0->unkA - a1->unk4;
    func_800492FC(d, sq);
    return sq[0] + sq[1] + sq[2];
}
extern s16 D_80126CB0;
