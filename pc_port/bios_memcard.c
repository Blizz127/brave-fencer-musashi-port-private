/* BIOS memory-card file device over a 128 KiB image. See the header. */
#include "musashi_bios_memcard.h"

#include <string.h>

/* Directory entry states (block 0, frames 1..15). */
enum {
    ST_FREE = 0xa0u,
    ST_FIRST = 0x51u,
    ST_MIDDLE = 0x52u,
    ST_LAST = 0x53u,
    ST_DELETED_FIRST = 0xa1u,
    ST_DELETED_MIDDLE = 0xa2u,
    ST_DELETED_LAST = 0xa3u
};
enum { NO_BLOCK = 0xffffu, BLOCKS = 16u, DIR_ENTRIES = 15u };
enum { MODE_READ = 1u, MODE_WRITE = 2u, MODE_CREATE = 0x200u, MODE_ASYNC = 0x8000u };
enum { CLASS_SW = 0xf4000001u, CLASS_HW = 0xf0000011u };
enum { DEVICE_TABLE_ADDRESS = 0x0000e000u, DEVICE_TABLE_WORDS = 0x150u,
       DEVICE_TABLE_SIZE_WORD = 0x154u, DEVICE_ENTRY_SIZE = 0x50u,
       FIRSTFILE_STUB = 0x80062248u };

static uint32_t le32(const uint8_t *p) {
    return (uint32_t)p[0] | ((uint32_t)p[1] << 8) | ((uint32_t)p[2] << 16) | ((uint32_t)p[3] << 24);
}
static uint16_t le16(const uint8_t *p) { return (uint16_t)(p[0] | (p[1] << 8)); }
static void put32(uint8_t *p, uint32_t v) {
    p[0] = (uint8_t)v; p[1] = (uint8_t)(v >> 8); p[2] = (uint8_t)(v >> 16); p[3] = (uint8_t)(v >> 24);
}
static void put16(uint8_t *p, uint16_t v) { p[0] = (uint8_t)v; p[1] = (uint8_t)(v >> 8); }

static void frame_checksum(uint8_t *frame) {
    uint8_t x = 0;
    unsigned i;
    for (i = 0; i + 1 < MUSASHI_MEMCARD_FRAME; i++) x ^= frame[i];
    frame[MUSASHI_MEMCARD_FRAME - 1] = x;
}

static uint8_t *dir_entry(uint8_t *image, unsigned block) {
    return image + block * MUSASHI_MEMCARD_FRAME; /* block 0, frame = block index */
}

void musashi_bios_memcard_format_fresh(uint8_t *image) {
    unsigned i;
    memset(image, 0, MUSASHI_MEMCARD_SIZE);
    image[0] = 'M'; image[1] = 'C';
    frame_checksum(image);
    for (i = 1; i < BLOCKS; i++) {
        uint8_t *e = dir_entry(image, i);
        put32(e, ST_FREE);
        put16(e + 8, NO_BLOCK);
        frame_checksum(e);
    }
    /* Broken-sector list: 20 frames of "none". */
    for (i = 16; i < 36; i++) {
        uint8_t *f = image + i * MUSASHI_MEMCARD_FRAME;
        put32(f, 0xffffffffu);
        frame_checksum(f);
    }
    /* Write-test frame. */
    image[63 * MUSASHI_MEMCARD_FRAME] = 'M';
    image[63 * MUSASHI_MEMCARD_FRAME + 1] = 'C';
    frame_checksum(image + 63 * MUSASHI_MEMCARD_FRAME);
}

int musashi_bios_memcard_is_formatted(const uint8_t *image) {
    return image && image[0] == 'M' && image[1] == 'C';
}

void musashi_bios_memcard_init(MusashiBiosMemcard *mc, int present) {
    if (!mc) return;
    memset(mc, 0, sizeof *mc);
    mc->present = present != 0;
    mc->new_card = 1;
    musashi_bios_memcard_format_fresh(mc->image);
}

