/** comm.cpp, migrated from comm.c from coreutils
 * comm -- compare two sorted files line by line.
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
 * Richard Stallman
 * David MacKenzie
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
#define PROGRAM_NAME ""
#define AUTHORS ""
constexpr auto USAGE =
R"(comm.

     Usage:
       comm [options] FILE1 FILE2

       Compare sorted files FILE1 and FILE2 line by line.
         When FILE1 or FILE2 (not both) is -, read standard input.
         With no options, produce three-column output.  Column one contains
         lines unique to FILE1, column two contains lines unique to FILE2,
         and column three contains lines common to both files.

     Options:
       -1                      Suppress column 1 (lines unique to FILE1)
       -2                      Suppress column 2 (lines unique to FILE2)
       -3                      Suppress column 3 (lines that appear in both files)
       --check-order           Check that the input is correctly sorted, even
                                 if all input lines are pairable
       --nocheck-order         Do not check that the input is correctly sorted
       --output-delimiter=STR  Separate columns with STR
       --total                 Output a summary
       -z, --zero-terminated   Line delimiter is NUL, not newline

     Note:

       Comparisons honor the rules specified by 'LC_COLLATE'.

     Examples:

       comm -12 file1 file2  Print only lines present in both file1 and file2.
       comm -3 file1 file2  Print lines in file1 not in file2, and vice versa.
)";

int main(int argc, char** argv)
{
    std::map<std::string, docopt::value> args =
        docopt::docopt(USAGE,
                       {argv+1, argv+argc},
                        true,
                        "comm (cpp) 0.1.0");

    // TODO(northerntechie): Finish implementation
    for(auto kv : args)
    {
        std::cout << kv.first << " : " << kv.second << "\n";
    }

    return EXIT_SUCCESS;
}
