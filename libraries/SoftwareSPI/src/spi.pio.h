// -------------------------------------------------- //
// This file is autogenerated by pioasm; do not edit! //
// -------------------------------------------------- //

#pragma once

#if !PICO_NO_HARDWARE
#include "hardware/pio.h"
#endif

// --------- //
// spi_cpha0 //
// --------- //

#define spi_cpha0_wrap_target 0
#define spi_cpha0_wrap 1
#define spi_cpha0_pio_version 0

static const uint16_t spi_cpha0_program_instructions[] = {
    //     .wrap_target
    0x6101, //  0: out    pins, 1         side 0 [1]
    0x5101, //  1: in     pins, 1         side 1 [1]
    //     .wrap
};

#if !PICO_NO_HARDWARE
static const struct pio_program spi_cpha0_program = {
    .instructions = spi_cpha0_program_instructions,
    .length = 2,
    .origin = -1,
    .pio_version = spi_cpha0_pio_version,
#if PICO_PIO_VERSION > 0
    .used_gpio_ranges = 0x0
#endif
};

static inline pio_sm_config spi_cpha0_program_get_default_config(uint offset) {
    pio_sm_config c = pio_get_default_sm_config();
    sm_config_set_wrap(&c, offset + spi_cpha0_wrap_target, offset + spi_cpha0_wrap);
    sm_config_set_sideset(&c, 1, false, false);
    return c;
}
#endif

// --------- //
// spi_cpha1 //
// --------- //

#define spi_cpha1_wrap_target 0
#define spi_cpha1_wrap 2
#define spi_cpha1_pio_version 0

static const uint16_t spi_cpha1_program_instructions[] = {
    //     .wrap_target
    0x6021, //  0: out    x, 1            side 0
    0xb101, //  1: mov    pins, x         side 1 [1]
    0x4001, //  2: in     pins, 1         side 0
    //     .wrap
};

#if !PICO_NO_HARDWARE
static const struct pio_program spi_cpha1_program = {
    .instructions = spi_cpha1_program_instructions,
    .length = 3,
    .origin = -1,
    .pio_version = spi_cpha1_pio_version,
#if PICO_PIO_VERSION > 0
    .used_gpio_ranges = 0x0
#endif
};

static inline pio_sm_config spi_cpha1_program_get_default_config(uint offset) {
    pio_sm_config c = pio_get_default_sm_config();
    sm_config_set_wrap(&c, offset + spi_cpha1_wrap_target, offset + spi_cpha1_wrap);
    sm_config_set_sideset(&c, 1, false, false);
    return c;
}

#include "hardware/gpio.h"
static inline void pio_spi_init(PIO pio, uint sm, uint prog_offs, uint n_bits,
                                float clkdiv, bool cpha, bool cpol, uint pin_sck, uint pin_mosi, uint pin_miso) {
    pio_sm_config c = cpha ? spi_cpha1_program_get_default_config(prog_offs) : spi_cpha0_program_get_default_config(prog_offs);
    sm_config_set_out_pins(&c, pin_mosi, 1);
    sm_config_set_in_pins(&c, pin_miso);
    sm_config_set_sideset_pins(&c, pin_sck);
    // Only support MSB-first in this example code (shift to left, auto push/pull, threshold=nbits)
    sm_config_set_out_shift(&c, false, true, n_bits);
    sm_config_set_in_shift(&c, false, true, n_bits);
    sm_config_set_clkdiv(&c, clkdiv);
    // MOSI, SCK output are low, MISO is input
    pio_sm_set_pins_with_mask(pio, sm, 0, (1u << pin_sck) | (1u << pin_mosi));
    pio_sm_set_pindirs_with_mask(pio, sm, (1u << pin_sck) | (1u << pin_mosi), (1u << pin_sck) | (1u << pin_mosi) | (1u << pin_miso));
    pio_gpio_init(pio, pin_mosi);
    pio_gpio_init(pio, pin_miso);
    pio_gpio_init(pio, pin_sck);
    // The pin muxes can be configured to invert the output (among other things
    // and this is a cheesy way to get CPOL=1
    gpio_set_outover(pin_sck, cpol ? GPIO_OVERRIDE_INVERT : GPIO_OVERRIDE_NORMAL);
    // SPI is synchronous, so bypass input synchroniser to reduce input delay.
    hw_set_bits(&pio->input_sync_bypass, 1u << pin_miso);
    pio_sm_init(pio, sm, prog_offs, &c);
    pio_sm_set_enabled(pio, sm, true);
}

#endif

// ------------ //
// spi_cpha0_cs //
// ------------ //

#define spi_cpha0_cs_wrap_target 0
#define spi_cpha0_cs_wrap 8
#define spi_cpha0_cs_pio_version 0

#define spi_cpha0_cs_offset_entry_point 8u

