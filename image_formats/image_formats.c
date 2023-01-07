#include "image_formats.h"
#include "image_formats_pbm.h"

int
image_format_read_image(image_type_t *image, FILE *input_file, char *buff)
{
    if ((image == NULL) || (buff == NULL) || (input_file == NULL)) {
        return -1;
    }

    switch (image->magic_number) {
	case P1:
        return image_pbm_load(image, input_file, buff);

	case P2:
		break;

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

    switch (image->magic_number) {
	case P1:
        return image_pbm_save(image, new_file_name);

	case P2:
		break;

	default:
		break;
	}

    return -100;
}
