/** mknod.cpp, migrated from mknod.c from coreutils
 * mknod -- make special files
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
 * David MacKenzie <djm@ai.mit.edu>
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
#define PROGRAM_NAME mknod

#define VERSION F_VERSION(PROGRAM_NAME)

constexpr auto USAGE =
R"(mknod.

     Usage:
       mknod [options] NAME TYPE [ MAJOR MINOR ]

       Create the special file NAME of the given TYPE.

     Options:
       -h --help              Show this screen
       --version              Show version
       -m, --mode=MODE        Set file permission bits to MODE, not a=rw - umask
       -Z                     Set the SELinux security context to default type
       --context[=CTX]        Like -Z, or if CTX is specified then set the SELinux
                                or SMACK security context to CTX

     Note:

       Both MAJOR and MINOR must be specified when TYPE is b, c, or u, and they
         must be omitted when TYPE is p.  If MAJOR or MINOR begins with 0x or 0X,
         it is interpreted as hexadecimal; otherwise, if it begins with 0, as octal;
         otherwise, as decimal.  TYPE may be:

         b      create a block (buffered) special file
         c, u   create a character (unbuffered) special file
         p      create a FIFO
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
