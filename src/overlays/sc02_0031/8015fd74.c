/* SC02.CD FILE_031 / ov_SC02_031 retail span [8015FD74,8015FDCC).
 * Offset 0x37C1C at overlay base 80128158. SHA256(span)=37e51dc5155bf9f5859484406871a6403310221b435016991eb805a5661d73ce.
 * Differs from the registry-verified MAIN member 0012 carve in exactly one
 * data reference: D_80180D78 here is D_80181600 (+0x888 member
 * data-block shift). Oracle MATCH re-earned on this file; Not MAIN10.
 */
#include "psx_types.h"
void *func_8013767C();
void func_80147324();
void func_80146CA0();
extern void *D_80181600[];
typedef struct {
    u8 pad[0x198];
    void *ptr;
    u8 pad19C[4];
    u8 idx;
} T;
void func_8015FD74(T *p) {
    func_80147324(0x18);
    p->ptr = func_8013767C(D_80181600[p->idx]);
    func_80146CA0(p);
}
