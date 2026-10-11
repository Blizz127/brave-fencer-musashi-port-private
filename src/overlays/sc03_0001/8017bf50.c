/* sc03_0001: func_8017BF50 from Druthulu/BFM-decomp
 * src/ov_SC03_001/ov_SC03_001_jr_8017AE2C.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0001 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef int s32;
typedef struct {
    s16 unk00;
    s16 unk02;
    s16 unk04;
    s16 unk06;
    s16 unk08;
    s16 unk0A;
    s16 unk0C;
    s16 unk0E;
    s32 unk10;
} Buf8017BF50;
extern void func_8012A568(void (*a0)(void));
extern u8 D_801EE680[];
extern u8 *func_8012913C(s32 a0);
extern s32 func_8012C750(s32 a0);

void func_8017BF50(s32 a0)
{
    s32 s3;
    s16 *s0;
    register s32 *s1 asm("$17");
    u8 *s2;
    s16 s4;
    Buf8017BF50 buf;
    s3 = a0;
    s0 = *(s16 **)(s3 + 0xDC);
    if (s0 != 0) {
        s2 = D_801EE680;
        s4 = 0;
        s1 = (s32 *)(D_801EE680 + 0x1C);
        buf.unk06 = 0x158;
        buf.unk0A = 0;
        buf.unk08 = 0;
        buf.unk0E = 0;
        buf.unk10 = 0;
        do {
            u16 v1;
            v1 = (u16)*s0;
            if ((v1 & 0xFFFF) == 0x8000) break;
            if (*(s16 *)(s3 + 0x70) != 0) {
                buf.unk00 = *s0++;
                buf.unk02 = *s0++;
                buf.unk04 = *s0++;
                if (((s32 (*)(void *))func_8012C750)(&buf) == 0) break;
            } else {
                s32 v3;
                v3 = ((s32 (*)(s32))func_8012913C)(0x11);
                if (v3 == 0) break;
                s1[-2] = *s0++;
                s1[-1] = *s0++;
                s1[0] = *s0++;
                s1 += 8;
                *(u8 **)(v3 + 0x30) = s2;
                s2 += 0x20;
            }
            s4++;
        } while (s4 < 0x10);
    }
    *(u16 *)(s3 + 2) += 1;
}
