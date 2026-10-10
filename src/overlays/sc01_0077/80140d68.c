/* sc01_0077: func_80140D68 from Druthulu/BFM-decomp
 * src/ov_SC01_077/ov_SC01_077.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc01_0077 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
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
typedef struct { s16 x; s16 y; } Hw4;
typedef struct { u16 f0; s16 f2; } Prim4;
typedef struct {
        u32 *ot;
        u32 pad[4];
    } Env_800D29F8;
typedef struct { u32 addr : 24; u32 len : 8; } PTag_80140D68;
extern short D_800B9A02;
extern short D_800B9A02;
extern short D_800B9A02;
extern short D_800B9A02;
extern Hw4 D_8011516A[];
extern short D_800B9A02;
extern short D_800B9A02;
extern Hw4 D_8011516A[];
extern Hw4 D_8011516A[];
extern short D_800B9A02;

s32 *func_80140D68(out, src, idx, dx, ofs)
    s32 *out;
    Prim4 *src;
    s16 idx;
    s32 dx;
    s16 ofs;
{
    extern Hw4 D_8011516A[];
    extern Env_800D29F8 D_800AE7BC[];
    register u32 mhi __asm__("$8");
    s16 *q;
    s32 a;
    out[0] = 0x04000000;
    *((u8 *)out + 0xC) = 0x70;
    *((u8 *)out + 0xD) = 0x10;
    mhi = 0x64808080;
    out[1] = mhi;
    *(u16 *)((u8 *)out + 0xE) = 0x4056;
    dx -= 0xD;
    q = (s16 *)(ofs * 2 + (s32)src);
    a = (u16)q[0] + (u16)D_8011516A[idx].x;
    a += dx;
    *(s16 *)((u8 *)out + 0x8) = a;
    *(s16 *)((u8 *)out + 0xA) = q[1] - 4;
    *(s16 *)((u8 *)out + 0x12) = 0x10;
    *(s16 *)((u8 *)out + 0x10) = 0x10;
    ((PTag_80140D68 *)out)->addr = ((PTag_80140D68 *)((D_800AE7BC[*(u16 *)&D_800B9A02].ot) + 2))->addr;
    ((PTag_80140D68 *)((D_800AE7BC[*(volatile u16 *)&D_800B9A02].ot) + 2))->addr = (u32)out;
    return out + 5;
}
