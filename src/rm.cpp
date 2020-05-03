/** rm.cpp, migrated from rm.c from coreutils
 * 'rm' file deletion utility for GNU.
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
 * Paul Rubin
 * David MacKenzie
 * Richard M. Stallman
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
#define PROGRAM_NAME rm

#define VERSION F_VERSION(PROGRAM_NAME)

constexpr auto USAGE =
R"(rm.

     Usage:
       rm [options] FILE...

       Remove (unlink) the FILE(s).

     Options:
       -h --help              Show this screen
       --version              Show version
       -f, --force            Ignore nonexistent files and arguments, never prompt
       -i                     Prompt before every removal
       -I                     Prompt once before removing more than three files, or
                                when removing recursively; less intrusive than -i,
                                while still giving protection against most mistakes
       --interactive[=WHEN]   Prompt according to WHEN: never, once (-I), or
                                always (-i); without WHEN, prompt always
       --one-file-system      When removing a hierarchy recursively, skip any
                                directory that is on a file system different from
                                that of the corresponding command line argument
       --no-preserve-root     Do not treat '/' specially
       --preserve-root[=all]  Do not remove '/' (default);
                                with 'all', reject any command line argument
                                on a separate device from its parent
       -r, -R, --recursive    Remove directories and their contents recursively
       -d, --dir              Remove empty directories
       -v, --verbose          Explain what is being done

     Note:

       By default, rm does not remove directories.  Use the --recursive (-r or -R)
         option to remove each listed directory, too, along with all of its contents.
         To remove a file whose name starts with a '-', for example '-foo',
         use one of these commands:
           rm -- -foo
           rm ./-foo
       Note that if you use rm to remove a file, it might be possible to recover
         some of its contents, given sufficient expertise and/or time.  For greater
         assurance that the contents are truly unrecoverable, consider using shred.
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
