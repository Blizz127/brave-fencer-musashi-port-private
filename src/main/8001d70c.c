/* func_80010178: func_8001D70C from Druthulu/BFM-decomp
 * src/src/800.c (preprocessed; only the declarations it uses),
 * byte-identical to the func_80010178 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef short s16;
typedef int s32;
typedef struct {
    u8 minute;
    u8 second;
    u8 sector;
    u8 track;
} CdlLOC;
typedef struct {
    CdlLOC pos;
    u32 size;
    char name[16];
} CdlFILE;
extern CdlFILE *func_80045374(CdlFILE *fp, char *name);
extern int func_80043B1C(CdlLOC *p);
extern CdlLOC *func_80043A18(int i, CdlLOC *p);
extern int func_8004239C(int mode);
extern s32 func_80034B98(void);
extern void func_8002D4C8(s32 a0, s32 a1);
extern int func_8004239C(int mode);
extern void func_80019990(void);
extern void func_8004978C(s16 *a0, void *a1);
extern u8 D_800747A0;
extern u8 D_800747A4;
extern u8 *D_800747AC;
extern u32 D_800747B0;
extern u16 D_800747B4;
extern u32 D_800C7D24;
s32 func_80018730(u8 *src) {
    s32 count = 0x800;
    u32 ringIdx = D_800747B0;
    u8 mask = D_800747A0;
    u8 token = D_800747A4;
    u8 *out = D_800747AC;
    u16 code = D_800747B4;
    u8 *ring = (u8 *)0x1F800000;
    u32 readIdx;
    s32 len;
    u8 b;
    u8 nb;
    u8 cb;
    u8 nh;
    s32 newState;
    s32 result;
    switch (D_800C7D24) {
    case 0:
        goto term_ret;
    case 1:
        ringIdx = 1;
        mask = 1;
        token = *src++;
        count--;
    case 2:
        for (;;) {
            if (token & mask) {
                b = *src++;
                ring[ringIdx] = b;
                ringIdx = (ringIdx + 1) & 0x3FF;
                count--;
                *out++ = b;
            } else {
                nb = *src++;
                count--;
                code = (code & 0xFF00) | nb;
                if (count != 0) {
                    goto have_low;
                }
                result = 1;
                newState = 3;
                goto save;
    have_low:
    case 3:
                nh = *src++;
                count--;
                code = (code & 0xFF) | (nh << 8);
                readIdx = code & 0x3FF;
                if (readIdx == 0) {
                    D_800C7D24 = 0;
                term_ret:
                    return 0;
                }
                len = (code >> 10) + 2;
                while (len != 0) {
                    cb = ring[readIdx];
                    readIdx = (readIdx + 1) & 0x3FF;
                    ring[ringIdx] = cb;
                    ringIdx = (ringIdx + 1) & 0x3FF;
                    *out++ = cb;
                    len--;
                }
            }
            if (count != 0) {
                goto next_bit;
            }
            result = 1;
            newState = 4;
        save:
            D_800C7D24 = newState;
            D_800747B0 = ringIdx;
            D_800747A0 = mask;
            D_800747A4 = token;
            D_800747AC = out;
            D_800747B4 = code;
            return result;
    next_bit:
    case 4:
            if (mask == 0x80) {
                mask = 1;
                token = *src++;
                count--;
                if (count == 0) {
                    register s32 r __asm__("$2");
                    r = 1;
                    __asm__ __volatile__("" : : "r"(r));
                    newState = 2;
                    D_800C7D24 = newState;
                    D_800747B0 = ringIdx;
                    D_800747A0 = mask;
                    D_800747A4 = token;
                    D_800747AC = out;
                    D_800747B4 = code;
                    return r;
                }
            } else {
                mask <<= 1;
            }
        }
    }
}
extern void func_8002D4C8(s32 a0, s32 a1);
extern s32 D_800747D0;
extern s32 D_800747D0;
extern s32 D_800747D4;
extern s32 D_800747D4;
extern void func_80019990(void);
extern int func_8004239C(int mode);
extern s32 func_80019A24(int *cdlFile, void *dest, s32 size, s32 mode);
extern u8 D_80062C38;
extern u8 D_80062C68;
extern s32 D_800747D0;
extern s32 D_80063074;
extern s32 D_800747D8;
extern u8 D_800AE830[];
extern u8 D_800AE834;
extern void func_80019990(void);
extern int func_8004239C(int mode);
extern s32 func_80019A24(int *cdlFile, void *dest, s32 size, s32 mode);
extern CdlFILE D_80063058;
extern u8 D_80062C38;
extern u8 D_80062C68;
extern s32 D_800747D0;
extern s32 D_800747D4;
extern s32 D_80063074;
extern s32 D_800747D8;
extern u8 D_800AE830[];
extern u8 D_800AE834;
void func_8001971C(void) {
    CdlFILE *res;
    register int tries __asm__("$21");
    register u8 *pathBase __asm__("$18");
    register char *nameBase __asm__("$19");
    register int pathOff __asm__("$17");
    int offCopy;
    int dead[4];
    register u32 pathN __asm__("$21");
    int base;
    int n;
    int rdy;
    int fileIdx;
    int bufIdx;
    register int j __asm__("$19");
    register int outer __asm__("$21");
    int locOff;
    u8 *tbl;
    u8 *lbv;
    int dstOff;
    int srcOff;
    s32 *pCount;
    s32 *pOff;
    CdlLOC *p;
    func_80019990();
    tries = 0;
    do {
        res = func_80045374(&D_80063058, (char *)&D_80063058 - 0x14);
        tries++;
        if (res != (CdlFILE *)-1) {
            break;
        }
    } while (tries < 0x10);
    pathN = 0;
    pathBase = &D_80062C38;
    nameBase = (char *)pathBase - 0x14;
    pathOff = 0;
    D_800747D0 = (res != (CdlFILE *)0);
    D_800747D4 = 1;
    D_80063074 = 0;
    D_800747D8 = 0;
    do {
        offCopy = pathOff;
        do {
            res = func_80045374((CdlFILE *)(&D_80062C38 + offCopy), nameBase + offCopy);
        } while ((u32)((int)res + 1) < 2);
        pathN++;
        pathOff += 0x30;
    } while (pathN < 0x15);
    do {
        rdy = func_80019A24((int *)&D_80062C38, (void *)0x80180000, 0xE40, 0);
        if (rdy != 0) {
            break;
        }
        func_8004239C(0);
    } while (1);
    tbl = D_800AE830;
    lbv = (u8 *)0x80180000;
    fileIdx = 0;
    bufIdx = 0;
    outer = 0;
    locOff = 0;
    pCount = (s32 *)0x80180000;
    do {
        base = func_80043B1C((CdlLOC *)(&D_80062C68 + locOff));
        n = *pCount;
        pCount += 2;
        bufIdx++;
        j = 0;
        if (n > 0) {
            p = (CdlLOC *)((u32)(fileIdx * 8) + (u32)tbl);
            dstOff = fileIdx * 8;
            pOff = (s32 *)((u32)(bufIdx * 8) + (u32)lbv);
            srcOff = bufIdx * 8;
            do {
                if (*pOff != 0) {
                    func_80043A18(*pOff + base, p);
                    *(s32 *)(&D_800AE834 + dstOff) = *(s32 *)(0x80180004 + srcOff);
                }
                pOff += 2;
                srcOff += 8;
                pCount += 2;
                bufIdx++;
                p += 2;
                dstOff += 8;
                j++;
                fileIdx++;
            } while (j < n);
        }
        outer++;
        locOff += 0x30;
    } while (outer < 8);
}
extern s32 D_800AE728;
extern s32 D_800AE6F0;
extern s32 D_800AE6F8;
extern s32 D_800AE6FC;
extern s32 D_800AE700;
extern s32 D_800AE748;
extern s32 D_800AE74C;
extern u8 D_800AE798;
extern u8 D_800AE799;
extern s32 D_800AE70C;
extern s32 D_800AE728;
extern s32 D_800AE708;
extern s32 D_800AE6F0;
extern s32 D_800AE6F8;
extern s32 D_800AE6FC;
extern s32 D_800AE700;
extern s32 D_800AE748;
extern s32 D_800AE74C;
extern u8 D_800AE798;
extern u8 D_800AE799;
extern s32 D_800AE70C;
extern s32 func_80034B98(void);
extern void func_80019AF8(int);
extern s32 D_800AE708;
extern void *D_800AE72C;
extern s32 D_800AE7A8;
extern void *D_800AE7A4;
extern s32 D_800AE7B0;
extern s32 D_800AE720;
extern s32 D_800AE724;
s32 func_80019A24(int *cdlFile, void *dest, s32 size, s32 mode) {
    s32 sector;
    if (func_80034B98() != 0) {
        return 0;
    }
    if (D_800AE708 == 0) {
        sector = *cdlFile;
    } else {
        sector = *cdlFile;
        if (sector != D_800AE708) {
            return 0;
        }
    }
    D_800AE72C = dest;
    D_800AE7A8 = size;
    D_800AE7A4 = cdlFile;
    D_800AE724 = mode;
    D_800AE720 = 0;
    D_800AE708 = sector;
    if (mode == 0) {
        D_800AE720 = 1;
    }
    func_80019AF8(0);
    return D_800AE7B0;
}
extern s32 func_800435CC(s32 mode, void *buf, void *param);
extern s32 func_8004355C(s32 mode, u8 *result);
extern void *func_800435B4(void *func);
extern void func_800434BC(void);
extern void func_8001A338(u8);
extern s32 func_8002FD14(s32, s32);
extern void func_8001A0FC(void);
extern s32 func_8001A114(void);
extern s32 D_800AE6F0;
extern s32 D_800AE750;
extern s32 D_800AE7B0;
extern u8 D_800AE738;
extern void *D_800AE7A4;
extern s32 D_800AE7AC;
extern s32 D_800AE754;
extern s32 D_800AE7A8;
extern void *D_800AE72C;
extern s32 D_800AE728;
extern s32 D_800AE748;
extern s32 D_800AE74C;
extern void *D_800AE734;
extern s32 D_800AE708;
extern s32 D_800AE6E8;
extern s32 D_800AE6F8;
extern s32 D_800AE6FC;
extern s32 D_800AE700;
extern s32 D_800AE70C;
extern s32 D_800AE71C;
extern s32 D_800AE724;
extern u8 D_800AE798;
extern u8 D_800AE799;
void func_80019AF8(s32 pauseAfterSeek) {
    s32 *rp;
    s32 *dp;
    s32 *sp7;
    s32 *sp9;
    u8 *p;
    u8 *q;
    u8 *p2;
    u8 *p3;
    u8 *p8;
    void **fpp;
    s32 r;
    s32 st;
    s32 n;
    s32 i;
    s32 off;
    s32 pad[2];
    switch (D_800AE6F0) {
    case 0:
        p = (u8 *)&D_800AE750;
        *(s32 *)p = 0;
        D_800AE71C = 0;
        D_800AE70C = 0;
        q = p - 0x10;
        *q = 0xA0;
        func_800435CC(0xE, q, p - 0x18);
        if ((p[-0x18] & 0x10) != 0) {
        setStateNine:
            D_800AE6F0 = 9;
            break;
        }
        D_800AE6F0++;
    case 1:
        r = func_8004355C(1, &D_800AE738);
        D_800AE6E8 = r;
        if (r == 0) {
            break;
        }
        if (r == 5) {
            goto resetState;
        }
        if (r != 2) {
            break;
        }
        D_800AE750 = 0;
        D_800AE6F0++;
    case 2:
        rp = &D_800AE750;
        *rp = *rp + 1;
        if (*rp < 3) {
            break;
        }
        *rp = 0;
        D_800AE6F0++;
        break;
    case 3:
        fpp = &D_800AE7A4;
        func_800435CC(0x15, (u8 *)*fpp, (u8 *)fpp - 0x6C);
        if ((*((u8 *)fpp - 0x6C) & 0x10) != 0) {
            goto setStateNine;
        }
        D_800AE754 = 0;
        D_800AE7AC = func_80043B1C((CdlLOC *)*fpp);
        D_800AE6F0++;
    case 4:
        p2 = &D_800AE738;
        r = func_8004355C(1, p2);
        D_800AE6E8 = r;
        if (r == 5) {
            D_800AE750++;
        flushRetry:
            func_800434BC();
            D_800AE6F0 = 3;
            break;
        }
        if (r == 0) {
            break;
        }
        if (r != 2) {
            D_800AE7B0 = 0;
            D_800AE754++;
            if (D_800AE754 < 0xB5) {
                return;
            }
            goto flushRetry;
        }
        if (pauseAfterSeek != 0) {
            func_800435CC(9, 0, p2);
            if ((*p2 & 0x10) != 0) {
                goto setStateNine;
            }
            D_800AE6F0 = 8;
            D_800AE70C = *(s32 *)D_800AE7A4;
            break;
        }
        D_800AE6F0++;
    case 5:
        D_800AE74C = 0;
        if (D_800AE7A8 < 1) {
            D_800AE6F8 = 0;
        } else {
            D_800AE6F8 = 3;
            D_800AE748 = (D_800AE7A8 + 3) / 4;
            D_800AE798 = 1;
            D_800AE728 = (s32)D_800AE72C;
        }
        p3 = (u8 *)&D_800AE734;
        *(void **)p3 = func_800435B4(func_8001A338);
        func_800435CC(6, 0, p3 + 4);
        if ((p3[4] & 0x10) != 0) {
            goto setStateNine;
        }
        D_800AE750 = 0;
        D_800AE6F0++;
    case 6:
        dp = &D_800AE74C;
        if (*dp == 1) {
            func_800435B4(D_800AE734);
            func_800435CC(9, 0, (u8 *)dp - 0x14);
            if ((*((u8 *)dp - 0x14) & 0x10) != 0) {
                goto setStateNine;
            }
            st = D_800AE6F0;
            n = D_800AE71C;
            D_800AE6F0 = st + 1;
            if (n == 0) {
                D_800AE6F0 = st + 2;
            }
            break;
        }
        if (*dp == 2) {
            func_800435B4(D_800AE734);
            goto resetState;
        }
        D_800AE750++;
        if (D_800AE750 < 0x12C) {
            break;
        }
        func_800435B4(D_800AE734);
        D_800AE6F0 = 0;
        func_800434BC();
        break;
    case 7:
        i = 0;
        if (D_800AE71C > 0) {
            do {
                off = i * 8;
                do {
                    r = func_8002FD14(*(s32 *)(off + D_800AE724), *(s32 *)(off + D_800AE724 + 4));
                } while (r == 0);
                i++;
            } while (i < D_800AE71C);
        }
        sp7 = &D_800AE6F0;
        *sp7 = *sp7 + 1;
        break;
    case 8:
        p8 = &D_800AE738;
        r = func_8004355C(1, p8);
        D_800AE6E8 = r;
        if (r == 2) {
            D_800AE728 = 0x80010000;
            D_800AE6F0 = 0;
            D_800AE6F8 = 0;
            D_800AE6FC = 0;
            D_800AE700 = 0;
            D_800AE748 = 1;
            D_800AE74C = 0;
            D_800AE798 = 0;
            D_800AE799 = 0;
            D_800AE70C = 0;
            D_800AE7B0 = 1;
            D_800AE708 = 0;
            return;
        }
        if (r != 5) {
            break;
        }
        func_800434BC();
        func_800435CC(9, 0, p8);
        if ((*p8 & 0x10) == 0) {
            break;
        }
        goto setStateNine;
    case 9:
        func_8001A0FC();
        sp9 = &D_800AE6F0;
        *sp9 = *sp9 + 1;
    case 10:
        D_800AE6E8 = func_8001A114();
        if (D_800AE6E8 == 0) {
            break;
        }
    resetState:
        D_800AE6F0 = 0;
        break;
    }
    D_800AE7B0 = 0;
}
extern s32 D_800AE6F4;
extern s32 D_800AE70C;
void func_8001A0FC(void);
extern void func_800434BC(void);
extern s32 D_800AE6F4;
extern u8 D_800AE738;
extern int D_800AE750;
int func_8001A114(void);
typedef struct XRECT {
           u16 x;
           u16 y;
           u16 w;
           u16 h;
} XRECT;
typedef struct CdReq {
           s32 state;
           s32 unk04;
           s32 phase;
           s32 unk0C;
           s32 unk10;
           s32 texIdx;
           s32 unk18;
           s32 unk1C;
           XRECT rect;
           XRECT *rectp;
           s32 count;
           s32 busy;
           s32 list;
           s32 sink;
           s32 dest;
           s32 unk40[6];
           s32 words;
           s32 drain;
           s32 unk60[2];
           u8 mask[0x40];
           u8 flags;
           u8 unkA9;
           u8 bit;
           u8 byteIdx;
           s32 unkAC[3];
           s32 size;
           s32 posInt;
} CdReq;
extern s32 D_800AE6F0;
extern s32 D_800AE7AC;
extern s32 D_800AE74C;
extern s32 D_800AE6F8;
extern u8 D_80078E40[];
extern u32 D_80079A70[];
extern u8 D_80079A74;
extern u8 D_80079A75;
extern s32 D_80079A78;
extern s32 D_80079A7C;
extern u32 D_8007A280[];
extern void *D_80072C80;
extern s32 func_80043994(void *buf, s32 n);
extern s32 func_8002FB08(s32 a0);
extern s32 func_8002FC64(s32 a0, u32 *a1);
extern void func_8002FDC8(void);
extern void func_80018714(void *);
extern s32 func_80018730(u8 *src);
void func_8001A338(u8 reason) {
    CdReq *p = (CdReq *)&D_800AE6F0;
    XRECT dead;
    u32 *q;
    XRECT *r;
    register s32 i __asm__("$18");
    s32 n, pos, res, b;
    s32 tmp;
    s32 k80;
    s32 one;
    s32 dst;
    s32 cnt;
    s32 dst4;
    if (reason != 1) goto endReason;
    func_80043994(D_80078E40, 3);
    pos = func_80043B1C((CdlLOC *)D_80078E40);
    if (pos != D_800AE7AC) {
        if (D_800AE6F8 == 4) func_8002FDC8();
        D_800AE74C = 2;
        return;
    }
    D_800AE7AC = pos + 1;
    switch (D_800AE6F8) {
    case 0:
        func_80043994(D_80079A70, 4);
        if (D_80079A70[0] != 0x434150) goto abortDrain;
        p->flags = D_80079A75;
        switch (D_80079A74) {
        case 6:
            func_80043994(D_8007A280, 0x1FC);
            q = &D_8007A280[0x24];
            n = D_80079A78;
            i = 0;
            p->rectp = (XRECT *)D_8007A280;
            if (n > 0) {
                do {
                    func_800599B8(p->rectp, q);
                    i++;
                    r = p->rectp;
                    q += (s16)r->w / 2;
                    p->rectp = r + 1;
                } while (i < n);
            }
            goto sectorDone;
        setTwo:
            p->phase = 2;
            goto tilePhase;
        case 0:
        case 5:
            p->texIdx = 0;
            func_80043994(p->mask, 0x10);
            p->rect.h = 0x20;
            p->rect.w = 0x20;
            p->rect.y = 0;
            p->rect.x = 0;
            p->bit = 1;
            p->byteIdx = 0;
            for (;;) {
                if (p->byteIdx >= 0x40) {
                    if (p->flags != 0) goto setTwo;
                    p->phase = 0;
                    goto tilePhase;
                }
                if ((p->mask[p->byteIdx] & p->bit) != 0) goto tilePhase;
                if (p->bit == 0x80) {
                    p->bit = 1;
                    p->byteIdx++;
                } else {
                    p->bit <<= 1;
                }
                p->rect.x += 0x20;
                if ((s16)p->rect.x > 0x3FF) {
                    p->rect.x = 0;
                    p->rect.y += 0x20;
                }
            }
        tilePhase:
            p->phase++;
            break;
        case 7:
            if (p->size < 0) goto phaseDone;
            p->phase = 3;
            p->words = (u32)(D_80079A7C - 0x7FD) >> 2;
            p->sink = (s32)D_80072C80;
            break;
        case 1:
            p->phase = 3;
            p->words = (u32)(D_80079A7C - 0x7FD) >> 2;
            p->sink = p->dest;
            break;
        case 8:
            p->phase = 6;
            p->words = (u32)(D_80079A7C - 0x7FD) >> 2;
            break;
        case 2:
            if (p->busy != 0) goto phaseDone;
            p->phase = 3;
            dst = *(s32 *)(p->count * 8 + p->list + 4);
            tmp = D_80079A7C - 0x7FD;
            p->words = (u32)tmp >> 2;
            p->sink = dst;
            break;
        case 3:
            if (p->busy != 0) goto phaseDone;
            do {
                res = func_8002FB08(*(s32 *)(p->count * 8 + p->list));
            } while (res == 0);
            p->phase = 4;
            p->words = D_80079A7C - 0x800;
            break;
        case 4:
            p->phase = 5;
            p->words = (u32)(D_80079A7C - 0x7FD) >> 2;
            dst4 = p->dest;
            p->sink = dst4;
            func_80018714((void *)dst4);
            break;
        }
        break;
    case 1:
        q = &D_80079A70[p->texIdx * 0x200];
        func_80043994(q, 0x200);
        func_800599B8(&p->rect, q);
        p->texIdx = (p->texIdx + 1) & 3;
        k80 = 0x80;
        one = 1;
        do {
            b = p->bit;
            if (b == k80) {
                p->bit = one;
                p->byteIdx++;
            } else {
                p->bit = b << 1;
            }
            if (p->byteIdx < 0x40) goto cont1;
        sectorDone:
            if (p->flags != 0) goto phaseDone;
            p->phase = 0;
            goto post;
        cont1:
            p->rect.x += 0x20;
            if ((s16)p->rect.x > 0x3FF) {
                p->rect.x = 0;
                p->rect.y += 0x20;
            }
        } while ((p->mask[p->byteIdx] & p->bit) == 0);
        break;
    case 3:
        if (p->words < 0x201) {
            func_80043994((void *)p->sink, p->words);
            goto sectorDone;
        }
        func_80043994((void *)p->sink, 0x200);
        p->sink += 0x800;
        p->words -= 0x200;
        break;
    case 4:
        if (p->words < 0x801) {
            cnt = (p->words + 3) / 4;
            func_80043994(D_80079A70, cnt);
            if (func_8002FC64(p->words, D_80079A70) == 0) goto stageFail;
            p->count++;
            if (p->flags != 0) goto phaseDone;
            p->phase = 0;
            break;
        }
        func_80043994(D_80079A70, 0x200);
        res = func_8002FC64(0x800, D_80079A70);
        p->sink += 0x800;
        p->words -= 0x800;
        if (res != 0) break;
    stageFail:
        func_8002FDC8();
        p->phase = 7;
        break;
    case 5:
        func_80043994(D_80079A70, 0x200);
        if (func_80018730((u8 *)D_80079A70) == 0) goto sectorDone;
        break;
    case 6:
        p->words -= 0x200;
        if (p->words > 0) break;
        if (p->flags == 0) goto setZero;
    phaseDone:
        p->phase = 2;
        break;
    setZero:
        p->phase = 0;
        break;
    }
post:
    if (p->phase == 2) {
        p->drain = 1;
    } else if (p->phase == 7) {
        p->drain = 2;
    }
endReason:
    if (reason == 5) {
        if (p->phase == 4) func_8002FDC8();
    abortDrain:
        p->drain = 2;
    }
}
extern s32 func_80034B98(void);
extern s32 D_800AE708;
extern s32 D_800AE708;
extern u8 D_80062C38;
extern s32 D_800A654C;
extern s32 D_800747F8;
extern u8 D_80063138[];
extern u8 D_8006313C;
extern void func_8002D4C8(s32 a0, s32 a1);
extern s32 D_800A6430;
extern s32 D_800A654C;
extern s32 D_800747F8;
extern u8 D_80063138[];
extern u8 D_8006313C;
extern void func_8002D4C8(int arg0, int arg1);
extern s32 D_800AE708;
extern void *D_800AE72C;
extern s32 D_800AE7A8;
extern void *D_800AE7A4;
extern s32 D_800AE724;
extern s32 D_800AE720;
extern s32 D_800AE7B0;
extern s32 D_800A6430;
extern s16 D_800A6430_h __asm__("D_800A6430");
extern s32 func_80034B98(void);
extern void func_80019AF8(int);
extern s32 func_80034B98(void);
extern int func_8001A114(void);
extern s32 D_800C6D34;
extern s32 D_800C6D10;
extern s32 D_800C6D34;
extern s32 D_800C6D10;
extern s32 D_800AE7EC;
extern s32 D_800A654C;
extern s32 D_800747F8;
extern s32 D_800A654C;
extern s32 D_800AE7EC;
extern s32 D_800C6D34;
extern s32 D_800C6D10;
extern void func_8001B3C4(void);
extern int func_8001A114(void);
extern void func_8001B710(void);
extern void func_8002D4C8(int arg0, int arg1);
extern void func_80036D58(s16);
extern int func_800363CC(int arg0, void *loc, int n);
extern s32 func_80034B98(void);
extern s32 func_8001B788(s16 arg0);
extern s32 D_800AE7EC;
extern s32 D_800C6D34;
extern s32 D_800A654C;
extern s32 D_800747F8;
extern s32 D_800C6D10;
extern s32 D_800AE708;
extern u8 D_80063138[];
extern u8 D_8006313A;
extern u8 D_8006313C;
extern u8 D_800AE830[];
extern s32 D_800AE6F4;
extern s32 D_800AE70C;
typedef struct {
    s16 v;
    s16 pad[2];
} ResMapCol;
extern ResMapCol aResourceIdMap[] __asm__("D_80063138");
extern ResMapCol aD_8006313A[] __asm__("D_8006313A");
extern ResMapCol aD_8006313C[] __asm__("D_8006313C");
void func_8001B3C4(void) {
    s32 result;
    s32 sp10[2];
    result = 0;
    switch ((u32)D_800AE7EC) {
    case 0:
        if (D_800C6D34 == D_800A654C) {
            D_800C6D10 = 1;
            return;
        }
        if (aResourceIdMap[D_800C6D34].v == D_800747F8 && aD_8006313C[D_800C6D34].v != 0) {
            func_8002D4C8((u16)aD_8006313C[D_800C6D34].v, 0);
            D_800A654C = D_800C6D34;
            D_800C6D10 = 1;
            return;
        }
        if (func_80034B98() != 0) {
            break;
        }
        if (aResourceIdMap[D_800C6D34].v < 0) {
            ((void (*)())func_80036D58)(aD_8006313A[D_800C6D34].v);
            D_800C6D10 = 1;
            return;
        }
        if (func_8001B788((s16)D_800C6D34) == 0) {
            D_800C6D10 = 1;
            return;
        }
        if (D_800AE708 != 0 && *(s32 *)(D_800AE830 + aResourceIdMap[D_800C6D34].v * 8) != D_800AE708) {
            break;
        }
        D_800AE708 = *(s32 *)(D_800AE830 + aResourceIdMap[D_800C6D34].v * 8);
        D_800AE7EC++;
    case 1:
        result = func_800363CC(aD_8006313A[D_800C6D34].v,
                                        &D_800AE830[aResourceIdMap[D_800C6D34].v * 8], 0x10);
        if (result == 2) {
            D_800AE7EC++;
            result = 0;
        }
        break;
    case 2:
        D_800AE6F4 = 0;
        D_800AE70C = 0;
        D_800AE7EC = 3;
    case 3:
        if (func_8001A114() != 0) {
            D_800AE7EC = 0;
        }
        break;
    }
    if (result != 0) {
        D_800747F8 = aResourceIdMap[D_800C6D34].v;
        if (aD_8006313C[D_800C6D34].v > 0) {
            func_8002D4C8((u16)aD_8006313C[D_800C6D34].v, 0);
            D_800A654C = D_800C6D34;
            if (D_800C6D34 == 0x3D) {
                func_8001B710();
            }
        }
        D_800AE7EC = 0;
        D_800AE708 = 0;
    }
    D_800C6D10 = result;
}
void func_8001B710(void);
extern u8 D_80063138[];
extern u8 D_800AE830[];
extern s32 func_80034B98(void);
extern void func_80019AF8(int);
extern s32 D_800AE708;
extern void *D_800AE7A4;
extern s32 D_800AE7B0;
extern s32 D_800AE70C;
extern s32 func_80034B98(void);
extern int func_8004239C(int mode);
extern s32 D_800AE708;
extern s32 func_80034B98(void);
extern void func_8002D4C8(int arg0, int arg1);
extern s32 D_80063074;
extern s32 D_80063074;
extern s32 D_800747D8;
extern s32 D_800747D8;
extern void func_8001CFDC(s32 a0, s32 a1);
void *func_8001CFDC_impl(s32 func_80010000, s32 end) __asm__("func_8001CFDC");
void *func_8001CFDC_impl(s32 func_80010000, s32 end);
extern void func_8001D074(s32 a, s32 b);
s32 func_8001D074_impl(s32 arg0, s32 arg1) __asm__("func_8001D074");
s32 func_8001D074_impl(s32 arg0, s32 arg1);
__asm__(
    ".macro cop2op fake_op, op, gbg = 0, sf = 1, mx = 0, v = 0, cv = 0, lm = 0\n"
    "    cop2 \\fake_op << 20 | \\gbg << 20 | \\sf << 19 | \\mx << 17 | \\v << 15 | \\cv << 13 | \\lm << 10 | \\op\n"
    ".endm\n"
    ".macro mvmva sf, mx, v, cv, lm\n"
    "    cop2op 0x04, 0x12, sf = \\sf, mx = \\mx, v = \\v, cv = \\cv, lm = \\lm\n"
    ".endm\n"
    ".macro op sf\n"
    "    cop2op 0x17, 0x0C, sf = \\sf\n"
    ".endm\n"
);

void func_8001D70C(s32 param_1)
{
    s32 matrix[8];  /* sp+0x10 */  /* retail 8001D724: addiu a1, sp, 0x10 */
    s16 sc[20];     /* sp+0x30 */  /* retail: sh v0, 0x30(sp); sh zero, 0x32(sp) */
    func_8004978C((s16 *)(param_1 + 0x10), (void *)matrix);
    sc[0] = *(u16 *)(param_1 + 0x18);
    sc[1] = 0;
    sc[2] = 0;
    sc[3] = 0;
    sc[4] = *(u16 *)(param_1 + 0x1A);
    sc[5] = 0;
    sc[6] = 0;
    sc[7] = 0;
    sc[8] = 0x1000;
    __asm__ volatile (
        "lw $12, 0(%0);"
        "lw $13, 4(%0);"
        "ctc2 $12, $0;"
        "ctc2 $13, $1;"
        "lw $12, 8(%0);"
        "lw $13, 12(%0);"
        "lw $14, 16(%0);"
        "ctc2 $12, $2;"
        "ctc2 $13, $3;"
        "ctc2 $14, $4;"
        "addiu $2, $sp, 0x30;"
        "lhu $12, 0($2);"
        "lhu $13, 6($2);"
        "lhu $14, 12($2);"
        "mtc2 $12, $9;"
        "mtc2 $13, $10;"
        "mtc2 $14, $11;"
        "nop;"
        "nop;"
        "mvmva 1, 0, 3, 3, 0;"
        "mfc2 $12, $9;"
        "mfc2 $13, $10;"
        "mfc2 $14, $11;"
        "sh $12, 0(%0);"
        "sh $13, 6(%0);"
        "sh $14, 12(%0);"
        "addiu $2, $sp, 0x32;"
        "lhu $12, 0($2);"
        "lhu $13, 6($2);"
        "lhu $14, 12($2);"
        "mtc2 $12, $9;"
        "mtc2 $13, $10;"
        "mtc2 $14, $11;"
        "nop;"
        "nop;"
        "mvmva 1, 0, 3, 3, 0;"
        "addiu $2, $sp, 0x12;"
        "mfc2 $12, $9;"
        "mfc2 $13, $10;"
        "mfc2 $14, $11;"
        "sh $12, 0($2);"
        "sh $13, 6($2);"
        "sh $14, 12($2);"
        "addiu $2, $sp, 0x34;"
        "lhu $12, 0($2);"
        "lhu $13, 6($2);"
        "lhu $14, 12($2);"
        "mtc2 $12, $9;"
        "mtc2 $13, $10;"
        "mtc2 $14, $11;"
        "nop;"
        "nop;"
        "mvmva 1, 0, 3, 3, 0;"
        "addiu $2, $sp, 0x14;"
        "mfc2 $12, $9;"
        "mfc2 $13, $10;"
        "mfc2 $14, $11;"
        "sh $12, 0($2);"
        "sh $13, 6($2);"
        "sh $14, 12($2);"
        : : "r"((s32)matrix) : "$12", "$13", "$14", "$2", "memory");
    *(s32 *)((u8 *)matrix + 0x14) = *(s16 *)(param_1 + 8);
    *(s32 *)((u8 *)matrix + 0x18) = *(s16 *)(param_1 + 10);
    *(s32 *)((u8 *)matrix + 0x1C) = *(s16 *)(param_1 + 12);
    __asm__ volatile (
        "lw $12, 0(%0);"
        "lw $13, 4(%0);"
        "ctc2 $12, $0;"
        "ctc2 $13, $1;"
        "lw $12, 8(%0);"
        "lw $13, 12(%0);"
        "lw $14, 16(%0);"
        "ctc2 $12, $2;"
        "ctc2 $13, $3;"
        "ctc2 $14, $4;"
        "lw $12, 20(%0);"
        "lw $13, 24(%0);"
        "ctc2 $12, $5;"
        "lw $14, 28(%0);"
        "ctc2 $13, $6;"
        "ctc2 $14, $7"
        : : "r"((s32)matrix) : "$12", "$13", "$14", "$2");
}
