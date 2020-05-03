/** who.cpp, migrated from who.c from coreutils
 * GNU's who
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
 * Michael Stone
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
#define PROGRAM_NAME who

#define VERSION F_VERSION(PROGRAM_NAME)

constexpr auto USAGE =
R"(who.

     Usage:
       who [options] [ FILE | ARG1 ARG2 ]

       Print information about users who are currently logged in.

     Options:
       -h --help              Show this screen
       --version              Show version
       -a, --all              Same as -b -d --login -p -r -t -T -u
       -b, --boot             Time of last system boot
       -d, --dead             Print dead processes
       -H, --heading          Print line of column headings
       -l, --login            Print system login processes
       --lookup               Attempt to canonicalize hostnames via DNS
       -m                     Only hostname and user associated with stdin
       -p, --process          Print active processes spawned by init
       -q, --count            All login names and number of users logged on
       -r, --runlevel         Print current runlevel
       -s, --short            Print only name, line, and time (default)
       -t, --time             Print last system clock change
       -T, -w, --mesg         Add user's message status as +, - or ?
       -u, --users            List users logged in
       --message              Same as -T
       --writable             Same as -T
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
