/* Overlay range [8017C268,8017C348) from MAIN.CD member 0012.
 * SHA256(span)=e102c7960af5822f9b5df698461341f733f7455492bb2f84a923fd460a7655e5.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8017C268 - byte-exact against retail at -O2 (tools/register_match.py). */
extern u16 aD800B9A02 __asm__("D_800B9A02");
extern u8 D_800B9A15;
extern unsigned short D_80115112;
extern u8 D_801151C8[];
extern s32 D_801151D0;
extern u16 D_80115112;

void func_8017C268(void)
{
    extern s32 func_8002B0B4(s32 a0, s32 a1, void *a2);
    extern u16 aD800B9A02 __asm__("D_800B9A02");
    extern s16 D_801857EC;
    extern s32 D_80185AD4;
    extern s32 D_80185AD8;
    extern u8 D_80185ADC[];
    extern s32 D_80185AEC;
    extern s16 D_801857E8;
    extern s16 D_80115126;
    extern u8 D_801151C8[];
    extern s32 D_801151D0;
    extern u16 D_80115112;
    extern u8 D_800B9A15;
    extern s32 func_8017CF3C(void);
    extern void func_8017D2A4(void);
    extern s32 func_8017C3BC(void);
    extern void func_8017CA18(void);
    s32 r;
    u32 pad[2];

    D_801151D0 = *(s32 *)&D_801151C8[aD800B9A02 * 4];
    if (D_801857EC == 0) {
        D_80185AEC = func_8002B0B4(D_80185AD4, D_80185AD8, D_80185ADC);
        if (D_80115126 == 0) {
            func_8017CF3C();
        } else {
            func_8017D2A4();
        }
    }
    r = func_8017C3BC();
    func_8017CA18();
    if ((s16)r != 0) {
        u16 *p = &D_80115112;
        D_801857E8 = r;
        D_800B9A15 = 0;
        *p = *p + 1;
    }
}
