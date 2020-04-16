/* echo.cpp, migrated from,
echo.c, derived from code echo.c in Bash.
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

/* C++ includes */
#include "docopt/docopt.h"
#include "fmt/format.h"
#include <cassert>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>
#include <variant>
/* End of C++ includes */

/* The official name of this program (e.g., no 'g' prefix).  */
#define PROGRAM_NAME "echo"

/* AUTHORS
Original authors: Brian Fox, Chet Ramey (work this code is derived from)
Migration author: Todd Saharchuk
*/
constexpr auto AUTHORS = "Todd Saharchuk";

/* If true, interpret backslash escapes by default.  */
#ifndef DEFAULT_ECHO_TO_XPG
enum { DEFAULT_ECHO_TO_XPG = false };
#endif

/* constexpr defines */
constexpr std::string_view USAGE =
    R"(echo.
    Usage:
      echo [-e|-E|-n] <string>
      echo (-h | --help)
      echo --version
    Options:
      -h --help     Show this screen.
      --version     Show version.
      -e            Enable interpretation of backslash escapes (default).
      -E            Disable interpretation of backslash escapes.
      -n            Do not display the trailing newline.

    Backlash Escapes:
      If -e is in effect, the following sequences are recognized:
      \\       backslash
      \a      alert (BEL)
      \b      backspace
      \c      produce no further output
      \e      escape
      \f      form feed
      \n      new line
      \r      carriage return
      \t      horizontal tab
      \v      vertical tab
      \0NNN   byte with octal value NNN (1 to 3 digits)
      \xHH    byte with hexadecimal value HH (1 to 2 digits)
    Note:
      To preserve exact spacing, use single- or double-quotes for strings.
)";

// TODO: migrate emit_ancillary_info()
//emit_ancillary_info (PROGRAM_NAME);

/* Print the words in LIST to standard output.  If the first word is
'-n', then don't print a trailing newline.  We also support the
echo syntax from Version 9 unix systems. */

int main (int argc, char **argv)
{
    //bool posixly_correct = getenv ("POSIXLY_CORRECT");


    bool allow_options = (1 < argc);

    /* System V machines already have a /bin/sh with a v9 behavior.
Use the identical behavior for these machines so that the
existing system shell scripts won't barf.  */
    // TODO: Determine how to handle v9 behaviour
    //bool do_v9 = DEFAULT_ECHO_TO_XPG;
    bool do_v9 = false;

    // TODO: How much of these external calls do we need?
    //set_program_name (argv[0]);
    //setlocale (LC_ALL, "");
    //bindtextdomain (PACKAGE, LOCALEDIR);
    //textdomain (PACKAGE);

    std::vector<std::string> strs;
    std::map<std::string, docopt::value> _args;

    if (allow_options)
    {
        std::vector<std::string> args;
        char **pargv = argv;
        int _argc = argc;
        // Add program name
        args.emplace_back (*pargv);
        --_argc;
        ++pargv;

        while (_argc > 0)
        {
            if (std::strlen (*pargv) > 1 && ((*pargv)[0] == '-' || ((*pargv)[0] == '-' && (*pargv)[1] == '-')))
            // Found option - add to vector
            {
                args.emplace_back (*pargv);
                --_argc;
                ++pargv;
            }
            else
                break;
        }
        while(_argc > 0)
        {
            strs.emplace_back(*pargv);
            --_argc;
            ++pargv;
        }
        _args =
            docopt::docopt(USAGE.data(),
                           args,
                           true,              // show help if requested
                           "echo (cpp) 0.1.0");// version string
    }

    if(_args["-e"].asBool() == true)
    {
        for(auto& str : strs)
        {
            for(auto it = str.begin(); it != str.end(); it++)
            {
                if(*it == '\\')
                {
                    it++;
                    char c = '\\';
                    switch(*it)
                    {
                        case 'a': c = '\a'; break;
                        case 'b': c = '\b'; break;
                        case 'c': return EXIT_SUCCESS;
                        case 'e': c = '\x1B'; break;
                        case 'f': c = '\f'; break;
                        case 'n': c = '\n'; break;
                        case 'r': c = '\r'; break;
                        case 't': c = '\t'; break;
                        case 'v': c = '\v'; break;
                        case 'x': {
                            it++;
                            std::size_t num;
                            std::string number = {it,str.end()};
                            c = static_cast<unsigned char>
                                (std::stoi(number, &num, 16));
                        }; break;
                        case '0': {
                            it++;
                            std::size_t num;
                            std::string number = {it,str.end()};
                            c = static_cast<unsigned char>
                            (std::stoi(number, &num, 8));
                        }; break;
                        case '\\': c = '\\'; break;
                        default: c = '\\'; break;
                    }
                    std::cout << c;
                }
                else
                {
                    std::cout << *it;
                }
            }
            std::cout << " ";
        }
    }
    else
    {
        for(auto& str : strs)
        {
            std::cout << str << " ";
        }
    }
    // End of echo display
    if (_args["-n"].asBool() == false)
    {
        std::cout << "\n";
    }

    return EXIT_SUCCESS;
}
