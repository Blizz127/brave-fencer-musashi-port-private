/* Main-exec range [8002C320,8002C3B0) from the SLUS executable.
 * SHA256(span)=bc45b3ac220bb74d8607ba4fbc091accf73c21383711723e353df44dfc53606d.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"

/* func_8002C320 - byte-exact against retail at -O2 (tools/register_match.py). */

extern u8 D_80075AC0[];

u32 func_8002C320(void) {
    register u32 result __asm__("$8") = 0;
    int count = 0;
    register u32 bit1 __asm__("$14") = 1;
    register u32 bit2 __asm__("$13") = 2;
    register u32 shift __asm__("$7") = 0;
    u8 *base = D_80075AC0;
    u8 *ptr_data = base + 0x10;
    u8 *ptr_check = base + 0x2;
    u8 *ptr_byte = base;
    u32 sum;
    u32 masked;
    int j;
    u16 val;

    for (; count < 4; count++) {
        if (*ptr_byte != 0) {
            val = *(u16 *)ptr_check;
            sum = 0;

            for (j = 0; j < 0x70; j++) {
                sum += ptr_data[j];
            }
            masked = sum & 0xFFFF;

            if (val == masked) {
                result |= bit1 << shift;
            } else {
                result |= bit2 << shift;
            }
        }

        shift += 8;
        ptr_data += 0x80;
        ptr_check += 0x80;
        ptr_byte += 0x80;
    }

    return result;
}
