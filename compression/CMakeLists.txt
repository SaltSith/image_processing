add_library(compression
            rle.h rle.c)

target_include_directories(compression PUBLIC "${PROJECT_SOURCE_DIR}/")
target_link_libraries(compression image)