/* SC02.CD member35: func_80183CBC from Druthulu/BFM-decomp
 * src/ov_SC02_035/ov_SC02_035_jr_8017BEBC.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc02_0035 retail words (gcc-2.7.2 -O2). */
typedef unsigned short u16;
typedef short s16;
typedef int s32;
extern void func_8012A568(void (*a0)(void));
extern void func_8012A828(s32*, s32);
extern void func_8012A828(s32*, s32);
extern void func_8012A828(s32*, s32);
extern void func_8012A828(s32*, s32);
extern s32 func_8012BEE8(s32 a0);
extern void func_8018016C(s32 a0, s32 a1);
extern s32 func_8012BEE8(s32 a0);
extern void func_8012E88C(s32);
extern s32 func_8012BEE8(s32 a0);
extern s32 func_80182318_def(s32 a0, s32 a1) __asm__("func_8018016C");
s32 func_80182318_def(s32 a0, s32 a1);
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
extern void func_8012A828(s32*, s32);
extern void func_8012A828(s32*, s32);
extern void func_8012A828(s32*, s32);
extern s32 func_8012BEE8(s32 a0);
extern void func_8012A828(s32*, s32);
extern void func_8012A828(s32*, s32);
extern void func_8012A828(s32*, s32);
extern void func_8012A828(s32 *a0, s32 a1);
extern s32 D_801BBC6C;
extern s32 func_8012BEE8(s32 a0);
extern s32 func_8012BEE8(s32 a0);
extern s32 func_8012BEE8(s32 a0);
extern s32 func_8012BEE8(s32 a0);
extern s32 func_8012E778(s32 a0, s32 a1);
extern void func_8012E88C(s32 a0);
extern void func_8012A828(s32 *a0, s32 a1);
extern s32 D_801BBC6C;

void func_80183CBC(void *arg0) {
    if (func_8012BEE8((s32)arg0)) {
        if (!func_8012E778((s32)arg0, 0xA000C8)) {
            {
                s32 t;
                t = *(u16 *)((char *)arg0 + 0x70) & 0x10;
                *(s16 *)((char *)arg0 + 0x2) = (t == 0) ? 1 : 3;
            }
            *(s16 *)((char *)arg0 + 0x5C) =
                *(u16 *)(*(s32 *)((char *)arg0 + 0x78) + 0x2);
            *(s16 *)((char *)arg0 + 0x76) =
                *(u16 *)(*(s32 *)((char *)arg0 + 0x78));
            *(s16 *)(*(s32 *)((char *)arg0 + 0x20) + 0x18) =
                *(s16 *)(*(s32 *)((char *)arg0 + 0x20) + 0x1A) =
                *(s16 *)(*(s32 *)((char *)arg0 + 0x20) + 0x1C) = 0x1000;
            *(u16 *)(*(s32 *)((char *)arg0 + 0x20) + 0x2C) &= 0x10;
            func_8012E88C((s32)arg0);
            func_8012A828(arg0, &D_801BBC6C);
        }
    }
}
