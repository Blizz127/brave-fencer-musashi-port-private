/* Independently re-derived from retail assembly; clean input set. */
#include "psx_types.h"

extern u8 D_80063906[];
extern s32 D_80078EF4;

u16 func_8002A9DC(void) {
    return *(u16 *)(D_80063906 + (D_80078EF4 * 0x10));
}
