/* SC02.CD member35: func_8017FE60 from Druthulu/BFM-decomp
 * src/ov_SC02_035/ov_SC02_035_jr_8017BEBC.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc02_0035 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef int s32;
extern void func_8002D4C8(s32 a0, s32 a1);
extern s32 func_8005C49C(void);
extern int func_8005C49C(void);
extern void func_8012A568(void (*a0)(void));
extern void func_8002D4C8(s32 a0, s32 a1);
extern void func_8002D4C8(s32 a0, s32 a1);
extern void func_8002D4C8(s32 a0, s32 a1);
extern s32 func_8005C49C(void);
extern s32 func_8005C49C(void);
extern s32 func_8005C49C(void);
extern void func_8012E8A8(u8 *a0);
extern s32 func_8005C49C(void);
extern s32 func_8005C49C(void);
extern void func_8002D4C8(s32 a0, s32 a1);
extern s32 func_8005C49C(void);
extern s32 func_801803F8(void *a0, s32 a1, s32 a2, s32 a3);
extern s32 func_8005C49C(void);
extern s32 func_801803F8(void *a0, s32 a1, s32 a2, s32 a3);
extern void func_8012E8A8(u8 *a0);
extern void func_8002D4C8(s32 a0, s32 a1);
s32 func_801803F8(void *a0, s32 a1, s32 a2, s32 a3);

void func_8017FE60(s32 a0) {
    u16 buf[3];
    s32 angle1;
    s32 angle2;
    s32 maskraw;
    s32 flags;
    s32 head1;
    s32 head2;
    s32 i;
    s32 ret1;
    s32 ret2;
    buf[0] = *(u16 *)(a0 + 0x6);
    buf[1] = *(u16 *)(a0 + 0xA);
    buf[2] = *(u16 *)(a0 + 0xE);
    head1 = 0;
    head2 = 0;
    {
        s32 fieldval = *(u16 *)(*(s32 *)(a0 + 0x20) + 0x12);
        angle1 = fieldval + 0x400;
        flags = *(u16 *)(a0 + 0x70);
        maskraw = flags & 0xF;
        angle2 = fieldval - 0x400;
    }
    if ((flags & 1) == 0) {
        s32 mask;
        s32 negoffset;
        i = 0;
        negoffset = -0x60000;
        mask = maskraw;
        while (i < 4) {
            func_801803F8(buf, angle1 * 0x10000 >> 0x10, func_8005C49C() % 4 * -0x10000 + negoffset, mask);
            func_801803F8(buf, angle2 * 0x10000 >> 0x10, func_8005C49C() % 4 * -0x10000 + negoffset, mask);
            i++;
        }
    } else {
        s32 mask;
        i = 0;
        mask = maskraw;
        for (; i < 4; i++) {
            ret1 = func_801803F8(buf, angle1 * 0x10000 >> 0x10, func_8005C49C() % 4 * -0x10000 + -0x60000, mask);
            ret2 = func_801803F8(buf, angle2 * 0x10000 >> 0x10, func_8005C49C() % 4 * -0x10000 + -0x60000, mask);
            if (ret1 != 0) {
                if (head1 != 0) {
                    *(s32 *)(ret1 + 0x2C) = head1;
                    *(s32 *)(head1 + 0x30) = *(s32 *)(head1 + 0x30) + 1;
                } else {
                    *(s32 *)(ret1 + 0x2C) = -1;
                    *(s32 *)(ret1 + 0x24) = a0;
                    head1 = ret1;
                }
            }
            if (ret2 != 0) {
                if (head2 != 0) {
                    *(s32 *)(ret2 + 0x2C) = head2;
                    *(s32 *)(head2 + 0x30) = *(s32 *)(head2 + 0x30) + 1;
                } else {
                    *(s32 *)(ret2 + 0x2C) = -1;
                    *(s32 *)(ret2 + 0x24) = a0;
                    head2 = ret2;
                }
            }
        }
    }
    func_8012E8A8((u8 *)a0);
    func_8002D4C8(0xA65, 0);
}
