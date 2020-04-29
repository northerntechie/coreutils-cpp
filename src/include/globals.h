/* coreutils-cpp
   A C++ toy library based on the GNU coreutils library.

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

   Migrated C++ code (c) Todd Saharchuk, 2020.
*/
#pragma once
#ifndef __GLOBALS_H__
#define __GLOBALS_H__

#include <string>


/**
 * Global Defines
 */

using namespace std::string_literals;

namespace cc
{
/* Error Code Strings */
constexpr auto ERR_BAD_OPTION = "Error: Bad or missing option!";

/* Version info */
constexpr auto MAJOR_VER = 0;  // Development = 0
constexpr auto MINOR_VER = 1;
constexpr auto PATCH_VER = 0;

template<typename T>
constexpr auto stringify(T args...)
{
  return std::string_view(args);
}

constexpr auto versionString(const std::string_view prog)
{
  return stringify(prog, " (cpp) ", MAJOR_VER,
      ".", MINOR_VER, ".", PATCH_VER);
}

} /* End of namespace cc */
#endif
