/* PsyCross-backed libgte wrappers against PsyCross's real GTE (gteRegs),
 * through the lease bridge. Built by tests/test_bfm_plat.py only when the
 * PsyCross checkout is present. */
#include "bfm_plat.h"
#include "psyq/bfm_psyq_compat.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern unsigned int CFC2(int reg);
extern unsigned int MFC2(int reg);

/* shim for the two PsyCross render-side symbols its GTE references */
int g_cfg_pgxpTextureCorrection = 0;
void PsyX_Log_Warning(const char *fmt, ...) { (void)fmt; }

#define CHECK(e) do { if (!(e)) { printf("FAIL %s:%d: %s\n", __FILE__, __LINE__, #e); exit(1); } } while (0)

static uint8_t ram[2u * 1024u * 1024u];
static uint32_t R[32];
static int begins, ends, allow = 1;
static uint32_t cmds;

static int br_begin(void *u) { (void)u; begins++; return allow; }
static void br_end(void *u, uint32_t c) { (void)u; ends++; cmds += c; }

static void w16(uint32_t a, int16_t v) { a &= 0x1FFFFF; ram[a] = (uint8_t)v; ram[a + 1] = (uint8_t)((uint16_t)v >> 8); }
static void w32(uint32_t a, int32_t v) { w16(a, (int16_t)v); w16(a + 2, (int16_t)((uint32_t)v >> 16)); }
static int32_t r32(uint32_t a) {
    a &= 0x1FFFFF;
    return (int32_t)((uint32_t)ram[a] | ((uint32_t)ram[a + 1] << 8) | ((uint32_t)ram[a + 2] << 16) | ((uint32_t)ram[a + 3] << 24));
}
static int16_t r16(uint32_t a) { a &= 0x1FFFFF; return (int16_t)(ram[a] | (ram[a + 1] << 8)); }

static int call(const char *name, uint32_t a0, uint32_t a1, uint32_t a2, uint32_t a3) {
    const BfmPsyqEntry *t;
    size_t n = bfm_psyq_table(&t), i;
    R[4] = a0; R[5] = a1; R[6] = a2; R[7] = a3;
    for (i = 0; i < n; i++)
        if (strcmp(t[i].name, name) == 0) {
            CHECK(t[i].available);
            return t[i].fn(R);
        }
    printf("FAIL no entry %s\n", name);
    exit(1);
}

/* MATRIX in guest RAM: short m[3][3], pad, int t[3] (32 bytes) */
static void put_matrix(uint32_t a, const int16_t m[9], const int32_t t[3]) {
    int i;
    for (i = 0; i < 9; i++) w16(a + 2u * (uint32_t)i, m[i]);
    w16(a + 18, 0);
    for (i = 0; i < 3; i++) w32(a + 20u + 4u * (uint32_t)i, t[i]);
}

