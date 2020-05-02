/** od.cpp, migrated from od.c from coreutils
 * od -- dump files in octal and other formats
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
 * Jim Meyering
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
#define PROGRAM_NAME od

#define VERSION F_VERSION(PROGRAM_NAME)

constexpr auto USAGE =
R"(od.

     Usage:
       od [options] FILE...
       od [ -abcdfilosx ] FILE [ [+] OFFSET[.][b] ]
       od --traditional [options] [FILE] [[+]OFFSET[.][b] [+][LABEL][.][b]]

       Write an unambiguous representation, octal bytes by default,
         of FILE to standard output.  With more than one FILE argument,
         concatenate them in the listed order to form the input.

       If first and second call formats both apply, the second format is assumed
         if the last operand begins with + or (if there are 2 operands) a digit.
         An OFFSET operand means -j OFFSET.  LABEL is the pseudo-address
         at first byte printed, incremented when dump is progressing.
         For OFFSET and LABEL, a 0x or 0X prefix indicates hexadecimal;
         suffixes may be . for octal and b for multiply by 512.

     Options:
       -h --help                  Show this screen
       --version                  Show version
       -A, --address-radix=RADIX  Output format for file offsets; RADIX is one
                                    of [doxn], for Decimal, Octal, Hex or None
       --endian={big|little}      Swap input bytes according the specified order
       -j, --skip-bytes=BYTES     Skip BYTES input bytes first
       -N, --read-bytes=BYTES     Limit dump to BYTES input bytes
       -S BYTES, --strings[=BYTES]
                                  Output strings of at least BYTES graphic chars;
                                    3 is implied when BYTES is not specified
       -t, --format=TYPE          Select output format or formats
       -v, --output-duplicates    Do not use * to mark line suppression
       -w[BYTES], --width[=BYTES]
                                  Output BYTES bytes per output line;
                                    32 is implied when BYTES is not specified
       --traditional              Accept arguments in third form above

     Traditional format specifications may be intermixed; they accumulate:

       -a                         Same as -t a, select named characters, ignoring high-order bit
       -b                         Same as -t o1, select octal bytes
       -c                         Same as -t c,  select printable characters or backslash escapes
       -d                         Same as -t u2, select unsigned decimal 2-byte units
       -f                         Same as -t fF, select floats
       -i                         Same as -t dI, select decimal ints
       -l                         Same as -t dL, select decimal longs
       -o                         Same as -t o2, select octal 2-byte units
       -s                         Same as -t d2, select decimal 2-byte units
       -x                         Same as -t x2, select hexadecimal 2-byte units

     TYPE is made up of one or more of these specifications:

       a                          Named character, ignoring high-order bit
       c                          Printable character or backslash escape
       d[SIZE]                    Signed decimal, SIZE bytes per integer
       f[SIZE]                    Floating point, SIZE bytes per float
       o[SIZE]                    Octal, SIZE bytes per integer
       u[SIZE]                    unsigned decimal, SIZE bytes per integer
       x[SIZE]                    hexadecimal, SIZE bytes per integer

     Note:

       SIZE is a number.  For TYPE in [doux], SIZE may also be C for
         sizeof(char), S for sizeof(short), I for sizeof(int) or L for
         sizeof(long).  If TYPE is f, SIZE may also be F for sizeof(float), D
         for sizeof(double) or L for sizeof(long double).
       Adding a z suffix to any type displays printable characters at the end of
         each output line.

       BYTES is hex with 0x or 0X prefix, and may have a multiplier suffix:
         b    512
         KB   1000
         K    1024
         MB   1000*1000
         M    1024*1024
       and so on for G, T, P, E, Z, Y.
       Binary prefixes can be used, too: KiB=K, MiB=M, and so on.
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
