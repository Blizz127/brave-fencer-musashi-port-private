/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_801533A4 - byte-exact against retail at -O2 (tools/register_match.py). */
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

void func_801533A4(s32 a0)
{
    func_80019064(D_80062C04);
    func_80149020(a0);
    func_801472C8((struct S *)a0);
    *((u8 *)a0 + 0xDE) = 0x40;
    func_8014CBF8(a0);
    func_801474EC(a0);
    func_80155440(a0);
    func_80146CA0(a0);
}
