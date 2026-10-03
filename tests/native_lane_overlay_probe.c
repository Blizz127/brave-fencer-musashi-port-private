/* Differential check of overlay entries in the native lane, plus the
 * residency guard's negative test.
 *
 * Guest RAM at host 0x80000000 holds the pinned retail EXE; the overlay
 * member's payload is copied from the user's own extracted member file to
 * its load address (arguments below; tests/test_native_lane_overlay.py reads
 * them from config/overlay_<member>.yaml). Every overlay entry of that
 * member is installed through a trampoline that records whether its native
 * body actually ran. For each entry:
 *
 *   positive (PATTERNS argument sets): interpreter-only run vs lane run from
 *     the same state; v0 and all guest RAM outside the callee frame must
 *     match, and the entry's native body must have run (the digest matched
 *     the resident bytes);
 *   negative: one byte inside the entry's extent is flipped in guest RAM;
 *     the lane run must NOT call the entry's native body (the resident bytes
 *     no longer hash to the member's digest), and must match the
 *     interpreter-only run of the same modified bytes when that is
 *     comparable.
 *
 * Ledger-mapped positive cases also run the D-011 cycle oracle and the
 * deadline guard (the overlay counterpart of native_lane_guard_probe: IRQs
 * due mid-body are delivered at the interpreter's retail pc and cycle).
 *
 * OVERLAY_PROBE_FOREIGN=1: MEMBER_FILE and its mapping belong to a different
 * member loaded at the same address (e.g. main_0001 in main_0003's window).
 * Every case is then negative: the native body must never run, because the
 * resident bytes are not the member's own.
 *
 * A case whose interpreter run refuses (device, BIOS, wild pointer) proves
 * nothing and is counted not_comparable. Exit 0 when nothing differs, no
 * positive case failed to run natively where comparable, and every negative
 * case stayed off the native body; 77 without the EXE, the member file or
 * the host window. Synthetic arguments only. */
#define _GNU_SOURCE
#include "musashi_boot_memory.h"
#include "musashi_cpu_status.h"
#include "musashi_native_lane.h"
#include "musashi_native_lane_psyq.h"

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <sys/wait.h>
#include <unistd.h>

#ifndef MAP_FIXED_NOREPLACE
#define MAP_FIXED_NOREPLACE 0x100000
#endif

extern const MusashiNativeLaneEntry musashi_native_lane_generated[];
extern const size_t musashi_native_lane_generated_count;
extern const MusashiNativeLaneOverlayEntry musashi_native_lane_overlay[];
extern const size_t musashi_native_lane_overlay_count;
extern const MusashiNativeLaneGuestLocal musashi_native_lane_guest_locals[];
extern const size_t musashi_native_lane_guest_locals_count;

enum { ARENA = 0x80180000u, ARENA_SIZE = 0x40000u, STACK_TOP = 0x801fe000u,
       FRAME_GUARD = 0x10000u, PATTERNS = 3, MAX_ENTRIES = 160 };
enum Outcome { SAME, DIFFERENT, NOT_NATIVE, NOT_COMPARABLE, NEG_OK, NEG_RAN_NATIVE, MIRROR_FAULT,
               WRAP_FAULT, FAULT, OUTCOMES };

