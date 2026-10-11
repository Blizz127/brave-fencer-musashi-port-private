/* sc03_0001: func_80188518 from Druthulu/BFM-decomp
 * src/ov_SC03_001/ov_SC03_001_jr_801870B0.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0001 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef int s32;
extern void func_8012A568(void (*a0)(void));
extern void func_8012F2E8(s32 a0, s32 a1, s32 a2);
extern s32 func_8012CB64(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4);
s32 aF801848DC(void *a0) __asm__("func_801848DC");

void func_80188518(s32 a0, s32 a1)
{
    extern u8 D_801202A0[];
    u8 *p = D_801202A0;
    u8 *end = p + 0x6480;
    if (p != end) {
        do {
            if (*(u16 *)p == 0x61 && *(s16 *)(p + 0x70) == a0) {
                *(s32 *)(p + 0xB0) = a1;
                return;
            }
            p += 0x10C;
        } while (p != end);
    }
}
