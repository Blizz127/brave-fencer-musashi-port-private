/* PsyCross-backed Psy-Q wrappers (status PSYCROSS in bfm_psyq_compat.def).
 * Build with -DBFM_PLAT_WITH_PSYCROSS, C11, -include assert.h and
 * -I tools/third_party/psycross/include. Only stateless functions are here:
 * PsyCross's GTE keeps its own register file, separate from the guest cop2
 * state the interpreter uses. */
#include "bfm_psyq_compat.h"

#include <psx/types.h>
#include <psx/libgte.h>

int bfm_psyq_ratan2(uint32_t *r) {
    r[2] = (uint32_t)ratan2((int)(int32_t)bfm_psyq_arg(r, 0), (int)(int32_t)bfm_psyq_arg(r, 1));
    return 1;
}
