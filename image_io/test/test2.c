#include <stdio.h>

#include "image_io/image_io.h"

int main(void) {
    image_type_t image;
    image.file_name = NULL;

    int result = image_io_read(&image);
    
    if (result == -2) {
        return 0;
    }

    return result;
}
