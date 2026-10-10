/* sc01_0077: func_8018414C from Druthulu/BFM-decomp
 * src/ov_SC01_077/ov_SC01_077_jr_80183CF4.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc01_0077 retail words (gcc-2.7.2 -O2). */
typedef int s32;
extern s32 func_8012DE2C(s32 a0);
extern s32 func_8012DDA4(void);
extern void func_8012A568(void (*a0)(void));
extern s32 func_8012DE2C(s32 a0);
extern s32 func_8012DDA4(void);

void func_8018414C(short *param_1) {
    unsigned short uVar1;
    short *psVar2;
    int iVar3;
    int k1f;
    int flag;
    psVar2 = (short *)func_8012DE2C((s32)param_1);
    if (psVar2 != (short *)0) {
        k1f = 0x1f;
        flag = 1;
        do {
            if (*(unsigned short *)psVar2 == 0x2f) {
                uVar1 = psVar2[0x2e];
                if ((uVar1 & 0x8000) != 0) {
                    if ((uVar1 & 0x4000) == 0) {
                        if (*(unsigned short *)&psVar2[0x2f] != k1f) {
                            if ((psVar2[0x57] & 1) == 0) {
                                iVar3 = (int)param_1[7] - (int)psVar2[7];
                                if (iVar3 < 0) iVar3 = -iVar3;
                                if (iVar3 < 0x21 && flag) {
                                    psVar2[0x2e] = uVar1 | 1;
                                    psVar2[0x30] = 0;
                                    psVar2[0x31] = 0;
                                    psVar2[0x2f] = k1f;
                                }
                            }
                        }
                    }
                }
            }
            psVar2 = (short *)func_8012DDA4();
        } while (psVar2 != (short *)0);
    }
}
