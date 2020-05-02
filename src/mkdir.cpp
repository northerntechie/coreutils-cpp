/** mkdir.cpp, migrated from mkdir.c from coreutils
 * mkdir -- make directories
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
 * David MacKenzie <djm@ai.mit.edu>
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
#define PROGRAM_NAME mkdir

#define VERSION F_VERSION(PROGRAM_NAME)

constexpr auto USAGE =
R"(mkdir.

     Usage:
       mkdir [options] [ DIRECTORY | DIRECTORIES... ]

       Create the DIRECTORY(ies), if they do not already exist.

     Options:
       -h --help              Show this screen
       --version              Show version
       -m, --mode=MODE        Set file mode (as in chmod), not a=rwx - umask
       -p, --parents          No error if existing, make parent directories as needed
       -v, --verbose          Print a message for each created directory
       -Z                     Set SELinux security context of each created directory
                                to the default type
       --context[=CTX]        Like -Z, or if CTX is specified then set the SELinux
                                or SMACK security context to CTX
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
