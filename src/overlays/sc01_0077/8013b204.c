/* sc01_0077: func_8013B204 from Druthulu/BFM-decomp
 * src/ov_SC01_077/ov_SC01_077_jr_801380E0.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc01_0077 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef int s32;
extern void func_8012A568(void (*a0)(void));
extern void func_8012A5F8(void (*a0)(void), s32 a1);
extern s32 D_800A651C;
extern s16 D_800B9A02;
extern short D_800B9A02;
extern short D_800B9A02;
extern short D_800B9A02;
extern s32 D_800A651C;
extern void func_8013B274(s32 a0, s32 a1, void *a2);
extern void func_8013B274(s32 a0, s32 a1, void *a2);
extern short D_800B9A02;
extern s32 D_800A651C;
void func_8013B274(s32 a0, s32 a1, void *a2);

void func_8013B204(s32 a0, s32 a1)
{
    void *a2;
    s32 idx;
    a2 = a1;
    if (*(s16 *)((u8 *)a2 + 0xC) != 0) {
        return;
    }
    if (*(s16 *)a2 != 2) {
        return;
    }
    a2 = (u8 *)a2 + 8;
    idx = (u16)D_800B9A02;
    func_8013B274(
        (&D_800A651C)[idx * 5] + ((u16)(*(u16 *)((u8 *)a0 + 0x1A)) << 2),
        *(s16 *)((u8 *)a0 + 0x1C),
        a2);
}
