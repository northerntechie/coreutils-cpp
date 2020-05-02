/** md5sum.cpp, migrated from md5sum.c from coreutils
 * Compute checksums of files or strings.
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
 * Ulrich Drepper <drepper@gnu.ai.mit.edu>
 * Scott Miller
 * David Madore
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
#define PROGRAM_NAME md5sum

#define VERSION F_VERSION(PROGRAM_NAME)

/* TODO(@northerntechie): Need a runtime generation of the USAGE string to
 * reflect the type of checksum and the bit-level.  Check original md5sum.c
 * file for dynamic text positions and string. */
constexpr auto USAGE =
R"(md5sum.

     Usage:
       md5sum [options] [ FILE | FILES... ]

       Print or check md5sum (xxx-bit) checksums.

     Options:
       -h --help              Show this screen
       --version              Show version
       -b, --binary           Read in binary mode (default unless reading tty stdin)
       -b, --binary           Read in binary mode
       -c, --check            Read digest_type sums from the FILEs and check them
       -l, --length           Digest length in bits; must not exceed the maximum for
                                the blake2 algorithm and must be a multiple of 8
       --tag                  Create a BSD-style checksum
       -t, --text             Read in text mode (default if reading tty stdin)
       -t, --text             Read in text mode (default)
       -z, --zero             End each output line with NUL, not newline,
                                and disable file name escaping

       The following five options are useful only when verifying checksums:

       --ignore-missing       Don't fail or report status for missing files
       --quiet                Don't print OK for each successfully verified file
       --status               Don't output anything, status code shows success
       --strict               Exit non-zero for improperly formatted checksum lines
       -w, --warn             Warn about improperly formatted checksum lines

       The sums are computed as described in md5sum.  When checking, the input
         should be a former output of this program.  The default mode is to print a
         line with checksum, a space, a character indicating input mode ('*' for binary,
         ' ' for text or where binary is insignificant), and name for each FILE.

     Note:

       There is no difference between binary mode and text mode on GNU systems.
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
