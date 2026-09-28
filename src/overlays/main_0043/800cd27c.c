/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CD27C - byte-exact against retail at -O2 (tools/register_match.py). */
typedef struct {
    s16 m[9];
    s16 pad;
    s32 t[3];
} Mtx_800CD27C;
typedef struct {
    Mtx_800CD27C mt;  
    s32 rest[2];      
} MtxBuf_800CD27C;
extern void func_80013F3C(s32 a0);
extern void func_800126C4(s32 a0, s32 a1);
extern void func_800123F0(s32 a0, s32 a1);
extern void func_80012558(s32 a0, s32 a1);

void func_800CD27C(s32 a0) {
    MtxBuf_800CD27C buf;
    s32 obj;

    obj = *(s32 *)(a0 + 0x20);
    func_80013F3C((s32)&buf);
    func_800126C4((s32)&buf, *(s16 *)(obj + 0x10));
    func_800123F0((s32)&buf, *(s16 *)(obj + 0x14));
    func_80012558((s32)&buf, *(s16 *)(obj + 0x12));
    func_800126C4((s32)&buf, 0x400);
    *(Mtx_800CD27C *)(*(s32 *)(obj + 0x34)) = buf.mt;
}
