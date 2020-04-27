/* basenc.cpp, migrated from basenc.c from coreutils
Copyright (C) 1987-2020 Free Software Foundation, Inc.

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <https://www.gnu.org/licenses/>.

Migrated C++ code Copyright (C) Todd Saharchuk, 2020.

*/

// C++ includes
#include <iostream>
#include <map>
#include <string>
#include "docopt/docopt.h"
// End of C++ includes

/* The official name of this program (e.g., no 'g' prefix).  */
#define PROGRAM_NAME "basenc"

constexpr auto USAGE =
R"(basenc.

     Usage:
       basenc [options] ( FILE | [-] )

         Print NAME with any leading directory components removed.
         If specified, also remove a trailing SUFFIX.

     Options:
       -d, --decode          Decode data
       -w, --wrap=COLS       Wrap encoded lines after COLS character (default 76)
       -i, --ignore-garbage  When decoding, ignore non-alphabet characters\n\
       --base64              Same as 'base64' program (RFC4648 section 4)
       --base64url           File- and url-safe base64 (RFC4648 section 5)
       --base32              Same as 'base32' program (RFC4648 section 6)
       --base32hex           Extended hex alphabet base32 (RFC4648 section 7)
       --base16              Hex encoding (RFC4648 section 8)
       --base2msbf           Bit string with most significant bit (msb) first
       --base2lsbf           Bit string with least significant bit (lsb) first
       --z85                 Ascii85-like encoding (ZeroMQ spec:32/Z85);
                               when encoding, input length must be a multiple of 4;
                               when decoding, input length must be a multiple of 5

     Notes:

     When decoding, the input may contain newlines in addition to the bytes of
       the formal alphabet.  Use --ignore-garbage to attempt to recover
       from any other non-alphabet bytes in the encoded stream.
       The data are encoded as described for the basenc alphabet in RFC 4648.
     When decoding, the input may contain newlines in addition to the bytes of
       the formal basenc alphabet.  Use --ignore-garbage to attempt to recover
       from any other non-alphabet bytes in the encoded stream.
)";

int main(int argc, char** argv)
{
    std::map<std::string, docopt::value> args =
        docopt::docopt(USAGE,
                       {argv+1, argv+argc},
                        true,
                        "basename (cpp) 0.1.0");

    // TODO(northerntechie): Finish implementation
    for(auto kv : args)
    {
        std::cout << kv.first << " : " << kv.second << "\n";
    }

    return EXIT_SUCCESS;
}
