/* Main-exec range [8001C5B8,8001C6E4) from the SLUS executable.
 * SHA256(span)=e48b4b053a337d548bef9405bd1df5bd32923f77c78e7dda90e720d82483423f.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8001C5B8 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"

/* Vendor names mapped to address-named symbols for the link-by-address harness. */
#define GsLinkObject5 func_800553D8
#define GsMapModelingData func_80053290
#define GsPresetObject func_800553F4

void func_8001C5B8(s32 a0, s32 a1)
{
    extern void func_8001C9D0(void);
    extern void func_80052D90(s32 a0, void *a1);
    extern void func_80054514(s32 a0, s32 a1);
    extern void GsMapModelingData(unsigned long *p);
    extern void GsLinkObject5();
    extern void *GsPresetObject();
    extern u8 D_800AF630[];
    extern u8 D_80063548[];
    extern u16 D_800AF7CC;
    extern s32 *D_800AF7C8;
    extern u8 D_800A5BD0[];

    s32 sp10[8];
    register s32 obj __asm__("$17");
    register s32 next __asm__("$19");
    register s32 work __asm__("$20");
    s32 entry;
    u16 c2;

    obj = a0;
    func_8001C9D0();
    *(u16 *)obj = 1;
    *(u16 *)(obj + 2) = 8;
    func_80052D90(0, (void *)(obj + 0x30));
    func_80054514(obj + 0x30, (s32)&sp10[0]);
    work = (s32)D_800AF630;
    *(s32 *)(obj + 0x24) = a1;
    if (a1 != 0) {
        *(s32 *)(obj + 0x20) = (s32)D_80063548;
        next = (s32)D_800AF7C8;
        *(u16 *)(obj + 0x2E) = D_800AF7CC;
        if (*(s32 *)a1 != 0) {
            do {
                entry = (*(s32 *)a1 & 0x80FFFFFF) + 4;
                a1 += 4;
                __asm__ __volatile__("" : "=r"(entry) : "0"(entry));
                GsMapModelingData((unsigned long *)entry);
                c2 = *(u16 *)(work + 0x19C);
                *(u16 *)(work + 0x19C) = c2 + 1;
                GsLinkObject5((u32 *)(entry + 8),
                              (void *)&D_800A5BD0[(c2 << 2) + c2 << 2], 0);
                next = (s32)GsPresetObject(
                    (void *)&D_800A5BD0[(c2 << 2) + c2 << 2], (void *)next);
            } while (*(s32 *)a1 != 0);
        }
        *(s32 *)(work + 0x198) = next;
    }
}
