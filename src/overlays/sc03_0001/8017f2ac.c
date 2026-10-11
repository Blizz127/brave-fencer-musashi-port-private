/* sc03_0001: func_8017F2AC from Druthulu/BFM-decomp
 * src/ov_SC03_001/ov_SC03_001_jr_8017AE2C.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0001 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef int s32;
extern void func_8012A568(void (*a0)(void));
void func_8017F368(u16 *a0, s32 a1);

void func_8017F2AC(u16 *a0, s32 a1)
{
    extern u16 D_800B99DA;
    extern u8 D_801918EC[];
    u8 arr[4];
    s32 t;
    s32 q;
    q = 0x50;
    if (D_801918EC[D_800B99DA & 0xF] == 0) {
        q = 0x60;
    }
    a1 += 1;
    t = q * a1;
    q = t / 32;
    arr[0] = q;
    arr[1] = q;
    arr[2] = q / 2;
    arr[3] = 0;
    if (*(s16 *)((char *)a0 + 6) == -1) {
        return;
    }
    do {
        func_8017F368(a0, *(s32 *)arr);
        a0 = (u16 *)((char *)a0 + 8);
    } while (*(s16 *)((char *)a0 + 6) != -1);
}
