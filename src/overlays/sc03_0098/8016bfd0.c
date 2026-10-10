/* sc03_0098: func_8016BFD0 from Druthulu/BFM-decomp
 * src/ov_SC03_098/ov_SC03_098_jr_8016AB6C.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0098 retail words (gcc-2.7.2 -O2). */
typedef unsigned short u16;
typedef unsigned int u32;
typedef short s16;
typedef int s32;
typedef struct {
    s16 m[9];
    s16 pad;
    s32 t[3];
    s32 rest[8];
} Mtx_8016BFD0;
typedef struct { s16 x, y, z; } Vec3_8016BFD0;
typedef struct { char b[4]; } W_8016BFD0;
extern void func_80013F3C(s32 a0);
extern void func_800123F0(s32 a0, s32 a1);
extern void func_8012F14C(s32 a0, s32 a1, s32 a2);
extern void func_8012EFB8(s32 a0);
extern void func_80020F34(s32 a0, s32 a1);
extern void func_8012EFB8(s32 a0);

void func_8016BFD0(s32 a0, s32 a1, s32 a2, s32 a3, void *a4) {
    extern void func_80017714();
    extern s32 D_80188568;
    extern s32 D_80188570;
    extern s32 D_80188578;
    extern s32 D_80188580;
    Mtx_8016BFD0 buf;
    Vec3_8016BFD0 v1;
    Vec3_8016BFD0 v2;
    s32 iVar5 = *(s32 *)(a0 + 0x20);
    *(u32 *)((s32)a4 + 0x30) = 0x50000000;
    *(W_8016BFD0 *)((s32)a4 + 0x20) = *(W_8016BFD0 *)a1;
    *(W_8016BFD0 *)((s32)a4 + 0x24) = *(W_8016BFD0 *)a1;
    *(W_8016BFD0 *)((s32)a4 + 0x28) = *(W_8016BFD0 *)a2;
    *(W_8016BFD0 *)((s32)a4 + 0x2c) = *(W_8016BFD0 *)a2;
    v1.x = *(u16 *)(a0 + 6);
    v1.y = *(u16 *)(a0 + 0xa);
    v1.z = *(u16 *)(a0 + 0xe);
    ((void(*)())func_8012EFB8)(&v1, &v1);
    ((void(*)())func_80013F3C)(&buf);
    ((void(*)())func_800123F0)(&buf, (s32)*(s16 *)(iVar5 + 0x12));
    v2.x = *(u16 *)(a3 + 0);
    v2.y = *(u16 *)(a3 + 2);
    v2.z = *(u16 *)(a3 + 4);
    ((void(*)())func_80020F34)(&buf, &v2);
    buf.t[0] = v1.x;
    buf.t[1] = v1.y;
    buf.t[2] = v1.z;
    ((void(*)())func_8012F14C)(&buf, &D_80188568, (s32)a4);
    ((void(*)())func_8012F14C)(&buf, &D_80188570, (s32)a4 + 8);
    ((void(*)())func_8012F14C)(&buf, &D_80188578, (s32)a4 + 0x10);
    ((void(*)())func_8012F14C)(&buf, &D_80188580, (s32)a4 + 0x18);
    *(s16 *)((s32)a4 + 4) = 0;
    *(s16 *)((s32)a4 + 0xc) = 0;
    *(s16 *)((s32)a4 + 0x14) = 0;
    *(s16 *)((s32)a4 + 0x1c) = 0;
    func_80017714(a4);
}
