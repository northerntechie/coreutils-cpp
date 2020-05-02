/** printf.cpp, migrated from printf.c from coreutils
 * printf - format and print data
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
#define PROGRAM_NAME printf

#define VERSION F_VERSION(PROGRAM_NAME)

constexpr auto USAGE =
R"(printf.

     Usage:
       printf [options]
       printf FORMAT [ARGUMENTS...]

     Print ARGUMENT(s) according to FORMAT, or execute according to OPTION:

     Options:
       -h --help              Show this screen
       --version              Show version

     Note:

       FORMAT controls the output as in C printf.  Interpreted sequences are:
         \\\"      double quote
         \\\\      backslash
         \\a      alert (BEL)
         \\b      backspace
         \\c      produce no further output
         \\e      escape
         \\f      form feed
         \\n      new line
         \\r      carriage return
         \\t      horizontal tab
         \\v      vertical tab
         \\NNN    byte with octal value NNN (1 to 3 digits)
         \\xHH    byte with hexadecimal value HH (1 to 2 digits)
         \\uHHHH  Unicode (ISO/IEC 10646) character with hex value HHHH (4 digits)
         \\UHHHHHHHH  Unicode character with hex value HHHHHHHH (8 digits)
         %%       a single %
         %b       ARGUMENT as a string with '\\' escapes interpreted,
                    except that octal escapes are of the form \\0 or \\0NNN
         %q       ARGUMENT is printed in a format that can be reused as shell input,
                    escaping non-printable characters with the proposed POSIX $'' syntax.

       and all C format specifications ending with one of diouxXfeEgGcs, with
         ARGUMENTs converted to proper type first.  Variable widths are handled.
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
