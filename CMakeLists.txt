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
