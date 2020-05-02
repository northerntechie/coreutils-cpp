/** mktemp.cpp, migrated from mktemp.c from coreutils
 * Create a temporary file or directory, safely.
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
 * Eric Blake
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
#define PROGRAM_NAME mktemp

#define VERSION F_VERSION(PROGRAM_NAME)

constexpr auto USAGE =
R"(mktemp.

     Usage:
       mktemp [options] [ TEMPLATE ]

       Create a temporary file or directory, safely, and print its name.
         TEMPLATE must contain at least 3 consecutive 'X's in last component.
         If TEMPLATE is not specified, use tmp.XXXXXXXXXX, and --tmpdir is implied.
         Files are created u+rw, and directories u+rwx, minus umask restrictions.

     Options:
       -h --help               Show this screen
       --version               Show version
       -d, --directory         Create a directory, not a file
       -u, --dry-run           Do not create anything; merely print a name (unsafe)
       -q, --quiet             Suppress diagnostics about file/dir-creation failure
       --suffix=SUFF           Append SUFF to TEMPLATE; SUFF must not contain a slash.
                                 This option is implied if TEMPLATE does not end in X
       -p DIR, --tmpdir[=DIR]  Interpret TEMPLATE relative to DIR; if DIR is not
                                 specified, use $TMPDIR if set, else /tmp.  With
                                 this option, TEMPLATE must not be an absolute name;
                                 unlike with -t, TEMPLATE may contain slashes, but
                                 mktemp creates only the final component
       -t                      Interpret TEMPLATE as a single file name component,
                                 relative to a directory: $TMPDIR, if set; else the
                                 directory specified via -p; else /tmp [deprecated]
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
