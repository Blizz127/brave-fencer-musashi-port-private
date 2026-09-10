/* SC02.CD FILE_031 / ov_SC02_031 retail span [80157A8C,80157AC8).
 * Offset 0x2F934 at overlay base 80128158. SHA256(span)=91fdc82b3d341ac21d4ccbd56cf91870ba5a928647ceb131737c46dfacd4754a.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80157a8c.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"
void func_80161D20();
void func_8014C010();
typedef struct {
    u8 pad_0[366];
    u16 f16E;
} T;
void func_80157A8C(T *p) {
    func_80161D20(p, p->f16E);
    func_8014C010(p, 1);
}
