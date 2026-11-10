/* sc03_0098: func_801841F0 - ground probe at the object; on a clear probe, switch to the fall state.
 * Hand-recovered from the retail words (gcc-2.7.2 -O2). */
#include "psx_types.h"
extern u8 D_801AEF34[];
extern s32 func_8012CEB0();
extern void func_80131E00();
extern void func_8012A828();
typedef struct {
    u16 act; u16 kind; u8 pad4[2]; u16 x; u8 p8[2]; u16 y; u8 pc[2]; u16 z; u8 p10[0x48];
    s32 w58; u16 h5c;
} Obj;
void func_801841F0(Obj *p) {
    s16 a[4];
    s16 b[4];
    b[0] = a[0] = p->x;
    b[1] = a[1] = p->y;
    b[2] = a[2] = p->z;
    a[1] = a[1] - 8;
    b[1] = b[1] + 8;
    if ((func_8012CEB0(a, b, 0) & 0x19) != 0) {
        func_80131E00(p, 6);
        return;
    }
    func_8012A828(p, D_801AEF34);
    p->kind = 6;
    p->h5c = 0xA810;
}
