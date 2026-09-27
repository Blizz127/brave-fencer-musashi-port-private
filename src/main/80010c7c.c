/* Exact retail word export for [80010C7C,80010CEC); EXE and assembly verified. */
#include "psx_types.h"

extern u8 D_800AE838;
extern void *D_80072C70;
extern int func_80019A24(void *, void *, int, int);
extern void func_80010AE0(int);
extern void func_80011778(void);

void func_80010C7C(void) {
    int res;
    res = func_80019A24(&D_800AE838, D_80072C70, 0, 0);
    if (res != 0) {
        func_80010AE0(0x3E0);
        func_80011778();
    }
}
