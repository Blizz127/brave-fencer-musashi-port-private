/* Overlay range [80145CEC,80145EE8) from MAIN.CD member 0012.
 * SHA256(span)=5fd93ad4f71d2d1b870505af473031690e206addddd2328c7011720df83c1926.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_80016714(void *, s32);          /* extern */
void func_8001C320(void *, void *);        /* extern */
void func_800290BC();                            /* extern */
u32 func_80029504();                                /* extern */
extern s32 D_8017FD30;
void func_80145EE8();                     /* static */
void func_801468C8(void *, s32);          /* static */
void func_80147084(void *);                   /* static */
void func_80147098(void *);                   /* static */
void func_801470AC(void *);                   /* static */
void func_80149210(void *, s32);          /* static */
void func_8014BE9C();                            /* static */
void func_8014C6D0();                            /* static */
void func_8014C968();                            /* static */
void func_80153C8C();                            /* static */
void func_801552F4(void *);                   /* static */
void func_801627C0();                            /* static */
void func_80162AF4();                            /* static */
void func_8016533C();                            /* static */
void func_80165938();                            /* static */
void func_80165C78();                            /* static */
extern void *D_800AF7C8;
extern s32 *D_800AFAE8;
extern s16 D_800B9A08;
extern s32 *D_800DE2A4;
extern s32 *D_801152C8;
extern s32 D_8011DB10;
extern s32 D_8011F9C4;
extern s32 *D_80126B58;
extern void *D_80126B78;
extern s32 (*D_80126B90)();
extern s16 D_80126BB8;
extern s16 D_80126BBA;
extern s16 D_80126BBC;
extern s16 D_80126BC0;
extern s16 D_80126BC2;
extern s16 D_80126BC4;
extern s16 D_80126BC8;
extern s16 D_80126BCA;
extern s16 D_80126BCC;
extern s16 D_80126C4E;
extern s16 D_80126D10;
extern s16 D_80126D12;
extern s32 D_8012707C;

void func_80145CEC(void) {
    func_80016714(&D_80126B58, 0x254);
    D_80126B78 = &D_800AFAE8;
    D_800AF7C8 = &D_801152C8;
    func_8001C320(&D_800AFAE8, &D_800DE2A4);
    M2C_FIELD(D_80126B78, s32 *, 0x28) = 0x7FFF7FFF;
    D_80126B90 = D_8017FD30;
    M2C_FIELD(D_80126B78, s16 *, 0x18) = 0x1000;
    D_80126BC8 = 0x1000;
    D_80126BC0 = 0x1000;
    D_80126BB8 = 0x1000;
    M2C_FIELD(D_80126B78, s16 *, 0x1A) = 0x1000;
    D_80126BCA = 0x1000;
    D_80126BC2 = 0x1000;
    D_80126BBA = 0x1000;
    M2C_FIELD(D_80126B78, s16 *, 0x1C) = 0x1000;
    D_80126BCC = 0x1000;
    D_80126BC4 = 0x1000;
    D_80126BBC = 0x1000;
    D_80126D12 = 0x1000;
    D_80126D10 = 0x1000;
    D_80126C4E = 0x1000;
    func_801552F4(&D_80126B58);
    func_80147084(&D_80126B58);
    func_80147098(&D_80126B58);
    func_801470AC(&D_80126B58);
    M2C_FIELD(D_80126B78, u16 *, 0x2C) = (u16) (M2C_FIELD(D_80126B78, u16 *, 0x2C) | 0x50);
    func_80149210(&D_80126B58, 8);
    func_8014BE9C();
    func_8016533C();
    func_801627C0();
    func_80162AF4();
    func_80165C78();
    func_801468C8(&D_80126B58, 1);
    if ((D_800B9A08 != 0x30A2) && (D_800B9A08 != 0x30A5)) {
        func_80145EE8(0);
    }
    func_8014C968();
    func_8014C6D0();
    D_8011F9C4 = 0;
    func_80165938();
    func_80153C8C();
    D_8012707C = 0;
    D_8011DB10 = 0;
    if (func_80029504() >= 0xAU) {
        func_800290BC();
    }
}
