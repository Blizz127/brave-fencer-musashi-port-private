/* Byte-exact decompilation of main [80010178,8001096C).
 * Verified against retail SLUS-00726 with tools/match_function.py (100.00% match). */
#include "psx_types.h"

extern u8  D_800BA118;
extern u8  D_800AF630[];
extern s32 D_80074778;
extern s32 D_800A2B7C;
extern s32 D_800C7C70;
extern s16 D_800C7C74;
extern s32 D_800A5E60;
extern u8  D_8007BA70[];
extern u8  D_800A4F48[];
extern s32 D_800A651C;
extern u8  D_800A6528[];
extern u8  D_800A6610[];
extern u8  D_800AA60C[];
extern s32 D_800AE7BC;
extern s32 D_800AE7C8;
extern u8  D_800BA0D8[];
extern u8  D_800BA0E4[];

extern void func_80043060(s32);
extern void func_800141F0(void);
extern void func_8005FC68(s32);
extern void func_8005FCB8(void);
extern void func_80018918(void);
extern s32  func_80043300(void);
extern void func_8002C8F4(void);
extern void func_8001971C(void);
extern void func_80014238(void);
extern void func_80014390(void);
extern void func_800191A8(void);
extern void func_80010A98(void);
extern void func_800189A8(void);
extern void func_80015208(void);
extern void func_80059BFC(s32, s32);
extern void func_80010B40(void);
extern void func_80015498(void);
extern void func_8001C00C(void);
extern void func_800D25FC(void);
extern void func_800184F0(void);
extern void func_800596F4(s32);
extern s32  func_8004239C(s32);
extern void func_80059FC0(u8 *);
extern void func_80059D68(u8 *);
extern void func_80058CE4(s32, s32);
extern s32  func_80059CF4(s32);
extern void func_8003500C(void);
extern void func_8002D034(void);
extern void func_8001AF34(void);
extern void func_8001513C(void);
extern void func_80042610(void (*)(void));

struct MainSlot { s32 unk0; s32 unk4; s32 unk8; };

