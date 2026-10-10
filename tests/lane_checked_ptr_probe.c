/* Unit test for pc_port/lane_checked_ptr.c: in-range addresses come back
 * unchanged; out-of-range ones reach musashi_strict_abort with the PC. */
#include <setjmp.h>
#include <stdio.h>
#include <string.h>
#include "lane_checked_ptr.h"

static jmp_buf g_jb;
static unsigned g_pc;
static int g_aborts;
void musashi_strict_abort(const char *seam, const char *routine, uint32_t guest_pc)
{
    (void)routine;
    if (strcmp(seam, "lane_checked_ptr") != 0) { fprintf(stderr, "bad seam %s\n", seam); return; }
    g_pc = guest_pc; g_aborts++;
    longjmp(g_jb, 1);
}

static int expect_ok(uint64_t a)
{
    void *p = musashi_lane_checked_ptr(a, (int32_t)0x8017DD04u);
    if ((uint64_t)(uintptr_t)p != a) { fprintf(stderr, "in-range %llx changed\n", (unsigned long long)a); return 1; }
    return 0;
}

static int expect_abort(uint64_t a)
{
    int before = g_aborts;
    if (setjmp(g_jb) == 0) {
        (void)musashi_lane_checked_ptr(a, (int32_t)0x8017DD04u);
        fprintf(stderr, "out-of-range %llx did not abort\n", (unsigned long long)a);
        return 1;
    }
    if (g_aborts != before + 1 || g_pc != 0x8017DD04u) { fprintf(stderr, "abort pc %08x\n", g_pc); return 1; }
    return 0;
}

int main(void)
{
    int bad = 0;
    bad += expect_ok(0x80000000ull);
    bad += expect_ok(0x800AA60Cull);
    bad += expect_ok(0x800AA60Cull + (1ull << 14));
    bad += expect_ok(0x801FFFF8ull);
    bad += expect_abort(0x801FFFF9ull);
    bad += expect_abort(0x80200000ull);
    bad += expect_abort(0x800AA60Cull + (0xFFFFull << 14));
    bad += expect_abort(0x7FFFFFFFull);
    bad += expect_abort(0ull);
    bad += expect_abort(0xFFFFFFFF80000000ull);
    printf("lane_checked_ptr: %s\n", bad ? "FAIL" : "ok");
    return bad != 0;
}
