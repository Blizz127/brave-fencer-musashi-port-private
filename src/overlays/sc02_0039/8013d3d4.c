/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8013D3D4 - byte-exact against retail at -O2 (tools/register_match.py). */
extern u8 D_80078E78[];
extern void func_8013CF68(void);
void func_8013CF68();
extern void *D_8019FA38;
extern void *D_8019FA3C;
extern void *D_8019FA40;
extern s32 D_8019FA68;
extern s32 D_8019FA6C;
extern s32 D_8019FA70;
extern s32 D_801A0CE4[];
extern u8 D_8017F93C[];
extern u8 D_8017F9E4[];
extern u8 D_8017F894[];
extern u8 D_8017F990[];
extern u8 D_8017FA10[];
extern u8 D_8017F8E8[];
extern void func_8013D53C();
extern void func_8013DD68(void);
extern void func_8013D8FC(void);

void func_8013D3D4(int param_1, int param_2)
{
    u8 *p = D_80078E78;

    D_8019FA68 = param_2;
    D_8019FA6C = (param_2 >> 2) & 3;
    D_8019FA70 = (param_2 >> 4) & 1;
    if (((param_2 >> 2) & 3) == 0) {
        D_8019FA38 = D_8017F93C;
        D_8019FA3C = D_8017F9E4;
        D_8019FA40 = D_8017F894;
    } else {
        D_8019FA38 = D_8017F990;
        D_8019FA3C = D_8017FA10;
        D_8019FA40 = D_8017F8E8;
    }
    func_8013D53C();
    if ((param_2 & 1) != 0) {
        if (D_8019FA70 != 0) {
            func_8013DD68();
        } else {
            func_8013D8FC();
        }
        func_8013CF68();
        if ((D_8019FA68 & 2) != 0) {
            D_801A0CE4[0] = 0x140;
            D_801A0CE4[3] = 0x80;
            if (p[0x37] == 4) {
                D_801A0CE4[0] = 0x140;
                D_801A0CE4[3] = 0;
            }
            if (p[0x37] == 0) {
                D_801A0CE4[0] = 0x140;
                D_801A0CE4[3] = 0x80;
            }
        }
    }
}