int main(void) {
    static const int16_t ident[9] = {4096, 0, 0, 0, 4096, 0, 0, 0, 4096};
    static const int32_t t1000[3] = {0, 0, 1000};
    BfmPsyqGteBridge b;
    int32_t sx, sy;
    bfm_psyq_set_ram(ram, sizeof ram);
    R[29] = 0x801FFE00;

    /* stateless: no bridge needed */
    CHECK(call("ratan2", 1, 1, 0, 0) && R[2] == 512);
    w16(0x80001000, 0); w16(0x80001002, 1024); w16(0x80001004, 0);   /* 90 deg about Y */
    CHECK(call("RotMatrixYXZ", 0x80001000, 0x80001100, 0, 0) && R[2] == 0x80001100);
    CHECK(r16(0x80001100) == 0 && r16(0x80001104) == 4096 && r16(0x80001110) == 0);
    /* RotMatrixZ multiplies m by the rotation (it doesn't overwrite it) */
    put_matrix(0x80001200, ident, t1000);
    CHECK(call("RotMatrixZ", 1024, 0x80001200, 0, 0) && r16(0x80001200) == 0 && r16(0x80001208) == 0 &&
          r16(0x80001210) == 4096);

    /* GTE state without a bridge: refuse and change nothing */
    put_matrix(0x80002000, ident, t1000);
    CHECK(!call("SetRotMatrix", 0x80002000, 0, 0, 0));

    b.begin = br_begin; b.end = br_end; b.user = NULL;
    bfm_psyq_set_gte_bridge(&b);
    allow = 0;
    CHECK(!call("SetRotMatrix", 0x80002000, 0, 0, 0) && begins == 1 && ends == 0);
    allow = 1;

    /* setters land in the shared gteRegs bank */
    CHECK(call("InitGeom", 0, 0, 0, 0));
    CHECK(call("SetRotMatrix", 0x80002000, 0, 0, 0));
    CHECK(call("SetTransMatrix", 0x80002000, 0, 0, 0));
    CHECK(CFC2(0) == 4096u && CFC2(2) == 4096u && CFC2(4) == 4096u && CFC2(7) == 1000u);
    CHECK(call("SetGeomOffset", 160, 120, 0, 0) && call("SetGeomScreen", 256, 0, 0, 0));
    CHECK(CFC2(26) == 256u);
    CHECK(call("ReadGeomOffset", 0x80003000, 0x80003004, 0, 0) && r32(0x80003000) == 160 && r32(0x80003004) == 120);
    CHECK(call("ReadRotMatrix", 0x80003100, 0, 0, 0) && r16(0x80003100) == 4096 && r32(0x80003100 + 28) == 1000);

    /* RotTransPers: sx = 160 + 100*256/1000, sy = 120 + 50*256/1000, otz = 1000/4 */
    w16(0x80004000, 100); w16(0x80004002, 50); w16(0x80004004, 0);
    CHECK(call("RotTransPers", 0x80004000, 0x80004100, 0x80004104, 0x80004108));
    sx = r16(0x80004100); sy = r16(0x80004102);
    printf("rtps sx %d sy %d otz %d flag %08x\n", sx, sy, (int)R[2], (unsigned)r32(0x80004108));
    CHECK(sx >= 185 && sx <= 186 && sy >= 132 && sy <= 133 && R[2] == 250);
    CHECK(r32(0x8000410C) == 0);   /* 32-bit outputs only: the word after flag is untouched */

    /* RotTransPers3 / 4 (stack arguments) agree with single-vertex results */
    w16(0x80004010, -100); w16(0x80004012, 0); w16(0x80004014, 0);
    w16(0x80004020, 0); w16(0x80004022, -50); w16(0x80004024, 0);
    w16(0x80004030, 30); w16(0x80004032, 30); w16(0x80004034, 0);
    /* a3 = sxy0; the stack holds sxy1, sxy2, p, flag */
    w32(R[29] + 0x10, (int32_t)0x80004204);
    w32(R[29] + 0x14, (int32_t)0x80004208);
    w32(R[29] + 0x18, (int32_t)0x8000420C);
    w32(R[29] + 0x1C, (int32_t)0x80004210);
    CHECK(call("RotTransPers3", 0x80004000, 0x80004010, 0x80004020, 0x80004200));
    CHECK(r32(0x80004200) == r32(0x80004100) && R[2] == 250);
    CHECK(r16(0x80004204) < 160 && r16(0x8000420A) < 120);
    /* RotTransPers4(v0..v3 in a0-a3, sxy0..3 + p + flag on the stack) */
    w32(R[29] + 0x10, (int32_t)0x80004300); w32(R[29] + 0x14, (int32_t)0x80004304);
    w32(R[29] + 0x18, (int32_t)0x80004308); w32(R[29] + 0x1C, (int32_t)0x8000430C);
    w32(R[29] + 0x20, (int32_t)0x80004310); w32(R[29] + 0x24, (int32_t)0x80004314);
    CHECK(call("RotTransPers4", 0x80004000, 0x80004010, 0x80004020, 0x80004030));
    CHECK(r32(0x80004300) == r32(0x80004100) && r16(0x8000430C) > 160 && r16(0x8000430E) > 120);

    /* matrices: ApplyMatrixSV / MulMatrix0 with the identity */
    w16(0x80005000, 7); w16(0x80005002, -9); w16(0x80005004, 11);
    CHECK(call("ApplyMatrixSV", 0x80002000, 0x80005000, 0x80005008, 0) && R[2] == 0x80005008);
    CHECK(r16(0x80005008) == 7 && r16(0x8000500A) == -9 && r16(0x8000500C) == 11);
    CHECK(call("MulMatrix0", 0x80002000, 0x80001100, 0x80005100, 0) && R[2] == 0x80005100);
    CHECK(memcmp(ram + 0x5100, ram + 0x1100, 18) == 0);
    CHECK(call("CompMatrix", 0x80002000, 0x80002000, 0x80005200, 0) && r32(0x80005200 + 28) == 2000);

    /* bad pointer refuses before the bridge is entered */
    {
        int before = begins;
        CHECK(!call("SetRotMatrix", 0x801FFFF0, 0, 0, 0) && begins == before);
    }
    printf("bridge begins %d ends %d commands %u\n", begins, ends, (unsigned)cmds);
    CHECK(ends == begins - 1);
    printf("ok gte\n");
    return 0;
}
