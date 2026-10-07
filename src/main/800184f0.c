/* Owner re-derivation from retail assembly (clean input set). */
#include "psx_types.h"

/* End-of-frame VRAM upload pump: for each of the 32 active upload slots,
 * runs its command list (image uploads to a fixed or slot-chosen position,
 * packed images, and the type-11 upload) until an end command, then frees
 * the slot. The upload rectangle is built in the scratchpad. */
typedef struct {
    s16 x;
    s16 y;
    s16 w;
    s16 h;
} Rect;

typedef struct {
    u16 type;
    u16 unk2;
    s16 x;
    s16 y;
    s16 w;
    s16 h;
    u32 data;   /* guest pointer to the image words */
} UploadCmd;    /* 0x10 bytes */

typedef struct {
    s16 active;
    u16 unk2;
    u32 cmds;   /* guest pointer to the UploadCmd list */
    s16 x;
    s16 y;
    u8  page;
    u8  placed;
    u8  unkE[2];
} UploadSlot;   /* 0x10 bytes */

typedef struct {
    s32 unk0;
    Rect rect;
    u32 data;   /* guest pointer to the pixel words */
    u8  unk10[16];
} ImageInfo;

extern UploadSlot D_800B97D8[32];

extern void func_800599B8(Rect *rect, u32 *data);
extern void func_80053D44(u32 *image, ImageInfo *info);
extern void func_80058890(u32 *data, s32 arg1, s32 arg2, s32 x, s32 y, s32 w, s32 h);

void func_800184F0(void)
{
    Rect *rect = (Rect *)0x1F800000;
    UploadSlot *slot;
    UploadCmd *cmd;
    ImageInfo info;
    s32 done;
    s32 type;
    s32 i;

    for (i = 0, slot = D_800B97D8; i < 32; i++, slot++) {
        if (slot->active == 0) {
            continue;
        }
        cmd = (UploadCmd *)slot->cmds;
        done = 0;
        do {
            /* 0: slot position, 5: image, 9: placed, 10: skip,
             * 11: packed; anything else ends the list. */
            type = cmd->type;
            if (type == 9) {
                goto upload_placed;
            }
            if (type < 10) {
                if (type == 0) {
                    goto upload_slot;
                }
                if (type == 5) {
                    goto upload_image;
                }
                done = 1;
                goto next;
            }
            if (type == 11) {
                goto upload_packed;
            }
            if (type < 11) {
                goto next;
            }
            goto end_list;
        upload_placed:
            if (slot->placed == 0) {
                rect->x = cmd->x;
                rect->y = cmd->y;
            } else {
                rect->x = (slot->page > 32) << 8;
                rect->y = slot->page | 0x1E0;
            }
            rect->w = cmd->w;
            rect->h = cmd->h;
            func_800599B8(rect, (u32 *)cmd->data);
            goto next;
        upload_slot:
            if (slot->placed == 0) {
                rect->x = cmd->x;
                rect->y = cmd->y;
            } else {
                rect->x = slot->x;
                rect->y = slot->y;
            }
            rect->w = cmd->w;
            rect->h = cmd->h;
            func_800599B8(rect, (u32 *)cmd->data);
            goto next;
        upload_image:
            func_80053D44((u32 *)cmd->data, &info);
            rect->x = info.rect.x;
            rect->y = info.rect.y;
            rect->w = info.rect.w;
            rect->h = info.rect.h;
            func_800599B8(rect, (u32 *)info.data);
            goto next;
        upload_packed:
            func_80058890((u32 *)cmd->data, 1, 0, cmd->x, cmd->y, cmd->w * 2, cmd->h);
            goto next;
        end_list:
            done = 1;
        next:
            cmd++;
        } while (!done);
        slot->active = 0;
    }
}
