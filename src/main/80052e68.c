/* Main-exec range [80052E68,80052F04) from the SLUS executable.
 * SHA256(span)=c3c6f1d1cc4856e3104968241a85eb6eec78de061693c24a033afa71d2a5050a.
 * Word export for the native seam (m2c produced no draft). */
/* Sony PsyQ library routine (vendor/bfm-decomp keeps it as INCLUDE_ASM); C written from the retail disassembly. */
#include "psx_types.h"

/* func_80052E68 - byte-exact against retail at -O2 (tools/register_match.py). */

typedef struct { s16 m[3][3]; s32 t[3]; } MATRIX;
extern MATRIX D_800A63F0;
extern void func_8004867C(void);
extern void func_80048D9C(MATRIX *, MATRIX *);
extern void func_8004871C(void);
extern void func_8004917C(MATRIX *);
void func_80052E68(MATRIX *mp)
{
    MATRIX m;

    m = D_800A63F0;
    func_8004867C();
    func_80048D9C(&m, mp);
    func_8004871C();
    func_8004917C(&m);
}
