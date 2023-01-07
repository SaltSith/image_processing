add_library(image_io
            image_io.h image_io.c)

target_include_directories(image_io PUBLIC "${PROJECT_SOURCE_DIR}/")
target_link_libraries(image_io image)

