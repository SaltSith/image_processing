add_library(image_formats
            image_formats.h image_formats.c
            image_formats_pbm.h image_formats_pbm.c
            image_formats_pgm.h image_formats_pgm.c
            image_formats_ppm.h image_formats_ppm.c)

target_link_libraries(image_formats image)
target_include_directories(image_formats PUBLIC "${PROJECT_SOURCE_DIR}/")

