#include "../pc_port/mips_formatter.c"
#include <assert.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char **argv) {
    static MusashiBootMemory memory;
    const unsigned char data[9] = {1,2,3,4,5,6,7,8,9};
    for (unsigned source_offset = 0; source_offset < 4; ++source_offset) {
        for (unsigned destination_offset = 0; destination_offset < 4; ++destination_offset) {
            FormatterCpu cpu = {0};
            uint32_t source = 0x80078000u + source_offset;
            uint32_t destination = 0x80078100u + destination_offset;
            memcpy(musashi_boot_ram_span(&memory, source, 9), data, 9);
            memset(musashi_boot_ram_span(&memory, destination, 9), 0, 9);
            cpu.pc = 0x8002b50cu; cpu.npc = cpu.pc + 4u;
            cpu.r[6] = source; cpu.r[7] = destination;
            for (unsigned n = 0; n < 10; ++n) assert(formatter_step(&memory, &cpu));
            assert(cpu.pc == 0x8002b534u && !cpu.merge_pending);
            assert(memcmp(musashi_boot_ram_span(&memory, destination, 9), data, 9) == 0);
        }
    }
    for (unsigned restore = 0; restore < 2; ++restore) {
        for (unsigned source_offset = 0; source_offset < 4; ++source_offset) {
            for (unsigned destination_offset = 0; destination_offset < 4; ++destination_offset) {
                FormatterCpu cpu = {0};
                unsigned char data96[96];
                uint32_t source = 0x80078000u + source_offset;
                uint32_t destination = 0x80078200u + destination_offset;
                for (unsigned n = 0; n < sizeof(data96); ++n) data96[n] = (unsigned char)(n * 7 + 3);
                memcpy(musashi_boot_ram_span(&memory, source, 96), data96, 96);
                memset(musashi_boot_ram_span(&memory, destination, 96), 0, 96);
                cpu.pc = restore ? 0x80029a28u : 0x80029878u;
                cpu.npc = cpu.pc + 4u;
                cpu.r[8] = restore ? destination : source;
                cpu.r[7] = (restore ? source : destination) - 0x27cu;
                for (unsigned n = 0; n < 240; ++n) assert(formatter_step(&memory, &cpu));
                assert(cpu.pc == (restore ? 0x80029a50u : 0x800298a0u) && !cpu.merge_pending);
                assert(memcmp(musashi_boot_ram_span(&memory, destination, 96), data96, 96) == 0);
            }
        }
    }
    assert(argc == 2);
    FILE *overlay = fopen(argv[1], "rb");
    if (!overlay) { fputs("MAIN12 owner-local image required\n", stderr); return 77; }
    assert(fseek(overlay, 0x28000, SEEK_SET) == 0);
    assert(fread(musashi_boot_ram_span(&memory, 0x80128158u, 385024u),
                 1, 385024u, overlay) == 385024u);
    fclose(overlay);
    g_fetch_memory = &memory;
    g_overlay_sc01_0000_words = sc01_entry_matches(&memory);
    assert(g_overlay_sc01_0000_words && g_sc01_code == kOverlayMain12CodeWords);
    /* Title enters below the normal entry: exercise lazy identification. */
    g_overlay_sc01_0000_words = 0;
    overlay_changed();
    FormatterCpu cpu = {0};
    uint32_t word;
    cpu.pc = 0x8017c080u;
    assert(formatter_fetch(&memory, &cpu, &word));
    uint8_t *entry = musashi_boot_ram_span(&memory, 0x80128158u, 1);
    *entry ^= 1u;
    g_overlay_sc01_0000_words = sc01_entry_matches(&memory);
    assert(!g_overlay_sc01_0000_words);
    overlay_changed();
    assert(!formatter_fetch(&memory, &cpu, &word));
    puts("SAVE COPIES: all alignments passed; MAIN12 identity/mutation checked");
    return 0;
}
