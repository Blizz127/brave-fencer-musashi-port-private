/* sc03_0001: func_801758FC from Druthulu/BFM-decomp
 * src/ov_SC03_001/ov_SC03_001_jr_801734BC.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0001 retail words (gcc-2.7.2 -O2). */
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
typedef struct { u32 *f0; s32 pad[4]; } S_AE7BC_801758FC;
typedef struct { s32 g0; s32 pad[2]; } S_AF634_801758FC;
extern u8 D_8011F7A8;
extern s16 D_800B9A02;
extern u8 D_8011F7A8;
extern u8 D_8011F7A8;
extern u8 D_8011F7A8;
extern short D_800B9A02;
extern s16 D_800B9A02;
extern short D_800B9A02;
extern short D_800B9A02;

s32 func_801758FC(void)
{
    extern s16 D_800B9A02;
    extern S_AE7BC_801758FC D_800AE7BC[];
    extern S_AF634_801758FC D_800AF634[];
    extern u8 D_8011F7A8;
    u8 *p = (u8 *)&D_8011F7A8;
    u16 *q;
    u32 *ptr;
    u32 old;
    u32 *p2;
    q = (u16 *)&(*(u16 *)&D_800B9A02);
    ptr = D_800AE7BC[*q].f0;
    old = ptr[3];
    ptr[3] = (old & 0xff000000) | (*(u32 *)(p + *q * 4 + 0x30) & 0xffffff);
    __asm__("" ::: "memory");
    p2 = *(u32 **)(p + *q * 4 + 0x28);
    *p2 = (*p2 & 0xff000000) | (old & 0xffffff);
    {
        s32 acc = D_800AF634[*q].g0;
        s32 t = *(s32 *)(p + *q * 4 + 0x28) - 0x14;
        D_800AF634[*q].g0 = acc + ((*(s32 *)(p + *q * 4 + 0x30) - t) >> 2);
    }
}
