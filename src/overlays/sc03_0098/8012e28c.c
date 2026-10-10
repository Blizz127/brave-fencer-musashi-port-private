/* sc03_0098: func_8012E28C from Druthulu/BFM-decomp
 * src/ov_SC03_098/ov_SC03_098_jr_8012ACE0.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0098 retail words (gcc-2.7.2 -O2). */
typedef unsigned short u16;
typedef signed char s8;
typedef short s16;
typedef int s32;
extern s32 func_80058C6C(s32, void *);
extern void *func_80010A08(s32);
extern s32 D_800A651C;
extern s16 D_800B9A02;
extern s32 func_80058C6C(s32, void *);
extern void *func_80010A08(s32);
extern s32 D_800A651C;
extern s16 D_800B9A02;
extern s32 func_80058C6C(s32, void *);
extern void *func_80010A08(s32);
extern s32 func_80058B40(s32, s32, s32, s32);
extern s32 func_8005A600(s32, s32, s32, s32, s32);
extern s32 D_800A651C;
extern s16 D_800B9A02;

void func_8012E28C(s32 arg0, s32 arg1) {
    void *temp_v0;
    s32 temp_v1;
    s32 base;
    if (arg0 > 0) {
        base = *(s32 *)((s8 *)&D_800A651C + ((u16)D_800B9A02 * 0x14)) + (arg0 * 4);
        temp_v0 = func_80010A08(0xC);
        temp_v1 = func_80058B40(0, arg1, 0, 0);
        func_8005A600((s32)temp_v0, 0, 0, (u16)temp_v1, 0);
        func_80058C6C(base, temp_v0);
    }
}
