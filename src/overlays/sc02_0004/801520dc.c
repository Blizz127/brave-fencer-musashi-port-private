/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_801520DC - byte-exact against retail at -O2 (tools/register_match.py). */
typedef s32 M2C_UNK;
struct S;
struct S {
    u8  pad0[0x7E];  
    u16 f7E;         
};
extern s32 func_80146A6C(s32 a0, void *a1, s32 a2, s32 a3, s32 a4, s32 a5, s32 a6);
void func_80146CA0(void *a0);
void func_80146DB8(s32 *a0, s32 *a1);
s32 func_801472C8(struct S *a0);
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
extern void func_80149020(s32 *a0);
extern void func_80146DB8(s32 *a0, s32 *a1);
extern s32 func_801472C8(struct S *a0);
extern void func_80147324(s32 a0);
extern void func_801474EC(s32 *a0);
extern void func_8014CBF8(void *a0);
extern u8 D_80062C04[];
extern M2C_UNK D_8017FA10;

void func_801520DC(s32 arg0)
{
    func_80019064(&D_80062C04);
    func_80151204(arg0, (*(  s16 * )((s8 *)( arg0 ) + (  0xF2 ))) );
    func_80149020(arg0);
    func_801472C8(arg0);
    (*(  s8 * )((s8 *)( arg0 ) + (  0xDE )))  = 0x10;
    func_80146DB8(arg0, &D_8017FA10);
    func_801477E8(arg0, 0x40000);
    func_8014CBF8(arg0);
    func_801474EC(arg0);
    func_80146A6C(0x10, arg0, (*(  s16 * )((s8 *)( arg0 ) + (  6 ))) , (*(  s16 * )((s8 *)( arg0 ) + (  0xA ))) , (s32) (*(  s16 * )((s8 *)( arg0 ) + (  0xE ))) , 0, 0);
    func_80147324(0x441);
    func_80146CA0(arg0);
}
