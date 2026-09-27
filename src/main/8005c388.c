/* Exact retail word export for [8005C388,8005C49C); EXE and assembly verified. */
#include "psx_types.h"

/* Byte-exact console output [8005C388,8005C43C). */
#ifdef MUSASHI_NATIVE_CONSOLE_BINDING
typedef void (*MusashiConsoleSink)(void *userdata, const u8 *bytes, s32 length);
extern void musashi_native_console_sink(void *, const u8 *, s32);
#define D_800728A9 (classification)
#define D_80078978 (*column)
#define func_8005CF38(fd, bytes, length) \
    musashi_native_console_sink(userdata, (bytes), (length))
#define func_8005C388(value) \
    func_8005C388_native((value), classification, column, userdata)
#else
extern u8 D_800728A9[];
extern s32 D_80078978;
extern void func_8005CF38(s32, const void *, s32);
#endif

#ifdef MUSASHI_NATIVE_CONSOLE_BINDING
void func_8005C388_native(s32 value, u8 *classification, s32 *column,
                          void *userdata) {
#else
void func_8005C388(s32 value) {
#endif
    u8 character = value;
    switch (character) {
    case '\n':
        func_8005C388('\r');
        D_80078978 = 0;
        break;
    case '\t':
        do {
            func_8005C388(' ');
        } while (D_80078978 & 7);
        return;
    default:
        if (D_800728A9[character] & 0x97)
            D_80078978++;
    }
    func_8005CF38(1, &character, 1);
}

#ifdef MUSASHI_NATIVE_CONSOLE_BINDING
#undef D_800728A9
#undef D_80078978
#undef func_8005CF38
#undef func_8005C388
#endif
