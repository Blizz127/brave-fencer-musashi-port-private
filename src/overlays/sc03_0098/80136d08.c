/* sc03_0098: func_80136D08 from Druthulu/BFM-decomp
 * src/ov_SC03_098/ov_SC03_098_jr_80135D20.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0098 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed char s8;
typedef short s16;
typedef int s32;
extern void func_8012A5F8(void (*a0)(void), s32 a1);
extern s32 func_80058C6C(s32, void *);
extern s32 func_8004955C(s32, s32, s32 *, s32 *);
extern void *func_80010A08(s32);
extern void func_8004914C(void *);
extern void func_800491AC(void *);
extern s32 D_800A651C;
extern u8 D_800AF648;
extern s16 D_800B9A02;
extern void func_8004914C(void *a0);
extern void func_800491AC(void *a0);
extern s32 func_8004955C(s32 a0, s32 a1, s32 *a2, s32 *a3);
extern s32 func_80058C6C(s32, void *);
extern s32 func_8004955C(s32, s32, s32 *, s32 *);
extern void func_80058EB0(void *);
extern void *func_80010A08(s32);
extern void func_8004914C(void *);
extern void func_800491AC(void *);
extern s32 D_800A651C;
extern u8 D_800AF648;
extern s16 D_800B9A02;

void func_80136D08(s32 arg0, s32 arg1) {
    s32 sp10;
    s32 sp14;
    s32 temp_v0;
    s32 temp_v0_2;
    void *buf;
    func_8004914C(&D_800AF648);
    func_800491AC(&D_800AF648);
    buf = func_80010A08(0x14);
    func_80058EB0(buf);
    *((u8 *)buf + 0xE) = 0xFF;
    *((u8 *)buf + 0x4) = 0xFF;
    *((u8 *)buf + 0xD) = 0x80;
    *((u8 *)buf + 0x5) = 0x80;
    *((u8 *)buf + 0xC) = 0x80;
    *((u8 *)buf + 0x6) = 0x80;
    temp_v0 = func_8004955C(arg0, (s32)buf + 8, &sp10, &sp14);
    temp_v0_2 = func_8004955C(arg1, (s32)buf + 0x10, &sp10, &sp14);
    temp_v0 = ((temp_v0 + temp_v0_2) >> 3) * 4;
    func_80058C6C(*(s32 *)((s8 *)&D_800A651C + ((u16)D_800B9A02 * 0x14)) + temp_v0, buf);
}
