#include "image_formats.h"

#include "image_formats_pbm.h"
#include "image_formats_pgm.h"
#include "image_formats_ppm.h"

#include <string.h>
#include <stdlib.h>

static const char *extension[] = {
    ".pbm",
    ".pgm",
    ".ppm"
};

int
image_format_read_image(image_type_t *image, FILE *input_file)
{
    if ((image == NULL) || (input_file == NULL)) {
        return -1;
    }

    switch (image->magic_number) {
	case P1:
        return image_pbm_load(image, input_file);

	case P2:
        return image_pgm_load(image, input_file);

    case P3:
        return image_ppm_load(image, input_file);

	default:
		break;
	}

    return -100;
}

int
image_format_save_image(image_type_t *image, const char *new_file_name)
{
    if ((image == NULL) || (new_file_name == NULL)) {
        return -1;
    }

    char *fn = malloc(strlen(new_file_name) + strlen(extension[image->magic_number]) + 1);
    if (fn == NULL) {
        return -2;
    }

    memset(fn, '\0', strlen(new_file_name) + strlen(extension[image->magic_number]) + 1);
    strncpy(fn, new_file_name, strlen(new_file_name));
    strcat(fn, extension[image->magic_number]);
    FILE *output_file_handler = fopen(fn, "w");
    free(fn);

    if (output_file_handler == NULL) {
        return -3;
    }

    switch (image->magic_number) {
	case P1:
        return image_pbm_save(image, output_file_handler);

	case P2:
        return image_pgm_save(image, output_file_handler);

    case P3:
        return image_ppm_save(image, output_file_handler);

	default:
		break;
	}

    fclose(output_file_handler);

    return -100;
}
