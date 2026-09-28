/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80128ED8 - byte-exact against retail at -O2 (tools/register_match.py). */


s32 func_80128ED8(s32 param_1, s32 *param_2) {
    register s32 iVar4 __asm__("$8");    
    register s32 cnt   __asm__("$2");    
    register s32 cc    __asm__("$3");    
    register s32 idx   __asm__("$3");    
    register s32 idc   __asm__("$7");    
    u32 uVar3;
    s32 frame_pad[4];                    
    __asm__ __volatile__("" : : "r"(&frame_pad) : "memory");
    iVar4 = *param_2;
    cnt = *(s16 *)((s32)param_2 + 6);
    if (cnt == 0) {
        return 1;
    }
    cc = cnt;
    __asm__ __volatile__("" : "=r"(cc) : "0"(cc));    
    cnt = cc - 1;
    *(s16 *)((s32)param_2 + 6) = (s16)cnt;
    if (cnt * 0x10000 < 1) {
        idx = *(s16 *)((s32)param_2 + 4);
        __asm__ __volatile__("" : "=r"(idx) : "0"(idx));    
        uVar3 = *(u32 *)(idx * 8 + iVar4 + 4);
        idc = idx;
        if ((uVar3 & 0xc0) == 0xc0) {
            *(s16 *)((s32)param_2 + 6) = 0;
            return 1;
        }
        if ((uVar3 & 0x80) != 0) {
            *(s16 *)((s32)param_2 + 4) = 0;
        } else {
            cnt = idc + 1;                        
            *(s16 *)((s32)param_2 + 4) = cnt;
        }
        *(u16 *)((s32)param_2 + 6) =
            (u16)(*(u32 *)((s16)param_2[1] * 8 + iVar4 + 4) & 0x3f);
        *(u16 *)(param_1 + 0x28) = *(u16 *)((s16)param_2[1] * 8 + iVar4);
        *(u16 *)(param_1 + 0x2a) = *(u16 *)((s16)param_2[1] * 8 + iVar4 + 2);
    }
    return 0;
}
