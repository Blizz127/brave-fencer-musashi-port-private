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

## In-game probe boundary

The initial 25-second village-interior probes ended before their warps arrived
and provide no menu acceptance evidence. Longer isolated runs reached the
target interiors. Screenshots identify the bakery in 2015, a grocery-style
shop in 2017, the pawnshop in 2018, church in 2019, and tavern in 201A.
Room 2016 remains the inn candidate. Several shop menu labels render as
colored bars while dialogue and HUD text can be readable; this is a separate
visible rendering issue, not evidence of a card error.

Runner `20260930-153221-bfm-r31-inn-save-859999` rebuilt the source of
commit `35e894d409`, reached 2016, and executed all nine input-script steps
(Cross taps with successive Down selections). It stopped cleanly after
240 seconds. The interface remained in a dialogue state; **no BIOS card
operation was called**. Captured RAM has game card state `800760AC = 0`,
request-stack index `80072A34 = FFFFFFFF` (idle), and no published result.
The card still has fifteen free directory entries and zero file-data bytes.
Thus the probe did not create a game save and did not test title Continue.
The cause of the dialogue/menu boundary is not yet established. In particular,
this fresh-New-Game warp does not establish the story prerequisites of a
normal Chapter 1 visit. It is not appropriate to infer a BIOS failure from it.

The final candidate binary is SHA-256
`cdf6e0f9d37d66fdab84a44e5d71caf6ddb9b3b92f2fafd09e37477a92011162`;
the fetched binary matches the runner hash. Evidence is in the private
`release-staging/bfm-r31-memcard/inn-evidence/` directory, including the input
script, log, screenshots, card image, and 2 MiB guest RAM. Earlier menu jobs
are `20260930-151612-bfm-r31-save-menu-557740`,
`20260930-151905-bfm-r31-save-menu-long-607227`, and
`20260930-152210-bfm-r31-find-save-menu-673970`. They have finished; do not
redispatch them as if they were interrupted.

## Remaining acceptance

Saving through an actual save-point menu, quitting, cold title Continue, and
comparing location/items/time have **not passed yet**. Native boot tests did
not exercise those menu interactions. Card-disabled full trace parity, any
existing quicksave path, the complete r31 gate, and packaging/publication are
also pending. One-hit kills, progression assists, movement speed, and the
graphics follow-up retain their existing separate scope. Nothing in these
results establishes Chapter 1 milestone completion.

Next: establish a valid inn/Record interaction and inspect its guest state
before extending BIOS bindings. No reliable save/title-load completion ETA
can be given from the present probe. A search of `pc_port/`, tests, the launch
wrapper, and `PC-PORT.md` found no existing quicksave/savestate implementation
to regress; that is a search result, not a compatibility claim for other tools.
