/* sc01_0077: func_8012DDA4 from Druthulu/BFM-decomp
 * src/ov_SC01_077/ov_SC01_077_jr_8012ACE0.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc01_0077 retail words (gcc-2.7.2 -O2). */
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
    extern Entry_8012DDA4 * D_801D94A4;
    extern Entry_8012DDA4 * D_801D94A0;
    Entry_8012DDA4 *p;
    Entry_8012DDA4 *end = ((Entry_8012DDA4 *)D_80126720);
    while (D_801D94A4 != end) {
        p = D_801D94A4;
        if (p->active != 0 && p != D_801D94A0) {
            D_801D94A4 = p + 1;
            return p;
        }
        D_801D94A4++;
    }
    D_801D94A4 = 0;
    return 0;
}
