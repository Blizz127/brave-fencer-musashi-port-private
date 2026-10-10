/* Overlay range [80159A20,80159B08) from MAIN.CD member 0012.
 * SHA256(span)=ec17af79e892e6ec87c54fffc47f024ea68f664a10448a8b3510cda0f643a9b5.
 * Word export for the native seam (m2c produced no draft). */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80159A20 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_8014900C(s32 *a0);
extern void func_80150B28(int param_1);
extern void func_8015126C(u16 *p);
extern void func_80158638(void *a0);
extern void func_80158638(void*);
extern void func_8015126C(unsigned short *);
extern void func_8014900C(int *a0);

void func_80159A20(unsigned char *param_1)
{

    extern void (*D_8018925C[])(unsigned char *);
    typedef unsigned short u16;
    typedef unsigned int u32;
    typedef int s32;
    typedef unsigned char u8;

    func_80150B28((int)param_1); /* a0 passes through (retail) */
    ((void (*)(unsigned char *))func_80158638)(param_1);
    ((void (*)(u8 *))func_8015126C)(param_1);
    ((void (*)(u8 *))func_8014900C)(param_1);
    D_8018925C[*(u16 *)param_1 & 0x7fff](param_1);
    *(u32 *)(param_1 + 0x44) |= 0x8000000;
    switch (*(u16 *)param_1) {
    case 2:
    case 3:
    case 0xb:
    case 0xc:
        goto mask;
    default:
        return;
    case 0x19:
        if (param_1[0xdd] != 1) {
            if (param_1[0xdd] == 4) {
                goto mask;
            }
            return;
        }
        if (*(u16 *)(param_1 + 2) == 3) {
            goto mask;
        }
        return;
    }
mask:
    *(u32 *)(param_1 + 0x44) &= 0xf7ffffff;
}
