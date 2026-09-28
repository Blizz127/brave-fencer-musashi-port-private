/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801A4724 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_80132288(s32 *a0, s32 *a1, s32 a2);
extern void func_8013240C(s32 a0);
extern void func_80132784(s32 a0, s32 a1, u32 a2);
extern void func_801A4A18(s32 a0);
extern s32 D_801F8888;
extern s32 D_801F8894;
extern s32 D_801F8898;
extern s32 D_801B001C;
extern s32 D_801B002C;
extern s32 D_801B003C;
extern s32 D_801B004C;
extern s32 D_801B005C;
extern s32 D_801B006C;
extern s32 D_801B75EC;
extern u8 D_801B80FC[];

void func_801A4724(void *arg0)
{
    s32 mirror;
    u16 state;
    s32 newState;

    state = *(u16 *)((u8 *)arg0 + 0x34);
    mirror = *(s32 *)((u8 *)arg0 + 0xCC);

    switch (state) {
    case 0:
        if (*(s16 *)((u8 *)arg0 + 0x70) != 0) {
            break;
        }
        if (*(s32 *)((u8 *)arg0 + 0x1C) != 0x16) {
            break;
        }
        func_80132288(&D_801F8888, &D_801B001C, D_801B75EC);
        if (mirror != 0) {
            func_80132288(&D_801F8898, &D_801B002C, *(s32 *)D_801B80FC);
        }
        goto inc;
    case 1:
    case 3:
        func_8013240C((s32)&D_801F8888);
        if (mirror != 0) {
            func_8013240C((s32)&D_801F8898);
        }
        if (!(D_801F8894 & 0x4000)) {
            break;
        }
        goto inc;
    case 2:
        if (*(s32 *)((u8 *)arg0 + 0x1C) != 0x2F) {
            break;
        }
        func_80132288(&D_801F8888, &D_801B003C, D_801B75EC);
        if (mirror != 0) {
            func_80132288(&D_801F8898, &D_801B004C, *(s32 *)D_801B80FC);
        }
        goto inc;
    case 4:
        if (*(s32 *)((u8 *)arg0 + 0x1C) != 0x3C) {
            break;
        }
        func_80132288(&D_801F8888, &D_801B005C, D_801B75EC);
        if (mirror != 0) {
            func_80132288(&D_801F8898, &D_801B006C, *(s32 *)D_801B80FC);
        }
        goto inc;

    inc:
        *(u16 *)((u8 *)arg0 + 0x34) = *(u16 *)((u8 *)arg0 + 0x34) + 1;
        break;

    case 5:
        func_8013240C((s32)&D_801F8888);
        if (mirror != 0) {
            func_8013240C((s32)&D_801F8898);
        }
        if (!(D_801F8894 & 0x4000)) {
            break;
        }
        func_801A4A18((s32)arg0);
        func_801A4A18(*(s32 *)((u8 *)arg0 + 0x6C));
        break;
    }

    newState = *(s32 *)((u8 *)arg0 + 0x1C) + 1;
    *(s32 *)((u8 *)arg0 + 0x1C) = newState;
    if (newState < 0x33) {
        *(s16 *)(*(s32 *)((u8 *)arg0 + 0x20) + 0x1A) = (newState << 12) / 50;
        *(s16 *)(*(s32 *)((u8 *)arg0 + 0x20) + 0x1C) = *(s16 *)(*(s32 *)((u8 *)arg0 + 0x20) + 0x1A);
        *(s16 *)(*(s32 *)((u8 *)arg0 + 0x20) + 0x14) = (0x32 - *(s32 *)((u8 *)arg0 + 0x1C)) << 4;
        if (*(s16 *)((u8 *)arg0 + 0x70) == 0) {
            *(s16 *)(*(s32 *)((u8 *)arg0 + 0x20) + 0x18) = *(u16 *)(*(s32 *)((u8 *)arg0 + 0x20) + 0x1A);
            *(s16 *)(*(s32 *)((u8 *)arg0 + 0x20) + 0x14) = -(s32)*(u16 *)(*(s32 *)((u8 *)arg0 + 0x20) + 0x14);
        } else {
            *(s16 *)(*(s32 *)((u8 *)arg0 + 0x20) + 0x18) = -(s32)*(u16 *)(*(s32 *)((u8 *)arg0 + 0x20) + 0x1A);
        }
    }

    func_80132784((s32)arg0, *(s32 *)((u8 *)arg0 + 0x64), 0);
}
