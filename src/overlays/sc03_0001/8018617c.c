/* sc03_0001: func_8018617C from Druthulu/BFM-decomp
 * src/ov_SC03_001/ov_SC03_001_jr_80184F64.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0001 retail words (gcc-2.7.2 -O2). */
typedef unsigned short u16;
typedef short s16;
typedef int s32;
extern void func_8012A568(void (*a0)(void));
extern void func_80172710(void);
extern s32 func_80178BF8();
extern void func_8012A828(s32, s32);
extern s32 func_8018766C(s32 arg0, s32 arg1);
extern void func_8012A828(s32 a0, s32 a1);
extern s32 func_8012BD14(s32 a0);
extern s32 func_8018739C(void);
extern s32 func_80188D1C(void *);
extern s32 func_80178BF8(void);
extern short D_801C3890;
extern s32 func_80178BF8();
extern short D_801C37E8;
extern s32 func_8018766C(s32 arg0, s32 arg1);
extern s32 func_8018766C(s32 arg0, s32 arg1);
extern s32 func_8018766C(s32 arg0, s32 arg1);
extern s32 func_8018766C(s32 a0, s32 a1);
extern void func_8012A828(s32, s32);
extern void func_8012A828(s32, s32);
extern s32 func_8018766C(s32 arg0, s32 arg1);
extern s32 func_8012BD14(s32 a0);
extern s32 func_80178BF8();
extern void func_80172710(void);
extern s32 func_8018739C(void);
extern s32 func_80188D1C(void *);
extern s32 func_8012BD14(s32 a0);
extern s32 func_80178BF8();
extern void func_80172710(void);
extern s32 func_8018739C(void);
extern s32 func_80188D1C(void *);
extern s32 func_8018766C(s32 arg0, s32 arg1);
s32 aF801856A8(void *a0) __asm__("func_801856A8");
extern void func_8012A828(s32, s32);
extern short D_801C37E8;
extern void func_8012A828(s32, s32);
extern void func_8012C218(void *arg0);
extern s32 func_8012E544(s32 arg0);
extern void func_8012A828(s32, s32);
extern short D_801C37E8;
extern short D_801C3890;

void func_8018617C(s32 arg0) {
    s32 temp;
    if (*(s32 *)(arg0 + 0xCC) == 0) {
        *(s32 *)(arg0 + 0xCC) = func_8012E544(0xAA);
        return;
    }
    temp = *(s32 *)(arg0 + 0xCC);
    switch (*(s16 *)(arg0 + 0xFC)) {
    case 0:
        break;
    case 1:
        func_8012A828(arg0, (s32)&D_801C37E8);
        break;
    case 2:
        func_8012A828(arg0, (s32)&D_801C3890);
        break;
    case 3:
        func_8012C218((void *)arg0);
        return;
    }
    *(u16 *)(arg0 + 0xFC) = 0;
    if (*(u16 *)(arg0 + 0x34) == 0) {
        *(u16 *)(arg0 + 6) = *(u16 *)(temp + 6) - 0x40;
        *(u16 *)(arg0 + 0xA) = *(u16 *)(temp + 0xA);
        *(u16 *)(arg0 + 0xE) = *(u16 *)(temp + 0xE) + 0x40;
        *(u16 *)(*(s32 *)(arg0 + 0x20) + 0x12) = *(u16 *)(*(s32 *)(temp + 0x20) + 0x12);
    }
}
