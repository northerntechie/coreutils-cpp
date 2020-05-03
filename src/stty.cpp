/** stty.cpp, migrated from stty.c from coreutils
 * stty -- change and print terminal line settings
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
#define PROGRAM_NAME stty

#define VERSION F_VERSION(PROGRAM_NAME)

constexpr auto USAGE =
R"(stty.

     Usage:
       stty [-F DEVICE | --file=DEVICE] [SETTING]
       stty [-F DEVICE | --file=DEVICE] [-a | --all]
       stty [-F DEVICE | --file=DEVICE] [-g | --save]

       Print or change terminal characteristics.

     Options:
       -h --help              Show this screen
       --version              Show version
       -a, --all              Print all current settings in human-readable form
       -g, --save             Print all current settings in a stty-readable form
       -F, --file=DEVICE      Open and use the specified DEVICE instead of stdin

       Optional - before SETTING indicates negation.  An * marks non-POSIX
         settings.  The underlying system defines which settings are available.

       Special characters:
         discard CHAR  CHAR will toggle discarding of output
         dsusp CHAR    CHAR will send a terminal stop signal once input flushed
         eof CHAR      CHAR will send an end of file (terminate the input)
         eol CHAR      CHAR will end the line
         eol2 CHAR     alternate CHAR for ending the line
         erase CHAR    CHAR will erase the last character typed
         intr CHAR     CHAR will send an interrupt signal
         kill CHAR     CHAR will erase the current line
         lnext CHAR    CHAR will enter the next character quoted
         status CHAR   CHAR will send an info signal
         quit CHAR     CHAR will send a quit signal
         rprnt CHAR    CHAR will redraw the current line
         start CHAR    CHAR will restart the output after stopping it
         stop CHAR     CHAR will stop the output
         susp CHAR     CHAR will send a terminal stop signal
         swtch CHAR    CHAR will switch to a different shell layer
         werase CHAR   CHAR will erase the last word typed

     Special settings:
       N             Set the input and output speeds to N bauds
       cols N        Tell the kernel that the terminal has N columns
       columns N     Same as cols N
       [-]drain      Wait for transmission before applying settings
       ispeed N      Set the input speed to N
       line N        Use line discipline N
       min N         With -icanon, set N characters minimum for a completed read
       ospeed N      Set the output speed to N
       rows N        Tell the kernel that the terminal has N rows
       size          Print the number of rows and columns according to the kernel
       speed         Print the terminal speed
       time N        With -icanon, set read timeout of N tenths of a second

     Control settings:
       [-]clocal     Disable modem control signals
       [-]cread      Allow input to be received
       [-]crtscts    Enable RTS/CTS handshaking
       [-]cdtrdsr    Enable DTR/DSR handshaking
       csN           Set character size to N bits, N in [5..8]
       [-]cstopb     Use two stop bits per character (one with '-')
       [-]hup        Send a hangup signal when the last process closes the tty
       [-]hupcl      Same as [-]hup
       [-]parenb     Generate parity bit in output and expect parity bit in input
       [-]parodd     Set odd parity (or even parity with '-')
       [-]cmspar     Use \"stick\" (mark/space) parity


     Input settings:
       [-]brkint     Breaks cause an interrupt signal
       [-]icrnl      Translate carriage return to newline
       [-]ignbrk     Ignore break characters
       [-]igncr      Ignore carriage return
       [-]ignpar     Ignore characters with parity errors
       [-]imaxbel    Beep and do not flush a full input buffer on a character
       [-]inlcr      Translate newline to carriage return
       [-]inpck      Enable input parity checking
       [-]istrip     Clear high (8th) bit of input characters
       [-]iutf8      Assume input characters are UTF-8 encoded
       [-]iuclc      Translate uppercase characters to lowercase
       [-]ixany      Let any character restart output, not only start character
       [-]ixoff      Enable sending of start/stop characters
       [-]ixon       Enable XON/XOFF flow control
       [-]parmrk     Mark parity errors (with a 255-0-character sequence)
       [-]tandem     Same as [-]ixoff

     Output settings:
       bsN           Backspace delay style, N in [0..1]
       crN           Carriage return delay style, N in [0..3]
       ffN           Form feed delay style, N in [0..1]
       nlN           Newline delay style, N in [0..1]
       [-]ocrnl      Translate carriage return to newline
       [-]ofdel      Use delete characters for fill instead of NUL characters
       [-]ofill      Use fill (padding) characters instead of timing for delays
       [-]olcuc      Translate lowercase characters to uppercase
       [-]onlcr      Translate newline to carriage return-newline
       [-]onlret     Newline performs a carriage return
       [-]onocr      Do not print carriage returns in the first column
       [-]opost      Postprocess output
       tabN          Horizontal tab delay style, N in [0..3]
       tabs          Same as tab0
       -tabs         Same as tab3
       vtN           Vertical tab delay style, N in [0..1]

     Local settings:
       [-]crterase   Echo erase characters as backspace-space-backspace
       crtkill       Kill all line by obeying the echoprt and echoe settings
       -crtkill      Kill all line by obeying the echoctl and echok settings
       [-]ctlecho    Echo control characters in hat notation ('^c')
       [-]echo       Echo input characters
       [-]echoctl    Same as [-]ctlecho
       [-]echoe      Same as [-]crterase
       [-]echok      Echo a newline after a kill character
       [-]echoke     Same as [-]crtkill
       [-]echonl     Echo newline even if not echoing other characters
       [-]echoprt    Echo erased characters backward, between '\\' and '/'
       [-]extproc    Enable \"LINEMODE\"; useful with high latency links
       [-]flusho     Discard output
       [-]icanon     Enable special characters:
       [-]iexten     Enable non-POSIX special characters
       [-]isig       Enable interrupt, quit, and suspend special characters
       [-]noflsh     Disable flushing after interrupt and quit special characters
       [-]prterase   Same as [-]echoprt
       [-]tostop     Stop background jobs that try to write to the terminal
       [-]xcase      With icanon, escape with '\\' for uppercase characters

     Combination settings:
       [-]LCASE      Same as [-]lcase
       cbreak        Same as -icanon
       -cbreak       Same as icanon
       cooked        Same as brkint ignpar istrip icrnl ixon opost isig
                       icanon, eof and eol characters to their default values
       -cooked       same as raw
       crt           same as echoctl
       dec           same as %s intr ^c erase 0177
                       kill ^u
       [-]decctlq    same as [-]ixany
       ek            erase and kill characters to their default values
       evenp         same as parenb -parodd cs7
       -evenp        same as -parenb cs8
       [-]lcase      same as xcase iuclc olcuc
       litout        same as -parenb -istrip -opost cs8
       -litout       same as parenb istrip opost cs7
       oddp          same as parenb parodd cs7
       -oddp         same as -parenb cs8
       [-]parity     same as [-]evenp
       pass8         same as -parenb -istrip cs8
       -pass8        same as parenb istrip cs7
       raw           same as -ignbrk -brkint -ignpar -parmrk -inpck -istrip
                       -inlcr -igncr -icrnl -ixon -ixoff -icanon -opost
                       -isig%s min 1 time 0
       -raw          same as cooked
       sane          same as cread -ignbrk brkint -inlcr -igncr icrnl
                       icanon iexten echo echoe echok -echonl -noflsh

     Handle the tty line connected to standard input.  Without arguments,
       prints baud rate, line discipline, and deviations from stty sane.  In
       settings, CHAR is taken literally, or coded as in ^c, 0x37, 0177 or
       127; special values ^- or undef used to disable special characters.
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
