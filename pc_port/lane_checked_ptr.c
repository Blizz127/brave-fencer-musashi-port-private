/* Strict (B28): run-time check for a native-lane integer->pointer conversion
 * the generator cannot bound (tools/native_lane_gen.py checked_inttoptr).
 * Guest RAM is mapped at its own address, so an address inside it is
 * returned unchanged. Anything else aborts strict-native, naming the lane
 * function's entry PC, before the host can touch memory outside the guest. */
#include <stdint.h>
#include "musashi_strict.h"
#include "lane_checked_ptr.h"

int musashi_lane_addr_in_ram(uint64_t addr)
{
    return addr >= MUSASHI_LANE_RAM_BASE &&
           addr + MUSASHI_LANE_ACCESS_SLACK <= MUSASHI_LANE_RAM_END;
}

void *musashi_lane_checked_ptr(uint64_t addr, int32_t lane_pc)
{
    if (!musashi_lane_addr_in_ram(addr))
        musashi_strict_abort("lane_checked_ptr", "address_outside_guest_ram", (uint32_t)lane_pc);
    return (void *)(uintptr_t)addr;
}
