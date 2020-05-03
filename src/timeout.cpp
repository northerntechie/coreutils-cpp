/** timeout.cpp, migrated from timeout.c from coreutils
 * timeout -- run a command with bounded time
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
 * Padraig Brady
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
#define PROGRAM_NAME timeout

#define VERSION F_VERSION(PROGRAM_NAME)

constexpr auto USAGE =
R"(timeout.

     Usage:
       timeout [options] DURATION COMMAND [ARG...]
       timeout [options]

       Start COMMAND, and kill it if still running after DURATION.

     Options:
       -h --help              Show this screen
       --version              Show version
       --preserve-status      Exit with the same status as COMMAND, even when the
                                command times out
       --foreground           When not running timeout directly from a shell prompt,
                                allow COMMAND to read from the TTY and get TTY signals;
                                in this mode, children of COMMAND will not be timed out
       -k, --kill-after=DURATION
                              Also send a KILL signal if COMMAND is still running
                                this long after the initial signal was sent
       -s, --signal=SIGNAL    Specify the signal to be sent on timeout;
                                SIGNAL may be a name like 'HUP' or a number;
                                see 'kill -l' for a list of signals
       -v, --verbose          Diagnose to stderr any signal sent upon timeout

     Note:

       DURATION is a floating point number with an optional suffix:
         's' for seconds (the default), 'm' for minutes, 'h' for hours or
         'd' for days.\nA duration of 0 disables the associated timeout.

       If the command times out, and --preserve-status is not set, then exit with
         status 124.  Otherwise, exit with the status of COMMAND.  If no signal
         is specified, send the TERM signal upon timeout.  The TERM signal kills
         any process that does not block or catch that signal.  It may be necessary
         to use the KILL (9) signal, since this signal cannot be caught, in which
         case the exit status is 128+9 rather than 124.
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
