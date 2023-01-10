#include "image.h"
#include <stdio.h>

void
image_print_info(const image_type_t *image)
{
    printf("%2s\r\n", image->magic_number_str);
    printf("#%s\r\n", image->name);
    printf("path: %s\r\n", image->file_name);

    printf("%d %d \r\n", image->x, image->y);

    if (image->magic_number > P1) {
        printf("%d\n", image->grey_scale);
    }

    if (image->magic_number <= P2) {
        for (uint32_t i = 0; i < (image->x * image->y); i++) {
            printf("%d ", image->pixels_backup[i]);
            if (((i + 1) % image->x) == 0) {
                printf("\r\n");
            }
        }
    } else {
        for (uint32_t i = 0; i < (3 * image->x * image->y); i++) {
            printf("%d ", image->pixels_backup[i]);
            if ((i + 1) % 3 == 0) {
                printf("  ");
            }
            if ((i + 1) % (3 * image->x) == 0) {
                printf("\n");
            }
        }
    }
}