/** join.cpp, migrated from join.c from coreutils
 * join - join lines of two files on a common field
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
 * Mike Haertel <mike@gnu.ai.mit.edu>
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
#define PROGRAM_NAME join

#define VERSION F_VERSION(PROGRAM_NAME)

constexpr auto USAGE =
R"(join.

     Usage:
       join [options] FILE1 FILE2

       For each pair of input lines with identical join fields, write a line to
         standard output.  The default join field is the first, delimited by blanks.
         When FILE1 or FILE2 (not both) is -, read standard input.

     Options:
       -h --help              Show this screen
       --version              Show version
       -a FILENUM             Also print unpairable lines from file FILENUM, where
                                FILENUM is 1 or 2, corresponding to FILE1 or FILE2
       -e EMPTY               Replace missing input fields with EMPTY
       -i, --ignore-case      Ignore differences in case when comparing fields
       -j FIELD               Equivalent to '-1 FIELD -2 FIELD'
       -o FORMAT              Obey FORMAT while constructing output line
       -t CHAR                Use CHAR as input and output field separator
       -v FILENUM             Like -a FILENUM, but suppress joined output lines
       -1 FIELD               Join on this FIELD of file 1
       -2 FIELD               Join on this FIELD of file 2
       --check-order          Check that the input is correctly sorted, even
                                if all input lines are pairable
       --nocheck-order        Do not check that the input is correctly sorted
       --header               Treat the first line in each file as field headers,
                                print them without trying to pair them
       -z, --zero-terminated  Line delimiter is NUL, not newline

     Note:

       Unless -t CHAR is given, leading blanks separate fields and are ignored,
         else fields are separated by CHAR.  Any FIELD is a field number counted
         from 1.  FORMAT is one or more comma or blank separated specifications,
         each being 'FILENUM.FIELD' or '0'.  Default FORMAT outputs the join field,
         the remaining fields from FILE1, the remaining fields from FILE2, all
         separated by CHAR.  If FORMAT is the keyword 'auto', then the first
         line of each file determines the number of fields output for each line.

     Important:

       FILE1 and FILE2 must be sorted on the join fields.
         E.g., use \"sort -k 1b,1\" if 'join' has no options,
         or use \"join -t ''\" if 'sort' has no options.
         Note, comparisons honor the rules specified by 'LC_COLLATE'.
         If the input is not sorted and some lines cannot be joined, a
         warning message will be given.
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
