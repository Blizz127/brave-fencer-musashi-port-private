/* sc03_0098: func_8013A164 from Druthulu/BFM-decomp
 * src/ov_SC03_098/ov_SC03_098_jr_801380E0.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0098 retail words (gcc-2.7.2 -O2). */
typedef unsigned short u16;
typedef short s16;
typedef int s32;
struct S8013A164;
struct S8013A164 {
    char pad0[0x4];
    s16 field_04;
    char pad06[0x2];
    s32 field_08;
    char pad0C[0xC];
    u16 field_18;
    char pad1A[0x26];
    s16 *field_40;
};
extern void func_8012A5F8(void (*a0)(void), s32 a1);
extern s32 D_80127524;
extern s32 D_80127524;
extern s16 D_8012752C;
extern s16 D_8012752C;
extern s16 D_8012752C;
extern s32 D_80127524;

void func_8013A164(struct S8013A164 *a0) {
    s32 flags;
    if (a0->field_40 == 0 || a0->field_18 == 0 || *a0->field_40 == 2) {
        flags = a0->field_08 | 0x1000;
        a0->field_08 = flags;
        if (flags & 0x10000) {
            if (D_8012752C != 0) {
                if (flags & 0x40000) {
                    a0->field_04 = 2;
                } else {
                    a0->field_04 = 0x10;
                }
            } else {
                a0->field_04 = 2;
            }
        } else {
            a0->field_04 = 2;
        }
    }
}
extern s32 D_80127524;