int musashi_bios_memcard_load_image(MusashiBiosMemcard *mc, const uint8_t *image, size_t size) {
    if (!mc || !image || size != MUSASHI_MEMCARD_SIZE) return 0;
    memcpy(mc->image, image, size);
    mc->dirty = 0;
    return 1;
}

/* Guest RAM span for KUSEG/KSEG0/KSEG1 aliases of main RAM. */
static uint8_t *span(MusashiBootMemory *memory, uint32_t address, size_t size) {
    uint32_t segment = address & 0xe0000000u, physical = address & 0x1fffffffu;
    if (segment != 0u && segment != 0x80000000u && segment != 0xa0000000u) return NULL;
    if (physical >= MUSASHI_RAM_SIZE) return NULL;
    return musashi_boot_ram_span(memory, 0x80000000u + physical, size);
}

/* "bu00:NAME" -> port and name (up to 20 chars). Returns 0 on a bad path. */
static int parse_path(MusashiBootMemory *memory, uint32_t name_ptr, int *port,
                      char name[MUSASHI_MEMCARD_NAME + 1]) {
    const uint8_t *p = span(memory, name_ptr, 5);
    unsigned i;
    if (!p || (p[0] != 'b' && p[0] != 'B') || (p[1] != 'u' && p[1] != 'U') ||
        p[2] < '0' || p[2] > '1' || p[3] != '0' || p[4] != ':')
        return 0;
    *port = p[2] - '0';
    for (i = 0; i < MUSASHI_MEMCARD_NAME; i++) {
        const uint8_t *c = span(memory, name_ptr + 5u + i, 1);
        if (!c) return 0;
        name[i] = (char)*c;
        if (!*c) break;
    }
    if (i == MUSASHI_MEMCARD_NAME) {
        const uint8_t *end = span(memory, name_ptr + 5u + i, 1);
        if (!end || *end) return 0;
    }
    name[i < MUSASHI_MEMCARD_NAME ? i : MUSASHI_MEMCARD_NAME] = 0;
    return 1;
}

static void queue(MusashiBiosMemcard *mc, uint32_t spec) { mc->pending_spec = spec; }

static int persist(MusashiBiosMemcard *mc) {
    mc->dirty = 1;
    if (!mc->persist) return 1;
    if (!mc->persist(mc->persist_userdata, mc->image, MUSASHI_MEMCARD_SIZE)) return 0;
    mc->dirty = 0;
    mc->persisted++;
    return 1;
}

static int entry_name_is(const uint8_t *e, const char *name) {
    unsigned i;
    for (i = 0; i < MUSASHI_MEMCARD_NAME; i++) {
        char c = (char)e[0x0a + i];
        if (c != name[i]) return 0;
        if (!c) return 1;
    }
    return name[MUSASHI_MEMCARD_NAME] == 0;
}

/* First block of the named file, or 0. */
static unsigned find_file(const uint8_t *image, const char *name) {
    unsigned b;
    for (b = 1; b < BLOCKS; b++) {
        const uint8_t *e = image + b * MUSASHI_MEMCARD_FRAME;
        if (le32(e) == ST_FIRST && entry_name_is(e, name)) return b;
    }
    return 0;
}

static int block_free(const uint8_t *e) {
    uint32_t st = le32(e);
    return st == ST_FREE || st == ST_DELETED_FIRST || st == ST_DELETED_MIDDLE ||
           st == ST_DELETED_LAST;
}

/* "*" and "?" wildcards, as the kernel's firstfile. */
static int pattern_match(const char *pattern, const uint8_t *e) {
    unsigned i = 0;
    const char *p = pattern;
    for (;;) {
        char c = i < MUSASHI_MEMCARD_NAME ? (char)e[0x0a + i] : 0;
        if (*p == '*') return 1;
        if (*p == 0) return c == 0;
        if (*p != '?' && *p != c) return 0;
        if (c == 0) return 0;
        p++; i++;
    }
}

