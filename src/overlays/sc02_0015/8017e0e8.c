/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8017E0E8 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_8012E8E0(s32 a0, s32 a1);
extern int func_80178970(void);
extern void func_80178D18(void);
extern s16 D_8018B074[];
extern void (*D_80181DBC[])(void);
extern void func_8012A828(s32 a0, void *a1);

void func_8017E0E8(arg0)
void *arg0;
{
    extern int func_80178970(void);
    extern void func_80178D18(void);
    extern void func_8012E8E0(s32 a0, s32 a1);
    extern void func_8012A828(s32 a0, void *a1);
    extern void (*D_80181DBC[])(void);
    extern s16 D_8018B074[];

    if (func_80178970() != 0) {
        ((void (*)(s32))func_80178D18)((s32)arg0);
        *(s16 *)((s32)arg0 + 2) = 1;
        func_8012E8E0((s32)arg0, (s32)&D_80181DBC);
        func_8012A828((s32)arg0, (s32)&D_8018B074);
    }
}
