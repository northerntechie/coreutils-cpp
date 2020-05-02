/** mv.cpp, migrated from mv.c from coreutils
 * mv -- move or rename files
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
 * David MacKenzie
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
#define PROGRAM_NAME mv

#define VERSION F_VERSION(PROGRAM_NAME)

constexpr auto USAGE =
R"(mv.

     Usage:
       mv [options] [-T] SOURCE DEST
       mv [options] SOURCES... DIRECTORY
       mv [options] -t DIRECTORY SOURCES...

       Rename SOURCE to DEST, or move SOURCE(s) to DIRECTORY.

     Options:
       -h --help                 Show this screen
       --version                 Show version
       --backup[=CONTROL]        Make a backup of each existing destination file
       -b                        Like --backup but does not accept an argument
       -f, --force               Do not prompt before overwriting
       -i, --interactive         Prompt before overwrite
       -n, --no-clobber          Do not overwrite an existing file
                                   If you specify more than one of -i, -f, -n,
                                   only the final one takes effect.
       --strip-trailing-slashes  Remove any trailing slashes from each SOURCE
                                   argument
       -S, --suffix=SUFFIX       Override the usual backup suffix
       -t, --target-directory=DIRECTORY
                                 Move all SOURCE arguments into DIRECTORY
       -T, --no-target-directory
                                 Treat DEST as a normal file
       -u, --update              Move only when the SOURCE file is newer
                                   than the destination file or when the
                                   destination file is missing
       -v, --verbose             Explain what is being done
       -Z, --context             Set SELinux security context of destination
                                   file to default type
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
