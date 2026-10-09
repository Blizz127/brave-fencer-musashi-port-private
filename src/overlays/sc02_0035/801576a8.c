/* SC02.CD member35: func_801576A8 from Druthulu/BFM-decomp
 * src/ov_SC02_035/ov_SC02_035_jr_80154C24.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc02_0035 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef int s32;
extern void func_801599A4(void *a0);
extern void func_80159B3C(void *a0);
extern void func_801599A4(void *a0);
extern void func_80159B3C(void *a0);
extern int func_80161208();
extern void func_801599A4(void *a0);
extern void func_80159B3C(void *a0);
extern int func_80155FF8(int arg, int a1);
extern void func_801599A4(void *a0);
extern void func_80159B3C(void *a0);
extern int func_80155FF8(int arg, int a1);
extern void func_801599A4(void *a0);
extern void func_80159B3C(void *a0);
extern s32 func_80161208();
extern int func_80155FF8(int arg, int a1);
extern int func_80155FF8(int arg, int a1);
int func_80155FF8(int arg, int a1);
extern int func_80155FF8(int arg, int a1);

void func_801576A8(void *arg0) {
    extern int func_80155FF8(int arg, int a1);
    extern void func_801599A4(void *a0);
    extern void func_80159B3C(void *a0);
    extern s32 func_80161208(void);
    s32 spill[4];
    *(s32 *)((u8 *)arg0 + 0x44) |= 2;
    if (*(u16 *)((u8 *)arg0 + 0xB8) == 0x8000) {
        func_801599A4(arg0);
        func_80159B3C(arg0);
    } else if (((s32 (*)(void *))func_80161208)(arg0) == 0) {
        func_80155FF8((int)arg0, *(u8 *)((u8 *)arg0 + 0x1AA));
    }
}
