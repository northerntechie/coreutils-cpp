/** env.cpp, migrated from env.c from coreutils
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
 * Richard Mlynarik
 * David MacKenzie
 * Assaf Gordon
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
#define PROGRAM_NAME env

#define VERSION F_VERSION(PROGRAM_NAME,MAJOR_VER,MINOR_VER,PATCH_VER)

constexpr auto USAGE =
R"(env.

     Usage:
       env [options] [ - ] [ NAME=VALUE ] COMMAND [ARG...]

       Set each NAME to VALUE in the environment and run COMMAND.

     Options:
       -h --help                 Show this screen
       --version                 Show version
       -i, --ignore-environment  Start with an empty environment
       -0, --null                End each output line with NUL, not newline
       -u, --unset=NAME          Remove variable from the environment
       -C, --chdir=DIR           Change working directory to DIR
       -S, --split-string=S      Process and split S into separate arguments;
                                   used to pass multiple arguments on shebang lines
       --block-signal[=SIG]      Block delivery of SIG signal(s) to COMMAND
       --default-signal[=SIG]    Reset handling of SIG signal(s) to the default
       --ignore-signal[=SIG]     Set handling of SIG signals(s) to do nothing
       --list-signal-handling    List non default signal handling to stderr
       -v, --debug               Print verbose information for each processing step

     Notes:

       A mere - implies -i.  If no COMMAND, print the resulting environment.

       SIG may be a signal name like 'PIPE', or a signal number like '13'.
         Without SIG, all known signals are included.  Multiple signals can be
         comma-separated.
)";

int main(int argc, char** argv)
{
    std::map<std::string, docopt::value> args =
        docopt::docopt(USAGE,
                       {argv+1, argv+argc},
                        true,
                        VERSION);

    // TODO(northerntechie): Finish implementation
    for(auto kv : args)
    {
        std::cout << kv.first << " : " << kv.second << "\n";
    }

    return EXIT_SUCCESS;
}
