/* sc02_0037: func_8012D3B4 from Druthulu/BFM-decomp
 * src/ov_SC02_037/ov_SC02_037.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc02_0037 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed char s8;
typedef short s16;
typedef int s32;
extern s32 func_80058C6C(s32, void *);
extern s32 func_8004955C(s32, s32, s32 *, s32 *);
extern void func_80058E9C(void *);
extern void *func_80010A08(s32);
extern void func_8004914C(void *);
extern void func_800491AC(void *);
extern s32 D_800A651C;
extern u8 D_800AF648;
extern s16 D_800B9A02;

void func_8012D3B4(s32 arg0, s32 arg1, s32 arg2) {
    s32 sp10;
    s32 sp14;
    s32 temp_v0_2;
    void *temp_v0;
    temp_v0 = func_80010A08(0x10);
    (*(s32 *)((s8*)(temp_v0)+(4))) = arg2;
    func_80058E9C(temp_v0);
    func_8004914C(&D_800AF648);
    func_800491AC(&D_800AF648);
    temp_v0_2 = func_8004955C(arg0, temp_v0 + 8, &sp10, &sp14);
    if ((temp_v0_2 > 0) && (sp14 >= 0) && (func_8004955C(arg1, temp_v0 + 0xC, &sp10, &sp14) > 0) && (sp14 >= 0)) {
        func_80058C6C(*(s32 *)((s8 *)&D_800A651C + ((u16)D_800B9A02 * 0x14)) + (temp_v0_2 * 4), temp_v0);
    }
}
