#include "psx_types.h"

/* Byte-exact recovery of the PS1 varargs home-area wrapper
 * [8005C604,8005C640). The caller-area stores are intentional: retail's
 * formatter consumes the words at SP+1C, including the format word at SP+18.
 * This source is oracle/decompilation code and is not a native binding. */
extern s32 func_8005C640(s32, const char *, s32 *);

/* This is the exact 15-word instruction stream emitted for this matched
 * function. It is retained beside the equivalent C so the native MIPS seam
 * can execute the same audited implementation without reading retail media or
 * creating a host-varargs companion. The macro is deliberately undefined in
 * retail and native C compilation. */

s32 func_8005C604(const char *format, s32 arg1, s32 arg2, s32 arg3) {
    s32 *arguments = &arg1;
    arguments[-1] = (s32)format;
    arguments[1] = arg2;
    arguments[2] = arg3;
    return func_8005C640(1, format, arguments);
}
