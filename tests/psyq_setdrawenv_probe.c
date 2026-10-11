/* Same-input differential of the SetDrawEnv HLE (bfm_psyq_SetDrawEnv) against
 * the retail libgpu code at 0x8005A658, run on the interpreter as a test-only
 * oracle from the developer's own EXE (extracted/disc/files/SLUS_007.26; no
 * retail bytes are compiled in or committed).
 *
 * Each case writes a pseudo-random DRAWENV (negative and oversized clip
 * rectangles, every dtd/dfe/isbg combination, random texture windows and
 * colours), the libgpu GPU-type byte D_80072788 (0..3) and VRAM limits
 * D_8007278C/E (1024x512, 1024x1024), then runs SetDrawEnv(dr, env) both ways
 * from the same RAM. All 2 MB of RAM must then be byte-identical, except the
 * retail call's own stack frame below STACK_TOP.
 *
 * Exit 0 when every case agrees; 1 on any difference; 77 when the EXE or the
 * host window at 0x80000000 is unavailable. */
#define _GNU_SOURCE
#include "musashi_boot_memory.h"
#include "musashi_native_lane.h"
#include "psyq/bfm_psyq_compat.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>

#ifndef MAP_FIXED_NOREPLACE
#define MAP_FIXED_NOREPLACE 0x100000
#endif

enum { SET_DRAW_ENV = 0x8005A658u, GPU_TYPE = 0x80072788u, LIM_W = 0x8007278Cu, LIM_H = 0x8007278Eu };
enum { DR = 0x801F0000u, ENV = 0x801F0100u, STACK_TOP = 0x801FF000u, STACK_SPAN = 0x100u };

static MusashiBootMemory *g_mem;
static uint8_t *g_image, *g_ref;
static uint32_t rng_state;
static uint32_t rng(void) {
    rng_state ^= rng_state << 13; rng_state ^= rng_state >> 17; rng_state ^= rng_state << 5;
    return rng_state;
}
static uint8_t *host(uint32_t a) { return g_mem->bytes + (a & 0x1FFFFFu); }
static void put8(uint32_t a, uint8_t v) { *host(a) = v; }
static void put16(uint32_t a, uint16_t v) { put8(a, (uint8_t)v); put8(a + 1u, (uint8_t)(v >> 8)); }

static int16_t pick16(void) {
    switch (rng() % 6u) {
    case 0: return (int16_t)(rng() % 64u) - 32;            /* around 0, negatives */
    case 1: return (int16_t)(rng() % 1100u);                /* inside / just past the limits */
    case 2: return (int16_t)(1000 + rng() % 100u);
    case 3: return (int16_t)(500 + rng() % 40u);
    default: return (int16_t)rng();                        /* anything */
    }
}

static void seed(uint32_t salt) {
    uint32_t i;
    memcpy(g_mem->bytes, g_image, MUSASHI_RAM_SIZE);
    rng_state = salt * 2654435761u | 1u;
    for (i = 0; i < 0x200u; ++i) put8(DR + i, (uint8_t)rng());
    for (i = 0; i < 10u; ++i) put16(ENV + 2u * i, (uint16_t)pick16());  /* clip, ofs, tw */
    put16(ENV + 20u, (uint16_t)rng());                                     /* tpage */
    put8(ENV + 22u, (uint8_t)(rng() % 3u ? rng() & 1u : rng()));          /* dtd */
    put8(ENV + 23u, (uint8_t)(rng() % 3u ? rng() & 1u : rng()));          /* dfe */
    put8(ENV + 24u, (uint8_t)(rng() % 3u ? rng() & 1u : rng()));          /* isbg */
    put8(ENV + 25u, (uint8_t)rng()); put8(ENV + 26u, (uint8_t)rng()); put8(ENV + 27u, (uint8_t)rng());
    put8(GPU_TYPE, (uint8_t)(rng() % 4u));
    put16(LIM_W, 1024u);
    put16(LIM_H, rng() & 1u ? 1024u : 512u);
}

