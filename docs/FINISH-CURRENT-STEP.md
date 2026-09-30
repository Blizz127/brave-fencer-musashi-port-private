# Finish Current Step (Port Dev Menu, spec section 7a): BFM plan

Status (2026-09-30): planned. The recording side is in place; no step is
offered yet.

## What it does

Finish Area ▸ **Finish Current Step** completes the story step the player is
on (for example "take the sword from the Spiral Tower"). It then moves
Musashi to where the next step happens, using the game's own exit request.
It can be used again and again. Only verified steps are offered.

## The game state involved

All of these addresses are already used by the port (docs/PC-PORT.md, "Port
Dev Menu"; the warp research notes):

| What | Where |
|---|---|
| scenario progress counter | `u32 80078E80`; area milestones 10 / 200 / 600 / 900 / 1200 |
| story flags | 512 bits at `800AE648`; flag n is byte n/8, bit n%8; set with `func_80029124` |
| script vars | 256 bytes at `800BA1B8`; inventory slots are vars 0x2F..0x3A |
| location / entrance | `800B9A08` / `800AE6BE` |
| moving | the warp: the attract demo's exit record written to `80078E50`, then `800AE6B0` |

## 1. Recording real step deltas

A step's completion delta must come from a real playthrough or from the
game's own debug presets (spec section 7), never from a guess.

- **Route journal.** With `BFM_ROUTE_JOURNAL` set, the port appends one JSON
  line per room entry (`"event":"enter"`) and one per change of the scenario
  counter (`"event":"progress"`). Each line holds the location, the
  entrance, the counter, all 512 flags as hex and all 256 script vars as
  hex. `launch.sh` points it at `~/.local/state/bfm-port/route.jsonl`, so
  the owner's normal play records the real route. The file stays on the
  owner's machine and is never committed. The step table only takes the
  small flag/var/counter differences between consecutive steps, not saved
  RAM.
- The same events appear in the run log as `ROUTE enter` / `ROUTE progress`
  lines, with digests only.
- **Seeds from the game's own data.** The debug menu's AREA presets (the
  Finish Area work) give area-level checkpoints. Their values are decoded
  from the player's own disc at run time, never shipped.

## 2. The step table

Each step is a row: `{id, chapter/area, short name, entry condition, delta,
next location + entrance}`.

- **Entry condition:** the counter value plus the one or two flags that
  first change at that step, read from the journal. It identifies the
  current step from live state.
- **Delta:** the flags set or cleared, the vars changed and the counter,
  between this step's entry and the next step's entry in the journal.
  Stats, items and money are handled per the section 7 rules. Values are
  never lowered unless the recorded route does so.
- **Next location:** where the journal shows the player entering the next
  step's room, with its entrance.
- **Names:** our own short names. Public walkthroughs were used for order
  and naming only (credited as "walkthrough references"); no guide text is
  copied.

The table is generated from the journal by a script, and reviewed.

## 3. Behaviour

1. Match the live counter and flags against the entry conditions to find
   the current step. If there is no match, refuse ("step not recognised").
2. At the warp's safe point (gameplay mode 9, room live, player in control
   and idle, no exit pending), apply the delta through the game's own flag
   and var setters' layout.
3. Take the game's exit request to the next step's location and entrance.
   The existing warp mechanism waits, sends, then confirms arrival.
4. Show "finished: <step>, now: <next step>" and log both. The save warning
   (spec section 9) applies.

## 4. Verification

A sweep job per step, run on the runners, headless:

1. Start a fresh game.
2. Apply steps 1..k-1 through this feature.
3. Check that step k's room is reached and idles without a refusal, and
   that its next trigger fires: the next `ROUTE progress` or `enter` event
   the journal predicts.

Only steps that pass are listed (VERIFIED n/m in the report). Unverified
steps stay hidden.

## 5. Order of work

1. Collect a real journal for Chapter 1, from 3005 to the Steam Knight to
   the castle (the owner's own play, or a scripted route if one becomes
   possible).
2. Write the generator for the step table, and the detection.
3. Enable "Finish Current Step" for the verified Chapter 1 steps.
4. Extend chapter by chapter as journals come in.
