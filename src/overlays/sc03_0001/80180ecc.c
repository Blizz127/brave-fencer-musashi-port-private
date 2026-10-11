/* sc03_0001: func_80180ECC from Druthulu/BFM-decomp
 * src/ov_SC03_001/ov_SC03_001_jr_8017AE2C.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0001 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef int s32;
extern void func_8012A568(void (*a0)(void));
extern s32 func_801789AC(s32 arg0);
extern int func_80178970(void);
extern void func_80178D18(void);
extern void func_80178CBC(s32*, s32);
extern int func_80178970(void);
extern void func_80178D18(void);
void func_80180C3C(void * arg0);
extern void func_80178CBC(s32 *a0, s32 a1);
extern s32 func_801789AC(s32 arg0);
extern int func_80178970(void);
extern void func_80178D18(void);
extern void func_80178CBC(s32 *a0, s32 a1);
void func_80180C3C(void *arg0);

void func_80180ECC(void *a0) {
    extern u16 D_80191AC4[];
    extern u8 D_80191AEC;
    u16 state;
    s32 r;
    state = *(u16 *)((char *)a0 + 0x34);
    switch (state) {
    case 1:
        r = func_801789AC((s32)a0);
        if (r != 0) {
            if (r == state) {
                func_80178CBC((s32 *)a0, (s32)&D_80191AC4);
            } else {
                func_80178CBC((s32 *)a0, (s32)&D_80191AEC);
            }
            *(u16 *)((char *)a0 + 0x34) = *(u16 *)((char *)a0 + 0x34) + 0x1;
        }
        break;
    case 0:
    case 2:
        if (((s32 (*)(s32))func_80178970)((s32)a0) != 0) {
            ((void (*)(s32))func_80178D18)((s32)a0);
            func_80180C3C(a0);
        }
        break;
    }
}