int main(int argc, char **argv) {
    FILE *file;
    uint8_t *exe;
    size_t exe_size;
    unsigned cases = 0, bad = 0, bg = 0, n;
    const char *fuzz = getenv("SETDRAWENV_PROBE_FUZZ");
    unsigned total = fuzz ? (unsigned)strtoul(fuzz, NULL, 0) : 3000u;
    if (argc != 2) { fprintf(stderr, "usage: %s SLUS_007.26\n", argv[0]); return 2; }
    file = fopen(argv[1], "rb");
    if (!file) { fprintf(stderr, "setdrawenv: EXE unavailable; NOT_RUN\n"); return 77; }
    exe = malloc(0x65000u);
    exe_size = exe ? fread(exe, 1, 0x65000u, file) : 0;
    fclose(file);
    g_mem = mmap((void *)(uintptr_t)MUSASHI_NATIVE_LANE_GUEST_BASE, sizeof(*g_mem),
                 PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS | MAP_FIXED_NOREPLACE, -1, 0);
    if (g_mem == MAP_FAILED || (uintptr_t)g_mem != MUSASHI_NATIVE_LANE_GUEST_BASE) {
        fprintf(stderr, "setdrawenv: host window at 0x80000000 unavailable; NOT_RUN\n");
        return 77;
    }
    if (!musashi_boot_map_exe(g_mem, exe, exe_size)) { fprintf(stderr, "setdrawenv: pinned EXE rejected\n"); return 1; }
    bfm_psyq_set_ram(g_mem->bytes, MUSASHI_RAM_SIZE);
    bfm_psyq_set_scratchpad(g_mem->scratchpad);
    g_image = malloc(MUSASHI_RAM_SIZE);
    g_ref = malloc(MUSASHI_RAM_SIZE);
    if (!g_image || !g_ref) return 1;
    memcpy(g_image, g_mem->bytes, MUSASHI_RAM_SIZE);

    for (n = 0; n < total; ++n) {
        uint32_t regs[32], r[32], i;
        const uint32_t args[2] = {DR, ENV};
        int same;
        seed(n + 1u);
        bg += *host(ENV + 24u) != 0;
        if (!musashi_native_lane_reference_call_regs(g_mem, SET_DRAW_ENV, args, 2, STACK_TOP, 0, regs)) {
            fprintf(stderr, "setdrawenv: case %u: retail oracle did not complete\n", n);
            return 1;
        }
        memcpy(g_ref, g_mem->bytes, MUSASHI_RAM_SIZE);
        seed(n + 1u);
        memset(r, 0, sizeof r);
        r[4] = DR; r[5] = ENV; r[29] = STACK_TOP; r[31] = 0xFFFFFFFFu;
        if (!bfm_psyq_SetDrawEnv(r)) {
            fprintf(stderr, "setdrawenv: case %u: HLE refused\n", n);
            ++bad; ++cases; continue;
        }
        /* the retail frame (sp-0x40..sp) is scratch the HLE does not use */
        for (i = 0; i < STACK_SPAN; ++i)
            g_ref[((STACK_TOP - STACK_SPAN) & 0x1FFFFFu) + i] = g_mem->bytes[((STACK_TOP - STACK_SPAN) & 0x1FFFFFu) + i];
        same = memcmp(g_ref, g_mem->bytes, MUSASHI_RAM_SIZE) == 0;
        if (!same) {
            ++bad;
            if (bad <= 5) {
                fprintf(stderr, "setdrawenv: case %u differs (gpu=%u isbg=%u)\n", n, *host(GPU_TYPE), *host(ENV + 24u));
                for (i = 0; i < 40u; i += 4u)
                    fprintf(stderr, "  dr+%02x retail %02x%02x%02x%02x hle %02x%02x%02x%02x\n", i,
                            g_ref[(DR & 0x1FFFFFu) + i + 3], g_ref[(DR & 0x1FFFFFu) + i + 2],
                            g_ref[(DR & 0x1FFFFFu) + i + 1], g_ref[(DR & 0x1FFFFFu) + i],
                            *host(DR + i + 3), *host(DR + i + 2), *host(DR + i + 1), *host(DR + i));
            }
        }
        ++cases;
    }
    printf("setdrawenv: cases=%u isbg=%u different=%u -> %s\n", cases, bg, bad, bad ? "DIFFERS" : "same");
    return bad ? 1 : 0;
}