static int fd_valid(const MusashiBiosMemcard *mc, int32_t fd) {
    return fd >= 0 && (unsigned)fd < MUSASHI_MEMCARD_FDS && mc->fds[fd].used;
}

/* Block holding file offset `pos`, following the chain from `first`. */
static unsigned block_at(const uint8_t *image, unsigned first, uint32_t pos) {
    unsigned b = first, hops = pos / MUSASHI_MEMCARD_BLOCK;
    while (hops-- && b && b < BLOCKS) {
        uint16_t next = le16(image + b * MUSASHI_MEMCARD_FRAME + 8);
        b = next == NO_BLOCK ? 0 : (unsigned)next + 1u;
    }
    return b < BLOCKS ? b : 0;
}

int musashi_bios_memcard_open(MusashiBiosMemcard *mc, MusashiBootMemory *memory,
                              uint32_t name_ptr, uint32_t mode, int32_t *result) {
    int port;
    char name[MUSASHI_MEMCARD_NAME + 1];
    unsigned first, i, free_fd;
    if (!mc || !memory || !result) return 0;
    mc->opens++;
    if (!parse_path(memory, name_ptr, &port, name)) { mc->refusals++; return 0; }
    if (port != 0 || !mc->present || !musashi_bios_memcard_is_formatted(mc->image)) {
        *result = -1;
        return 1;
    }
    first = find_file(mc->image, name);
    for (free_fd = 0; free_fd < MUSASHI_MEMCARD_FDS; free_fd++)
        if (!mc->fds[free_fd].used) break;
    if (free_fd == MUSASHI_MEMCARD_FDS) { *result = -1; return 1; }
    if (mode & MODE_CREATE) {
        unsigned blocks = mode >> 16, chain[BLOCKS], n = 0, b;
        if (first || blocks == 0 || blocks > DIR_ENTRIES || !name[0]) { *result = -1; return 1; }
        for (b = 1; b < BLOCKS && n < blocks; b++)
            if (block_free(mc->image + b * MUSASHI_MEMCARD_FRAME)) chain[n++] = b;
        if (n < blocks) { *result = -1; return 1; }
        for (i = 0; i < n; i++) {
            uint8_t *e = dir_entry(mc->image, chain[i]);
            memset(e, 0, MUSASHI_MEMCARD_FRAME);
            put32(e, i == 0 ? ST_FIRST : (i + 1 == n ? ST_LAST : ST_MIDDLE));
            put32(e + 4, i == 0 ? blocks * MUSASHI_MEMCARD_BLOCK : 0u);
            put16(e + 8, (uint16_t)(i + 1 < n ? chain[i + 1] - 1u : NO_BLOCK));
            if (i == 0) memcpy(e + 0x0a, name, strlen(name));
            frame_checksum(e);
            memset(mc->image + chain[i] * MUSASHI_MEMCARD_BLOCK, 0, MUSASHI_MEMCARD_BLOCK);
        }
        first = chain[0];
        if (!persist(mc)) return 0;
    }
    if (!first) { *result = -1; return 1; }
    for (i = 0; i < MUSASHI_MEMCARD_FDS; i++) {
        if (mc->fds[i].used) continue;
        mc->fds[i].used = 1;
        mc->fds[i].first_block = (uint16_t)first;
        mc->fds[i].size = le32(mc->image + first * MUSASHI_MEMCARD_FRAME + 4);
        mc->fds[i].pos = 0;
        mc->fds[i].mode = mode;
        *result = (int32_t)i;
        return 1;
    }
    *result = -1;
    return 1;
}

