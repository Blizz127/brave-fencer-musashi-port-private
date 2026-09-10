/* Exact overlay word export for [80128A28,80128AF4) from MAIN.CD
 * member0012 (extracted/overlays/main/0012.bin offset 0x288D0, base 80128158).
 * Callee of 80128228.
 */
#include "psx_types.h"

/* Recovered from member0012 and verified byte-exact by match_function.py.
 * These globals are pointer cells, not direct-call function symbols.
 * The signed low halfword of the callback result selects the next state. */
extern void func_80010DE0(void);
extern void func_80011B7C(s32);
extern void func_80011C10(void);
extern void (*D_8017E354)(void);
extern s32 (*D_8017E358)(void);
extern u16 D_800B99F6;
extern s16 D_800B9A00;

void func_80128A28(void) {
    s16 result;
    switch (D_800B99F6) {
    case 1:
        D_8017E354();
        /* fall through */
    case 0:
        func_80011C10();
        return;
    case 2:
        result = D_8017E358();
        if (result != 0) {
            if (result < 0) {
                func_80011B7C(0);
                D_800B9A00 = 1;
                return;
            }
            func_80010DE0();
        } else {
            return;
        }
        break;
    }
}

