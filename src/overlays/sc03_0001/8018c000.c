/* sc03_0001: func_8018C000 from Druthulu/BFM-decomp
 * src/ov_SC03_001/ov_SC03_001_jr_8018B8DC.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0001 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed char s8;
typedef short s16;
typedef int s32;
extern void func_80029124(s32, s32);
extern void func_80029514(s32);
extern void func_8002D4C8(s32 a0, s32 a1);
extern s32 func_800291B4(s32 arg);
extern void func_800291A0(s32, s32);
extern void func_80029124(s32 a0, s32 a1);
extern void func_8012A568(void (*a0)(void));
extern int func_800D0F8C(int a0);
extern int func_800D0FE0(int a0);
extern void func_800D128C(s32, s32);
extern s32 func_800D0EC4(void);
extern void func_800D0F0C(s32, s32);
extern s32 func_8017ADE8(s32 a0);
extern void func_8002D4C8(s32 arg0, s32 arg1);
extern s16 D_801EEB10;
extern s16 D_80115126;
extern u8 D_80115148[];
extern s16 D_801EF274;
extern s32 D_801F4334;
extern void func_80139A68(s32 a0, u16 a1);
extern s16 func_8018C914(s32 a0);
extern void func_80029124(s32, s32);
extern void func_800291A0(s32, s32);
extern s32 func_800291B4(s32 arg);
extern void func_80029514(s32);
extern void func_8002D4C8(s32 a0, s32 a1);
extern s32 func_800D0EC4(void);
extern void func_800D0F0C(s32, s32);
extern int func_800D0F8C(int a0);
extern int func_800D0FE0(int a0);
extern void func_800D128C(s32, s32);
extern void func_80139A44(s32 a0, u16 a1);
extern void func_80139A68(s32 a0, u16 a1);
extern s32 func_8017ADE8(s32 a0);
extern void func_801898E4(void);
extern void func_8018C8D4(s32);
extern s16 func_8018C914(s32 a0);
void func_8018C8D4();
s16 func_8018C914(s32 a0);

s32 func_8018C000(s32 param_1, s16 param_2)
{
    extern s16 D_800A6586[];
    extern u8 D_8010EDEC[];
    extern s16 D_8010EDEE;
    extern u8 D_8010EDF1;
    extern u8 D_8010EDF2;
    extern unsigned short D_80115112;
    extern u16 D_8011511A;
    extern s16 D_80115126;
    extern u8 D_80115148[];
    extern s16 D_8011514C;
    extern s16 D_8011514E;
    extern s8 D_801C1800[];
    extern void (*D_801EB520[])(void);
    extern s32 D_801EB650[];
    extern u8 *D_801EF1D4;
    extern u8 *D_801EF1DC;
    extern s32 D_801EF1E0;
    extern s16 D_801EF26C;
    extern s16 D_801EF274;
    extern u8 D_801EF298[];
    extern u8 D_801F0CEC[];
    extern s32 D_801F1090;
    extern u8 D_801F10B0[];
    extern s32 D_801F10F4;
    extern s32 D_801F4334;
    extern s16 D_801EEB10;
    s32 unused_[2];
    switch ((short)param_1) {
    case 1:
    case 2:
    case 4:
    case 6:
        if (param_2 == 2) {
            return -1;
        }
        func_8002D4C8(0x46F, 0);
        D_8011511A = param_2 + 1;
        return 0;
    case 3:
        if (param_2 == 2) {
            return -1;
        }
        D_8011511A = 2;
        func_8002D4C8(0x46F, 0);
        return 0;
    case 5:
        if (param_2 == 1) {
            D_801EEB10 = 1;
            func_8002D4C8(0x474, 0);
            return -1;
        }
        if (param_2 == 3) {
            return -1;
        }
        func_8002D4C8(0x46F, 0);
        if (param_2 != 0) {
            D_8011511A = param_2;
        } else {
            D_8011511A = 2;
        }
        return 0;
    case 12:
        D_8011511A = 3;
        D_8011514E = 0;
        func_8002D4C8(0x46F, 0);
        return 0;
    case 13:
    {
        register s32 f13 __asm__("$16");
        s32 i13;
        s32 c13;
        register u8 *q __asm__("$5");
        s16 d;
        i13 = D_801EF1DC[param_2];
        c13 = i13 + 0x62;
        f13 = ((u8 (*)(s32))func_800291B4)(c13);
        if ((f13 & 0xF0) != 0x80) {
            goto bad472;
        }
        if (func_8018C914(-D_800A6586[i13]) != 0) {
        L801896C8:
            func_8018C8D4(3);
            goto bad472;
        }
        func_800291A0(c13, f13 | 0x40);
        func_801898E4();
        __asm__ __volatile__("" : "=r"(q) : "0"(&D_8011514C));
        d = (s8)q[0] - (s8)q[-0xA];
        if (d >= 6) {
            q[-0xA] = q[0] - 5;
        } else if (d < 0) {
            q[-0xA] = q[0];
        }
        func_8018C8D4(1);
        func_8002D4C8(0x5EE, 0);
        return 0;
    }
    case 14:
    {
        register s32 f14 __asm__("$16");
        s32 i14;
        s32 n14;
        s32 t14;
        s32 c14;
        i14 = param_2;
        t14 = D_801EF298[i14];
        n14 = t14 + 1;
        __asm__("" : "=r"(t14) : "0"(t14));
        c14 = n14 + 0x62;
        f14 = ((u8 (*)(s32))func_800291B4)(c14);
        if ((f14 & 0xF0) != 0xC0) {
            goto bad472;
        }
        func_8018C914(D_800A6586[n14] * 9 / 10);
        func_800291A0(c14, f14 & 0xBF);
        func_801898E4();
        D_801EF298[i14] = 0xFF;
        func_8018C8D4(4);
        func_8002D4C8(0x5EE, 0);
        return 0;
    }
    case 10:
    {
        s32 b10 = D_801EF1D4[param_2];
        s32 m10;
        s32 w10;
        __asm__ __volatile__("" : "=r"(m10) : "0"(b10));
        if (m10 < 0x6F) {
            register s16 slot __asm__("$16");
            register s16 sraw __asm__("$2");
            s16 val;
            s16 x;
            if (m10 == 0xA) {
                if (func_800D0F8C(0xA) != 0) {
                    goto bad472;
                }
            }
            sraw = ((s16 (*)(void))func_800D0EC4)();
            slot = sraw;
            if (sraw == 0) {
                func_8018C8D4(2);
                func_8002D4C8(0x45F, 0);
                return 0;
            }
            x = D_801EF26C;
            if (x != 0) {
                if (D_80115126 == 0) {
                    val = (*(s16 *)((u8 *)&(D_8010EDEC) + (s32)(b10) * 0xC)) * (100 - x) / 100;
                } else {
                    val = (*(u16 *)((u8 *)&(D_8010EDEC) + (s32)(b10) * 0xC)) - x;
                }
            } else {
                val = (*(u16 *)((u8 *)&(D_8010EDEC) + (s32)(b10) * 0xC));
            }
            if (func_8018C914(-val) != 0) {
                func_8018C8D4(3);
                func_8002D4C8(0x472, 3);
                return 0;
            }
            func_8002D4C8(0x5EE, 0);
            __asm__("addu %0,%1,$zero" : "=r"(w10) : "r"(b10));
            func_800D0F0C(slot, w10);
            if (w10 == 0xA) {
                func_801898E4();
            }
        } else {
            if (func_8018C914(-(*(s16 *)((u8 *)&(D_8010EDEC) + (s32)(m10) * 0xC))) != 0) {
                goto L801896C8;
            }
            func_800D128C(b10, 0);
        }
        func_8018C8D4(1);
        return 0;
    }
    case 7:
    {
        s32 c7;
        s32 k7;
        s32 a7;
    L801899B0:
        c7 = (s32)param_2 + 0x2F;
        k7 = ((u8 (*)(s32))func_800291B4)(c7);
        if (k7 == 0) {
            goto bad472;
        }
        a7 = (*(s16 *)((u8 *)&(D_8010EDEE) + (s32)(k7) * 0xC));
        if (a7 == 0 || D_80115126 != (*(u8 *)((u8 *)&(D_8010EDF2) + (s32)(k7) * 0xC))) {
            func_8018C8D4(5);
            goto bad472;
        }
        func_8018C914(a7);
        ((void (*)(s32))func_800D0FE0)(c7);
        if (k7 == 0xA) {
            func_801898E4();
        }
        func_8018C8D4(4);
        func_8002D4C8(0x5EE, 0);
        return 0;
    }
    case 8:
    {
        s32 k8;
        s32 f8;
        register s32 g8 __asm__("$16");
        register s32 t8 __asm__("$2");
        register s32 cv __asm__("$2");
        s32 p8;
        u16 *c;
        if ((*(u8 *)D_80115148) != 0) {
            goto L801899B0;
        }
        k8 = ((u8 (*)(s32))func_800291B4)((s32)param_2 + 0x2F);
        if (k8 == 0) {
            goto bad472;
        }
        f8 = (*(s16 *)((u8 *)&(D_8010EDEC) + (s32)(k8) * 0xC));
        if (f8 >= 0) {
            D_801EF1E0 = (s32)&D_801F10F4;
            goto bad472;
        }
        __asm__ __volatile__("" : "=r"(g8) : "0"(f8));
        t8 = g8 & 0x4000;
        if (t8 != 0) {
            p8 = ((s32 *)D_801EB520)[k8];
        } else {
            p8 = D_801EB650[((*(u8 *)((u8 *)&(D_8010EDF1) + (s32)(k8) * 0xC)) - 0x14) >> 1];
        }
        D_801EF1E0 = (s32)&D_801F1090;
        func_80139A44(p8, 0);
        c = &D_80115112;
        cv = *c;
        cv = cv + 1;
        *c = cv;
        return 0;
    }
    case 15:
    {
        register u16 f15 __asm__("$16");
        register s32 t15 __asm__("$2");
        s32 c15;
        s32 k15;
        s32 n15;
        c15 = (s32)param_2 + 0x2F;
        k15 = ((u8 (*)(s32))func_800291B4)(c15);
        f15 = (*(u16 *)((u8 *)&(D_8010EDEC) + (s32)(k15) * 0xC));
        n15 = (*(u8 *)((u8 *)&(D_8010EDF1) + (s32)(k15) * 0xC));
        t15 = f15 & 0x4000;
        if (t15 != 0) {
            s32 m15;
            __asm__ __volatile__("" : "=r"(m15) : "0"(n15));
            func_80029124(m15, 1);
            ((void (*)(s32))func_800D0FE0)(c15);
            D_801EEB10 = n15 - 0x1C;
            if (m15 != 0x1F) {
                return 0;
            }
            func_80029514(0x64);
            func_80029124(0xEB, 1);
            func_80029124(0x91, 1);
            func_800291A0(0xCE, 1);
            return 0;
        }
        func_800D0F0C(c15, n15);
        return 0;
    }
    case 11:
    {
        typedef struct Rec {
            s32 unk0;
            s32 unk4;
            s32 unk8;
            void (*unkC)(void);
        } Rec;
        extern Rec *D_801EF254[];
        Rec **pp;
        Rec *r;
        Rec **pp2;
        register s32 dv __asm__("$2");
        Rec **base;
        Rec *r2;
        s32 t;
        s32 u;
        if (D_80115126 == 4) {
            if ((*(u8 *)D_80115148) == 0) {
                s32 i11 = param_2;
                if (D_801EF254[i11] != 0) {
                    goto bad472;
                }
                if (func_8018C914(D_801C1800[i11]) != 0) {
                    goto L801896C8;
                }
                D_801EF1E0 = (s32)&D_801F4334;
                D_80115112 = D_80115112 + 1;
                ((void (*)(s32, s32))func_80139A68)((s16)(param_2 + 1), 0);
                func_8002D4C8(0x5EE, 0);
                return 0;
            }
            base = D_801EF254;
            pp = &base[param_2];
            r = *pp;
            if (r == 0) {
                goto bad472;
            }
            if (r->unk4 == 0) {
                goto bad472;
            }
            D_801EF1E0 = r->unk4;
            if (r->unkC != 0) {
                r->unkC();
            }
            ((void (*)(s32))func_8017ADE8)((*pp)->unk8);
            goto tail45D;
        }
        base = D_801EF254;
        pp2 = &base[param_2];
        r2 = *pp2;
        if (r2 == 0) {
            goto bad472;
        }
        t = (*(Rec * volatile *)pp2)->unk8;
        __asm__ __volatile__("");
        D_801EF1E0 = r2->unk4;
        ((void (*)(s32))func_8017ADE8)(t);
        u = D_801EF1E0;
        D_801EF274 = 0;
        if (u == (s32)&D_801F0CEC) {
            D_801EF274 = 1;
        }
        if (u == (s32)&D_801F10B0) {
            D_801EF274 = 2;
        }
    tail45D:
        func_8002D4C8(0x45D, 0);
        dv = D_80115112;
        dv = dv + 1;
        D_80115112 = dv;
        return 0;
    }
    }
    goto done;
bad472:
    func_8002D4C8(0x472, 0);
done:
    return 0;
}
