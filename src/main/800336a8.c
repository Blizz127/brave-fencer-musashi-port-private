/* Exact retail word export for [800336A8,8003388C); EXE and assembly verified. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"

/* func_800336A8 - byte-exact against retail at -O2 (tools/register_match.py). */

s32 aF800301A4(void) __asm__("func_800301A4");
extern void func_800301A4(void);
typedef struct {
     u8 pad00[0x0A];
     u16 unk0A;
     u8 pad0C[0x28];
     u8 unk34;
     u8 unk35;
     u8 pad36[0x1C];
     u8 unk52;
     u8 pad53[1];
} Chan336A8;
typedef struct {
     s32 unk00;
     s32 unk04;
     s16 unk08;
     s16 unk0A;
     u8 pad0C[0x34];
     s32 unk40;
     u8 unk44;
     u8 pad45[3];
} Voice336A8;
typedef struct {
     u8 pad00[0x16];
     u8 unk16;
     u8 pad17[1];
     u16 unk18;
     u8 pad1A[2];
     u16 unk1C[12];
     u8 pad34[4];
     u8 unk38;
     u8 pad39[1];
     u8 unk3A[8];
} Req336A8;
extern u8 D_800A4988[];
extern s32 D_80073140[];
extern u16 D_8006AA30[];
extern const u16 D_8007319E[];
extern u16 D_8007321E;
extern u8 D_800A4F19;
extern void func_800336A8();

void func_800336A8(Req336A8 *arg)
{
    Chan336A8 *ch;
    Voice336A8 *vo;
    u16 *p;
    const u16 *q;
    u32 m;
    u32 n;
    u32 v;
    s32 i;
    s32 j;

    for (i = 0; i < 8; i++) {
        if (arg->unk3A[i] == 0) {
            continue;
        }
        ch = (Chan336A8 *)(D_800A4988 + i * 0x54);
        vo = (Voice336A8 *)(D_800A4988 + 0x2A0 + i * 0x48);
        vo->unk00 = D_80073140[ch->unk0A];
        m = ch->unk34;
        m = D_8006AA30[m];
        m = m * *(s16 *)(D_800A4988 + 0x572);
        m = m >> 7;
        if (arg->unk16 != 0) {
            m = m * arg->unk18;
            m = m >> 15;
        }
        p = arg->unk1C;
        for (j = 2; j >= 0; j--, p += 4) {
            m = m * *p;
            m = m >> 14;
        }
        n = ch->unk35;
        if (n == 0) {
            v = m;
            vo->unk0A = v;
            vo->unk08 = v;
        } else {
            if (arg->unk38 != 0) {
                n += arg->unk38;
                if (n >= 0x42) {
                    n -= 0x40;
                    if (n >= 0x80) {
                        n = 0x7F;
                    }
                } else {
                    n = 1;
                }
            }
            ch->unk52 = n;
            if (D_800A4F19 != 0) {
                

                __asm__ __volatile__("");
                v = (m * D_8007319E[n]) >> 14;
                vo->unk0A = v;
                q = D_8007319E + 1;
                v = (m * q[0x7F - n]) >> 14;
                vo->unk08 = v;
            } else {
                v = (m * D_8007321E) >> 14;
                vo->unk0A = v;
                vo->unk08 = v;
            }
        }
        vo->unk40 = ch->unk0A;
        if (vo->unk44 != 0) {
            vo->unk04 |= 3;
        } else {
            vo->unk04 = 3;
            vo->unk44 = 1;
        }
    }
}
