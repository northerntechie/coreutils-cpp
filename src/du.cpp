/** du.cpp, migrated from du.c from coreutils
 * du -- summarize disk usage
 * Copyright (C) 1987-2020 Free Software Foundation, Inc.
 * Migrated C++ code Copyright (C) Todd Saharchuk, 2020.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 *
 * Original Authors:
 * Torbjorn Granlund <tege@sics.se>
 * David MacKenzie <djm@ai.mit.edu>
 * Paul Eggert <eggert@twinsun.com>
 * Jim Meyering
 * <lm@sgi.com>
 *
 * C++ Code migration:
 * Todd Saharchuk <tsaharchuk1@athabasca.edu> @northerntechie
 */

// C++ includes
#include <iostream>
#include <map>
#include <string>
#include "docopt/docopt.h"
#include "globals.h"
// End of C++ includes

/* The official name of this program (e.g., no 'g' prefix).  */
#define PROGRAM_NAME du

#define VERSION F_VERSION(PROGRAM_NAME,MAJOR_VER,MINOR_VER,PATCH_VER)

constexpr auto USAGE =
R"(du.

     Usage:
       du [options] FILE...
       du [options] --files0-from=F0

       Summarize disk usage of the set of FILEs, recursively for directories.

     Options:
       -h --help               Show this screen
       --version               Show version
       -0, --null              End each output line with NUL, not newline
       -a, --all               Write counts for all files, not just directories
       --apparent-size         Print apparent sizes, rather than disk usage; although
                                 the apparent size is usually smaller, it may be
                                 larger due to holes in ('sparse') files, internal
                                 fragmentation, indirect blocks, and the like
       -B, --block-size=SIZE   Scale sizes by SIZE before printing them; e.g.,
                                 '-BM' prints sizes in units of 1,048,576 bytes;
                                 see SIZE format below
       -b, --bytes             Equivalent to '--apparent-size --block-size=1'
       -c, --total             Produce a grand total
       -D, --dereference-args  Dereference only symlinks that are listed on the
                                 command line
       -d, --max-depth=N       Print the total for a directory (or file, with --all)
                                 only if it is N or fewer levels below the command
                                 line argument;  --max-depth=0 is the same as
                                 --summarize
       --files0-from=F         Summarize disk usage of the
                                 NUL-terminated file names specified in file F;
                                 if F is -, then read names from standard input
       -H                      Equivalent to --dereference-args (-D)
       -h, --human-readable    Print sizes in human readable format (e.g., 1K 234M 2G)
       --inodes                List inode usage information instead of block usage
       -k                      Like --block-size=1K
       -L, --dereference       Dereference all symbolic links
       -l, --count-links       Count sizes many times if hard linked
       -m                      Like --block-size=1M
       -P, --no-dereference    Don't follow any symbolic links (this is the default)
       -S, --separate-dirs     For directories do not include size of subdirectories
       --si                    Like -h, but use powers of 1000 not 1024
       -s, --summarize         Display only a total for each argument
       -t, --threshold=SIZE    Exclude entries smaller than SIZE if positive,
                                 or entries greater than SIZE if negative
       --time                  Show time of the last modification of any file in the
                                 directory, or any of its subdirectories
       --time=WORD             Show time as WORD instead of modification time:
                                 atime, access, use, ctime or status
       --time-style=STYLE      Show times using STYLE, which can be:
                                 full-iso, long-iso, iso, or +FORMAT;
                                 FORMAT is interpreted like in 'date'
       -X, --exclude-from=FILE
                               Exclude files that match any pattern in FILE
       --exclude=PATTERN       Exclude files that match PATTERN
       -x, --one-file-system   Skip directories on different file systems
)";

int main(int argc, char** argv)
{
    std::map<std::string, docopt::value> args =
        docopt::docopt(USAGE,
                       {argv+1, argv+argc},
                        true,
                        VERSION);

    // TODO(@northerntechie): Finish implementation
    for(auto kv : args)
    {
        std::cout << kv.first << " : " << kv.second << "\n";
    }

    return EXIT_SUCCESS;
}
