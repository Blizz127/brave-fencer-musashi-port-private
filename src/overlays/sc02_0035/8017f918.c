/* SC02.CD member35: func_8017F918 from Druthulu/BFM-decomp
 * src/ov_SC02_035/ov_SC02_035_jr_8017BEBC.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc02_0035 retail words (gcc-2.7.2 -O2). */
typedef unsigned short u16;
typedef int s32;
extern void func_8012A568(void (*a0)(void));
extern s32 func_8012BEE8(s32 a0);
extern s32 func_8012BEE8(s32 a0);

void func_8017F918(void *a0) {
    s32 v1;
    if (func_8012BEE8((s32)a0)) {
        *(u16 *)((char *)a0 + 0x2) = 6;
        *(u16 *)((char *)a0 + 0x34) = 0;
        v1 = *(s32 *)((char *)a0 + 0x20);
        *(u16 *)(v1 + 0x1C) = 0x400;
        *(u16 *)(v1 + 0x18) = 0x400;
        *(u16 *)(*(s32 *)((char *)a0 + 0x20) + 0x1A) = 0x3000;
    }
}
