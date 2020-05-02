/** install.cpp, migrated from install.c from coreutils
 * install - copy files and set attributes
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
 * David MacKenzie <djm@gnu.ai.mit.edu>
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
#define PROGRAM_NAME install

#define VERSION F_VERSION(PROGRAM_NAME)

constexpr auto USAGE =
R"(install.

     Usage:
       install [options] [-T] SOURCE DEST
       install [options] SOURCES... DIRECTORY
       install [options] -t DIRECTORY SOURCES...
       install [options] -d DIRECTORIES...

       This install program copies files (often just compiled) into destination
         locations you choose.  If you want to download and install a ready-to-use
         package on a GNU/Linux system, you should instead be using a package manager
         like yum(1) or apt-get(1).

       In the first three forms, copy SOURCE to DEST or multiple SOURCE(s) to
         the existing DIRECTORY, while setting permission modes and owner/group.
         In the 4th form, create all components of the given DIRECTORY(ies).

     Options:
       -h --help                Show this screen
       --version                Show version
       --backup[=CONTROL]       Make a backup of each existing destination file
       -b                       Like --backup but does not accept an argument
       -c                       (ignored)
       -C, --compare            Compare each pair of source and destination files, and
                                  in some cases, do not modify the destination at all
       -d, --directory          Treat all arguments as directory names; create all
                                  components of the specified directories
       -D                       Create all leading components of DEST except the last,
                                  or all components of --target-directory,
                                  then copy SOURCE to DEST
       -g, --group=GROUP        Set group ownership, instead of process' current group
       -m, --mode=MODE          Set permission mode (as in chmod), instead of rwxr-xr-x
       -o, --owner=OWNER        Set ownership (super-user only)
       -p, --preserve-timestamps
                                Apply access/modification times of SOURCE files
                                  to corresponding destination files
       -s, --strip              Strip symbol tables
       --strip-program=PROGRAM  Program used to strip binaries
       -S, --suffix=SUFFIX      Override the usual backup suffix
       -t, --target-directory=DIRECTORY
                                Copy all SOURCE arguments into DIRECTORY
       -T, --no-target-directory
                                Treat DEST as a normal file
       -v, --verbose            Print the name of each directory as it is created
       --preserve-context       Preserve SELinux security context
       -Z                       Set SELinux security context of destination
                                  file and each created directory to default type
       --context[=CTX]          Like -Z, or if CTX is specified then set the
                                  SELinux or SMACK security context to CTX
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
