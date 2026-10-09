/* SC02.CD member35: func_801832D4 from Druthulu/BFM-decomp
 * src/ov_SC02_035/ov_SC02_035_jr_8017BEBC.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc02_0035 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef short s16;
typedef int s32;
extern s32 func_8005C49C(void);
extern int func_8005C49C(void);
extern void func_8012A568(void (*a0)(void));
extern s32 func_8012C354(s32*, s32);
extern s32 func_8012C354(s32*, s32);
extern void func_8012A828(s32*, s32);
extern s32 func_8012C354(s32*, s32);
extern void func_8012A828(s32*, s32);
extern s32 func_8012C354(s32*, s32);
extern void func_8012A828(s32*, s32);
extern void func_8012A828(s32*, s32);
extern s32 func_8005C49C(void);
extern s32 func_8005C49C(void);
extern s32 func_8005C49C(void);
extern s32 func_8012C354(s32*, s32);
extern s32 func_8005C49C(void);
extern s32 func_8005C49C(void);
extern void func_8018016C(s32 a0, s32 a1);
extern s32 func_8005C49C(void);
extern s32 func_8005C49C(void);
extern s32 func_80182318_def(s32 a0, s32 a1) __asm__("func_8018016C");
s32 func_80182318_def(s32 a0, s32 a1);
extern s32 func_8005C49C(void);
extern void func_8012A828(s32*, s32);
extern s32 func_8012C354(s32*, s32);
extern void func_8012A828(s32*, s32);
extern s32 func_8005C49C(void);
extern void func_8012A828(s32*, s32);
extern void func_8012A828(s32*, s32);
extern s32 func_8005C49C(void);
extern void func_8012A828(s32*, s32);
extern void func_8012A828(s32*, s32);
extern s32 func_8005C49C(void);
extern void func_8012A828(s32*, s32);
extern void func_8012A828(s32*, s32);
extern void func_8012A828(s32*, s32);
extern void func_8012A828(s32*, s32);
extern void func_8012A828(s32*, s32);
extern void func_8012A828(s32*, s32);
extern void func_8012A828(s32*, s32);
extern void func_8012A828(s32*, s32);
extern void func_8012A828(s32*, s32);
extern void func_8012A828(s32*, s32);
extern void func_8012A828(s32*, s32);
extern void func_8012A828(s32*, s32);
extern s32 func_8005C49C(void);
extern s32 func_8005C49C(void);
extern s32 func_8012C354(s32 *a0, s32 a1);
extern void func_8012A828(s32 *a0, s32 a1);
extern void func_80143994(s32 *a0, s32 a1);
extern s32 D_801B9710;
extern s32 D_801B9754;
extern s32 D_801BBC6C;

void func_801832D4(void *arg0) {
    s32 t;
    if (func_8012C354(arg0, &D_801B9710)) {
        *(u8 *)((char *)arg0 + 0xC0) = 1;
        *(s32 *)((char *)arg0 + 0xB4) = -1;
        *(s32 **)((char *)arg0 + 0xBC) = &D_801B9754;
        *(u32 *)((char *)arg0 + 0xC4) |= 1;
        *(s32 *)((char *)arg0 + 0xE4) = -((func_8005C49C() % 8 + 0xC) << 16);
        func_8012A828(arg0, &D_801BBC6C);
        func_80143994(arg0, 0x1000);
        t = *(u16 *)((char *)arg0 + 0x70) & 0x10;
        if (t != 0) {
            t = 3;
        } else {
            t = 1;
        }
        *(s16 *)((char *)arg0 + 0x2) = t;
    }
}
