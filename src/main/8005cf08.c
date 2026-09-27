#include "psx_types.h"

/* Exact SYS1 EnterCriticalSection wrapper [8005CF08,8005CF18). */
__asm__(
    ".set noreorder\n"
    ".globl func_8005CF08\n"
    ".type func_8005CF08, @function\n"
    "func_8005CF08:\n"
    "addiu $a0, $zero, 1\n"
    "syscall\n"
    "jr    $ra\n"
    "nop\n"
    ".size func_8005CF08, .-func_8005CF08\n"
    ".set reorder\n"
);

