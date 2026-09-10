/* SC02.CD FILE_031 / ov_SC02_031 retail span [8013D330,8013D3D4).
 * Offset 0x151D8 at overlay base 80128158. SHA256(span)=5e5b717e23fb160c7dc61abfc172e672c123d714ee306c84915b61e57e71c589.
 * Druthulu shared/ov func_8013D330__3ba2802e donor shape with the six
 * counters and the flag retargeted to the SC02 slot; 41/41 words -O2 -G0.
 * Not MAIN10.
 */
#include "psx_types.h"

extern u8 D_801A5872;
extern u8 D_801A58E6;
extern u8 D_801A579A;
extern u8 D_801A5854;
extern u8 D_801A5778;
extern u8 D_801A5799;
extern s32 D_801A5858;

void func_8013D330(void) {
    if ((D_801A5872 & 0xff) != D_801A58E6) {
        D_801A5872 = ((D_801A5872 & 0xff) < D_801A58E6) ? (D_801A5872 + 1) : (D_801A5872 - 1);
    }
    if ((D_801A579A & 0xff) != D_801A5854) {
        D_801A579A = ((D_801A579A & 0xff) < D_801A5854) ? (D_801A579A + 1) : (D_801A579A - 1);
    }
    if ((D_801A5778 & 0xff) != D_801A5799) {
        D_801A5778 = ((D_801A5778 & 0xff) < D_801A5799) ? (D_801A5778 + 1) : (D_801A5778 - 1);
    }
    D_801A5858 = 1;
}
