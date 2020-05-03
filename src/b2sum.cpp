/* b2sum.cpp, migrated from b2sum.c
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
#define PROGRAM_NAME b2sum

#define VERSION F_VERSION(PROGRAM_NAME)

constexpr auto USAGE =
R"(b2sum.

     Usage:
       b2sum [options]

     Options:
       -h --help              Show this screen
       --version              Show version
)";

int main()
{
    return EXIT_FAILURE;
}