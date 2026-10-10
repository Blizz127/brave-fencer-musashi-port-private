/* sc03_0098: func_8012A988 from Druthulu/BFM-decomp
 * src/ov_SC03_098/ov_SC03_098.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0098 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef int s32;
extern void func_8012AAAC();
extern int func_8012ACE0(void *a0);
extern void func_8012AAAC();
extern void func_8012AAAC();
extern void func_8012AAAC();
extern s32 func_8012ACE0(void *a0);
extern void func_8012AAAC();
void func_8012AAAC(void *arg0);

void func_8012A988(u8 *a0) {
    s32 v0;
    s16 t;
    u16 flags;
    *(u16 *)(a0 + 0x72) = *(u16 *)(a0 + 0x72) & 0x9FFF;
    if (*(u16 *)(a0 + 0x0) == 0) return;
    if (*(u8 *)(a0 + 0xC1) == 0x11) return;
    t = *(s16 *)(a0 + 0x98);
    if (t == 0) return;
    t = t - 1;
    *(s16 *)(a0 + 0x98) = t;
    if (t > 0) return;
    if (*(s32 *)(a0 + 0x90) == 0) return;
    flags = *(u16 *)(a0 + 0x72);
    if (flags & 0x400) {
        v0 = *(s32 *)(a0 + 0x94) - 1;
        *(s32 *)(a0 + 0x94) = v0;
        if (v0 < 0) {
            *(s32 *)(a0 + 0x94) = 1;
            *(u16 *)(a0 + 0x72) = *(u16 *)(a0 + 0x72) & 0xFBFF;
        }
    } else if (flags & 0x200) {
        v0 = *(s32 *)(a0 + 0x94) - 1;
        *(s32 *)(a0 + 0x94) = v0;
        if (v0 < 0) {
            s32 idx = func_8012ACE0(a0);
            if (*(s16 *)((idx * 8) + *(s32 *)(a0 + 0x90) + 4) != -1) {
                *(s32 *)(a0 + 0x94) = 0;
                *(s16 *)(a0 + 0x98) = 0;
                return;
            }
            *(s32 *)(a0 + 0x94) = idx - 1;
        }
    } else {
        *(s32 *)(a0 + 0x94) = *(s32 *)(a0 + 0x94) + 1;
    }
    ((void (*)(u8 *))func_8012AAAC)(a0);
}
