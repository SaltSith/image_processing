#include <stdio.h>

#include "image_io/image_io.h"

int main(void) {
    int result = image_io_read(NULL);
    if (result == -1) {
        return 0;
    }
    return result;
}
