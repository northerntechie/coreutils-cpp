/* basename.cpp, migrated from basename.c from coreutils
Copyright (C) 1987-2020 Free Software Foundation, Inc.

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

Migrated C++ code Copyright (C) Todd Saharchuk, 2020.

*/

// C++ includes
#include <iostream>
#include <map>
#include <string>
#include "docopt/docopt.h"
// End of C++ includes

/* The official name of this program (e.g., no 'g' prefix).  */
#define PROGRAM_NAME ""

constexpr auto USAGE =
R"(basename.

     Usage:
       basename [ -a NAME... | --multiple NAME... ] [-s SUFFIX | --suffix=SUFFIX ]
         [ -z | --zero ] [ NAME SUFFIX ]

         Print NAME with any leading directory components removed.
         If specified, also remove a trailing SUFFIX.

     Options:
       -a, --multiple       Support multiple arguments and treat each as a NAME
       -s, --suffix=SUFFIX  Remove a trailing SUFFIX; implies -a.
       -z, --zero           End each output line with NUL, not newline.


     Examples:
       basename /usr/bin/sort          -> "sort"
       basename include/stdio.h .h     -> "stdio"
       basename -s .h include/stdio.h  -> \"stdio\"\n\
  %s -a any/str1 any/str2   -> \"str1\" followed by \"str2\"\n\



)";

int main(int argc, char** argv)
{
    std::map<std::string, docopt::value> args =
        docopt::docopt(USAGE,
                       {argv+1, argv+argc},
                        true,
                        "basename (cpp) 0.1.0");

    for(auto kv : args)
    {
        std::cout << kv.first << " : " << kv.second << "\n";
    }

    return EXIT_SUCCESS;
}
