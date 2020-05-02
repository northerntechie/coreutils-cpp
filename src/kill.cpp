/** kill.cpp, migrated from kill.c from coreutils
 * kill -- send a signal to a process
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
#define PROGRAM_NAME kill

#define VERSION F_VERSION(PROGRAM_NAME)

constexpr auto USAGE =
R"(kill.

     Usage:
       kill [ -s SIGNAL | -SIGNAL ] PID...
       kill -l SIGNALS...
       kill -t SIGNALS...

       Send signals to processes, or list signals.

     Options:
       -h --help                     Show this screen
       --version                     Show version
       -s, --signal=SIGNAL, -SIGNAL  Specify the name or number of the signal to be sent
       -l, --list                    List signal names, or convert signal names to/from numbers
       -t, --table                   Print a table of signal information

     Note:

       SIGNAL may be a signal name like 'HUP', or a signal number like '1',
         or the exit status of a process terminated by a signal.
         PID is an integer; if negative it identifies a process group.
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
