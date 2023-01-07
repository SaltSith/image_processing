#include "image.h"
#include <stdio.h>

void
image_print_info(const image_type_t *image)
{
    printf("%2s\r\n", image->magic_number_str);
    printf("#%s\r\n", image->name);
    printf("path: %s\r\n", image->file_name);

    printf("%d %d \r\n", image->x, image->y);

    for (uint32_t i = 0; i < (image->x * image->y); i++) {
        printf("%d ", image->pixels_backup[i]);
        if (((i + 1) % image->x) == 0) {
            printf("\r\n");
        }
    }
}