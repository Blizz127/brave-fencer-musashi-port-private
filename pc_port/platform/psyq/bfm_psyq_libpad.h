/* libpad SIO exchange leaves as native code (stage S3a).
 *
 * The pad driver's VBlank handler (8005D734) runs in the port's input BIOS
 * callback frame (mips_formatter.c, musashi_boot_execute_input_bios_callback),
 * an admitted-word interpreter of its own that never consults the native
 * lane. The frame dispatches the seven leaves below to this native code once
 * it has accepted the exact call edge and stepped the delay slot. The rest of
 * the driver (the handler, 8005DBD8, the five step bodies, the TAP/config
 * code, 8005F830/8005FA94) stays interpreted.
 *
 *   8005FBA8  RC2 wait start: latch Timer2 and the wait length
 *   8005FBC8  RC2 wait check: elapsed Timer2 ticks >= wait
 *   8005E0AC  clear the SIO ACK latch, wait for /ACK release, CTRL |= 0x10
 *   8005DCA0  one pipelined SIO byte (select byte when a1 < 0)
 *   8005DE78  one SIO byte with the inline Timer2 ACK timeout
 *   8005E13C  wait for SIO RX ready
 *   8005F394  next transmit byte from the record's actuator/config buffers
 *
 * Owner-written from the disassembly's behaviour; no Sony source or SDK
 * material. Each leaf performs the same guest loads and stores, at the same
 * addresses and in the same order, as the retail words, and reports every
 * retail instruction it stands for to the frame (run/load/store below). The
 * frame charges each one exactly as its interpreter would (one budget unit,
 * then 2 cycles, +1 for a load or store), so device time, the per-byte SIO
 * timing, Timer2 and I_STAT edges match the interpreted words cycle for
 * cycle. The leaves leave the register file as the retail words do. */
#ifndef BFM_PSYQ_LIBPAD_H
#define BFM_PSYQ_LIBPAD_H

#include <stdint.h>

typedef struct BfmPadLeafIo {
    void *user;
    uint32_t *r;   /* the frame CPU's 32 GPRs, read and written in place */
    /* `count` register-only retail instructions starting at `pc` retire. */
    int (*run)(void *user, uint32_t pc, unsigned count);
    /* One retail LBU/LHU/LW (width 1/2/4, zero-extended) or SB/SH/SW at `pc`. */
    int (*load)(void *user, uint32_t pc, uint32_t address, unsigned width, uint32_t *value);
    int (*store)(void *user, uint32_t pc, uint32_t address, unsigned width, uint32_t value);
    /* A retail JAL at `call` into another leaf, entered at `target`. */
    void (*entered)(void *user, uint32_t target, uint32_t call);
    /* Opt-in poll-site counter (MUSASHI_TRACE_PAD); may be NULL. */
    void (*site)(void *user, uint32_t pc);
} BfmPadLeafIo;

/* Guest word range [start, end) of a leaf and the FNV-1a 64 digest of its
 * retail words (little-endian bytes), checked by the frame before a call. */
typedef struct BfmPadLeafCode {
    uint32_t start, end;
    uint64_t digest;
} BfmPadLeafCode;

enum {
    BFM_PAD_LEAF_REFUSED = 0,  /* nothing happened; the retail words run */
    BFM_PAD_LEAF_DONE = 1,     /* returned through `jr ra` at *exit_pc */
    BFM_PAD_LEAF_FAULT = -1    /* an access/budget/clock refusal mid-leaf */
};

/* The leaf at `target`, or NULL. `nested` receives the leaves it calls
 * (at most 2), each of which must also match its digest. */
const BfmPadLeafCode *bfm_psyq_pad_leaf_code(uint32_t target, const BfmPadLeafCode **nested,
                                             unsigned *nested_count);
/* Nesting depth the leaf adds to the frame's call stack (0 or 1). */
unsigned bfm_psyq_pad_leaf_depth(uint32_t target);
/* Runs the leaf at `target`. `peek32` is a side-effect-free RAM read used
 * only for the refusal checks before the first retail instruction. */
int bfm_psyq_pad_leaf(uint32_t target, const BfmPadLeafIo *io,
                      int (*peek32)(void *user, uint32_t address, uint32_t *value),
                      uint32_t *exit_pc);

/* The three entry points as one table, so the port core (mips_formatter.c)
 * takes them by pointer: native_boot installs it for MUSASHI_PSYQ_LANE class
 * "pad" (musashi_input_pad_leaves_set), and NULL keeps every leaf retail. */
typedef struct BfmPadLeafApi {
    const BfmPadLeafCode *(*code)(uint32_t, const BfmPadLeafCode **, unsigned *);
    unsigned (*depth)(uint32_t);
    int (*leaf)(uint32_t, const BfmPadLeafIo *,
                int (*)(void *, uint32_t, uint32_t *), uint32_t *);
} BfmPadLeafApi;
extern const BfmPadLeafApi bfm_psyq_pad_leaf_api;

/* Test hook (tests/input_pad_leaf_probe.c): a nonzero value selects one
 * deliberate break so the differential can show it fails. Never set by the
 * port. */
extern int bfm_psyq_pad_test_break;

#endif
