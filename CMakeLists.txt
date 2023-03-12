cmake_minimum_required(VERSION 3.0)

project(photo_shop
        VERSION 1.0.0
        LANGUAGES C)

add_executable(${CMAKE_PROJECT_NAME} main.c)


add_subdirectory(image)
target_link_libraries(${CMAKE_PROJECT_NAME} image)

add_subdirectory(image_io)
target_link_libraries(${CMAKE_PROJECT_NAME} image_io)

add_subdirectory(image_formats)
target_link_libraries(${CMAKE_PROJECT_NAME} image_formats)

add_subdirectory(compression)
target_link_libraries(${CMAKE_PROJECT_NAME} compression)

# testing 
enable_testing()

# image_type_t struct null pointer
add_executable(test1 image_io/test/test1.c)
target_link_libraries(test1 image)
target_link_libraries(test1 image_io)
target_link_libraries(test1 image_formats)
add_test(NAME image_struct_null_pointer COMMAND test1)

# filename null pointer
add_executable(test2 image_io/test/test2.c)
target_link_libraries(test2 image)
target_link_libraries(test2 image_io)
target_link_libraries(test2 image_formats)
add_test(NAME filename_null_pointer COMMAND test2)

# file not exists
add_executable(test3 image_io/test/test3.c)
target_link_libraries(test3 image)
target_link_libraries(test3 image_io)
target_link_libraries(test3 image_formats)
add_test(NAME image_file_not_exists COMMAND test3)

# empty file
add_executable(test4 image_io/test/test4.c)
target_link_libraries(test4 image)
target_link_libraries(test4 image_io)
target_link_libraries(test4 image_formats)
add_test(NAME empty_picture_file COMMAND test4)

#unsupported file format
add_executable(test5 image_io/test/test5.c)
target_link_libraries(test5 image)
target_link_libraries(test5 image_io)
target_link_libraries(test5 image_formats)
add_test(NAME unsupported_image_format COMMAND test5)