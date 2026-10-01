/* libpad SIO exchange leaves (see bfm_psyq_libpad.h).
 *
 * Every function below walks the retail control flow of its routine and
 * reports each retail instruction to the frame: RUN for register-only
 * instructions (counted by PC; branch delay slots included), LD/ST for each
 * load/store, which the frame charges and then performs through the same
 * memory/device path as its interpreter. Register effects are applied in
 * retail order, so the GPRs at `jr ra` equal the interpreter's. Comments give
 * the retail PC of each block. */
#include "bfm_psyq_libpad.h"

#include <stddef.h>

int bfm_psyq_pad_test_break;

enum {
    AT = 1, V0 = 2, V1 = 3, A0 = 4, A1 = 5, A2 = 6, A3 = 7,
    T0 = 8, T1 = 9, T2 = 10, S0 = 16, S1 = 17, S2 = 18, S3 = 19, SP = 29, RA = 31
};

/* Guest addresses the routines use. */
#define SIO_SLOT   0x800729C0u  /* holds the SIO0 base, 1F801040 */
#define ISTAT_SLOT 0x800729BCu  /* holds I_STAT, 1F801070 */
#define STEP_INDEX 0x800729A0u  /* the handler's step counter */
#define RC2_START  0x80078F24u  /* Timer2 count latched by 8005FBA8 */
#define RC2_WAIT   0x800C5320u  /* wait length (Timer2 ticks / 8) */
#define T2_COUNT   0x1F801120u
#define T2_MODE    0x1F801124u
#define T2_TARGET  0x1F801128u
/* LUI halves the retail code builds those addresses from (%hi rounds when
 * the low half is >= 0x8000). */
#define HI_7       0x80070000u
#define HI_RC2S    0x80080000u
#define HI_RC2W    0x800C0000u

#define R (io->r)
#define RUN(pc, n) do { if (!io->run(io->user, (pc), (n))) return BFM_PAD_LEAF_FAULT; } while (0)
#define LD(pc, reg, address, width) do { \
        uint32_t v_; \
        if (!io->load(io->user, (pc), (address), (width), &v_)) return BFM_PAD_LEAF_FAULT; \
        R[reg] = v_; \
    } while (0)
#define ST(pc, address, width, value) do { \
        if (!io->store(io->user, (pc), (address), (width), (value))) return BFM_PAD_LEAF_FAULT; \
    } while (0)
#define SITE(pc) do { if (io->site) io->site(io->user, (pc)); } while (0)
#define CALL(f) do { int c_ = (f)(io); if (c_ != BFM_PAD_LEAF_DONE) return c_; } while (0)

/* 8005FBA8: v0 = Timer2 count; RC2_WAIT = a0; RC2_START = v0. */
static int leaf_fba8(const BfmPadLeafIo *io) {
    RUN(0x8005FBA8u, 2);                     /* lui/ori v0 = T2_COUNT */
    R[V0] = T2_COUNT;
    LD(0x8005FBB0u, V0, R[V0], 2);           /* lhu v0,0(v0) */
    RUN(0x8005FBB4u, 1);                     /* lui at */
    R[AT] = HI_RC2W;
    ST(0x8005FBB8u, RC2_WAIT, 4, R[A0]);     /* sw a0 */
    RUN(0x8005FBBCu, 2);                     /* lui at; jr ra */
    R[AT] = HI_RC2S;
    ST(0x8005FBC4u, RC2_START, 4, R[V0]);    /* (delay) sw v0 */
    return BFM_PAD_LEAF_DONE;
}

/* 8005FBC8: v0 = (elapsed Timer2 ticks [>> 3 unless mode bit 0x200]) >= wait.
 * A count below the start wraps by the target, or 0x10000 if it is 0. The
 * mode read is a real device read (it clears the model's latched bits). */
