/** ln.cpp, migrated from ln.c from coreutils
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
#define PROGRAM_NAME ln

#define VERSION F_VERSION(PROGRAM_NAME)

constexpr auto USAGE =
R"(ln.

     Usage:
       ln [options] [ -T ] TARGET LINK_NAME
       ln [options] TARGET
       ln [options] TARGETS... DIRECTORY
       ln [options] -t DIRECTORY TARGETS...

       In the 1st form, create a link to TARGET with the name LINK_NAME.
         In the 2nd form, create a link to TARGET in the current directory.
         In the 3rd and 4th forms, create links to each TARGET in DIRECTORY.
         Create hard links by default, symbolic links with --symbolic.
         By default, each destination (name of new link) should not already exist.
         When creating hard links, each TARGET must exist.  Symbolic links
         can hold arbitrary text; if later resolved, a relative link is
         interpreted in relation to its parent directory.

     Options:
       -h --help              Show this screen
       --version              Show version
       --backup[=CONTROL]     Make a backup of each existing destination file
       -b                     Like --backup but does not accept an argument
       -d, -F, --directory    Allow the superuser to attempt to hard link
                                directories (note: will probably fail due to
                                system restrictions, even for the superuser)
       -f, --force            Remove existing destination files
       -i, --interactive      Prompt whether to remove destinations
       -L, --logical          Dereference TARGETs that are symbolic links
       -n, --no-dereference   Treat LINK_NAME as a normal file if
                                it is a symbolic link to a directory
       -P, --physical         Make hard links directly to symbolic links
       -r, --relative         Create symbolic links relative to link location
       -s, --symbolic         Make symbolic links instead of hard links
       -S, --suffix=SUFFIX    Override the usual backup suffix
       -t, --target-directory=DIRECTORY
                              Specify the DIRECTORY in which to create
                                the links
       -T, --no-target-directory
                              Treat LINK_NAME as a normal file always
       -v, --verbose          Print name of each linked file

     Note:

       Using -s ignores -L and -P.  Otherwise, the last option specified controls
         behavior when a TARGET is a symbolic link, defaulting to ln.
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
