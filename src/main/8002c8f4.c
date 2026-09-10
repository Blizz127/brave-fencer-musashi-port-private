#include "psx_types.h"

/* Retail source-backed startup initialization overlay [8002C8F4,8002CC4C).
 * It calls unresolved game/overlay services; this preserves only the audited
 * PS1 body and is not a native startup binding. */
__asm__(
    ".set noreorder\n"
    ".globl func_8002C8F4\n"
    ".type func_8002C8F4, @function\n"
    "func_8002C8F4:\n"
    ".size func_8002C8F4, .-func_8002C8F4\n"
    ".set reorder\n"
);