static const uint16_t spi_cpha0_cs_program_instructions[] = {
    //     .wrap_target
    0x6101, //  0: out    pins, 1         side 0 [1]
    0x4801, //  1: in     pins, 1         side 1
    0x0840, //  2: jmp    x--, 0          side 1
    0x6001, //  3: out    pins, 1         side 0
    0xa022, //  4: mov    x, y            side 0
    0x4801, //  5: in     pins, 1         side 1
    0x08e0, //  6: jmp    !osre, 0        side 1
    0xa142, //  7: nop                    side 0 [1]
    0x91e0, //  8: pull   ifempty block   side 2 [1]
    //     .wrap
};

#if !PICO_NO_HARDWARE
static const struct pio_program spi_cpha0_cs_program = {
    .instructions = spi_cpha0_cs_program_instructions,
    .length = 9,
    .origin = -1,
    .pio_version = spi_cpha0_cs_pio_version,
#if PICO_PIO_VERSION > 0
    .used_gpio_ranges = 0x0
#endif
};

static inline pio_sm_config spi_cpha0_cs_program_get_default_config(uint offset) {
    pio_sm_config c = pio_get_default_sm_config();
    sm_config_set_wrap(&c, offset + spi_cpha0_cs_wrap_target, offset + spi_cpha0_cs_wrap);
    sm_config_set_sideset(&c, 2, false, false);
    return c;
}
#endif

// ------------ //
// spi_cpha1_cs //
// ------------ //

#define spi_cpha1_cs_wrap_target 0
#define spi_cpha1_cs_wrap 8
#define spi_cpha1_cs_pio_version 0

#define spi_cpha1_cs_offset_entry_point 7u

static const uint16_t spi_cpha1_cs_program_instructions[] = {
    //     .wrap_target
    0x6901, //  0: out    pins, 1         side 1 [1]
    0x4001, //  1: in     pins, 1         side 0
    0x0040, //  2: jmp    x--, 0          side 0
    0x6801, //  3: out    pins, 1         side 1
    0xa822, //  4: mov    x, y            side 1
    0x4001, //  5: in     pins, 1         side 0
    0x00e0, //  6: jmp    !osre, 0        side 0
    0x91e0, //  7: pull   ifempty block   side 2 [1]
    0xa142, //  8: nop                    side 0 [1]
    //     .wrap
};

#if !PICO_NO_HARDWARE
static const struct pio_program spi_cpha1_cs_program = {
    .instructions = spi_cpha1_cs_program_instructions,
    .length = 9,
    .origin = -1,
    .pio_version = spi_cpha1_cs_pio_version,
#if PICO_PIO_VERSION > 0
    .used_gpio_ranges = 0x0
#endif
};

static inline pio_sm_config spi_cpha1_cs_program_get_default_config(uint offset) {
    pio_sm_config c = pio_get_default_sm_config();
    sm_config_set_wrap(&c, offset + spi_cpha1_cs_wrap_target, offset + spi_cpha1_cs_wrap);
    sm_config_set_sideset(&c, 2, false, false);
    return c;
}

#include "hardware/gpio.h"
static inline void pio_spi_cs_init(PIO pio, uint sm, uint prog_offs, uint n_bits, float clkdiv, bool cpha, bool cpol,
                                   uint pin_sck, uint pin_mosi, uint pin_miso) {
    pio_sm_config c = cpha ? spi_cpha1_cs_program_get_default_config(prog_offs) : spi_cpha0_cs_program_get_default_config(prog_offs);
    sm_config_set_out_pins(&c, pin_mosi, 1);
    sm_config_set_in_pins(&c, pin_miso);
    sm_config_set_sideset_pins(&c, pin_sck);
    sm_config_set_out_shift(&c, false, true, n_bits);
    sm_config_set_in_shift(&c, false, true, n_bits);
    sm_config_set_clkdiv(&c, clkdiv);
    pio_sm_set_pins_with_mask(pio, sm, (2u << pin_sck), (3u << pin_sck) | (1u << pin_mosi));
    pio_sm_set_pindirs_with_mask(pio, sm, (3u << pin_sck) | (1u << pin_mosi), (3u << pin_sck) | (1u << pin_mosi) | (1u << pin_miso));
    pio_gpio_init(pio, pin_mosi);
    pio_gpio_init(pio, pin_miso);
    pio_gpio_init(pio, pin_sck);
    pio_gpio_init(pio, pin_sck + 1);
    gpio_set_outover(pin_sck, cpol ? GPIO_OVERRIDE_INVERT : GPIO_OVERRIDE_NORMAL);
    hw_set_bits(&pio->input_sync_bypass, 1u << pin_miso);
    uint entry_point = prog_offs + (cpha ? spi_cpha1_cs_offset_entry_point : spi_cpha0_cs_offset_entry_point);
    pio_sm_init(pio, sm, entry_point, &c);
    pio_sm_exec(pio, sm, pio_encode_set(pio_x, n_bits - 2));
    pio_sm_exec(pio, sm, pio_encode_set(pio_y, n_bits - 2));
    pio_sm_set_enabled(pio, sm, true);
}

#endif

