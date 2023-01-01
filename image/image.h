#pragma once

#include <stdint.h>

typedef enum {
	P1 = 0,
	P2,
} magic_number_t;

typedef struct {
    uint32_t x;
    uint32_t y;
    uint8_t grey_scale;
    uint8_t *pixels;
    uint8_t *pixels_backup;
    char magic_number_str[2];
    magic_number_t magic_number;
    char *file_name;
    char *name;
} image_type_t;

void image_dummy(void);
