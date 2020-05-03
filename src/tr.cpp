/** tr.cpp, migrated from tr.c from coreutils
 * tr -- a filter to translate characters
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
 * Jim Meyering
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
#define PROGRAM_NAME tr

#define VERSION F_VERSION(PROGRAM_NAME)

constexpr auto USAGE =
R"(tr.

     Usage:
       tr [options] SET1 [SET2]

       Translate, squeeze, and/or delete characters from standard input,
         writing to standard output.

     Options:
       -h --help               Show this screen
       --version               Show version
       -c, -C, --complement    Use the complement of SET1
       -d, --delete            Delete characters in SET1, do not translate
       -s, --squeeze-repeats   Replace each sequence of a repeated character
                                 that is listed in the last specified SET,
                                 with a single occurrence of that character
       -t, --truncate-set1     First truncate SET1 to length of SET2

     SETs are specified as strings of characters.  Most represent themselves.
       Interpreted sequences are:
         \\NNN            character with octal value NNN (1 to 3 octal digits)
         \\\\             backslash
         \\a              audible BEL
         \\b              backspace
         \\f              form feed
         \\n              new line
         \\r              return
         \\t              horizontal tab
         \\v              vertical tab
         CHAR1-CHAR2     all characters from CHAR1 to CHAR2 in ascending order
         [CHAR*]         in SET2, copies of CHAR until length of SET1
         [CHAR*REPEAT]   REPEAT copies of CHAR, REPEAT octal if starting with 0
         [:alnum:]       all letters and digits
         [:alpha:]       all letters
         [:blank:]       all horizontal whitespace
         [:cntrl:]       all control characters
         [:digit:]       all digits
         [:graph:]       all printable characters, not including space
         [:lower:]       all lower case letters
         [:print:]       all printable characters, including space
         [:punct:]       all punctuation characters
         [:space:]       all horizontal or vertical whitespace
         [:upper:]       all upper case letters
         [:xdigit:]      all hexadecimal digits
         [=CHAR=]        all characters which are equivalent to CHAR

       Translation occurs if -d is not given and both SET1 and SET2 appear.
         -t may be used only when translating.  SET2 is extended to length of
         SET1 by repeating its last character as necessary.  Excess characters
         of SET2 are ignored.  Only [:lower:] and [:upper:] are guaranteed to
         expand in ascending order; used in SET2 while translating, they may
         only be used in pairs to specify case conversion.  -s uses the last
         specified SET, and occurs after translation or deletion.
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
