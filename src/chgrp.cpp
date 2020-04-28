/* chgrp.cpp, migrated from chgrp.c from coreutils
chgrp -- change group ownership of files

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
#define PROGRAM_NAME "chgrp"

constexpr auto USAGE =
R"(chgrp.

     Usage:
       chgrp [options] GROUP FILE...
       chgrp [options] --reference=RFILE FILE...

       Change the group of each FILE to GROUP.
       With --reference, change the group of each FILE to that of RFILE.

     Options:
       -h --help              Show this screen
       --version              Show version
       -c, --changes          Like verbose but report only when a change is made
       -f, --silent, --quiet  Suppress most error messages
       -v, --verbose          Output a diagnostic for every file processed
       --dereference          Affect the referent of each symbolic link (this is
                                the default), rather than the symbolic link itself
       -h, --no-dereference   Affect symbolic links instead of any referenced file
                                (useful only on systems that can change the
                                ownership of a symlink)
       --no-preserve-root     Do not treat '/' specially (the default)
       --preserve-root        Fail to operate recursively on '/'
       --reference=RFILE      Use RFILE's group rather than specifying a
                                GROUP value
       -R, --recursive        Operate on files and directories recursively

       The following options modify how a hierarchy is traversed when the -R
         option is also specified.  If more than one is specified, only the final
         one takes effect.

       -H                     If a command line argument is a symbolic link
                                to a directory, traverse it
       -L                     Traverse every symbolic link to a directory
                                encountered
       -P                     Do not traverse any symbolic links (default)

     Examples:

       chgrp staff /u      Change the group of /u to \"staff\".
       chgrp -hR staff /u  Change the group of /u and subfiles to \"staff\".

)";

int main(int argc, char** argv)
{
    std::map<std::string, docopt::value> args =
        docopt::docopt(USAGE,
                       {argv+1, argv+argc},
                        true,
                        "chgrp (cpp) 0.1.0");

    // TODO(northerntechie): Finish implementation
    for(auto kv : args)
    {
        std::cout << kv.first << " : " << kv.second << "\n";
    }

    return EXIT_SUCCESS;
}
