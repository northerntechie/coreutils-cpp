/** chown.cpp, migrated from chown.c from coreutils
 * chown -- change user and group ownership of files
 * Copyright (C) 1987-2020 Free Software Foundation, Inc.
 * Migrated C++ code Copyright (C) Todd Saharchuk, 2020a.
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
 * David MacKenzie <djm@gnu.ai.mit.edu>
 * Jim Meyering
 */

// C++ includes
#include <iostream>
#include <map>
#include <string>
#include "docopt/docopt.h"
// End of C++ includes

/* The official name of this program (e.g., no 'g' prefix).  */
#define PROGRAM_NAME "chown"
#define AUTHORS David "MacKenzie, Jim Meyering, Todd Saharchuk"

constexpr auto USAGE =
R"(chown.

     Usage:
       chown [options] [OWNER] FILE...
       chown [options] --reference=RFILE FILE...

       Change the owner and/or group of each FILE to OWNER and/or GROUP.
       With --reference, change the owner and group of each FILE to those of RFILE.

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
       --from=CURRENT_OWNER:CURRENT_GROUP
                              Change the owner and/or group of each file only if
                                its current owner and/or group match those specified
                                here.  Either may be omitted, in which case a match
                                is not required for the omitted attribute
       --no-preserve-root     Do not treat '/' specially (the default)
       --preserve-root        Fail to operate recursively on '/'
       --reference=RFILE      Use RFILE's owner and group rather than
                                specifying OWNER:GROUP values
       -R, --recursive        Operate on files and directories recursively

     The following options modify how a hierarchy is traversed when the -R
       option is also specified.  If more than one is specified, only the final
       one takes effect.

       -H                     If a command line argument is a symbolic link
                                to a directory, traverse it
       -L                     Traverse every symbolic link to a directory
                                encountered
       -P                     Do not traverse any symbolic links (default)

     Owner is unchanged if missing.  Group is unchanged if missing, but changed
       to login group if implied by a ':' following a symbolic OWNER.
       OWNER and GROUP may be numeric as well as symbolic.

     Examples:
       chown root /u          Change the owner of /u to \"root\".
       chown root:staff /u    Likewise, but also change its group to \"staff\".
       chown -hR root /u      Change the owner of /u and subfiles to \"root\".
)";

int main(int argc, char** argv)
{
    std::map<std::string, docopt::value> args =
        docopt::docopt(USAGE,
                       {argv+1, argv+argc},
                        true,
                        "chown (cpp) 0.1.0");

    // TODO(northerntechie): Finish implementation

    for(auto kv : args)
    {
        std::cout << kv.first << " : " << kv.second << "\n";
    }

    return EXIT_SUCCESS;
}
