/* sc03_0001: func_8013A250 from Druthulu/BFM-decomp
 * src/ov_SC03_001/ov_SC03_001_jr_801380E0.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0001 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef int s32;
struct S8013A250;
struct S8013A250 {
    u8 pad8[8];
    s32 unk8;
    u8 unkC;
};
extern void func_8012A568(void (*a0)(void));
extern void func_8012A5F8(void (*a0)(void), s32 a1);
extern s32 D_80127524;
extern s32 D_80127524;
extern void func_80138B88(s32 a0);
extern void func_80139B18(s32 a0);
void func_80138B88(s32 a0);
void func_80139A8C(s32 a0);
void func_80139B18(s32 a0);
extern void func_80139A8C(s32 a0);
extern void func_80139A8C(s32 a0);
extern void func_80139B18(s32 a0);
extern void func_80139B18(s32 a0);
extern s32 D_80127524;
extern void func_80139A8C(s32 a0);
extern void func_80139B18(s32 a0);
extern void func_80139A8C(s32 a0);
extern void func_80139B18(s32 a0);
extern void func_80138B88(s32 a0);
extern void func_80139A8C(s32 a0);
extern void func_80139B18(s32 a0);
extern void func_80138B88(s32 a0);

void func_8013A250(struct S8013A250 *a0) {
    if (a0->unkC != 0) {
        a0->unkC = a0->unkC - 1;
        func_80139A8C((s32)a0);
        if ((a0->unk8 & 0x80020) == 0) {
            func_80139B18((s32)a0);
            return;
        }
    }
    func_80138B88((s32)a0);
}
extern s32 D_80127524;
