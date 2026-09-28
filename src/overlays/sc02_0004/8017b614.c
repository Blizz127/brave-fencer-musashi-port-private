/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8017B614 - byte-exact against retail at -O2 (tools/register_match.py). */
typedef struct { u8 b[8]; } Blk8_8017B614;
extern s32 D_80126990;
extern s32 D_80126994;
extern void func_8012A018(s32 a, s32 b);
extern s16 D_80196350;
extern s16 D_801961B4;

s32 func_8017B614(s32 param_1, s32 param_2)
{
    extern void func_8012F214(s32 a0, s32 a1, s32 a2);
    extern void func_80129CF8(void);
    extern s32 func_8017BE60(void *a0);
    extern u8 D_8018161C[];
    extern s16 D_8019622C;
    extern s16 D_8019622E;
    extern s16 D_80196230;
    extern s16 D_80196224;
    extern s16 D_80196226;
    extern s16 D_80196228;
    extern u8 D_8012694C;
    extern s32 D_80126998;
    extern s32 D_80126984;
    extern s32 D_80126988;
    extern s32 D_8012698C;

    u8 buf[16];

    if (((u32)param_2) >= 0xB) {
        register u8 *src __asm__("$16");
        __asm__ __volatile__("" : "=r"(src) : "0"((u8 *)((u32)param_2)));
        *(Blk8_8017B614 *)&buf[0] = *(Blk8_8017B614 *)src;
        *(Blk8_8017B614 *)&buf[8] = *(Blk8_8017B614 *)(src + 8);
    } else {
        s32 a1addr = (s32)&D_8018161C[((u32)param_2) * 0x10];
        s32 a2addr = (s32)&D_8018161C[((u32)param_2) * 0x10 + 8];
        func_8012F214(param_1, a1addr, (s32)&buf[0]);
        func_8012F214(param_1, a2addr, (s32)&buf[8]);
    }
    {
        s16 *p794 = &D_8019622C;
        s16 *p78C = &D_80196224;
        *(Blk8_8017B614 *)p794 = *(Blk8_8017B614 *)&buf[0];
        *(Blk8_8017B614 *)p78C = *(Blk8_8017B614 *)&buf[8];
        ((void(*)(s32, s32))func_8012A018)((s32)func_8017BE60, 0);
        {
            s32 v794, v796, v798, v78C, v78E, v790;
            D_8012694C = 0;
            v794 = *p794;
            v796 = D_8019622E;
            v798 = D_80196230;
            v78C = *p78C;
            v78E = D_80196226;
            v790 = D_80196228;
            __asm__ __volatile__("");
            D_80196350 = 1;
            D_801961B4 = 0x1E;
            D_80126990 = v794;
            D_80126994 = v796;
            D_80126998 = v798;
            D_80126984 = v78C;
            D_80126988 = v78E;
            D_8012698C = v790;
        }
        func_80129CF8();
    }
}
