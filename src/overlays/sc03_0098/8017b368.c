/* sc03_0098: func_8017B368 from Druthulu/BFM-decomp
 * src/ov_SC03_098/ov_SC03_098_jr_8017AE2C.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0098 retail words (gcc-2.7.2 -O2). */
typedef unsigned short u16;
typedef unsigned int u32;
typedef short s16;
typedef int s32;
typedef struct {
    s32 op;
    union {
        s32 w;
        void *p;
        s16 h[2];
        u16 uh[2];
    } a;
} Cmd_80178D40;
typedef struct { s16 a, b, c, d; } SV4_8017B368;
typedef struct { SV4_8017B368 x, y; } Pair16_8017B368;
extern void func_8012A568(void (*a0)(void));
extern s16 D_801C5840;
extern s16 D_801C5424;
extern s16 D_801C5840;
void func_8017BA3C(s32 param_1, s32 param_2);

s32 func_8017B368(s32 param)
{
    extern void func_8017BA3C(s32 param_1, s32 param_2);
    extern void func_8012F214(s32 a0, s32 a1, s32 a2);
    extern SV4_8017B368 D_801C5444;
    extern SV4_8017B368 D_801C544C;
    extern s16 D_801C549C;
    extern s16 D_801C5494;
    extern u16 D_80188C60;
    SV4_8017B368 loc0;
    SV4_8017B368 loc1;
    u32 n = (u32)&D_801C5444;
    ((void (*)(void))func_8017BA3C)();
    if (n >= 0xB) {
        loc0 = *(SV4_8017B368 *)n;
        loc1 = D_801C544C;
    } else {
        s32 ax = (s32)&((Pair16_8017B368 *)&D_80188C60)[n].x;
        s32 ay = (s32)&((Pair16_8017B368 *)&D_80188C60)[n].y;
        func_8012F214(param, ax, (s32)&loc0);
        func_8012F214(param, ay, (s32)&loc1);
    }
    (*(SV4_8017B368 *)&D_801C549C) = loc0;
    (*(SV4_8017B368 *)&D_801C5494) = loc1;
    D_801C5840 = 1;
    D_801C5424 = 0;
}
