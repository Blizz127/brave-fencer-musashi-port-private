/* SC02.CD FILE_031 / ov_SC02_031 retail span [80136C90,80136D00).
 * Offset 0xEB38 at overlay base 80128158. SHA256(span)=46e38c23cfbf5f77d846613ff5c9e843318e0cab00a433a4ee10b8efbc760562.
 * Same shape as the registry-verified MAIN member 0012 carve with only the
 * listed data references retargeted for this member: D_80182F70->D_801A3488.
 * Oracle MATCH re-earned on this file; Not MAIN10.
 */
#include "psx_types.h"
typedef struct { u8 b[10]; } S;
extern S D_801A3488;
void func_8001534C();
void func_80136C90(void) {
    S tmp;
    tmp = D_801A3488;
    func_8001534C(0, &tmp, 0x78, 0x10, 0, 0);
}
