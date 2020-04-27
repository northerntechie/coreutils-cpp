cmake_minimum_required(VERSION 3.15)

project(coreutils_cpp LANGUAGES CXX)


set(CMAKE_RUNTIME_OUTPUT_DIRECTORY build)

set(CMAKE_CXX_STANDARD 20)

include_directories(src/include)

find_package(docopt 0.6 REQUIRED)

add_executable(echo
        src/include/globals.h
        src/echo.cpp)
target_link_libraries(echo docopt)

add_executable(touch
        src/include/globals.h
        src/touch.cpp)
target_link_libraries(touch docopt)

add_executable(b2sum
        src/include/globals.h
        src/b2sum.cpp)
target_link_libraries(b2sum docopt)

add_executable(basename
        src/include/globals.h
        src/basename.cpp)
target_link_libraries(basename docopt)

add_executable(basenc
        src/include/globals.h
        src/basenc.cpp)
target_link_Libraries(basenc docopt)

add_executable(cat
        src/include/globals.h
        src/cat.cpp)
target_link_libraries(cat docopt)

add_executable(chcon
        src/include/globals.h
        src/chcon.cpp)
target_link_libraries(chcon docopt)

add_executable(chgrp
        src/include/globals.h
        src/chgrp.cpp)
target_link_libraries(chgrp docopt)

add_executable(chmod
        src/include/globals.h
        src/chmod.cpp)
target_link_libraries(chmod docopt)