/* ---- trampolines: which overlay entries' native bodies ran ------------- */
static MusashiNativeLaneFn g_orig[MAX_ENTRIES];
static int g_foreign;
static volatile unsigned g_ran[MAX_ENTRIES];
/* One trampoline per installed entry (generated list). */
static int tramp_0(MusashiNativeLaneCall *c) { g_ran[0]++; return g_orig[0](c); }
static int tramp_1(MusashiNativeLaneCall *c) { g_ran[1]++; return g_orig[1](c); }
static int tramp_2(MusashiNativeLaneCall *c) { g_ran[2]++; return g_orig[2](c); }
static int tramp_3(MusashiNativeLaneCall *c) { g_ran[3]++; return g_orig[3](c); }
static int tramp_4(MusashiNativeLaneCall *c) { g_ran[4]++; return g_orig[4](c); }
static int tramp_5(MusashiNativeLaneCall *c) { g_ran[5]++; return g_orig[5](c); }
static int tramp_6(MusashiNativeLaneCall *c) { g_ran[6]++; return g_orig[6](c); }
static int tramp_7(MusashiNativeLaneCall *c) { g_ran[7]++; return g_orig[7](c); }
static int tramp_8(MusashiNativeLaneCall *c) { g_ran[8]++; return g_orig[8](c); }
static int tramp_9(MusashiNativeLaneCall *c) { g_ran[9]++; return g_orig[9](c); }
static int tramp_10(MusashiNativeLaneCall *c) { g_ran[10]++; return g_orig[10](c); }
static int tramp_11(MusashiNativeLaneCall *c) { g_ran[11]++; return g_orig[11](c); }
static int tramp_12(MusashiNativeLaneCall *c) { g_ran[12]++; return g_orig[12](c); }
static int tramp_13(MusashiNativeLaneCall *c) { g_ran[13]++; return g_orig[13](c); }
static int tramp_14(MusashiNativeLaneCall *c) { g_ran[14]++; return g_orig[14](c); }
static int tramp_15(MusashiNativeLaneCall *c) { g_ran[15]++; return g_orig[15](c); }
static int tramp_16(MusashiNativeLaneCall *c) { g_ran[16]++; return g_orig[16](c); }
static int tramp_17(MusashiNativeLaneCall *c) { g_ran[17]++; return g_orig[17](c); }
static int tramp_18(MusashiNativeLaneCall *c) { g_ran[18]++; return g_orig[18](c); }
static int tramp_19(MusashiNativeLaneCall *c) { g_ran[19]++; return g_orig[19](c); }
static int tramp_20(MusashiNativeLaneCall *c) { g_ran[20]++; return g_orig[20](c); }
static int tramp_21(MusashiNativeLaneCall *c) { g_ran[21]++; return g_orig[21](c); }
static int tramp_22(MusashiNativeLaneCall *c) { g_ran[22]++; return g_orig[22](c); }
static int tramp_23(MusashiNativeLaneCall *c) { g_ran[23]++; return g_orig[23](c); }
static int tramp_24(MusashiNativeLaneCall *c) { g_ran[24]++; return g_orig[24](c); }
static int tramp_25(MusashiNativeLaneCall *c) { g_ran[25]++; return g_orig[25](c); }
static int tramp_26(MusashiNativeLaneCall *c) { g_ran[26]++; return g_orig[26](c); }
static int tramp_27(MusashiNativeLaneCall *c) { g_ran[27]++; return g_orig[27](c); }
static int tramp_28(MusashiNativeLaneCall *c) { g_ran[28]++; return g_orig[28](c); }
static int tramp_29(MusashiNativeLaneCall *c) { g_ran[29]++; return g_orig[29](c); }
static int tramp_30(MusashiNativeLaneCall *c) { g_ran[30]++; return g_orig[30](c); }
static int tramp_31(MusashiNativeLaneCall *c) { g_ran[31]++; return g_orig[31](c); }
static int tramp_32(MusashiNativeLaneCall *c) { g_ran[32]++; return g_orig[32](c); }
static int tramp_33(MusashiNativeLaneCall *c) { g_ran[33]++; return g_orig[33](c); }
static int tramp_34(MusashiNativeLaneCall *c) { g_ran[34]++; return g_orig[34](c); }
static int tramp_35(MusashiNativeLaneCall *c) { g_ran[35]++; return g_orig[35](c); }
static int tramp_36(MusashiNativeLaneCall *c) { g_ran[36]++; return g_orig[36](c); }
static int tramp_37(MusashiNativeLaneCall *c) { g_ran[37]++; return g_orig[37](c); }
static int tramp_38(MusashiNativeLaneCall *c) { g_ran[38]++; return g_orig[38](c); }
static int tramp_39(MusashiNativeLaneCall *c) { g_ran[39]++; return g_orig[39](c); }
static int tramp_40(MusashiNativeLaneCall *c) { g_ran[40]++; return g_orig[40](c); }
static int tramp_41(MusashiNativeLaneCall *c) { g_ran[41]++; return g_orig[41](c); }
static int tramp_42(MusashiNativeLaneCall *c) { g_ran[42]++; return g_orig[42](c); }
static int tramp_43(MusashiNativeLaneCall *c) { g_ran[43]++; return g_orig[43](c); }
static int tramp_44(MusashiNativeLaneCall *c) { g_ran[44]++; return g_orig[44](c); }
static int tramp_45(MusashiNativeLaneCall *c) { g_ran[45]++; return g_orig[45](c); }
static int tramp_46(MusashiNativeLaneCall *c) { g_ran[46]++; return g_orig[46](c); }
static int tramp_47(MusashiNativeLaneCall *c) { g_ran[47]++; return g_orig[47](c); }
static int tramp_48(MusashiNativeLaneCall *c) { g_ran[48]++; return g_orig[48](c); }
static int tramp_49(MusashiNativeLaneCall *c) { g_ran[49]++; return g_orig[49](c); }
static int tramp_50(MusashiNativeLaneCall *c) { g_ran[50]++; return g_orig[50](c); }
static int tramp_51(MusashiNativeLaneCall *c) { g_ran[51]++; return g_orig[51](c); }
static int tramp_52(MusashiNativeLaneCall *c) { g_ran[52]++; return g_orig[52](c); }
static int tramp_53(MusashiNativeLaneCall *c) { g_ran[53]++; return g_orig[53](c); }
static int tramp_54(MusashiNativeLaneCall *c) { g_ran[54]++; return g_orig[54](c); }
static int tramp_55(MusashiNativeLaneCall *c) { g_ran[55]++; return g_orig[55](c); }
static int tramp_56(MusashiNativeLaneCall *c) { g_ran[56]++; return g_orig[56](c); }
static int tramp_57(MusashiNativeLaneCall *c) { g_ran[57]++; return g_orig[57](c); }
static int tramp_58(MusashiNativeLaneCall *c) { g_ran[58]++; return g_orig[58](c); }
static int tramp_59(MusashiNativeLaneCall *c) { g_ran[59]++; return g_orig[59](c); }
static int tramp_60(MusashiNativeLaneCall *c) { g_ran[60]++; return g_orig[60](c); }
static int tramp_61(MusashiNativeLaneCall *c) { g_ran[61]++; return g_orig[61](c); }
static int tramp_62(MusashiNativeLaneCall *c) { g_ran[62]++; return g_orig[62](c); }
static int tramp_63(MusashiNativeLaneCall *c) { g_ran[63]++; return g_orig[63](c); }
static int tramp_64(MusashiNativeLaneCall *c) { g_ran[64]++; return g_orig[64](c); }
static int tramp_65(MusashiNativeLaneCall *c) { g_ran[65]++; return g_orig[65](c); }
static int tramp_66(MusashiNativeLaneCall *c) { g_ran[66]++; return g_orig[66](c); }
static int tramp_67(MusashiNativeLaneCall *c) { g_ran[67]++; return g_orig[67](c); }
static int tramp_68(MusashiNativeLaneCall *c) { g_ran[68]++; return g_orig[68](c); }
static int tramp_69(MusashiNativeLaneCall *c) { g_ran[69]++; return g_orig[69](c); }
static int tramp_70(MusashiNativeLaneCall *c) { g_ran[70]++; return g_orig[70](c); }
static int tramp_71(MusashiNativeLaneCall *c) { g_ran[71]++; return g_orig[71](c); }
static int tramp_72(MusashiNativeLaneCall *c) { g_ran[72]++; return g_orig[72](c); }
static int tramp_73(MusashiNativeLaneCall *c) { g_ran[73]++; return g_orig[73](c); }
static int tramp_74(MusashiNativeLaneCall *c) { g_ran[74]++; return g_orig[74](c); }
static int tramp_75(MusashiNativeLaneCall *c) { g_ran[75]++; return g_orig[75](c); }
static int tramp_76(MusashiNativeLaneCall *c) { g_ran[76]++; return g_orig[76](c); }
static int tramp_77(MusashiNativeLaneCall *c) { g_ran[77]++; return g_orig[77](c); }
static int tramp_78(MusashiNativeLaneCall *c) { g_ran[78]++; return g_orig[78](c); }
static int tramp_79(MusashiNativeLaneCall *c) { g_ran[79]++; return g_orig[79](c); }
static int tramp_80(MusashiNativeLaneCall *c) { g_ran[80]++; return g_orig[80](c); }
static int tramp_81(MusashiNativeLaneCall *c) { g_ran[81]++; return g_orig[81](c); }
static int tramp_82(MusashiNativeLaneCall *c) { g_ran[82]++; return g_orig[82](c); }
static int tramp_83(MusashiNativeLaneCall *c) { g_ran[83]++; return g_orig[83](c); }
static int tramp_84(MusashiNativeLaneCall *c) { g_ran[84]++; return g_orig[84](c); }
static int tramp_85(MusashiNativeLaneCall *c) { g_ran[85]++; return g_orig[85](c); }
static int tramp_86(MusashiNativeLaneCall *c) { g_ran[86]++; return g_orig[86](c); }
static int tramp_87(MusashiNativeLaneCall *c) { g_ran[87]++; return g_orig[87](c); }
static int tramp_88(MusashiNativeLaneCall *c) { g_ran[88]++; return g_orig[88](c); }
static int tramp_89(MusashiNativeLaneCall *c) { g_ran[89]++; return g_orig[89](c); }
static int tramp_90(MusashiNativeLaneCall *c) { g_ran[90]++; return g_orig[90](c); }
static int tramp_91(MusashiNativeLaneCall *c) { g_ran[91]++; return g_orig[91](c); }
static int tramp_92(MusashiNativeLaneCall *c) { g_ran[92]++; return g_orig[92](c); }
static int tramp_93(MusashiNativeLaneCall *c) { g_ran[93]++; return g_orig[93](c); }
static int tramp_94(MusashiNativeLaneCall *c) { g_ran[94]++; return g_orig[94](c); }
static int tramp_95(MusashiNativeLaneCall *c) { g_ran[95]++; return g_orig[95](c); }
static int tramp_96(MusashiNativeLaneCall *c) { g_ran[96]++; return g_orig[96](c); }
static int tramp_97(MusashiNativeLaneCall *c) { g_ran[97]++; return g_orig[97](c); }
static int tramp_98(MusashiNativeLaneCall *c) { g_ran[98]++; return g_orig[98](c); }
static int tramp_99(MusashiNativeLaneCall *c) { g_ran[99]++; return g_orig[99](c); }
static int tramp_100(MusashiNativeLaneCall *c) { g_ran[100]++; return g_orig[100](c); }
static int tramp_101(MusashiNativeLaneCall *c) { g_ran[101]++; return g_orig[101](c); }
static int tramp_102(MusashiNativeLaneCall *c) { g_ran[102]++; return g_orig[102](c); }
static int tramp_103(MusashiNativeLaneCall *c) { g_ran[103]++; return g_orig[103](c); }
static int tramp_104(MusashiNativeLaneCall *c) { g_ran[104]++; return g_orig[104](c); }
static int tramp_105(MusashiNativeLaneCall *c) { g_ran[105]++; return g_orig[105](c); }
static int tramp_106(MusashiNativeLaneCall *c) { g_ran[106]++; return g_orig[106](c); }
static int tramp_107(MusashiNativeLaneCall *c) { g_ran[107]++; return g_orig[107](c); }
static int tramp_108(MusashiNativeLaneCall *c) { g_ran[108]++; return g_orig[108](c); }
static int tramp_109(MusashiNativeLaneCall *c) { g_ran[109]++; return g_orig[109](c); }
static int tramp_110(MusashiNativeLaneCall *c) { g_ran[110]++; return g_orig[110](c); }
static int tramp_111(MusashiNativeLaneCall *c) { g_ran[111]++; return g_orig[111](c); }
static int tramp_112(MusashiNativeLaneCall *c) { g_ran[112]++; return g_orig[112](c); }
static int tramp_113(MusashiNativeLaneCall *c) { g_ran[113]++; return g_orig[113](c); }
static int tramp_114(MusashiNativeLaneCall *c) { g_ran[114]++; return g_orig[114](c); }
static int tramp_115(MusashiNativeLaneCall *c) { g_ran[115]++; return g_orig[115](c); }
static int tramp_116(MusashiNativeLaneCall *c) { g_ran[116]++; return g_orig[116](c); }
static int tramp_117(MusashiNativeLaneCall *c) { g_ran[117]++; return g_orig[117](c); }
static int tramp_118(MusashiNativeLaneCall *c) { g_ran[118]++; return g_orig[118](c); }
static int tramp_119(MusashiNativeLaneCall *c) { g_ran[119]++; return g_orig[119](c); }
static int tramp_120(MusashiNativeLaneCall *c) { g_ran[120]++; return g_orig[120](c); }
static int tramp_121(MusashiNativeLaneCall *c) { g_ran[121]++; return g_orig[121](c); }
static int tramp_122(MusashiNativeLaneCall *c) { g_ran[122]++; return g_orig[122](c); }
static int tramp_123(MusashiNativeLaneCall *c) { g_ran[123]++; return g_orig[123](c); }
static int tramp_124(MusashiNativeLaneCall *c) { g_ran[124]++; return g_orig[124](c); }
static int tramp_125(MusashiNativeLaneCall *c) { g_ran[125]++; return g_orig[125](c); }
static int tramp_126(MusashiNativeLaneCall *c) { g_ran[126]++; return g_orig[126](c); }
static int tramp_127(MusashiNativeLaneCall *c) { g_ran[127]++; return g_orig[127](c); }
static int tramp_128(MusashiNativeLaneCall *c) { g_ran[128]++; return g_orig[128](c); }
static int tramp_129(MusashiNativeLaneCall *c) { g_ran[129]++; return g_orig[129](c); }
static int tramp_130(MusashiNativeLaneCall *c) { g_ran[130]++; return g_orig[130](c); }
static int tramp_131(MusashiNativeLaneCall *c) { g_ran[131]++; return g_orig[131](c); }
static int tramp_132(MusashiNativeLaneCall *c) { g_ran[132]++; return g_orig[132](c); }
static int tramp_133(MusashiNativeLaneCall *c) { g_ran[133]++; return g_orig[133](c); }
static int tramp_134(MusashiNativeLaneCall *c) { g_ran[134]++; return g_orig[134](c); }
static int tramp_135(MusashiNativeLaneCall *c) { g_ran[135]++; return g_orig[135](c); }
static int tramp_136(MusashiNativeLaneCall *c) { g_ran[136]++; return g_orig[136](c); }
static int tramp_137(MusashiNativeLaneCall *c) { g_ran[137]++; return g_orig[137](c); }
static int tramp_138(MusashiNativeLaneCall *c) { g_ran[138]++; return g_orig[138](c); }
static int tramp_139(MusashiNativeLaneCall *c) { g_ran[139]++; return g_orig[139](c); }
static int tramp_140(MusashiNativeLaneCall *c) { g_ran[140]++; return g_orig[140](c); }
static int tramp_141(MusashiNativeLaneCall *c) { g_ran[141]++; return g_orig[141](c); }
static int tramp_142(MusashiNativeLaneCall *c) { g_ran[142]++; return g_orig[142](c); }
static int tramp_143(MusashiNativeLaneCall *c) { g_ran[143]++; return g_orig[143](c); }
static int tramp_144(MusashiNativeLaneCall *c) { g_ran[144]++; return g_orig[144](c); }
static int tramp_145(MusashiNativeLaneCall *c) { g_ran[145]++; return g_orig[145](c); }
static int tramp_146(MusashiNativeLaneCall *c) { g_ran[146]++; return g_orig[146](c); }
static int tramp_147(MusashiNativeLaneCall *c) { g_ran[147]++; return g_orig[147](c); }
static int tramp_148(MusashiNativeLaneCall *c) { g_ran[148]++; return g_orig[148](c); }
static int tramp_149(MusashiNativeLaneCall *c) { g_ran[149]++; return g_orig[149](c); }
static int tramp_150(MusashiNativeLaneCall *c) { g_ran[150]++; return g_orig[150](c); }
static int tramp_151(MusashiNativeLaneCall *c) { g_ran[151]++; return g_orig[151](c); }
static int tramp_152(MusashiNativeLaneCall *c) { g_ran[152]++; return g_orig[152](c); }
static int tramp_153(MusashiNativeLaneCall *c) { g_ran[153]++; return g_orig[153](c); }
static int tramp_154(MusashiNativeLaneCall *c) { g_ran[154]++; return g_orig[154](c); }
static int tramp_155(MusashiNativeLaneCall *c) { g_ran[155]++; return g_orig[155](c); }
static int tramp_156(MusashiNativeLaneCall *c) { g_ran[156]++; return g_orig[156](c); }
static int tramp_157(MusashiNativeLaneCall *c) { g_ran[157]++; return g_orig[157](c); }
static int tramp_158(MusashiNativeLaneCall *c) { g_ran[158]++; return g_orig[158](c); }
static int tramp_159(MusashiNativeLaneCall *c) { g_ran[159]++; return g_orig[159](c); }
static const MusashiNativeLaneFn kTramp[MAX_ENTRIES] = {
    tramp_0,
    tramp_1,
    tramp_2,
    tramp_3,
    tramp_4,
    tramp_5,
    tramp_6,
    tramp_7,
    tramp_8,
    tramp_9,
    tramp_10,
    tramp_11,
    tramp_12,
    tramp_13,
    tramp_14,
    tramp_15,
    tramp_16,
    tramp_17,
    tramp_18,
    tramp_19,
    tramp_20,
    tramp_21,
    tramp_22,
    tramp_23,
    tramp_24,
    tramp_25,
    tramp_26,
    tramp_27,
    tramp_28,
    tramp_29,
    tramp_30,
    tramp_31,
    tramp_32,
    tramp_33,
    tramp_34,
    tramp_35,
    tramp_36,
    tramp_37,
    tramp_38,
    tramp_39,
    tramp_40,
    tramp_41,
    tramp_42,
    tramp_43,
    tramp_44,
    tramp_45,
    tramp_46,
    tramp_47,
    tramp_48,
    tramp_49,
    tramp_50,
    tramp_51,
    tramp_52,
    tramp_53,
    tramp_54,
    tramp_55,
    tramp_56,
    tramp_57,
    tramp_58,
    tramp_59,
    tramp_60,
    tramp_61,
    tramp_62,
    tramp_63,
    tramp_64,
    tramp_65,
    tramp_66,
    tramp_67,
    tramp_68,
    tramp_69,
    tramp_70,
    tramp_71,
    tramp_72,
    tramp_73,
    tramp_74,
    tramp_75,
    tramp_76,
    tramp_77,
    tramp_78,
    tramp_79,
    tramp_80,
    tramp_81,
    tramp_82,
    tramp_83,
    tramp_84,
    tramp_85,
    tramp_86,
    tramp_87,
    tramp_88,
    tramp_89,
    tramp_90,
    tramp_91,
    tramp_92,
    tramp_93,
    tramp_94,
    tramp_95,
    tramp_96,
    tramp_97,
    tramp_98,
    tramp_99,
    tramp_100,
    tramp_101,
    tramp_102,
    tramp_103,
    tramp_104,
    tramp_105,
    tramp_106,
    tramp_107,
    tramp_108,
    tramp_109,
    tramp_110,
    tramp_111,
    tramp_112,
    tramp_113,
    tramp_114,
    tramp_115,
    tramp_116,
    tramp_117,
    tramp_118,
    tramp_119,
    tramp_120,
    tramp_121,
    tramp_122,
    tramp_123,
    tramp_124,
    tramp_125,
    tramp_126,
    tramp_127,
    tramp_128,
    tramp_129,
    tramp_130,
    tramp_131,
    tramp_132,
    tramp_133,
    tramp_134,
    tramp_135,
    tramp_136,
    tramp_137,
    tramp_138,
    tramp_139,
    tramp_140,
    tramp_141,
    tramp_142,
    tramp_143,
    tramp_144,
    tramp_145,
    tramp_146,
    tramp_147,
    tramp_148,
    tramp_149,
    tramp_150,
    tramp_151,
    tramp_152,
    tramp_153,
    tramp_154,
    tramp_155,
    tramp_156,
    tramp_157,
    tramp_158,
    tramp_159,
};