static int leaf_fbc8(const BfmPadLeafIo *io) {
    int take;
    RUN(0x8005FBC8u, 2);
    R[V0] = T2_COUNT;
    LD(0x8005FBD0u, V1, R[V0], 2);           /* lhu v1, count */
    RUN(0x8005FBD4u, 1);
    R[V0] = HI_RC2S;
    LD(0x8005FBD8u, V0, RC2_START, 4);       /* lw v0, start */
    RUN(0x8005FBDCu, 4);                     /* andi; sltu; beqz; (delay) lui v1 */
    R[A0] = R[V1] & 0xFFFFu;
    R[V0] = R[A0] < R[V0];
    take = R[V0] == 0;
    R[V1] = 0x1F800000u;
    if (!take) {                             /* count < start: wrapped */
        RUN(0x8005FBECu, 1);
        R[V1] = T2_TARGET;
        LD(0x8005FBF0u, V0, R[V1], 2);       /* lhu v0, target */
        RUN(0x8005FBF4u, 3);                 /* nop; beqz; (delay) lui v0 */
        take = R[V0] == 0;
        R[V0] = 0x10000u;
        if (!take) {
            LD(0x8005FC00u, V0, R[V1], 2);   /* lhu v0, target */
            RUN(0x8005FC04u, 2);             /* j; (delay) addu a0 */
            R[A0] += R[V0];
        } else {
            RUN(0x8005FC0Cu, 1);             /* addu a0, a0, 0x10000 */
            R[A0] += R[V0];
        }
    }
    RUN(0x8005FC10u, 2);
    R[V0] = T2_MODE;
    LD(0x8005FC18u, V0, R[V0], 2);           /* lhu v0, mode */
    RUN(0x8005FC1Cu, 4);                     /* nop; andi; bnez; (delay) nop */
    R[V0] &= 0x200u;
    if (!R[V0]) {
        RUN(0x8005FC2Cu, 1);
        R[V0] = HI_RC2S;
        LD(0x8005FC30u, V0, RC2_START, 4);
        RUN(0x8005FC34u, 1);
        R[V1] = HI_RC2W;
        LD(0x8005FC38u, V1, RC2_WAIT, 4);
        RUN(0x8005FC3Cu, 3);                 /* subu; j; (delay) srl 3 */
        R[V0] = R[A0] - R[V0];
        R[V0] >>= bfm_psyq_pad_test_break == 1 ? 2 : 3;
    } else {
        RUN(0x8005FC48u, 1);
        R[V0] = HI_RC2S;
        LD(0x8005FC4Cu, V0, RC2_START, 4);
        RUN(0x8005FC50u, 1);
        R[V1] = HI_RC2W;
        LD(0x8005FC54u, V1, RC2_WAIT, 4);
        RUN(0x8005FC58u, 1);
        R[V0] = R[A0] - R[V0];
    }
    RUN(0x8005FC5Cu, 3);                     /* sltu; jr ra; (delay) xori */
    R[V0] = (R[V0] < R[V1]) ^ 1u;
    return BFM_PAD_LEAF_DONE;
}

/* A retail `jal` at `call` into another leaf: the jal and its delay slot
 * (the caller applies any delay-slot effect), ra = call + 8. */
static int call_leaf(const BfmPadLeafIo *io, uint32_t call, uint32_t target) {
    RUN(call, 2);
    R[RA] = call + 8u;
    /* The two DE78 calls of 8005FBA8 load a0 in the delay slot. */
    if (call == 0x8005DEECu) R[A0] = 0x190u;
    if (call == 0x8005E028u) R[A0] = 0x3Cu;
    io->entered(io->user, target, call);
    return BFM_PAD_LEAF_DONE;
}
#define JAL(call, target, leaf) do { \
        int j_ = call_leaf(io, (call), (target)); \
        if (j_ != BFM_PAD_LEAF_DONE) return j_; \
        CALL(leaf); \
    } while (0)

/* 8005E13C: spin until SIO STAT bit 1 (RX ready). No retail timeout. */
static int leaf_e13c(const BfmPadLeafIo *io) {
    RUN(0x8005E13Cu, 1);
    R[V1] = HI_7;
    LD(0x8005E140u, V1, SIO_SLOT, 4);
    RUN(0x8005E144u, 1);
    for (;;) {
        SITE(0x8005E148u);
        LD(0x8005E148u, V0, R[V1] + 4u, 2);  /* lhu v0, STAT */
        RUN(0x8005E14Cu, 4);                 /* nop; andi; beqz; (delay) nop */
        R[V0] &= 2u;
        if (R[V0]) break;
    }
    RUN(0x8005E15Cu, bfm_psyq_pad_test_break == 5 ? 3 : 2);  /* jr ra; nop */
    return BFM_PAD_LEAF_DONE;
}

/* 8005E0AC: I_STAT = ~0x80; while STAT bit 7 (/ACK still low) poll the RC2
 * wait, giving up (v0 = 0) when it expires; else CTRL |= 0x10, v0 = 1. */
