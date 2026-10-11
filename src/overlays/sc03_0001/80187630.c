/* sc03_0001: func_80187630 from Druthulu/BFM-decomp
 * src/ov_SC03_001/ov_SC03_001_jr_801870B0.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0001 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef int s32;
extern void func_8012A568(void (*a0)(void));
extern u8 D_80078EB1;
extern s32 func_8018739C(void);
s32 aF801848DC(void *a0) __asm__("func_8018739C");

void func_80187630(void *a0, s32 a1, s32 a2)
{
    extern u8 D_80078EB1;
    s32 v0;
    register s32 v1 __asm__("$3");
    v0 = D_80078EB1;
    if (!(v0 < a1)) {
        if (v0 < a2) {
            v0 = 1;
            v1 = *(s32 *)((s32)a0 + 0xCC);
        } else {
            v1 = *(s32 *)((s32)a0 + 0xCC);
            v0 = 2;
        }
    } else {
        v1 = *(s32 *)((s32)a0 + 0xCC);
        v0 = 2;
    }
    *(s32 *)(v1 + 0xB0) = v0;
}
