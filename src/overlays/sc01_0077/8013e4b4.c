/* sc01_0077: func_8013E4B4 from Druthulu/BFM-decomp
 * src/ov_SC01_077/ov_SC01_077.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc01_0077 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef int s32;
typedef struct {
    u16 guard;
    u16 pad;
    u16 field;
    u8 rest[14];
} Ent;
extern void *D_801274CC;
extern s32 func_8012C750(s32 a0);
extern u8 *D_801274C8;
extern void *D_801274CC;

void func_8013E4B4(void) {
    u8 *s0;
    Ent *p;
    s32 i;
    s0 = D_801274C8;
    if (s0 != 0) {
        if (*(u16 *)(s0 + 6) != 0) {
            do {
                func_8012C750(s0);
                s0 += 0x14;
            } while (*(u16 *)(s0 + 6) != 0);
        }
    }
    s0 = (u8 *)D_801274CC;
    if (s0 != 0) {
        p = (Ent *)(s0 + 6);
        for (i = 0; p[i].guard != 0; i++) {
            p[i].field &= 0x7FFF;
        }
    }
}
