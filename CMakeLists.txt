cmake_minimum_required(VERSION 3.15)

project(coreutils_cpp LANGUAGES CXX)

# Some of the coreutils original names are reserved in cmake
# turn off policy for the reserved keywords to allow for the
# use of the original coreutils program names
if(POLICY CMP0037)
    cmake_policy(SET CMP0037 OLD)
endif()

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

add_executable(du
        src/include/globals.h
        src/du.cpp)
target_link_libraries(du docopt)

add_executable(env
        src/include/globals.h
        src/env.cpp)
target_link_libraries(env docopt)

add_executable(expand
        src/include/globals.h
        src/expand.cpp)
target_link_libraries(expand docopt)

add_executable(expr
        src/include/globals.h
        src/expr.cpp)
target_link_libraries(expr docopt)

add_executable(factor
        src/include/globals.h
        src/factor.cpp)
target_link_libraries(factor docopt)

add_executable(false
        src/include/globals.h
        src/false.cpp)
target_link_libraries(false docopt)

add_executable(fmt
        src/include/globals.h
        src/fmt.cpp)
target_link_libraries(fmt docopt)

add_executable(fold
        src/include/globals.h
        src/fold.cpp)
target_link_libraries(fold docopt)

add_executable(groups
        src/include/globals.h
        src/groups.cpp)
target_link_libraries(groups docopt)

add_executable(head
        src/include/globals.h
        src/head.cpp)
target_link_libraries(head docopt)

add_executable(hostid
        src/include/globals.h
        src/hostid.cpp)
target_link_libraries(hostid docopt)

add_executable(hostname
        src/include/globals.h
        src/hostname.cpp)
target_link_libraries(hostname docopt)

add_executable(id
        src/include/globals.h
        src/id.cpp)
target_link_libraries(id docopt)

add_executable(install
        src/include/globals.h
        src/install.cpp)
target_link_libraries(install docopt)

add_executable(join
        src/include/globals.h
        src/join.cpp)
target_link_libraries(join docopt)

add_executable(kill
        src/include/globals.h
        src/kill.cpp)
target_link_libraries(kill docopt)

add_executable(link
        src/include/globals.h
        src/link.cpp)
target_link_libraries(link docopt)

add_executable(ln
        src/include/globals.h
        src/ln.cpp)
target_link_libraries(ln docopt)

add_executable(logname
        src/include/globals.h
        src/logname.cpp)
target_link_libraries(logname docopt)

add_executable(ls
        src/include/globals.h
        src/ls.cpp)
target_link_libraries(ls docopt)

add_executable(md5sum
        src/include/globals.h
        src/md5sum.cpp)
target_link_libraries(md5sum docopt)

add_executable(mkdir
        src/include/globals.h
        src/mkdir.cpp)
target_link_libraries(mkdir docopt)

add_executable(mkfifo
        src/include/globals.h
        src/mkfifo.cpp)
target_link_libraries(mkfifo docopt)

add_executable(mknod
        src/include/globals.h
        src/mknod.cpp)
target_link_libraries(mknod docopt)

add_executable(mktemp
        src/include/globals.h
        src/mktemp.cpp)
target_link_libraries(mktemp docopt)

add_executable(mv
        src/include/globals.h
        src/mv.cpp)
target_link_libraries(mv docopt)

add_executable(nice
        src/include/globals.h
        src/nice.cpp)
target_link_libraries(nice docopt)

add_executable(nl
        src/include/globals.h
        src/nl.cpp)
target_link_libraries(nl docopt)

add_executable(nohup
        src/include/globals.h
        src/nohup.cpp)
target_link_libraries(nohup docopt)

add_executable(nproc
        src/include/globals.h
        src/nproc.cpp)
target_link_libraries(nproc docopt)

add_executable(numfmt
        src/include/globals.h
        src/numfmt.cpp)
target_link_libraries(numfmt docopt)

add_executable(od
        src/include/globals.h
        src/od.cpp)
target_link_libraries(od docopt)

add_executable(paste
        src/include/globals.h
        src/paste.cpp)
target_link_libraries(paste docopt)

add_executable(pathchk
        src/include/globals.h
        src/pathchk.cpp)
target_link_libraries(pathchk docopt)

add_executable(pinky
        src/include/globals.h
        src/pinky.cpp)
target_link_libraries(pinky docopt)

add_executable(pr
        src/include/globals.h
        src/pr.cpp)
target_link_libraries(pr docopt)

add_executable(printenv
        src/include/globals.h
        src/printenv.cpp)
