#pragma once

#include "image/image.h"

#include <stdio.h>

int image_pbm_load(image_type_t *image, FILE *input_file, char *buff);
int image_pbm_save(image_type_t *image, const char *new_file_name);
