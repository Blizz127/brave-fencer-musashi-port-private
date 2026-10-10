/* sc03_0098: func_80131170 from Druthulu/BFM-decomp
 * src/ov_SC03_098/ov_SC03_098_jr_8012ACE0.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0098 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef short s16;
typedef int s32;
extern void func_8012A5F8(void (*a0)(void), s32 a1);
void func_8012B14C(s32 a0, s32 a1);
s32 func_8012BCCC(s32 a0);
extern void func_80131B14();
extern s32 func_80131A34(s32, s32);
extern void func_80131B14();
extern s32 func_80131A34(s32, s32);
extern s32 func_80131A34(s32 a0, s32 a1);
extern void func_80131B14();
extern s32 func_80131A34(s32, s32);
extern s32 func_8012BCCC(s32 a0);
extern s32 func_80131AC8(void *a0);
extern s32 func_8012BCCC(s32 a0);
extern s32 func_80131AC8(void *a0);
extern s32 func_80131A34(s32, s32);
extern s32 func_8012BCCC(s32);
extern s32 func_80131AC8(void *a0);
extern void func_80131B14();
extern s32 func_80131A34(s32 a0, s32 a1);
extern s32 func_80131A34(s32, s32);
extern void func_80131B14();
extern int func_80131A34(int a0, int a1);
s32 func_80131A34(s32 a0, s32 a1);
s32 func_80131AC8(void *a0);
void func_80131B14();

void func_80131170(s32 p, s32 b, s32 c) {
    extern u8 D_80185684[];
    func_80131B14();
    *(u8 *)(((u8 *)p) + 0xC2) = 0;
    *(u8 *)(((u8 *)p) + 0xC3) = 0;
    *(s16 *)(((u8 *)p) + 0x98) = 0;
    if (((u8 *)b) == 0) {
        ((u8 *)b) = D_80185684;
    }
    func_8012B14C((s32)((u8 *)p), (s32)((u8 *)b));
    *(s32 *)(((u8 *)p) + 0x1C) = 0;
    if (c != 0) {
        if (((s32(*)(s32, s32))func_80131A34)((s32)((u8 *)p), c) != 0) goto tail;
        if (((s32(*)(s32, s32))func_80131A34)((s32)((u8 *)p), 0x24) != 0) goto tail;
        *(s32 *)(((u8 *)p) + 0xC4) &= ~4;
        if (((s32(*)(s32, s32))func_80131A34)((s32)((u8 *)p), 0x20) != 0) {
            *(s32 *)(((u8 *)p) + 0xC4) |= 4;
        } else {
            *(s16 *)(((u8 *)p) + 0x98) = 0;
        }
    } else {
        if (((s32(*)(s32, s32))func_80131A34)((s32)((u8 *)p), 0x24) != 0) goto tail;
        *(s32 *)(((u8 *)p) + 0xC4) &= ~4;
        if (((s32(*)(s32, s32))func_80131A34)((s32)((u8 *)p), 0x20) != 0) {
            *(s32 *)(((u8 *)p) + 0xC4) |= 4;
        } else {
            *(s16 *)(((u8 *)p) + 0x98) = 0;
        }
    }
tail:
    if (*(s16 *)(((u8 *)p) + 0x76) > 0) {
        return;
    }
    if (((s32(*)(s32))func_8012BCCC)((s32)((u8 *)p)) <= 0x8FFF) {
        if (((s32(*)())func_80131AC8)(((u8 *)p), 0x32) != 0) return;
        ((s32(*)())func_80131AC8)(((u8 *)p), 0x33);
    } else {
        if (((s32(*)())func_80131AC8)(((u8 *)p), 0x33) != 0) return;
        ((s32(*)())func_80131AC8)(((u8 *)p), 0x32);
    }
}
