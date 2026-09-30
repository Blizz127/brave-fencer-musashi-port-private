# Native memory-card implementation and verification

The r31 candidate implements the BIOS `bu00:` file device over a port-owned
128 KiB card image. The game's Sony libmcrd request handlers and save/load
state machine continue to execute as guest code. The serial card interface
still answers absent; the file-device calls are handled at the BIOS seam.
This is not a complete serial memory-card emulation.

The image is `bfm_card0.mcd` in `BFM_SAVE_DIR`, otherwise the configured
`[storage] save_dir` when it differs from the legacy `saves` default,
otherwise `$XDG_STATE_HOME/bfm-port` or `$HOME/.local/state/bfm-port`.
The default contains a factory-formatted empty card. Port 1 remains absent.
Game save slots share the game's own file on card 0; no existing retail card
is imported. `MUSASHI_MEMCARD=0` keeps both ports absent and leaves card files
alone. Builds without the platform storage backend also report absent.

Writes use the platform's temporary-file/rename store. Read errors and
wrong-sized existing files stop startup instead of allowing a fresh card
to overwrite the file. New directories are created as needed. This does
not claim durability against power loss or multiple concurrent game writers.

The [PSX-SPX card-format reference](https://raw.githubusercontent.com/psx-spx/psx-spx.github.io/master/docs/controllersandmemorycards.md)
specifies directory links as the next block number minus one. The inherited
draft used physical block numbers; the candidate fixes creation, traversal,
and erase. The probe checks the on-disk link bytes independently. The guest
`_card_write_file` at `80060BEC` uses BIOS `open(0x8001)`, so the device accepts
both read and write through that descriptor rather than enforcing POSIX modes.

Other checks cover negative seeks, exhausted descriptors without a file-create
side effect, whole-transfer RAM validation, cross-block transfers, and bounded
erase traversal. Async completions are queued until VBlank and dispatched to
the card event classes; compatibility with the full save menu is still pending.

## Verification on September 30

- Card and platform pytest run: 37 passed, 2 optional backend skips.
- Card, existing BIOS card, backup-unit, and event pytest run: 14 passed.
- Synthetic save bytes written through the BIOS device and platform disk
  backend, then read by a second process, match exactly.
- Native boot source compiles; pre-existing PsyCross/OpenSSL/path warnings remain.
- Guarded blizzpc build succeeded. Fresh card boot reached rooms 3005 and
  3008; a separate boot loaded the disk image; absent-card boot reached the
  same rooms without modifying that image. All stopped cleanly on timeout.
- A wrong-sized card was preserved. Its first native check exposed a missing
  PsyCross shutdown on the new error path. After fixing that path, the isolated
  check returned 2 cleanly and preserved the file.

Evidence is in `/home/blizz/release-staging/bfm-r31-memcard/`, with runner jobs
`20260930-150752-bfm-r31-memcard-gate-356392`,
`20260930-151035-bfm-r31-memcard-remaining-423266`, and
`20260930-151451-bfm-r31-memcard-cleanup-516160`. The first gate stopped on
an incorrect harness log-field assertion; the second exposed the cleanup bug;
the third passed the corrected cleanup check. The last binary's SHA-256 is
`845bec954a8736b8f5841e54115e7f7d327309cf239a482be933b203d78292d5`.
That binary predates the final overlong-filename rejection added to the probe;
it is boot evidence for the earlier snapshot, not a final package gate.

## Remaining acceptance

Saving through an actual save-point menu, quitting, cold title Continue, and
comparing location/items/time have **not passed yet**. Native boot tests did
not exercise those menu interactions. Card-disabled full trace parity, any
existing quicksave path, the complete r31 gate, and packaging/publication are
also pending. One-hit kills, progression assists, movement speed, and the
graphics follow-up retain their existing separate scope. Nothing in these
results establishes Chapter 1 milestone completion.
