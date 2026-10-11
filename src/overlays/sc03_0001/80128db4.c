/* sc03_0001: func_80128DB4 from Druthulu/BFM-decomp
 * src/ov_SC03_001/ov_SC03_001.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0001 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned int u32;
typedef short s16;
typedef int s32;
extern void func_80018450(s32 a0, s32 a1);
extern void func_800183E0(s32 a0);
extern void func_80018450(s32 a0, s32 a1);
extern void func_800183E0(s32 a0);

s32 func_80128DB4(s32 a0, s32 *a1) {
    s32 base = a1[0];
    s16 cnt = *(s16 *)((u8 *)a1 + 6);
    if (cnt == 0) {
        return 1;
    }
    cnt = cnt - 1;
    *(s16 *)((u8 *)a1 + 6) = cnt;
    if (cnt > 0) {
        return 0;
    }
    {
        s16 idx = *(s16 *)((u8 *)a1 + 4);
        u32 flags = *(u32 *)(base + idx * 8 + 4);
        if ((flags & 0xC0) == 0xC0) {
            *(s16 *)((u8 *)a1 + 6) = 0;
            return 1;
        }
        if ((flags & 0x80) != 0) {
            *(s16 *)((u8 *)a1 + 4) = 0;
        } else {
            *(s16 *)((u8 *)a1 + 4) = idx + 1;
        }
        *(s16 *)((u8 *)a1 + 6) =
            *(u32 *)(base + *(s16 *)((u8 *)a1 + 4) * 8 + 4) & 0x3F;
        if (a0 != 0) {
            func_80018450(a0, *(s32 *)(base + *(s16 *)((u8 *)a1 + 4) * 8));
        } else {
            func_800183E0(*(s32 *)(base + *(s16 *)((u8 *)a1 + 4) * 8));
        }
        return 0;
    }
}
