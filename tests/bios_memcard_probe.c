/* Standalone probe for the BIOS memory-card file device: a fresh card is
 * formatted and empty; create/write/read/lseek/close round-trip through
 * guest RAM; firstfile/nextfile enumerate; erase frees; card_info reports a
 * new card once, then IoEnd; completions are delivered to enabled events of
 * both classes at VBlank; persistence is called after every change. */
#include "musashi_bios_events.h"
#include "musashi_bios_memcard.h"
#include "musashi_boot_memory.h"
#include "bfm_plat_storage.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CHECK(cond) do { if (!(cond)) { fprintf(stderr, "FAIL %s:%d %s\n", __FILE__, __LINE__, #cond); return 1; } } while (0)

static MusashiBootMemory *g_memory;
static unsigned g_persists;
static uint32_t g_executed[16];
static unsigned g_nexec;
static uint8_t g_saved[MUSASHI_MEMCARD_SIZE];
static int g_disk_persist;

static int persist_cb(void *userdata, const uint8_t *image, size_t size) {
    (void)userdata;
    if (size != MUSASHI_MEMCARD_SIZE) return 0;
    if (g_disk_persist && bfm_plat_memcard_save(0, image, size) != BFM_PLAT_OK) return 0;
    memcpy(g_saved, image, size);
    g_persists++;
    return 1;
}

static int execute_cb(void *userdata, uint32_t target) {
    (void)userdata;
    if (g_nexec < 16) g_executed[g_nexec++] = target;
    return 1;
}

static void guest_string(uint32_t address, const char *s) {
    uint8_t *p = musashi_boot_ram_span(g_memory, address, strlen(s) + 1);
    memcpy(p, s, strlen(s) + 1);
}

