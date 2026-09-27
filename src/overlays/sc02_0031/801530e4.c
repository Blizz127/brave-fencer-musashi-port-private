/* SC02.CD FILE_031 / ov_SC02_031 retail span [801530E4,80153150).
 * Offset 0x2AF8C at overlay base 80128158. SHA256(span)=375a9c7f0aa8ce63bc1ee04954957fa9da0f3b8f90381b05f1ba1bda99eb66e9.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/801530e4.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"
extern s32 D_80062C04;
void func_80019064();
void func_80149020();
void func_801472C8();
void func_8014CBF8();
void func_801474EC();
void func_80155440();
void func_80146CA0();
typedef struct { u8 pad[0xDE]; u8 fDE; } T;
void func_801530E4(T *p) {
    func_80019064(&D_80062C04);
    func_80149020(p);
    func_801472C8(p);
    p->fDE = 0x40;
    func_8014CBF8(p);
    func_801474EC(p);
    func_80155440(p);
    func_80146CA0(p);
}
