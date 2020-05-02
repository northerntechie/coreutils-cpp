/** readlink.cpp, migrated from readlink.c from coreutils
 * readlink -- display value of a symbolic link.
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
 * Dmitry V. Levin
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
#define PROGRAM_NAME readlink

#define VERSION F_VERSION(PROGRAM_NAME)

constexpr auto USAGE =
R"(readlink.

     Usage:
       readlink [options] FILE...

       Print value of a symbolic link or canonical file name.

     Options:
       -h --help              Show this screen
       --version              Show version
       -f, --canonicalize     Canonicalize by following every symlink in
                                every component of the given name recursively;
                                all but the last component must exist
       -e, --canonicalize-existing
                              Canonicalize by following every symlink in
                                every component of the given name recursively,
                                all components must exist
       -m, --canonicalize-missing
                              Canonicalize by following every symlink in
                                every component of the given name recursively,
                                without requirements on components existence
       -n, --no-newline       Do not output the trailing delimiter
       -q, --quiet
       -s, --silent           Suppress most error messages (on by default)
       -v, --verbose          Report error messages
       -z, --zero             End each output line with NUL, not newline
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