int musashi_bios_memcard_lseek(MusashiBiosMemcard *mc, int32_t fd, int32_t offset,
                               int32_t whence, int32_t *result) {
    int64_t pos;
    if (!mc || !result) return 0;
    if (!fd_valid(mc, fd) || whence < 0 || whence > 2) { *result = -1; return 1; }
    pos = (int64_t)offset + (whence == 0 ? 0 :
          whence == 1 ? mc->fds[fd].pos : mc->fds[fd].size);
    if (pos < 0 || pos > mc->fds[fd].size) { *result = -1; return 1; }
    mc->fds[fd].pos = (uint32_t)pos;
    *result = (int32_t)pos;
    return 1;
}

static int transfer(MusashiBiosMemcard *mc, MusashiBootMemory *memory, int32_t fd,
                    uint32_t buf_ptr, uint32_t length, int write, int32_t *result) {
    MusashiMemcardFd *f;
    uint32_t done = 0;
    if (!mc || !memory || !result) return 0;
    if (!fd_valid(mc, fd) || !length || (length % MUSASHI_MEMCARD_FRAME) ||
        !mc->present) { *result = -1; return 1; }
    f = &mc->fds[fd];
    /* The guest's _card_write_file opens with 0x8001 too: the bu driver
     * permits both directions rather than enforcing POSIX access modes. */
    if (f->pos > f->size || f->pos % MUSASHI_MEMCARD_FRAME ||
        length > f->size - f->pos) { *result = -1; return 1; }
    /* Validate the entire transfer before changing either image or RAM. */
    if (!span(memory, buf_ptr, length)) { mc->refusals++; return 0; }
    for (done = 0; done < length; ) {
        uint32_t pos = f->pos + done;
        uint32_t chunk = MUSASHI_MEMCARD_BLOCK - pos % MUSASHI_MEMCARD_BLOCK;
        if (!block_at(mc->image, f->first_block, pos)) { *result = -1; return 1; }
        if (chunk > length - done) chunk = length - done;
        done += chunk;
    }
    done = 0;
    while (done < length) {
        uint32_t pos = f->pos + done, in_block = pos % MUSASHI_MEMCARD_BLOCK;
        uint32_t chunk = MUSASHI_MEMCARD_BLOCK - in_block;
        unsigned block = block_at(mc->image, f->first_block, pos);
        uint8_t *guest;
        if (chunk > length - done) chunk = length - done;
        if (!block) { *result = -1; return 1; }
        guest = span(memory, buf_ptr + done, chunk);
        if (!guest) { mc->refusals++; return 0; }
        if (write) memcpy(mc->image + block * MUSASHI_MEMCARD_BLOCK + in_block, guest, chunk);
        else memcpy(guest, mc->image + block * MUSASHI_MEMCARD_BLOCK + in_block, chunk);
        done += chunk;
    }
    f->pos += length;
    if (write) { mc->writes++; if (!persist(mc)) return 0; } else mc->reads++;
    if (f->mode & MODE_ASYNC) {
        queue(mc, MUSASHI_MEMCARD_EV_IOEND);
        *result = 0;
    } else {
        *result = (int32_t)length;
    }
    return 1;
}

int musashi_bios_memcard_read(MusashiBiosMemcard *mc, MusashiBootMemory *memory,
                              int32_t fd, uint32_t buf_ptr, uint32_t length, int32_t *result) {
    return transfer(mc, memory, fd, buf_ptr, length, 0, result);
}

int musashi_bios_memcard_write(MusashiBiosMemcard *mc, MusashiBootMemory *memory,
                               int32_t fd, uint32_t buf_ptr, uint32_t length, int32_t *result) {
    return transfer(mc, memory, fd, buf_ptr, length, 1, result);
}

int musashi_bios_memcard_close(MusashiBiosMemcard *mc, int32_t fd, int32_t *result) {
    if (!mc || !result) return 0;
    if (!fd_valid(mc, fd)) { *result = -1; return 1; }
    memset(&mc->fds[fd], 0, sizeof mc->fds[fd]);
    *result = fd;
    return 1;
}