static int leaf_e0ac(const BfmPadLeafIo *io) {
    RUN(0x8005E0ACu, 2);                     /* addiu sp; lui v1 */
    R[SP] -= 0x18u;
    R[V1] = HI_7;
    LD(0x8005E0B4u, V1, ISTAT_SLOT, 4);
    RUN(0x8005E0B8u, 1);
    R[A0] = HI_7;
    LD(0x8005E0BCu, A0, SIO_SLOT, 4);
    RUN(0x8005E0C0u, 1);
    R[V0] = 0xFFFFFF7Fu;
    ST(0x8005E0C4u, R[SP] + 0x10u, 4, R[RA]);
    if (bfm_psyq_pad_test_break == 2) RUN(0x8005E0C8u, 1);  /* drop the I_STAT ack */
    else ST(0x8005E0C8u, R[V1], 4, R[V0]);   /* sw v0, I_STAT */
    LD(0x8005E0CCu, V0, R[A0] + 4u, 2);      /* lhu v0, STAT */
    RUN(0x8005E0D0u, 4);                     /* nop; andi; beqz; (delay) nop */
    R[V0] &= 0x80u;
    if (R[V0]) {
        for (;;) {
            SITE(0x8005E0E0u);
            JAL(0x8005E0E0u, 0x8005FBC8u, leaf_fbc8);
            RUN(0x8005E0E8u, 2);             /* bnez v0; (delay) addu v0, 0 */
            if (R[V0]) { R[V0] = 0; goto out; }
            R[V0] = 0;
            RUN(0x8005E0F0u, 1);
            R[V0] = HI_7;
            LD(0x8005E0F4u, V0, SIO_SLOT, 4);
            RUN(0x8005E0F8u, 1);
            LD(0x8005E0FCu, V0, R[V0] + 4u, 2);
            RUN(0x8005E100u, 4);             /* nop; andi; bnez; (delay) nop */
            R[V0] &= 0x80u;
            if (!R[V0]) break;
        }
    }
    RUN(0x8005E110u, 1);
    R[A0] = HI_7;
    LD(0x8005E114u, A0, SIO_SLOT, 4);
    RUN(0x8005E118u, 1);
    LD(0x8005E11Cu, V1, R[A0] + 0xAu, 2);    /* lhu v1, CTRL */
    RUN(0x8005E120u, 2);                     /* addiu v0, 1; ori v1, 0x10 */
    R[V0] = 1;
    R[V1] |= bfm_psyq_pad_test_break == 4 ? 0u : 0x10u;
    ST(0x8005E128u, R[A0] + 0xAu, 2, R[V1]);
out:
    LD(0x8005E12Cu, RA, R[SP] + 0x10u, 4);
    RUN(0x8005E130u, 3);                     /* addiu sp; jr ra; nop */
    R[SP] += 0x18u;
    return BFM_PAD_LEAF_DONE;
}

/* 8005DCA0 (rec = a0, byte = a1). a1 < 0: the transaction's first byte:
 * reset the record cursors, store ~a1 as the first receive byte, wait TX
 * ready and the select delay (RC2 already started), then send ~a1; return
 * the stale DATA byte read first. a1 >= 0: start a 0x1AE RC2 wait, wait RX
 * ready, read the reply, set the baud (0x22 for a multitap past 8 bytes),
 * wait for the ACK latch (I_STAT bit 7) or the RC2 timeout (-0x14), then
 * send a1 and store the reply at rec+0x44. */