/* The case the forked child is running, for the fault handler. */
static size_t g_case_idx;
static int g_case_negative, g_case_lane;

/* A host fault during the lane run at a RAM-mirror address (low KUSEG, the
 * mirrors above the 2 MB window, KSEG1) or past 32 bits is the main probe's
 * documented model gap (tests/native_lane_probe.c): the interpreter decodes
 * the mirrors and wraps guest arithmetic, the host window does not. A native
 * callee reading through a null guest pointer (e.g. obj->model == 0 in the
 * synthetic state) reaches it. In a negative case the verdict is whether the
 * entry under test ran natively, not whether something faulted. Any other
 * fault, or a fault in the interpreter-only run, is a real failure. */
static void on_fault(int sig, siginfo_t *info, void *context) {
    uint64_t address = (uint64_t)(uintptr_t)info->si_addr;
    int gap = address < 0x00800000u || (address >= 0x80200000u && address < 0x80800000u) ||
              (address >= 0xa0000000u && address < 0xa0800000u);
    int wrap = address >= 0x100000000ull;
    (void)sig; (void)context;
    if (!g_case_lane || (!gap && !wrap)) {
        fprintf(stderr, "overlay_lane: fault address %llx (%s run)\n", (unsigned long long)address,
                g_case_lane ? "lane" : "interpreter-only");
        _exit(FAULT);
    }
    if (g_case_negative) _exit(g_ran[g_case_idx] ? NEG_RAN_NATIVE : NEG_OK);
    _exit(gap ? MIRROR_FAULT : WRAP_FAULT);
}

