/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8016A8FC - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

typedef struct { s32 w[8]; } Blk20;
typedef struct {
    short v0;   /* 0x00 */
    short v1;   /* 0x02 */
    short v2;   /* 0x04 */
    short pad6; /* 0x06 */
    short w0;   /* 0x08 */
    short w1;   /* 0x0A */
    short w2;   /* 0x0C */
    short padE; /* 0x0E */
    unsigned char b10; /* 0x10 */
    unsigned char b11; /* 0x11 */
    unsigned char b12; /* 0x12 */
    unsigned char b13; /* 0x13 */
    unsigned char b14; /* 0x14 */
    unsigned char b15; /* 0x15 */
    unsigned char b16; /* 0x16 */
    unsigned char b17; /* 0x17 */
    int   w18; /* 0x18 */
} Prim;
extern s32 func_80016A5C();
extern Blk20 D_800AE620;

s32 func_8016A8FC(s32 a0)
{
    Prim p;
    int ptr;
    ptr = *(int *)(a0 + 0x34);
    p.v0 = (short)*(int *)(a0 + 0x4C);
    p.v1 = (short)*(int *)(a0 + 0x50);
    p.v2 = (short)*(int *)(a0 + 0x54);
    p.w0 = *(unsigned short *)(ptr + 6);
    p.w1 = *(unsigned short *)(ptr + 0xA);
    p.w2 = *(unsigned short *)(ptr + 0xE);
    p.v0 = (short)(((int)*(short *)(a0 + 6) + *(int *)(a0 + 0x4C)) >> 1);
    p.v1 = (short)(((int)*(short *)(a0 + 0xA) + *(int *)(a0 + 0x50)) >> 1);
    p.v2 = (short)(((int)*(short *)(a0 + 0xE) + *(int *)(a0 + 0x54)) >> 1);
    *(short *)(a0 + 6) = (short)*(int *)(a0 + 0x4C);
    p.w0 = (short)(((int)*(short *)(a0 + 6) + (int)*(short *)(ptr + 6)) >> 1);
    *(int *)(a0 + 0x4C) = p.w0;
    *(short *)(a0 + 0xA) = (short)*(int *)(a0 + 0x50);
    p.w1 = (short)(((int)*(short *)(a0 + 0xA) + (int)*(short *)(ptr + 0xA)) >> 1);
    *(int *)(a0 + 0x50) = p.w1;
    *(short *)(a0 + 0xE) = (short)*(int *)(a0 + 0x54);
    p.w2 = (short)(((int)*(short *)(a0 + 0xE) + (int)*(short *)(ptr + 0xE)) >> 1);
    *(int *)(a0 + 0x54) = p.w2;
    p.b11 = 0x10;
    p.b15 = 0x80;
    p.b16 = 0x20;
    p.b14 = 0x20;
    p.b12 = 0;
    p.b10 = 0;
    p.w18 = 0x50000000;
    ((s32 (*)(void *, void *))func_80016A5C)(&p, &D_800AE620);
}
