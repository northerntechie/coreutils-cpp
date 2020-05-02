/** expr.cpp, migrated from expr.c from coreutils
 * expr -- evaluate expressions.
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
 * James Youngman
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
#define PROGRAM_NAME expr

#define VERSION F_VERSION(PROGRAM_NAME)

constexpr auto USAGE =
R"(expr.

     Usage:
       expr EXPRESSION
       expr [options]

       Print the value of EXPRESSION to standard output.  A blank line below
         separates increasing precedence groups.  EXPRESSION may be:

     Options:
       -h --help              Show this screen
       --version              Show version

     Notes:
       ARG1 | ARG2       ARG1 if it is neither null nor 0, otherwise ARG2
       ARG1 & ARG2       ARG1 if neither argument is null or 0, otherwise 0
       ARG1 < ARG2       ARG1 is less than ARG2
       ARG1 <= ARG2      ARG1 is less than or equal to ARG2
       ARG1 = ARG2       ARG1 is equal to ARG2
       ARG1 != ARG2      ARG1 is unequal to ARG2
       ARG1 >= ARG2      ARG1 is greater than or equal to ARG2
       ARG1 > ARG2       ARG1 is greater than ARG2
       ARG1 + ARG2       arithmetic sum of ARG1 and ARG2
       ARG1 - ARG2       arithmetic difference of ARG1 and ARG2
       ARG1 * ARG2       arithmetic product of ARG1 and ARG2
       ARG1 / ARG2       arithmetic quotient of ARG1 divided by ARG2
       ARG1 % ARG2       arithmetic remainder of ARG1 divided by ARG2
       STRING : REGEXP   anchored pattern match of REGEXP in STRING
       match STRING REGEXP        same as STRING : REGEXP
       substr STRING POS LENGTH   substring of STRING, POS counted from 1
       index STRING CHARS         index in STRING where any CHARS is found, or 0
       length STRING              length of STRING
       + TOKEN                    interpret TOKEN as a string, even if it is a
                               keyword like 'match' or an operator like '/'

     Notes:
       Beware that many operators need to be escaped or quoted for shells.
         Comparisons are arithmetic if both ARGs are numbers, else lexicographical.
         Pattern matches return the string matched between \\( and \\) or null; if
         \\( and \\) are not used, they return the number of characters matched or 0.

       Exit status is 0 if EXPRESSION is neither null nor 0, 1 if EXPRESSION is null
         or 0, 2 if EXPRESSION is syntactically invalid, and 3 if an error occurred.
)";

int main(int argc, char** argv)
{
    std::map<std::string, docopt::value> args =
        docopt::docopt(USAGE,
                       {argv+1, argv+argc},
                        true,
                        VERSION);

    // TODO(@northerntechie): Finish implementation
    for(auto kv : args)
    {
        std::cout << kv.first << " : " << kv.second << "\n";
    }

    return EXIT_SUCCESS;
}
