/** dircolors.cpp, migrated from dircolors.c from coreutils
 * dircolors - output commands to set the LS_COLOR environment variable
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
 * H. Peter Anvin
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
#define PROGRAM_NAME "dircolors"

constexpr auto VERSION = cc::versionString(PROGRAM_NAME);

constexpr auto USAGE =
R"(dircolors.

     Usage:
       dircolors [options] FILE

       Output commands to set the LS_COLORS environment variable.

     Options:
       -h --help                 Show this screen
       --version                 Show version
       -b, --sh, --bourne-shell  Output Bourne shell code to set LS_COLORS
       -c, --csh, --c-shell      Output C shell code to set LS_COLORS
       -p, --print-database      Output defaults

     Note:

       If FILE is specified, read it to determine which colors to use for which
         file types and extensions.  Otherwise, a precompiled database is used.
         For details on the format of these files, run 'dircolors --print-database'.
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
