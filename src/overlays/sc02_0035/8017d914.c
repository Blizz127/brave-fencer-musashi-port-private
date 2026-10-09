/* SC02.CD member35: func_8017D914 from Druthulu/BFM-decomp
 * src/ov_SC02_035/ov_SC02_035_jr_8017BEBC.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc02_0035 retail words (gcc-2.7.2 -O2). */
typedef unsigned short u16;
typedef short s16;
typedef int s32;
typedef struct {
        u16 x;
        u16 y;
        u16 z;
        u16 w;
    } V4_8017FAC0_8017D914;
extern void func_8012A568(void (*a0)(void));
extern u16 D_80126B96;
extern s32 func_8012DEB8(s32 a0, s32 a1, s32 a2);
extern s32 func_8012BD14(s32 a0);
extern void func_8002D59C(s32 a0, u16 a1, s32 a2);

void func_8017D914(s32 a0) {
    extern u16 D_80126B62;
    extern u16 D_80126B96;
    extern u16 D_80196924[];
    extern u16 D_8019694C[];
    extern u16 D_80196974[];
    extern void (*D_8019699C[])(s32);
    V4_8017FAC0_8017D914 p1;
    V4_8017FAC0_8017D914 p2;
    s32 i;
    s32 t;
    s32 y;
    s32 ret;
    t = *(s16 *)(a0 + 0xA) + 0x20;
    y = *(s16 *)&D_80126B62 - t;
    if (y < -0x110) {
        y = -0x110;
    } else if (y > 0) {
        y = 0;
    }
    p1.y = y;
    p2.y = y;
    for (i = 0; i < 20; i += 4) {
        p1.x = D_80196924[i];
        p1.z = D_80196924[i + 1];
        p2.x = D_80196924[i + 2];
        p2.z = D_80196924[i + 3];
        if (func_8012DEB8(a0, (s32)&p1, (s32)&p2) == 1) {
            D_80126B96 = 0x4004;
        }
    }
    for (i = 0; i < 20; i += 4) {
        p1.x = D_8019694C[i];
        p1.z = D_8019694C[i + 1];
        p2.x = D_8019694C[i + 2];
        p2.z = D_8019694C[i + 3];
        if (func_8012DEB8(a0, (s32)&p1, (s32)&p2) == 1) {
            D_80126B96 = 0x4004;
        }
    }
    for (i = 0; i < 20; i += 4) {
        p1.x = D_80196974[i];
        p1.z = D_80196974[i + 1];
        p2.x = D_80196974[i + 2];
        p2.z = D_80196974[i + 3];
        if (func_8012DEB8(a0, (s32)&p1, (s32)&p2) == 1) {
            D_80126B96 = 0x4004;
        }
    }
    D_8019699C[*(u16 *)(a0 + 0x2)](a0);
    ret = func_8012BD14(a0);
    if (ret > 0x3FFFF) {
        *(s16 *)(a0 + 0xFE) = 1;
        func_8002D59C(4, 0x609, *(u16 *)(a0 + 0x70));
    } else {
        *(s16 *)(a0 + 0xFE) = *(u16 *)(a0 + 0xFE) - 1;
        if (*(s16 *)(a0 + 0xFE) == 0) {
            *(s16 *)(a0 + 0xFE) = 4;
            func_8002D59C(0x609, ((0x40000 - ret) * 127) / 0x40000 | 0x1000,
                          *(u16 *)(a0 + 0x70));
        }
    }
}
