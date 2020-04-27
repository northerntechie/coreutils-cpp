/* chmod.cpp, migrated from chmod.c from coreutils
chmod -- change permission modes of files
Copyright (C) 1987-2020 Free Software Foundation, Inc.

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <https://www.gnu.org/licenses/>.

Migrated C++ code Copyright (C) Todd Saharchuk, 2020.

*/

// C++ includes
#include <iostream>
#include <map>
#include <string>
#include "docopt/docopt.h"
// End of C++ includes

/* The official name of this program (e.g., no 'g' prefix).  */
#define PROGRAM_NAME "chmod"

constexpr auto USAGE =
R"(chmod.

     Change the mode of each FILE to MODE.
     With --reference, change the mode of each FILE to that of RFILE.

     Usage:
       chmod [options] MODE FILE...
       chmod [options] OCTAL-MODE FILE...
       chmod [options] --reference=RFILE FILE...

     Options:
       -c, --changes          Like verbose but report only when a change is made
       -f, --silent, --quiet  Suppress most error messages
       -v, --verbose          Output a diagnostic for every file processed
       --no-preserve-root     Do not treat '/' specially (the default)
       --preserve-root        Fail to operate recursively on '/'
       --reference=RFILE      Use RFILE's mode instead of MODE values
       -R, --recursive        Change files and directories recursively

     Examples:

       Each MODE is of the form '[ugoa]*([-+=]([rwxXst]*|[ugo]))+|[-+=][0-7]+'.
)";

int main(int argc, char** argv)
{
    std::map<std::string, docopt::value> args =
        docopt::docopt(USAGE,
                       {argv+1, argv+argc},
                        true,
                        "chmod (cpp) 0.1.0");

    // TODO(northerntechie): Finish implementation
    for(auto kv : args)
    {
        std::cout << kv.first << " : " << kv.second << "\n";
    }

    return EXIT_SUCCESS;
}
