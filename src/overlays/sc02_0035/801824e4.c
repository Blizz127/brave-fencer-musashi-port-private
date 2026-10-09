/* SC02.CD member35: func_801824E4 from Druthulu/BFM-decomp
 * src/ov_SC02_035/ov_SC02_035_jr_8017BEBC.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc02_0035 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef int s32;
typedef struct { u16 x, y, z, w; } V8_801824E4;
extern s32 func_80133784(s32 a0, void *a1, s32 a2);
extern s32 func_80133784(s32 a0, void *src, s32 dst);
extern void func_8012A568(void (*a0)(void));
extern void func_8012B1B4(s32 a0, s32 a1);
extern void func_8012B1B4(s32 a0, s32 a1);
extern void func_8012CBA4(s32 a0);
extern void func_8012CBA4(s32 a0);
extern void func_8018016C(s32 a0, s32 a1);
extern void func_8012CBA4(s32 a0);
extern s32 func_80182318_def(s32 a0, s32 a1) __asm__("func_8018016C");
s32 func_80182318_def(s32 a0, s32 a1);
extern void func_8012B1B4(s32 a0, s32 a1);
extern void func_8012CBA4(s32 a0);
extern s32 func_80133784(s32 a0, void *a1, s32 a2);
extern void func_8012B1B4(s32 a0, s32 a1);
extern void func_8012CBA4(s32 a0);
extern s32 func_80133784(s32 a0, void *a1, s32 a2);
extern void func_8012B1B4(s32 a0, s32 a1);
extern void func_8012CBA4(s32 a0);
extern void func_8012B1B4(s32 a0, s32 a1);
extern void func_8012CBA4(s32 a0);
extern s32 func_80133784(s32 a0, void *a1, s32 a2);
extern void func_8012B1B4(s32 a0, s32 a1);
extern void func_8012B1B4(s32 a0, s32 a1);
extern void func_8012B1B4(s32 a0, s32 a1);
extern void func_8012CBA4(s32 a0);
extern s32 func_80133784(s32 a0, void *a1, s32 a2);

void func_801824E4(s32 a0) {
    extern u8 D_8019C19C[];
    V8_801824E4 sp10;
    V8_801824E4 sp18;
    if (*(s32 *)(a0 + 0x94) >= 8) {
        *(s16 *)(a0 + 0xFE) = 1;
        func_8012B1B4(a0, (s32)D_8019C19C);
        if ((((s32 (*)(s32))func_8012CBA4)(a0) & 0x6000) == 0) {
            sp10.x = *(u16 *)(a0 + 0x3A);
            sp10.y = *(u16 *)(a0 + 0x3E);
            sp10.z = *(u16 *)(a0 + 0x42);
            sp18 = sp10;
            sp18.y += 8;
            if (func_80133784(1, &sp10, (s32)&sp18) != 0) {
                *(s32 *)(a0 + 0x4) = *(s32 *)(a0 + 0x38);
                *(s32 *)(a0 + 0x8) = *(s32 *)(a0 + 0x3C);
                *(s32 *)(a0 + 0xC) = *(s32 *)(a0 + 0x40);
            }
        }
    }
}
