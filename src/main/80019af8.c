/* Clean-room re-derivation from the retail disassembly only (B27): disc file loader state machine. */
#include "psx_types.h"

extern s32 func_800435CC(s32 com, void *param, u8 *result);
extern s32 func_8004355C(s32 mode, u8 *result);
extern s32 func_800435B4(s32 callback);
extern void func_800434BC(void);
extern s32 func_80043B1C(void *pos);
extern s32 func_8002FD14(s32, s32);
extern void func_8001A0FC(void);
extern s32 func_8001A114(void);
extern void func_8001A338(void);

extern s32 D_800AE6E8;
extern s32 D_800AE6F0;
extern s32 D_800AE6F8;
extern s32 D_800AE6FC;
extern s32 D_800AE700;
extern s32 D_800AE708;
extern s32 D_800AE70C;
extern s32 D_800AE71C;
extern s32 *D_800AE724;
extern s32 D_800AE728;
extern s32 D_800AE72C;

typedef struct {
    /* 0x00 */ s32 saved_cb;
    /* 0x04 */ u8 cd_result[8];
    /* 0x0C */ u8 cd_param[8];
    /* 0x14 */ s32 unk14;
    /* 0x18 */ s32 read_state;
    /* 0x1C */ s32 retry;
    /* 0x20 */ s32 seek_wait;
    /* 0x24 */ s32 unk24[16];
    /* 0x64 */ u8 unk64;
    /* 0x65 */ u8 unk65;
    /* 0x66 */ u8 unk66[10];
    /* 0x70 */ u32 file; /* CdlFILE * (guest address) */
    /* 0x74 */ s32 dest;
    /* 0x78 */ s32 lba;
    /* 0x7C */ s32 done;
} Loader;

extern Loader D_800AE734;
#define L D_800AE734


void func_80019AF8(s32 pause) {
    s32 result;
    s32 i;
    s32 *state;

    switch (D_800AE6F0) {
    case 0:
        L.retry = 0;
        D_800AE71C = 0;
        D_800AE70C = 0;
        L.cd_param[0] = 0xA0;
        func_800435CC(14, L.cd_param, L.cd_result);
        if (L.cd_result[0] & 0x10) {
        shell_open:
            D_800AE6F0 = 9;
            break;
        }
        D_800AE6F0++;
    case 1:
        result = func_8004355C(1, L.cd_result);
        D_800AE6E8 = result;
        if (result == 0) {
            break;
        }
        if (result == 5) {
            goto reset;
        }
        if (result != 2) {
            break;
        }
        L.retry = 0;
        D_800AE6F0++;
    case 2:
        if (++L.retry < 3) {
            break;
        }
        L.retry = 0;
        D_800AE6F0++;
        break;
    case 3:
        func_800435CC(21, (void *)L.file, L.cd_result);
        if (L.cd_result[0] & 0x10) {
            goto shell_open;
        }
        L.seek_wait = 0;
        L.lba = func_80043B1C((void *)L.file);
        D_800AE6F0++;
    case 4:
        result = func_8004355C(1, L.cd_result);
        D_800AE6E8 = result;
        if (result == 5) {
            L.retry++;
        retry_seek:
            func_800434BC();
            D_800AE6F0 = 3;
            break;
        }
        if (result == 0) {
            break;
        }
        if (result != 2) {
            L.done = 0;
            if (++L.seek_wait >= 181) {
                goto retry_seek;
            }
            return;
        }
        if (pause != 0) {
            func_800435CC(9, 0, L.cd_result);
            if (L.cd_result[0] & 0x10) {
                goto shell_open;
            }
            D_800AE6F0 = 8;
            D_800AE70C = *(s32 *)L.file;
            break;
        }
        D_800AE6F0++;
    case 5:
        L.read_state = 0;
        if (L.dest <= 0) {
            D_800AE6F8 = 0;
        } else {
            D_800AE6F8 = 3;
            L.unk14 = (L.dest + 3) / 4;
            L.unk64 = 1;
            D_800AE728 = D_800AE72C;
        }
        L.saved_cb = func_800435B4((s32)func_8001A338);
        func_800435CC(6, 0, L.cd_result);
        if (L.cd_result[0] & 0x10) {
            goto shell_open;
        }
        L.retry = 0;
        D_800AE6F0++;
    case 6:
        if (L.read_state == 1) {
            func_800435B4(L.saved_cb);
            func_800435CC(9, 0, L.cd_result);
            if (L.cd_result[0] & 0x10) {
                goto shell_open;
            }
            D_800AE6F0++;
            if (D_800AE71C == 0) {
                D_800AE6F0++;
            }
        } else if (L.read_state == 2) {
            func_800435B4(L.saved_cb);
            goto reset;
        } else if (++L.retry >= 300) {
            func_800435B4(L.saved_cb);
            D_800AE6F0 = 0;
            func_800434BC();
        }
        break;
    case 7:
        for (i = 0; i < D_800AE71C; i++) {
            while (func_8002FD14(D_800AE724[i * 2], D_800AE724[i * 2 + 1]) == 0) {
            }
        }
        state = &D_800AE6F0;
        (*state)++;
        break;
    case 8:
        result = func_8004355C(1, L.cd_result);
        D_800AE6E8 = result;
        if (result == 2) {
            D_800AE728 = 0x80010000;
            D_800AE6F0 = 0;
            D_800AE6F8 = 0;
            D_800AE6FC = 0;
            D_800AE700 = 0;
            L.unk14 = 1;
            L.read_state = 0;
            L.unk64 = 0;
            L.unk65 = 0;
            D_800AE70C = 0;
            L.done = 1;
            D_800AE708 = 0;
            return;
        }
        if (result == 5) {
            func_800434BC();
            func_800435CC(9, 0, L.cd_result);
            if ((L.cd_result[0] & 0x10) == 0) {
                break;
            }
            goto shell_open;
        }
        break;
    case 9:
        func_8001A0FC();
        state = &D_800AE6F0;
        (*state)++;
    case 10:
        D_800AE6E8 = func_8001A114();
        if (D_800AE6E8 != 0) {
        reset:
            D_800AE6F0 = 0;
        }
        break;
    }
    L.done = 0;
}
