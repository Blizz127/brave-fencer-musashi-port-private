/* sc01_0077: func_801598E0 from Druthulu/BFM-decomp
 * src/ov_SC01_077/ov_SC01_077_jr_801588CC.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc01_0077 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned short u16;
extern void func_80159968(void *a0);
void func_80159968(void *a0);

void func_801598E0(u8 *a0) {
    switch (a0[0xA9]) {
    case 0x41:
        *(u16 *)(a0 + 0xAA) &= 0xAFFF;
        *(u16 *)(a0 + 0xAC) &= 0xAFFF;
        break;
    case 0x53:
    case 0x73:
        *(u16 *)(a0 + 0xAE) = a0[0xAE] | 0x8000;
        break;
    }
    func_80159968((void *)a0);
}
