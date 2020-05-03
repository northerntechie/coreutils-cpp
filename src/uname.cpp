/** uname.cpp, migrated from uname.c from coreutils
 * uname -- print system information
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
#define PROGRAM_NAME uname

#define VERSION F_VERSION(PROGRAM_NAME)

constexpr auto USAGE =
R"(uname.

     Usage:
       uname [options]

       Print certain system information.  With no OPTION, same as -s.
         Print machine architecture.

     Options:
       -h --help                Show this screen
       --version                Show version
       -a, --all                Print all information, in the following order,
                                  except omit -p and -i if unknown:
       -s, --kernel-name        Print the kernel name
       -n, --nodename           Print the network node hostname
       -r, --kernel-release     Print the kernel release
       -v, --kernel-version     Print the kernel version
       -m, --machine            Print the machine hardware name
       -p, --processor          Print the processor type (non-portable)
       -i, --hardware-platform  Print the hardware platform (non-portable)
       -o, --operating-system   Print the operating system
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
