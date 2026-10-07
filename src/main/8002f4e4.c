/* Owner re-derivation from retail assembly (clean input set). */
#include "psx_types.h"

/* Looks up the table entry for an object's (kind, row) pair in the active
 * lookup table; 0 when there is no table, no mapping or the entry is 127. */
typedef struct {
    s16  unk0;
    s16  count;
    s16  base;
    s16  unk6;
    u32  map;   /* guest s16 * */
    s16  rows;
    s16  cols;
    u32  data;  /* guest u16 * */
} LookupTable;

typedef struct {
    s16 key;
    u8  unk2[22];
} KindInfo;     /* 0x18 bytes */

extern s16          D_800A4EF0;
extern LookupTable *D_800A4EE8;
extern KindInfo     D_800A4640[];

u16 func_8002F4E4(u8 *obj)
{
    LookupTable *table;
    s32 key;
    s32 row;
    s32 stride;
    u16 *line;
    u16 value;

    if (D_800A4EF0 == 0) {
        return 0;
    }
    table = D_800A4EE8;
    if (table == 0) {
        return 0;
    }
    key = D_800A4640[obj[2]].key;
    if (key < table->base) {
        return 0;
    }
    key -= table->base;
    if (key >= table->count) {
        return 0;
    }
    key = ((s16 *)table->map)[key];
    if (key == 0) {
        return 0;
    }
    row = obj[3];
    if (row >= table->rows) {
        return 0;
    }
    key--;
    stride = table->cols * 2;
    line = (u16 *)(table->data + row * stride);
    value = line[key];
    if (value != 127) {
        return value;
    }
    return 0;
}
