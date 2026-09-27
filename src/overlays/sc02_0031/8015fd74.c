/* SC02 resident retail span [8015FD74,8015FDCC). Offset 0x37C1C at base 80128158.
 * SHA256(span)=01b34d231b4ba95467304a7870709bbf3ba89cda4020de8514993a89c5437fce.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_80180D78->D_80187668.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
#include "psx_types.h"
void *func_8013767C();
void func_80147324();
void func_80146CA0();
extern void *D_80187668[];
typedef struct {
    u8 pad[0x198];
    void *ptr;
    u8 pad19C[4];
    u8 idx;
} T;
void func_8015FD74(T *p) {
    func_80147324(0x18);
    p->ptr = func_8013767C(D_80187668[p->idx]);
    func_80146CA0(p);
}
