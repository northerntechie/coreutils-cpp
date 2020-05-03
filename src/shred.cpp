/** shred.cpp, migrated from shred.c from coreutils
 * shred.c - overwrite files and devices to make it harder to recover data
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
 * Colin Plumb
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
#define PROGRAM_NAME shred

#define VERSION F_VERSION(PROGRAM_NAME)

constexpr auto USAGE =
R"(shred.

     Usage:
       shred [options] FILE...

       Overwrite the specified FILE(s) repeatedly, in order to make it harder
         for even very expensive hardware probing to recover the data.
         If FILE is -, shred standard output.

     Options:
       -h --help              Show this screen
       --version              Show version
       -f, --force            Change permissions to allow writing if necessary
       -n, --iterations=N     Overwrite N times instead of the default (%d)
       --random-source=FILE   Get random bytes from FILE
       -s, --size=N           Shred this many bytes (suffixes like K, M, G accepted)
       -u                     Deallocate and remove file after overwriting
       --remove[=HOW]         Like -u but give control on HOW to delete;  See below
       -v, --verbose          Show progress
       -x, --exact            Do not round file sizes up to the next full block;
                                this is the default for non-regular files
       -z, --zero             Add a final overwrite with zeros to hide shredding

     Note:

       Delete FILE(s) if --remove (-u) is specified.  The default is not to remove
         the files because it is common to operate on device files like /dev/hda,
         and those files usually should not be removed.
         The optional HOW parameter indicates how to remove a directory entry:
         'unlink' => use a standard unlink call.
         'wipe' => also first obfuscate bytes in the name.
         'wipesync' => also sync each obfuscated byte to disk.
         The default mode is 'wipesync', but note it can be expensive.

     CAUTION: shred assumes the file system and hardware overwrite data in place.
       Although this is common, many platforms operate otherwise.  Also, backups
       and mirrors may contain unremovable copies that will let a shredded file
       be recovered later.  See the GNU coreutils manual for details.
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
