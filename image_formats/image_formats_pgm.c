#include "image_formats_pgm.h"

#include <stdlib.h>
#include <string.h>

int image_pgm_load(image_type_t *image, FILE *input_file)
{
    if (fscanf(input_file, "%d %d", &image->x, &image->y) != 2) {
        return -7;
    }

    if (fscanf(input_file, "%hu", &image->grey_scale) != 1) {
        return -8;
    }

    image->pixels = malloc(image->x * image->y * sizeof(int));
    if (image->pixels == NULL) {
        return -8;
    }

    image->pixels_backup = malloc(image->x * image->y * sizeof(int));
    if (image->pixels_backup == NULL) {
        return -8;
    }

    for (uint32_t i = 0; i < (image->x * image->y); i++) {
        if (fscanf(input_file, "%hhu", &image->pixels[i]) != 1) {
            return -9;
        }
        image->pixels_backup[i] = image->pixels[i];
    }

    return 0;
}

int image_pgm_save(image_type_t *image, FILE *output_file_handler)
{
    if ((image == NULL) || (output_file_handler == NULL)) {
        return -1;
    }

    fprintf(output_file_handler, "%s\n", image->magic_number_str);
    fprintf(output_file_handler, "#%s\n", image->name);
    fprintf(output_file_handler, "%d %d\n", image->x, image->y);

    fprintf(output_file_handler, "%hu\n", image->grey_scale);

    for (uint32_t i = 0; i < (image->x * image->y); i++) {
        fprintf(output_file_handler, "%d ", image->pixels[i]);
        if ((i + 1) % image->x == 0) {
            fprintf(output_file_handler, "\n");
        }
    }

    return 0;
}
