/** fmt.cpp, migrated from fmt.c from coreutils
 * fmt -- simple text formatter.
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
 * Ross Paterson
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
#define PROGRAM_NAME fmt

#define VERSION F_VERSION(PROGRAM_NAME)

constexpr auto USAGE =
R"(fmt.

     Usage:
       fmt [options] [FILE...]

       Reformat each paragraph in the FILE(s), writing to standard output.
         The option -WIDTH is an abbreviated form of --width=DIGITS.

     Options:
       -h --help               Show this screen
       --version               Show version
       -c, --crown-margin      Preserve indentation of first two lines
       -p, --prefix=STRING     Reformat only lines beginning with STRING,
                                 reattaching the prefix to reformatted lines
       -s, --split-only        Split long lines, but do not refill
       -t, --tagged-paragraph  Indentation of first line different from second
       -u, --uniform-spacing   One space between words, two after sentences
       -w, --width=WIDTH       Maximum line width (default of 75 columns)
       -g, --goal=WIDTH        Goal width (default of 93% of width)
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
