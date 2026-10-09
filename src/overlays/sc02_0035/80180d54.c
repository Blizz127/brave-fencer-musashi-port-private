/* SC02.CD member35: func_80180D54 from Druthulu/BFM-decomp
 * src/ov_SC02_035/ov_SC02_035_jr_8017BEBC.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc02_0035 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef int s32;
typedef struct {
    u8 f0, f1, f2, f3;
    struct { s16 a, b, c, d, e, g; } ent[16];
} Blk_8016CF04;
typedef struct {
    u8 f0, f1, f2, f3;
    struct { s16 a, b, c, d, e, g; } ent[16];
} Blk_8016CF04_8016CF04;
typedef struct {
    s32 op;
    union {
        s32 w;
        void *p;
        s16 h[2];
        u16 uh[2];
    } a;
} Cmd_80178D40;
extern void func_8012A568(void (*a0)(void));
extern s32 func_8012C658(s32 arg0, s32 arg1, s32 arg2);
extern void func_8012C218(void *a0);
extern s32 func_8012C658(s32 arg0, s32 arg1, s32 arg2);
extern void func_8012A828(s32*, s32);
extern s32 func_8012C658(s32 arg0, s32 arg1, s32 arg2);
extern void func_8012A828(s32*, s32);
extern void func_8012C218(void *a0);
extern void func_8012A828(s32*, s32);
extern void func_8012A828(s32*, s32);
extern s32 func_8012B030(u8 *a0);
extern void func_8018016C(s32 a0, s32 a1);
extern s32 func_8012B030(u8 *a0);
extern s32 func_80182318_def(s32 a0, s32 a1) __asm__("func_8018016C");
s32 func_80182318_def(s32 a0, s32 a1);
extern s32 func_8012CEB0(s32 a0, s32 a1, s32 a2);
extern s32 func_8012CEB0(s32 a0, s32 a1, s32 a2);
extern void func_8002AC00(s32 arg0);
extern s32 func_8012CEB0(s32 a0, s32 a1, s32 a2);
extern void func_8001C214(s32 a0, s32 a1);
extern void func_8012A828(s32*, s32);
extern s32 func_8012C658(s32 arg0, s32 arg1, s32 arg2);
extern void func_8012C218(void *a0);
extern s32 func_8012B030(u8 *a0);

void func_80180D54(void *a0) {
    extern s32 D_801A257C;
    extern s32 D_801A9CC0;
    u16 buf[8];
    s32 ent;
    u16 saved;
    u16 v0;
    register u16 v1 __asm__("$3");
    register u16 a3 __asm__("$7");
    func_8002AC00(0xD);
    if (*(u16 *)((s32)a0 + 0x0) != 0) {
        v0 = *(u16 *)((s32)a0 + 0x6);
        buf[0] = v0;
        buf[4] = v0;
        v1 = *(u16 *)((s32)a0 + 0xA);
        v0 = v1 - 8;
        buf[1] = v1;
        buf[5] = v1;
        a3 = *(u16 *)((s32)a0 + 0xE);
        v1 = v1 + 8;
        buf[1] = v0;
        buf[5] = v1;
        buf[2] = a3;
        buf[6] = a3;
        if ((func_8012CEB0((s32)&buf[0], (s32)&buf[4], 0) & 0x1F) == 0) {
            if ((*(s16 *)((s32)a0 + 0x100) & 0x8000) == 0) {
                saved = *(u16 *)(*(s32 *)((s32)a0 + 0x20) + 0x12);
                func_8001C214(*(s32 *)((s32)a0 + 0x20), (s32)&D_801A257C);
                ((void (*)(s32, s32))func_8012A828)((s32)a0, (s32)&D_801A9CC0);
                *(u16 *)(*(s32 *)((s32)a0 + 0x20) + 0x12) = saved;
                ent = func_8012C658(0x12C, 1, (s32)a0);
                if (ent != 0) {
                    if (*(s16 *)((s32)a0 + 0xA) >= 0x10) {
                        func_8012C218((void *)ent);
                    } else {
                        *(u16 *)(*(s32 *)(ent + 0x20) + 0x12) = saved;
                        func_8012B030((u8 *)ent);
                        if (*(s16 *)((s32)a0 + 0x70) == 5) {
                            s16 t = *(s16 *)((s32)a0 + 0x100);
                            *(s16 *)(ent + 0x70) = 6;
                            *(s16 *)(ent + 0xFE) = 1;
                            *(s16 *)(ent + 0x100) = t;
                            do {
                                func_8012C658(0x12F, 5, ent);
                                *(s16 *)(ent + 0xFE) = *(u16 *)(ent + 0xFE) + 3;
                            } while (*(s16 *)(ent + 0xFE) < 0x10);
                            *(s16 *)(ent + 0xFE) = 0;
                        }
                    }
                }
            }
        }
    }
}
