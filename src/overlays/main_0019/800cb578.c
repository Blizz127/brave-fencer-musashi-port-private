/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* GTE mnemonic macros, copied from vendor/bfm-decomp/include/gte_macros.inc (assembler-only, emit no code). */
__asm__(
".macro cop2op fake_op, op, gbg = 0, sf = 1, mx = 0, v = 0, cv = 0, lm = 0\n"
"    cop2 \\fake_op << 20 | \\gbg << 20 | \\sf << 19 | \\mx << 17 | \\v << 15 | \\cv << 13 | \\lm << 10 | \\op\n"
".endm\n"
".macro mvmva sf, mx, v, cv, lm\n"
"    cop2op 0x04, 0x12, sf = \\sf, mx = \\mx, v = \\v, cv = \\cv, lm = \\lm\n"
".endm\n"
);
/* func_800CB578 - byte-exact against retail at -O2 (tools/register_match.py). */
#define RotMatrixZ func_8004A27C
extern s32 func_8004787C(s32 a0);
extern s32 func_80047948(s32 a0);
extern u8 D_800CC5B0[];
typedef struct { u8 b[4]; } B4_CB578;
typedef struct { u8 b[8]; } B8_CB578;
typedef struct { s16 m[3][3]; s32 t[3]; } MTX_CB578;
extern void func_80013F3C(void *a0);
extern void RotMatrixZ(s32 a0, void *a1);
extern s32 func_800130D0(s32 a0, s32 a1, s32 a2);
extern void func_800CB9F8(u16 *a0, u16 *a1, s32 *a2, s32 *a3, s32 stg);
extern u8 D_800CC114[];
extern u8 D_800CC638[];

