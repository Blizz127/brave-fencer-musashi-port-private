/* SC02.CD FILE_031 / ov_SC02_031 retail span [8012B1B4,8012B200).
 * Offset 0x305C at overlay base 80128158. SHA256(span)=0bfac1bc003dd13ab61f9ba8cdb74f43f471aab93ea5cc65ec9a00db2e1b4aba.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8012b1b4.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"
void func_800484EC();
typedef struct { u8 pad[0x10]; s32 u10; u8 pad14[4]; s32 u18; } Inner;
typedef struct { u8 pad[0x10]; s32 u10; u8 pad14[4]; s32 u18; u8 pad1C[4]; u8 *inner; } T;
void func_8012B1B4(T *p, void *a1) {
    s32 tmp[4];
    func_800484EC(p->inner + 0x34, a1, tmp);
    p->u10 = tmp[0];
    p->u18 = tmp[2];
}
