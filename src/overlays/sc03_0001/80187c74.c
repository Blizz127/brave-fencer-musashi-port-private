/* sc03_0001: func_80187C74 from Druthulu/BFM-decomp
 * src/ov_SC03_001/ov_SC03_001_jr_801870B0.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0001 retail words (gcc-2.7.2 -O2). */
typedef unsigned short u16;
typedef int s32;
extern void func_8012A568(void (*a0)(void));
extern void (*D_801C0B20[])(void);

void func_80187C74(void *a0) {
    D_801C0B20[*(u16 *)((s32)a0 + 0x2)]();
}
