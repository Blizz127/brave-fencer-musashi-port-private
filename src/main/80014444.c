/* Owner re-derivation from retail assembly (clean input set). */
#include "psx_types.h"

/* Geometry init for a session: InitGeom, projection distance 1000 (also kept
 * in D_80126950), the game's 2048 scale setup, the two coordinate systems in
 * the game state block (+0x1A0, +0x1F0) and light mode 0. */
extern u8 D_800AF630[];
extern s32 D_80126950;

extern void func_80047CB4(void);  /* InitGeom */
extern void func_8004923C(s32 h);  /* SetGeomScreen */
extern void func_80053218(void);
extern void func_800144D4(void);
extern void func_8001455C(void);
extern void func_8002850C(s32 x, s32 y, s32 z);
extern void func_8002823C(void);
extern void func_80052D90(s32 super, u8 *coord);  /* GsInitCoordinate2 */
extern void func_800538EC(s32 mode);  /* GsSetLightMode */

void func_80014444(void)
{
    u8 *state = D_800AF630;

    func_80047CB4();
    D_80126950 = 1000;
    func_8004923C(1000);
    func_80053218();
    func_800144D4();
    func_8001455C();
    func_8002850C(0x800, 0x800, 0x800);
    func_8002823C();
    func_80052D90(0, state + 0x1A0);
    func_80052D90(1, state + 0x1F0);
    func_800538EC(0);
}
