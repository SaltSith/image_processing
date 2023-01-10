#include "image_io.h"
#include "image_formats/image_formats.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int
image_io_read(image_type_t *image)
{
    if (image == NULL) {
        return -1;
    }

    if (image->file_name == NULL) {
        return -2;
    }

    FILE *input_file = fopen(image->file_name, "r");
    if (input_file == NULL) {
    	return -3;
    }

    char buff[BUFF_SIZE];
    if (fgets(buff, BUFF_SIZE, input_file) == NULL) {
    	fclose(input_file);
    	return -4;
    }

    if (buff[0] == 'P' && buff[1] == '1') {
    	image->magic_number = P1;
    } else if (buff[0] == 'P' && buff[1] == '2') {
    	image->magic_number = P2;
	} else if (buff[0] == 'P' && buff[1] == '3') {
    	image->magic_number = P3;
    } else {
    	fclose(input_file);
    	return -5;
    }

	memcpy(image->magic_number_str, buff, 2 * sizeof(char));

	memset(buff, '\0', sizeof(buff));
	char *im_name = buff;
	char ch;

	do {
		ch = fgetc(input_file);
		if (ch == '#') {
			while (ch != '\n') {
				ch = fgetc(input_file);
				if (ch == '\n') {
					continue;
				}
				*im_name++ = ch;
			}
		} else {
			ungetc(ch, input_file);
			break;
		}
	} while(1);

	if (im_name != buff) {
		image->name = (char *)malloc((strlen(buff) + 1) * sizeof(char));
		if (image->name == NULL) {
			fclose(input_file);
			return -7;
		}
		strncpy(image->name, buff, (strlen(buff) + 1) * sizeof(char));
	}

	int result = image_format_read_image(image, input_file);

	fclose(input_file);

	image_print_info(image);

    return result;
}

int
image_io_write(image_type_t *image, const char *file_name)
{
    if (image == NULL) {
        return -1;
    }

    if (file_name == NULL) {
        return -2;
    }

    return 0;
}
