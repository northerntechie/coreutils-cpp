/** stat.cpp, migrated from stat.c from coreutils
 * stat.c -- display file or file system status
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
 * Michael Meskes
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
#define PROGRAM_NAME stat

#define VERSION F_VERSION(PROGRAM_NAME)

constexpr auto USAGE =
R"(stat.

     Usage:
       stat [options] FILE...

       Display file or file system status.

     Options:
       -h --help              Show this screen
       --version              Show version
       -L, --dereference      Follow links
       -f, --file-system      Display file system status instead of file status
       --cached=MODE          Specify how to use cached attributes;
                                useful on remote file systems. See MODE below
       -c  --format=FORMAT    Use the specified FORMAT instead of the default;
                                output a newline after each use of FORMAT
       --printf=FORMAT        Like --format, but interpret backslash escapes,
                                and do not output a mandatory trailing newline;
                                if you want a newline, include \\n in FORMAT
       -t, --terse            Print the information in terse form

     Note:
       The --cached MODE argument can be; always, never, or default.
         `always` will use cached attributes if available, while
         `never` will try to synchronize with the latest attributes, and
         `default` will leave it up to the underlying file system.

       The valid format sequences for files (without --file-system):
         %a   permission bits in octal (note '#' and '0' printf flags)
         %A   permission bits and file type in human readable form
         %b   number of blocks allocated (see %B)
         %B   the size in bytes of each block reported by %b
         %C   SELinux security context string
         %d   device number in decimal
         %D   device number in hex
         %f   raw mode in hex
         %F   file type
         %g   group ID of owner
         %G   group name of owner
         %h   number of hard links
         %i   inode number
         %m   mount point
         %n   file name
         %N   quoted file name with dereference if symbolic link
         %o   optimal I/O transfer size hint
         %s   total size, in bytes
         %t   major device type in hex, for character/block device special files
         %T   minor device type in hex, for character/block device special files
         %u   user ID of owner
         %U   user name of owner
         %w   time of file birth, human-readable; - if unknown
         %W   time of file birth, seconds since Epoch; 0 if unknown
         %x   time of last access, human-readable
         %X   time of last access, seconds since Epoch
         %y   time of last data modification, human-readable
         %Y   time of last data modification, seconds since Epoch
         %z   time of last status change, human-readable
         %Z   time of last status change, seconds since Epoch

     Valid format sequences for file systems:
       %a   free blocks available to non-superuser
       %b   total data blocks in file system
       %c   total file nodes in file system
       %d   free file nodes in file system
       %f   free blocks in file system
       %i   file system ID in hex
       %l   maximum length of filenames
       %n   file name
       %s   block size (for faster transfers)
       %S   fundamental block size (for block counts)
       %t   file system type in hex
       %T   file system type in human readable form
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
