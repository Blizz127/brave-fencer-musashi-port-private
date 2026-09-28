/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80169584 - byte-exact against retail at -O2 (tools/register_match.py). */
extern s32  func_80017758(void *a0, void *a1);
extern s32 func_80017758(void *a0, void *a1);

void func_80169584(s32 param_1) {
    u8 buf[0x60];    
    s32 v1;
    s32 v0;
    register s32 s0 __asm__("$16");    
    *(s16 *)(buf + 0x00) = 7;      
    *(s16 *)(buf + 0x18) = -7;     
    *(s16 *)(buf + 0x0a) = 2;      
    *(s16 *)(buf + 0x10) = 0;      
    *(s16 *)(buf + 0x08) = 0;      
    *(s16 *)(buf + 0x1a) = 0;      
    *(s16 *)(buf + 0x02) = 0;      
    *(s16 *)(buf + 0x12) = -2;     
    *(s16 *)(buf + 0x1c) = 0;      
    *(s16 *)(buf + 0x14) = 0;      
    *(s16 *)(buf + 0x0c) = 0;      
    *(s16 *)(buf + 0x04) = 0;      
    *(u8 *)(buf + 0x22) = 0;       
    *(u8 *)(buf + 0x20) = 0;       
    *(u8 *)(buf + 0x2e) = 0;       
    *(u8 *)(buf + 0x2c) = 0;       
    *(u8 *)(buf + 0x2d) = 0;       
    *(u8 *)(buf + 0x21) = 0;       
    if (*(s32 *)(param_1 + 0x2c) == 0) {
        v1 = -0x40 - (*(s32 *)(param_1 + 0x1c) << 4);
        v0 = ((u32)(v1 & 0xff)) >> 2;
        *(s8 *)(buf + 0x29) = v1;     
        *(s8 *)(buf + 0x25) = v1;     
        *(s8 *)(buf + 0x2a) = v0;     
        *(s8 *)(buf + 0x26) = v0;     
    } else {
        v1 = -0x40 - (*(s32 *)(param_1 + 0x1c) << 4);
        v0 = ((u32)(v1 & 0xff)) >> 2;
        *(s8 *)(buf + 0x29) = v1;     
        *(s8 *)(buf + 0x25) = v1;     
        *(s8 *)(buf + 0x2a) = v1;     
        *(s8 *)(buf + 0x26) = v1;     
    }
    *(s8 *)(buf + 0x28) = v0;         
    *(s8 *)(buf + 0x24) = v0;         
    __asm__ __volatile__("" ::: "memory");
    *(s32 *)(buf + 0x30) = 0x50000000;    
    s0 = param_1 + 0x38;
    *(s32 *)(param_1 + 0x4c) = (s32)*(s16 *)(param_1 + 0x06);
    *(s32 *)(param_1 + 0x50) = (s32)*(s16 *)(param_1 + 0x0a);
    *(s32 *)(param_1 + 0x54) = (s32)*(s16 *)(param_1 + 0x0e);
    func_80017758(buf + 0x00, (void *)s0);
    *(s16 *)(buf + 0x02) = 7;      
    *(s16 *)(buf + 0x1a) = -7;     
    *(s16 *)(buf + 0x08) = 2;      
    *(s16 *)(buf + 0x12) = 0;      
    *(s16 *)(buf + 0x0a) = 0;      
    *(s16 *)(buf + 0x18) = 0;      
    *(s16 *)(buf + 0x00) = 0;      
    *(s16 *)(buf + 0x10) = -2;     
    func_80017758(buf + 0x00, (void *)s0);
}
