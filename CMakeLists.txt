cmake_minimum_required(VERSION 3.21)

if (NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif()

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
project(hon)

# include(FetchContent)
# FetchContent_Declare(cxxopts GIT_REPOSITORY https://github.com/jarro2783/cxxopts.git)
# FetchContent_MakeAvailable(cxxopts)

file(GLOB src_files src/*.cpp)
list(LENGTH src_files file_num)
message(STATUS "Source files (${file_num})")
foreach(file ${src_files})
message(${file})
endforeach()
message("")

add_executable(main main.cpp ${src_files})
target_include_directories(main PRIVATE src)
# target_link_libraries(main PRIVATE cxxopts)
