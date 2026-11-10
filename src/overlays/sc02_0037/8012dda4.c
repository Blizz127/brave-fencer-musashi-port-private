/* sc02_0037: func_8012DDA4 from Druthulu/BFM-decomp
 * src/ov_SC02_037/ov_SC02_037.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc02_0037 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef int s32;
typedef struct Entry_8012DDA4 {
    u16 active;
    unsigned char pad[0x10C - 2];
} Entry_8012DDA4;
extern u8 D_80126720[];
extern u8 D_80126720[];
extern u8 D_80126720[];

s32 func_8012DDA4()
{
    extern u8 D_80126720[];
    extern Entry_8012DDA4 * D_801C83CC;
    extern Entry_8012DDA4 * D_801C83C8;
    Entry_8012DDA4 *p;
    Entry_8012DDA4 *end = ((Entry_8012DDA4 *)D_80126720);
    while (D_801C83CC != end) {
        p = D_801C83CC;
        if (p->active != 0 && p != D_801C83C8) {
            D_801C83CC = p + 1;
            return p;
        }
        D_801C83CC++;
    }
    D_801C83CC = 0;
    return 0;
}
