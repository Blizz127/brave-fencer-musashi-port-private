/* func_80016714 (STARTUP_ENVIRONMENT_CLEAR, a zeroing memset) through the
 * formatter's host-intrinsic route, the one guest code takes whenever the
 * lane does not run the matched C (startup runs, guest calls from native
 * code). Retail leaves the loop-end constant -1 in v0 on every path
 * (src/main/80016714.c), and the table dispatcher at main_0012 80140420
 * branches on it (`bnez v0`) through func_80142838's tail chain. The
 * intrinsic must leave that v0, clear exactly [a0, a0 + a1), return to ra
 * and keep its refusals with v0 untouched. v1 is NOT restored (retail leaves
 * -1 there when a1 >= 4; no reader is known): the probe pins that too.
 * Synthetic RAM, no lane registered, no retail words needed. */
#include "../pc_port/mips_formatter.c"
#include <assert.h>
#include <stdio.h>
#include <string.h>

enum { RA = 0x80012340u, V0_SENTINEL = 0x5EB7C0DEu, V1_SENTINEL = 0x0BADF00Du, FILL = 0xA5u };

static MusashiBootMemory memory;

static uint32_t g_v0_seed = V0_SENTINEL;   /* also run with 0: the value that flips the 80140420 `bnez v0` */

static void setup(FormatterCpu *cpu, uint32_t dst, uint32_t count) {
    memset(cpu, 0, sizeof *cpu);
    memset(memory.bytes, FILL, sizeof memory.bytes);
    cpu->pc = STARTUP_ENVIRONMENT_CLEAR;
    cpu->npc = STARTUP_ENVIRONMENT_CLEAR + 4u;
    cpu->r[4] = dst;
    cpu->r[5] = count;
    cpu->r[2] = g_v0_seed;
    cpu->r[3] = V1_SENTINEL;
    cpu->r[31] = RA;
}

static void cleared(uint32_t dst, uint32_t count) {
    FormatterCpu cpu;
    uint32_t off = dst & (MUSASHI_RAM_SIZE - 1u), i;
    setup(&cpu, dst, count);
    assert(formatter_call(&memory, &cpu, NULL, NULL) == 1);
    assert(cpu.r[2] == 0xFFFFFFFFu);                 /* retail v0 on every path */
    assert(cpu.r[2] != 0);                           /* so `bnez v0` (80140420) takes retail's branch */
    assert(cpu.r[3] == V1_SENTINEL);                 /* v1 not restored (disclosed) */
    assert(cpu.pc == RA && cpu.npc == RA + 4u);
    for (i = 0; i < count; ++i) assert(memory.bytes[off + i] == 0);
    assert(memory.bytes[off - 1u] == FILL);
    assert(memory.bytes[off + count] == FILL);
}

static void refused(uint32_t dst, uint32_t count) {
    FormatterCpu cpu;
    setup(&cpu, dst, count);
    assert(formatter_call(&memory, &cpu, NULL, NULL) == 0);
    assert(cpu.r[2] == g_v0_seed && cpu.r[3] == V1_SENTINEL);     /* a refusal writes nothing */
    assert(cpu.pc == STARTUP_ENVIRONMENT_CLEAR);
}

int main(void) {
    static const uint32_t seeds[2] = {V0_SENTINEL, 0u};
    unsigned k;
    assert(g_lane_count == 0);                       /* the host-intrinsic route, not the lane */
    for (k = 0; k < 2; ++k) {
        g_v0_seed = seeds[k];
        cleared(0x80100001u, 0);                     /* a1 = 0: no write, v0 still -1 (delay slot at 8001671C) */
        cleared(0x80100001u, 3);                     /* a1 < 4: byte loop only */
        cleared(0x80100000u, 4);                     /* aligned: one word, no head or tail */
        cleared(0x80100003u, 38);                    /* 1 head byte, 9 words, 1 tail byte */
        cleared(0x80100000u, 64);                    /* aligned words only */
        cleared(0x800747C0u, 8);                     /* the 8001903C record clear (musashi_boot_call_8001903c) */
        refused(0x80100000u, 0x80000000u);           /* count beyond INT32_MAX */
        refused(0x1F800000u, 16u);                   /* scratchpad: no checked RAM span */
        refused(0x801FFFF8u, 64u);                   /* runs past the end of RAM */
    }
    puts("ENVIRONMENT_CLEAR_V0_PASS cases=9 seeds=2 (v0 5EB7C0DE, 0)");
    return 0;
}
