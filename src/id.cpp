/** id.cpp, migrated from id.c from coreutils
 * id -- print real and effective UIDs and GIDs
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
 * Arnold Robbins
 * David MacKenzie <djm@gnu.ai.mit.edu>
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
#define PROGRAM_NAME id

#define VERSION F_VERSION(PROGRAM_NAME)

constexpr auto USAGE =
R"(id.

     Usage:
       id [options] [USER...]

       Print user and group information for each specified USER,
         or (when USER omitted) for the current user.

     Options:
       -h --help              Show this screen
       --version              Show version
       -a                     Ignore, for compatibility with other versions
       -Z, --context          Print only the security context of the process
       -g, --group            Print only the effective group ID
       -G, --groups           Print all group IDs
       -n, --name             Print a name instead of a number, for -ugG
       -r, --real             Print the real ID instead of the effective ID, with -ugG
       -u, --user             Print only the effective user ID
       -z, --zero             Delimit entries with NUL characters, not whitespace;
                                not permitted in default format

     Note:

       Without any OPTION, print some useful set of identified information.
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
