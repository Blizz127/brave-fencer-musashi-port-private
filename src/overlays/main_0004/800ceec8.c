/* Clean-room re-derivation from the retail disassembly only (B28): MAIN.CD
 * member 0004 (intro movie overlay) state dispatcher, called every frame from
 * 80010F80. Indexes the handler table 800D3598 with the state u16 800B99E4. */
#include "psx_types.h"

extern u16 D_800B99E4;
extern void (*D_800D3598[])(void);

void func_800CEEC8(void) {
    D_800D3598[D_800B99E4]();
}
