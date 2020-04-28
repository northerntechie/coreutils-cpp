/** .cpp, migrated from .c from coreutils
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
 * Roland McGrath
 */

// C++ includes
#include <iostream>
#include <map>
#include <string>
#include "docopt/docopt.h"
// End of C++ includes

/* The official name of this program (e.g., no 'g' prefix).  */
#define PROGRAM_NAME "chroot"
#define AUTHORS "Roland McGrath, Todd Saharchuk"
constexpr auto USAGE =
R"(chroot.

     Usage:
       chroot [options] NEWROOT [COMMAND [ARGS...]]
       chroot [options]

       Run COMMAND with root directory set to NEWROOT.

     Options:
       -h --help              Show this screen
       --version              Show version
       --groups=G_LIST        Specify supplementary groups as g1,g2,..,gN
       --userspec=USER:GROUP  Specify user and group (ID or name) to use
       --skip-chdir           Do not change working directory

     Notes:
       If no command is given, run '\"$SHELL\" -i' (default: '/bin/sh -i').
)";

int main(int argc, char** argv)
{
    std::map<std::string, docopt::value> args =
        docopt::docopt(USAGE,
                       {argv+1, argv+argc},
                        true,
                        "chroot (cpp) 0.1.0");

    // TODO(northerntechie): Finish implementation
    for(auto kv : args)
    {
        std::cout << kv.first << " : " << kv.second << "\n";
    }

    return EXIT_SUCCESS;
}
