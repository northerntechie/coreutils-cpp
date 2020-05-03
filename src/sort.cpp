/** sort.cpp, migrated from sort.c from coreutils
 * sort - sort lines of text (with all kinds of options).
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
 * Mike Haertel
 * Paul Eggert
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
#define PROGRAM_NAME sort

#define VERSION F_VERSION(PROGRAM_NAME)

constexpr auto USAGE =
R"(sort.

     Usage:
       sort [options] FILE...
       sort [options] ==files0-from=F

       Write sorted concatenation of all FILE(s) to standard output.

     Options:
       -h --help                      Show this screen
       --version                      Show version

     Ordering options:
       -b, --ignore-leading-blanks    Ignore leading blanks
       -d, --dictionary-order         Consider only blanks and alphanumeric characters
       -f, --ignore-case              Fold lower case to upper case characters
       -g, --general-numeric-sort     Compare according to general numerical value
       -i, --ignore-nonprinting       Consider only printable characters
       -M, --month-sort               Compare (unknown) < 'JAN' < ... < 'DEC'
       -h, --human-numeric-sort       Compare human readable numbers (e.g., 2K 1G)
       -n, --numeric-sort             Compare according to string numerical value
       -R, --random-sort              Shuffle, but group identical keys.  See shuf(1)
       --random-source=FILE           Get random bytes from FILE
       -r, --reverse                  Reverse the result of comparisons
       --sort=WORD                    Sort according to WORD:
                                        general-numeric -g, human-numeric -h, month -M,
                                        numeric -n, random -R, version -V
       -V, --version-sort             Natural sort of (version) numbers within text

     Other options:
       --batch-size=NMERGE            Merge at most NMERGE inputs at once;
                                        for more use temp files
       -c, --check, --check=diagnose-first
                                      Check for sorted input; do not sort
       -C, --check=quiet, --check=silent
                                      Like -c, but do not report first bad line
       --compress-program=PROG        Compress temporaries with PROG;
                                        decompress them with PROG -d
       --debug                        Annotate the part of the line used to sort,
                                        and warn about questionable usage to stderr
       --files0-from=F                Read input from the files specified by
                                        NUL-terminated names in file F;
                                        If F is - then read names from standard input
       -k, --key=KEYDEF               Sort via a key; KEYDEF gives location and type
       -m, --merge                    Merge already sorted files; do not sort
       -o, --output=FILE              Write result to FILE instead of standard output
       -s, --stable                   Stabilize sort by disabling last-resort comparison
       -S, --buffer-size=SIZE         Use SIZE for main memory buffer
       -t, --field-separator=SEP      Use SEP instead of non-blank to blank transition
       -T, --temporary-directory=DIR  Use DIR for temporaries, not $TMPDIR or %s;
                                        multiple options specify multiple directories
       --parallel=N                   Change the number of sorts run concurrently to N
       -u, --unique                   With -c, check for strict ordering;
                                        without -c, output only the first of an equal run
       -z, --zero-terminated          Line delimiter is NUL, not newline

     Note:

       KEYDEF is F[.C][OPTS][,F[.C][OPTS]] for start and stop position, where F is a
         field number and C a character position in the field; both are origin 1, and
         the stop position defaults to the line's end.  If neither -t nor -b is in
         effect, characters in a field are counted from the beginning of the preceding
         whitespace.  OPTS is one or more single-letter ordering options [bdfgiMhnRrV],
         which override global ordering options for that key.  If no key is given, use
         the entire line as the key.  Use --debug to diagnose incorrect key usage.

       SIZE may be followed by the following multiplicative suffixes:
         % 1% of memory, b 1, K 1024 (default), and so on for M, G, T, P, E, Z, Y.

     *** WARNING ***
       The locale specified by the environment affects sort order.
         Set LC_ALL=C to get the traditional sort order that uses
         native byte values.
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
