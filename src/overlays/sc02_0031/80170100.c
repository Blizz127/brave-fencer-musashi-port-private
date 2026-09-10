/* SC02.CD FILE_031 / ov_SC02_031 retail span [80170100,80170150).
 * Offset 0x47FA8 at overlay base 80128158. SHA256(span)=55538d12747b9febe4138271ea448ce2eaf3c3ff2407fd0f79767778931db09f.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80170100.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"
s32 func_801399F0();
void func_80139914();
void func_80171928();
typedef struct { u8 pad[0x198]; s32 p198; } T;
void func_80170100(T *p) {
    if (func_801399F0(p->p198)) {
        func_80139914(p->p198);
        p->p198 = 0;
        func_80171928(p);
    }
}
