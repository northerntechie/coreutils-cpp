/** tee.cpp, migrated from tee.c from coreutils
 * tee - read from standard input and write to standard output and files.
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
 * Mike Parker
 * Richard M. Stallman
 * David MacKenzie
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
#define PROGRAM_NAME tee

#define VERSION F_VERSION(PROGRAM_NAME)

constexpr auto USAGE =
R"(tee.

     Usage:
       tee [options] [FILE...]

       Copy standard input to each FILE, and also to standard output.

     Options:
       -h --help                Show this screen
       --version                Show version
       -a, --append             Append to the given FILEs, do not overwrite
       -i, --ignore-interrupts  Ignore interrupt signals
       -p                       Diagnose errors writing to non pipes
       --output-error[=MODE]    Set behavior on write error.  See MODE below

     Note:

       MODE determines behavior with write errors on the outputs:
         'warn'         diagnose errors writing to any output
         'warn-nopipe'  diagnose errors writing to any output not a pipe
         'exit'         exit on error writing to any output
         'exit-nopipe'  exit on error writing to any output not a pipe
       The default MODE for the -p option is 'warn-nopipe'.
         The default operation when --output-error is not specified, is to
         exit immediately on error writing to a pipe, and diagnose errors
         writing to non pipe outputs.
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