target_link_libraries(printenv docopt)

add_executable(ptx
        src/include/globals.h
        src/ptx.cpp)
target_link_libraries(ptx docopt)

add_executable(printf
        src/include/globals.h
        src/printf.cpp)
target_link_libraries(printf docopt)

add_executable(pwd
        src/include/globals.h
        src/pwd.cpp)
target_link_libraries(pwd docopt)

add_executable(readlink
        src/include/globals.h
        src/readlink.cpp)
target_link_libraries(readlink docopt)

add_executable(realpath
        src/include/globals.h
        src/realpath.cpp)
target_link_libraries(realpath docopt)

add_executable(rm
        src/include/globals.h
        src/rm.cpp)
target_link_libraries(rm docopt)

add_executable(rmdir
        src/include/globals.h
        src/rmdir.cpp)
target_link_libraries(rmdir docopt)

add_executable(runcon
        src/include/globals.h
        src/runcon.cpp)
target_link_libraries(runcon docopt)

add_executable(seq
        src/include/globals.h
        src/seq.cpp)
target_link_libraries(seq docopt)

add_executable(shred
        src/include/globals.h
        src/shred.cpp)
target_link_libraries(shred docopt)

add_executable(shuf
        src/include/globals.h
        src/shuf.cpp)
target_link_libraries(shuf docopt)

add_executable(sleep
        src/include/globals.h
        src/sleep.cpp)
target_link_libraries(sleep docopt)

add_executable(sort
        src/include/globals.h
        src/sort.cpp)
target_link_libraries(sort docopt)

add_executable(split
        src/include/globals.h
        src/split.cpp)
target_link_libraries(split docopt)

add_executable(stat
        src/include/globals.h
        src/stat.cpp)
target_link_libraries(stat docopt)

add_executable(stdbuf
        src/include/globals.h
        src/stdbuf.cpp)
target_link_libraries(stdbuf docopt)

add_executable(stty
        src/include/globals.h
        src/stty.cpp)
target_link_libraries(stty docopt)

add_executable(sum
        src/include/globals.h
        src/sum.cpp)
target_link_libraries(sum docopt)

add_executable(sync
        src/include/globals.h
        src/sync.cpp)
target_link_libraries(sync docopt)

add_executable(tac
        src/include/globals.h
        src/tac.cpp)
target_link_libraries(tac docopt)

add_executable(tail
        src/include/globals.h
        src/tail.cpp)
target_link_libraries(tail docopt)

add_executable(tee
        src/include/globals.h
        src/tee.cpp)
target_link_libraries(tee docopt)

add_executable(test
        src/include/globals.h
        src/test.cpp)
target_link_libraries(test docopt)

add_executable(timeout
        src/include/globals.h
        src/timeout.cpp)
target_link_libraries(timeout docopt)

add_executable(tr
        src/include/globals.h
        src/tr.cpp)
target_link_libraries(tr docopt)

add_executable(true
        src/include/globals.h
        src/true.cpp)
target_link_libraries(true docopt)

add_executable(truncate
        src/include/globals.h
        src/truncate.cpp)
target_link_libraries(truncate docopt)

add_executable(tsort
        src/include/globals.h
        src/tsort.cpp)
target_link_libraries(tsort docopt)

add_executable(tty
        src/include/globals.h
        src/tty.cpp)
target_link_libraries(tty docopt)

add_executable(uname
        src/include/globals.h
        src/uname.cpp)
target_link_libraries(uname docopt)

add_executable(unexpand
        src/include/globals.h
        src/unexpand.cpp)
target_link_libraries(unexpand docopt)

add_executable(uniq
        src/include/globals.h
        src/uniq.cpp)
target_link_libraries(uniq docopt)

add_executable(unlink
        src/include/globals.h
        src/unlink.cpp)
target_link_libraries(unlink docopt)

add_executable(uptime
        src/include/globals.h
        src/uptime.cpp)
target_link_libraries(uptime docopt)

add_executable(users
        src/include/globals.h
        src/users.cpp)
target_link_libraries(users docopt)

add_executable(wc
        src/include/globals.h
        src/wc.cpp)
target_link_libraries(wc docopt)

add_executable(who
        src/include/globals.h
        src/who.cpp)
target_link_libraries(who docopt)

add_executable(whoami
        src/include/globals.h
        src/whoami.cpp)
target_link_libraries(whoami docopt)

add_executable(yes
        src/include/globals.h
        src/yes.cpp)
target_link_libraries(yes docopt)