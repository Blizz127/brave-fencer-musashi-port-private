/* Clean-room re-derivation from the retail disassembly only (B27): CD data-ready callback of the disc file loader. */
#include "psx_types.h"

extern s32 func_80043994(void *buf, s32 nwords);
extern s32 func_80043B1C(void *pos);
extern void func_8002FDC8(void);
extern s32 func_800599B8(void *rect, void *pixels);
extern s32 func_8002FB08(s32 arg);
extern void func_80018714(u32 dst);
extern s32 func_8002FC64(s32 size, void *buf);
extern s32 func_80018730(void *buf);

typedef struct {
    /* 0x00 */ s16 x;
    /* 0x02 */ s16 y;
    /* 0x04 */ s16 w;
    /* 0x06 */ s16 h;
} Rect;

typedef struct {
    /* 0x00 */ s32 state;
    /* 0x04 */ s32 unk04;
    /* 0x08 */ s32 mode;
    /* 0x0C */ s32 unk0C;
    /* 0x10 */ s32 unk10;
    /* 0x14 */ s32 buf_idx;
    /* 0x18 */ s32 unk18;
    /* 0x1C */ s32 unk1C;
    /* 0x20 */ Rect rect;
    /* 0x28 */ u32 rects;
    /* 0x2C */ s32 count;
    /* 0x30 */ s32 busy;
    /* 0x34 */ u32 pairs;
    /* 0x38 */ u32 dst;
    /* 0x3C */ u32 dst_alt;
    /* 0x40 */ s32 unk40[6];
    /* 0x58 */ s32 remain;
    /* 0x5C */ s32 read_state;
    /* 0x60 */ s32 unk60[2];
    /* 0x68 */ u8 bitmap[64];
    /* 0xA8 */ u8 more;
    /* 0xA9 */ u8 unkA9;
    /* 0xAA */ u8 bit;
    /* 0xAB */ u8 index;
    /* 0xAC */ s32 unkAC[3];
    /* 0xB8 */ s32 dest_size;
} LoaderState;

extern LoaderState D_800AE6F0;
extern s32 D_800AE6F8;
extern s32 D_800AE74C;
extern s32 D_800AE7AC;
extern u8 D_80078E40[];
extern u8 D_80079A70[];
extern u8 D_80079A74;
extern u8 D_80079A75;
extern s32 D_80079A78;
extern s32 D_80079A7C;
extern u8 D_8007A280[];
extern u32 D_80072C80;

