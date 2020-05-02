/** realpath.cpp, migrated from realpath.c from coreutils
 * realpath - print the resolved path
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
 * Padraig Brady
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
#define PROGRAM_NAME realpath

#define VERSION F_VERSION(PROGRAM_NAME)

constexpr auto USAGE =
R"(realpath.

     Usage:
       realpath [options] FILE...

       Print the resolved absolute file name;
         all but the last component must exist

     Options:
       -h --help                    Show this screen
       --version                    Show version
       -e, --canonicalize-existing  All components of the path must exist
       -m, --canonicalize-missing   No path components need exist or be a directory
       -L, --logical                Resolve '..' components before symlinks
       -P, --physical               Resolve symlinks as encountered (default)
       -q, --quiet                  Suppress most error messages
       --relative-to=DIR            Print the resolved path relative to DIR
       --relative-base=DIR          Print absolute paths unless paths below DIR
       -s, --strip, --no-symlinks   Don't expand symlinks
       -z, --zero                   End each output line with NUL, not newline
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
