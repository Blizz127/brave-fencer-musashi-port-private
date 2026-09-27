#include "psx_types.h"

/* Exact matched stream for the bounded callback-initialization diagnostic. */

/* Initialization returns a dispatch address for the caller to install.
 * Callback words and this pointer-bearing ABI are PS1-width, not host-width. */
typedef s32 (*ChannelDispatch)(s32, s32);
extern s32 func_80042F8C(s32, s32);
extern void func_80042E08(void);
extern void func_80043034(void *, s32);
extern s32 func_800425B0(s32, void (*)(void));
extern u32 D_8006CBC4[];
extern volatile u32 *D_8006CBC0;

ChannelDispatch func_80042DB8(void) {
    func_80043034(D_8006CBC4, 8);
    *D_8006CBC0 = 0;
    func_800425B0(3, func_80042E08);
    return func_80042F8C;
}
