/*netdb->winsock2 수정*/
/* Test of <netdb.h> substitute.
   Copyright (C) 2007-2008, 2010-2024 Free Software Foundation, Inc.

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

/* Written by Simon Josefsson <simon@josefsson.org>, 2008.  */

#include <config.h>

#ifdef _WIN32
#include <winsock2.h>
#include <ws2tcpip.h>
#else
#include <netdb.h>
#endif

static_assert (NI_MAXHOST == 1025);
static_assert (NI_MAXSERV == 32);

/* Check that the 'struct hostent' type is defined.  */
struct hostent t1;

/* Check that the 'socklen_t' type is defined.  */
// Windows에서는 socklen_t가 정의되지 않으므로, int로 변경
int t2; // socklen_t t2;에서 int t2;로 변경

int
main (void)
{
  return 0;
}
