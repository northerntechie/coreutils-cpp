/** seq.cpp, migrated from seq.c from coreutils
 * seq - print sequence of numbers to standard output.
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
 * Ulrich Drepper
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
#define PROGRAM_NAME seq

#define VERSION F_VERSION(PROGRAM_NAME)

constexpr auto USAGE =
R"(seq.

     Usage:
       seq [options] LAST
       seq [options] FIRST LAST
       seq [options] FIRST INCREMENT LAST

       Print numbers from FIRST to LAST, in steps of INCREMENT.

     Options:
       -h --help               Show this screen
       --version               Show version
       -f, --format=FORMAT     Use printf style floating-point FORMAT
       -s, --separator=STRING  Use STRING to separate numbers (default: \\n)
       -w, --equal-width       Equalize width by padding with leading zeroes

     Note:

       If FIRST or INCREMENT is omitted, it defaults to 1.  That is, an
         omitted INCREMENT defaults to 1 even when LAST is smaller than FIRST.
         The sequence of numbers ends when the sum of the current number and
         INCREMENT would become greater than LAST.
         FIRST, INCREMENT, and LAST are interpreted as floating point values.
         INCREMENT is usually positive if FIRST is smaller than LAST, and
         INCREMENT is usually negative if FIRST is greater than LAST.
         INCREMENT must not be 0; none of FIRST, INCREMENT and LAST may be NaN.

       FORMAT must be suitable for printing one argument of type 'double';
         it defaults to %.PRECf if FIRST, INCREMENT, and LAST are all fixed point
         decimal numbers with maximum precision PREC, and to %g otherwise.
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
