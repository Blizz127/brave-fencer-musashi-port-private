/* sc03_0001: func_8017DF78 from Druthulu/BFM-decomp
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
} Ent_8017D6EC_8017DEE8;
extern u8 D_800AF630[];
extern void func_8012A568(void (*a0)(void));
extern s32 func_8004787C(s32 a0);
extern u8 D_80078EB1;
extern u8 D_80078E78[];
extern u8 D_800AF630[];
extern s32 func_8004787C(s32 a0);
extern void func_8012AD44(s32 *a0, s16 a1);
extern void func_8017E1B4(void *a0);
extern void func_8017E2C0(void *arg0);
void func_8017E2C0(void *arg0);

void func_8017DF78(void *arg0)
{
    extern Ent_8017D6EC_8017DEE8 D_801EE888[];
    u8 *m;
    u8 *e78;
    s32 k;
    m = D_800AF630;
    e78 = D_80078E78;
    if (D_80078EB1 >= 9) {
        s32 count;
        s32 i;
        u8 *base;
        base = (u8 *)D_801EE888;
        count = 0;
        for (i = 0; i < 4; i++) {
            if (*(s32 *)(base + i * 0x24 + 0x1C) == 0) {
                count++;
            }
        }
        if (count == 0) {
            func_8012AD44((s32 *)arg0, 0);
            return;
        }
    }
    for (k = 0; k < 4; k++) {
        u8 *p = (u8 *)D_801EE888 + k * 0x24;
        s32 c;
        if (*(s32 *)(p + 0x1C) != 0) {
            continue;
        }
        {
            s16 val = *(s16 *)(p + 0xC);
            if (val < 0x401) {
                *(s16 *)(p + 0xC) = val + 0xB;
            } else if (*(s32 *)(p + 0x18) != 0) {
                *(s32 *)(p + 0x18) -= 1;
            } else {
                *(s16 *)(p + 0xC) = val + 0xB;
            }
        }
        if (*(s16 *)(p + 0xC) >= 0x801) {
            *(s16 *)(p + 0xC) = 0;
        }
        c = (func_8004787C(*(s16 *)(p + 0xC)) / 64) & 0xFF;
        c = c | (c << 16 | c << 8);
        *(s32 *)(p + 0x4) = c;
        c = (func_8004787C(*(s16 *)(p + 0xC)) / 256) & 0xFF;
        c = c | (c << 16 | c << 8);
        *(s32 *)(p + 0x8) = c;
        if ((*(u16 *)(m + 0xA3AA) & 1) == 0) {
            s16 cnt = *(u16 *)(p + 0xE) + 1;
            *(u16 *)(p + 0xE) = cnt;
            if (cnt >= 0x40) {
                *(u16 *)(p + 0xE) = 0;
            }
        }
        {
            s32 val2 = *(s16 *)(p + 0xC);
            if (val2 == 0) {
                *(s32 *)(p + 0x1C) = 1;
            } else if (val2 >= 0x556) {
                if (*(s32 *)(p + 0x20) == 0) {
                    *(s32 *)(p + 0x20) = 1;
                    if (e78[0x39] < 9) {
                        func_8017E1B4(p);
                    }
                }
            }
        }
        func_8017E2C0(p);
    }
}
