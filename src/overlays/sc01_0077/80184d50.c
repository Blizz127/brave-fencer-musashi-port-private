/* sc01_0077: func_80184D50 from Druthulu/BFM-decomp
 * src/ov_SC01_077/ov_SC01_077_jr_80183CF4.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc01_0077 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef int s32;
typedef struct { u8 b[8]; } Blk8;
typedef struct { short a, b, c; } SV3;
typedef struct {
    s32 op;
    union {
        s32 w;
        void *p;
        s16 h[2];
        u16 uh[2];
    } a;
} Cmd_80178D40;
extern void func_8012A568(void (*a0)(void));
extern void func_8012F214(s32 a0, s32 a1, s32 a2);
extern void func_8012C218(void *a0);
extern void func_8012C218(void *a0);
extern void func_8012F214(s32 a0, s32 a1, s32 a2);
extern void func_8012C218(void *a0);
extern u8 D_80197514[];
extern u8 D_8018AFB0[];

void func_80184D50(s32 *self)
{
    s32 *tgt = (s32 *)*(s32 *)((s32)self + 0x64);
    SV3 out;
    if (*(s16 *)((s32)self + 0xFE) == 0x7FFF) {
        *(s16 *)((s32)self + 0xFE) =
            *(u16 *)(*(s32 *)((s32)self + 0x20) + 0x12);
    }
    if (*(s16 *)((s32)self + 0xFC) !=
        *(s16 *)(*(s32 *)((s32)self + 0x64) + 0x36)) {
        func_8012C218(self);
        return;
    }
    *(Blk8 *)(*(s32 *)((s32)self + 0x20) + 0x10) =
        *(Blk8 *)(*(s32 *)((s32)tgt + 0x20) + 0x10);
    if (*(s32 *)(*(s32 *)((s32)self + 0x64) + 0x90) != (s32)D_80197514) {
        *(s16 *)(*(s32 *)((s32)self + 0x20) + 0x12) =
            *(u16 *)((s32)self + 0xFE);
        *(s32 *)((s32)self + 0x4) =
            *(s32 *)(*(s32 *)((s32)self + 0x64) + 0x4);
        *(s32 *)((s32)self + 0x8) =
            *(s32 *)(*(s32 *)((s32)self + 0x64) + 0x8);
        *(s32 *)((s32)self + 0xC) =
            *(s32 *)(*(s32 *)((s32)self + 0x64) + 0xC);
    } else {
        func_8012F214(*(s32 *)((s32)self + 0x64), (s32)D_8018AFB0, (s32)&out);
        *(s16 *)((s32)self + 0x6) = out.a;
        *(s16 *)((s32)self + 0xA) = out.b;
        *(s16 *)((s32)self + 0xE) = out.c;
    }
    *(Blk8 *)(*(s32 *)((s32)self + 0x20) + 0x18) =
        *(Blk8 *)(*(s32 *)((s32)tgt + 0x20) + 0x18);
    *(u16 *)(*(s32 *)((s32)self + 0x20) + 0x2C) =
        *(u16 *)(*(s32 *)((s32)tgt + 0x20) + 0x2C);
    *(s32 *)(*(s32 *)((s32)self + 0x20) + 0x4) =
        *(s32 *)(*(s32 *)((s32)tgt + 0x20) + 0x4);
}
