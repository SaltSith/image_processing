#include "image_formats_ppm.h"

#include <stdlib.h>
#include <string.h>

int image_ppm_load(image_type_t *image, FILE *input_file)
{
    if (fscanf(input_file, "%d %d", &image->x, &image->y) != 2) {
        return -7;
    }

    if (fscanf(input_file, "%hu ", &image->grey_scale) != 1) {
        return -7;
    }

    image->pixels = malloc(3 * image->x * image->y * sizeof(int));
    if (image->pixels == NULL) {
        return -8;
    }

    image->pixels_backup = malloc(3 * image->x * image->y * sizeof(int));
    if (image->pixels_backup == NULL) {
        return -8;
    }

    for (int i = 0; i < (3 * image->x * image->y); i++) {
        if (fscanf(input_file, "%hhu", &image->pixels[i]) != 1) {
            return -9;
        }
        image->pixels_backup[i] = image->pixels[i];
    }

    return 0;
}

int
image_ppm_save(image_type_t *image, const char *new_file_name)
{
    if ((image == NULL) || (new_file_name == NULL)) {
        return -1;
    }

    char *fn = malloc(strlen(new_file_name) + strlen(".ppm") + 1);
    if (fn == NULL) {
        return -3;
    }

    memset(fn, '\0', strlen(new_file_name) + strlen(".ppm") + 1);
    strncpy(fn, new_file_name, strlen(new_file_name));
    strcat(fn, ".ppm");

    FILE *output_file_handler = fopen(fn, "w");
    free(fn);
    if (output_file_handler == NULL) {
        return -3;
    }

    fprintf(output_file_handler, "%s\n", image->magic_number_str);
    fprintf(output_file_handler, "#%s\n", image->name);
    fprintf(output_file_handler, "%d %d\n", image->x, image->y);
    fprintf(output_file_handler, "%hu\n", image->grey_scale);

    for (uint32_t i = 0; i < (3 * image->x * image->y); i++) {
        fprintf(output_file_handler, "%hhu ", image->pixels_backup[i]);
        if (i % 68 == 0) {
            fprintf(output_file_handler, "\n");
        }
    }

    fclose(output_file_handler);

    return 0;
}