static int leaf_dca0(const BfmPadLeafIo *io) {
    int take;
    RUN(0x8005DCA0u, 1);
    R[SP] -= 0x20u;
    ST(0x8005DCA4u, R[SP] + 0x10u, 4, R[S0]);
    RUN(0x8005DCA8u, 1);
    R[S0] = R[A0];
    ST(0x8005DCACu, R[SP] + 0x18u, 4, R[S2]);
    RUN(0x8005DCB0u, 1);
    R[S2] = R[A1];
    ST(0x8005DCB4u, R[SP] + 0x1Cu, 4, R[RA]);
    RUN(0x8005DCB8u, 1);                     /* bgez s2 */
    take = (int32_t)R[S2] >= 0;
    ST(0x8005DCBCu, R[SP] + 0x14u, 4, R[S1]);/* (delay) sw s1 */
    if (!take) {
        RUN(0x8005DCC0u, 1);
        R[V0] = HI_7;
        LD(0x8005DCC4u, V0, SIO_SLOT, 4);
        LD(0x8005DCC8u, V1, R[S0] + 0x40u, 4);
        LD(0x8005DCCCu, A0, R[V0], 1);       /* lbu a0, DATA */
        RUN(0x8005DCD0u, 1);
        R[V0] = 0xFFu;
        ST(0x8005DCD4u, R[S0] + 0x44u, 1, R[V0]);
        RUN(0x8005DCD8u, 1);
        R[V0] = 1;
        ST(0x8005DCDCu, R[S0] + 0x45u, 1, R[V0]);
        RUN(0x8005DCE0u, 1);
        R[V0] = ~R[S2];
        ST(0x8005DCE4u, R[V1], 1, R[V0]);
        RUN(0x8005DCE8u, 1);
        R[V1] = HI_7;
        LD(0x8005DCECu, V1, SIO_SLOT, 4);
        RUN(0x8005DCF0u, 1);
        LD(0x8005DCF4u, V0, R[V1] + 4u, 2);  /* lhu v0, STAT */
        RUN(0x8005DCF8u, 4);                 /* nop; andi; bnez; (delay) andi s1 */
        R[V0] &= 1u;
        take = R[V0] != 0;
        R[S1] = R[A0] & 0xFFu;
        if (!take) {
            for (;;) {                       /* TX ready */
                SITE(0x8005DD08u);
                LD(0x8005DD08u, V0, R[V1] + 4u, 2);
                RUN(0x8005DD0Cu, 4);
                R[V0] &= 1u;
                if (R[V0]) break;
            }
        }
        for (;;) {                           /* select delay */
            SITE(0x8005DD1Cu);
            JAL(0x8005DD1Cu, 0x8005FBC8u, leaf_fbc8);
            RUN(0x8005DD24u, 2);             /* beqz v0; (delay) nor v0, s2 */
            take = R[V0] == 0;
            R[V0] = ~R[S2];
            if (!take) break;
        }
        RUN(0x8005DD2Cu, 1);
        R[V1] = HI_7;
        LD(0x8005DD30u, V1, SIO_SLOT, 4);
        RUN(0x8005DD34u, 1);
        if (bfm_psyq_pad_test_break == 6) RUN(0x8005DD38u, 1);  /* select byte never sent */
        else ST(0x8005DD38u, R[V1], 1, R[V0]);    /* sb v0, DATA */
        RUN(0x8005DD3Cu, 2);                 /* j; (delay) addu v0, s1 */
        R[V0] = R[S1];
        goto epilogue;
    }
    LD(0x8005DD44u, V0, R[S0] + 0x3Cu, 4);
    RUN(0x8005DD48u, 1);
    LD(0x8005DD4Cu, V0, R[V0], 1);
    RUN(0x8005DD50u, 4);                     /* addiu v1, 8; sra; bne; (delay) a2 = 0x88 */
    R[V1] = 8;
    R[V0] = (uint32_t)((int32_t)R[V0] >> 4);
    take = R[V0] != R[V1];
    R[A2] = bfm_psyq_pad_test_break == 3 ? 0x89u : 0x88u;
    if (take) {
        RUN(0x8005DD78u, 1);
        R[V0] = 0x1F800000u;
    } else {
        LD(0x8005DD60u, V0, R[S0] + 0x44u, 1);
        RUN(0x8005DD64u, 4);                 /* nop; sltiu; bnez; (delay) lui v0 */
        R[V0] = R[V0] < 9u;
        take = R[V0] != 0;
        R[V0] = 0x1F800000u;
        if (!take) {
            RUN(0x8005DD74u, 2);             /* a2 = 0x22; lui v0 */
            R[A2] = 0x22u;
            R[V0] = 0x1F800000u;
        }
    }
    RUN(0x8005DD7Cu, 2);                     /* ori v0; lui a1 */
    R[V0] = T2_COUNT;
    R[A1] = HI_7;
    LD(0x8005DD84u, A1, SIO_SLOT, 4);
    LD(0x8005DD88u, A0, R[V0], 2);           /* lhu a0, Timer2 */
    LD(0x8005DD8Cu, V1, R[A1] + 4u, 2);      /* lhu v1, STAT */
    RUN(0x8005DD90u, 2);                     /* v0 = 0x1AE; lui at */
    R[V0] = 0x1AEu;
    R[AT] = HI_RC2W;
    ST(0x8005DD98u, RC2_WAIT, 4, R[V0]);
    RUN(0x8005DD9Cu, 1);
    R[AT] = HI_RC2S;
    ST(0x8005DDA0u, RC2_START, 4, R[A0]);
    RUN(0x8005DDA4u, 3);                     /* andi; bnez; (delay) addu v1, a1 */
    R[V1] &= 2u;
    take = R[V1] != 0;
    R[V1] = R[A1];
    if (!take) {
        for (;;) {                           /* RX ready */
            SITE(0x8005DDB0u);
            LD(0x8005DDB0u, V0, R[V1] + 4u, 2);
            RUN(0x8005DDB4u, 4);
            R[V0] &= 2u;
            if (R[V0]) break;
        }
    }
    RUN(0x8005DDC4u, 1);
    R[V0] = HI_7;
    LD(0x8005DDC8u, V0, SIO_SLOT, 4);
    RUN(0x8005DDCCu, 1);
    R[V1] = HI_7;
    LD(0x8005DDD0u, V1, ISTAT_SLOT, 4);
    LD(0x8005DDD4u, A0, R[V0], 1);           /* lbu a0, DATA */
    ST(0x8005DDD8u, R[V0] + 0xEu, 2, R[A2]); /* sh a2, BAUD */
    LD(0x8005DDDCu, V0, R[V1], 4);           /* lw v0, I_STAT */
    RUN(0x8005DDE0u, 4);                     /* nop; andi; bnez; (delay) andi s1 */
    R[V0] &= 0x80u;
    take = R[V0] != 0;
    R[S1] = R[A0] & 0xFFu;
    if (!take) {
        for (;;) {                           /* ACK latch or timeout */
            SITE(0x8005DDF0u);
            JAL(0x8005DDF0u, 0x8005FBC8u, leaf_fbc8);
            RUN(0x8005DDF8u, 2);             /* bnez v0; (delay) v0 = -0x14 */
            take = R[V0] != 0;
            R[V0] = (uint32_t)-0x14;
            if (take) goto epilogue;
            RUN(0x8005DE00u, 1);
            R[V0] = HI_7;
            LD(0x8005DE04u, V0, ISTAT_SLOT, 4);
            RUN(0x8005DE08u, 1);
            LD(0x8005DE0Cu, V0, R[V0], 4);
            RUN(0x8005DE10u, 4);             /* nop; andi; beqz; (delay) nop */
            R[V0] &= 0x80u;
            if (R[V0]) break;
        }
    }
    RUN(0x8005DE20u, 1);
    R[V0] = HI_7;
    LD(0x8005DE24u, V0, SIO_SLOT, 4);
    RUN(0x8005DE28u, 1);
    ST(0x8005DE2Cu, R[V0], 1, R[S2]);        /* sb s2, DATA */
    LD(0x8005DE30u, V0, R[S0] + 0x45u, 1);
    LD(0x8005DE34u, A0, R[S0] + 0x44u, 1);
    LD(0x8005DE38u, V1, R[S0] + 0x3Cu, 4);
    RUN(0x8005DE3Cu, 2);
    R[V0] += 1u;
    R[V1] += R[A0];
    ST(0x8005DE44u, R[S0] + 0x45u, 1, R[V0]);
    ST(0x8005DE48u, R[V1], 1, R[S1]);
    LD(0x8005DE4Cu, V0, R[S0] + 0x44u, 1);
    RUN(0x8005DE50u, 2);
    R[V0] += 1u;
    ST(0x8005DE58u, R[S0] + 0x44u, 1, R[V0]);
    RUN(0x8005DE5Cu, 1);
    R[V0] = R[S1];
epilogue:
    LD(0x8005DE60u, RA, R[SP] + 0x1Cu, 4);
    LD(0x8005DE64u, S2, R[SP] + 0x18u, 4);
    LD(0x8005DE68u, S1, R[SP] + 0x14u, 4);
    LD(0x8005DE6Cu, S0, R[SP] + 0x10u, 4);
    RUN(0x8005DE70u, 2);                     /* jr ra; (delay) addiu sp */
    R[SP] += 0x20u;
    return BFM_PAD_LEAF_DONE;
}

