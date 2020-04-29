/** dd.cpp, migrated from dd.c from coreutils
 * dd -- convert a file while copying it.
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
 * Paul Rubin
 * David MacKenzie
 * Stuart Kemp
 *
 * C++ Code migration:
 * Todd Saharchuk, tsaharchuk1@athabasca.edu
 */

// C++ includes
#include <iostream>
#include <map>
#include <string>
#include "docopt/docopt.h"
#include "globals.h"
// End of C++ includes

/* The official name of this program (e.g., no 'g' prefix).  */
#define PROGRAM_NAME "dd"

constexpr auto VERSION = cc::versionString(PROGRAM_NAME);

constexpr auto USAGE =
R"(dd.

     Usage:
       dd --if=FILE --of=FILE [options]

       Copy a file, converting and formatting according to the operands.

     Options:
       -h --help              Show this screen
       --version              Show version
       --bs=BYTES             Read and write up to BYTES bytes at a time (default: 512);
                                overrides ibs and obs
       --cbs=BYTES            Convert BYTES bytes at a time
       --conv=CONVS           Convert the file as per the comma separated symbol list
       --count=N              Copy only N input blocks
       --ibs=BYTES            Read up to BYTES bytes at a time (default: 512)
       --if=FILE              Read from FILE instead of stdin
       --iflag=FLAGS          Read as per the comma separated symbol list
       --obs=BYTES            Write BYTES bytes at a time (default: 512)
       --of=FILE              Write to FILE instead of stdout
       --oflag=FLAGS          Write as per the comma separated symbol list
       --seek=N               Skip N obs-sized blocks at start of output
       --skip=N               Skip N ibs-sized blocks at start of input
       --status=LEVEL         The LEVEL of information to print to stderr;
                                'none' suppresses everything but error messages,
                                'noxfer' suppresses the final transfer statistics,
                                'progress' shows periodic transfer statistics

     Notes:

       N and BYTES may be followed by the following multiplicative suffixes:
         c=1, w=2, b=512, kB=1000, K=1024, MB=1000*1000, M=1024*1024, xM=M,
         GB=1000*1000*1000, G=1024*1024*1024, and so on for T, P, E, Z, Y.
         Binary prefixes can be used, too: KiB=K, MiB=M, and so on.

       Each CONV symbol may be:

         ascii     from EBCDIC to ASCII
         ebcdic    from ASCII to EBCDIC
         ibm       from ASCII to alternate EBCDIC
         block     pad newline-terminated records with spaces to cbs-size
         unblock   replace trailing spaces in cbs-size records with newline
         lcase     change upper case to lower case
         ucase     change lower case to upper case
         sparse    try to seek rather than write all-NUL output blocks
         swab      swap every pair of input bytes
         sync      pad every input block with NULs to ibs-size; when used
                     with block or unblock, pad with spaces rather than NULs
         excl      fail if the output file already exists
         nocreat   do not create the output file
         notrunc   do not truncate the output file
         noerror   continue after read errors
         fdatasync  physically write output file data before finishing
         fsync     likewise, but also write metadata

       Each FLAG symbol may be:

         append       append mode (makes sense only for output; conv=notrunc suggested)
         cio          use concurrent I/O for data
         direct       use direct I/O for data
         directory    fail unless a directory
         dsync        use synchronized I/O for data
         sync         likewise, but also for metadata
         fullblock    accumulate full blocks of input (iflag only)
         nonblock     use non-blocking I/O
         noatime      do not update access time
         nocache      Request to drop cache.  See also oflag=sync
         noctty       do not assign controlling terminal from file
         nofollow     do not follow symlinks
         nolinks      fail if multiply-linked
         binary       use binary I/O for data
         text         use text I/O for data
         count_bytes  treat 'count=N' as a byte count (iflag only)
         skip_bytes   treat 'skip=N' as a byte count (iflag only)
         seek_bytes   treat 'seek=N' as a byte count (oflag only)

       Sending a %s signal to a running 'dd' process makes it
         print I/O statistics to standard error and then resume copying.
)";

int main(int argc, char** argv)
{

  std::map<std::string, docopt::value> args =
      docopt::docopt(USAGE,
                     {argv+1, argv+argc},
                     true,
                     VERSION.data());

    // TODO(northerntechie): Finish implementation
    for(auto kv : args)
    {
        std::cout << kv.first << " : " << kv.second << "\n";
    }

    return EXIT_SUCCESS;
}
