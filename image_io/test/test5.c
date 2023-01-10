#include <stdio.h>

#include "image_io/image_io.h"

int main(void) {
    image_type_t image;
    image.file_name = "../test_images/unsupported_image.ppm";

    int result = image_io_read(&image);
    
    if (result == -5) {
        return 0;
    }

    return result;
}
