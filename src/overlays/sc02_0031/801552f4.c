/* SC02.CD member31 PAC0 decoded [801552F4,80155344). No C match claim. */
/* SC02 member31 [801552F4,80155344): normalize resource tags and set flags. */
extern unsigned int D_800DE2A4[];
void func_801552F4(unsigned char *object)
{
    unsigned int *entry = D_800DE2A4;
    while (*entry) {
        *entry &= 0x80FFFFFF;
        ++entry;
    }
    *(unsigned int *)(object + 0x44) |= 0x30000000;
}

