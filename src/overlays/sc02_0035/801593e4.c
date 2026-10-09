/* SC02.CD member35: func_801593E4 from Druthulu/BFM-decomp
 * src/ov_SC02_035/ov_SC02_035_jr_801588CC.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc02_0035 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef struct {
    u8 pad[0x12];
    u16 field12;
} S801593E4;
typedef struct {
    u8 pad[0x20];
    S801593E4 *p20;
} A801593E4;

void func_801593E4(A801593E4 *a0) {
    S801593E4 *v1 = a0->p20;
    v1->field12 = (v1->field12 + 0x16) & 0xFFF;
}
