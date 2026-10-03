# Windows shared patch review, 2026-10-03

Linux integration starts at `f53b4e93cc`. The standalone BIOS callback pointer
fix is accepted in `d52d99922a`: subtract the guest stack base before forming
the scratch-array pointer. Bounds checks and the resulting address are unchanged.
All supplied patch checksums, including the standalone patch, were verified.

The existing input BIOS callback probe passed with GCC and with Clang
`-fsanitize=undefined,bounds -fno-sanitize-recover=all`. The unmodified pytest
command fails compilation on an existing GCC `-Wclobbered` warning in
`lane_try`; the diagnostic GCC run downgraded that warning. The Clang run
downgraded the existing unused `kOverlaySc01_80128158Words` declaration warning.
Neither diagnostic run changed source or test files. These are bounded callback
tests, not runtime route or release qualification.

## Series 0001–0005: changes requested before integration

The series remains unapplied. Two concrete issues need a refreshed series:

1. Patch 0002 changes production identity functions to in-tree SHA-256, but
   leaves direct-link Python test builds on their old linkage. Forty-seven
   Python test files still mention `-lcrypto`; audit these and any other direct
   compilation of `boot_memory.c`, `bios_exception.c` or `disc_media.c`.
   Reproduction: invoke the existing `tests/test_boot_memory.py` setup with
   `ROOT` pointing to the proposed Windows worktree. Compilation succeeds,
   but `ctypes.CDLL` fails with `undefined symbol: bfm_plat_sha256_final`.
   Link `pc_port/platform/bfm_plat_sha256.c` (or the corresponding library)
   in affected probes and remove stale crypto linkage. Also audit probes
   that need the moved Linux host implementation. CTest's reported 38/38
   does not establish these Python harnesses pass.
2. Patch 0005 adds `docs/WINDOWS-PORT.md`, which already exists on the Linux
   branch. An isolated apply check confirms the path collision. Rebase that
   documentation change as a modification, preserving the existing audit
   history and current separate Windows-task ownership. Distinguish design
   from implemented and qualified behavior.

The supplied byte-identity and decision-equivalence evidence remains useful,
but is side-track evidence. Complete Linux review/build/probe checks and the
normal village/attract DEVOBS/RAM/PAD routes are still required after the
refreshed series. Packaging must audit the actual dependency closure before
removing its stale libcrypto bundle. No release is qualified or published by
this review, and the qualified r37/r38 packages remain unchanged.
