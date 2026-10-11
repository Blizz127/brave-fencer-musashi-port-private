/* sc03_0001: func_8012BC60 from Druthulu/BFM-decomp
 * src/ov_SC03_001/ov_SC03_001_jr_8012ACE0.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0001 retail words (gcc-2.7.2 -O2). */
typedef short s16;
typedef int s32;
struct Vec;
struct Vec {
    s16 unk0;
    s16 unk2;
    s16 unk4;
    s16 unk6;
    s16 unk8;
    s16 unkA;
};
typedef struct { short vx, vy, vz, pad; } Vec;
extern void func_8012A568(void (*a0)(void));
extern void func_8012A5F8(void (*a0)(void), s32 a1);
extern void func_80049324(s32 *a0, s32 *a1);

s32 func_8012BC60(struct Vec *a0, struct Vec *a1) {
    s32 d[3];
    d[0] = a0->unk2 - a1->unk2;
    d[1] = a0->unk6 - a1->unk6;
    d[2] = a0->unkA - a1->unkA;
    func_80049324(d, d);
    return d[0] + d[1] + d[2];
}