void func_8001A338(u8 intr, u8 *result) {
    LoaderState *s = &D_800AE6F0;
    s32 i;
    s32 n;
    s32 *pix;
    s32 words;
    s32 pos;

    if (intr == 1) {
        func_80043994(D_80078E40, 3);
        pos = func_80043B1C(D_80078E40);
        if (pos != D_800AE7AC) {
            if (D_800AE6F8 == 4) {
                func_8002FDC8();
            }
            D_800AE74C = 2;
            return;
        }
        D_800AE7AC = pos + 1;
        switch (s->mode) {
        case 0:
            func_80043994(D_80079A70, 4);
            if (*(s32 *)D_80079A70 != 0x434150) {
                goto failed;
            }
            s->more = D_80079A75;
            switch (D_80079A74) {
            case 6:
                func_80043994(D_8007A280, 508);
                pix = (s32 *)(D_8007A280 + 144);
                n = D_80079A78;
                s->rects = (u32)D_8007A280;
                for (i = 0; i < n; i++) {
                    func_800599B8((void *)s->rects, pix);
                    pix += ((Rect *)s->rects)->w / 2;
                    s->rects += 8;
                }
                if (s->more) {
                    s->mode = 2;
                } else {
                    s->mode = 0;
                }
                break;
            case 0:
            case 5:
                s->buf_idx = 0;
                func_80043994(s->bitmap, 16);
                s->rect.h = 32;
                s->rect.w = 32;
                s->rect.y = 0;
                s->rect.x = 0;
                s->bit = 1;
                s->index = 0;
                for (;;) {
                    if (s->index >= 64) {
                        if (s->more) {
                            s->mode = 2;
                        } else {
                            s->mode = 0;
                        }
                        break;
                    }
                    if (s->bitmap[s->index] & s->bit) {
                        break;
                    }
                    if (s->bit == 128) {
                        s->bit = 1;
                        s->index++;
                    } else {
                        s->bit <<= 1;
                    }
                    s->rect.x += 32;
                    if (s->rect.x >= 1024) {
                        s->rect.x = 0;
                        s->rect.y += 32;
                    }
                }
                s->mode++;
                break;
            case 7:
                if (s->dest_size < 0) {
                    goto more;
                }
                s->mode = 3;
                s->remain = (u32)(D_80079A7C - 2045) >> 2;
                s->dst = D_80072C80;
                break;
            case 1:
                s->mode = 3;
                s->remain = (u32)(D_80079A7C - 2045) >> 2;
                s->dst = s->dst_alt;
                break;
            case 8:
                s->mode = 6;
                s->remain = (u32)(D_80079A7C - 2045) >> 2;
                break;
            case 2:
                if (s->busy) {
                    goto more;
                }
                s->mode = 3;
                s->dst = ((s32 *)s->pairs)[s->count * 2 + 1];
                s->remain = (u32)(D_80079A7C - 2045) >> 2;
                break;
            case 3:
                if (s->busy) {
                    goto more;
                }
                while (func_8002FB08(((s32 *)s->pairs)[s->count * 2]) == 0) {
                }
                s->mode = 4;
                s->remain = D_80079A7C - 2048;
                break;
            case 4:
                s->mode = 5;
                s->remain = (u32)(D_80079A7C - 2045) >> 2;
                s->dst = s->dst_alt;
                func_80018714(s->dst);
                break;
            }
            break;
        case 1:
            pix = (s32 *)(D_80079A70 + (s->buf_idx << 11));
            func_80043994(pix, 512);
            func_800599B8(&s->rect, pix);
            s->buf_idx = (s->buf_idx + 1) & 3;
            do {
                if (s->bit == 128) {
                    s->bit = 1;
                    s->index++;
                } else {
                    s->bit <<= 1;
                }
                if (s->index >= 64) {
                    if (s->more) {
                        s->mode = 2;
                    } else {
                        s->mode = 0;
                    }
                    break;
                }
                s->rect.x += 32;
                if (s->rect.x >= 1024) {
                    s->rect.x = 0;
                    s->rect.y += 32;
                }
            } while (!(s->bitmap[s->index] & s->bit));
            break;
        case 3:
            if (s->remain < 513) {
                func_80043994((void *)s->dst, s->remain);
                if (s->more) {
                s->mode = 2;
            } else {
                s->mode = 0;
            }
            break;
            }
            func_80043994((void *)s->dst, 512);
            s->dst += 2048;
            s->remain -= 512;
            break;
        case 4:
            if (s->remain < 2049) {
                words = (s->remain + 3) / 4;
                func_80043994(D_80079A70, words);
                if (func_8002FC64(s->remain, D_80079A70) == 0) {
                    goto aborted;
                }
                s->count++;
                if (s->more) {
                    goto more_or_idle;
                }
                s->mode = 0;
                break;
            }
            func_80043994(D_80079A70, 512);
            pos = func_8002FC64(2048, D_80079A70);
            s->dst += 2048;
            s->remain -= 2048;
            if (pos == 0) {
            aborted:
                func_8002FDC8();
                s->mode = 7;
            }
            break;
        case 5:
            func_80043994(D_80079A70, 512);
            if (func_80018730(D_80079A70) == 0) {
                if (s->more) {
                    s->mode = 2;
                } else {
                    s->mode = 0;
                }
                break;
            }
            break;
        case 6:
            s->remain -= 512;
            if (s->remain > 0) {
                break;
            }
        more_or_idle:
            if (s->more) {
            more:
                s->mode = 2;
            } else {
                s->mode = 0;
            }
            break;
        }
        if (s->mode == 2) {
            s->read_state = 1;
        } else if (s->mode == 7) {
            s->read_state = 2;
        }
    }
    if (intr == 5) {
        if (s->mode == 4) {
            func_8002FDC8();
        }
    failed:
        s->read_state = 2;
    }
}
