/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CC7FC - byte-exact against retail at -O2 (tools/register_match.py). */
typedef struct { char b[4]; } W;
typedef struct { s16 m[9]; s16 pad; s32 t[3]; s32 rest[8]; } Mtx;
typedef struct { s16 x, y, z; } Vec3s;
extern void func_80015978(s32 a0, void *a1);
extern void func_8012EFB8();
extern void func_80013F3C(s32 a0);
extern void func_800123F0(s32 a0, s32 a1);
extern void func_80020F34(s32 a0, s32 a1);
extern void func_8012F14C(s32 a0, s32 a1, s32 a2);
extern void func_80017714();

void func_800CC7FC(s32 a0, void *a1, void *a2, void *a3, void *a4) {
    extern s32 D_800CCA3C;
    extern s32 D_800CCA44;
    extern s32 D_800CCA4C;
    extern s32 D_800CCA54;

    Mtx buf;
    Vec3s v1;
    Vec3s v2;

    *(u32 *)((s32)a4 + 0x30) = 0x50000000;
    *(W *)((s32)a4 + 0x20) = *(W *)a1;
    *(W *)((s32)a4 + 0x24) = *(W *)a1;
    *(W *)((s32)a4 + 0x28) = *(W *)a2;
    *(W *)((s32)a4 + 0x2c) = *(W *)a2;

    func_80015978(a0 + 4, &v1);
    ((void (*)())func_8012EFB8)(&v1, &v1);
    func_80013F3C((s32)&buf);
    func_800123F0((s32)&buf, *(s16 *)((s32)a3 + 6));

    v2.x = *(u16 *)((s32)a3 + 0);
    v2.y = *(u16 *)((s32)a3 + 2);
    v2.z = *(u16 *)((s32)a3 + 4);
    func_80020F34((s32)&buf, (s32)&v2);

    buf.t[0] = v1.x;
    buf.t[1] = v1.y;
    buf.t[2] = v1.z;
    func_8012F14C((s32)&buf, (s32)&D_800CCA3C, (s32)a4);
    func_8012F14C((s32)&buf, (s32)&D_800CCA44, (s32)a4 + 8);
    func_8012F14C((s32)&buf, (s32)&D_800CCA4C, (s32)a4 + 0x10);
    func_8012F14C((s32)&buf, (s32)&D_800CCA54, (s32)a4 + 0x18);

    *(s16 *)((s32)a4 + 4) = 0;
    *(s16 *)((s32)a4 + 0xc) = 0;
    *(s16 *)((s32)a4 + 0x14) = 0;
    *(s16 *)((s32)a4 + 0x1c) = 0;
    func_80017714(a4);
}
