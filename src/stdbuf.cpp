/** stdbuf.cpp, migrated from stdbuf.c from coreutils
 * stdbuf -- setup the standard streams for a command
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
#define PROGRAM_NAME stdbuf

#define VERSION F_VERSION(PROGRAM_NAME)

constexpr auto USAGE =
R"(stdbuf.

     Usage:
       stdbuf [options] COMMAND

       Run COMMAND, with modified buffering operations for its standard streams.

     Options:
       -h --help              Show this screen
       --version              Show version
       -i, --input=MODE       Adjust standard input stream buffering
       -o, --output=MODE      Adjust standard output stream buffering
       -e, --error=MODE       Adjust standard error stream buffering

     Note:
       If MODE is 'L' the corresponding stream will be line buffered.
         This option is invalid with standard input.
         If MODE is '0' the corresponding stream will be unbuffered.
         Otherwise MODE is a number which may be followed by one of the following:
           KB 1000, K 1024, MB 1000*1000, M 1024*1024, and so on for G, T, P, E, Z, Y.
         Binary prefixes can be used, too: KiB=K, MiB=M, and so on.
         In this case the corresponding stream will be fully buffered with the buffer
         size set to MODE bytes.

       If COMMAND adjusts the buffering of its standard streams ('tee' does
         for example) then that will override corresponding changes by 'stdbuf'.
         Also some filters (like 'dd' and 'cat' etc.) don't use streams for I/O,
         and are thus unaffected by 'stdbuf' settings.
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
