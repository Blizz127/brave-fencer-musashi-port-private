/* Owner re-derivation from retail assembly (clean input set). */
#include "psx_types.h"

/* Clears the active flag (byte 10) of every 12-byte record in the four
 * record lists; D_80065504[i] holds the length of list i. */
typedef struct {
    u8 unk0[10];
    u8 active;
    u8 unkB;
} Record;

extern s32     D_80065504[4];
extern u32     D_8006A970[4];  /* guest Record * */

void func_8002CC4C(void)
{
    s32 i;
    s32 j;
    Record *rec;
    u32 *list = D_8006A970;

    for (i = 0; i < 4; i++, list++) {
        j = 0;
        rec = (Record *)*list;
        while (j < D_80065504[i]) {
            j++;
            rec->active = 0;
            rec++;
        }
    }
}
