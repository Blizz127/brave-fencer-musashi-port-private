/* musashi_strict.h — strict-native abort reporting.
 *
 * A MUSASHI_STRICT_NATIVE build (CMake option MUSASHI_STRICT_NATIVE) refuses
 * every remaining entry into the MIPS interpreter: instead of executing the
 * retail words from the user's disc, the seam prints this diagnostic and
 * aborts. That makes "interpreted a word" impossible to miss: the process
 * dies with the seam id, the C routine entered, the best-known guest PC and a
 * host backtrace, instead of silently falling back like the hybrid build.
 *
 * This is an enforcement/acceptance tool for the interpreter-free native
 * slice, not a playable configuration: until the slice conversion is done a
 * strict build aborts early by design. The seam catalog is in
 * docs/STRICT-NATIVE-BUILD.md. Drafted by the GLM lane (task 52098a9467c4).
 */
#ifndef MUSASHI_STRICT_H
#define MUSASHI_STRICT_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Prints "native_boot: STRICT_INTERPRETER_ENTRY seam=<seam> routine=<routine>
 * guest_pc=<pc>" plus a host backtrace to stderr, then abort(). Never
 * returns. seam is a short stable id ("boot_entry", "cd_irq", ...); routine
 * is __func__ of the interpreter entry; guest_pc is the guest address the
 * seam was about to interpret (0 when the seam has no single such address).
 */
#if defined(__GNUC__) || defined(__clang__)
__attribute__((noreturn))
#endif
void musashi_strict_abort(const char *seam, const char *routine, uint32_t guest_pc);

/* Optional diagnostics hook, run once by musashi_strict_abort just before
 * abort() (native_boot registers its render stats + VRAM dump here). */
extern void (*musashi_strict_pre_abort)(void);

#ifdef __cplusplus
}
#endif

#endif /* MUSASHI_STRICT_H */
