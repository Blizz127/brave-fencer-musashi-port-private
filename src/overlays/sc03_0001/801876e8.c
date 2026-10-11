/* sc03_0001: func_801876E8 from Druthulu/BFM-decomp
 * src/ov_SC03_001/ov_SC03_001_jr_801870B0.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0001 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef int s32;
typedef struct {
    u8 f0, f1, f2, f3;
    struct { s16 a, b, c, d, e, g; } ent[16];
} Blk_8016CF04;
typedef struct {
    u8 f0, f1, f2, f3;
    struct { s16 a, b, c, d, e, g; } ent[16];
} Blk_8016CF04_8016CF04;
typedef struct {
    s32 op;
    union {
        s32 w;
        void *p;
        s16 h[2];
        u16 uh[2];
    } a;
} Cmd_80178D40;
typedef struct {
    s16 f0, f1, f2, f3;
} Vec4s_801876E8;
extern void func_8012A568(void (*a0)(void));
extern void func_8012F214(s32 a0, s32 a1, s32 a2);
extern void func_8012F2E8(s32 a0, s32 a1, s32 a2);
extern s32 func_8012CB64(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4);
s32 aF801848DC(void *a0) __asm__("func_801848DC");
extern void func_8012F214(s32 a0, s32 a1, s32 a2);
extern s32 func_8012CEB0(s32 a0, s32 a1, s32 a2);

void func_801876E8(void *a0, s32 a1)
{
    Vec4s_801876E8 loc_10;
    Vec4s_801876E8 loc_18;
    Vec4s_801876E8 loc_20;
    loc_10.f0 = *(s16 *)((u8 *)a0 + 0x6);
    loc_10.f1 = *(s16 *)((u8 *)a0 + 0xA);
    loc_10.f2 = *(s16 *)((u8 *)a0 + 0xE);
    loc_18.f0 = 0;
    loc_18.f1 = 0;
    loc_18.f2 = (s16)(-a1);
    ((void(*)(s32, s32, s32))func_8012F214)((s32)a0, (s32)&loc_18, (s32)&loc_20);
    func_8012CEB0((s32)&loc_10, (s32)&loc_20, 0);
}
