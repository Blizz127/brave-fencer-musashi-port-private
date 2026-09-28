/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80137178 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A5F8(void (*a0)(void), s32 a1);
extern short D_800B9A02;
extern u8 D_800A6518[];
extern void func_80051DC8(void *a0, void *a1, s32 a2);

void func_80137178(s32 a0, s32 a1)
{
    struct {
        u32 tag;
        s16 x0;
        s16 y0;
        s16 x1;
        s16 y1;
        u8 r;
        u8 g;
        u8 b;
    } line;
    register s16 x0    __asm__("$19");             /* $s3 */
    register s16 white __asm__("$17");             /* $s1 */
    register u8 *base  __asm__("$18") = D_800A6518; /* $s2 */
    s16 x1;
    s16 y0;
    s16 y1;
    x0 = a0 - 3;
    y0 = a1 - 3;
    x1 = a0 + 3;
    __asm__("" : "=r"(x0) : "0"(x0));
    y1 = a1 - 3;
    white = 0xFF;
    line.tag = 0;
    line.r = 0;
    line.g = 0;
    line.b = white;
    line.x0 = x0;
    line.y0 = y0;
    line.x1 = x1;
    line.y1 = y1;
    func_80051DC8(&line, &base[(u16)D_800B9A02 * 20], 0);
    y0 = a1 + 3;
    line.tag = 0;
    line.r = 0;
    line.g = 0;
    line.b = white;
    line.x0 = x0;
    line.y0 = y0;
    line.x1 = x1;
    line.y1 = y1;
    func_80051DC8(&line, &base[(u16)D_800B9A02 * 20], 0);
    y1 = a1 + 3;
    line.tag = 0;
    line.r = 0;
    line.g = 0;
    line.b = white;
    line.x0 = x0;
    line.y0 = y0;
    line.x1 = x1;
    line.y1 = y1;
    func_80051DC8(&line, &base[(u16)D_800B9A02 * 20], 0);
}
