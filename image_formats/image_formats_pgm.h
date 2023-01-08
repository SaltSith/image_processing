#pragma once

#include "image/image.h"

#include <stdio.h>

int image_pgm_load(image_type_t *image, FILE *input_file);
int image_pgm_save(image_type_t *image, const char *new_file_name);
