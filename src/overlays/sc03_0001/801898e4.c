/* sc03_0001: func_801898E4 from Druthulu/BFM-decomp
 * src/ov_SC03_001/ov_SC03_001_jr_80189030.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0001 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef short s16;
typedef int s32;
extern s32 func_80029504(void);
extern s32 func_800291B4(s32 arg);
extern s32 func_80029178(s32 arg);
extern s32 func_80029178(s32 a0);
extern s32 func_80029178(s32);
extern void func_8012A568(void (*a0)(void));
extern int func_800D0F8C(int a0);
extern u32 func_801783D0(s32 a0, s32 a1);
extern char *func_8005C540(char *, const char *);
extern s16 D_80115126;
extern char D_801ED214[];
extern char D_801ED234[];
extern char D_801ED254[];
extern char D_801ED034[];
extern char D_801ED278[];
extern char D_801EEB14[];
extern char D_801EED54[];
extern char D_801EEF94[];
extern s32 func_80029178(s32);
extern s32 func_80029504(void);
extern s32 func_800291B4(s32);
extern u8 D_801C16AC[];
extern u8 D_801C168C[];
extern u8 D_801C16B4[];
extern u8 D_801C16BC[];
extern s16 D_8011515A;
extern u8 *D_801EF1D4;
extern u8 D_8010EDE8[];
extern u8 D_8010EDEC[];
extern s16 D_801EF26C;
extern u32 func_801783D0(s32, s32);
extern char D_801EEB2F[];
extern u8 D_8011514A;
extern u8 D_801EF290[];
extern u8 *D_801EB574[];
extern u8 D_801EB56C[];
extern u8 *D_801EF1DC;
extern s16 D_8011515E;
extern s32 func_800D0F8C(s32);
extern char *D_801C12EC;
extern char D_801EEB94[];
extern u8 D_8010F468[];
extern s16 D_800A6586[];
extern char D_801EED6F[];
extern char D_801EED6A[];
extern char *D_801C12F0[];
extern u16 D_8011511A;
extern u8 D_801EF298[];
extern s16 D_8011515C;
extern u8 D_8011514C;
extern u8 *D_801C12F4[];
extern u8 *D_801EF254[];
extern char *D_801C1264[];
extern char D_801EEF98[];
extern char *D_801C1324;
extern char D_801EEFA0[];

void func_801898E4(void)
{
    s32 pad[2];
    s16 i;
    s16 cnt;
    s16 k;
    s32 b;
    u8 *s;
    char *d;
    char *srcA;
    char *srcB;
    char *tmpl;
    register s32 count __asm__("$19");
    register u8 *table __asm__("$20");
    register s32 descCount __asm__("$19");
    register u8 *table2 __asm__("$20");
    srcA = D_801ED214;
    srcB = D_801ED234;
    if (D_80115126 == 4) {
        tmpl = D_801ED254;
    } else {
        tmpl = D_801ED034;
        if (D_80115126 == 5) {
            tmpl = D_801ED278;
        }
    }
    for (i = 0; i < 16; i++) {
        func_8005C540(&D_801EEB14[i * 36], srcA);
        func_8005C540(&D_801EED54[i * 36], srcB);
        func_8005C540(&D_801EEF94[i * 36], tmpl);
    }
    switch (D_80115126) {
    case 0:
        {
            if ((u8)func_80029178(0xFB) != 0) {
                i = 1;
            } else {
                i = (((u32 (*)(void))func_80029504)() >= 0x258);
            }
            if ((u8)func_80029178(0x9B) != 0) {
                i |= 2;
            }
            if ((u8)func_800291B4(0x5B) >= 3) {
                i |= 4;
            }
            count = D_801C16AC[i];
            D_8011515A = count | 0x100;
            table = *(u8 **)(D_801C168C + i * 4);
            D_801EF1D4 = table;
        }
        break;
    case 1:
        count = 7;
        if (((u32 (*)(void))func_80029504)() < 0x258) {
            count = 5;
        }
        table = D_801C16B4;
        D_8011515A = count | 0x100;
        D_801EF1D4 = table;
        break;
    case 5:
        table = D_801C16BC;
        D_801EF1D4 = table;
        count = 7;
        break;
    default:
        count = 0;
        break;
    }
    i = 0;
    if (count != 0) {
        do {
            s32 pct;
            s32 sub;
            s32 raw;
            u16 q;
            b = table[i];
            s = *(u8 **)(D_8010EDE8 + b * 12);
            d = &D_801EEB14[i * 36];
            while (*(s) != 0) { *(d)++ = *(s)++; *(d)++ = *(s)++; }
            pct = D_801EF26C;
            sub = pct;
            if (pct != 0) {
                if (D_80115126 == 0) {
                    raw = (*(s16 *)(D_8010EDE8 + b * 12 + 4) * (100 - pct)) / 100;
                } else {
                    raw = *(u16 *)(D_8010EDEC + b * 12) - sub;
                }
            } else {
                raw = *(u16 *)(D_8010F468 - 0x67C + b * 12);
            }
            q = ((s32 (*)(s16, s32))func_801783D0)(raw, 0);
            { (k) = -0x1000; for ((cnt) = 3; (cnt) >= 0; (cnt)--) { if (((q) & (k)) != 0) { break; } (k) >>= 4; } (d) = (&D_801EEB2F[i * 36]); for ((k) = 0; (k) < (cnt) + 1; (k)++, (q) >>= 4) { *(d) = ((q) & 0xF) + 0x4F; (d)--; *(d) = (0x82); (d)--; } *(d) = 0x46; (d)[-1] = 0x81; }
            i++;
        } while (i < count);
    }
    {
        u8 sel = D_801EF290[D_8011514A];
        table2 = D_801EB574[sel];
        descCount = D_801EB56C[sel];
        D_801EF1DC = table2;
        D_8011515E = descCount | 0x100;
        if (D_80115126 == 0) {
            if (func_800D0F8C(0xA) != 0) {
                func_8005C540(D_801EEB94, D_801C12EC);
            }
        }
    }
    if (D_80115126 == 3) {
        i = 0;
        if (descCount != 0) {
            do {
                register s32 zr __asm__("$0");
                s32 id;
                b = table2[i];
                s = *(u8 **)(D_8010F468 + b * 8);
                d = &D_801EED54[i * 36];
                while (*(s) != 0) { *(d)++ = *(s)++; *(d)++ = *(s)++; }
                id = b + zr;
                cnt = (u8)func_800291B4(id + 0x62);
                if ((cnt & 0x80) != 0) {
                    if ((cnt & 0x40) == 0) {
                        u16 q = ((s32 (*)(s16, s32))func_801783D0)(D_800A6586[id], 0);
                        { (k) = -0x1000; for ((cnt) = 3; (cnt) >= 0; (cnt)--) { if (((q) & (k)) != 0) { break; } (k) >>= 4; } (d) = (&D_801EED6F[i * 36]); for ((k) = 0; (k) < (cnt) + 1; (k)++, (q) >>= 4) { *(d) = ((q) & 0xF) + 0x4F; (d)--; *(d) = (0x82); (d)--; } *(d) = 0x46; (d)[-1] = 0x81; }
                    } else {
                        func_8005C540(&D_801EED6A[i * 36], D_801C12EC + 2);
                    }
                } else {
                    func_8005C540(&D_801EED54[i * 36], D_801C12F0[0]);
                }
                i++;
            } while (i < descCount);
        }
        if (D_8011511A != 1 && D_8011511A != 2) {
            i = 0;
            cnt = 0;
            for (; i < 0x40; i++) {
                if ((func_800291B4(i + 0x63) & 0x40) != 0) {
                    D_801EF298[cnt++] = i;
                }
            }
            D_8011515C = cnt | 0x100;
            if (D_8011514C >= cnt) {
                if (cnt != 0) {
                    D_8011514C = cnt - 1;
                } else {
                    D_8011514C = 0;
                }
            }
        }
    }
    if (D_80115126 == 4) {
        i = 0;
        do {
            s32 *p;
            s = D_801C12F4[i];
            d = &D_801EEF98[i * 36];
            d[0] = s[0];
            d[1] = s[1];
            d = &D_801EEF98[i * 36 + 4];
            p = ((s32 *)D_801EF254)[i];
            if (p != 0) {
                s = (u8 *)D_801C1264[p[2]];
                while (*(s) != 0) { *(d)++ = *(s)++; *(d)++ = *(s)++; }
            } else {
                func_8005C540(&D_801EEF98[i * 36 + 0x16], (char *)D_801C12F4[i + 6]);
            }
            i++;
        } while (i < 6);
    }
    if (D_80115126 == 5) {
        i = 0;
        do {
            s32 *p;
            d = &D_801EEF94[i * 36];
            if (i == 0) {
                s = (u8 *)D_801C1324;
            } else {
                s = (u8 *)D_801C12F0[i];
                d += 8;
            }
            while (*(s) != 0) { *(d)++ = *(s)++; *(d)++ = *(s)++; }
            p = ((s32 *)D_801EF254)[i];
            if (p != 0) {
                func_8005C540(&D_801EEFA0[i * 36], D_801C1264[p[2]]);
            }
            i++;
        } while (i < 6);
    }
}
