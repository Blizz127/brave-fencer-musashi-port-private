/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_801530E4 - byte-exact against retail at -O2 (tools/register_match.py). */
struct S;
struct S {
    u8  pad0[0x7E];  
    u16 f7E;         
};
void func_80146CA0(void *a0);
s32 func_801472C8(struct S *a0);
void func_801474EC(s32 *a0);
void func_80149020(s32 *a0);
extern void func_80019064(void *a0);
void func_8014CBF8(void *a0);
extern void func_80146CA0(void *a0);
extern void func_80149020(s32 *a0);
extern s32 func_801472C8(struct S *a0);
extern void func_801474EC(s32 *a0);
extern void func_8014CBF8(void *a0);
extern u8 D_80062C04[];
extern void func_80155440(s32 *a0);

void func_801530E4(s32 arg0)
{
    func_80019064(&D_80062C04);
    func_80149020(arg0);
    func_801472C8(arg0);
    (*(  s8 * )((s8 *)( arg0 ) + (  0xDE )))  = 0x40;
    func_8014CBF8(arg0);
    func_801474EC(arg0);
    func_80155440(arg0);
    func_80146CA0(arg0);
}
