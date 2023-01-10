#pragma once

#include "image/image.h"

#include <stdio.h>

int image_format_read_image(image_type_t *image, FILE *input_file);
int image_format_save_image(image_type_t *image, const char *new_file_name);
