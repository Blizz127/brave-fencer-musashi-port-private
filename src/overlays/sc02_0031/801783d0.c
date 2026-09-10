/* Complete SC02 numeric helper; independently matched ordinary C.
 * C shift domain: current bounded callers only; MIPS words retain masked shifts. */
unsigned int func_801783D0(int value, int shift)
{
    unsigned int packed = 0;
    int remaining = value;
    int position = 0;
    while (remaining >= 10) {
        value /= 10;
        packed |= (unsigned int)(remaining - ((value << 1) + (value << 3))) << position;
        remaining = value;
        position += 4;
    }
    packed |= (unsigned int)remaining << position;
    return packed << shift;
}
