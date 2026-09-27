/* Exact retail word export for [8005CD48,8005CD98); EXE and assembly verified. */
#include "psx_types.h"

/* Byte-exact console-string emitter [8005CD48,8005CD98). */
#ifdef MUSASHI_NATIVE_CONSOLE_BINDING
extern void func_8005C388_native(s32, u8 *, s32 *, void *);
#define D_80074498 (fallback)
#define func_8005C388(value) \
    func_8005C388_native((value), classification, column, userdata)
#else
extern u8 D_80074498[];
extern void func_8005C388(s32);
#endif

#ifdef MUSASHI_NATIVE_CONSOLE_BINDING
void func_8005CD48_native(u8 *source, u8 *fallback, u8 *classification,
                          s32 *column, void *userdata) {
#else
void func_8005CD48(u8 *source) {
#endif
    if (!source)
        source = D_80074498;
    {
        u8 character;
        while ((character = *source++) != 0)
            func_8005C388(character);
    }
}

#ifdef MUSASHI_NATIVE_CONSOLE_BINDING
#undef D_80074498
#undef func_8005C388
#endif