static uint32_t rng_state = 0x1234567u;
static uint32_t rng(void) {
    rng_state ^= rng_state << 13;
    rng_state ^= rng_state >> 17;
    rng_state ^= rng_state << 5;
    return rng_state;
}

static void seed_arena(MusashiBootMemory *memory, uint32_t seed) {
    uint32_t a;
    rng_state = seed | 1u;
    for (a = ARENA; a < ARENA + ARENA_SIZE; a += 4u)
        musashi_boot_write32(memory, a, ARENA + (rng() % (ARENA_SIZE - 0x1000u) & ~3u));
}

static void make_args(unsigned pattern, uint32_t *args) {
    unsigned i;
    for (i = 0; i < 8; ++i) {
        if (pattern == 0) args[i] = ARENA + 0x1000u * (i + 1u);
        else if (pattern == 1) args[i] = rng() % 8u;
        else if (pattern > PATTERNS) args[i] = ARENA + ((rng() % (ARENA_SIZE - 0x2000u)) & ~3u);
        else args[i] = (i & 1u) ? rng() % 4u : ARENA + 0x800u * (i + 3u);
    }
}

/* 1 when guest address a is a guest-frame local of the overlay entry
 * (member, pc) called with sp = STACK_TOP: compared although it sits in the
 * skipped frame band (the native body keeps it where retail does). */
static int guest_local_byte(const char *member, uint32_t pc, uint32_t a) {
    size_t k;
    for (k = 0; k < musashi_native_lane_guest_locals_count; ++k) {
        const MusashiNativeLaneGuestLocal *g = &musashi_native_lane_guest_locals[k];
        uint32_t lo = STACK_TOP - g->frame + g->off;
        if (g->guest_pc == pc && g->member && member && !strcmp(g->member, member) && g->size &&
            a >= lo && a < lo + g->size)
            return 1;
    }
    return 0;
}

enum { GL_EXTRA = 64 };
static int has_guest_locals(const MusashiNativeLaneOverlayEntry *e) {
    size_t k;
    for (k = 0; k < musashi_native_lane_guest_locals_count; ++k)
        if (musashi_native_lane_guest_locals[k].guest_pc == e->entry.guest_pc &&
            musashi_native_lane_guest_locals[k].member && e->member &&
            !strcmp(musashi_native_lane_guest_locals[k].member, e->member))
            return 1;
    return 0;
}


/* ---- entry-specific seeded patterns: main_0012 80161A90 ----------------
 * func_80161A90(obj): obj->timer (s16 @+0x1C8) counts down while the mode
 * byte (D_80078E78+0x48 == D_80078EC0, low 7 bits) is 6; at mode 6 with the
 * timer at 0 it calls func_8014AC10(0x3B) (guest call, not a lane entry).
 * Patterns above PATTERNS: the first 42 are every timer x mode combination
 * of the brief, the rest are pseudo-random (own LCG, a pure function of the
 * pattern so the parent can classify without running the case). */
enum { T80161A90 = 0x80161a90u, MODE_ADDR = 0x80078ec0u, TIMER_OFF = 0x1c8u, REC_BASE = 0x8011d030u,
       REC_STRIDE = 0x58u, REC_COUNT = 30u, T_EXTRA = 42 + 240 };
typedef struct { uint16_t timer; uint8_t mode; int plant; unsigned cls; } T161Seed;
enum { K_T0_M6, K_T0_OTHER, K_TN_M6_TO0, K_TN_M6_STAY, K_TN_OTHER, K_CLASSES };
static const char *const k_names[K_CLASSES] = {"timer0+mode6(call,no dec)", "timer0+other mode(none)",
    "timer!=0+mode6->0(dec+call)", "timer!=0+mode6->!0(dec only)", "timer!=0+other mode(none)"};
static unsigned k_same[K_CLASSES], k_total[K_CLASSES], k_cyc_same[K_CLASSES], k_planted_same;
static uint32_t lcg_(uint32_t *s) { *s = *s * 1664525u + 1013904223u; return *s >> 8; }
static T161Seed t161_seed(unsigned pattern) {
    static const uint16_t timers[6] = {0, 1, 2, 0x7fff, 0xffff, 0};
    static const uint8_t modes[7] = {6, 0x86, 0, 5, 7, 0x7f, 0};
    unsigned k = pattern - PATTERNS - 1u;
    uint32_t s = 0xc0ffee11u ^ (pattern * 0x9e3779b9u);
    T161Seed r;
    if (k < 42u) {
        r.timer = timers[k / 7u];
        r.mode = modes[k % 7u];
        if (k / 7u == 5u) r.timer = (uint16_t)lcg_(&s);
        if (k % 7u == 6u) r.mode = (uint8_t)lcg_(&s);
    } else {
        uint32_t a = lcg_(&s);
        r.timer = (a & 3u) == 0u ? (uint16_t)lcg_(&s) : (uint16_t)(lcg_(&s) % 4u);
        r.mode = (lcg_(&s) & 1u) ? (uint8_t)(6u | (lcg_(&s) & 0x80u)) : (uint8_t)lcg_(&s);
    }
    r.plant = (int)(lcg_(&s) & 1u);
    if ((r.mode & 0x7fu) == 6u) r.cls = r.timer == 0u ? K_T0_M6 : r.timer == 1u ? K_TN_M6_TO0 : K_TN_M6_STAY;
    else r.cls = r.timer == 0u ? K_T0_OTHER : K_TN_OTHER;
    return r;
}
static int is_t161(const MusashiNativeLaneOverlayEntry *e) {
    return e->entry.guest_pc == T80161A90 && e->member && !strcmp(e->member, "main_0012");
}
/* After seed_arena + make_args: put obj at args[0], set its timer, the mode
 * byte, and (half the cases) a matching 0x3B record in the table
 * func_8014AC10 scans so the callee does real work when it is reached. */
