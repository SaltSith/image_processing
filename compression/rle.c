#include "rle.h"

#include <stdlib.h>

typedef struct {
    uint8_t value;
    uint32_t count;
} rle_t;

int rle_encode(image_type_t *image)
{
    rle_t *rle = malloc(image->x * image->y * sizeof(rle_t));
    if (rle == NULL) {
        return -1;
    }

    uint8_t start_value = 0;
    uint32_t rle_elements = 0;

    for (uint32_t i = 0; i < (image->x * image->y); i++) {
        if (i == 0) {
            rle[rle_elements].value = image->pixels[i];
            rle[rle_elements].count++;
            continue;
        }

        if (rle[rle_elements].value == image->pixels[i]) {
            rle[rle_elements].count++;
        } else {
            rle_elements++;
            rle[rle_elements].value = image->pixels[i];
            rle[rle_elements].count++;
        }
    }

    for (uint32_t i = 0; i < rle_elements; i++) {
        printf("element %d \t count %d \r\n", rle[i].value, rle[i].count);
    }

    free(rle);
    return 0;
}

int rle_decode(image_type_t *image)
{
    return 0;
}