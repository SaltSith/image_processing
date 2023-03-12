#include <stdio.h>

#include "image_io/image_io.h"
#include "compression/rle.h"

int main(int argc, const char *argv[]) {
  image_type_t image;

  //image.file_name = "/home/sith66/Code/Code/image_processing/feep.ppm";
  image.file_name = "/home/sith66/Desktop/lena_threshold.pgm";//"/home/sith66/Code/Code/c/mucha/image_processing/images/barbara2.ascii.pgm";
  // image.file_name =
  //     "/home/sith66/Code/Code/c/mucha/image_processing/images/image.pbm";
  int result = image_io_read(&image);

  rle_encode(&image);
  printf("red result = %d\r\n", result);

image_io_write(&image, "result_image2");  

  return result;
}
