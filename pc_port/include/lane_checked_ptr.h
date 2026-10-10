#ifndef LANE_CHECKED_PTR_H
#define LANE_CHECKED_PTR_H
#include <stdint.h>
/* KSEG0 main RAM, 2 MB, identity-mapped on the host. */
#define MUSASHI_LANE_RAM_BASE 0x80000000ull
#define MUSASHI_LANE_RAM_END 0x80200000ull
/* The widest lane access through one pointer (a 64-bit load/store). */
#define MUSASHI_LANE_ACCESS_SLACK 8ull
int musashi_lane_addr_in_ram(uint64_t addr);
void *musashi_lane_checked_ptr(uint64_t addr, int32_t lane_pc);
#endif
