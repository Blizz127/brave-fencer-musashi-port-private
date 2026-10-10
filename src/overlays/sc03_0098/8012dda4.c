/* sc03_0098: func_8012DDA4 from Druthulu/BFM-decomp
 * src/ov_SC03_098/ov_SC03_098_jr_8012ACE0.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0098 retail words (gcc-2.7.2 -O2). */
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
    extern Entry_8012DDA4 * D_801C41AC;
    extern Entry_8012DDA4 * D_801C41A8;
    Entry_8012DDA4 *p;
    Entry_8012DDA4 *end = ((Entry_8012DDA4 *)D_80126720);
    while (D_801C41AC != end) {
        p = D_801C41AC;
        if (p->active != 0 && p != D_801C41A8) {
            D_801C41AC = p + 1;
            return p;
        }
        D_801C41AC++;
    }
    D_801C41AC = 0;
    return 0;
}
