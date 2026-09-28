/* Overlay range [801523F4,80152500) from MAIN.CD member 0012.
 * SHA256(span)=f14b083d28e24cb8428aa0e1586f7a0a2e24ddacb977db1d5aeb964600db0355.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_801523F4 - byte-exact against retail at -O2 (tools/register_match.py). */
typedef s32 M2C_UNK;
extern void func_80019064(void *);
extern void func_80019064(void *a0);
void func_80146CA0(void *a0);
void func_80146DB8(s32 *a0, s32 *a1);
void func_80146E90(s32 *a0, s32 a1);
void func_80147324(s32 arg0);
void func_801477E8(s32 *a0, s32 a1);
extern s32 func_80012A60(s32 a0, s32 a1);
void func_80149020(s32 *a0);
extern void func_80147324(s32 a0);
extern void func_80147324(s32 arg0);
extern int func_80151204(int arg, int a1);
int func_80151204(int a0, int a1);
extern void func_80154A74(s32 a0, s32 a1);
extern void func_801477E8(s32 *a0, s32 a1);
extern void func_80146CA0(void *a0);
extern M2C_UNK D_800D5880;
extern s32 D_800D58AC;
extern void func_80154274(s32 *a0, s32 a1);
extern void func_80149020(s32 *a0);
extern void func_80146DB8(s32 *a0, s32 *a1);
extern void func_80146E90(s32 *a0, s32 a1);
extern void func_8001382C(s32 a0, void *a1, void *a2);

void func_801523F4(s32 arg0)
{

    extern u8 D_80062C04[];
    extern M2C_UNK D_800D5880;
    extern s32 D_800D58AC;
    extern u8 D_801800E4[];
    s32 pad[4];
    s32 buf[4];
    register s32 s0a __asm__("$16");                     
    register s32 s2a __asm__("$18") = (s32)&D_801800E4;  

    ((void (*)(s32, s32))func_80146E90)(arg0, 0);
    func_80019064(&D_80062C04);
    ((void (*)(s32, s32))func_80151204)(arg0, *(s16 *)(arg0 + 0xF2));
    if ((s16)func_80012A60((s32)*(s16 *)(*(s32 *)(arg0 + 0x20) + 0x12),
                           (s32)*(s16 *)(arg0 + 0xF4)) >= 0x401) {
        ((void (*)(s32, s32))func_80154274)(arg0, (s32)&D_800D5880);
    } else {
        ((void (*)(s32, s32))func_80154274)(arg0, (s32)&D_800D58AC);
    }
    func_80154A74(arg0, 0x16);
    ((void (*)(s32))func_80149020)(arg0);
    s0a = (s32)buf;
    ((void (*)(s32, s32, s32))func_8001382C)((*(u16 *)(arg0 + 0xF4) - *(u16 *)(*(s32 *)(arg0 + 0x20) + 0x12)) & 0xFFF,
                  s2a, s0a);
    ((void (*)(s32, s32))func_80146DB8)(arg0, s0a);
    ((void (*)(s32, s32))func_801477E8)(arg0, *(s32 *)(s2a + 0xC));
    func_80147324(0x451);
    ((void (*)(s32))func_80146CA0)(arg0);
    (void)pad;
}
