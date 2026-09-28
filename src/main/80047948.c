/* Exact retail word export for [80047948,800479E8); EXE and assembly verified. */
/* Source: PsyQ library C derived from parasite-eve-decomp (src/main/psyq/libgte/geo_01.c), same PsyQ object; symbols renamed to this build's addresses. Matching build only. */
/* func_80047948 - byte-exact against retail at -O2 (tools/register_match.py). */
extern short D_8006D0A8[], D_8006C8A8[], D_8006B8A8[];

int func_80047948(int angle) {
    int value;

    if (angle < 0) {
        angle = (int)(0U - (unsigned int)angle);
    }

    angle &= 0xFFF;
    if (angle < 0x801) {
        if (angle < 0x401) {
            return D_8006D0A8[0x400 - angle];
        }

        value = D_8006C8A8[angle];
        return -value;
    }

    if (angle < 0xC01) {
        value = D_8006D0A8[0xC00 - angle];
        return -value;
    }

    return D_8006B8A8[angle];
}
