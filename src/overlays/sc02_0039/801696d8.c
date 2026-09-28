/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_801696D8 - byte-exact against retail at -O2 (tools/register_match.py). */
extern s32 func_80017DC4(void *a0, void *a1);
extern s32  func_80017758(void *a0, void *a1);
extern s32  func_80017DC4(void *a0, void *a1);
extern void func_80048EAC(void *a0, void *a1);
extern s32 func_80017758(void *a0, void *a1);

void func_801696D8(s32 a0, s32 a1) {
    void *arg0 = (void *)a0;
    void *arg1 = (void *)a1;
    u8 buf[0x5C];                
    u8 *p = buf + 0x38;           
    u8 v1;
    u8 v0;
    u8 a1b;
    u16 t2c;
    u8 *q = buf + 0x58;           
    *(s16 *)(buf + 0x00) = 8;     
    *(s16 *)(buf + 0x10) = 0;     
    *(s16 *)(buf + 0x08) = 0;     
    *(s16 *)(buf + 0x18) = -8;    
    *(s16 *)(buf + 0x0a) = 2;     
    *(s16 *)(buf + 0x1a) = 0;     
    *(s16 *)(buf + 0x02) = 0;     
    *(s16 *)(buf + 0x12) = -2;    
    *(s16 *)(buf + 0x1c) = 0;     
    *(s16 *)(buf + 0x14) = 0;     
    *(s16 *)(buf + 0x0c) = 0;     
    *(s16 *)(buf + 0x04) = 0;     
    v1 = *(u8 *)((u8 *)arg0 + 0x30);
    *(s32 *)(buf + 0x30) = 0x50000000;   
    v0 = (u8)(v1 >> 1);
    a1b = (u8)(v0 >> 2);
    *(u8 *)(buf + 0x2a) = v1;      
    *(u8 *)(buf + 0x26) = v1;      
    *(u8 *)(buf + 0x2e) = v0;      
    *(u8 *)(buf + 0x22) = v0;      
    *(u8 *)(buf + 0x29) = v0;      
    *(u8 *)(buf + 0x25) = v0;      
    *(u8 *)(buf + 0x28) = v0;      
    *(u8 *)(buf + 0x24) = v0;      
    *(u8 *)(buf + 0x2d) = a1b;     
    *(u8 *)(buf + 0x21) = a1b;     
    *(u8 *)(buf + 0x2c) = a1b;     
    *(u8 *)(buf + 0x20) = a1b;     
    t2c = *(u16 *)((u8 *)arg0 + 0x2c);
    *(u16 *)(q + 0x02) = t2c;   
    *(u16 *)(q + 0x00) = t2c;   
    func_80017DC4(q, p);
    func_80048EAC(arg1, p);
    *(s32 *)(buf + 0x4c) = (s32)*(s16 *)((u8 *)arg0 + 6);    
    *(s32 *)(buf + 0x50) = (s32)*(s16 *)((u8 *)arg0 + 0xa);  
    *(s32 *)(buf + 0x54) = (s32)*(s16 *)((u8 *)arg0 + 0xe);  
    func_80017758(buf + 0x00, p);
    *(s16 *)(buf + 0x00) = 2;     
    *(s16 *)(buf + 0x10) = 0;     
    *(s16 *)(buf + 0x08) = 0;     
    *(s16 *)(buf + 0x18) = -2;    
    *(s16 *)(buf + 0x0a) = 8;     
    *(s16 *)(buf + 0x1a) = 0;     
    *(s16 *)(buf + 0x02) = 0;     
    *(s16 *)(buf + 0x12) = -8;    
    func_80017758(buf + 0x00, p);
}
