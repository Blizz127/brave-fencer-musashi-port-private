/* sc03_0001: func_801855CC from Druthulu/BFM-decomp
 * src/ov_SC03_001/ov_SC03_001_jr_80184F64.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0001 retail words (gcc-2.7.2 -O2). */
typedef unsigned short u16;
typedef int s32;
extern void func_8012A568(void (*a0)(void));
extern void func_80172710(void);
extern s32 func_80178BF8();
extern s32 func_8012BD14(s32 a0);
extern s32 func_8018739C(void);
extern s32 func_80188D1C(void *);
extern s32 func_80178BF8(void);
extern s32 func_80178BF8();
extern s32 func_8012BD14(s32 a0);
extern s32 func_80178BF8();
extern void func_80172710(void);
extern s32 func_8018739C(void);
extern s32 func_80188D1C(void *);

s32 func_801855CC(void *a0)
{
    u16 st;
    st = *(u16 *)(*(s32 *)((s32)a0 + 0x64) + 0x2);
    switch (st) {
    case 6:
    case 0xC:
        if (((s32 (*)(void *))func_8018739C)(a0) == 0) {
            func_80188D1C(*(void **)((s32)a0 + 0x64));
            return 0;
        }
        break;
    case 2:
    case 9:
        if (*(u16 *)(*(s32 *)((s32)a0 + 0x64) + 0x34) != 2) {
            return 0;
        }
        if (func_8012BD14(*(s32 *)((s32)a0 + 0x64)) > 0x4000) {
            return 0;
        }
        break;
    default:
        return 0;
    }
    *(u16 *)(*(s32 *)((s32)a0 + 0x64) + 0x2) =
        *(u16 *)(*(s32 *)((s32)a0 + 0x64) + 0x2) + 1;
    func_80178BF8();
    return (s32)func_80172710;
}
