/** nl.cpp, migrated from nl.c from coreutils
 * nl -- number lines of files
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
 * Scott Bartram <nancy!scott@uunet.uu.net>
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
#define PROGRAM_NAME nl

#define VERSION F_VERSION(PROGRAM_NAME)

constexpr auto USAGE =
R"(nl.

     Usage:
       nl [options] [ FILES... ]

       Write each FILE to standard output, with line numbers added.

     Options:
       -h --help                      Show this screen
       --version                      Show version
       -b, --body-numbering=STYLE     Use STYLE for numbering body lines
       -d, --section-delimiter=CC     Use CC for logical page delimiters
       -f, --footer-numbering=STYLE   Use STYLE for numbering footer lines
       -h, --header-numbering=STYLE   Use STYLE for numbering header lines
       -i, --line-increment=NUMBER    Line number increment at each line
       -l, --join-blank-lines=NUMBER  Group of NUMBER empty lines counted as one
       -n, --number-format=FORMAT     Insert line numbers according to FORMAT
       -p, --no-renumber              Do not reset line numbers for each section
       -s, --number-separator=STRING  Add STRING after (possible) line number
       -v, --starting-line-number=NUMBER
                                      First line number for each section
       -w, --number-width=NUMBER      Use NUMBER columns for line numbers

     Note:

       Default options are: -bt -d'\\:' -fn -hn -i1 -l1 -n'rn' -s<TAB> -v1 -w6

       CC are two delimiter characters used to construct logical page delimiters;
         a missing second character implies ':'.

       STYLE is one of:
         a      number all lines
         t      number only nonempty lines
         n      number no lines
         pBRE   number only lines that contain a match for the basic regular
                  expression, BRE

       FORMAT is one of:
         ln     left justified, no leading zeros
         rn     right justified, no leading zeros
         rz     right justified, leading zeros
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
