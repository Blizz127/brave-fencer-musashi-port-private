/* sc03_0001: func_8015E5B0 from Druthulu/BFM-decomp
 * src/ov_SC03_001/ov_SC03_001_jr_8015C32C.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0001 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef int s32;
struct obj;
struct obj {
    u8 pad0[0x4];
    s16 unk4;
    u8 pad6[0x2];
    s32 unk8;
};
extern void func_80015978(s32 a0, s32 *a1);
extern void func_8014C4AC(s32 a0, s32 a1, s32 a2, s16 *a3, s32 a4);
extern s32 func_80133784(s32 a0, void *a1, s32 a2);
extern s32 func_80133784(s32 a0, void *src, s32 dst);
extern void func_8014C4AC(s32 a0, s32 a1, s32 a2, s16 *a3, s32 a4);
extern s32 func_80133784(s32 a0, void *a1, s32 a2);
extern void func_80015978(s32 a0, s32 *a1);
extern void func_8014C4AC(s32 a0, s32 a1, s32 a2, s16 *a3, s32 a4);

void func_8015E5B0(u8 *self)
{
    u8 *obj;
    s16 src[4];
    s16 dst[4];
    obj = *(u8 **)(self + 0x18C);
    if (obj == 0) {
        return;
    }
    src[0] = *(u16 *)(self + 0x6);
    src[1] = *(u16 *)(self + 0xA) - 0x14;
    src[2] = *(u16 *)(self + 0xE);
    dst[0] = *(u16 *)(obj + 0x6);
    dst[1] = *(u16 *)(obj + 0xA);
    dst[2] = *(u16 *)(obj + 0xE);
    if (func_80133784(0, src, (s32)dst) != 0) {
        *(u16 *)(obj + 0x6) = dst[0];
        *(u16 *)(obj + 0xA) = dst[1];
        *(u16 *)(obj + 0xE) = dst[2];
    }
    func_80015978((s32)(obj + 4), (s32 *)src);
    src[3] = 0;
    func_8014C4AC((s32)obj, 0x1C, 0, src,
                  *(s16 *)(*(u8 **)(self + 0x20) + 0x12));
    *(s32 *)(self + 0x18C) = 0;
}
