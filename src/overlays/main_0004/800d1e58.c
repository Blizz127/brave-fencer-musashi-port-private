/* Clean-room re-derivation from the retail disassembly only (B28): intro
 * movie overlay, start the selected movie. Clears 800EC9E0, hands the
 * 800D942C entry chosen by 8001BFA0 to 800D1E9C, then calls 8001BFB0. */
#include "psx_types.h"

typedef struct {
    char *name;
    u8 rest[28];
} MovieEntry;

extern s32 D_800EC9E0;
extern MovieEntry D_800D942C[];
extern s32 func_8001BFA0(void);
extern void func_800D1E9C(MovieEntry *);
extern void func_8001BFB0(void);

void func_800D1E58(void) {
    D_800EC9E0 = 0;
    func_800D1E9C(&D_800D942C[func_8001BFA0()]);
    func_8001BFB0();
}
