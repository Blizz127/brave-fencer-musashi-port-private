/* Exact retail [80023570,8002374C).
 * Words from pinned SLUS_007.26.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80023570 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"

/* Vendor names mapped to address-named symbols for the link-by-address harness. */
#define GetTPage func_80058B40

typedef struct { u32 addr : 24; u32 len : 8; } PTag_80023570;

extern u8 D_800A6610[];
extern u16 D_800B9A02;
extern u8 *D_800A5E60;
extern s32 GetTPage(s32, s32, s32, s32);
extern s32 func_8005A600(s32, s32, s32, s32, s32);

void func_80023570(s32 arg0)
{
    u32 *ot;
    register u32 flags __asm__("$5");
    u16 idx;
    PTag_80023570 *slot2;
    u8 *cur;
    u8 *nxt;

    {
        register u8 *rec0 __asm__("$8");
        register u8 *p __asm__("$7");
        register u16 addX __asm__("$14");
        register u16 addY __asm__("$13");
        register u8 code __asm__("$11");
        register u32 tagconst __asm__("$15");
        register u32 *slot __asm__("$10");
        register u32 maskAddr __asm__("$9");
        register u32 maskLen __asm__("$12");
        register u8 *rec3 __asm__("$6");
        register u8 *q __asm__("$4");
        register u32 sc __asm__("$2");
        u8 last;
        u32 x, y;
        u16 t16;

        rec0 = *(u8 **)(arg0 + 0x20);
        sc = (u32)(u16)D_800B9A02;
        p = D_800A5E60;
        flags = *(u32 *)(arg0 + 4);
        addX = *(u16 *)(arg0 + 8);
        addY = *(u16 *)(arg0 + 0xA);
        idx = *(u16 *)(arg0 + 0x2C);
        ot = (u32 *)(D_800A6610 + (sc << 14));
        code = (flags & 0x40000000) ? 0x62 : 0x60;
        tagconst = 0x03000000;
        sc = idx << 2;
        slot = (u32 *)(sc + (u32)ot);
        maskAddr = 0x00FFFFFF;
        maskLen = 0xFF000000;
        rec3 = rec0 + 3;
        q = p + 0xE;

        do {
            q[-7] = code;
            *(u32 *)p = tagconst;
            q[-0xA] = rec0[0];
            q[-9] = rec3[-2];
            q[-8] = rec3[-1];
            *(u16 *)(q - 6) = addX + *(u16 *)(rec3 + 1);
            cur = D_800A5E60;
            *(u16 *)(q - 4) = addY + *(u16 *)(rec3 + 3);
            t16 = *(u16 *)(rec3 + 5);
            rec0 += 0xC;
            *(u16 *)(q - 2) = t16;
            t16 = *(u16 *)(rec3 + 7);
            nxt = cur + 0x10;
            D_800A5E60 = nxt;
            *(u16 *)(q) = t16;
            q += 0x10;

            x = *(u32 *)p;
            y = *slot;
            x = x & maskLen;
            y = y & maskAddr;
            x = x | y;
            *(u32 *)p = x;
            x = (u32)p & maskAddr;
            p += 0x10;
            y = *slot;
            y = y & maskLen;
            y = y | x;
            *slot = y;

            last = rec3[0];
            rec3 += 0xC;
        } while (last == 0);
    }

    if (flags & 0x40000000) {
        s32 tp;

        D_800A5E60 = cur + 0x1C;
        tp = GetTPage(2, (flags >> 28) & 3, 0x280, 0);
        func_8005A600((s32)nxt, 0, 0, (u16)tp, 0);

        slot2 = (PTag_80023570 *)(((u32)idx << 2) + (u32)ot);
        ((PTag_80023570 *)nxt)->addr = slot2->addr;
        slot2->addr = (u32)nxt;
    }
}
