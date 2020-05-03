/** wc.cpp, migrated from wc.c from coreutils
 *
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
 * Paul Rubin <phr@ocf.berkeley.edu>
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
#define PROGRAM_NAME wc

#define VERSION F_VERSION(PROGRAM_NAME)

constexpr auto USAGE =
R"(wc.

     Usage:
       wc [options] [FILES...]
       wc [options] --files0-from=FILE

       Print newline, word, and byte counts for each FILE, and a total line if
         more than one FILE is specified.  A word is a non-zero-length sequence of
         characters delimited by white space.

     Options:
       -h --help              Show this screen
       --version              Show version

       The options below may be used to select which counts are printed, always in
         the following order: newline, word, character, byte, maximum line length.

       -c, --bytes            Print the byte counts
       -m, --chars            Print the character counts
       -l, --lines            Print the newline counts
       --files0-from=FILE     Read input from the files specified by
                                NUL-terminated names in file FILE;
                                If FILE is - then read names from standard input
       -L, --max-line-length  Print the maximum display width
       -w, --words            Print the word counts
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