/* 8005DE78 (rec = a0, byte = a1): wait RX ready, start a 0x190 RC2 wait,
 * read the reply, set the baud (0x22 for a multitap past 8 bytes, or when
 * the first reply byte names one), then wait for the ACK latch with an
 * inline Timer2 timeout (v0 = -2). Unless the record is a multitap, step
 * index 2 adds a 0x3C RC2 delay. Then send a1, store the reply at the
 * rec+0x44 cursor unless it is 0xFF, and return it. */
static int leaf_de78(const BfmPadLeafIo *io) {
    int take;
    RUN(0x8005DE78u, 1);
    R[SP] -= 0x28u;
    ST(0x8005DE7Cu, R[SP] + 0x10u, 4, R[S0]);
    RUN(0x8005DE80u, 1);
    R[S0] = R[A0];
    ST(0x8005DE84u, R[SP] + 0x1Cu, 4, R[S3]);
    RUN(0x8005DE88u, 1);
    R[S3] = R[A1];
    ST(0x8005DE8Cu, R[SP] + 0x20u, 4, R[RA]);
    ST(0x8005DE90u, R[SP] + 0x18u, 4, R[S2]);
    ST(0x8005DE94u, R[SP] + 0x14u, 4, R[S1]);
    LD(0x8005DE98u, V0, R[S0] + 0x3Cu, 4);
    RUN(0x8005DE9Cu, 1);
    LD(0x8005DEA0u, V0, R[V0], 1);
    RUN(0x8005DEA4u, 4);                     /* v1 = 8; sra; bne; (delay) s1 = 0x88 */
    R[V1] = 8;
    R[V0] = (uint32_t)((int32_t)R[V0] >> 4);
    take = R[V0] != R[V1];
    R[S1] = 0x88u;
    if (!take) {
        LD(0x8005DEB4u, V0, R[S0] + 0x44u, 1);
        RUN(0x8005DEB8u, 4);                 /* nop; sltiu; bnez; (delay) nop */
        R[V0] = R[V0] < 9u;
        if (!R[V0]) {
            RUN(0x8005DEC8u, 1);
            R[S1] = 0x22u;
        }
    }
    RUN(0x8005DECCu, 1);
    R[V1] = HI_7;
    LD(0x8005DED0u, V1, SIO_SLOT, 4);
    RUN(0x8005DED4u, 1);
    for (;;) {                               /* RX ready */
        SITE(0x8005DED8u);
        LD(0x8005DED8u, V0, R[V1] + 4u, 2);
        RUN(0x8005DEDCu, 4);
        R[V0] &= 2u;
        if (R[V0]) break;
    }
    JAL(0x8005DEECu, 0x8005FBA8u, leaf_fba8);
    RUN(0x8005DEF4u, 1);
    R[A0] = HI_7;
    LD(0x8005DEF8u, A0, SIO_SLOT, 4);
    RUN(0x8005DEFCu, 1);
    LD(0x8005DF00u, V0, R[A0], 1);           /* lbu v0, DATA */
    LD(0x8005DF04u, V1, R[S0] + 0x44u, 1);
    RUN(0x8005DF08u, 3);                     /* nop; bnez v1; (delay) andi s2 */
    take = R[V1] != 0;
    R[S2] = R[V0] & 0xFFu;
    if (!take) {
        RUN(0x8005DF14u, 4);                 /* sra v1; v0 = 8; beq; (delay) v0 = 0x22 */
        R[V1] = (uint32_t)((int32_t)R[S2] >> 4);
        R[V0] = 8;
        take = R[V1] == R[V0];
        R[V0] = 0x22u;
        if (take) {
            ST(0x8005DF30u, R[A0] + 0xEu, 2, R[V0]);
            goto baud_set;
        }
    }
    ST(0x8005DF24u, R[A0] + 0xEu, 2, R[S1]);
    RUN(0x8005DF28u, 2);                     /* j; nop */
baud_set:
    RUN(0x8005DF34u, 1);
    R[V1] = HI_7;
    LD(0x8005DF38u, V1, ISTAT_SLOT, 4);
    RUN(0x8005DF3Cu, 1);
    LD(0x8005DF40u, V0, R[V1], 4);           /* lw v0, I_STAT */
    RUN(0x8005DF44u, 4);                     /* nop; andi; bnez; (delay) nop */
    R[V0] &= 0x80u;
    if (!R[V0]) {
        RUN(0x8005DF54u, 9);                 /* t1/a2/t2/t0 addresses; a3 = v1; lui a0 */
        R[T1] = T2_COUNT;
        R[A2] = T2_TARGET;
        R[T2] = 0x10000u;
        R[T0] = T2_MODE;
        R[A3] = R[V1];
        R[A0] = HI_RC2S;
        LD(0x8005DF78u, A0, RC2_START, 4);
        RUN(0x8005DF7Cu, 1);
        R[A1] = HI_RC2W;
        LD(0x8005DF80u, A1, RC2_WAIT, 4);
        for (;;) {
            SITE(0x8005DF84u);
            LD(0x8005DF84u, V0, R[T1], 2);   /* lhu v0, Timer2 */
            RUN(0x8005DF88u, 5);             /* nop; andi v1; sltu; beqz; (delay) nop */
            R[V1] = R[V0] & 0xFFFFu;
            R[V0] = R[V1] < R[A0];
            if (R[V0]) {                     /* wrapped */
                LD(0x8005DF9Cu, V0, R[A2], 2);
                RUN(0x8005DFA0u, 3);         /* nop; beqz; (delay) nop */
                if (R[V0]) {
                    LD(0x8005DFACu, V0, R[A2], 2);
                    RUN(0x8005DFB0u, 2);     /* j; (delay) addu v1 */
                    R[V1] = R[V0] + R[V1];
                } else {
                    RUN(0x8005DFB8u, 1);
                    R[V1] += R[T2];
                }
            }
            LD(0x8005DFBCu, V0, R[T0], 2);   /* lhu v0, mode */
            RUN(0x8005DFC0u, 4);             /* nop; andi; beqz; (delay) subu */
            R[V0] &= 0x200u;
            take = R[V0] == 0;
            R[V0] = R[V1] - R[A0];
            if (!take) {
                RUN(0x8005DFD0u, 3);         /* sltu; beqz; (delay) v0 = -2 */
                R[V0] = R[V0] < R[A1];
                take = R[V0] == 0;
                R[V0] = (uint32_t)-2;
                if (take) goto epilogue;
            }
            RUN(0x8005DFDCu, 5);             /* subu; srl; sltu; beqz; (delay) v0 = -2 */
            R[V0] = R[V1] - R[A0];
            R[V0] >>= 3;
            R[V0] = R[V0] < R[A1];
            take = R[V0] == 0;
            R[V0] = (uint32_t)-2;
            if (take) goto epilogue;
            LD(0x8005DFF0u, V0, R[A3], 4);   /* lw v0, I_STAT */
            RUN(0x8005DFF4u, 4);             /* nop; andi; beqz; (delay) nop */
            R[V0] &= 0x80u;
            if (R[V0]) break;
        }
    }
    LD(0x8005E004u, V1, R[S0] + 0xE8u, 1);
    RUN(0x8005E008u, 3);                     /* v0 = 8; beq; (delay) v0 = 2 */
    R[V0] = 8;
    take = R[V1] == R[V0];
    R[V0] = 2;
    if (!take) {
        RUN(0x8005E014u, 1);
        R[V1] = HI_7;
        LD(0x8005E018u, V1, STEP_INDEX, 4);
        RUN(0x8005E01Cu, 3);                 /* nop; bne; (delay) nop */
        if (R[V1] == R[V0]) {
            JAL(0x8005E028u, 0x8005FBA8u, leaf_fba8);
            for (;;) {
                SITE(0x8005E030u);
                JAL(0x8005E030u, 0x8005FBC8u, leaf_fbc8);
                RUN(0x8005E038u, 2);         /* beqz v0; (delay) nop */
                if (R[V0]) break;
            }
        }
    }
    RUN(0x8005E040u, 1);
    R[V0] = HI_7;
    LD(0x8005E044u, V0, SIO_SLOT, 4);
    RUN(0x8005E048u, 1);
    ST(0x8005E04Cu, R[V0], 1, R[S3]);        /* sb s3, DATA */
    LD(0x8005E050u, V0, R[S0] + 0x45u, 1);
    LD(0x8005E054u, V1, R[S0] + 0x44u, 1);
    RUN(0x8005E058u, 1);
    R[V0] += 1u;
    ST(0x8005E05Cu, R[S0] + 0x45u, 1, R[V0]);
    RUN(0x8005E060u, 3);                     /* v0 = 0xFF; beq; (delay) nop */
    R[V0] = 0xFFu;
    if (R[V1] != R[V0]) {
        LD(0x8005E06Cu, V1, R[S0] + 0x44u, 1);
        LD(0x8005E070u, V0, R[S0] + 0x3Cu, 4);
        RUN(0x8005E074u, 2);
        R[V0] += R[V1];
        ST(0x8005E07Cu, R[V0], 1, R[S2]);
    }
    LD(0x8005E080u, V1, R[S0] + 0x44u, 1);
    RUN(0x8005E084u, 2);
    R[V0] = R[S2];
    R[V1] += 1u;
    ST(0x8005E08Cu, R[S0] + 0x44u, 1, R[V1]);
epilogue:
    LD(0x8005E090u, RA, R[SP] + 0x20u, 4);
    LD(0x8005E094u, S3, R[SP] + 0x1Cu, 4);
    LD(0x8005E098u, S2, R[SP] + 0x18u, 4);
    LD(0x8005E09Cu, S1, R[SP] + 0x14u, 4);
    LD(0x8005E0A0u, S0, R[SP] + 0x10u, 4);
    RUN(0x8005E0A4u, 2);                     /* jr ra; (delay) addiu sp */
    R[SP] += 0x28u;
    return BFM_PAD_LEAF_DONE;
}

