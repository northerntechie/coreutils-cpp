/** ls.cpp, migrated from ls.c from coreutils
 * 'dir', 'vdir' and 'ls' directory listing programs for GNU.
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
 * Richard Stallman
 * David MacKenzie
 * Peter Anvin <Peter.Anvin@linux.org>
 * Dennis Flaherty <dennisf@denix.elk.miles.com>
 * Greg Lee <lee@uhunix.uhcc.hawaii.edu>
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
#define PROGRAM_NAME ls

#define VERSION F_VERSION(PROGRAM_NAME)

constexpr auto USAGE =
R"(ls.

     Usage:
       ls [options] [FILE | FILES...]

       List information about the FILEs (the current directory by default).
         Sort entries alphabetically if none of -cftuvSUX nor --sort is specified.

     Options:
       -h --help              Show this screen
       --version              Show version
       -a, --all              Do not ignore entries starting with .
       -A, --almost-all       Do not list implied . and ..
       --author               With -l, print the author of each file
       -b, --escape           Print C-style escapes for nongraphic characters
       --block-size=SIZE      With -l, scale sizes by SIZE when printing them;
                                e.g., '--block-size=M'; see SIZE format below
       -B, --ignore-backups   Do not list implied entries ending with ~
       -c                     With -lt: sort by, and show, ctime (time of last
                                modification of file status information);
                                with -l: show ctime and sort by name;
                                otherwise: sort by ctime, newest first
       -C                     List entries by columns
       --color[=WHEN]         Colorize the output; WHEN can be 'always' (default
                                if omitted), 'auto', or 'never'; more info below
       -d, --directory        List directories themselves, not their contents
       -D, --dired            Generate output designed for Emacs' dired mode
       -f                     Do not sort, enable -aU, disable -ls --color
       -F, --classify         Append indicator (one of */=>@|) to entries
       --file-type            Likewise, except do not append '*'
       --format=WORD          Across -x, commas -m, horizontal -x, long -l,
                                single-column -1, verbose -l, vertical -C
       --full-time            Like -l --time-style=full-iso
       -g                     Like -l, but do not list owner
       --group-directories-first
                              Group directories before files;
                                can be augmented with a --sort option, but any
                                use of --sort=none (-U) disables grouping
       -G, --no-group         In a long listing, don't print group names
       -h, --human-readable   With -l and -s, print sizes like 1K 234M 2G etc.
       --si                   Likewise, but use powers of 1000 not 1024
       -H, --dereference-command-line
                              Follow symbolic links listed on the command line
       --dereference-command-line-symlink-to-dir
                              Follow each command line symbolic link
                                that points to a directory
       --hide=PATTERN         Do not list implied entries matching shell PATTERN
                                (overridden by -a or -A)
       --hyperlink[=WHEN]     Hyperlink file names; WHEN can be 'always'
                               (default if omitted), 'auto', or 'never'
       --indicator-style=WORD
                              Append indicator with style WORD to entry names:
                                none (default), slash (-p),
                                file-type (--file-type), classify (-F)
       -i, --inode            Print the index number of each file
       -I, --ignore=PATTERN   Do not list implied entries matching shell PATTERN
       -k, --kibibytes        Default to 1024-byte blocks for disk usage;
                                used only with -s and per directory totals
       -l                     Use a long listing format
       -L, --dereference      When showing file information for a symbolic
                                link, show information for the file the link
                                references rather than for the link itself
       -m                     Fill width with a comma separated list of entries
       -n, --numeric-uid-gid  Like -l, but list numeric user and group IDs
       -N, --literal          Print entry names without quoting
       -o                     Like -l, but do not list group information
       -p, --indicator-style=slash
                              Append / indicator to directories
       -q, --hide-control-chars
                              Print ? instead of nongraphic characters
       --show-control-chars   Show nongraphic characters as-is (the default,
                                unless program is 'ls' and output is a terminal)
       -Q, --quote-name       Enclose entry names in double quotes
       --quoting-style=WORD   Use quoting style WORD for entry names:
                                literal, locale, shell, shell-always,
                                shell-escape, shell-escape-always, c, escape
                                (overrides QUOTING_STYLE environment variable)
       -r, --reverse          Reverse order while sorting
       -R, --recursive        List subdirectories recursively
       -s, --size             Print the allocated size of each file, in blocks
       -S                     Sort by file size, largest first
       --sort=WORD            Sort by WORD instead of name: none (-U), size (-S)
                                time (-t), version (-v), extension (-X)
       --time=WORD            Change the default of using modification times;
                                access time (-u): atime, access, use;
                                change time (-c): ctime, status;
                                birth time: birth, creation;
                              with -l, WORD determines which time to show;
                              with --sort=time, sort by WORD (newest first)
       --time-style=TIME_STYLE
                              Time/date format with -l; see TIME_STYLE below
       -t                     Sort by time, newest first; see --time
       -T, --tabsize=COLS     Assume tab stops at each COLS instead of 8
       -u                     With -lt: sort by, and show, access time;
                                with -l: show access time and sort by name;
                                otherwise: sort by access time, newest first
       -U                     Do not sort; list entries in directory order
       -v                     Natural sort of (version) numbers within text
       -w, --width=COLS       Set output width to COLS.  0 means no limit
       -x                     List entries by lines instead of by columns
       -X                     Sort alphabetically by entry extension
       -Z, --context          Print any security context of each file
       -1                     List one file per line.  Avoid '\\n' with -q or -b

     Note:

       The TIME_STYLE argument can be full-iso, long-iso, iso, locale, or +FORMAT.
         FORMAT is interpreted like in date(1).  If FORMAT is FORMAT1<newline>FORMAT2,
         then FORMAT1 applies to non-recent files and FORMAT2 to recent files.
         TIME_STYLE prefixed with 'posix-' takes effect only outside the POSIX locale.
         Also the TIME_STYLE environment variable sets the default style to use.

       Using color to distinguish file types is disabled both by default and
         with --color=never.  With --color=auto, ls emits color codes only when
         standard output is connected to a terminal.  The LS_COLORS environment
         variable can change the settings.  Use the dircolors command to set it.


       Exit status:
         0  if OK,
         1  if minor problems (e.g., cannot access subdirectory),
         2  if serious trouble (e.g., cannot access command-line argument).
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
