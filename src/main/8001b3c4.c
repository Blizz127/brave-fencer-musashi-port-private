/* Exact retail word export for [8001B3C4,8001B710); EXE and assembly verified. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8001B3C4 (vendor: ResourceLoadStateMachine) - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"

/* Vendor names mapped to address-named symbols for the link-by-address harness. */
#define CdQueueBusy func_80034B98
#define ResourceGetCdLoc func_8001B788
#define StreamLoadStateMachine func_800363CC
#define cdFileLocTable D_800AE830
#define cdReq_curSector D_800AE708
#define resLoad_curId D_800C6D34
#define resLoad_lastId D_800A654C
#define resLoad_loadedFileIdx D_800747F8
#define resLoad_result D_800C6D10
#define resLoad_state D_800AE7EC
#define resourceIdMap D_80063138

#define ResourceLoadStateMachine func_8001B3C4
/* resourceIdMap is a table of 6-byte rows. The destination TU (src/800.c) already declares this
 * column set as three byte-typed externs (u8 resourceIdMap[], u8 D_8006313A, u8 D_8006313C) in two
 * other functions (func_8001ACF0, ResourceGetCdLoc) — a second, differently-typed file-scope
 * extern of the same symbols is a hard C constraint violation, so those exact declarations are
 * adopted verbatim below. See the use-site comment for how the byte match is kept despite that. */
extern int func_8001A114(void);
extern void func_8001B710(void);
extern void func_8002D4C8(int arg0, int arg1);
extern void func_80036D58(s16);
extern int StreamLoadStateMachine(int arg0, void *loc, int n);
extern s32 CdQueueBusy(void);
extern s32 ResourceGetCdLoc(s16 arg0);
extern s32 resLoad_state;
extern s32 resLoad_curId;
extern s32 resLoad_lastId;
extern s32 resLoad_loadedFileIdx;
extern s32 resLoad_result;
extern s32 cdReq_curSector;
extern u8 resourceIdMap[]; /* 6B entries {s16 fileIdx; s16 D_8006313A; s16 D_8006313C} */
extern u8 D_8006313A;
extern u8 D_8006313C;
extern u8 cdFileLocTable[]; /* 8B rows {s32 startSector; s32 size}; sites carry an explicit *8 */
extern s32 D_800AE6F4;
extern s32 D_800AE70C;

/* Byte-measured (both tried literally, both NON-MATCH at the same 109/211 site): a raw
 * u8-pointer-arithmetic use site (mirroring the other functions' own idiom), AND a
 * `(ResMapCol *) resourceIdMap` cast of the u8[] object, both leave gcc treating the address as a
 * computed POINTER value — it gets CSE'd into a callee-saved reg (`la $s0,resourceIdMap` hoisted
 * across the 6 uses) instead of rematerialising `lui %hi / addu / lo_sum` at every site the way the
 * target does. Only a genuine array-of-struct OBJECT TYPE avoids this (gcc builds a true ARRAY_REF
 * off the symbol instead of an INDIRECT_REF off a pointer expression) — but declaring `resourceIdMap`
 * that way conflicts with the u8[] extern already load-bearing elsewhere in this TU (func_8001ACF0,
 * ResourceGetCdLoc): two file-scope externs of one identifier with incompatible types is a hard C
 * constraint violation, which is exactly what the reconciler's refuse-TYPE caught.
 * The resolution (cookbook §37/§124 "data asm-label alias"): declare a SEPARATE C identifier bound
 * to the SAME linker symbol via `__asm__("resourceIdMap")`. A distinct identifier sidesteps the
 * redeclaration-type conflict entirely (the TU's own u8[] declarations, wherever they occur, are
 * untouched and still visible under their own name), while this alias gets the true array-of-struct
 * type gcc needs to avoid the CSE. Byte-measured MATCH. */