static void t161_apply(MusashiBootMemory *memory, unsigned pattern, uint32_t *args) {
    T161Seed r = t161_seed(pattern);
    uint32_t obj = args[0] & ~3u;
    args[0] = obj;
    musashi_boot_write16(memory, obj + TIMER_OFF, r.timer);
    memory->bytes[MODE_ADDR & 0x1fffffu] = r.mode;
    if (r.plant) {
        uint32_t rec = REC_BASE + REC_STRIDE * (uint32_t)(pattern % REC_COUNT);
        musashi_boot_write16(memory, rec, 0x3bu);
        musashi_boot_write32(memory, rec + 0x20u, pattern & 2u ? 0u : obj + 0x800u);
    }
}
static unsigned extra_patterns(const MusashiNativeLaneOverlayEntry *e) {
    if (g_foreign) return 0u;
    if (is_t161(e)) return T_EXTRA;
    return has_guest_locals(e) ? GL_EXTRA : 0u;
}

static int ram_differs(const MusashiBootMemory *memory, const uint8_t *reference,
                       const MusashiNativeLaneOverlayEntry *e, const char *what) {
    const uint32_t lo = STACK_TOP - FRAME_GUARD - 0x80000000u;
    const uint32_t hi = STACK_TOP + 0x10u + 4u * 8u - 0x80000000u;
    const char *name = e->entry.name;
    uint32_t i;
    for (i = 0; i < MUSASHI_RAM_SIZE; ++i) {
        if (i >= lo && i < hi && !guest_local_byte(e->member, e->entry.guest_pc, 0x80000000u + i))
            continue;
        if (memory->bytes[i] != reference[i]) {
            fprintf(stderr, "overlay_lane: %s %s RAM %08x interp=%02x native=%02x\n",
                    name, what, 0x80000000u + i, reference[i], memory->bytes[i]);
            return 1;
        }
    }
    return 0;
}

/* pattern != PATTERNS: positive case (above PATTERNS: the extra seeded
 * patterns of an entry with guest-frame locals); pattern == PATTERNS:
 * negative case. */
static int run_case(MusashiBootMemory *memory, const uint8_t *image, size_t idx,
                    const MusashiNativeLaneOverlayEntry *e, unsigned pattern, uint8_t *reference,
                    uint8_t *start) {
    uint32_t args[8], ref_v0 = 0, lane_v0 = 0;
    unsigned argc = e->entry.argc > 8u ? 8u : e->entry.argc;
    int ok, negative = pattern == PATTERNS || g_foreign;
    memcpy(memory->bytes, image, MUSASHI_RAM_SIZE);
    seed_arena(memory, e->entry.guest_pc ^ (pattern * 0x9e3779b9u));
    make_args(negative ? 0u : pattern, args);
    if (!negative && pattern > PATTERNS && is_t161(e)) t161_apply(memory, pattern, args);
    if (pattern == PATTERNS) {
        /* flip one byte in the middle of the extent (not the first word, so
         * the entry PC still decodes the same prologue) */
        uint32_t at = e->entry.guest_pc + (e->size > 8u ? e->size / 2u : e->size - 1u);
        memory->bytes[(at & 0x1fffffu)] ^= 0x01u;
    }
    memcpy(start, memory->bytes, MUSASHI_RAM_SIZE);
    g_case_idx = idx;
    g_case_negative = negative;
    g_case_lane = 0;
    alarm(5);
    ok = musashi_native_lane_reference_call(memory, e->entry.guest_pc, args, argc, STACK_TOP, 0,
                                            &ref_v0, NULL);
    alarm(0);
    memcpy(reference, memory->bytes, MUSASHI_RAM_SIZE);
    memcpy(memory->bytes, start, MUSASHI_RAM_SIZE);
    g_ran[idx] = 0;
    g_case_lane = 1;
    alarm(5);
    {
        int lane_ok = musashi_native_lane_reference_call(memory, e->entry.guest_pc, args, argc,
                                                         STACK_TOP, 1, &lane_v0, NULL);
        alarm(0);
        if (negative) {
            if (g_ran[idx]) return NEG_RAN_NATIVE;
            return NEG_OK; /* the interpreter ran the modified words in both runs */
        }
        if (!ok) return NOT_COMPARABLE;
        if (!lane_ok) return DIFFERENT;
    }
    if (!g_ran[idx]) return NOT_NATIVE;
    if (e->entry.returns && ref_v0 != lane_v0) {
        fprintf(stderr, "overlay_lane: %s pattern %u v0 interp=%08x native=%08x\n",
                e->entry.name, pattern, ref_v0, lane_v0);
        return DIFFERENT;
    }
    return ram_differs(memory, reference, e, "positive") ? DIFFERENT : SAME;
}

/* ---- D-011 cycle oracle (positive cases, second child) -----------------
 * The main table holds only the generated entries (PsyQ code interpreted on
 * both sides). The cycle total at each entry to a function outside the lane
 * tables and at the return must match for a ledger-mapped overlay entry. */
enum { C_SAME, C_DIFFERENT, C_NOT_COMPARABLE };
enum { MARKS = 8192 };
static uint64_t g_cycles;
static struct { uint32_t pc; uint64_t cycle; } g_marks[MARKS];
static unsigned g_nmarks;
static int g_overflow;
static uint32_t g_lane_pcs[4096];
static size_t g_lane_n;
static int cyc_advance(void *u, uint32_t c) { (void)u; g_cycles += c; return 1; }
static const MusashiExecutionClock g_cyc_clock = {NULL, cyc_advance};
static int pc_cmp(const void *a, const void *b) {
    uint32_t x = *(const uint32_t *)a, y = *(const uint32_t *)b;
    return x < y ? -1 : x > y;
}
static void cyc_mark(void *u, uint32_t pc, const uint32_t *r) {
    (void)u; (void)r;
    if (bsearch(&pc, g_lane_pcs, g_lane_n, sizeof pc, pc_cmp)) return;
    if (g_nmarks == MARKS) { g_overflow = 1; return; }
    g_marks[g_nmarks].pc = pc; g_marks[g_nmarks].cycle = g_cycles; ++g_nmarks;
}

