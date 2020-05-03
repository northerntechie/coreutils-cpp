/** split.cpp, migrated from split.c from coreutils
 * split.c -- split a file into pieces.
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
 * Torbjorn Granlund
 * Richard M. Stallman
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
#define PROGRAM_NAME split

#define VERSION F_VERSION(PROGRAM_NAME)

constexpr auto USAGE =
R"(split.

     Usage:
       split [options] [ FILE [PREFIX] ]

       Output pieces of FILE to PREFIXaa, PREFIXab, ...;
         default size is 1000 lines, and default PREFIX is 'x'.

     Options:
       -h --help                   Show this screen
       --version                   Show version
       -a, --suffix-length=N       Generate suffixes of length N (default %d)
       --additional-suffix=SUFFIX  append an additional SUFFIX to file names
       -b, --bytes=SIZE            Put SIZE bytes per output file
       -C, --line-bytes=SIZE       Put at most SIZE bytes of records per output file
       -d                          Use numeric suffixes starting at 0, not alphabetic
       --numeric-suffixes[=FROM]   Same as -d, but allow setting the start value
       -x                          Use hex suffixes starting at 0, not alphabetic
       --hex-suffixes[=FROM]       Same as -x, but allow setting the start value
       -e, --elide-empty-files     Do not generate empty output files with '-n'
       --filter=COMMAND            Write to shell COMMAND; file name is $FILE
       -l, --lines=NUMBER          Put NUMBER lines/records per output file
       -n, --number=CHUNKS         Generate CHUNKS output files; see explanation below
       -t, --separator=SEP         Use SEP instead of newline as the record separator;
                                     '\\0' (zero) specifies the NUL character
       -u, --unbuffered            Immediately copy input to output with '-n r/...'
       --verbose                   Print a diagnostic just before each
                                     output file is opened

     CHUNKS may be:
       N       split into N files based on size of input
       K/N     output Kth of N to stdout
       l/N     split into N files without splitting lines/records
       l/K/N   output Kth of N to stdout without splitting lines/records
       r/N     like 'l' but use round robin distribution
       r/K/N   likewise but only output Kth of N to stdout
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
