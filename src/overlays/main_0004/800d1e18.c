/* Clean-room re-derivation from the retail disassembly only (B28): intro
 * movie overlay, locate the movie file. 8001BFA0 selects a 32-byte entry of
 * the table 800D942C, whose first word names the file. Returns nonzero when
 * CdSearchFile fills the CdlFILE 800EC9FC. */
#include "psx_types.h"

typedef struct {
    char *name;
    u8 rest[28];
} MovieEntry;

extern MovieEntry D_800D942C[];
extern u8 D_800EC9FC[];
extern s32 func_8001BFA0(void);
extern void *func_80045374(void *, char *);

s32 func_800D1E18(void) {
    return func_80045374(D_800EC9FC, D_800D942C[func_8001BFA0()].name) != 0;
}
