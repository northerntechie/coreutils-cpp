/** df.cpp, migrated from df.c from coreutils
 * df - summarize free disk space
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
 * David MacKenzie <djm@gnu.ai.mit.edu>
 * Paul Eggert <eggert@twinsun.com>
 * Torbjorn Granlund
 * lm@sgi.com
 *
 * C++ Code migration:
 * Todd Saharchuk <tsaharchuk1@athabasca.edu>
 */

// C++ includes
#include <iostream>
#include <map>
#include <string>
#include "docopt/docopt.h"
#include "globals.h"
// End of C++ includes

/* The official name of this program (e.g., no 'g' prefix).  */
#define PROGRAM_NAME "df"

constexpr auto VERSION = cc::versionString(PROGRAM_NAME);

constexpr auto USAGE =
R"(df.

     Usage:
       df [options] FILE...

       Show information about the file system on which each FILE resides,
         or all file systems by default.

     Options:
       -h --help              Show this screen
       --version              Show version
       -a, --all              Include pseudo, duplicate, inaccessible file systems
       -B, --block-size=SIZE  Scale sizes by SIZE before printing them; e.g.,
                                '-BM' prints sizes in units of 1,048,576 bytes;
                                see SIZE format below
       -h, --human-readable   Print sizes in powers of 1024 (e.g., 1023M)
       -H, --si               Print sizes in powers of 1000 (e.g., 1.1G)
       -i, --inodes           List inode information instead of block usage
       -k                     Like --block-size=1K
       -l, --local            Limit listing to local file systems
       --no-sync              Do not invoke sync before getting usage info (default)
       --output[=FIELD_LIST]  Use the output format defined by FIELD_LIST,
                                or print all fields if FIELD_LIST is omitted.
       -P, --portability      Use the POSIX output format
       --sync                 Invoke sync before getting usage info
       --total                Elide all entries insignificant to available space,
                                and produce a grand total
       -t, --type=TYPE        Limit listing to file systems of type TYPE
       -T, --print-type       Print file system type
       -x, --exclude-type=TYPE
                              Limit listing to file systems not of type TYPE

     Notes:

       FIELD_LIST is a comma-separated list of columns to be included.  Valid
         field names are: 'source', 'fstype', 'itotal', 'iused', 'iavail', 'ipcent',
         'size', 'used', 'avail', 'pcent', 'file' and 'target' (see info page).
)";

int main(int argc, char** argv)
{
    std::map<std::string, docopt::value> args =
        docopt::docopt(USAGE,
                       {argv+1, argv+argc},
                        true,
                        VERSION.data());

    // TODO(northerntechie): Finish implementation
    for(auto kv : args)
    {
        std::cout << kv.first << " : " << kv.second << "\n";
    }

    return EXIT_SUCCESS;
}
