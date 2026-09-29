# Opening control port evidence (2026-09-29)

The handoff build reached scene 000b mode 8 at frame 640, then refused
Square0 at 80049334. Controls had not unlocked. These are interpreter
admission gaps; no run below uses MUSASHI_DEBUG_FORCE or forces player RAM.
The `mash` driver supplies Cross pad input for four of every thirty frames.

## Bounded admissions

- RGB0–RGB2 transfers, MAIN.CD member 0010 and SC01 member 77 identities
  are admitted from licensed instruction images (27c68f01d).
- Rotation and translation caller pairs in resident main code and member 77
  preserve member identity checks (4e339a008, cef5d9499).
- Square0's observed return address 8012bcac is admitted only under the
  member 77 identity. Its command is SQR, not MVMVA (eba1bfc3f).
- Flat triangle routine 8004a660, observed return address 8005652c,
  admits architectural COP2 transfers under two exact instruction-image
  digest windows (99c907683).
- Gouraud triangle dispatcher 8004b078, observed return address 80056600,
  uses two additional digest windows covering exactly 96 words
  (cef5d9499). Other libgte ranges retain their existing admission rules.

## Evidence

Real source fixtures execute InitGeom and the original library instructions.
Square0 checks the output vector (4, 9, 16) from (2, -3, 4) and wrong-member
refusal. Matrix fixtures check every rotation/translation control word and
wrong-member refusal. Rendering fixtures check coordinates, packet colors,
ordering-table links, reversed-winding rejection and mutated instruction-image
refusal with unchanged CPU/GTE state. All four focused source tests passed.
These fixtures establish semantics for their inputs; they do not establish
whole-game parity or control release.

Full optimized native run 10 passed Square0, then stopped at 8004a68c.
Run 11b passed the flat triangle admission, reached mode 8 frame 640, and
stopped at 8004b0a8. Logs are in the local scratch archive:
`bfm-codex-rerun-gte10-native-20260929/out.log` and
`bfm-codex-rerun-gte11b-native-20260929/out.log`.
Control release remains unverified pending the next full run.

## Build and launcher

Native lane ON, RelWithDebInfo, Linux x86_64. Runtime RUNPATH is
`$ORIGIN/lib:$ORIGIN`, with runtime libraries next to the executable.
The launcher bundle contains no BIOS, disc image or game data. Owner data
must supply `files/SLUS_007.26`, `disc.cue` and `disc.bin` under the configured
disc directory. Legion Go hardware remains untested.
