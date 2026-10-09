/* SC02.CD member35: func_80180ED8 from Druthulu/BFM-decomp
 * src/ov_SC02_035/ov_SC02_035_jr_8017BEBC.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc02_0035 retail words (gcc-2.7.2 -O2, rodata 0x801BD568). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef int s32;
extern s32 func_8005C49C(void);
extern int func_8005C49C(void);
extern void func_8012A568(void (*a0)(void));
extern s32 func_8012C658(s32 arg0, s32 arg1, s32 arg2);
extern void func_8012B2CC(s32 a0);
extern s32 func_8012C354(s32*, s32);
extern s32 func_8012C658(s32 arg0, s32 arg1, s32 arg2);
extern s32 func_8012C354(s32*, s32);
extern void func_8012A828(s32*, s32);
extern s32 func_8012C658(s32 arg0, s32 arg1, s32 arg2);
extern s32 func_8012C354(s32*, s32);
extern void func_8012A828(s32*, s32);
extern void func_8012B2CC(s32 a0);
extern void func_8012B23C(void *a0);
extern void func_80143970(void *a0);
extern s32 func_8012C354(s32*, s32);
extern void func_8012A828(s32*, s32);
extern void func_8012CAE4(void *a0);
extern void func_8012A828(s32*, s32);
extern s32 func_8005C49C(void);
extern s32 func_8005C49C(void);
extern s32 func_8005C49C(void);
extern void func_8012CAE4(void *a0);
extern s32 func_8012C354(s32*, s32);
extern void func_8012B2CC(s32 a0);
extern s32 func_8005C49C(void);
extern void func_8012B23C(void *a0);
extern s32 func_8005C49C(void);
extern void func_8018016C(s32 a0, s32 a1);
extern s32 func_8005C49C(void);
extern void func_8012B23C(void *a0);
extern void func_8012B23C(void *a0);
extern s32 func_8005C49C(void);
extern void func_8012B2CC(s32 a0);
extern s32 func_80182318_def(s32 a0, s32 a1) __asm__("func_8018016C");
s32 func_80182318_def(s32 a0, s32 a1);
extern s32 func_8005C49C(void);
extern void func_8012A828(s32*, s32);
extern s32 func_8012C658(s32 arg0, s32 arg1, s32 arg2);
extern s32 func_8012C354(s32*, s32);
extern void func_8012CAE4(void *a0);
extern void func_80143970(void *a0);
extern void func_8012A828(s32*, s32);
extern void func_8012B23C(void *a0);
extern void func_8012B2CC(s32 a0);
extern s32 func_8012C658(s32 arg0, s32 arg1, s32 arg2);
extern s32 func_8005C49C(void);

void func_80180ED8(void *a0) {
    extern u8 D_8019C1E8[];
    extern u8 D_801A8BC8[];
    extern u8 D_801A8490[];
    extern char D_801A9B40[];
    extern u8 D_801A99C0[];
    extern s32 D_8019C320;
    extern s32 D_8019C3C0;
    extern s32 D_8019C408;
    s16 state = *(s16 *)((s32)a0 + 0x70);
    if (((s32 (*)(s32, s32))func_8012C354)((s32)a0, (s32)(D_8019C1E8 + state * 0x34)) == 0) {
        func_8012CAE4((void *)a0);
    } else {
        s16 state2;
        u16 saved;
        *(u8 *)((s32)a0 + 0xC0) = 1;
        *(s32 *)((s32)a0 + 0xB4) = -0x401;
        func_80143970((void *)a0);
        state2 = *(s16 *)((s32)a0 + 0x70);
        switch (state2) {
            case 0:
                ((void (*)(s32, s32))func_8012A828)((s32)a0, (s32)D_801A8BC8);
                *(s16 *)((s32)a0 + 0x2) = 1;
                func_8012B23C((void *)a0);
                saved = *(u16 *)((s32)a0 + 0xFC);
                *(s32 *)((s32)a0 + 0xBC) = (s32)&D_8019C320;
                *(s16 *)((s32)a0 + 0xFC) = 0;
                *(u16 *)((s32)a0 + 0x100) = saved;
                break;
            case 2:
                ((void (*)(s32, s32))func_8012A828)((s32)a0, (s32)D_801A8490);
                saved = *(u16 *)((s32)a0 + 0xFC);
                *(s16 *)((s32)a0 + 0x2) = 9;
                *(s32 *)((s32)a0 + 0xBC) = (s32)&D_8019C3C0;
                *(u16 *)((s32)a0 + 0x100) = saved;
                break;
            case 1:
            case 3:
                ((void (*)(s32, s32))func_8012A828)((s32)a0, (s32)&D_801A9B40);
                *(s16 *)((s32)a0 + 0x2) = 6;
                *(s32 *)((s32)a0 + 0xBC) = (s32)&D_8019C408;
                break;
            case 4:
                ((void (*)(s32, s32))func_8012A828)((s32)a0, (s32)D_801A8BC8);
                *(s16 *)((s32)a0 + 0x2) = 0xD;
                func_8012B23C((void *)a0);
                *(s32 *)((s32)a0 + 0xBC) = (s32)&D_8019C320;
                *(s16 *)((s32)a0 + 0xFC) = 0x1E;
                break;
            case 5:
                if (*(s16 *)((s32)a0 + 0xFC) != 0) {
                    ((void (*)(s32, s32))func_8012A828)((s32)a0, (s32)D_801A99C0);
                    *(s16 *)((s32)a0 + 0x2) = 0xE;
                    *(u16 *)(*(s32 *)((s32)a0 + 0x20) + 0x12) = func_8005C49C() & 0xFFF;
                } else {
                    ((void (*)(s32, s32))func_8012A828)((s32)a0, (s32)D_801A8BC8);
                    *(s16 *)((s32)a0 + 0x2) = 1;
                }
                func_8012B23C((void *)a0);
                *(s32 *)((s32)a0 + 0xBC) = (s32)&D_8019C320;
                *(s16 *)((s32)a0 + 0xFE) = 1;
                do {
                    func_8012C658(0x12F, 5, (s32)a0);
                    *(s16 *)((s32)a0 + 0xFE) = *(u16 *)((s32)a0 + 0xFE) + 1;
                } while (*(s16 *)((s32)a0 + 0xFE) < 6);
                *(s16 *)((s32)a0 + 0xFE) = 0;
                break;
            }
        func_8012B2CC((s32)a0);
    }
}