static int cycle_case(MusashiBootMemory *memory, const uint8_t *image, size_t idx,
                      const MusashiNativeLaneOverlayEntry *e, unsigned pattern) {
    uint32_t args[8], regs[32], fixed0, lost0;
    unsigned argc = e->entry.argc > 8u ? 8u : e->entry.argc, i, ref_n;
    uint64_t ref_total;
    static struct { uint32_t pc; uint64_t cycle; } ref[MARKS];
    uint8_t *start = malloc(MUSASHI_RAM_SIZE);
    int ok;
    if (!start || !e->entry.ledger) return C_NOT_COMPARABLE;
    if (musashi_native_lane_install(musashi_native_lane_generated,
                                    musashi_native_lane_generated_count) < 0) return C_NOT_COMPARABLE;
    musashi_formatter_set_entry_hook(cyc_mark, NULL);
    memcpy(memory->bytes, image, MUSASHI_RAM_SIZE);
    seed_arena(memory, e->entry.guest_pc ^ (pattern * 0x9e3779b9u));
    make_args(pattern, args);
    if (pattern > PATTERNS && is_t161(e)) t161_apply(memory, pattern, args);
    memcpy(start, memory->bytes, MUSASHI_RAM_SIZE);
    g_cycles = 0; g_nmarks = 0; g_overflow = 0;
    alarm(5);
    ok = musashi_native_lane_reference_call_clocked(memory, e->entry.guest_pc, args, argc, STACK_TOP, 0,
                                                    regs, &g_cyc_clock);
    alarm(0);
    if (!ok || g_overflow) return C_NOT_COMPARABLE;
    ref_total = g_cycles; ref_n = g_nmarks;
    memcpy(ref, g_marks, ref_n * sizeof ref[0]);
    memcpy(memory->bytes, start, MUSASHI_RAM_SIZE);
    g_cycles = 0; g_nmarks = 0; g_overflow = 0; g_ran[idx] = 0;
    fixed0 = musashi_lane_fixed; lost0 = musashi_lane_ledger_lost;
    alarm(5);
    ok = musashi_native_lane_reference_call_clocked(memory, e->entry.guest_pc, args, argc, STACK_TOP, 1,
                                                    regs, &g_cyc_clock);
    alarm(0);
    if (!ok || !g_ran[idx] || g_overflow || musashi_lane_fixed != fixed0) return C_NOT_COMPARABLE;
    if (musashi_lane_ledger_lost != lost0) {
        fprintf(stderr, "overlay_cycles: %s pattern %u left its mapped graph\n", e->entry.name, pattern);
        return C_DIFFERENT;
    }
    for (i = 0; i < ref_n || i < g_nmarks; ++i)
        if (i >= ref_n || i >= g_nmarks || ref[i].pc != g_marks[i].pc || ref[i].cycle != g_marks[i].cycle) {
            fprintf(stderr, "overlay_cycles: %s pattern %u boundary %u: interp %08x@%llu native %08x@%llu\n",
                    e->entry.name, pattern, i, i < ref_n ? ref[i].pc : 0u,
                    i < ref_n ? (unsigned long long)ref[i].cycle : 0ull, i < g_nmarks ? g_marks[i].pc : 0u,
                    i < g_nmarks ? (unsigned long long)g_marks[i].cycle : 0ull);
            return C_DIFFERENT;
        }
    if (ref_total != g_cycles) {
        fprintf(stderr, "overlay_cycles: %s pattern %u return: interp %llu native %llu\n", e->entry.name,
                pattern, (unsigned long long)ref_total, (unsigned long long)g_cycles);
        return C_DIFFERENT;
    }
    return C_SAME;
}

/* ---- D-011 deadline guard (positive cases, third child) ----------------
 * native_lane_guard_probe's check for overlay entries: device events fall
 * due on a fixed schedule (first at phase D0, then every P cycles); the
 * checkpoint, called before every interpreted instruction and by the lane's
 * tick, "delivers" a due event by charging an IRQ handler's cost and
 * recording the CPU context (retail pc, delay slot, branch pc, instruction)
 * and the clock. Interpreter and lane must record the same deliveries and
 * the same total. Main table as in the cycle oracle (PsyQ interpreted).
 * Diagnostics: OVERLAY_GUARD_VERBOSE=1 prints each schedule's deliveries;
 * OVERLAY_GUARD_PLANT (below) steers an entry (with OVERLAY_PROBE_ONLY) onto
 * a deeper path, e.g. 8014C99C: "b:800AE66B:ff,w:80126D50:1". */
enum { G_SAME, G_DIFFERENT, G_NOT_COMPARABLE };
enum { MAX_DELIVERIES = 512, HANDLER_CYCLES = 50u };
static const uint32_t G_PHASES[] = {1u, 2u, 3u, 4u, 5u, 6u, 7u, 9u, 11u, 13u, 17u, 23u, 31u, 47u, 64u, 101u};
static const uint32_t G_PERIODS[] = {37u, 211u};
#define GN(a) (sizeof(a) / sizeof((a)[0]))
typedef struct GDelivery { uint32_t pc, branch_pc, instruction; uint8_t delay_slot; uint64_t cycle; } GDelivery;
typedef struct GRun {
    uint64_t cycles, next_due, period;
    GDelivery d[MAX_DELIVERIES];
    unsigned n;
    int overflow, identity_bad;
    const void *identity;
} GRun;
static GRun g_grun;
static int g_advance(void *u, uint32_t c) { (void)u; g_grun.cycles += c; return 1; }
static int g_deadline(void *u, uint64_t *until) {
    (void)u;
    *until = g_grun.next_due > g_grun.cycles ? g_grun.next_due - g_grun.cycles : 0;
    return 1;
}
static const MusashiExecutionClock g_guard_clock = {NULL, g_advance};
static int g_checkpoint(void *u, const void *continuation) {
    MusashiCpuContext ctx;
    (void)u;
    if (!g_grun.identity) g_grun.identity = continuation;
    else if (g_grun.identity != continuation) g_grun.identity_bad = 1;
    if (g_grun.cycles < g_grun.next_due) return 1;
    if (!musashi_boot_cpu_context(continuation, MUSASHI_CPU_CONTEXT_SOURCE, &ctx)) return 0;
    if (g_grun.n == MAX_DELIVERIES) { g_grun.overflow = 1; return 1; }
    g_grun.d[g_grun.n].pc = ctx.pc;
    g_grun.d[g_grun.n].branch_pc = ctx.delay_slot ? ctx.branch_pc : 0u;
    g_grun.d[g_grun.n].instruction = ctx.instruction_valid ? ctx.instruction : 0u;
    g_grun.d[g_grun.n].delay_slot = ctx.delay_slot ? 1u : 0u;
    g_grun.d[g_grun.n].cycle = g_grun.cycles;
    ++g_grun.n;
    g_grun.cycles += HANDLER_CYCLES;
    while (g_grun.next_due <= g_grun.cycles) g_grun.next_due += g_grun.period;
    return 1;
}
static int guard_run(MusashiBootMemory *memory, const MusashiNativeLaneOverlayEntry *e, const uint32_t *args,
                     unsigned argc, int use_lane, uint32_t phase, uint32_t period) {
    uint32_t regs[32];
    int ok;
    memset(&g_grun, 0, sizeof g_grun);
    g_grun.next_due = phase;
    g_grun.period = period;
    alarm(5);
    ok = musashi_native_lane_reference_call_checkpoint(memory, e->entry.guest_pc, args, argc, STACK_TOP,
                                                       use_lane, regs, &g_guard_clock, g_checkpoint, NULL);
    alarm(0);
    return ok;
}

