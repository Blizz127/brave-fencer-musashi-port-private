/* Main-exec range [80052430,80052454) from the SLUS executable.
 * SHA256(span)=e7c83d5bccd6bc52a2f15133283c464864c5087e31234fa07c436e2946e8eac4.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Source: PsyQ library C derived from parasite-eve-decomp (src/main/psyq/libgte/mtx_07.c), same PsyQ object; symbols renamed to this build's addresses. Matching build only. */
/* func_80052430 - byte-exact against retail at -O2 (tools/register_match.py). */
typedef signed short s16;

typedef signed int s32;

typedef struct GteMatrix {
    s16 m[3][3];
    s32 t[3];
} GteMatrix;

GteMatrix *func_80052430(GteMatrix *matrix, const int *v) {
    register GteMatrix *m asm("$4") = matrix;
    register int x asm("$8") = v[0];
    register int y asm("$9") = v[1];
    register int z asm("$10") = v[2];
    GteMatrix *ret;
    m->t[0] = x;
    m->t[1] = y;
    m->t[2] = z;

    asm volatile("" : "=r"(m) : "0"(m), "m"(m->t[0]), "m"(m->t[1]), "m"(m->t[2]));
    ret = m;

    asm volatile("" : "=r"(ret) : "0"(ret));
    return ret;
}
