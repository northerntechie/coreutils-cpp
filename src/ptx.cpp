/** ptx.cpp, migrated from ptx.c from coreutils
 * Permuted index for GNU, with keywords in their context.
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
 * François Pinard <pinard@iro.umontreal.ca>
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
#define PROGRAM_NAME ptx

#define VERSION F_VERSION(PROGRAM_NAME)

constexpr auto USAGE =
R"(ptx.

     Usage:
       ptx [options] [ INPUT... ]
       ptx -G [options] [ INPUT [OUTPUT] ]

       Output a permuted index, including context, of the words in the input files.

     Options:
       -h --help                Show this screen
       --version                Show version
       -A, --auto-reference     Output automatically generated references
       -G, --traditional        Behave more like System V 'ptx'
       -F, --flag-truncation=STRING
                                Use STRING for flagging line truncations.
                                  The default is '/'
       -M, --macro-name=STRING  Macro name to use instead of 'xx'
       -O, --format=roff        Generate output as roff directives
       -R, --right-side-refs    Put references at right, not counted in -w
       -S, --sentence-regexp=REGEXP
                                For end of lines or end of sentences
       -T, --format=tex         Generate output as TeX directives
       -W, --word-regexp=REGEXP
                                Use REGEXP to match each keyword
       -b, --break-file=FILE    Word break characters in this FILE
       -f, --ignore-case        Fold lower case to upper case for sorting
       -g, --gap-size=NUMBER    Gap size in columns between output fields
       -i, --ignore-file=FILE   Read ignore word list from FILE
       -o, --only-file=FILE     Read only word list from this FILE
       -r, --references         First field of each line is a reference
       -t, --typeset-mode       - not implemented -
       -w, --width=NUMBER       Output width in columns, reference excluded
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
