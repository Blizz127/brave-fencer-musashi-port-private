/* sc01_0077: func_8017BEF8 from Druthulu/BFM-decomp
 * src/ov_SC01_077/ov_SC01_077_jr_8017AE2C.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc01_0077 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef short s16;
typedef int s32;
struct obj;
struct obj {
    u8 pad0[0x4];
    s16 unk4;
    u8 pad6[0x2];
    s32 unk8;
};
typedef struct {
    u16 x, y, z, xpad;
    u16 vx, vy, vz, vpad;
    s32 dead[8];
} Work8017;
extern s32 func_80146A6C(s32 a0, void *a1, s32 a2, s32 a3, s32 a4, s32 a5, s32 a6);
extern void func_80146C3C();
extern void func_80146C3C(void);
extern void func_800D20C0(void *a0, void *a1, s32 a2);
extern void func_800D23D0(void *a0);
extern void func_800D20C0();
extern void func_8012A568(void (*a0)(void));
extern s32 func_80146A6C(s32 a0, void *a1, s32 a2, s32 a3, s32 a4, s32 a5, s32 a6);
extern void func_800D20C0(void *a0, void *a1, s32 a2);
extern void func_800D23D0(void *a0);
extern s32 func_800D222C(s32 a0, void *a1, s32 a2);
extern s32 func_8001CF30(void *a0);
extern void func_80146C3C(void);
extern u8 D_8018A508;

void func_8017BEF8(s32 param_1) {
    s32 obj = *(s32 *)(param_1 + 0x34);
    Work8017 w;
    short i;
    s32 e;
    s32 node;
    func_80146A6C(0x11, (void *)param_1, *(s16 *)(param_1 + 6),
                  (s16)(*(u16 *)(param_1 + 0xA) - 0x10),
                  *(s16 *)(param_1 + 0xE), 0, 0);
    w.x = *(u16 *)(param_1 + 6);
    w.y = *(u16 *)(param_1 + 0xA);
    w.z = *(u16 *)(param_1 + 0xE);
    func_800D20C0(&w.x, &w.vx, 10);
    *(s16 *)(param_1 + 6) = w.x;
    *(s16 *)(param_1 + 0xE) = w.z;
    w.vy = 0;
    func_800D23D0(&w.vx);
    i = 0;
    do {
        e = func_80146A6C(0x12, (void *)param_1, *(s16 *)(obj + 6),
                          *(s16 *)(obj + 0xA), *(s16 *)(obj + 0xE), i, 0);
        if (e != 0) {
            *(s16 *)(e + 0x12) = w.vx;
            *(s16 *)(e + 0x16) = w.vy;
            *(s16 *)(e + 0x1A) = 0;
        }
        i = i + 1;
    } while (i < 3);
    node = func_800D222C(param_1, &D_8018A508, 0xFD);
    if (node != 0) {
        *(s32 *)(param_1 + 0x20) = node;
        *(u32 *)(node + 4) = *(u32 *)(node + 4) | 0x5D000100;
        ((void (*)(void *))func_8001CF30)((void *)node);
        *(s16 *)(node + 0x18) = 0x4000;
        *(s16 *)(node + 0x1A) = 0x200;
        *(s16 *)(param_1 + 0x16) = 0x200;
        *(s16 *)(param_1 + 0x14) = 0x1000;
        *(s16 *)(node + 0x28) = 0x240;
        *(s16 *)(node + 0x2A) = 0x180;
        *(s16 *)(node + 0x10) = w.vx;
        *(s16 *)(node + 0x12) = w.vy;
        *(s16 *)(param_1 + 2) = *(s16 *)(param_1 + 2) + 1;
    } else {
        ((void (*)(s32))func_80146C3C)(param_1);
    }
}