/* 8005F394 (rec = a0): the next byte to send for reply position
 * rec+0x45 - 3. Command 0 (rec+0x36): the actuator byte rec+0x28[i] for
 * i < rec+0x34 when its slot rec+0x57[i] (i < 6) is set, else 0. Command
 * 0x4D: rec+0x2C[i] for i < rec+0x35, else 0xFF. Other commands: rec+0x2C[i]
 * for i < rec+0x35, else 0. */
static int leaf_f394(const BfmPadLeafIo *io) {
    LD(0x8005F394u, V0, R[A0] + 0x45u, 1);
    LD(0x8005F398u, A1, R[A0] + 0x36u, 1);
    RUN(0x8005F39Cu, 3);                     /* nop; beqz a1; (delay) v1 = v0 - 3 */
    R[V1] = R[V0] - 3u;
    if (!R[A1]) {
        RUN(0x8005F3BCu, 3);                 /* slti; beqz; (delay) addu v0 */
        R[V0] = (int32_t)R[V1] < 6;
        {
            int skip = R[V0] == 0;
            R[V0] = R[A0] + R[V1];
            if (!skip) {
                LD(0x8005F3C8u, V0, R[V0] + 0x57u, 1);
                RUN(0x8005F3CCu, 3);         /* nop; beqz; (delay) v0 = 0 */
                skip = R[V0] == 0;
                R[V0] = 0;
                if (skip) goto done;
            }
        }
        LD(0x8005F3D8u, V0, R[A0] + 0x34u, 1);
        RUN(0x8005F3DCu, 4);                 /* nop; slt; beqz; (delay) v0 = 0 */
        R[V0] = (int32_t)R[V1] < (int32_t)R[V0];
        if (!R[V0]) { R[V0] = 0; goto done; }
        R[V0] = 0;
        LD(0x8005F3ECu, V0, R[A0] + 0x28u, 4);
        RUN(0x8005F3F0u, 2);
        R[V0] += R[V1];
        LD(0x8005F3F8u, V0, R[V0], 1);
        RUN(0x8005F3FCu, 2);                 /* j; nop */
        goto done;
    }
    RUN(0x8005F3A8u, 3);                     /* v0 = 0x4D; beq; (delay) nop */
    R[V0] = 0x4Du;
    if (R[A1] == R[V0]) {
        LD(0x8005F404u, V0, R[A0] + 0x35u, 1);
        RUN(0x8005F408u, 4);                 /* nop; slt; beqz; (delay) v0 = 0xFF */
        R[V0] = (int32_t)R[V1] < (int32_t)R[V0];
        if (!R[V0]) { R[V0] = 0xFFu; goto done; }
        R[V0] = 0xFFu;
        LD(0x8005F418u, V0, R[A0] + 0x2Cu, 4);
        RUN(0x8005F41Cu, 2);                 /* j F3F8; (delay) addu */
        R[V0] += R[V1];
        LD(0x8005F3F8u, V0, R[V0], 1);
        RUN(0x8005F3FCu, 2);
        goto done;
    }
    RUN(0x8005F3B4u, 2);                     /* j F424; nop */
    LD(0x8005F424u, V0, R[A0] + 0x35u, 1);
    RUN(0x8005F428u, 4);                     /* nop; slt; beqz; (delay) v0 = 0 */
    R[V0] = (int32_t)R[V1] < (int32_t)R[V0];
    if (!R[V0]) { R[V0] = 0; goto done; }
    R[V0] = 0;
    LD(0x8005F438u, V0, R[A0] + 0x2Cu, 4);
    RUN(0x8005F43Cu, 2);
    R[V0] += R[V1];
    LD(0x8005F444u, V0, R[V0], 1);
done:
    RUN(0x8005F448u, 2);                     /* jr ra; nop */
    return BFM_PAD_LEAF_DONE;
}

