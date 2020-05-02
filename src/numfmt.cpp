/** .cpp, migrated from .c from coreutils
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
 * Assaf Gordon
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
#define PROGRAM_NAME numfmt

#define VERSION F_VERSION(PROGRAM_NAME)

constexpr auto USAGE =
R"(numfmt.

     Usage:
       numfmt [options] [ NUMBER | NUMBERS... ]

       Reformat NUMBER(s), or the numbers from standard input if none are specified.

     Options:
       -h --help              Show this screen
       --version              Show version
       --debug                Print warnings about invalid input
       -d, --delimiter=X      Use X instead of whitespace for field delimiter
       --field=FIELDS         Replace the numbers in these input fields (default=1)
                                see FIELDS below
       --format=FORMAT        Use printf style floating-point FORMAT;
                                see FORMAT below for details
       --from=UNIT            Auto-scale input numbers to UNITs; default is 'none';
                                see UNIT below
       --from-unit=N          Specify the input unit size (instead of the default 1)
       --grouping             Use locale-defined grouping of digits, e.g. 1,000,000
                                (which means it has no effect in the C/POSIX locale)
       --header[=N]           Print (without converting) the first N header lines;
                                N defaults to 1 if not specified
       --invalid=MODE         Failure mode for invalid numbers: MODE can be:
                                abort (default), fail, warn, ignore
       --padding=N            Pad the output to N characters; positive N will
                                right-align; negative N will left-align;
                                padding is ignored if the output is wider than N;
                                the default is to automatically pad if a whitespace
                                is found
       --round=METHOD         Use METHOD for rounding when scaling; METHOD can be:
                                up, down, from-zero (default), towards-zero, nearest
       --suffix=SUFFIX        Add SUFFIX to output numbers, and accept optional
                                SUFFIX in input numbers
       --to=UNIT              Auto-scale output numbers to UNITs; see UNIT below
       --to-unit=N            The output unit size (instead of the default 1)
       -z, --zero-terminated  Line delimiter is NUL, not newline

     UNIT options:
       none       no auto-scaling is done; suffixes will trigger an error
       auto       accept optional single/two letter suffix:
         1K = 1000,
         1Ki = 1024,
         1M = 1000000,
         1Mi = 1048576,
       si         accept optional single letter suffix:
         1K = 1000,
         1M = 1000000,
         ...
       iec        accept optional single letter suffix:
         1K = 1024,
         1M = 1048576,
         ...
       iec-i      accept optional two-letter suffix:
         1Ki = 1024,
         1Mi = 1048576,
         ...

     FIELDS supports cut(1) style field ranges:
       N    N'th field, counted from 1
       N-   from N'th field, to end of line
       N-M  from N'th to M'th field (inclusive)
       -M   from first to M'th field (inclusive)
       -    all fields
     Multiple fields/ranges can be separated with commas

     FORMAT must be suitable for printing one floating-point argument '%f'.
       Optional quote (%'f) will enable --grouping (if supported by current locale).
       Optional width value (%10f) will pad output. Optional zero (%010f) width
       will zero pad the number. Optional negative values (%-10f) will left align.
       Optional precision (%.1f) will override the input determined precision.

     Exit status is 0 if all input numbers were successfully converted.
       By default, %s will stop at the first conversion error with exit status 2.
       With --invalid='fail' a warning is printed for each conversion error
       and the exit status is 2.  With --invalid='warn' each conversion error is
       diagnosed, but the exit status is 0.  With --invalid='ignore' conversion
       errors are not diagnosed and the exit status is 0.

     Examples:

       $ numfmt --to=si 1000
            -> \"1.0K\"
       $ numfmt --to=iec 2048
            -> \"2.0K\"
       $ numfmt --to=iec-i 4096
            -> \"4.0Ki\"
       $ echo 1K | numfmt --from=si
            -> \"1000\"
       $ echo 1K | numfmt --from=iec
            -> \"1024\"
       $ df -B1 | numfmt --header --field 2-4 --to=si
       $ ls -l  | numfmt --header --field 5 --to=iec
       $ ls -lh | numfmt --header --field 5 --from=iec --padding=10
       $ ls -lh | numfmt --header --field 5 --from=iec --format %%10f
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
