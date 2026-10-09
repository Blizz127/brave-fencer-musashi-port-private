/* Main-exec function func_8001382C from the SLUS executable (clean room, owner).
 * Rotates the vector `in` by Y(angle) into `out`: a local matrix is set up
 * by func_80013F3C, multiplied by Ry(angle) in place (rsin/rcos columns
 * through the GTE rotation matrix: PsyQ gte_SetRotMatrix / gte_ldclmv /
 * gte_rtir / gte_stclmv), finished by func_8001282C, and applied to `in`
 * by func_800484EC. */
#include "psx_types.h"

/* GTE command mnemonics (mvmva, rtpt, ...) come from include/gte_macros.inc. */
__asm__(".include \"gte_macros.inc\"\n");

extern s32 func_8004787C(s32 angle);
extern s32 func_80047948(s32 angle);
extern void func_8001282C(s32 m);
extern void func_80013F3C(s32 *m);
extern void func_800484EC(s32 m, s32 in, s32 out);

void func_8001382C(s16 angle, s32 in, s32 out)
{
    s32 mat[8];
    register s32 m __asm__("$16");
    s16 *col0;
    s32 s;
    s32 c;
    s16 r[16];
    register s32 v1 __asm__("$3");

    func_80013F3C(mat);
    s = func_8004787C(angle);
    c = func_80047948(angle);
    v1 = s;
    r[2] = v1;
    v1 = 0x1000;
    r[0] = c;
    r[8] = c;
    col0 = &r[0];
    r[6] = -s;
    m = (s32)mat;
    r[1] = 0;
    r[3] = 0;
    r[4] = v1;
    r[5] = 0;
    r[7] = 0;

    __asm__ __volatile__("lw $12, 0(%0)\n" "lw $13, 4(%0)\n" "ctc2 $12, $0\n" "ctc2 $13, $1\n"
                         "lw $12, 8(%0)\n" "lw $13, 12(%0)\n" "lw $14, 16(%0)\n"
                         "ctc2 $12, $2\n" "ctc2 $13, $3\n" "ctc2 $14, $4\n"
                         : : "r"(m) : "$12", "$13", "$14");
    __asm__ __volatile__("lhu $12, 0(%0)\n" "lhu $13, 6(%0)\n" "lhu $14, 12(%0)\n"
                         "mtc2 $12, $9\n" "mtc2 $13, $10\n" "mtc2 $14, $11\n"
                         : : "r"(col0) : "$12", "$13", "$14", "memory");
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
        register s32 dst __asm__("$2") = (s32)mat + 2;
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
        register s32 dst __asm__("$2") = (s32)mat + 4;
        __asm__ __volatile__("mfc2 $12, $9\n" "mfc2 $13, $10\n" "mfc2 $14, $11\n"
                             "sh $12, 0(%0)\n" "sh $13, 6(%0)\n" "sh $14, 12(%0)\n"
                             : : "r"(dst) : "$12", "$13", "$14", "memory");
    }

    func_8001282C(m);
    func_800484EC(m, in, out);
}
