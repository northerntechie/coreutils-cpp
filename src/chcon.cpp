/* chcon.cpp, migrated from chcon.c from coreutils
chcon -- change security context of files
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
#define PROGRAM_NAME "chcon"

constexpr auto USAGE =
R"(chcon.

     Usage:
       chcon [options] CONTEXT FILE...
       chcon [options] [ -u USER ] [ -r ROLE ] [ -l RANGE ] [ -t TYPE ] FILE...
       chcon [options] --reference=RFILE FILE...

       Change the SELinux security context of each FILE to CONTEXT.
       With --reference, change the security context of each FILE to that of RFILE.

     Options:
       --dereference         Affect the referent of each symbolic link (this is
                               the default), rather than the symbolic link itself
       -h, --no-dereference  Affect symbolic links instead of any referenced file
       -u, --user=USER       Set user USER in the target security context
       -r, --role=ROLE       Set role ROLE in the target security context
       -t, --type=TYPE       Set type TYPE in the target security context
       -l, --range=RANGE     Set range RANGE in the target security context
       --no-preserve-root    Do not treat '/' specially (the default)
       --preserve-root       Fail to operate recursively on '/'
       --reference=RFILE     Use RFILE's security context rather than specifying
                               a CONTEXT value
       -R, --recursive       Operate on files and directories recursively
       -v, --verbose         Output a diagnostic for every file processed

       The following options modify how a hierarchy is traversed when the -R
         option is also specified.  If more than one is specified, only the final
         one takes effect.
       -H                    If a command line argument is a symbolic link
                               to a directory, traverse it
       -L                    Traverse every symbolic link to a directory
                               encountered
       -P                    Do not traverse any symbolic links (default)
)";

int main(int argc, char** argv)
{
    std::map<std::string, docopt::value> args =
        docopt::docopt(USAGE,
                       {argv+1, argv+argc},
                        true,
                        "basename (cpp) 0.1.0");

    // TODO(northerntechie): Finish implementation

    for(auto kv : args)
    {
        std::cout << kv.first << " : " << kv.second << "\n";
    }

    return EXIT_SUCCESS;
}
