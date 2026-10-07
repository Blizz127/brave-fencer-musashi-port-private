/* Strict-native lane dispatch probe (MUSASHI_STRICT_NATIVE builds only).
 *
 * Synthetic lane entries, no retail data: checks that
 * musashi_native_lane_invoke runs a lane entry, that a guest call made from
 * native code reaches another lane entry through the strict lane-table
 * dispatch, that a PC outside the table is reported as a miss (0), that a
 * guest call to a PC outside the table stops the process with the strict
 * abort (SIGABRT, not an interpreter fallback), and that the frame driver's
 * own PadGetState replacement answers "no pad" without platform services. */
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

#include "musashi_native_frame_driver.h"
#include "musashi_native_lane.h"

#define PC_LEAF   0x80020000u
#define PC_CALLER 0x80020100u
#define PC_BAD    0x80020200u
#define PC_MISS   0x80030000u

static int leaf(MusashiNativeLaneCall *call) {
    call->r[2] = call->r[4] + 1u;
    return 1;
}

static int caller(MusashiNativeLaneCall *call) {
    uint32_t arg = 41u;
    call->r[2] = musashi_native_guest_call(PC_LEAF, 1u, &arg, NULL);
    return 1;
}

static int bad(MusashiNativeLaneCall *call) {
    call->r[2] = musashi_native_guest_call(PC_MISS, 0u, NULL, NULL);
    return 1;
}

int main(void) {
    MusashiNativeLaneEntry table[16] = {
        {PC_LEAF, 0, leaf, "leaf", 1, 1, 0},
        {PC_CALLER, 0, caller, "caller", 0, 1, 0},
        {PC_BAD, 0, bad, "bad", 0, 1, 0},
    };
    size_t n = 3, extra;
    int aliased = 0, status = 0;
    uint32_t v0 = 0, port = 0;
    pid_t child;
    const MusashiStartupPrefixDevice devices = {0};
    MusashiBootMemory *memory = musashi_native_lane_map_guest(sizeof *memory, &aliased);
    if (!memory) {
        fprintf(stderr, "native_frame_driver_probe: no lane window; skipped\n");
        return 77;
    }
    extra = musashi_frame_driver_lane_entries(table + n, 16u - n);
    n += extra < 16u - n ? extra : 16u - n;
    if (musashi_native_lane_install(table, n) != (int)n) {
        fprintf(stderr, "install refused\n");
        return 1;
    }
    if (musashi_native_lane_invoke(memory, &devices, PC_CALLER, NULL, 0, 0x801FFF00u, &v0) != 1 ||
        v0 != 42u) {
        fprintf(stderr, "lane dispatch: expected 42, got %u\n", (unsigned)v0);
        return 1;
    }
    if (musashi_native_lane_invoke(memory, &devices, PC_MISS, NULL, 0, 0x801FFF00u, &v0) != 0) {
        fprintf(stderr, "a PC outside the table was not a miss\n");
        return 1;
    }
    v0 = 99u;
    if (musashi_native_lane_invoke(memory, &devices, 0x8005D184u, &port, 1, 0x801FFF00u, &v0) != 1 ||
        v0 != 0u) {
        fprintf(stderr, "PadGetState replacement: expected 0 (no pad), got %u\n", (unsigned)v0);
        return 1;
    }
    fflush(NULL);
    child = fork();
    if (child == 0) {
        (void)musashi_native_lane_invoke(memory, &devices, PC_BAD, NULL, 0, 0x801FFF00u, &v0);
        _exit(0);   /* reaching here means the miss fell through */
    }
    if (child < 0 || waitpid(child, &status, 0) != child ||
        !WIFSIGNALED(status) || WTERMSIG(status) != SIGABRT) {
        fprintf(stderr, "guest call to a PC outside the table did not stop strictly\n");
        return 1;
    }
    printf("native_frame_driver_probe: ok (dispatch, miss, strict stop, pad replacement)\n");
    return 0;
}
