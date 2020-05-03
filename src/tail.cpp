/** tail.cpp, migrated from tail.c from coreutils
 * tail -- output the last part of file(s)
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
 * Paul Rubin <phr@ocf.berkeley.edu>
 * David MacKenzie <djm@gnu.ai.mit.edu>
 * Ian Lance Taylor <ian@airs.com>
 * Giuseppe Scrivano <gscrivano@gnu.org>
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
#define PROGRAM_NAME tail

#define VERSION F_VERSION(PROGRAM_NAME)

constexpr auto USAGE =
R"(tail.

     Usage:
       tail [options] [FILE...]

       Print the last %d lines of each FILE to standard output.
         With more than one FILE, precede each with a header giving the file name.

     Options:
       -h --help                Show this screen
       --version                Show version
       -c, --bytes=[+]NUM       Output the last NUM bytes; or use -c +NUM to
                                  output starting with byte NUM of each file
       -f, --follow[={name|descriptor}]
                                Output appended data as the file grows;
                                  an absent option argument means 'descriptor'
       -F                       Same as --follow=name --retry
       -n, --lines=[+]NUM       Output the last NUM lines, instead of the last %d;
                                  or use -n +NUM to output starting with line NUM
       --max-unchanged-stats=N  With --follow=name, reopen a FILE which has not
                                  changed size after N (default %d) iterations
                                  to see if it has been unlinked or renamed
                                  (this is the usual case of rotated log files);
                                  with inotify, this option is rarely useful
       --pid=PID                With -f, terminate after process ID, PID dies
       -q, --quiet, --silent    Never output headers giving file names
       --retry                  Keep trying to open a file if it is inaccessible
       -s, --sleep-interval=N   With -f, sleep for approximately N seconds
                                  (default 1.0) between iterations;
                                  with inotify and --pid=P, check process P at
                                  least once every N seconds
       -v, --verbose            Always output headers giving file names
       -z, --zero-terminated    Line delimiter is NUL, not newline

     Note:
       NUM may have a multiplier suffix:
         b 512, kB 1000, K 1024, MB 1000*1000, M 1024*1024,
         GB 1000*1000*1000, G 1024*1024*1024, and so on for T, P, E, Z, Y.
         Binary prefixes can be used, too: KiB=K, MiB=M, and so on.
       With --follow (-f), tail defaults to following the file descriptor, which
         means that even if a tail'ed file is renamed, tail will continue to track
         its end.  This default behavior is not desirable when you really want to
         track the actual name of the file, not the file descriptor (e.g., log
         rotation).  Use --follow=name in that case.  That causes tail to track the
         named file in a way that accommodates renaming, removal and creation.
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
