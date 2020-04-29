/** cut.cpp, migrated from cut.c from coreutils
 * cut - remove parts of lines of files
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
 * David Ihnat
 * David MacKenzie <djm@gnu.ai.mit.edu>
 *
 * C++ Code migration:
 * Todd Saharchuk, tsaharchuk1@athabasca.edu
 */

// C++ includes
#include <iostream>
#include <map>
#include <string>
#include "docopt/docopt.h"
// End of C++ includes

/* The official name of this program (e.g., no 'g' prefix).  */
#define PROGRAM_NAME "cut"

constexpr auto USAGE =
R"(cut.

     Usage:
       cut [options] FILE...


     Options:
       -h --help               Show this screen
       --version               Show version
       -b, --bytes=LIST        Select only these bytes
       -c, --characters=LIST   Select only these characters
       -d, --delimiter=DELIM   Use DELIM instead of TAB for field delimiter
       -f, --fields=LIST       Select only these fields;  also print any line
                                 that contains no delimiter character, unless
                                 the -s option is specified
       -n                      (ignored)
       --complement            Complement the set of selected bytes, characters
                                 or fields
       -s, --only-delimited    Do not print lines not containing delimiters
       --output-delimiter=STRING
                               Use STRING as the output delimiter
                                 the default is to use the input delimiter
       -z, --zero-terminated   Line delimiter is NUL, not newline

     Notes:

       Use one, and only one of -b, -c or -f.  Each LIST is made up of one
         range, or many ranges separated by commas.  Selected input is written
         in the same order that it is read, and is written exactly once.

       Each range is one of:
         N     N'th byte, character or field, counted from 1
         N-    from N'th byte, character or field, to end of line
         N-M   from N'th to M'th (included) byte, character or field
         -M    from first to M'th (included) byte, character or field
)";

int main(int argc, char** argv)
{
    std::map<std::string, docopt::value> args =
        docopt::docopt(USAGE,
                       {argv+1, argv+argc},
                        true,
                        "cut (cpp) 0.1.0");

    // TODO(northerntechie): Finish implementation
    for(auto kv : args)
    {
        std::cout << kv.first << " : " << kv.second << "\n";
    }

    return EXIT_SUCCESS;
}
