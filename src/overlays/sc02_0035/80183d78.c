/* SC02.CD member35: func_80183D78 from Druthulu/BFM-decomp
 * src/ov_SC02_035/ov_SC02_035_jr_8017BEBC.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc02_0035 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed char s8;
typedef short s16;
typedef int s32;
extern void func_8012A568(void (*a0)(void));
extern void func_8012C218(void *a0);
extern void func_8002A04C(s32 a0);
extern void func_8012C218(void *a0);
extern void func_8012E8A8(u8 *a0);
extern void func_8018016C(s32 a0, s32 a1);
extern void func_8012E8A8(u8 *a0);
extern s32 func_80182318_def(s32 a0, s32 a1) __asm__("func_8018016C");
s32 func_80182318_def(s32 a0, s32 a1);
extern void func_8012C218(void *a0);
extern void func_8012C218(void *a0);
extern void func_8012C218(void *a0);
extern void func_8012C218(void *a0);
extern void func_8002A04C(s32 a0);
extern void func_8012C218(void *a0);
extern void func_8012E8A8(u8 *a0);

void func_80183D78(void *arg0) {
    func_8002A04C((s32)arg0);
    if ((*(s16 *)((char *)arg0 + 0x70) & 0x8000) != 0) {
        s32 v1 = *(s32 *)((char *)arg0 + 0x20);
        *(s16 *)((char *)arg0 + 0x2) = 0x7;
        *(s8 *)((char *)arg0 + 0xC1) = 0;
        *(s32 *)((char *)arg0 + 0x1C) = 0x40;
        *(s16 *)((char *)arg0 + 0x5E) = 0;
        *(s16 *)((char *)arg0 + 0x5C) = 0;
        *(s16 *)((char *)v1 + 0x12) = 0;
        *(s16 *)((char *)v1 + 0x10) = 0;
        func_8012E8A8((u8 *)arg0);
        *(s16 *)((char *)arg0 + 0x6) = *(u16 *)((char *)arg0 + 0x88);
        *(s16 *)((char *)arg0 + 0xA) = *(u16 *)((char *)arg0 + 0x8A);
        *(s16 *)((char *)arg0 + 0xE) = *(u16 *)((char *)arg0 + 0x8C);
    } else {
        func_8012C218(arg0);
    }
}
