#include "psx_types.h"

/* Exact input serial wait helper [8005E13C,8005E164), 10 retail words. */
__asm__(
    ".set noreorder\n"
    ".globl func_8005E13C\n"
    ".type func_8005E13C, @function\n"
    "func_8005E13C:\n"
    ".size func_8005E13C, .-func_8005E13C\n"
    ".set reorder\n"
);


