/*netdb->winsock2 수정*/
/* Test of <netdb.h> substitute in C++ mode.
   Copyright (C) 2011-2024 Free Software Foundation, Inc.

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

/* Written by Bruno Haible <bruno@clisp.org>, 2011.  */

#define GNULIB_NAMESPACE gnulib
#include <config.h>

#ifdef _WIN32
#include <winsock2.h>
#include <ws2tcpip.h>
#else
#include <netdb.h>
#endif

#include "signature.h"

#if GNULIB_TEST_GETADDRINFO
SIGNATURE_CHECK (GNULIB_NAMESPACE::getaddrinfo, int,
                 (const char *, const char *, const struct addrinfo *,
                  struct addrinfo **));
SIGNATURE_CHECK (GNULIB_NAMESPACE::freeaddrinfo, void, (struct addrinfo *));
SIGNATURE_CHECK (GNULIB_NAMESPACE::gai_strerror, const char *, (int));
SIGNATURE_CHECK (GNULIB_NAMESPACE::getnameinfo, int,
                 (const struct sockaddr *, int, char *, int,
                  char *, int, int)); // socklen_t를 int로 변경
#endif

int main ()
{
    // Windows 소켓 초기화
#ifdef _WIN32
    WSADATA wsaData;
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
        fprintf(stderr, "WSAStartup failed.\n");
        return 1;
    }
#endif

    // 여기에 추가적인 테스트 코드 또는 함수 호출을 추가하세요.

#ifdef _WIN32
    WSACleanup(); // Windows 소켓 종료
#endif

    return 0;
}
