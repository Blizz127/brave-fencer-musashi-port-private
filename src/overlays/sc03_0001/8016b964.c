/* sc03_0001: func_8016B964 from Druthulu/BFM-decomp
 * src/ov_SC03_001/ov_SC03_001_jr_8016AB6C.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0001 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef struct {
    u8 pad6[0x6];
    u16 h6;
    u16 h8;
    u16 hA;
} SrcB964;
typedef struct {
    u8 pad8[0x8];
    u16 h8;
    u16 hA;
    u16 hC;
} DstB964;

void func_8016B964(SrcB964 *a0, DstB964 *a1) {
    a1->h8 = a0->h6;
    a1->hA = a0->hA;
    a1->hC = 3;
}