int musashi_bios_memcard_format(MusashiBiosMemcard *mc, MusashiBootMemory *memory,
                                uint32_t name_ptr, int32_t *result) {
    int port;
    char name[MUSASHI_MEMCARD_NAME + 1];
    if (!mc || !memory || !result) return 0;
    mc->formats++;
    if (!parse_path(memory, name_ptr, &port, name)) { mc->refusals++; return 0; }
    if (port != 0 || !mc->present) {
        queue(mc, MUSASHI_MEMCARD_EV_TIMEOUT);
        *result = 0;
        return 1;
    }
    musashi_bios_memcard_format_fresh(mc->image);
    memset(mc->fds, 0, sizeof mc->fds);
    if (!persist(mc)) return 0;
    queue(mc, MUSASHI_MEMCARD_EV_IOEND);
    *result = 1;
    return 1;
}

static int dir_emit(MusashiBiosMemcard *mc, MusashiBootMemory *memory, uint32_t dirent_ptr,
                    int32_t *result) {
    for (; mc->dir_next < BLOCKS; mc->dir_next++) {
        const uint8_t *e = mc->image + mc->dir_next * MUSASHI_MEMCARD_FRAME;
        uint8_t *d;
        if (le32(e) != ST_FIRST || !pattern_match(mc->pattern, e)) continue;
        d = span(memory, dirent_ptr, 0x28);
        if (!d) { mc->refusals++; return 0; }
        memset(d, 0, 0x28);
        memcpy(d, e + 0x0a, MUSASHI_MEMCARD_NAME);
        put32(d + 0x14, ST_FIRST);          /* attr: the entry state */
        put32(d + 0x18, le32(e + 4));       /* size in bytes */
        put32(d + 0x1c, 0);                 /* next: unused by the kernel */
        mc->dir_next++;
        *result = (int32_t)dirent_ptr;
        return 1;
    }
    mc->dir_active = 0;
    *result = 0;
    return 1;
}

int musashi_bios_memcard_firstfile(MusashiBiosMemcard *mc, MusashiBootMemory *memory,
                                   uint32_t name_ptr, uint32_t dirent_ptr, int32_t *result) {
    int port;
    if (!mc || !memory || !result) return 0;
    if (!parse_path(memory, name_ptr, &port, mc->pattern)) { mc->refusals++; return 0; }
    if (port != 0 || !mc->present || !musashi_bios_memcard_is_formatted(mc->image)) {
        mc->dir_active = 0;
        *result = 0;
        return 1;
    }
    mc->dir_active = 1;
    mc->dir_next = 1;
    return dir_emit(mc, memory, dirent_ptr, result);
}

int musashi_bios_memcard_nextfile(MusashiBiosMemcard *mc, MusashiBootMemory *memory,
                                  uint32_t dirent_ptr, int32_t *result) {
    if (!mc || !memory || !result) return 0;
    if (!mc->dir_active) { *result = 0; return 1; }
    return dir_emit(mc, memory, dirent_ptr, result);
}

int musashi_bios_memcard_erase(MusashiBiosMemcard *mc, MusashiBootMemory *memory,
                               uint32_t name_ptr, int32_t *result) {
    int port;
    char name[MUSASHI_MEMCARD_NAME + 1];
    unsigned b, hops;
    if (!mc || !memory || !result) return 0;
    mc->erases++;
    if (!parse_path(memory, name_ptr, &port, name)) { mc->refusals++; return 0; }
    if (port != 0 || !mc->present) { *result = 0; return 1; }
    b = find_file(mc->image, name);
    if (!b) { *result = 0; return 1; }
    for (hops = 0; b && b < BLOCKS && hops < DIR_ENTRIES; hops++) {
        uint8_t *e = dir_entry(mc->image, b);
        uint32_t st = le32(e);
        uint16_t next = le16(e + 8);
        put32(e, st == ST_FIRST ? ST_DELETED_FIRST : st == ST_MIDDLE ? ST_DELETED_MIDDLE : ST_DELETED_LAST);
        frame_checksum(e);
        b = next == NO_BLOCK ? 0 : (unsigned)next + 1u;
    }
    if (!persist(mc)) return 0;
    *result = 1;
    return 1;
}

