/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80133298 - byte-exact against retail at -O2 (tools/register_match.py). */
typedef struct { s32 w[8]; } Blk32L_80133298;
void func_8012B2CC(s32 a0);
extern u8 D_80126B5C;
extern void func_8012F0BC(s32 *a0, s32 *a1, s32 *a2);
extern void func_8012F1A4(s32 *a0, s32 a1, s32 *a2);
void func_8012F0BC(s32 *a0, s32 *a1, s32 *a2);
void func_8012F1A4(s32 *a0, s32 a1, s32 *a2);
extern void func_8012B2CC(s32 a0);
extern void func_8013339C(s16 *a0, s16 *a1);

void func_80133298(s32 *a0)
{
    extern u8 D_80126B5C;  
    extern s32 D_80126B5C_w __asm__("D_80126B5C");  
    extern s32 D_80126B60;
    extern s32 D_80126B64;
    s32 in[3];
    s32 out[3];
    s32 tmp[3];
    Blk32L_80133298 m;
    in[0] = D_80126B5C_w;
    in[1] = D_80126B60;
    in[2] = D_80126B64;
    func_8012F0BC((s32 *)(a0[8] + 0x34), in, tmp);
    func_8012B2CC((s32)a0);
    m = *(Blk32L_80133298 *)(a0[8] + 0x34);
    func_8013339C((s16 *)&m, (s16 *)(a0[8] + 0x18));
    func_8012F1A4((s32 *)&m, (s32)tmp, out);
    D_80126B5C_w = out[0];
    D_80126B60 = out[1];
    D_80126B64 = out[2];
}
