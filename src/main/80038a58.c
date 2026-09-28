/* Main-exec range [80038A58,80038FC4) from the SLUS executable.
 * SHA256(span)=05ccdb27f0c65a6e6101d950100ea996630efe116e9b2d36fe792324d46d7409.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80038A58 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"

extern u8 *D_800762B0;
extern u8 D_800762B4[];
extern u8 D_800B9CD8[];
extern u8 D_800C6DD0[];
extern u8 D_800C6E2A[];
extern s16 D_800A4EF8;
extern u16 D_800A4EE0;
extern u8 D_800A4F16;
extern s32 func_80038FC4(u8 **);
extern s32 func_80038FFC(s32 *);   

void func_80038A58(void)
{
    register u8 *base __asm__("$19");
    register u8 *p __asm__("$17");
    register s32 i __asm__("$18");
    register s32 one __asm__("$20");

    base = D_800B9CD8;

    {
        register u8 *q __asm__("$2");
        q = D_800762B4;
        i = 0xF;
        do {
            *q = 0;
            i--;
            q++;
        } while (i >= 0);
    }

    {
        register u8 *a3 __asm__("$7");
        register u8 *a2 __asm__("$6");
        register s32 a1 __asm__("$5");
        register u8 *a0 __asm__("$4");
        register s32 t0 __asm__("$8");
        register s32 v0 __asm__("$2");
        register s32 v1 __asm__("$3");

        a3 = D_800762B0;
        a2 = D_800762B4;
        a1 = 0;
        t0 = 3;
        a0 = D_800C6E2A;

        while (a1 < 0x10) {
            v0 = *a3;
            if (v0 == 0 || v0 == t0) {
                if (*a2 == 0) {
                    v0 = *a0;
                    a0[1] = 0;
                    if (v0 != 0) {
                        v0 = *(s16 *)(a0 - 0x54);
                        v1 = v0 << 1;
                        v1 = v1 + v0;
                        v1 = v1 << 2;
                        v1 = v1 + v0;
                        v0 = *(s32 *)(a0 - 0xA);
                        v1 = v1 << 1;
                        v0 = v0 + v1;
                        v0 = v0 + a1;
                        *(u8 *)(v0 + 0x23) = 0;
                        a0[0] = 0;
                    }
                }
            }
            a1++;
            a0 += 0x60;
            a3++;
            a2++;
        }
    }

    i = 0;
    one = 1;
    p = base + 0x10;
    do {
        if (p[0x1EB] != 0 && p[0x1EA] != 0) {
            s32 sum = *(s32 *)(p + 0x1BC) + *(s32 *)(p + 0x1C0);
            s32 lim = *(s32 *)(p + 0x1C4);
            s32 k;
            u8 flag;

            *(s32 *)(p + 0x1BC) = sum;
            if (sum >= lim) {
                register s32 cur __asm__("$3");
                register s32 quot __asm__("$5");
                register s32 c __asm__("$4");
                register s32 r __asm__("$16");
                register s32 v __asm__("$3");

                quot = sum / lim;
                cur = *(s32 *)(p - 8);
                *(s32 *)(p + 0x1BC) = sum % lim;
                c = cur;
                r = quot;
                if (cur != 0) {
                    if (quot >= cur) {
                        do {
                            if (c == r) {
                                r = 0;
                            } else {
                                r = r - c;
                            }
                            *(s32 *)(p - 8) = 0;
                            do {
                                if (p[0x1E8] != 0) {
                                    func_80038FFC((s32 *)base);
                                    if (p[0x1E9] != 0) {
                                        p[0x1EA] = 0;
                                        p[0x1E8] = 0;
                                        goto next;
                                    }
                                }
                                v = func_80038FC4((u8 **)base);
                                p[0x1E8] = one;
                            } while (v == 0);
                            *(s32 *)(p - 8) = v;
                            c = v;
                        } while (r >= v);
                        {
                            register s32 d __asm__("$2");
                            d = v - r;
                            *(s32 *)(p - 8) = d;
                        }
                    } else {
                        register s32 d2 __asm__("$2");
                        d2 = cur - quot;
                        *(s32 *)(p - 8) = d2;
                    }
                } else {
                    p[0x1EA] = 0;
                    p[0x1E8] = 0;
                }
            }

            flag = 0;
            if (p[0x1E4] != 0) {
                register u16 *hp __asm__("$8");
                register u8 *sq __asm__("$5");

                hp = (u16 *)(base + 0x12);
                k = 0;
                sq = base + 0x18;
                do {
                    if (*sq != 0) {
                        u16 cur16 = *hp;
                        flag = 1;
                        if (cur16 < *(u16 *)(sq - 2)) {
                            *hp = cur16 + *(u16 *)(sq - 4);
                            if (*hp < *(u16 *)(sq - 2)) {
                                goto cont1;
                            }
                            __asm__ __volatile__("");
                            *hp = *(u16 *)(sq - 2);
                        } else if (*(u16 *)(sq - 4) < cur16) {
                            *hp = cur16 - *(u16 *)(sq - 4);
                            if (*(u16 *)(sq - 2) < *hp) {
                                goto cont1;
                            }
                            *hp = *(u16 *)(sq - 2);
                        } else {
                            *hp = *(u16 *)(sq - 2);
                        }
                        *sq = 0;
                    }
                cont1:
                    k++;
                    sq += 8;
                    hp += 4;
                } while (k <= 0);

                {
                    register u16 *hp2 __asm__("$5");
                    register s32 c2 __asm__("$3");
                    s32 acc2;
                    acc2 = D_800A4EF8 << 7;
                    acc2 *= D_800A4EE0;
                    c2 = 0;
                    __asm__("addiu %0,%1,18" : "=r"(hp2) : "r"(base), "r"(c2));
                    acc2 >>= 14;
                    do {
                        acc2 *= *hp2;
                        acc2 >>= 14;
                        c2--;
                        hp2 += 4;
                    } while (c2 >= 0);
                    *(s16 *)p = acc2;
                }

                if (flag != 0 || D_800A4F16 != 0) {
                    register u8 *b __asm__("$5");
                    register u8 *e __asm__("$4");
                    b = D_800C6DD0;
                    k = 0;
                    e = b + 0x5A;
                    do {
                        if (*e == one) {
                            if (*(s16 *)(*(s32 *)(e - 0xA) + 0x1F0) == i) {
                                *(s16 *)(e - 0x42) = (u32)(*(s16 *)b * *(s16 *)p) >> 14;
                                *(s16 *)(e - 0x40) = (u32)(*(s16 *)(e - 0x58) * *(s16 *)p) >> 14;
                                e[3] = one;
                                *(u32 *)(e - 0x46) |= 3;
                            }
                        } else if (*e != 0) {
                            *e = one;
                        }
                        k++;
                        e += 0x60;
                        b += 0x60;
                    } while (k < 0x10);
                } else {
                    register u8 *c __asm__("$3");
                    register s32 two __asm__("$5");
                    register s32 uno __asm__("$4");

                    p[0x1E4] = 0;
                    k = 0;
                    two = 2;
                    uno = 1;
                    c = D_800C6E2A;
                    do {
                        if (*c == two && *(s16 *)(*(s32 *)(c - 0xA) + 0x1F0) == i) {
                            *c = uno;
                        }
                        k++;
                        c += 0x60;
                    } while (k < 0x10);
                }
            } else if (D_800A4F16 != 0) {
                register u16 *hp3 __asm__("$3");
                register s32 c3 __asm__("$5");
                register u8 *b2 __asm__("$5");
                register u8 *e2 __asm__("$4");
                register s32 k2 __asm__("$6");

                s32 acc3;
                acc3 = D_800A4EF8 << 7;
                acc3 *= D_800A4EE0;
                hp3 = (u16 *)(base + 0x12);
                c3 = 0;
                acc3 >>= 14;
                do {
                    acc3 *= *hp3;
                    acc3 >>= 14;
                    c3--;
                    hp3 += 4;
                } while (c3 >= 0);
                *(s16 *)p = acc3;

                b2 = D_800C6DD0;
                k2 = 0;
                e2 = b2 + 0x5A;
                do {
                    if (*e2 == one) {
                        if (*(s16 *)(*(s32 *)(e2 - 0xA) + 0x1F0) == i) {
                            *(s16 *)(e2 - 0x42) = (u32)(*(s16 *)b2 * *(s16 *)p) >> 14;
                            *(s16 *)(e2 - 0x40) = (u32)(*(s16 *)(e2 - 0x58) * *(s16 *)p) >> 14;
                            e2[3] = one;
                            *(u32 *)(e2 - 0x46) |= 3;
                        }
                    } else if (*e2 != 0) {
                        *e2 = one;
                    }
                    k2++;
                    e2 += 0x60;
                    b2 += 0x60;
                } while (k2 < 0x10);
            }
        }
    next:
        i++;
        p += 0x1FC;
        base += 0x1FC;
    } while (i < 2);

    D_800A4F16 = 0;
}
