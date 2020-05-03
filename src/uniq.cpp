/** uniq.cpp, migrated from uniq.c from coreutils
 * uniq -- remove duplicate lines from a sorted file
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
#define PROGRAM_NAME uniq

#define VERSION F_VERSION(PROGRAM_NAME)

constexpr auto USAGE =
R"(uniq.

     Usage:
       uniq [options] [INPUT [OUTPUT] ]

       Filter adjacent matching lines from INPUT (or standard input),
         writing to OUTPUT (or standard output).
         With no options, matching lines are merged to the first occurrence.

     Options:
       -h --help                Show this screen
       --version                Show version
       -c, --count              Prefix lines by the number of occurrences
       -d, --repeated           Only print duplicate lines, one for each group
       -D                       Print all duplicate lines\n\
       --all-repeated[=METHOD]  Like -D, but allow separating groups
                                  with an empty line;
                                  METHOD={none(default),prepend,separate}
       -f, --skip-fields=N      Avoid comparing the first N fields
       --group[=METHOD]         Show all items, separating groups with an empty line;
                                  METHOD={separate(default),prepend,append,both}
       -i, --ignore-case        Ignore differences in case when comparing
       -s, --skip-chars=N       Avoid comparing the first N characters
       -u, --unique             Only print unique lines
       -z, --zero-terminated    Line delimiter is NUL, not newline
       -w, --check-chars=N      Compare no more than N characters in lines

     Note:

       A field is a run of blanks (usually spaces and/or TABs), then non-blank
         characters.  Fields are skipped before chars.
       Note: 'uniq' does not detect repeated lines unless they are adjacent.
         You may want to sort the input first, or use 'sort -u' without 'uniq'.
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
