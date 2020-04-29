/** date.cpp, migrated from date.c from coreutils\
 * date - print or set the system date and time
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
 * Todd Saharchuk, tsaharchuk1@athabasca.edu
 */

// C++ includes
#include <iostream>
#include <map>
#include <string>
#include "docopt/docopt.h"
// End of C++ includes

/* The official name of this program (e.g., no 'g' prefix).  */
#define PROGRAM_NAME "date"

constexpr auto USAGE =
R"(date.

     Usage:
       date [options] [+FORMAT...]
       date [ -u | --utc | --universal ] [ MMDDhhmm[[CC]YY][.ss]]

       Display the current time in the given FORMAT, or set the system date.

     Options:
       -h --help              Show this screen
       --version              Show version
       -d, --date=STRING      Display time described by STRING, not 'now'
       --debug                Annotate the parsed date,
                                and warn about questionable usage to stderr
       -f, --file=DATEFILE    Like --date; once for each line of DATEFILE
       -I[FMT], --iso-8601[=FMT]
                              Output date/time in ISO 8601 format.
                                FMT='date' for date only (the default),
                                'hours', 'minutes', 'seconds', or 'ns'
                                for date and time to the indicated precision.
                                Example: 2006-08-14T02:34:56-06:00
       -R, --rfc-email        Output date and time in RFC 5322 format.
                                Example: Mon, 14 Aug 2006 02:34:56 -0600
       --rfc-3339=FMT         Output date/time in RFC 3339 format.
                                FMT='date', 'seconds', or 'ns'
                                for date and time to the indicated precision.
                                Example: 2006-08-14 02:34:56-06:00
       -r, --reference=FILE   Display the last modification time of FILE
       -s, --set=STRING       Set time described by STRING
       -u, --utc, --universal
                              Print or set Coordinated Universal Time (UTC)

     Notes:
       FORMAT controls the output.  Interpreted sequences are:
         %%   a literal %
         %a   locale's abbreviated weekday name (e.g., Sun)
         %A   locale's full weekday name (e.g., Sunday)
         %b   locale's abbreviated month name (e.g., Jan)
         %B   locale's full month name (e.g., January)
         %c   locale's date and time (e.g., Thu Mar  3 23:05:25 2005)
         %C   century; like %Y, except omit last two digits (e.g., 20)
         %d   day of month (e.g., 01)
         %D   date; same as %m/%d/%y
         %e   day of month, space padded; same as %_d
         %F   full date; like %+4Y-%m-%d
         %g   last two digits of year of ISO week number (see %G)
         %G   year of ISO week number (see %V); normally useful only with %V
         %h   same as %b
         %H   hour (00..23)
         %I   hour (01..12)
         %j   day of year (001..366)
         %k   hour, space padded ( 0..23); same as %_H
         %l   hour, space padded ( 1..12); same as %_I
         %m   month (01..12)
         %M   minute (00..59)
         %n   a newline
         %N   nanoseconds (000000000..999999999)
         %p   locale's equivalent of either AM or PM; blank if not known
         %P   like %p, but lower case
         %q   quarter of year (1..4)
         %r   locale's 12-hour clock time (e.g., 11:11:04 PM)
         %R   24-hour hour and minute; same as %H:%M
         %s   seconds since 1970-01-01 00:00:00 UTC
         %S   second (00..60)
         %t   a tab
         %T   time; same as %H:%M:%S
         %u   day of week (1..7); 1 is Monday
         %U   week number of year, with Sunday as first day of week (00..53)
         %V   ISO week number, with Monday as first day of week (01..53)
         %w   day of week (0..6); 0 is Sunday
         %W   week number of year, with Monday as first day of week (00..53)
         %x   locale's date representation (e.g., 12/31/99)
         %X   locale's time representation (e.g., 23:13:48)
         %y   last two digits of year (00..99)
         %Y   year
         %z   +hhmm numeric time zone (e.g., -0400)
         %:z  +hh:mm numeric time zone (e.g., -04:00)
         %::z  +hh:mm:ss numeric time zone (e.g., -04:00:00)
         %:::z  numeric time zone with : to necessary precision (e.g., -04, +05:30)
         %Z   alphabetic time zone abbreviation (e.g., EDT)

        By default, date pads numeric fields with zeroes.

       The following optional flags may follow '%':

         -  (hyphen) do not pad the field
         _  (underscore) pad with spaces
         0  (zero) pad with zeros
         +  pad with zeros, and put '+' before future years with >4 digits
         ^  use upper case if possible
         #  use opposite case if possible

       After any flags comes an optional field width, as a decimal number;
         then an optional modifier, which is either
         E to use the locale's alternate representations if available, or
         O to use the locale's alternate numeric symbols if available.

     Examples:

       Convert seconds since the epoch (1970-01-01 UTC) to a date

       $ date --date='@2147483647'

       Show the time on the west coast of the US (use tzselect(1) to find TZ)

       $ TZ='America/Los_Angeles' date

       Show the local time for 9AM next Friday on the west coast of the US

       $ date --date='TZ=\"America/Los_Angeles\" 09:00 next Fri'
)";

int main(int argc, char** argv)
{
    std::map<std::string, docopt::value> args =
        docopt::docopt(USAGE,
                       {argv+1, argv+argc},
                        true,
                        "date (cpp) 0.1.0");

    // TODO(northerntechie): Finish implementation
    for(auto kv : args)
    {
        std::cout << kv.first << " : " << kv.second << "\n";
    }

    return EXIT_SUCCESS;
}
