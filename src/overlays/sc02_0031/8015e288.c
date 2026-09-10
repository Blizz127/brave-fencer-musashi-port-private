/* SC02.CD FILE_031 / ov_SC02_031 retail span [8015E288,8015E344).
 * Offset 0x36130 at overlay base 80128158. SHA256(span)=f10e8d7935c530939c9a109cb89905066aa25c2b856b88b6e9143d1d671f8394.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8015e288.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"
s32 func_80161208();
s32 func_8014A850();
void func_80154274();
void func_8015E40C();
void func_8015E588();
void func_8015E4B0();
void func_80146994();
void func_80146CA0();
void func_80146C98();
extern s32 D_800D5098;
extern s32 D_800D5060;
typedef struct { u8 pad[0xB8]; u16 uB8; } T;
void func_8015E288(T *p) {
    if (func_80161208(p)) {
        return;
    }
    if (func_8014A850(p)) {
        func_80154274(p, &D_800D5098);
        func_8015E40C(p);
        func_8015E588(p);
        func_8015E4B0(p);
        func_80146994(5, p, 0xB, 0);
        func_80146CA0(p);
    } else if (p->uB8 & 0x8000) {
        func_80154274(p, &D_800D5060);
        func_80146C98(p, 3);
    }
}