/* ---- dispatch ---------------------------------------------------------- */

static const BfmPadLeafCode kCode[] = {
    {0x8005FBA8u, 0x8005FBC8u, 0x11fd60caefca6122ull},
    {0x8005FBC8u, 0x8005FC68u, 0xb2959d851755bc88ull},
    {0x8005E0ACu, 0x8005E13Cu, 0x3485b5c4dd987592ull},
    {0x8005E13Cu, 0x8005E164u, 0xc59f9cc73ee539d7ull},
    {0x8005DCA0u, 0x8005DE78u, 0x10c88bc7cdcb8588ull},
    {0x8005DE78u, 0x8005E0ACu, 0x1396fde11b452334ull},
    {0x8005F394u, 0x8005F450u, 0x1bc0c280e78a5180ull},
};
enum { C_FBA8, C_FBC8, C_E0AC, C_E13C, C_DCA0, C_DE78, C_F394 };

static int index_of(uint32_t target) {
    unsigned i;
    for (i = 0; i < sizeof kCode / sizeof kCode[0]; ++i)
        if (kCode[i].start == target) return (int)i;
    return -1;
}

const BfmPadLeafCode *bfm_psyq_pad_leaf_code(uint32_t target, const BfmPadLeafCode **nested,
                                             unsigned *nested_count) {
    int i = index_of(target);
    unsigned n = 0;
    if (i < 0) return NULL;
    if (i == C_E0AC || i == C_DCA0 || i == C_DE78) nested[n++] = &kCode[C_FBC8];
    if (i == C_DE78) nested[n++] = &kCode[C_FBA8];
    *nested_count = n;
    return &kCode[i];
}

