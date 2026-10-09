/* SC02.CD member35: func_801800C0 from Druthulu/BFM-decomp
 * src/ov_SC02_035/ov_SC02_035_jr_8017BEBC.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc02_0035 retail words (gcc-2.7.2 -O2). */
typedef unsigned short u16;
typedef signed char s8;
typedef short s16;
typedef int s32;
extern void func_8012A568(void (*a0)(void));
extern void func_8012B2CC(s32 a0);
extern void func_8012B2CC(s32 a0);
extern void func_8012B2CC(s32 a0);
extern void func_8012B2CC(s32 a0);
extern void func_8012C098(void *param_1);

void func_801800C0(arg0)
s32 arg0;
{
    s32 a3;
    register s32 v1 __asm__("$3");
    s32 v0;
    register s32 a0r __asm__("$4");
    register s32 a1r __asm__("$5");
    register s32 a2r __asm__("$6");
    a3 = arg0;
    v1 = *(u16 *)(a3 + 0x70);
    if ((v1 & 0x800) != 0) {
        v0 = v1 & 0x10;
        if (v0 != 0) {
            v0 = 5;
            v1 = *(s32 *)(a3 + 0x78);
            a0r = *(u16 *)(a3 + 0x88);
            a1r = *(s32 *)(a3 + 0x20);
            *(s16 *)(a3 + 0x2) = v0;
            v0 = 0x5A;
            *(s8 *)(a3 + 0xC1) = 0;
            *(s16 *)(a3 + 0x5E) = 0;
            *(s32 *)(a3 + 0x1C) = v0;
            v0 = *(u16 *)(v1 + 0x2);
            *(s16 *)(a3 + 0x5C) = v0;
            v0 = *(s32 *)(a3 + 0x78);
            v1 = *(u16 *)(a3 + 0x8C);
            a2r = *(u16 *)(v0 + 0x0);
            v0 = *(u16 *)(a3 + 0x8A);
            *(s16 *)(a3 + 0x6) = a0r;
            *(s16 *)(a3 + 0xE) = v1;
            *(s16 *)(a3 + 0xA) = v0;
            *(s16 *)(a3 + 0x76) = a2r;
            *(s16 *)(a1r + 0x10) = 0;
            v0 = *(s32 *)(a3 + 0x20);
            *(s16 *)(v0 + 0x12) = 0;
            *(s16 *)(a3 + 0xAA) = 0;
            func_8012B2CC(a3);
        } else {
            goto c098;
        }
    } else {
    c098:
        func_8012C098((void *)a3);
    }
}
