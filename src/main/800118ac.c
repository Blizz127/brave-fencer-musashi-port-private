/* Exact retail word export for [800118AC,80011928); EXE and assembly verified. */
#include "psx_types.h"
typedef struct {
    u8 pad[0xA3B4];
    u16 state;
    u16 substate;
    u16 other;
    u16 timer;
    u16 counter;
    u16 flags;
} StartState;
extern StartState D_800AF630;
/* GCC register binding retains the retail base-address evaluation without
 * adding a local stack slot. No assembly instructions are emitted. */
register StartState *start_state asm("$2");
void func_800118AC(void) {
    start_state = &D_800AF630;
    start_state->state++;
    start_state->timer = 0;
    start_state->flags = 0;
    start_state->substate = 0;
    start_state->counter = 0;
}

