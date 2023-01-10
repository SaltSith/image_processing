#pragma once

#include "image/image.h"

#include <stdio.h>

int image_pbm_load(image_type_t *image, FILE *input_file);
int image_pbm_save(image_type_t *image, FILE *output_file_handler);
