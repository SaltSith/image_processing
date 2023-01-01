#pragma once

#include "image/image.h"

int image_io_read(image_type_t *image);
int image_io_write(image_type_t *image, const char *file_name);
