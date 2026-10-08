/* Main-exec function func_800126C4 from the SLUS executable (clean room, owner).
 * m = m * Rx(angle) in place: the local X rotation matrix is built from
 * rsin/rcos and each of its columns goes through the GTE rotation matrix
 * (PsyQ gte_SetRotMatrix / gte_ldclmv / gte_rtir / gte_stclmv), then the
 * shared tail func_8001282C runs. */
#include "psx_types.h"

/* GTE command mnemonics (mvmva, rtpt, ...) come from include/gte_macros.inc. */
__asm__(".include \"gte_macros.inc\"\n");

extern s32 func_8004787C(s32 angle);
extern s32 func_80047948(s32 angle);
extern void func_8001282C(s32 m);

void func_800126C4(s32 m, s32 angle)
{
    s32 s;
    s32 c;
    s16 r[16];
    register s32 v1 __asm__("$3");

    s = func_8004787C(angle);
    c = func_80047948(angle);
    v1 = 0x1000;
    r[0] = v1;
    v1 = -s;
    r[1] = 0;
    r[2] = 0;
    r[3] = 0;
    r[4] = c;
    r[5] = v1;
    r[6] = 0;
    r[7] = s;
    r[8] = c;

    __asm__ __volatile__("lw $12, 0(%0)\n" "lw $13, 4(%0)\n" "ctc2 $12, $0\n" "ctc2 $13, $1\n"
                         "lw $12, 8(%0)\n" "lw $13, 12(%0)\n" "lw $14, 16(%0)\n"
                         "ctc2 $12, $2\n" "ctc2 $13, $3\n" "ctc2 $14, $4\n"
                         : : "r"(m) : "$12", "$13", "$14");
    {
        register s16 *col __asm__("$2") = &r[0];
        __asm__ __volatile__("lhu $12, 0(%0)\n" "lhu $13, 6(%0)\n" "lhu $14, 12(%0)\n"
                             "mtc2 $12, $9\n" "mtc2 $13, $10\n" "mtc2 $14, $11\n"
                             : : "r"(col) : "$12", "$13", "$14", "memory");
    }
    __asm__ __volatile__("nop\n" "nop\n" "mvmva 1, 0, 3, 3, 0\n");
    __asm__ __volatile__("mfc2 $12, $9\n" "mfc2 $13, $10\n" "mfc2 $14, $11\n"
                         "sh $12, 0(%0)\n" "sh $13, 6(%0)\n" "sh $14, 12(%0)\n"
                         : : "r"(m) : "$12", "$13", "$14", "memory");
    {
        register s16 *col __asm__("$2") = &r[1];
        __asm__ __volatile__("lhu $12, 0(%0)\n" "lhu $13, 6(%0)\n" "lhu $14, 12(%0)\n"
                             "mtc2 $12, $9\n" "mtc2 $13, $10\n" "mtc2 $14, $11\n"
                             : : "r"(col) : "$12", "$13", "$14", "memory");
    }
    __asm__ __volatile__("nop\n" "nop\n" "mvmva 1, 0, 3, 3, 0\n");
    {
        register s32 dst __asm__("$2") = m + 2;
        __asm__ __volatile__("mfc2 $12, $9\n" "mfc2 $13, $10\n" "mfc2 $14, $11\n"
                             "sh $12, 0(%0)\n" "sh $13, 6(%0)\n" "sh $14, 12(%0)\n"
                             : : "r"(dst) : "$12", "$13", "$14", "memory");
    }
    {
        register s16 *col __asm__("$2") = &r[2];
        __asm__ __volatile__("lhu $12, 0(%0)\n" "lhu $13, 6(%0)\n" "lhu $14, 12(%0)\n"
                             "mtc2 $12, $9\n" "mtc2 $13, $10\n" "mtc2 $14, $11\n"
                             : : "r"(col) : "$12", "$13", "$14", "memory");
    }
    __asm__ __volatile__("nop\n" "nop\n" "mvmva 1, 0, 3, 3, 0\n");
    {
        register s32 dst __asm__("$2") = m + 4;
        __asm__ __volatile__("mfc2 $12, $9\n" "mfc2 $13, $10\n" "mfc2 $14, $11\n"
                             "sh $12, 0(%0)\n" "sh $13, 6(%0)\n" "sh $14, 12(%0)\n"
                             : : "r"(dst) : "$12", "$13", "$14", "memory");
    }

    func_8001282C(m);
}
