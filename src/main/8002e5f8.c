/* Owner re-derivation from retail assembly (clean input set). */
#include "psx_types.h"

/* Sets the CD audio mix to straight stereo (left to left and right to right
 * at 128, no cross-feed) and raises the flag at D_800A4F19. */
typedef struct {
    u8 leftToLeft;
    u8 leftToRight;
    u8 rightToRight;
    u8 rightToLeft;
} Levels;

extern u8 D_800A4F19;
extern void func_80043974(Levels *levels);  /* CdMix */

void func_8002E5F8(void)
{
    Levels levels;

    levels.leftToLeft = 128;
    levels.leftToRight = 0;
    levels.rightToRight = 128;
    levels.rightToLeft = 0;
    func_80043974(&levels);
    D_800A4F19 = 1;
}
