/* Exact retail word export for [800478B8,80047948); EXE and assembly verified. */
/* Source: PsyQ library C derived from parasite-eve-decomp (src/main/psyq/libgte/geo_00.c), same PsyQ object; symbols renamed to this build's addresses. Matching build only. */
/* func_800478B8 - byte-exact against retail at -O2 (tools/register_match.py). */
extern short D_8006C0A8[];

extern short D_8006D0A8[];

int func_800478B8(int angle) {
    int value;

    if (angle < 0x801) {
        if (angle < 0x401) {
            return D_8006D0A8[angle];
        }

        return D_8006D0A8[0x800 - angle];
    }

    if (angle < 0xC01) {
        value = D_8006C0A8[angle];
        return -value;
    }

    value = D_8006D0A8[0x1000 - angle];
    return -value;
}
