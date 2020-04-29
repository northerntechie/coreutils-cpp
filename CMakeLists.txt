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

add_executable(chown
        src/include/globals.h
        src/chown.cpp)
target_link_libraries(chown docopt)

add_executable(chroot
        src/include/globals.h
        src/chroot.cpp)
target_link_libraries(chroot docopt)

add_executable(cksum
        src/include/globals.h
        src/cksum.cpp)
target_link_libraries(cksum docopt)

add_executable(comm
        src/include/globals.h
        src/comm.cpp)
target_link_libraries(comm docopt)

add_executable(coreutils
        src/include/globals.h
        src/coreutils.cpp)
target_link_libraries(coreutils docopt)

add_executable(cp
        src/include/globals.h
        src/cp.cpp)
target_link_libraries(cp docopt)

add_executable(csplit
        src/include/globals.h
        src/csplit.cpp)
target_link_libraries(csplit docopt)

add_executable(cut
        src/include/globals.h
        src/cut.cpp)
target_link_libraries(cut docopt)

add_executable(date
        src/include/globals.h
        src/date.cpp)
target_link_libraries(date docopt)

add_executable(dd
        src/include/globals.h
        src/dd.cpp)
target_link_libraries(dd docopt)

add_executable(df
        src/include/globals.h
        src/df.cpp)
target_link_libraries(df docopt)

add_executable(dircolors
        src/include/globals.h
        src/dircolors.cpp)
target_link_libraries(dircolors docopt)

add_executable(dirname
        src/include/globals.h
        src/dirname.cpp)
target_link_libraries(dirname docopt)