void main(void) {
    register u8 *q = &D_800BA118;
    register u8 *p = D_800AF630;
    s32 pad[6];

    func_80043060(0);
    D_80074778 = 0x3E0;
    func_800141F0();
    func_8005FC68(0);
    func_8005FCB8();
    func_80018918();
    D_800A2B7C = func_80043300();
    func_8002C8F4();
    func_8001971C();

    while (1) {
        func_80014238();
        func_80014390();
        func_800191A8();
        func_80010A98();

        while (*(u16 *)(p + 0xA3D4) == 0) {
            D_800C7C70++;
            D_800C7C70 = D_800C7C70 ? D_800C7C70 : 1;
            D_800C7C74 = !D_800C7C74;
            *(u16 *)(p + 0xA3D2) = D_800C7C74;

            D_800A5E60 = (s32)(D_8007BA70 + *(u16 *)(p + 0xA3D2) * 80000);
            ((struct MainSlot *)(p + ((*(u16 *)(p + 0xA3D2) * 3) << 2)))->unk8 =
                (s32)(D_800A4F48 + *(u16 *)(p + 0xA3D2) * 1600);
            ((struct MainSlot *)(p + ((*(u16 *)(p + 0xA3D2) * 3) << 2)))->unk0 = 0x640;
            ((struct MainSlot *)(p + ((*(u16 *)(p + 0xA3D2) * 3) << 2)))->unk4 = 0;

            func_800189A8();
            func_80015208();

            if (*(u8 *)(p + 0xA3E3) == 0) {
                (*(u16 *)(p + 0xA3A8))++;
                *(u16 *)(p + 0xA3AC) += *(u16 *)(p + 0xA3A8);

                *(s32 *)((u8 *)&D_800A651C + ((*(u16 *)(p + 0xA3D2) * 5) << 2)) =
                    (s32)(D_800A6610 + *(u16 *)(p + 0xA3D2) * 16384);
                *(s32 *)(D_800A6528 + ((*(u16 *)(p + 0xA3D2) * 5) << 2)) =
                    *(u16 *)(p + 0xA3D2) * 16384 + (s32)D_800AA60C;
                func_80059BFC(*(s32 *)((u8 *)&D_800A651C + ((*(u16 *)(p + 0xA3D2) * 5) << 2)), 0x1000);
                *(s32 *)((u8 *)&D_800AE7BC + ((*(u16 *)(p + 0xA3D2) * 5) << 2)) =
                    (s32)(D_800BA0D8 + *(u16 *)(p + 0xA3D2) * 16);
                *(s32 *)((u8 *)&D_800AE7C8 + ((*(u16 *)(p + 0xA3D2) * 5) << 2)) =
                    *(u16 *)(p + 0xA3D2) * 16 + (s32)D_800BA0E4;
                func_80059BFC(*(s32 *)((u8 *)&D_800AE7BC + ((*(u16 *)(p + 0xA3D2) * 5) << 2)), 4);
                func_80010B40();

                __asm__ __volatile__(
                    "lui   $a2, 0x1f80\n"
                    "ori   $a2, $a2, 0x03fc\n"
                    "addu  $t0, $a2, $zero\n"
                    "sw    $sp, 0($t0)\n"
                    "addiu $t0, $t0, -4\n"
                    "addu  $sp, $t0, $zero\n" : : : "memory");
                func_80015498();
                __asm__ __volatile__(
                    "addiu $sp, $sp, 4\n"
                    "lw    $sp, 0($sp)\n" : : : "memory");

                __asm__ __volatile__(
                    "lui   $a2, 0x1f80\n"
                    "ori   $a2, $a2, 0x03fc\n"
                    "addu  $t0, $a2, $zero\n"
                    "sw    $sp, 0($t0)\n"
                    "addiu $t0, $t0, -4\n"
                    "addu  $sp, $t0, $zero\n" : : : "memory");
                func_8001C00C();
                __asm__ __volatile__(
                    "addiu $sp, $sp, 4\n"
                    "lw    $sp, 0($sp)\n" : : : "memory");
            } else {
                *(s32 *)((u8 *)&D_800AE7BC + ((*(u16 *)(p + 0xA3D2) * 5) << 2)) =
                    (s32)(D_800BA0D8 + *(u16 *)(p + 0xA3D2) * 16);
                *(s32 *)((u8 *)&D_800AE7C8 + ((*(u16 *)(p + 0xA3D2) * 5) << 2)) =
                    *(u16 *)(p + 0xA3D2) * 16 + (s32)D_800BA0E4;
                func_80059BFC(*(s32 *)((u8 *)&D_800AE7BC + ((*(u16 *)(p + 0xA3D2) * 5) << 2)), 4);

                __asm__ __volatile__(
                    "lui   $a2, 0x1f80\n"
                    "ori   $a2, $a2, 0x03fc\n"
                    "addu  $t0, $a2, $zero\n"
                    "sw    $sp, 0($t0)\n"
                    "addiu $t0, $t0, -4\n"
                    "addu  $sp, $t0, $zero\n" : : : "memory");
                func_800D25FC();
                __asm__ __volatile__(
                    "addiu $sp, $sp, 4\n"
                    "lw    $sp, 0($sp)\n" : : : "memory");
            }

            func_800184F0();
            func_800596F4(0);
            func_8004239C(*(s32 *)(p + 0xA3E8));

            *(u16 *)(p + 0x188) = *(u16 *)(p + 0x18A);
            (*(u16 *)(p + 0x18A))++;
            if (*(u16 *)(p + 0x18A) > 1) {
                *(u16 *)(p + 0x18A) = 0;
            }
            func_80059FC0(&p[*(u16 *)(p + 0x188) * 20 + 0x14C]);
            func_80059D68(&p[*(u16 *)(p + 0x18A) * 92 + 0x38]);

            func_80058CE4(*(s32 *)((u8 *)&D_800A651C + ((*(u16 *)(p + 0xA3D2) * 5) << 2)) + 0x3FF0,
                          *(s32 *)((u8 *)&D_800A651C + ((*(u16 *)(p + 0xA3D2) * 5) << 2)) + D_80074778 * 4);
            func_80059CF4(*(s32 *)((u8 *)&D_800A651C + ((*(u16 *)(p + 0xA3D2) * 5) << 2)) + 0x3FFC);
            func_80059CF4(*(s32 *)((u8 *)&D_800AE7BC + ((*(u16 *)(p + 0xA3D2) * 5) << 2)) + 0xC);
            func_8003500C();
            func_8002D034();
            func_8001AF34();
            func_8001513C();
        }
        func_80042610(0);
    }
}
