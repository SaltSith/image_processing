#include <stdio.h>



#include "image_io/image_io.h"


int main(int argc, const char *argv[]) {
	image_type_t image;

	image.file_name = "/home/sith66/Code/Code/c/mucha/image_processing/images/barbara2.ascii.pgm";

	int result = image_io_read(&image);

    return result;
}
