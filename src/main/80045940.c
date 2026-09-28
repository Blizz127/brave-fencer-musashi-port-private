/* Exact retail word export for [80045940,800459E8); EXE-verified. */
/* Source: PsyQ library C derived from parasite-eve-decomp (candidates/main/psyq/misc34.c), same PsyQ object; symbols renamed to this build's addresses. Matching build only. */
/* func_80045940 - byte-exact against retail at -O2 (tools/register_match.py). */
int func_8005C4DC(char *a, char *b);

extern int D_80076A04[];

extern char D_80076A0C[];

int func_80045940(int dev, char *name) {
    int saved_dev;
    register char *saved_name asm("$20");
    int i;
    int offset;
    register char *entry_name asm("$18");
    int value;
    saved_dev = dev;
    saved_name = name;
    i = 0;
    entry_name = D_80076A0C;
    offset = 0;
    do {
        value = *(int *)((char *)D_80076A04 + offset);

        if (value == 0) {
            return -1;
        }
        if (value == saved_dev) {
            if (func_8005C4DC(saved_name, entry_name) == 0) {
                return i + 1;
            }
            entry_name += 0x2C;
        } else {
            entry_name += 0x2C;
        }
        i++;
        offset += 0x2C;
    } while (i < 0x80);

    return -1;
}

int DS_cachefile(int index);
