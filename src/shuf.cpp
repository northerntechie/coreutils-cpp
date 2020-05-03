/** shuf.cpp, migrated from shuf.c from coreutils
 * Shuffle lines of text.
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
 * Paul Eggert
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
#define PROGRAM_NAME shuf

#define VERSION F_VERSION(PROGRAM_NAME)

constexpr auto USAGE =
R"(shuf.

     Usage:
       shuf [options] FILE
       shuf -e [options] ARG...
       shuf -i LO-HI [options]

       Write a random permutation of the input lines to standard output.

     Options:
       -h --help                 Show this screen
       --version                 Show version
       -e, --echo                Treat each ARG as an input line
       -i, --input-range=LO-HI   Treat each number LO through HI as an input line
       -n, --head-count=COUNT    Output at most COUNT lines
       -o, --output=FILE         Write result to FILE instead of standard output
       --random-source=FILE      Get random bytes from FILE
       -r, --repeat              Output lines can be repeated
       -z, --zero-terminated     Line delimiter is NUL, not newline
)";

int main(int argc, char** argv)
{
  std::map<std::string, docopt::value> args =
      docopt::docopt (USAGE,
                      {argv + 1, argv + argc},
                      true,
                      VERSION);

  // TODO(@northerntechie): Finish implementation
  for (auto kv : args)
    {
      std::cout << kv.first << " : " << kv.second << "\n";
    }

  std::cout << "Implementation incomplete! Do not use!\n";

  return EXIT_SUCCESS;
}
