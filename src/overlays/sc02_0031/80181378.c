/* Complete SC02 camera handler [80181378,801814E4). */
extern short D_80126940,D_80126942,D_80126944;
extern void func_801814E4(void *, void *);
void func_80181378(unsigned char *state)
{
    short vector[3];
    if (D_80126944 < 0x800) {
        if ((unsigned short)(D_80126940 + 0x2FF) < 0xFF) {
            *(short *)(state+0x1A) = *(short *)(state+0x22) = -0x200 - D_80126940 * 4;
        }
    }
    if (D_80126944 < 0x11A0) {
        if (D_80126940 < -0x4C0) vector[0] = -0x4C0;
        else if (D_80126940 > 0x2C0) vector[0] = 0x2C0;
        else vector[0] = D_80126940;
        vector[1] = D_80126942;
        vector[2] = D_80126944;
    } else {
        if (D_80126940 < -0x2C0) vector[0] = -0x2C0;
        else if (D_80126940 > 0x2C0) vector[0] = 0x2C0;
        else vector[0] = D_80126940;
        if (D_80126940 < -0x200) {
            if (D_80126944 > 0x13D0) vector[2] = 0x13D0;
            else vector[2] = D_80126944;
        } else vector[2] = D_80126944;
        vector[1] = D_80126942;
    }
    func_801814E4(state, vector);
}
