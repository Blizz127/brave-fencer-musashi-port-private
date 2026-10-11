/* sc03_0001: func_80177AD4 from Druthulu/BFM-decomp
 * src/ov_SC03_001/ov_SC03_001_jr_801734BC.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0001 retail words (gcc-2.7.2 -O2). */


void func_80177AD4(int param_1, unsigned int param_2) {
    unsigned int c;
    register unsigned int b __asm__("$3");
    char *base; short i; int f; int t;
    f = 0x100; i = 0; base = (char *)param_1;
    do {
        c = (param_2 << 16) >> 28;
        b = c;
        if ((c != 0) || (i == 3) || (i == 1)) f = 0;
        param_2 = param_2 << 4; i = i + 1;
        t = *(unsigned short *)(base + 0x1e);
        *(unsigned short *)(base + 0x1e) = f | (t & ~0x100);
        base[0x20] = b * 8 + 8;
        base = base + 0x14;
    } while (i < 4);
}
