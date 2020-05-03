/** truncate.cpp, migrated from truncate.c from coreutils
 * truncate -- truncate or extend the length of files.
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
 * Pádraig Brady
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
#define PROGRAM_NAME truncate

#define VERSION F_VERSION(PROGRAM_NAME)

constexpr auto USAGE =
R"(truncate.

     Usage:
       truncate [options] FILE...

       Shrink or extend the size of each FILE to the specified size
         A FILE argument that does not exist is created.
         If a FILE is larger than the specified size, the extra data is lost.
         If a FILE is shorter, it is extended and the sparse extended part (hole)
           reads as zero bytes.

     Options:
       -h --help              Show this screen
       --version              Show version
       -c, --no-create        Do not create any files
       -o, --io-blocks        Treat SIZE as number of IO blocks instead of bytes
       -r, --reference=RFILE  Base size on RFILE
       -s, --size=SIZE        Set or adjust the file size by SIZE bytes

     Note:

       SIZE may also be prefixed by one of the following modifying characters:
         '+' extend by, '-' reduce by, '<' at most, '>' at least,
         '/' round down to multiple of, '%' round up to multiple of.
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