static int guard_case(MusashiBootMemory *memory, const uint8_t *image, size_t idx,
                      const MusashiNativeLaneOverlayEntry *e, unsigned pattern) {
    uint32_t args[8], fixed0, lost0;
    unsigned argc = e->entry.argc > 8u ? 8u : e->entry.argc, p, q, i, compared = 0;
    uint8_t *start = malloc(MUSASHI_RAM_SIZE);
    static GRun ref;
    if (!start || !e->entry.ledger) return G_NOT_COMPARABLE;
    if (musashi_native_lane_install(musashi_native_lane_generated,
                                    musashi_native_lane_generated_count) < 0) return G_NOT_COMPARABLE;
    musashi_execution_clock_set_deadline(&g_guard_clock, g_deadline);
    memcpy(memory->bytes, image, MUSASHI_RAM_SIZE);
    seed_arena(memory, e->entry.guest_pc ^ (pattern * 0x9e3779b9u));
    make_args(pattern, args);
    if (pattern > PATTERNS && is_t161(e)) t161_apply(memory, pattern, args);
    {   /* OVERLAY_GUARD_PLANT="b:ADDR:VAL,w:ADDR:VAL": guest state that steers
         * the entry onto a path the seeded arena does not reach */
        const char *plant = getenv("OVERLAY_GUARD_PLANT");
        char kind;
        unsigned addr, val;
        int used;
        while (plant && sscanf(plant, "%c:%x:%x%n", &kind, &addr, &val, &used) == 3) {
            if (kind == 'b') { uint8_t *b = musashi_boot_ram_span(memory, addr, 1); if (b) *b = (uint8_t)val; }
            else musashi_boot_write32(memory, addr, val);
            plant += used;
            if (*plant == ',') ++plant;
        }
    }
    memcpy(start, memory->bytes, MUSASHI_RAM_SIZE);
    for (q = 0; q < GN(G_PERIODS); ++q)
        for (p = 0; p < GN(G_PHASES); ++p) {
            memcpy(memory->bytes, start, MUSASHI_RAM_SIZE);
            if (!guard_run(memory, e, args, argc, 0, G_PHASES[p], G_PERIODS[q]) || g_grun.overflow) continue;
            ref = g_grun;
            memcpy(memory->bytes, start, MUSASHI_RAM_SIZE);
            g_ran[idx] = 0;
            fixed0 = musashi_lane_fixed; lost0 = musashi_lane_ledger_lost;
            if (!guard_run(memory, e, args, argc, 1, G_PHASES[p], G_PERIODS[q])) {
                fprintf(stderr, "overlay_guard: %s pattern %u phase %u period %u: native run failed\n",
                        e->entry.name, pattern, G_PHASES[p], G_PERIODS[q]);
                return G_DIFFERENT;
            }
            if (!g_ran[idx] || musashi_lane_fixed != fixed0 || g_grun.overflow) return G_NOT_COMPARABLE;
            if (musashi_lane_ledger_lost != lost0) {
                fprintf(stderr, "overlay_guard: %s pattern %u left its mapped graph\n", e->entry.name, pattern);
                return G_DIFFERENT;
            }
            if (g_grun.identity_bad) {
                fprintf(stderr, "overlay_guard: %s: a checkpoint saw another CPU identity\n", e->entry.name);
                return G_DIFFERENT;
            }
            for (i = 0; i < ref.n || i < g_grun.n; ++i) {
                const GDelivery *a = i < ref.n ? &ref.d[i] : NULL, *b = i < g_grun.n ? &g_grun.d[i] : NULL;
                if (!a || !b || a->pc != b->pc || a->cycle != b->cycle || a->delay_slot != b->delay_slot ||
                    a->branch_pc != b->branch_pc || a->instruction != b->instruction) {
                    fprintf(stderr, "overlay_guard: %s pattern %u phase %u period %u delivery %u/%u/%u: "
                            "interp %08x%s@%llu native %08x%s@%llu\n", e->entry.name, pattern, G_PHASES[p],
                            G_PERIODS[q], i, ref.n, g_grun.n, a ? a->pc : 0u, a && a->delay_slot ? "(slot)" : "",
                            a ? (unsigned long long)a->cycle : 0ull, b ? b->pc : 0u,
                            b && b->delay_slot ? "(slot)" : "", b ? (unsigned long long)b->cycle : 0ull);
                    return G_DIFFERENT;
                }
            }
            if (g_grun.cycles != ref.cycles) {
                fprintf(stderr, "overlay_guard: %s pattern %u phase %u period %u: total %llu/%llu\n",
                        e->entry.name, pattern, G_PHASES[p], G_PERIODS[q], (unsigned long long)ref.cycles,
                        (unsigned long long)g_grun.cycles);
                return G_DIFFERENT;
            }
            if (getenv("OVERLAY_GUARD_VERBOSE")) {
                size_t k;
                fprintf(stderr, "overlay_guard: %s pattern %u phase %u period %u deliveries=%u total=%llu ran:",
                        e->entry.name, pattern, G_PHASES[p], G_PERIODS[q], ref.n, (unsigned long long)ref.cycles);
                for (k = 0; k < MAX_ENTRIES; ++k) if (g_ran[k]) fprintf(stderr, " %zu", k);
                fprintf(stderr, "\n");
            }
            ++compared;
        }
    free(start);
    return compared ? G_SAME : G_NOT_COMPARABLE;
}

static uint8_t *read_file(const char *path, size_t *size) {
    FILE *f = fopen(path, "rb");
    uint8_t *data;
    long n;
    if (!f) return NULL;
    fseek(f, 0, SEEK_END);
    n = ftell(f);
    fseek(f, 0, SEEK_SET);
    data = n > 0 ? malloc((size_t)n) : NULL;
    if (data && fread(data, 1, (size_t)n, f) != (size_t)n) { free(data); data = NULL; }
    fclose(f);
    *size = data ? (size_t)n : 0u;
    return data;
}

