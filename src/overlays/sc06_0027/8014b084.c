/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8014B084 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern u16 D_80078EAC;
extern u8 D_80078EBA;
extern void func_800D10EC(void);
extern void func_8002AC98(void);
extern void func_80145C54(void);

void func_8014B084(void) {
    u16 a;
    u8 b;
    a = D_80078EAC + 1;
    b = D_80078EBA + 1;
    D_80078EAC = a;
    D_80078EBA = b;
    if (a >= 0x16E) {
        D_80078EAC = 1;
    }
    D_80078EBA = b % 7;
    func_800D10EC();
    func_8002AC98();
    func_80145C54();
}
