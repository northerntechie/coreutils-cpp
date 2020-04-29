/** dirname.cpp, migrated from dirname.c from coreutils
 * dirname -- strip suffix from file name
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
 * David MacKenzie
 * Jim Meyering
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
#define PROGRAM_NAME "dirname"

constexpr auto VERSION = cc::versionString(PROGRAM_NAME);

constexpr auto USAGE =
R"(dirname.

     Usage:
       dirname [options] NAME...

       Output each NAME with its last non-slash component and trailing slashes
         removed; if NAME contains no /'s, output '.' (meaning the current directory).

     Options:
       -h --help              Show this screen
       --version              Show version
       -z, --zero             End each output line with NUL, not newline

     Examples:

       dirname /usr/bin/          -> \"/usr\"
       dirname dir1/str dir2/str  -> \"dir1\" followed by \"dir2\"
       dirname stdio.h            -> \".\"
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
