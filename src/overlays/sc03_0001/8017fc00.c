/* sc03_0001: func_8017FC00 from Druthulu/BFM-decomp
 * src/ov_SC03_001/ov_SC03_001_jr_8017AE2C.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0001 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef int s32;
typedef struct {
    u8 unk00[0x16];
    s16 unk16;
    u8 unk18[4];
    s32 unk1C;
    u8 unk20[4];
} Ent_8017D6EC;
extern void func_8002D4C8(s32 a0, s32 a1);
extern void func_8012A568(void (*a0)(void));
extern s32 func_80013450(s32, s32);
extern void func_8004914C(void *a0);
extern void func_800491AC(void *a0);
extern void func_8017E204(void *arg0);
extern void func_8017E204(void *arg0);
void aF8017E1B4(void) __asm__("func_8017E1B4");
void func_8017E204(void *arg0);
extern void func_8002D4C8(s32 a0, s32 a1);
extern void func_8002D4C8(s32 a0, s32 a1);
extern void func_8004914C(void *a0);
extern void func_800491AC(void *a0);
extern s32 func_8004955C(s32, s32, s32 *, s32 *);
extern void func_8002D4C8(s32 a0, s32 a1);

void func_8017FC00(void)
{
    extern u16 D_800B99DA;
    extern s32 D_80126B58;
    extern u8 D_800AF648;
    extern s32 D_80191968;
    extern s32 func_80013450(s32, s32);
    s32 *p = &D_80126B58;
    s32 sxy, pv, flag;
    s16 x;
    s32 pan;
    s32 dist;
    s32 vol;
    if (!(D_800B99DA & 1)) {
        func_8004914C(&D_800AF648);
        func_800491AC(&D_800AF648);
        if (func_8004955C((s32)&D_80191968, (s32)&sxy, &pv, &flag) <= 0 || flag < 0) {
            func_8002D4C8(4, 0x7E6);
        } else {
            x = *(u16 *)&sxy + 0xA0;
            *(s16 *)&sxy = x;
            if (x < 0) {
                x = 0;
                *(s16 *)&sxy = x;
            } else if (x >= 0x141) {
                x = 0x140;
                *(s16 *)&sxy = x;
            }
            x = *(s16 *)&sxy;
            pan = (x * 15) / 320;
            dist = func_80013450((s32)(p + 1), (s32)&D_80191968);
            if (dist >= 0x240) {
                dist = 0x23F;
            }
            {
                s32 panpart;
                vol = ((0x23F - dist) * 127) / 576;
                panpart = ((pan << 8) & 0xF00) | 0x3000;
                func_8002D4C8(0x7E6, panpart | (vol & 0x7F));
            }
        }
    }
}