unsigned bfm_psyq_pad_leaf_depth(uint32_t target) {
    int i = index_of(target);
    return i == C_E0AC || i == C_DCA0 || i == C_DE78;
}

int bfm_psyq_pad_leaf(uint32_t target, const BfmPadLeafIo *io,
                      int (*peek32)(void *user, uint32_t address, uint32_t *value),
                      uint32_t *exit_pc) {
    uint32_t sio = 0, istat = 0;
    int i = index_of(target), result;
    if (i < 0 || !io || !io->r || !io->run || !io->load || !io->store || !io->entered ||
        !peek32 || !exit_pc)
        return BFM_PAD_LEAF_REFUSED;
    /* The SIO/IRQ routines dereference the two pointer slots; anything but the
     * hardware addresses PadInitDirect leaves there runs as retail words. */
    if (i == C_E0AC || i == C_E13C || i == C_DCA0 || i == C_DE78) {
        if (!peek32(io->user, SIO_SLOT, &sio) || sio != 0x1F801040u ||
            !peek32(io->user, ISTAT_SLOT, &istat) || istat != 0x1F801070u)
            return BFM_PAD_LEAF_REFUSED;
    }
    switch (i) {
    case C_FBA8: result = leaf_fba8(io); *exit_pc = 0x8005FBC0u; break;
    case C_FBC8: result = leaf_fbc8(io); *exit_pc = 0x8005FC60u; break;
    case C_E0AC: result = leaf_e0ac(io); *exit_pc = 0x8005E134u; break;
    case C_E13C: result = leaf_e13c(io); *exit_pc = 0x8005E15Cu; break;
    case C_DCA0: result = leaf_dca0(io); *exit_pc = 0x8005DE70u; break;
    case C_DE78: result = leaf_de78(io); *exit_pc = 0x8005E0A4u; break;
    default:     result = leaf_f394(io); *exit_pc = 0x8005F448u; break;
    }
    return result;
}

const BfmPadLeafApi bfm_psyq_pad_leaf_api = {
    bfm_psyq_pad_leaf_code, bfm_psyq_pad_leaf_depth, bfm_psyq_pad_leaf
};
