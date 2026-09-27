/* Exact retail overlay 0010 export [800CFBCC,800CFBE8), offset 0x20DD4. */
#include "psx_types.h"

extern u16 D_80114E70;
extern u16 D_80114E74;

void func_800CFBCC(u16 arg0) {
    D_80114E70 = 1;
    D_80114E74 = arg0;
}
