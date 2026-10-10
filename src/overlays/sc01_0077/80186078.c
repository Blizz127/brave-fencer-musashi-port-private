/* sc01_0077: func_80186078 from Druthulu/BFM-decomp
 * src/ov_SC01_077/ov_SC01_077_jr_80183CF4.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc01_0077 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef short s16;
typedef int s32;
extern void func_8012A568(void (*a0)(void));
extern void func_8012F214(s32 a0, s32 a1, s32 a2);
extern s32 func_8012BEE8(s32 a0);
extern void func_8012C218(void *a0);
extern s32 func_8012C588(s32 a0, s32 a1);
extern void func_8012A828(s32, void *);
extern void func_8012A828(s32 a0, void *a1);
extern void func_8012A828(int, void *);
extern int func_8012BEE8(int a0);
extern void func_8012A828(int a0, void *a1);
extern void func_8012C218(void *a0);
extern void func_8012A828(s32 a0, void *a1);
extern void func_8012A828(s32 a0, void *a1);
extern void func_8012A828(s32 a0, void *a1);
extern void func_8012A828(s32 a0, void *a1);
extern void func_8012A828(s32 a0, void *a1);
extern void func_8012F214(s32 a0, s32 a1, s32 a2);
extern s32 func_8012BEE8(s32 a0);
extern void func_8012A828(s32 a0, void *a1);
extern void func_8012C218(void *a0);
extern s32 func_8012BEE8(s32);
extern s32 func_8012BEE8(s32 a0);
extern s32 func_8012BEE8(s32 a0);
extern void func_8012A828(int, void *);
extern s32 func_8012C588(s32 a0, s32 a1);
extern void func_8012A828(s32, void *);
extern s32 func_8012C588(s32 a0, s32 a1);
extern s32 func_8012BEE8(s32 a0);
extern void func_8012C218(void *a0);
extern void func_8012F214(s32 a0, s32 a1, s32 a2);
extern s32 func_8012BEE8(s32 a0);
extern void func_8012C218(void *a0);
extern s32 func_8012BEE8(s32 a0);
extern void func_8012A828(s32 a0, void *a1);
extern void func_8012A828(s32 a0, void * a1);
extern s32 func_8012BEE8(s32 a0);
extern void func_8012C218(void *a0);
extern s32 func_8012C588(s32 a0, s32 a1);
extern void func_8012F214(s32 a0, s32 a1, s32 a2);
extern void func_80186330(void *arg0);
void func_80186330(void *arg0);

void func_80186078(s32 arg0) {
    extern s32 D_801DA988;
    extern s16 D_801DA98A[];
    extern s32 D_801DA98C;
    extern s16 D_801DA98E[];
    extern s32 D_801DA990;
    extern s16 D_801DA992[];
    extern s32 D_801D55AC[];
    extern u8 D_801D5568;
    extern u8 D_801D5558;
    u16 in[4];
    u16 out[4];
    s32 *p1;
    s32 *p2;
    s32 *p3;
    s32 t;
    s32 o;
    s32 base;
    s32 idx;
    u16 *dst;
    *(s32 *)(*(s32 *)(arg0 + 0x20) + 0x48) = *(s16 *)(arg0 + 0xDC);
    *(s32 *)(*(s32 *)(arg0 + 0x20) + 0x50) = *(s16 *)(arg0 + 0xDE);
    in[0] = (*(s32 *)(arg0 + 0x1C) & 1) << 2;
    in[2] = 0;
    in[1] = 0;
    func_8012F214(arg0, (s32)&in[0], (s32)&out[0]);
    *(u16 *)(arg0 + 6) = out[0];
    *(u16 *)(arg0 + 0xE) = out[2];
    *(s16 *)(arg0 + 0x98) = 0;
    base = *(s32 *)(*(s32 *)(arg0 + 0x90));
    idx = *(s16 *)(arg0 + 0xFC);
    *(s32 *)(arg0 + 0x10) += *(s32 *)(arg0 + 0x44);
    *(s32 *)(arg0 + 0x14) += *(s32 *)(arg0 + 0x48);
    *(s32 *)(arg0 + 0x18) += *(s32 *)(arg0 + 0x4C);
    p1 = &D_801DA988;
    *p1 += *(s32 *)(arg0 + 0x10);
    p2 = &D_801DA98C;
    *p2 += *(s32 *)(arg0 + 0x14);
    p3 = &D_801DA990;
    *p3 += *(s32 *)(arg0 + 0x18);
    dst = (u16 *)(base + idx * 12);
    dst[0] = *(u16 *)D_801DA98A - in[0];
    dst[1] = *(u16 *)D_801DA98E;
    dst[2] = *(u16 *)D_801DA992 - in[2];
    if (*(s32 *)(arg0 + 0x1C) >= 0xB) {
        o = func_8012C588(0x24, arg0);
        if (o != 0) {
            in[0] = dst[0];
            in[1] = dst[1];
            in[2] = dst[2];
            func_8012F214(arg0, (s32)&in[0], (s32)&out[0]);
            *(u16 *)(o + 6) = out[0];
            *(u16 *)(o + 0xA) = out[1];
            *(u16 *)(o + 0xE) = out[2];
        }
    }
    if (func_8012BEE8(arg0) != 0) {
        if (*(s16 *)(arg0 + 0x76) <= 0) {
            if (*(s16 *)(arg0 + 0x70) == 4) {
                func_8012C218((void *)arg0);
            } else {
                func_80186330((void *)arg0);
            }
        } else {
            ((void (*)(s32, s32))func_8012A828)(arg0, D_801D55AC[*(s16 *)(arg0 + 0x76)]);
            *(s16 *)(arg0 + 2) = 1;
            if (*(s16 *)(arg0 + 0x70) == 4) {
                *(s32 *)(arg0 + 0x58) = (s32)&D_801D5568;
            } else {
                *(s32 *)(arg0 + 0x58) = (s32)&D_801D5558;
            }
            *(u32 *)(arg0 + 0x58) |= 0x60000000;
            t = *(s32 *)(arg0 + 0x20);
            *(u16 *)(t + 0x1C) = 0x1C00;
            *(u16 *)(t + 0x1A) = 0x1C00;
            *(u16 *)(t + 0x18) = 0x1C00;
            *(u16 *)(arg0 + 0x5E) = 0;
            *(u16 *)(arg0 + 0x5C) |= 0x8800;
            *(u16 *)(arg0 + 6) = *(u16 *)(arg0 + 0xDC);
            *(u16 *)(arg0 + 0xE) = *(u16 *)(arg0 + 0xDE);
        }
    }
}
