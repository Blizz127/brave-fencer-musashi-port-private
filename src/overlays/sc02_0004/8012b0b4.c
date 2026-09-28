/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8012B0B4 - byte-exact against retail at -O2 (tools/register_match.py). */
extern int func_80047948(int a0);
extern int func_8004787C(int a0);

void func_8012B0B4(unsigned int *param_1, int param_2, int param_3)
{
    int iVar1, iVar2;
    register int prod __asm__("$7");           
    register unsigned int *p __asm__("$2");     
    register int sh1 __asm__("$2");             
    register int sh2 __asm__("$3");             
    unsigned int uVar3, result;
    uVar3 = (param_2 - 0x400U) & 0xfff;
    iVar1 = func_80047948(uVar3);
    result &= 0xFFFF0000;
    prod = iVar1 * param_3;
    sh1 = prod >> 0xc;
    result |= sh1 & 0xFFFF;
    iVar2 = func_8004787C(uVar3);
    prod = iVar2 * -param_3;
    result &= 0xFFFF;
     

    __asm__ ("addu %0,%1,$zero" : "=r"(p) : "r"(param_1));
    sh2 = prod >> 0xc;
    result |= sh2 << 0x10;
    *p = result;
}
