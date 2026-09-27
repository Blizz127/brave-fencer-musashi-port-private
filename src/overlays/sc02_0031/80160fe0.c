/* SC02.CD FILE_031 / ov_SC02_031 retail span [80160FE0,80161034).
 * Offset 0x38E88 at overlay base 80128158. SHA256(span)=1ad0627ab36df6573858465d58627418f4cc430426cb9e8e6bdf6679c100168b.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80160fe0.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"
void func_80149020();
s32 func_801399F0();
void func_80139914();
void func_80146CA0();
typedef struct { u8 pad[0x198]; s32 p198; } T;
void func_80160FE0(T *p) {
    func_80149020(p);
    if (func_801399F0(p->p198)) {
        func_80139914(p->p198);
        p->p198 = 0;
        func_80146CA0(p);
    }
}
