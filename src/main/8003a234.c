/* Main-exec range [8003A234,8003A3D8) from the SLUS executable.
 * SHA256(span)=3d54a6a2f02394ae122f754b990b20ed428ad447d17cd0b9b662a0e894ebc1b7.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8003A234 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"

typedef struct {
     u8 *ptr;
     u8 pad_004[0x1D0 - 0x004];
     s32 unk1D0;
     u8 pad_1D4[0x1E4 - 0x1D4];
     s16 unk1E4;
     s16 unk1E6;
     u8 pad_1E8[0x1F9 - 0x1E8];
     u8 unk1F9;
} func_8003A234_Ctx;

void func_8003A234(func_8003A234_Ctx *a0) {
    u8 *a2 = a0->ptr;
    u8 v1;

    a0->ptr = a2 + 1;
    v1 = *a2;

    switch (v1) {
    case 0x20:
        a0->ptr = a2 + 3;
        break;

    case '/':
        a0->ptr = a2 + 2;
        a0->unk1F9 = 1;
        break;

    case 'Q':
        {
            register s32 num __asm__("$4");
            s32 den;
            s32 b3;
            s32 b4;
            s32 q;

            a0->ptr = a2 + 2;
            den = a2[1];
            if (den != 3) {
                a0->unk1F9 = 1;
                break;
            }
            num = 0x3938700;
            a0->ptr = a2 + 3;
            den = a2[2];
            a0->ptr = a2 + 4;
            b3 = a2[3];
            a0->ptr = a2 + 5;
            b4 = a2[4];
            den = den << 16;
            den += b3 << 8;
            den += b4;
            q = num / den;
            a0->unk1E4 = (s16)q;
            a0->unk1D0 = q * a0->unk1E6;
        }
        break;

    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 'T':
    case 0x58:
    case 0x59:
    case 0x7F:
        {
            register u8 *p __asm__("$3") = a0->ptr;
            u8 *np = p + 1;
            a0->ptr = np;
            {
                register s32 byte __asm__("$5") = p[0];
                a0->ptr = np + byte;
            }
        }
        break;

    case 0:
        a0->ptr = a2 + 2;
        {
            register s32 b1 __asm__("$5") = a2[1];
            if (b1 != 2) {
                a0->unk1F9 = 1;
                break;
            }
        }
        a0->ptr = a2 + 4;
        break;

    default:
        a0->unk1F9 = 1;
        break;
    }
}