int musashi_bios_memcard_card_info(MusashiBiosMemcard *mc, int32_t chan, int32_t *result) {
    if (!mc || !result) return 0;
    mc->infos++;
    if ((chan >> 4) != 0 || !mc->present) {
        queue(mc, MUSASHI_MEMCARD_EV_TIMEOUT);
    } else if (mc->new_card) {
        /* The kernel reports a card it has not seen since power-on once. */
        mc->new_card = 0;
        queue(mc, MUSASHI_MEMCARD_EV_NEWCARD);
    } else {
        queue(mc, MUSASHI_MEMCARD_EV_IOEND);
    }
    *result = 1;
    return 1;
}

int musashi_bios_memcard_card_write(MusashiBiosMemcard *mc, MusashiBootMemory *memory,
                                    int32_t chan, int32_t sector, uint32_t buf_ptr, int32_t *result) {
    const uint8_t *guest;
    if (!mc || !memory || !result) return 0;
    if ((chan >> 4) != 0 || !mc->present || sector < 0 ||
        (uint32_t)sector >= MUSASHI_MEMCARD_SIZE / MUSASHI_MEMCARD_FRAME) {
        queue(mc, MUSASHI_MEMCARD_EV_TIMEOUT);
        *result = 0;
        return 1;
    }
    guest = span(memory, buf_ptr, MUSASHI_MEMCARD_FRAME);
    if (!guest) { mc->refusals++; return 0; }
    memcpy(mc->image + (uint32_t)sector * MUSASHI_MEMCARD_FRAME, guest, MUSASHI_MEMCARD_FRAME);
    mc->writes++;
    if (!persist(mc)) return 0;
    queue(mc, MUSASHI_MEMCARD_EV_IOEND);
    *result = 1;
    return 1;
}

int musashi_bios_memcard_new_card(MusashiBiosMemcard *mc, int32_t *result) {
    if (!mc || !result) return 0;
    mc->new_card = 0;
    *result = 1;
    return 1;
}

int musashi_bios_memcard_vblank(MusashiBiosMemcard *mc, MusashiBiosEvents *events,
                                MusashiBiosEventExecutor execute, void *userdata) {
    uint32_t spec;
    if (!mc || !events) return 0;
    spec = mc->pending_spec;
    if (!spec) return 1;
    mc->pending_spec = 0;
    /* Both classes carry the completion; the game clears the flags of the
     * class it is not waiting on before every operation. */
    if (!musashi_bios_events_deliver(events, CLASS_SW, spec, execute, userdata) ||
        !musashi_bios_events_deliver(events, CLASS_HW, spec, execute, userdata))
        return 0;
    mc->delivered++;
    return 1;
}

int musashi_bios_memcard_install_device_table(MusashiBootMemory *memory) {
    uint8_t *table, *words;
    if (!memory) return 0;
    table = musashi_boot_ram_span(memory, 0x80000000u + DEVICE_TABLE_ADDRESS, DEVICE_ENTRY_SIZE + 8u);
    words = musashi_boot_ram_span(memory, 0x80000000u + DEVICE_TABLE_WORDS, 8u);
    if (!table || !words) return 0;
    memset(table, 0, DEVICE_ENTRY_SIZE + 8u);
    /* entry->name: "bu" just after the entry; entry->firstFile: the stub. */
    put32(table, 0x80000000u + DEVICE_TABLE_ADDRESS + DEVICE_ENTRY_SIZE);
    put32(table + 0x34, FIRSTFILE_STUB);
    table[DEVICE_ENTRY_SIZE] = 'b';
    table[DEVICE_ENTRY_SIZE + 1] = 'u';
    put32(words, 0x80000000u + DEVICE_TABLE_ADDRESS);
    put32(words + 4, DEVICE_ENTRY_SIZE);
    return 1;
}
