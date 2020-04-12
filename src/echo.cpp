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
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* C++ includes */
#include <cassert>
#include <string>
#include <cstring>
#include <iostream>
/* End of C++ includes */

/* C includes */
//#include <config.h>
//#include <stdio.h>
//#include <assert.h>
//#include <sys/types.h>
//#include "system.h"
/* Endof C includes */

/* The official name of this program (e.g., no 'g' prefix).  */
#define PROGRAM_NAME "echo"

/* AUTHORS
   Original authors: Brian Fox, Chet Ramey
   Migration author: Todd Saharchuk
*/
constexpr auto AUTHORS = "Todd Saharchuk";
    
/* If true, interpret backslash escapes by default.  */
#ifndef DEFAULT_ECHO_TO_XPG
enum { DEFAULT_ECHO_TO_XPG = false };
#endif

/* constexpr defines */
constexpr auto VERSION = "0.1.0";
constexpr auto HELP_OPTION_DESCRIPTION =
    "      --help     display this help and exit\n";
constexpr auto VERSION_OPTION_DESCRIPTION =              \
    "      --version  output version information and exit\n";
constexpr auto USAGE_BUILTIN_WARNING = "\nNOTE: your shell may have its own version of "
    PROGRAM_NAME ", which usually supersedes\n" 
    "the version described here.  Please refer to your shell's documentation\n" 
    "for details about the options it supports.\n";

void usage (const int status)
{
  /* STATUS should always be EXIT_SUCCESS (unlike in most other
     utilities which would call emit_try_help otherwise).  */
    assert (status == EXIT_SUCCESS);
    
    std::cout << "Usage: " << PROGRAM_NAME
              << " [SHORT-OPTION]... [STRING]...\n"
              << " or: " << PROGRAM_NAME << " LONG-OPTION\n";
    std::cout << "Echo the STRING(s) to standard output.\n\n"
              << " -n             do not output the trailing newline\n";
    if(DEFAULT_ECHO_TO_XPG)
    {
        std::cout << " -e             enable interpretation of backslash escapes (default)\n"
                  << " -E             disable interpretation of backslash escapes\n";
    }
    else
    {
        std::cout << " -e             enable interpretation of backslash escapes\n"
                  << " -E             disable interpretation of backslash escapes (default)\n";
    }
    std::cout << HELP_OPTION_DESCRIPTION;
    std::cout << VERSION_OPTION_DESCRIPTION;
    std::cout << "\n"
              << "If -e is in effect, the following sequences are recognized:\n\n";
    std::cout << "\\\\      backslash\n"
              << "\\a      alert (BEL)\n"
              << "\\b      backspace\n"
              << "\\c      produce no further output\n"
              << "\\e      escape\n"
              << "\\f      form feed\n"
              << "\\n      new line\n"
              << "\\r      carriage return\n"
              << "\\t      horizontal tab\n"
              << "\\v      vertical tab\n"
              << "\\0NNN   byte with octal value NNN (1 to 3 digits)\n"
              << "\\xHH    byte with hexadecimal value HH (1 to 2 digits)\n";
    std::cout << USAGE_BUILTIN_WARNING << PROGRAM_NAME;
    // TODO: migrate emit_ancillary_info()
    //emit_ancillary_info (PROGRAM_NAME);
    exit (status);
}

/* Convert C from hexadecimal character to integer.  */
static int hextobin (unsigned char c)
{
  switch (c)
    {
    default: return c - '0';
    case 'a': case 'A': return 10;
    case 'b': case 'B': return 11;
    case 'c': case 'C': return 12;
    case 'd': case 'D': return 13;
    case 'e': case 'E': return 14;
    case 'f': case 'F': return 15;
    }
}

/* Print the words in LIST to standard output.  If the first word is
   '-n', then don't print a trailing newline.  We also support the
   echo syntax from Version 9 unix systems. */

int main (int argc, char **argv)
{
    bool display_return = true;
    //bool posixly_correct = getenv ("POSIXLY_CORRECT");

    //bool allow_options =
    //(! posixly_correct
    //|| (! DEFAULT_ECHO_TO_XPG && 1 < argc && STREQ (argv[1], "-n")));

    bool allow_options = (1 < argc); //&& (std::strcmp(argv[1], "-n") == 0);

    /* System V machines already have a /bin/sh with a v9 behavior.
       Use the identical behavior for these machines so that the
       existing system shell scripts won't barf.  */
    //bool do_v9 = DEFAULT_ECHO_TO_XPG;
    bool do_v9 = false;
    
    //initialize_main (&argc, &argv); //empty
    
    //set_program_name (argv[0]);
    //setlocale (LC_ALL, "");
    //bindtextdomain (PACKAGE, LOCALEDIR);
    //textdomain (PACKAGE);

    //atexit (close_stdout);

    /* We directly parse options, rather than use parse_long_options, in
       order to avoid accepting abbreviations.  */
    if (allow_options && argc == 2)
    {
        if(std::strcmp(argv[1], "--help") == 0)
            usage (EXIT_SUCCESS);
        if (std::strcmp(argv[1], "--version") == 0)
        {
            std::cout << PROGRAM_NAME << ", " << VERSION
                      << ", " << AUTHORS << "\n";
          return EXIT_SUCCESS;
        }
    }

    --argc;
    ++argv;

  if (allow_options)
    while (argc > 0 && *argv[0] == '-')
      {
        char const *temp = argv[0] + 1;
        size_t i;

        /* If it appears that we are handling options, then make sure that
           all of the options specified are actually valid.  Otherwise, the
           string should just be echoed.  */

        for (i = 0; temp[i]; i++)
          switch (temp[i])
            {
            case 'e': case 'E': case 'n':
              break;
            default:
              goto just_echo;
            }

        if (i == 0)
          goto just_echo;

        /* All of the options in TEMP are valid options to ECHO.
           Handle them. */
        while (*temp)
          switch (*temp++)
            {
            case 'e':
              do_v9 = true;
              break;

            case 'E':
              do_v9 = false;
              break;

            case 'n':
              display_return = false;
              break;
            }

        argc--;
        argv++;
      }

just_echo:

  if (do_v9)
    {
      while (argc > 0)
        {
          char const *s = argv[0];
          unsigned char c;

          while ((c = *s++))
            {
              if (c == '\\' && *s)
                {
                  switch (c = *s++)
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
                    case 'x':
                      {
                        unsigned char ch = *s;
                        if (! isxdigit (ch))
                          goto not_an_escape;
                        s++;
                        c = hextobin (ch);
                        ch = *s;
                        if (isxdigit (ch))
                          {
                            s++;
                            c = c * 16 + hextobin (ch);
                          }
                      }
                      break;
                    case '0':
                      c = 0;
                      if (! ('0' <= *s && *s <= '7'))
                        break;
                      c = *s++;
                      //FALLTHROUGH;
                    case '1': case '2': case '3':
                    case '4': case '5': case '6': case '7':
                      c -= '0';
                      if ('0' <= *s && *s <= '7')
                        c = c * 8 + (*s++ - '0');
                      if ('0' <= *s && *s <= '7')
                        c = c * 8 + (*s++ - '0');
                      break;
                    case '\\': break;

                    not_an_escape:
                    default:  putchar ('\\'); break;
                    }
                }
              putchar (c);
            }
          argc--;
          argv++;
          if (argc > 0)
            putchar (' ');
        }
    }
  else
    {
      while (argc > 0)
        {
          fputs (argv[0], stdout);
          argc--;
          argv++;
          if (argc > 0)
            putchar (' ');
        }
    }

  if (display_return)
    putchar ('\n');
  return EXIT_SUCCESS;
}
