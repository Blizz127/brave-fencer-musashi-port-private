/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CBCB4 - byte-exact against retail at -O2 (tools/register_match.py). */
#define currentLocationId D_800B9A08
extern s16 currentLocationId;
extern void func_80015978(s32, s32 *);

void func_800CBCB4(void *a0) {
    s16 sp[4];

    func_80015978((s32)a0 + 4, sp);
    switch (currentLocationId) {
    case 0x3035:
        if (sp[0] < -0x93E) {
            sp[0] = -0x93E;
        }
        if (sp[0] >= -0x3C1) {
            sp[0] = -0x3C2;
        }
        if (sp[2] < 0x3C2) {
            sp[2] = 0x3C2;
        }
        if (sp[2] >= 0xCBF) {
            sp[2] = 0xCBE;
            goto after;
        }
        break;
    case 0x3037:
        if (sp[0] < 0x4C2) {
            sp[0] = 0x4C2;
        }
        if (sp[0] >= 0xA3F) {
            sp[0] = 0xA3E;
        }
        if (sp[2] < 0xAC2) {
            sp[2] = 0xAC2;
        }
        if (sp[2] >= 0x13BF) {
            sp[2] = 0x13BE;
            goto after;
        }
        break;
    case 0x3038:
        if (sp[0] < -0xF3E) {
            sp[0] = -0xF3E;
        }
        if (sp[0] >= -0x9C1) {
            sp[0] = -0x9C2;
        }
        if (sp[1] < -0xA00) {
            sp[1] = -0xA00;
        }
        if (sp[1] >= -0x201) {
            sp[1] = -0x202;
            goto after;
        }
        break;
    case 0x3039:
        if (sp[0] < -0x153E) {
            sp[0] = -0x153E;
        }
        if (sp[0] >= -0xFC1) {
            sp[0] = -0xFC2;
        }
        if (sp[2] < 0x3C2) {
            sp[2] = 0x3C2;
        }
        if (sp[2] >= 0xFBF) {
            sp[2] = 0xFBE;
        }
        break;
    }
after:
    func_80015954(sp, (s32)a0 + 4);
}
