/* Owner re-derivation from retail assembly (clean input set). */
#include "psx_types.h"
/* Copies three 16-bit fields (+6, +0xA, +0xE) of a record into a local vector and passes it to func_8012D664. */
void func_8012D664(u16 *v);
void func_8012D624(u16 *p) {
    u16 v[3];
    v[0] = p[3];
    v[1] = p[5];
    v[2] = p[7];
    func_8012D664(v);
}
