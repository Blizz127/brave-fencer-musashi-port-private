/* Main-exec range [8005D0A0,8005D0D4) from the SLUS executable.
 * SHA256(span)=5bd7e39d766d33d5d022a06018938f7bbdd8be8a949541884f5a0a8cb15a6505.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Source: PsyQ library C derived from parasite-eve-decomp (src/main/psyq/libapi/counter.c), same PsyQ object; symbols renamed to this build's addresses. Matching build only. */
/* func_8005D0A0 - byte-exact against retail at -O2 (tools/register_match.py). */
typedef signed short s16;

typedef unsigned short u16;

typedef signed int s32;

typedef struct RootCounter {
    u16 rootCounter;
    s16 field_02;
    s16 mode;
    s16 field_06;
    s16 target;
    s16 field_0A;
    s32 field_0C;
} RootCounter;

extern RootCounter *D_80072938;

int func_8005D0A0(unsigned int counter) {
    int id;

    id = counter & 0xFFFF;
    if (id >= 3) {
        return 0;
    }
    D_80072938[id].rootCounter = 0;
    return 1;
}
