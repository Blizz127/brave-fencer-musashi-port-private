#include "psx_types.h"


/* Decompiled from retail and verified byte-exact with gcc-2.7.2-psx -O2. */
typedef struct {
    u8 pad00[0x10];
    void (*reset10)(s32);
} GraphicsDispatch;

extern u8 D_8007278A;
extern u8 D_8007412C[];
extern void (*D_80072784)(const char *, s32);
extern GraphicsDispatch *D_80072780;
extern void func_8005C29C(u8 *, s32, u32);

void func_80059658(s32 argument) {
    u8 *state = &D_8007278A;
    s32 value = argument;
    if (state[0] >= 2)
        D_80072784((const char *)D_8007412C, argument);
    if (value == 0)
        func_8005C29C(state + 0x6a, -1, 0x14);
    D_80072780->reset10(value ? 0x03000000 : 0x03000001);
}
