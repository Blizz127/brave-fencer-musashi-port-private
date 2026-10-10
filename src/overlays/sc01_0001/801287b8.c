/* Overlay range [801287B8,801288B0) from MAIN.CD member 0012.
 * SHA256(span)=2845ab190f9887efa58b0eb9ae1f2f166d17816e78e1e20d24922422235e1cc8.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_801287B8 - byte-exact against retail at -O2 (tools/register_match.py). */
struct S8014FDF4;
struct S8014FDF4 {
    s16 pad0[3];    
    s16 f6;         
    s16 pad8;       
    s16 fA;         
    s16 padC;       
    s16 fE;         
    s16 pad[0x3C];  
    s16 f88;        
    s16 f8A;        
    s16 f8C;        
};
extern u8 D_800B9A64;
extern void func_80129CF8(void);
extern void func_8017849C(void);
extern void func_8014FDF4(struct S8014FDF4 *a0);
extern s32 func_801505FC(s32 a0);
extern s32 func_801508B4(s32);
extern void func_80165E90(void);
extern void func_801627E8(void);
extern void func_80162B1C(void);
extern void func_80165CA0(void);
extern void func_80129010(void);
extern void func_8013CA14(void);
extern void func_800190AC(void);
extern void func_8012956C(void);
extern s32 func_8016E95C();
extern void func_801754A8(void);
extern void func_8013BC7C(void *);
extern void func_8013BCDC(void);
extern void func_801379FC(void);
extern void func_8001212C(void);

void func_801287B8(void) {

    extern s32 D_80126B58;
    extern s32 D_801F3158;
    extern u16 D_800B99DA;
    extern u8 D_800B9A64;
    func_80129CF8();
    func_8017849C();
    ((void (*)(void *))func_8014FDF4)(&D_80126B58);
    ((void (*)(void *))func_801505FC)(&D_80126B58);
    ((void (*)(void *))func_801508B4)(&D_80126B58);
    func_80165E90();
    func_801627E8();
    func_80162B1C();
    func_80165CA0();
    func_80129010();
    func_8013CA14();
    func_800190AC();
    func_8012956C();
    ((void (*)(void))func_8016E95C)();
    func_801754A8();
    {
         

        register volatile s32 *p __asm__("$4") = &D_801F3158;
        if (*p == 0) {
            func_8013BC7C((void *)p); /* a0 already holds p (retail) */
        }
    }
    func_8013BCDC();
    func_801379FC();
    D_800B99DA++;
    if (D_800B9A64 != 0) {
        func_8001212C();
    }
}