void func_800CB578(void *arg0) {
    u16 pos[4];
    MTX_CB578 mat;
    u16 sv[4];
    B4_CB578 clr[2];
    s32 obj;
    s32 t;
    s16 sn;
    u8 *p;
    s32 i;

    obj = *(s32 *)((u8 *)arg0 + 0x20);
    func_80013F3C(&mat);
    RotMatrixZ(*(s16 *)((u8 *)arg0 + 0x64), &mat);
    __asm__ volatile ( "lw $12, 0( %0 );" "lw $13, 4( %0 );" "ctc2 $12, $0;" "ctc2 $13, $1;" "lw $12, 8( %0 );" "lw $13, 12( %0 );" "lw $14, 16( %0 );" "ctc2 $12, $2;" "ctc2 $13, $3;" "ctc2 $14, $4" : : "r"(  obj + 0x34  ) : "$12", "$13", "$14", "memory" ) ;
    __asm__ volatile ( "lhu $12, 0( %0 );" "lhu $13, 6( %0 );" "lhu $14, 12( %0 );" "mtc2 $12, $9;" "mtc2 $13, $10;" "mtc2 $14, $11;" "nop;" "nop;" "mvmva 1, 0, 3, 3, 0" : : "r"(  (s32)&mat  ) : "$12", "$13", "$14", "memory"); __asm__ volatile ( "mfc2 $12, $9;" "mfc2 $13, $10;" "mfc2 $14, $11;" "sh $12, 0( %0 );" "sh $13, 6( %0 );" "sh $14, 12( %0 )" : : "r"(  (s32)&mat  ) : "$12", "$13", "$14", "memory") ;
    __asm__ volatile ( "lhu $12, 0( %0 );" "lhu $13, 6( %0 );" "lhu $14, 12( %0 );" "mtc2 $12, $9;" "mtc2 $13, $10;" "mtc2 $14, $11;" "nop;" "nop;" "mvmva 1, 0, 3, 3, 0" : : "r"(  (s32)&mat + 2  ) : "$12", "$13", "$14", "memory"); __asm__ volatile ( "mfc2 $12, $9;" "mfc2 $13, $10;" "mfc2 $14, $11;" "sh $12, 0( %0 );" "sh $13, 6( %0 );" "sh $14, 12( %0 )" : : "r"(  (s32)&mat + 2  ) : "$12", "$13", "$14", "memory") ;
    __asm__ volatile ( "lhu $12, 0( %0 );" "lhu $13, 6( %0 );" "lhu $14, 12( %0 );" "mtc2 $12, $9;" "mtc2 $13, $10;" "mtc2 $14, $11;" "nop;" "nop;" "mvmva 1, 0, 3, 3, 0" : : "r"(  (s32)&mat + 4  ) : "$12", "$13", "$14", "memory"); __asm__ volatile ( "mfc2 $12, $9;" "mfc2 $13, $10;" "mfc2 $14, $11;" "sh $12, 0( %0 );" "sh $13, 6( %0 );" "sh $14, 12( %0 )" : : "r"(  (s32)&mat + 4  ) : "$12", "$13", "$14", "memory") ;
    mat.t[0] = *(s32 *)(obj + 0x48);
    mat.t[1] = *(s32 *)(obj + 0x4C);
    mat.t[2] = *(s32 *)(obj + 0x50);
    *(u16 *)((u8 *)arg0 + 0x64) = (*(u16 *)((u8 *)arg0 + 0x64) + 0x71) & 0xFFF;
    *(B8_CB578 *)pos = *(B8_CB578 *)((u8 *)arg0 + 0x10);

    sn = func_8004787C(*(s16 *)((u8 *)arg0 + 0x62)) / 128;
    t = func_80047948(*(s16 *)((u8 *)arg0 + 0x60));
    pos[0] += (sn * t) / 4096;
    t = func_8004787C(*(s16 *)((u8 *)arg0 + 0x60));
    pos[1] += (sn * t) / 4096;

    *(u16 *)((u8 *)arg0 + 0x60) = (*(u16 *)((u8 *)arg0 + 0x60) + 0xE3) & 0xFFF;
    *(u16 *)((u8 *)arg0 + 0x62) = (*(u16 *)((u8 *)arg0 + 0x62) + 0x38) & 0xFFF;

    p = D_800CC5B0 + *(s32 *)((u8 *)arg0 + 0x50) * 160;
    clr[0] = *(B4_CB578 *)(D_800CC114 + *(s32 *)((u8 *)arg0 + 0x50) * 4);
    clr[1] = *(B4_CB578 *)(D_800CC114 + *(s32 *)((u8 *)arg0 + 0x50) * 4);
    sv[0] = sv[1] = sv[2] = 0x1000;
    func_800CB9F8(pos, (u16 *)p, (s32 *)&mat, (s32 *)clr, (s32)sv);

    p = D_800CC5B0 + *(s32 *)((u8 *)arg0 + 0x50) * 160;
    i = 0;
    do {
        clr[0] = clr[1];
        clr[1].b[0] = func_800130D0(clr[1].b[0], 0, 0xC);
        clr[1].b[1] = func_800130D0(clr[1].b[1], 0, 0xC);
        clr[1].b[2] = func_800130D0(clr[1].b[2], 0, 0xC);
        sv[0] = sv[1] = sv[2] = sv[2] - 0x100;
        func_800CB9F8((u16 *)p, (u16 *)(p + 0x10), (s32 *)&mat, (s32 *)clr, (s32)sv);
        p += 0x10;
        i += 2;
    } while (i < 0x12);

    p = D_800CC638 + *(s32 *)((u8 *)arg0 + 0x50) * 160;
    clr[0] = clr[1];
    clr[1].b[0] = func_800130D0(clr[1].b[0], 0, 0xA);
    clr[1].b[1] = func_800130D0(clr[1].b[1], 0, 0xA);
    clr[1].b[2] = func_800130D0(clr[1].b[2], 0, 0xA);
    sv[0] = sv[1] = sv[2] = sv[2] - 0x100;
    func_800CB9F8((u16 *)p, (u16 *)(p + 0x10), (s32 *)&mat, (s32 *)clr, (s32)sv);

    i = 0;
    p = &D_800CC638[0x10] + *(s32 *)((u8 *)arg0 + 0x50) * 160;
    do {
        *(B8_CB578 *)p = *(B8_CB578 *)(p - 8);
        i += 1;
        p -= 8;
    } while (i < 0x13);
    *(B8_CB578 *)p = *(B8_CB578 *)pos;
}