typedef struct {
    s16 v;
    s16 pad[2];
} ResMapCol;
extern ResMapCol aResourceIdMap[] __asm__("D_80063138"); /* vendor: __asm__("resourceIdMap") */
extern ResMapCol aD_8006313A[] __asm__("D_8006313A");
extern ResMapCol aD_8006313C[] __asm__("D_8006313C");
#define RES_FILE aResourceIdMap
#define RES_ARG aD_8006313A
#define RES_POST aD_8006313C

/* Loads the resource named by resLoad_curId. Polled state machine (resLoad_state 0..3); the
 * caller reads the done flag out of resLoad_result.
 *   state 0  arbitrate: load-once cache hit (resLoad_lastId / resLoad_loadedFileIdx), non-CD
 *            resources (file index < 0), CD-queue busy, and the in-flight-sector dedup; on success
 *            latch cdReq_curSector and FALL THROUGH into state 1.
 *   state 1  pump StreamLoadStateMachine until it reports 2 (done).
 *   state 2  reset the stream bookkeeping and FALL THROUGH into state 3.
 *   state 3  poll func_8001A114 for the tail work, then idle.
 *
 * The switch index is read UNSIGNED: that is what makes gcc's case tree degrade to the target's
 * bare equality chain (tested 1,0,2,3 = balance_case_nodes' root-then-bounded-left order). Signed
 * (`switch (resLoad_state)`) inserts an `slti v0,v1,2` range test the target does not have.
 * resLoad_state itself keeps the TU-canonical s32 type; the cast lives at the use site (§20). */
void ResourceLoadStateMachine(void) {
    s32 result;
    /* The original keeps 8 bytes of frame the emitted code never touches (target frame 0x38, an
     * empty-locals build gets 0x30). Reserved as a local so the prologue/epilogue offsets match. */
    s32 sp10[2];

    result = 0;
    switch ((u32)resLoad_state) {
    case 0:
        if (resLoad_curId == resLoad_lastId) {
            resLoad_result = 1;
            return;
        }
        if (RES_FILE[resLoad_curId].v == resLoad_loadedFileIdx && RES_POST[resLoad_curId].v != 0) {
            func_8002D4C8((u16)RES_POST[resLoad_curId].v, 0);
            resLoad_lastId = resLoad_curId;
            resLoad_result = 1;
            return;
        }
        if (CdQueueBusy() != 0) {
            break;
        }
        if (RES_FILE[resLoad_curId].v < 0) {
            ((void (*)())func_80036D58)(RES_ARG[resLoad_curId].v);
            resLoad_result = 1;
            return;
        }
        if (ResourceGetCdLoc((s16)resLoad_curId) == 0) {
            resLoad_result = 1;
            return;
        }
        if (cdReq_curSector != 0 && *(s32 *)(cdFileLocTable + RES_FILE[resLoad_curId].v * 8) != cdReq_curSector) {
            break;
        }
        cdReq_curSector = *(s32 *)(cdFileLocTable + RES_FILE[resLoad_curId].v * 8);
        resLoad_state++;
        /* fallthrough */
    case 1:
        result = StreamLoadStateMachine(RES_ARG[resLoad_curId].v,
                                        &cdFileLocTable[RES_FILE[resLoad_curId].v * 8], 0x10);
        if (result == 2) {
            resLoad_state++;
            result = 0;
        }
        break;
    case 2:
        D_800AE6F4 = 0;
        D_800AE70C = 0;
        resLoad_state = 3;
        /* fallthrough */
    case 3:
        if (func_8001A114() != 0) {
            resLoad_state = 0;
        }
        break;
    }
    if (result != 0) {
        resLoad_loadedFileIdx = RES_FILE[resLoad_curId].v;
        if (RES_POST[resLoad_curId].v > 0) {
            func_8002D4C8((u16)RES_POST[resLoad_curId].v, 0);
            resLoad_lastId = resLoad_curId;
            if (resLoad_curId == 0x3D) {
                func_8001B710();
            }
        }
        resLoad_state = 0;
        cdReq_curSector = 0;
    }
    resLoad_result = result;
}
