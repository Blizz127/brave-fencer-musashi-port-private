/* SC02.CD FILE_031 / ov_SC02_031 retail span [8015AC48,8015AC90).
 * Offset 0x32AF0 at overlay base 80128158. SHA256(span)=c6418b229fc1b5898b2140b52c6387c9e862acc3fff1dfbc9281de472b729980.
 * Differs from the registry-verified MAIN member 0012 carve in exactly one
 * data reference: D_801809B0 here is D_80181238 (+0x888 member
 * data-block shift). Oracle MATCH re-earned on this file; Not MAIN10.
 */
#include "psx_types.h"
extern s32 D_80181238;
void func_80154150();
void func_80146DB8();
void func_80161CD0();
typedef struct { u8 pad_0[366]; u16 f16E; } T;
void func_8015AC48(T *p) {
    func_80154150(p, 9);
    func_80146DB8(p, &D_80181238);
    func_80161CD0(p, p->f16E);
}
