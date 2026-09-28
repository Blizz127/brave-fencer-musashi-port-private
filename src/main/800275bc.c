/* Main-exec range [800275BC,800277DC) from the SLUS executable.
 * SHA256(span)=137379b6ab869375f72ff1e129ed8645f09e80df96ceda25f1dba2524e782f1a.
 * Word export for the native seam; the body below is kept
 * byte-identical (wrap only, no rewrite). */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_800275BC - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

#define gte_ldv0(r0) __asm__ volatile (          \
    "lwc2 $0, 0( %0 );"                          \
    "lwc2 $1, 4( %0 )"                           \
    :: "r"(r0))
#define gte_ldv3(r0, r1, r2) __asm__ volatile (  \
    "lwc2 $0, 0( %0 );"                          \
    "lwc2 $1, 4( %0 );"                          \
    "lwc2 $2, 0( %1 );"                          \
    "lwc2 $3, 4( %1 );"                          \
    "lwc2 $4, 0( %2 );"                          \
    "lwc2 $5, 4( %2 )"                           \
    :: "r"(r0), "r"(r1), "r"(r2))
#define gte_rtps()  __asm__ volatile ("nop;nop;.word 0x4a180001")
#define gte_rtpt()  __asm__ volatile ("nop;nop;.word 0x4a280030")
#define gte_nclip() __asm__ volatile ("nop;nop;.word 0x4b400006")
#define gte_avsz4() __asm__ volatile ("nop;nop;.word 0x4b68002e")
#define gte_stflg(r0) __asm__ volatile (         \
    "cfc2 $12, $31;"                             \
    "nop;"                                       \
    "sw $12, 0( %0 )"                            \
    :: "r"(r0) : "$12", "memory")
#define gte_stsxy2(r0) __asm__ volatile (        \
    "swc2 $14, 0( %0 )"                          \
    :: "r"(r0) : "memory")
#define gte_stsxy3_g4(r0) __asm__ volatile (     \
    "swc2 $12, 8( %0 );"                         \
    "swc2 $13, 16( %0 );"                        \
    "swc2 $14, 24( %0 )"                         \
    :: "r"(r0) : "memory")
#define gte_stotz(r0) __asm__ volatile (         \
    "swc2 $7, 0( %0 )"                           \
    :: "r"(r0) : "memory")
#define gte_stopz(r0) __asm__ volatile (         \
    "swc2 $24, 0( %0 )"                          \
    :: "r"(r0) : "memory")
extern s32 D_800A2B78;
typedef struct {
    s16 vx, vy, vz, pad;
} SVEC_800275BC;
typedef struct {               /* TMD G4 flat-normal primitive, 0x20 bytes */
    u32 tag;                   /* 0x00 */
    u32 c0;                    /* 0x04 */
    u32 c1;                    /* 0x08 */
    u32 c2;                    /* 0x0C */
    u32 c3;                    /* 0x10 */
    u16 n0;                    /* 0x14 */
    u16 v0;                    /* 0x16 */
    u16 v1;                    /* 0x18 */
    u16 v2;                    /* 0x1A */
    u16 v3;                    /* 0x1C */
    u16 pad;                   /* 0x1E */
} TPRIM_800275BC;

void *func_800275BC(TPRIM_800275BC *prim, SVEC_800275BC *vp, void *nrm, u8 *pk, s32 n,
                    s32 shift, u32 *ot)
{
    s32 flag;
    s32 otz;
    u32 *op;

    if (n == 0) {
        return pk;
    }

    do {
        gte_ldv3(&vp[prim->v0], &vp[prim->v1], &vp[prim->v2]);
        gte_rtpt();
        gte_stflg(&flag);
        if ((flag & 0xFFFFEFFF) == 0) {
            gte_nclip();
            gte_stopz(&otz);
            if (otz > 0) {
                gte_stsxy3_g4(pk);
                gte_ldv0(&vp[prim->v3]);
                gte_rtps();
                gte_stflg(&flag);
                if ((flag & 0xFFFFEFFF) == 0) {
                    gte_stsxy2(pk + 0x20);
                    gte_avsz4();
                    gte_stotz(&otz);
                    *(u32 *)(pk + 0x04) = prim->c0;
                    *(u32 *)(pk + 0x0C) = prim->c1;
                    *(u32 *)(pk + 0x14) = prim->c2;
                    *(u32 *)(pk + 0x1C) = prim->c3;
                    *(u8 *)(pk + 7) = (*(u8 *)(pk + 7) & 2) | 0x38;
                    op = &ot[otz >> shift];
                    *(u32 *)pk = (*op & 0xFFFFFF) | 0x08000000;
                    *op = (u32)pk & 0xFFFFFF;
                    pk += 0x24;
                    if (D_800A2B78 != 0) {
                        if (*(u8 *)(pk - 0x1D) & 2) {
                            op = &ot[otz >> shift];
                            *(u8 *)(pk + 3) = 1;
                            *(u32 *)(pk + 4) =
                                ((D_800A2B78 & 3) << 5) | 0xE100000A;
                            *(u32 *)pk = (*op & 0xFFFFFF) | 0x01000000;
                            *op = (u32)pk & 0xFFFFFF;
                            pk += 8;
                        }
                    }
                }
            }
        }
        prim++;
    } while (--n != 0);
    return pk;
}
