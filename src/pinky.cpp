/** pinky.cpp, migrated from pinky.c from coreutils
 * GNU's pinky
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
 * Joseph Arceneaux
 * David MacKenzie
 * Kaveh Ghazi
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
#define PROGRAM_NAME pinky

#define VERSION F_VERSION(PROGRAM_NAME)

constexpr auto USAGE =
R"(pinky.

     Usage:
       pinky [options] [ USER... ]

       A lightweight 'finger' program;  print user information.
         The utmp file will be pinky.

     Options:
       -h --help       Show this screen
       --version       Show version
       -l              Produce long format output for the specified USERs
       -b              Omit the user's home directory and shell in long format
       -h              Omit the user's project file in long format
       -p              Omit the user's plan file in long format
       -s              Do short format output, this is the default
       -f              Omit the line of column headings in short format
       -w              Omit the user's full name in short format
       -i              Omit the user's full name and remote host in short format
       -q              Omit the user's full name, remote host and idle time
                         in short format
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
