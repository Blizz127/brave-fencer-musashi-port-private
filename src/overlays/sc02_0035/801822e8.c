/* SC02.CD member35: func_801822E8 from Druthulu/BFM-decomp
 * src/ov_SC02_035/ov_SC02_035_jr_8017BEBC.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc02_0035 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef int s32;
extern void func_8012A568(void (*a0)(void));
extern void func_8012A828(s32*, s32);
extern void func_8012A828(s32*, s32);
extern void func_8012A828(s32*, s32);
extern void func_8012A828(s32*, s32);
extern void func_8018016C(s32 a0, s32 a1);
extern void func_80131E00(void *a0, s32 a1);
extern s32 func_80182318_def(s32 a0, s32 a1) __asm__("func_8018016C");
s32 func_80182318_def(s32 a0, s32 a1);
extern s32 func_8012CEB0(s32 a0, s32 a1, s32 a2);
extern s32 func_8012CEB0(s32 a0, s32 a1, s32 a2);
extern s32 func_8012CEB0(s32 a0, s32 a1, s32 a2);
extern void func_8012A828(s32*, s32);
extern void func_8012A828(s32*, s32);
extern void func_8012A828(s32*, s32);
extern void func_8012A828(s32*, s32);
extern void func_8012A828(s32*, s32);
extern void func_8012A828(s32*, s32);
extern s32 func_8012CEB0(s32 a0, s32 a1, s32 a2);
extern void func_8012A828(s32*, s32);
extern void func_80131E00(void *a0, s32 a1);

void func_801822E8(void *a0) {
    extern u8 D_801A7E08[];
    extern u8 D_801A8010[];
    extern u8 D_801A8BC8[];
    extern u8 D_801A96D0[];
    u16 buf[8];
    u16 v0;
    register u16 v1 __asm__("$3");
    register u16 a2 __asm__("$6");
    v0 = *(u16 *)((s32)a0 + 0x6);
    buf[0] = v0;
    buf[4] = v0;
    v1 = *(u16 *)((s32)a0 + 0xA);
    v0 = v1 - 8;
    buf[1] = v1;
    buf[5] = v1;
    a2 = *(u16 *)((s32)a0 + 0xE);
    v1 = v1 + 8;
    buf[1] = v0;
    buf[5] = v1;
    buf[2] = a2;
    buf[6] = a2;
    if ((func_8012CEB0((s32)&buf[0], (s32)&buf[4], 0) & 0x1F) != 0) {
        *(u16 *)((s32)a0 + 0x100) = *(u16 *)((s32)a0 + 0x100) | 0x8000;
        func_80131E00(a0, 6);
    } else {
        if (*(s32 *)((s32)a0 + 0x90) == (s32)&D_801A8010) {
            ((void (*)(s32, s32))func_8012A828)((s32)a0, (s32)&D_801A7E08);
            *(u16 *)((s32)a0 + 0x2) = 0x14;
            *(u16 *)((s32)a0 + 0x34) = 1;
            *(s16 *)((s32)a0 + 0xFE) = 0;
            *(s32 *)((s32)a0 + 0xCC) = (s32)&D_801A8BC8;
        } else {
            if (*(s16 *)((s32)a0 + 0xFE) != 0) {
                ((void (*)(s32, s32))func_8012A828)((s32)a0, (s32)&D_801A96D0);
            } else {
                ((void (*)(s32, s32))func_8012A828)((s32)a0, (s32)&D_801A8BC8);
            }
            *(u16 *)((s32)a0 + 0x2) = 1;
        }
        *(s16 *)((s32)a0 + 0xFC) = 0;
        *(u16 *)((s32)a0 + 0x5C) = (u16)0xAA10;
    }
}
