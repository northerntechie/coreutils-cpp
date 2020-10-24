/* basename.cpp, migrated from basename.c from coreutils
   cat -- concatenate files and print on the standard output.

 /*
   Copyright (C) 1988-2020 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.

   Differences from the Unix cat:
   * Always unbuffered, -u is ignored.
   * Usually much faster than other versions of cat, the difference
   is especially apparent when using the -v option.

   By tege@sics.se, Torbjorn Granlund, advised by rms, Richard Stallman.

   Migrated C++ code Copyright (C) Todd Saharchuk, 2020.
*/

// C++ includes
#include <iostream>
#include <map>
#include <string>
#include "docopt/docopt.h"
// End of C++ includes

/* The official name of this program (e.g., no 'g' prefix).  */
#define PROGRAM_NAME "cat"

constexpr auto USAGE =
R"(cat.

     Usage:
       cat [options] [FILE | - ]...

       Concatenate FILE(s) to standard output.

     Options:
       -A, --show-all           Equivalent to -vET
       -b, --number-nonblank    Number nonempty output lines, overrides -n
       -e                       Equivalent to -vE
       -E, --show-ends          Display $ at end of each line
       -n, --number             Number all output lines
       -s, --squeeze-blank      Suppress repeated empty output lines
       -t                       Equivalent to -vT
       -T, --show-tabs          Display TAB characters as ^I
       -u                       (ignored)
       -v, --show-nonprinting   Use ^ and M- notation, except for LFD and TAB

     Examples:
       cat f - g  Output f's contents, then standard input, then g's contents.
       cat        Copy standard input to standard output.
)";

int main(int argc, char** argv)
{
    std::map<std::string, docopt::value> args =
        docopt::docopt(USAGE,
                       {argv+1, argv+argc},
                        true,
                        "cat (cpp) 0.1.0");

    // TODO(northerntechie): Finish implementation
    for(auto kv : args)
    {
        std::cout << kv.first << " : " << kv.second << "\n";
    }
    std::cout << "\n";

    return EXIT_SUCCESS;
}
