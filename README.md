# Coreutils-CPP - A modern C++ interpretation of the GNU coreutils library

These are some of the GNU core utilities migrated to C++ code through a 
complete rewrite using modern C++ conventions and techniques.  This package
is the union of the GNU fileutils, sh-utils, and textutils packages.

Most of these programs lack significant advantages over their Unix
and GNU counterparts, such as greater speed, additional options, and fewer
arbitrary limits.  The only advantage is the implementations are developed
using modern C++.

Important: 
2020-04-28 Current library build is only a skeleton build.  The docopt usage
strings are built for most programs (not in future).  You can fork the project if you want to
finish implementations.  PR's are welcome.

The programs that can be built with this package are:

  b2sum echo touch basename basenc cat chcon chgrp chmod chown chroot 
  cksum comm coreutils cp csplit cut date dd df dircolors dirname du 
  env expand expr factor false fmt fold groups head hostid hostname
  id install join kill link ln logname ls md5sum mkdir mkfifo mknod 
  mktemp mv nice nl nohup nproc numfmt od paste pathchk pinky pr 
  printenv printf ptx pwd readlink realpath rm rmdir runcon seq shred 
  shuf sleep sort split stat stdbuf stty sum sync tac tail tee test 
  timeout tr true truncate tsort tty uname unexpand uniq unlink uptime
  users wc who whoami yes
  
Future:

  arch base32 base64 dir sha1sum sha224sum sha256sum sha384sum sha512sum
  vdir  
  
Unlike the rest of the GNU system, these programs do not conform to
POSIX, with BSD and other extensions.  For closer conformance, choose another 
library.

This library is a toy library to explore the issues of migrating system tools
programmed in C to modern C++.  Use at your own risk.

LICENSE: Same as original GNU coreutils, GPL v1.3.

C++ migrated implementation code (c) Todd Saharchuk, 2020.

Permission is granted to copy, distribute and/or modify this document
under the terms of the GNU Free Documentation License, Version 1.3 or
any later version published by the Free Software Foundation.  A copy 
of the license is included in the "GNU Free Documentation License" 
file as part of this distribution.
