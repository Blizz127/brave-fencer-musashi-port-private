/* sc01_0077: func_8013A0A4 from Druthulu/BFM-decomp
 * src/ov_SC01_077/ov_SC01_077_jr_801380E0.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc01_0077 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef int s32;
struct S8013A0A4;
struct S8013A0A4 {
    u8 pad0[4];
    s16 field_4;
    u8 pad6[2];
    s32 field_8;
    u8 pad12[10];
    u16 field_16;
    u8 pad18[6];
    u8 field_1E;
    u8 pad1F[15];
    s16 field_2E;
};
extern void func_8012A568(void (*a0)(void));
extern void func_8012A5F8(void (*a0)(void), s32 a1);
extern void func_80139B18(s32 a0);
extern s16 D_8012752C;
extern s16 D_8012752C;
void func_80139A8C(s32 a0);
extern s16 D_8012752C;
void func_80139B18(s32 a0);
extern void func_80139A8C(s32 a0);
extern void func_80139A8C(s32 a0);
extern void func_80139B18(s32 a0);
extern void func_80139B18(s32 a0);
extern void func_80139A8C(s32 a0);
extern void func_80139B18(s32 a0);
extern void func_80139A8C(s32 a0);
extern void func_80139B18(s32 a0);

void func_8013A0A4(struct S8013A0A4 *a0) {
    if (a0->field_1E != 0) {
        a0->field_1E = a0->field_1E + 5;
    } else {
        a0->field_1E = 4;
    }
    if (a0->field_1E >= 0xC) {
        a0->field_16 = (a0->field_16 + 1) % (a0->field_2E + 1);
        a0->field_1E = 0;
        if (a0->field_8 & 0x100) {
            a0->field_4 = 6;
        } else {
            a0->field_4 = 2;
        }
    }
    func_80139A8C((s32)a0);
    func_80139B18((s32)a0);
}
extern s16 D_8012752C;
