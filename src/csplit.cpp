/** csplit.cpp, migrated from csplit.c from coreutils
 * csplit - split a file into sections determined by context lines
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
 * Stuart Kemp, cpsrk@groper.jcu.edu.au.
 * David MacKenzie, djm@gnu.ai.mit.edu.
 *
 * C++ Code migration Todd Saharchuk, tsaharchuk1@athabasca.edu
 */

// C++ includes
#include <iostream>
#include <map>
#include <string>
#include "docopt/docopt.h"
// End of C++ includes

/* The official name of this program (e.g., no 'g' prefix).  */
#define PROGRAM_NAME "csplit"

constexpr auto USAGE =
R"(csplit.

     Usage:
       csplit [options] FILE PATTERN...

       Output pieces of FILE separated by PATTERN(s) to files 'xx00', 'xx01', ...,
         and output byte counts of each piece to standard output.
       Read standard input if FILE is -

     Options:
       -h --help                   Show this screen
       --version                   Show version
       -b, --suffix-format=FORMAT
                                   Use sprintf FORMAT instead of %02d
       -f, --prefix=PREFIX         Use PREFIX instead of 'xx'
       -k, --keep-files            Do not remove output files on errors
       --suppress-matched          Suppress the lines matching PATTERN
       -n, --digits=DIGITS         Use specified number of digits instead of 2
       -s, --quiet, --silent       Do not print counts of output file sizes
       -z, --elide-empty-files     Remove empty output files

     Each PATTERN may be:

       INTEGER                     Copy up to but not including specified line number
       /REGEXP/[OFFSET]            Copy up to but not including a matching line
       %REGEXP%[OFFSET]            Skip to, but not including a matching line
       {INTEGER}                   Repeat the previous pattern specified number of times
       {*}                         Repeat the previous pattern as many times as possible

       A line OFFSET is a required '+' or '-' followed by a positive integer.
)";

int main(int argc, char** argv)
{
    std::map<std::string, docopt::value> args =
        docopt::docopt(USAGE,
                       {argv+1, argv+argc},
                        true,
                        "<prog> (cpp) 0.1.0");

    // TODO(northerntechie): Finish implementation
    for(auto kv : args)
    {
        std::cout << kv.first << " : " << kv.second << "\n";
    }

    return EXIT_SUCCESS;
}