int main(int argc, char **argv) {
    static MusashiBiosMemcard mc;
    static MusashiBiosEvents events;
    int32_t r, fd, h_sw, h_hw;
    uint8_t *buf;
    unsigned i;
    const uint32_t NAME = 0x801ff000u, DIRENT = 0x801ff100u, BUF = 0x80100000u;

    g_memory = calloc(1, sizeof *g_memory);
    CHECK(g_memory);
    if (argc == 3) {
        CHECK(bfm_plat_memcard_set_dir(argv[1]) == BFM_PLAT_OK);
        musashi_bios_memcard_init(&mc, 1);
        guest_string(NAME, "bu00:BASLUS-00726MUSASHI");
        buf = musashi_boot_ram_span(g_memory, BUF, 0x300);
        if (strcmp(argv[2], "write") == 0) {
            g_disk_persist = 1;
            mc.persist = persist_cb;
            CHECK(musashi_bios_memcard_open(&mc, g_memory, NAME, (1u << 16) | 0x200u, &fd) && fd >= 0);
            CHECK(musashi_bios_memcard_close(&mc, fd, &r));
            CHECK(musashi_bios_memcard_open(&mc, g_memory, NAME, 2u, &fd) && fd >= 0);
            for (i = 0; i < 0x300; i++) buf[i] = (uint8_t)(i * 7u);
            CHECK(musashi_bios_memcard_lseek(&mc, fd, 0x480, 0, &r));
            CHECK(musashi_bios_memcard_write(&mc, g_memory, fd, BUF, 0x300, &r) && r == 0x300);
        } else {
            CHECK(strcmp(argv[2], "read") == 0);
            CHECK(bfm_plat_memcard_load(0, g_saved, sizeof g_saved) == BFM_PLAT_OK);
            CHECK(musashi_bios_memcard_load_image(&mc, g_saved, sizeof g_saved));
            CHECK(musashi_bios_memcard_open(&mc, g_memory, NAME, 1u, &fd) && fd >= 0);
            CHECK(musashi_bios_memcard_lseek(&mc, fd, 0x480, 0, &r));
            CHECK(musashi_bios_memcard_read(&mc, g_memory, fd, BUF, 0x300, &r) && r == 0x300);
            for (i = 0; i < 0x300; i++) CHECK(buf[i] == (uint8_t)(i * 7u));
        }
        CHECK(musashi_bios_memcard_close(&mc, fd, &r));
        puts("bios_memcard disk roundtrip ok");
        free(g_memory);
        return 0;
    }
    musashi_bios_events_init(&events);
    musashi_bios_memcard_init(&mc, 1);
    mc.persist = persist_cb;
    CHECK(musashi_bios_memcard_is_formatted(mc.image));
    CHECK(mc.image[127] == ('M' ^ 'C'));
    CHECK(mc.image[128] == 0xa0 && mc.image[128 + 127] == 0xa0);
    CHECK(musashi_bios_memcard_install_device_table(g_memory));
    CHECK(musashi_boot_ram_span(g_memory, 0x80000150u, 4)[0] == 0x00);
    CHECK(musashi_boot_ram_span(g_memory, 0x80000150u, 4)[1] == 0xe0);

    /* Events: one Sw IoEnd and one Hw IoEnd, mode 0x1000 with callbacks. */
    CHECK(musashi_bios_events_open(&events, 0xf4000001u, 0x0004u, 0x1000u, 0x800617ccu, &h_sw));
    CHECK(musashi_bios_events_open(&events, 0xf0000011u, 0x0004u, 0x1000u, 0x8006181cu, &h_hw));
    CHECK(musashi_bios_events_enable(&events, h_sw, &r) && r == 1);
    CHECK(musashi_bios_events_enable(&events, h_hw, &r) && r == 1);

    /* card_info: new card once, then IoEnd; port 1 times out. */
    CHECK(musashi_bios_memcard_card_info(&mc, 0, &r) && r == 1 && mc.pending_spec == 0x2000u);
    mc.pending_spec = 0;
    CHECK(musashi_bios_memcard_card_info(&mc, 0, &r) && r == 1 && mc.pending_spec == 0x0004u);
    CHECK(musashi_bios_memcard_vblank(&mc, &events, execute_cb, NULL));
    CHECK(g_nexec == 2 && g_executed[0] == 0x800617ccu && g_executed[1] == 0x8006181cu);
    CHECK(mc.pending_spec == 0);
    CHECK(musashi_bios_memcard_card_info(&mc, 0x10, &r) && mc.pending_spec == 0x0100u);
    mc.pending_spec = 0;

    /* Empty card: no files, open fails. */
    guest_string(NAME, "bu00:*");
    CHECK(musashi_bios_memcard_firstfile(&mc, g_memory, NAME, DIRENT, &r) && r == 0);
    guest_string(NAME, "bu00:BASLUS-00726MUSASHI");
    CHECK(musashi_bios_memcard_open(&mc, g_memory, NAME, 0x8001u, &r) && r == -1);

    /* Create a one-block file, write frames asynchronously, read them back. */
    CHECK(musashi_bios_memcard_open(&mc, g_memory, NAME, (1u << 16) | 0x200u, &fd) && fd >= 0);
    CHECK(g_persists == 1);
    CHECK(musashi_bios_memcard_close(&mc, fd, &r));

    CHECK(musashi_bios_memcard_open(&mc, g_memory, NAME, (1u << 16) | 0x200u, &r) && r == -1); /* exists */
    CHECK(musashi_bios_memcard_open(&mc, g_memory, NAME, 0x8002u, &fd) && fd >= 0);
    buf = musashi_boot_ram_span(g_memory, BUF, 0x300);
    for (i = 0; i < 0x300; i++) buf[i] = (uint8_t)(i * 7u);
    CHECK(musashi_bios_memcard_lseek(&mc, fd, 0x480, 0, &r) && r == 0x480);
    CHECK(musashi_bios_memcard_write(&mc, g_memory, fd, BUF, 0x300, &r) && r == 0);
    CHECK(mc.pending_spec == 0x0004u && g_persists == 2);
    CHECK(musashi_bios_memcard_vblank(&mc, &events, execute_cb, NULL) && g_nexec == 4);
    CHECK(musashi_bios_memcard_close(&mc, fd, &r));

    /* Two-block on-disk links are block number minus one, independently
     * checked here rather than trusting the reader to mirror the writer. */
    guest_string(NAME, "bu00:TWO-BLOCK");
    CHECK(musashi_bios_memcard_open(&mc, g_memory, NAME, (2u << 16) | 0x200u, &fd) && fd >= 0);
    CHECK(mc.image[2 * 128 + 8] == 2 && mc.image[2 * 128 + 9] == 0); /* block 2 -> 3 */
    CHECK(mc.image[3 * 128] == 0x53 && mc.image[3 * 128 + 8] == 0xff);
    CHECK(musashi_bios_memcard_close(&mc, fd, &r));
    CHECK(musashi_bios_memcard_open(&mc, g_memory, NAME, 3u, &fd) && fd >= 0);
    CHECK(musashi_bios_memcard_lseek(&mc, fd, 8192 - 128, 0, &r));
    memset(buf, 0x72, 128); memset(buf + 128, 0x93, 128);
    CHECK(musashi_bios_memcard_write(&mc, g_memory, fd, BUF, 256, &r) && r == 256);
    CHECK(mc.image[3 * 8192 - 128] == 0x72 && mc.image[3 * 8192] == 0x93);
    CHECK(musashi_bios_memcard_lseek(&mc, fd, -256, 1, &r) && r == 8192 - 128);
    memset(buf, 0, 256);
    CHECK(musashi_bios_memcard_read(&mc, g_memory, fd, BUF, 256, &r) && r == 256);
    CHECK(buf[127] == 0x72 && buf[128] == 0x93);
    CHECK(musashi_bios_memcard_close(&mc, fd, &r));
    CHECK(musashi_bios_memcard_erase(&mc, g_memory, NAME, &r) && r == 1);
    CHECK(mc.image[2 * 128] == 0xa1 && mc.image[3 * 128] == 0xa3);

    /* Exhausted descriptors must not create a file as a side effect. */
    guest_string(NAME, "bu00:BASLUS-00726MUSASHI");
    for (i = 0; i < MUSASHI_MEMCARD_FDS; i++)
        CHECK(musashi_bios_memcard_open(&mc, g_memory, NAME, 1u, &r) && r >= 0);
    guest_string(NAME, "bu00:FD-FULL");
    CHECK(musashi_bios_memcard_open(&mc, g_memory, NAME, (1u << 16) | 0x200u, &r) && r == -1);
    CHECK(musashi_bios_memcard_firstfile(&mc, g_memory, NAME, DIRENT, &r) && r == 0);
    for (i = 0; i < MUSASHI_MEMCARD_FDS; i++) CHECK(musashi_bios_memcard_close(&mc, (int32_t)i, &r));
    guest_string(NAME, "bu00:BASLUS-00726MUSASHI");
    memset(buf, 0, 0x300);
    CHECK(musashi_bios_memcard_open(&mc, g_memory, NAME, 0x8001u, &fd) && fd >= 0);
    CHECK(musashi_bios_memcard_lseek(&mc, fd, 0x480, 0, &r) && r == 0x480);
    CHECK(musashi_bios_memcard_read(&mc, g_memory, fd, BUF, 0x300, &r) && r == 0);
    for (i = 0; i < 0x300; i++) CHECK(buf[i] == (uint8_t)(i * 7u));
    /* The bytes live in block 1 at the file offset, standard layout. */
    CHECK(mc.image[8192 + 0x480] == 0 && mc.image[8192 + 0x481] == 7);
    /* Not frame aligned, past the end: refused as -1, not a stop. */
    CHECK(musashi_bios_memcard_lseek(&mc, fd, 8192 - 64, 0, &r) && r == 8192 - 64);
    CHECK(musashi_bios_memcard_read(&mc, g_memory, fd, BUF, 0x80, &r) && r == -1);
    CHECK(musashi_bios_memcard_close(&mc, fd, &r));

    /* A new card device owner (cold boot) sees only persisted image bytes. */
    musashi_bios_memcard_init(&mc, 1);
    CHECK(musashi_bios_memcard_load_image(&mc, g_saved, sizeof g_saved));
    mc.persist = persist_cb;
    CHECK(musashi_bios_memcard_open(&mc, g_memory, NAME, 1u, &fd) && fd >= 0);
    memset(buf, 0, 0x300);
    CHECK(musashi_bios_memcard_lseek(&mc, fd, 0x480, 0, &r));
    CHECK(musashi_bios_memcard_read(&mc, g_memory, fd, BUF, 0x300, &r) && r == 0x300);
    for (i = 0; i < 0x300; i++) CHECK(buf[i] == (uint8_t)(i * 7u));
    CHECK(musashi_bios_memcard_lseek(&mc, fd, -1, 0, &r) && r == -1);
    CHECK(musashi_bios_memcard_close(&mc, fd, &r));
    /* Sony _card_write_file uses open(0x8001), despite the nominal read bit. */
    CHECK(musashi_bios_memcard_open(&mc, g_memory, NAME, 0x8001u, &fd) && fd >= 0);
    CHECK(musashi_bios_memcard_lseek(&mc, fd, 0x480, 0, &r));
    CHECK(musashi_bios_memcard_write(&mc, g_memory, fd, BUF, 0x300, &r) && r == 0);
    CHECK(musashi_bios_memcard_close(&mc, fd, &r));

    /* Directory: the file, then nothing; the wildcard finds it too. */
    CHECK(musashi_bios_memcard_firstfile(&mc, g_memory, NAME, DIRENT, &r) && r == (int32_t)DIRENT);
    CHECK(memcmp(musashi_boot_ram_span(g_memory, DIRENT, 20), "BASLUS-00726MUSASHI\0", 20) == 0);
    CHECK(musashi_boot_ram_span(g_memory, DIRENT, 0x28)[0x18] == 0x00 &&
          musashi_boot_ram_span(g_memory, DIRENT, 0x28)[0x19] == 0x20); /* size 0x2000 */
    CHECK(musashi_bios_memcard_nextfile(&mc, g_memory, DIRENT, &r) && r == 0);
    guest_string(NAME, "bu00:*");
    CHECK(musashi_bios_memcard_firstfile(&mc, g_memory, NAME, DIRENT, &r) && r == (int32_t)DIRENT);
    guest_string(NAME, "bu10:*");
    CHECK(musashi_bios_memcard_firstfile(&mc, g_memory, NAME, DIRENT, &r) && r == 0);

    /* Erase frees the block; a fresh create reuses it. */
    guest_string(NAME, "bu00:BASLUS-00726MUSASHI");
    CHECK(musashi_bios_memcard_erase(&mc, g_memory, NAME, &r) && r == 1);
    CHECK(mc.image[128] == 0xa1);
    CHECK(musashi_bios_memcard_open(&mc, g_memory, NAME, 0x8001u, &r) && r == -1);
    CHECK(musashi_bios_memcard_open(&mc, g_memory, NAME, (1u << 16) | 0x200u, &fd) && fd >= 0);
    CHECK(mc.image[128] == 0x51 && mc.image[8192 + 0x481] == 0); /* data cleared */
    CHECK(musashi_bios_memcard_close(&mc, fd, &r));

    /* A transfer straddling the guest RAM boundary refuses before any image
     * mutation, even when its first chunk is a valid RAM span. */
    CHECK(musashi_bios_memcard_open(&mc, g_memory, NAME, 2u, &fd) && fd >= 0);
    CHECK(!musashi_bios_memcard_write(&mc, g_memory, fd, 0x801fff80u, 256, &r));
    CHECK(mc.fds[fd].pos == 0 && memcmp(mc.image, g_saved, sizeof g_saved) == 0);
    CHECK(musashi_bios_memcard_close(&mc, fd, &r));

    guest_string(NAME, "bu00:ABCDEFGHIJKLMNOPQRST");
    CHECK(musashi_bios_memcard_open(&mc, g_memory, NAME, (1u << 16) | 0x200u, &fd) && fd >= 0);
    CHECK(musashi_bios_memcard_close(&mc, fd, &r));
    guest_string(NAME, "bu00:ABCDEFGHIJKLMNOPQRSTU");
    CHECK(!musashi_bios_memcard_open(&mc, g_memory, NAME, 1u, &r));

    /* Format wipes and queues a completion; a bad path is a refusal. */
    guest_string(NAME, "bu00:");
    CHECK(musashi_bios_memcard_format(&mc, g_memory, NAME, &r) && r == 1 && mc.pending_spec == 0x0004u);
    guest_string(NAME, "bu00:*");
    CHECK(musashi_bios_memcard_firstfile(&mc, g_memory, NAME, DIRENT, &r) && r == 0);
    guest_string(NAME, "cdrom:");
    CHECK(!musashi_bios_memcard_open(&mc, g_memory, NAME, 1u, &r));

    /* No card: every access times out or fails without a stop. */
    musashi_bios_memcard_init(&mc, 0);
    guest_string(NAME, "bu00:X");
    CHECK(musashi_bios_memcard_card_info(&mc, 0, &r) && mc.pending_spec == 0x0100u);
    CHECK(musashi_bios_memcard_open(&mc, g_memory, NAME, 1u, &r) && r == -1);
    CHECK(musashi_bios_memcard_firstfile(&mc, g_memory, NAME, DIRENT, &r) && r == 0);
    puts("bios_memcard probe ok");
    free(g_memory);
    return 0;
}
