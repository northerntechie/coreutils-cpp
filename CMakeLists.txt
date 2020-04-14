cmake_minimum_required(VERSION 3.10)
project(coreutils_cpp)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY build)

set(CMAKE_CXX_STANDARD 17)

include_directories(src/include)

find_package(Boost 1.65 REQUIRED COMPONENTS
        program_options)
find_package(docopt 0.6 REQUIRED)

add_executable(echo
        src/include/getoptions.h
        src/include/globals.h
        src/echo.cpp)
target_link_libraries(echo Boost::program_options)
target
add_executable(ut_getoptions
        src/include/getoptions.h
        src/include/globals.h
        src/tests/ut_getoptions.cpp)

