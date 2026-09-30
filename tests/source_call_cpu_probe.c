#include "musashi_boot_memory.h"
#include <stddef.h>
#include <assert.h>
#include <stdio.h>
#include <string.h>
static int irq_testevent(void *userdata, int32_t handle, int32_t *result) {
    unsigned *calls = userdata;
    ++*calls;
    if (handle != (int32_t)0xf1000008u) return 0;
    *result = 0;
    return 1;
}
static int card_info(void *userdata, uint32_t target, const uint32_t *registers,
                     int32_t *result) {
    unsigned *calls = userdata;
    ++*calls;
    assert(target == 0x80062258u || target == 0x80062268u);
    assert(registers[4] == 0 && registers[5] == 0xabcdef01u);
    *result = 7;
    return 1;
}

static void source_call_sink(void *userdata, const uint8_t *bytes, int32_t size) {
    (void)userdata; (void)bytes; (void)size;
}

static void probe_source_call_arguments(void) {
    static MusashiBootMemory memory;
    MusashiCallbackDevice callback = {0};
    MusashiEventDevice events = {0};
    MusashiCdDevice cd = {0};
    MusashiStartupPrefixDevice devices = {0};
    MusashiResetGraphPrefixStop stop = {0};
    int32_t result = 0x12345678;
    unsigned calls = 0;
    events.userdata = &calls;
    events.b0_0b = irq_testevent;
    devices.callback = &callback;
    devices.event = &events;
    /* Retail name builder exercises its guarded merge pair at all alignments. */
    memcpy(musashi_boot_ram_span(&memory, 0x8007472cu, 6), "bu00:", 6);
    for (unsigned offset = 0; offset < 4; ++offset) {
        uint32_t destination = 0x80078000u + offset;
        assert(musashi_boot_execute_source_call(&memory, &devices, 0x80061770u,
            0x10u, destination, &result, source_call_sink, NULL, &stop)
            == MUSASHI_RESETGRAPH_PREFIX_COMPLETE);
        assert(memcmp(musashi_boot_ram_span(&memory, destination, 6), "bu10:", 6) == 0);
    }
    /* Actual TestEvent BIOS leaf consumes the supplied a0 and returns v0. */
    assert(musashi_boot_execute_source_call(&memory, &devices, 0x8005cea8u,
        0xf1000008u, 0xabcdef01u, &result, source_call_sink, NULL, &stop)
        == MUSASHI_RESETGRAPH_PREFIX_COMPLETE);
    assert(calls == 1 && result == 0);
    cd.userdata = &calls;
    cd.memcard_call = card_info;
    devices.cd = &cd;
    assert(musashi_boot_execute_source_call(&memory, &devices, 0x80062258u,
        0, 0xabcdef01u, &result, source_call_sink, NULL, &stop)
        == MUSASHI_RESETGRAPH_PREFIX_COMPLETE);
    assert(calls == 2 && result == 7);
    assert(musashi_boot_execute_source_call(&memory, &devices, 0x80062268u,
        0, 0xabcdef01u, &result, source_call_sink, NULL, &stop)
        == MUSASHI_RESETGRAPH_PREFIX_COMPLETE);
    assert(calls == 3 && result == 7);
    result = 0x12345678;
    assert(musashi_boot_execute_source_call(&memory, &devices, 0x8005cea8u,
        0xf1000009u, 0, &result, source_call_sink, NULL, &stop)
        != MUSASHI_RESETGRAPH_PREFIX_COMPLETE);
    assert(calls == 4 && result == 0x12345678);
    assert(musashi_boot_execute_source_call(&memory, &devices, 0x8005cea8u,
        0xf1000008u, 0, NULL, source_call_sink, NULL, &stop)
        == MUSASHI_RESETGRAPH_PREFIX_INVALID_INPUT);
}

int main(void) { probe_source_call_arguments(); puts("SOURCE CALL: argument, return value and refusal checks passed"); return 0; }
