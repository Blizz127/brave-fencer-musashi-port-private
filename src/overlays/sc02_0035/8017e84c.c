/* SC02.CD member35: func_8017E84C from Druthulu/BFM-decomp
 * src/ov_SC02_035/ov_SC02_035_jr_8017BEBC.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc02_0035 retail words (gcc-2.7.2 -O2). */
typedef unsigned short u16;
typedef int s32;
extern void func_8012A568(void (*a0)(void));
extern void (*D_80196E70[])(void);

void func_8017E84C(void *a0) {
    D_80196E70[*(u16 *)((s32)a0 + 0x2)]();
}
