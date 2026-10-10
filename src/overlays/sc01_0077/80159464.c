/* sc01_0077: func_80159464 from Druthulu/BFM-decomp
 * src/ov_SC01_077/ov_SC01_077_jr_801588CC.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc01_0077 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef int s32;
typedef struct { s16 id; s16 val; } Entry;
struct Entry {
    u8 f0;
    u8 f1;
    u8 pad[0x1e];
};
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
extern s16 D_800B9A08;
extern s32 func_80029A94(s32);
extern s16 D_800B9A08;
extern s32 func_80029A94(s32);
extern Entry D_80188EF4[];

s32 func_80159464(void) {
    Entry *e;
    e = D_80188EF4;
    while (e->id != 0) {
        if (D_800B9A08 == e->id) {
            return e->val;
        }
        e++;
    }
    if (func_80029A94(1) != 0) {
        goto ret0;
    }
    if (func_80029A94(0) != 0) {
        goto ret0;
    }
    return -1;
ret0:
    return 0;
}
