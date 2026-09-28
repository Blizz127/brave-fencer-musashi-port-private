/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CB3FC - byte-exact against retail at -O2 (tools/register_match.py). */
typedef struct { s32 vpx, vpy, vpz, vrx, vry, vrz, rz, super; } RView;
extern void func_800CB578(void *a0);
extern s32 func_80146E98(s32 a0);
extern void func_80015954(s32 a0, s32 a1);
extern void func_80149374(s32 a0, s32 a1);
extern s32 func_80146A6C(s32 a0, void *a1, s32 a2, s32 a3, s32 a4, s32 a5, s32 a6);
extern void func_80146CA0(void *a0);
extern void func_800CBC0C(void *a0);

void func_800CB3FC(void *arg0)
{
    RView view;  
    *(u16 *)((s32)arg0 + 0x14) -= 6;
    func_800CB578(arg0);
    if (func_80146E98((s32)arg0) != 0) {
        func_80015954((s32)arg0 + 0x10, (s32)arg0 + 4);
        func_80149374((s32)arg0, (s32)arg0 + 4);
        func_80146A6C(3, arg0,
                      *(s16 *)((s32)arg0 + 6),
                      *(s16 *)((s32)arg0 + 0xA),
                      *(s16 *)((s32)arg0 + 0xE),
                      0,
                      0x80001C00);
        func_80146CA0(arg0);
    } else {
        func_800CBC0C(arg0);
    }
}
