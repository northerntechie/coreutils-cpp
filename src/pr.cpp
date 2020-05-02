/** pr.cpp, migrated from pr.c from coreutils
 * pr -- convert text files for printing.
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
 * Pete TerMaat
 * Roland Huebner
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
#define PROGRAM_NAME pr

#define VERSION F_VERSION(PROGRAM_NAME)

constexpr auto USAGE =
R"(pr.

     Usage:
       pr [options] [ FILE | FILES... ]

       Paginate or columnate FILE(s) for printing.

     Options:
       -h --help              Show this screen
       --version              Show version
       +FIRST_PAGE[:LAST_PAGE], --pages=FIRST_PAGE[:LAST_PAGE]
                              Begin [stop] printing with page FIRST_[LAST_]PAGE
       -COLUMN, --columns=COLUMN
                              Output COLUMN columns and print columns down,
                                unless -a is used. Balance number of lines in the
                                columns on each page
       -a, --across           Print columns across rather than down, used together
                                with -COLUMN
       -c, --show-control-chars
                              Use hat notation (^G) and octal backslash notation
       -d, --double-space     Double space the output
       -D, --date-format=FORMAT
                              Use FORMAT for the header date
       -e[CHAR[WIDTH]], --expand-tabs[=CHAR[WIDTH]]
                              Expand input CHARs (TABs) to tab WIDTH (8)
       -F, -f, --form-feed
                              Use form feeds instead of newlines to separate pages
                                (by a 3-line page header with -F or a 5-line header
                                and trailer without -F)
       -h, --header=HEADER
                              Use a centered HEADER instead of filename in page header,
                                -h \"\" prints a blank line, don't use -h\"\"
       -i[CHAR[WIDTH]], --output-tabs[=CHAR[WIDTH]]
                              Replace spaces with CHARs (TABs) to tab WIDTH (8)
       -J, --join-lines       Merge full lines, turns off -W line truncation, no column
                                alignment, --sep-string[=STRING] sets separators
       -l, --length=PAGE_LENGTH
                              Set the page length to PAGE_LENGTH (66) lines
                                (default number of lines of text 56, and with -F 63).
                                implies -t if PAGE_LENGTH <= 10
       -m, --merge            Print all files in parallel, one in each column,
                                truncate lines, but join lines of full length with -J
       -n[SEP[DIGITS]], --number-lines[=SEP[DIGITS]]
                              Number lines, use DIGITS (5) digits, then SEP (TAB),
                                default counting starts with 1st line of input file
       -N, --first-line-number=NUMBER
                              Start counting with NUMBER at 1st line of first
                                page printed (see +FIRST_PAGE)
       -o, --indent=MARGIN
                              Offset each line with MARGIN (zero) spaces, do not
                                affect -w or -W, MARGIN will be added to PAGE_WIDTH
       -r, --no-file-warnings
                              Omit warning when a file cannot be opened
       -s[CHAR], --separator[=CHAR]
                              Separate columns by a single character, default for CHAR
                                is the <TAB> character without -w and \'no char\' with -w.
                                -s[CHAR] turns off line truncation of all 3 column
                                options (-COLUMN|-a -COLUMN|-m) except -w is set
       -S[STRING], --sep-string[=STRING]
                              Separate columns by STRING,
                                without -S: Default separator <TAB> with -J and <space>
                                otherwise (same as -S\" \"), no effect on column options
       -t, --omit-header  omit page headers and trailers;
                              Implied if PAGE_LENGTH <= 10
       -T, --omit-pagination
                              Omit page headers and trailers, eliminate any pagination
                                by form feeds set in input files
       -v, --show-nonprinting
                              Use octal backslash notation
       -w, --width=PAGE_WIDTH
                              Set page width to PAGE_WIDTH (72) characters for
                                multiple text-column output only, -s[char] turns off (72)
       -W, --page-width=PAGE_WIDTH
                              Set page width to PAGE_WIDTH (72) characters always,
                                truncate lines, except -J option is set, no interference
                                with -S or -s
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
