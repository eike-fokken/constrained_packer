cmake_minimum_required (VERSION 3.9)
# 3.9 is needed for CheckIPOSupported and for doxygen_add_docs.

project(test_consumecasadi LANGUAGES C CXX)


#for multiple compiler compatibility:
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

#for development:
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_subdirectory(consumecasadi)
add_subdirectory(src)

