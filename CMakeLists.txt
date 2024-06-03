cmake_minimum_required(VERSION 3.21)

if (NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif()

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
project(hon)

# if (CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
#     set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Werror -Wall -Wextra -Werror=return-type -Werror=unused-result -Werror=uninitialized -Wno-unused-parameter -Wno-exceptions -Werror=missing-declarations -Werror=missing-field-initializers -Wparentheses -Wconversion -Wsign-conversion")
# endif()

# include(FetchContent)
# FetchContent_Declare(cxxopts GIT_REPOSITORY https://github.com/jarro2783/cxxopts.git)
# FetchContent_MakeAvailable(cxxopts)
add_subdirectory(3rdparty/cxxopts)

file(GLOB src_files src/*.cpp)
list(LENGTH src_files file_num)
message(STATUS "Source files (${file_num})")
foreach(file ${src_files})
message(${file})
endforeach()

add_executable(main main.cpp ${src_files})
target_include_directories(main PRIVATE src 3rdparty/debug-hpp)
target_link_libraries(main PRIVATE cxxopts)
