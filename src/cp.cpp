/** cp.cpp, migrated from cp.c from coreutils
 * cp.c  -- file copying (main routines)
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
 * Torbjorn Granlund
 * David MacKenzie
 * Jim Meyering
 *
 * C++ Code migration Todd Saharchuk tsaharchuk1@athabasca.edu
 */

// C++ includes
#include <iostream>
#include <map>
#include <string>
#include "docopt/docopt.h"
// End of C++ includes

/* The official name of this program (e.g., no 'g' prefix).  */
#define PROGRAM_NAME ""
#define AUTHORS ""
constexpr auto USAGE =
R"(cp.

     Usage:
       cp [options] [-T] SOURCE DEST
       cp [options] SOURCE... DIRECTORY
       cp [options] -t DIRECTORY SOURCE...

       Copy SOURCE to DEST, or multiple SOURCE(s) to DIRECTORY.

     Options:
       -h --help               Show this screen
       --version               Show version
       -a, --archive           Same as -dR --preserve=all
       --attributes-only       Don't copy the file data, just the attributes
       --backup[=CONTROL]      Make a backup of each existing destination file
       -b                      Like --backup but does not accept an argument
       --copy-contents         Copy contents of special files when recursive
       -d                      Same as --no-dereference --preserve=links
       -f, --force             If an existing destination file cannot be
                                 opened, remove it and try again (this option
                                 is ignored when the -n option is also used)
       -i, --interactive       Prompt before overwrite (overrides a previous -n
                                 option)
       -H                      Follow command-line symbolic links in SOURCE
       -l, --link              Hard link files instead of copying
       -L, --dereference       Always follow symbolic links in SOURCE
       -n, --no-clobber        Do not overwrite an existing file (overrides
                                 a previous -i option)
       -P, --no-dereference    Never follow symbolic links in SOURCE
       -p                      Same as --preserve=mode,ownership,timestamps
       --preserve[=ATTR_LIST]  Preserve the specified attributes (default:
                                 mode,ownership,timestamps), if possible
                                 additional attributes: context, links, xattr,
                                 all
       --no-preserve=ATTR_LIST
                               Don't preserve the specified attributes
       --parents               Use full source file name under DIRECTORY
       -R, -r, --recursive     Copy directories recursively
       --reflink[=WHEN]        Control clone/CoW copies. See below
       --remove-destination    Remove each existing destination file before
                                 attempting to open it (contrast with --force)
       --sparse=WHEN           Control creation of sparse files. See below\n\
       --strip-trailing-slashes
                               Remove any trailing slashes from each SOURCE
                                 argument
       -s, --symbolic-link     Make symbolic links instead of copying
       -S, --suffix=SUFFIX     Override the usual backup suffix
       -t, --target-directory=DIRECTORY
                               Copy all SOURCE arguments into DIRECTORY
       -T, --no-target-directory
                               Treat DEST as a normal file
       -u, --update            Copy only when the SOURCE file is newer
                                 than the destination file or when the
                                 destination file is missing
       -v, --verbose           Explain what is being done
       -x, --one-file-system   Stay on this file system
       -Z                      Set SELinux security context of destination
                                 file to default type
       --context[=CTX]         Like -Z, or if CTX is specified then set the
                                 SELinux or SMACK security context to CTX

     Notes:

     By default, sparse SOURCE files are detected by a crude heuristic and the
       corresponding DEST file is made sparse as well.  That is the behavior
       selected by --sparse=auto.  Specify --sparse=always to create a sparse DEST
       file whenever the SOURCE file contains a long enough sequence of zero bytes.
       Use --sparse=never to inhibit creation of sparse files.

     When --reflink[=always] is specified, perform a lightweight copy, where the
       data blocks are copied only when modified.  If this is not possible the copy
       fails, or if --reflink=auto is specified, fall back to a standard copy.
       Use --reflink=never to ensure a standard copy is performed.

     As a special case, cp makes a backup of SOURCE when the force and backup
       options are given and SOURCE and DEST are the same name for an existing,
       regular file.
)";

int main(int argc, char** argv)
{
    std::map<std::string, docopt::value> args =
        docopt::docopt(USAGE,
                       {argv+1, argv+argc},
                        true,
                        "<prog> (cpp) 0.1.0");

    // TODO(northerntechie): Finish implementation
    for(auto kv : args)
    {
        std::cout << kv.first << " : " << kv.second << "\n";
    }

    return EXIT_SUCCESS;
}
