#include <stdio.h>

#include "image_io/image_io.h"

int main(void) {
    image_type_t image;
    image.file_name = "../test_images/picture_not_exists.pgm";

    int result = image_io_read(&image);
    
    if (result == -3) {
        return 0;
    }

    return result;
}
