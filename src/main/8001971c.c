/* Owner re-derivation from retail assembly (clean input set). */
/* Disc file table setup: finds the boot files, loads the sector table to
 * 80180000 and converts its relative sectors into absolute positions. */
#include "psx_types.h"

typedef struct {
    s32 sector;
    s32 size;
} FileSlot;

typedef struct {
    u8 name[20];
    u8 file[24];
    s32 pad;
} DiscFile;

extern DiscFile D_80063044;
extern DiscFile D_80062C24[];
extern s32 D_800747D0;
extern s32 D_800747D4;
extern s32 D_80063074;
extern s32 D_800747D8;
#define SECTOR_TABLE ((FileSlot *)0x80180000)
extern FileSlot D_800AE830[];

extern void func_80019990(void);
extern s32 func_80045374(void *file, void *name);
extern s32 func_80019A24(void *file, void *dst, s32 sectors, s32 mode);
extern s32 func_8004239C(s32 mode);
extern s32 func_80043B1C(void *pos);
extern void func_80043A18(s32 sector, void *pos);

void func_8001971C(void)
{
    s32 i;
    s32 r;
    s32 k;
    s32 n;
    s32 m;
    s32 pos;
    s32 slot;
    FileSlot spare;

    func_80019990();
    i = 0;
    do {
        r = func_80045374(D_80063044.file, D_80063044.name);
        i++;
        if (r != -1) {
            break;
        }
    } while (i < 16);
    D_800747D0 = r != 0;
    D_800747D4 = 1;
    D_80063074 = 0;
    D_800747D8 = 0;
    for (i = 0; (u32)i < 21; i++) {
        while ((u32)(func_80045374(D_80062C24[i].file, D_80062C24[i].name) + 1) < 2) {
        }
    }
    while (func_80019A24(D_80062C24[0].file, SECTOR_TABLE, 3648, 0) == 0) {
        func_8004239C(0);
    }
    slot = 0;
    k = 0;
    for (i = 0; i < 8; i++) {
        pos = func_80043B1C(D_80062C24[i + 1].file);
        n = SECTOR_TABLE[k].sector;
        k++;
        for (m = 0; m < n; m++) {
            if (SECTOR_TABLE[k].sector != 0) {
                func_80043A18(SECTOR_TABLE[k].sector + pos, &D_800AE830[slot]);
                D_800AE830[slot].size = SECTOR_TABLE[k].size;
            }
            k++;
            slot++;
        }
    }
}