int main(int argc, char **argv) {
    MusashiBootMemory *memory;
    uint8_t *image, *reference, *start, *exe, *member_file;
    size_t exe_size, member_size, i, n = 0, table_count = 0;
    uint32_t vram, fstart, load_off, load_end;
    const char *member;
    MusashiNativeLaneEntry *table;
    MusashiNativeLaneOverlayEntry mine[MAX_ENTRIES];
    unsigned counts[OUTCOMES] = {0}, bad = 0, ccounts[3] = {0}, cf[3] = {0}, gcounts[3] = {0}, gf[3] = {0};
    if (argc != 8) {
        fprintf(stderr, "usage: %s SLUS_007.26 MEMBER MEMBER_FILE VRAM START LOAD_OFF LOAD_END\n", argv[0]);
        return 2;
    }
    member = argv[2];
    vram = (uint32_t)strtoul(argv[4], NULL, 16);
    fstart = (uint32_t)strtoul(argv[5], NULL, 16);
    load_off = (uint32_t)strtoul(argv[6], NULL, 16);
    load_end = (uint32_t)strtoul(argv[7], NULL, 16);
    exe = read_file(argv[1], &exe_size);
    member_file = read_file(argv[3], &member_size);
    if (!exe || !member_file) { fprintf(stderr, "overlay_lane: EXE or member file unavailable; NOT_RUN\n"); return 77; }
    if (load_end > member_size || load_off >= load_end) { fprintf(stderr, "overlay_lane: bad load range\n"); return 2; }
    memory = mmap((void *)(uintptr_t)MUSASHI_NATIVE_LANE_GUEST_BASE, sizeof(*memory),
                  PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS | MAP_FIXED_NOREPLACE, -1, 0);
    if (memory == MAP_FAILED || (uintptr_t)memory != MUSASHI_NATIVE_LANE_GUEST_BASE) {
        fprintf(stderr, "overlay_lane: host window at 0x80000000 unavailable; NOT_RUN\n");
        return 77;
    }
    if (!musashi_boot_map_exe(memory, exe, exe_size)) { fprintf(stderr, "overlay_lane: EXE rejected\n"); return 1; }
    {   /* the member payload at its load address, as the game's loader leaves it */
        uint32_t dst = vram + load_off - fstart;
        uint8_t *span = musashi_boot_ram_span(memory, dst, load_end - load_off);
        if (!span) { fprintf(stderr, "overlay_lane: load range outside RAM\n"); return 1; }
        memcpy(span, member_file + load_off, load_end - load_off);
    }
    /* The interpreter fetches overlay words only for a member the port has
     * selected as resident (native_boot does this when the member loads).
     * Port numbering is the vendor's 0-based FILE_NNN: registry main_0003 is
     * the port's MAIN_0004 word set. */
    g_foreign = getenv("OVERLAY_PROBE_FOREIGN") && getenv("OVERLAY_PROBE_FOREIGN")[0] == '1';
    if (strcmp(member, "main_0003") == 0) musashi_boot_select_overlay_0004_words(1);
    for (i = 0; i < musashi_native_lane_overlay_count && n < MAX_ENTRIES; ++i) {
        if (!musashi_native_lane_overlay[i].member || strcmp(musashi_native_lane_overlay[i].member, member))
            continue;
        mine[n] = musashi_native_lane_overlay[i];
        g_orig[n] = mine[n].entry.fn;
        mine[n].entry.fn = kTramp[n];
        ++n;
    }
    if (!n) { fprintf(stderr, "overlay_lane: no overlay entries for %s\n", member); return 1; }
    table = musashi_native_lane_psyq_merge(musashi_native_lane_generated, musashi_native_lane_generated_count,
                                           MUSASHI_PSYQ_LANE_PURE, &table_count);
    if (!table) return 1;
    musashi_native_lane_psyq_bind(memory, NULL);
    if (musashi_native_lane_install(table, table_count) < 0 ||
        musashi_native_lane_install_overlay(mine, n) < 0) {
        fprintf(stderr, "overlay_lane: table rejected\n");
        return 1;
    }
    if (!musashi_native_lane_usable(memory)) { fprintf(stderr, "overlay_lane: lane not usable\n"); return 1; }
    image = malloc(MUSASHI_RAM_SIZE);
    reference = malloc(MUSASHI_RAM_SIZE);
    start = malloc(MUSASHI_RAM_SIZE);
    if (!image || !reference || !start) return 1;
    memcpy(image, memory->bytes, MUSASHI_RAM_SIZE);
    for (i = 0; i < musashi_native_lane_generated_count && g_lane_n < 4000u; ++i)
        g_lane_pcs[g_lane_n++] = musashi_native_lane_generated[i].guest_pc;
    for (i = 0; i < n && g_lane_n < 4096u; ++i) g_lane_pcs[g_lane_n++] = mine[i].entry.guest_pc;
    qsort(g_lane_pcs, g_lane_n, sizeof g_lane_pcs[0], pc_cmp);
    for (i = 0; i < n; ++i) {
        unsigned pattern, same = 0, fails = 0, cs = 0, cd = 0, cn = 0, gs = 0, gd = 0, gn = 0;
        const char *only = getenv("OVERLAY_PROBE_ONLY");
        if (only && strtoul(only, NULL, 16) != mine[i].entry.guest_pc) continue;
        /* Entries with guest-frame locals get GL_EXTRA more seeded positive
         * patterns (the generic three rarely complete their callees). */
        unsigned last = PATTERNS + extra_patterns(&mine[i]);
        for (pattern = 0; pattern <= last; ++pattern) {
            int status, outcome;
            pid_t child;
            fflush(stderr);
            child = fork();
            if (child == 0) {
                struct sigaction action;
                memset(&action, 0, sizeof(action));
                action.sa_sigaction = on_fault;
                action.sa_flags = SA_SIGINFO;
                sigaction(SIGSEGV, &action, NULL);
                sigaction(SIGBUS, &action, NULL);
                signal(SIGALRM, SIG_DFL);
                _exit(run_case(memory, image, i, &mine[i], pattern, reference, start));
            }
            if (child < 0 || waitpid(child, &status, 0) != child) return 1;
            outcome = WIFEXITED(status) && WEXITSTATUS(status) < OUTCOMES ? WEXITSTATUS(status) : FAULT;
            /* killed (the 5 s alarm): a negative case cannot show the guard held */
            if (!WIFEXITED(status)) outcome = pattern == PATTERNS || g_foreign ? NEG_RAN_NATIVE : NOT_COMPARABLE;
            counts[outcome]++;
            if (outcome == SAME) same++;
            if (is_t161(&mine[i]) && !g_foreign && pattern > PATTERNS) {
                T161Seed r = t161_seed(pattern);
                k_total[r.cls]++;
                if (outcome == SAME) { k_same[r.cls]++; k_planted_same += r.plant && (r.cls == K_T0_M6 || r.cls == K_TN_M6_TO0); }
            }
            if (pattern != PATTERNS && !g_foreign && mine[i].entry.ledger) {
                int cstatus, c;
                fflush(stderr);
                child = fork();
                if (child == 0) {
                    signal(SIGSEGV, SIG_DFL);
                    signal(SIGALRM, SIG_DFL);
                    _exit(cycle_case(memory, image, i, &mine[i], pattern));
                }
                if (child < 0 || waitpid(child, &cstatus, 0) != child) return 1;
                c = WIFEXITED(cstatus) && WEXITSTATUS(cstatus) <= C_NOT_COMPARABLE ? WEXITSTATUS(cstatus)
                    : (outcome == SAME ? C_DIFFERENT : C_NOT_COMPARABLE);
                ccounts[c]++;
                if (c == C_SAME && is_t161(&mine[i]) && pattern > PATTERNS) k_cyc_same[t161_seed(pattern).cls]++;
                if (c == C_SAME) cs++; else if (c == C_DIFFERENT) cd++; else cn++;
                fflush(stderr);
                child = fork();
                if (child == 0) {
                    signal(SIGSEGV, SIG_DFL);
                    signal(SIGALRM, SIG_DFL);
                    _exit(guard_case(memory, image, i, &mine[i], pattern));
                }
                if (child < 0 || waitpid(child, &cstatus, 0) != child) return 1;
                c = WIFEXITED(cstatus) && WEXITSTATUS(cstatus) <= G_NOT_COMPARABLE ? WEXITSTATUS(cstatus)
                    : G_NOT_COMPARABLE;
                gcounts[c]++;
                if (c == G_SAME) gs++; else if (c == G_DIFFERENT) gd++; else gn++;
            }
            if (outcome == DIFFERENT || outcome == NEG_RAN_NATIVE || outcome == NOT_NATIVE ||
                outcome == FAULT) {
                fails++;
                fprintf(stderr, "overlay_lane: %s %s: %s\n", mine[i].entry.name,
                        pattern == PATTERNS || g_foreign ? "negative" : "positive",
                        outcome == DIFFERENT ? "DIFFERENT" : outcome == NEG_RAN_NATIVE
                            ? "native body ran on modified bytes (or timed out)" : outcome == FAULT
                            ? "host fault outside the documented mirror gap"
                            : "digest did not match the loaded member");
            }
        }
        if (is_t161(&mine[i]) && !g_foreign) {
            unsigned c;
            for (c = 0; c < K_CLASSES; ++c)
                printf("overlay_t161: class %-30s total=%u same=%u cycles_same=%u\n", k_names[c], k_total[c],
                       k_same[c], k_cyc_same[c]);
            printf("overlay_t161: call-path same with a planted 0x3B record=%u\n", k_planted_same);
        }
        if (mine[i].entry.ledger) {
            cf[cd ? C_DIFFERENT : cs ? C_SAME : C_NOT_COMPARABLE]++;
            printf("overlay_cycles: %-34s %08x same=%u different=%u not_comparable=%u\n",
                   mine[i].entry.name, mine[i].entry.guest_pc, cs, cd, cn);
            bad += cd != 0;
            gf[gd ? G_DIFFERENT : gs ? G_SAME : G_NOT_COMPARABLE]++;
            printf("overlay_guard: %-34s %08x same=%u different=%u not_comparable=%u\n",
                   mine[i].entry.name, mine[i].entry.guest_pc, gs, gd, gn);
            bad += gd != 0;
        }
        printf("overlay_lane: %-34s %08x size=%u %s positive_same=%u\n", mine[i].entry.name,
               mine[i].entry.guest_pc, mine[i].size,
               fails ? "BAD" : same ? "verified" : "negative-only (no comparable positive case)", same);
        bad += fails != 0;
    }
    printf("overlay_lane: member=%s%s entries=%zu same=%u different=%u not_native=%u not_comparable=%u "
           "negative_ok=%u negative_ran_native=%u mirror_fault=%u wrap_fault=%u fault=%u functions_bad=%u\n", member,
           g_foreign ? " foreign_payload" : "", n, counts[SAME],
           counts[DIFFERENT], counts[NOT_NATIVE], counts[NOT_COMPARABLE], counts[NEG_OK],
           counts[NEG_RAN_NATIVE], counts[MIRROR_FAULT], counts[WRAP_FAULT], counts[FAULT], bad);
    printf("overlay_cycles: member=%s functions same=%u different=%u not_comparable=%u "
           "cases same=%u different=%u not_comparable=%u\n", member, cf[C_SAME], cf[C_DIFFERENT],
           cf[C_NOT_COMPARABLE], ccounts[C_SAME], ccounts[C_DIFFERENT], ccounts[C_NOT_COMPARABLE]);
    printf("overlay_guard: member=%s functions same=%u different=%u not_comparable=%u "
           "cases same=%u different=%u not_comparable=%u\n", member, gf[G_SAME], gf[G_DIFFERENT],
           gf[G_NOT_COMPARABLE], gcounts[G_SAME], gcounts[G_DIFFERENT], gcounts[G_NOT_COMPARABLE]);
    return bad ? 1 : 0;
}
