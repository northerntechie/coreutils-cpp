cmake_minimum_required(VERSION 3.10)
project(coreutils_cpp)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY build)

set(CMAKE_CXX_STANDARD 17)

include_directories(src/include)

add_executable(echo
        src/include/getoptions.h
        src/include/globals.h
        src/echo.cpp)

add_executable(ut_getoptions
        src/include/getoptions.h
        src/include/globals.h
        src/tests/ut_getoptions.cpp)

