/* Complete SC02 retail span [80146360,801463A0).
 * Ahead leaf.
 * Words from pinned SC02.CD member31 PAC0 decode (live-guest identity).
 */
#include "psx_types.h"


extern void (*D_80186760[])(void *);
extern u8 D_80126BA4;
extern s32 D_80126B58;

void func_80146360(void) {
    D_80186760[D_80126BA4](&D_80126B58);
}
