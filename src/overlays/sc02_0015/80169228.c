/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80169228 - byte-exact against retail at -O2 (tools/register_match.py). */
extern s32 func_80017DC4(void *a0, void *a1);
extern s32  func_80017758(void *a0, void *a1);
extern s32  func_80017DC4(void *a0, void *a1);
extern void func_80048EAC(void *a0, void *a1);

s32 func_80169228(void)
{
    register s32 a0v __asm__("$4");
    s32 arg0 = a0v;
    u8 buf[0x60];                
    register u8 *p __asm__("$16");    
    s32 col;
    s16 base;
    s16 v;
     
    *(s16 *)(buf + 0x08) = -5;    
    *(s16 *)(buf + 0x00) = -5;    
    *(s16 *)(buf + 0x18) = 5;     
    *(s16 *)(buf + 0x10) = 5;     
    *(s16 *)(buf + 0x12) = -5;    
    *(s16 *)(buf + 0x02) = -5;    
    *(s16 *)(buf + 0x1a) = 5;     
    *(s16 *)(buf + 0x0a) = 5;     
    *(s16 *)(buf + 0x1c) = 0;     
    *(s16 *)(buf + 0x14) = 0;     
    *(s16 *)(buf + 0x0c) = 0;     
    *(s16 *)(buf + 0x04) = 0;     
     
    if ((*(u32 *)(arg0 + 0x2c) & 2) == 0) {
        col = -0x40 - (*(s32 *)(arg0 + 0x1c) << 4);
        *(u8 *)(buf + 0x21) = *(u8 *)(buf + 0x22) =
        *(u8 *)(buf + 0x25) = *(u8 *)(buf + 0x26) =
        *(u8 *)(buf + 0x29) = *(u8 *)(buf + 0x2a) =
        *(u8 *)(buf + 0x2d) = *(u8 *)(buf + 0x2e) = col;
        *(u8 *)(buf + 0x20) = *(u8 *)(buf + 0x24) =
        *(u8 *)(buf + 0x28) = *(u8 *)(buf + 0x2c) = col;
    } else {
        col = -0x40 - (*(s32 *)(arg0 + 0x1c) << 4);
        *(u8 *)(buf + 0x20) = *(u8 *)(buf + 0x24) =
        *(u8 *)(buf + 0x2a) = *(u8 *)(buf + 0x2e) = 0x20;
        *(u8 *)(buf + 0x21) = *(u8 *)(buf + 0x25) =
        *(u8 *)(buf + 0x29) = *(u8 *)(buf + 0x2d) = col;
        *(u8 *)(buf + 0x29) = *(u8 *)(buf + 0x2d) = 0x20;
    }
    *(s32 *)(buf + 0x30) = 0x50000000;    
    base = 0x800;
    if (*(u32 *)(arg0 + 0x2c) & 1) base = 0x4cc;
    v = base + (*(s32 *)(arg0 + 0x1c) << 7);
    *(u16 *)(buf + 0x5c) = v;    
    *(u16 *)(buf + 0x5a) = v;    
    *(u16 *)(buf + 0x58) = v;    
    p = buf + 0x38;
    func_80017DC4(buf + 0x58, p);
    func_80048EAC((void *)(arg0 + 0x38), p);
    *(s32 *)(buf + 0x4c) = (s32)*(s16 *)(arg0 + 6);     
    *(s32 *)(buf + 0x50) = (s32)*(s16 *)(arg0 + 0xa);   
    *(s32 *)(buf + 0x54) = (s32)*(s16 *)(arg0 + 0xe);   
    func_80017758(buf + 0x00, p);
     
    *(s16 *)(buf + 0x00) = -7;    
    *(s16 *)(buf + 0x10) = 0;     
    *(s16 *)(buf + 0x08) = 0;     
    *(s16 *)(buf + 0x18) = 7;     
    *(s16 *)(buf + 0x1a) = 0;     
    *(s16 *)(buf + 0x02) = 0;     
    *(s16 *)(buf + 0x0a) = 7;     
    *(s16 *)(buf + 0x12) = -7;    
    func_80017758(buf + 0x00, p);
}
