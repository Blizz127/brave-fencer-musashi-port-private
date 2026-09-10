/* MAIN10 resident retail span [800D1938,800D1984), offset 0x22B40 at base 800AEDF8.
 * Donor: Druthulu resident_jr_800D128C func_800D1938, cleaned to house style. */
#include "psx_types.h"

typedef struct {
    u8 pad[0x14];
    u8 f14;
    u8 f15;
} S800D1938;

extern void func_800D1F58(void);
extern void func_801285D4(void);
extern void func_800D1984(S800D1938 *arg0);

s32 func_800D1938(S800D1938 *arg0) {
    func_800D1F58();
    func_801285D4();
    arg0->f15 = 0;
    arg0->f14 = arg0->f14 + 1;
    func_800D1984(arg0);
    return 0;
}
