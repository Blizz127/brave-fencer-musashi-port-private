/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80152DA8 - byte-exact against retail at -O2 (tools/register_match.py). */
typedef s32 M2C_UNK;
void func_80146CA0(void *a0);
void func_80146DB8(s32 *a0, s32 *a1);
void func_80147324(s32 arg0);
void func_801474EC(s32 *a0);
void func_801477E8(s32 *a0, s32 a1);
void func_80149020(s32 *a0);
extern void func_80019064(void *a0);
void func_8014CBF8(void *a0);
extern void func_80147324(s32 arg0);
extern int func_80151204(int arg, int a1);
int func_80151204(int a0, int a1);
extern void func_801477E8(s32 *a0, s32 a1);
extern void func_80146CA0(void *a0);
extern M2C_UNK D_800D5880;
extern void func_80154274(s32 *a0, s32 a1);
extern void func_80149020(s32 *a0);
extern s32 D_80062C14;
extern void func_80146DB8(s32 *a0, s32 *a1);
extern void func_80147324(s32 a0);
extern void func_801474EC(s32 *a0);
extern void func_8014CBF8(void *a0);
extern M2C_UNK D_8017FFF0;

void func_80152DA8(s32 arg0)
{
    func_80019064(&D_80062C14);
    func_80151204(arg0, (*(  s16 * )((s8 *)( arg0 ) + (  0xF2 ))) );
    func_80149020(arg0);
    func_80154274(arg0, &D_800D5880);
    func_80147324(0x451);
    (*(  s8 * )((s8 *)( arg0 ) + (  0xDE )))  = 0x10;
    (*(  s8 * )((s8 *)( arg0 ) + (  0xDF )))  = 8;
    func_80146DB8(arg0, &D_8017FFF0);
    func_801477E8(arg0, 0xFFE40000);
    func_8014CBF8(arg0);
    func_801474EC(arg0);
    func_80146CA0(arg0);
}
