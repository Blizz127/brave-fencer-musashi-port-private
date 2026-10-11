/* sc03_0001: func_8017EA58 from Druthulu/BFM-decomp
 * src/ov_SC03_001/ov_SC03_001_jr_8017AE2C.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0001 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef int s32;
extern s32 func_80012A60(s32 a0, s32 a1);
extern u16 func_801487F4(s32 *a0);
extern u16 func_80148800(s32 *a0);
extern void func_8012A568(void (*a0)(void));
extern s32 func_80012A60(s32 a0, s32 a1);
extern u16 func_801487F4(s32 *a0);
extern u16 func_80148800(s32 *a0);
extern s32 func_80012A60(s32 a0, s32 a1);

void func_8017EA58(void *a0, u8 *a1)
{
    extern s32 D_80126B58;
    extern s16 D_8018D828[];
    s32 frame_pad[1];
    u8 dir;
    s32 lim;
    s32 flags;
    s32 held;
    s32 cur;
    dir = *a1;
    held = ((s32(*)(s32 *))func_801487F4)(&D_80126B58);
    cur = ((s32(*)(s32 *))func_80148800)(&D_80126B58);
    *(s16 *)((s32)a0 + 0x9C) = 0x5B;
    lim = 0;
    if (cur & 3) {
        lim = 0x555;
        flags = cur;
        *(s16 *)((s32)a0 + 0xA2) = 8;
    } else if (*(s16 *)((s32)a0 + 0xA2) == 0) {
        if (held & 3) {
            lim = 0x555;
            flags = held;
            *(s16 *)((s32)a0 + 0x9C) = 0x2D;
        }
    } else {
        *(s16 *)((s32)a0 + 0xA2) = *(s16 *)((s32)a0 + 0xA2) - 1;
    }
    if (lim != 0) {
        if (flags & 1) {
            dir = (dir - 1) & 7;
        } else if (flags & 2) {
            dir = (dir + 1) & 7;
        }
        if ((s16)func_80012A60(*(s16 *)((s32)a0 + 0x1A), D_8018D828[dir]) < lim) {
            *a1 = dir;
        }
    }
    *(s16 *)((s32)a0 + 0x22) = D_8018D828[*a1];
}
