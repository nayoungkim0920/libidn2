/*netdb->winsock2 수정*/
/* Get address information (partial implementation).
   Copyright (C) 1997, 2001-2002, 2004-2024 Free Software Foundation, Inc.
   Contributed by Simon Josefsson <simon@josefsson.org>.

   This file is free software: you can redistribute it and/or modify
   it under the terms of the GNU Lesser General Public License as
   published by the Free Software Foundation; either version 2.1 of
   the License, or (at your option) any later version.

   This file is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* 이 컴파일 단위에서 __attribute__ __nonnull__ 사용하지 않음.
   그렇지 않으면 gcc가 아래 sa == NULL 검사를 최적화해버림.  */
#define _GL_ARG_NONNULL(params)

#include <config.h>

#ifdef _WIN32
#include <winsock2.h>
#include <ws2tcpip.h>
#else
#include <netdb.h>
#endif

#if HAVE_NETINET_IN_H
# include <netinet/in.h>
#endif

/* inet_ntop을 가져옴.  */
#include <arpa/inet.h>

/* calloc을 가져옴. */
#include <stdlib.h>

/* memcpy, strdup을 가져옴. */
#include <string.h>

/* snprintf을 가져옴. */
#include <stdio.h>

#include "gettext.h"
#define _(String) gettext (String)
#define N_(String) String

/* BeOS는 AF_INET이 있지만 PF_INET은 없음.  */
#ifndef PF_INET
# define PF_INET AF_INET
#endif
/* BeOS는 PF_UNSPEC도 없음.  */
#ifndef PF_UNSPEC
# define PF_UNSPEC 0
#endif

#if HAVE_GETADDRINFO

/* cdecl 호출 규약으로 재정의.  */
int
getaddrinfo (const char *restrict nodename,
             const char *restrict servname,
             const struct addrinfo *restrict hints,
             struct addrinfo **restrict res)
# undef getaddrinfo
{
  return getaddrinfo (nodename, servname, hints, res);
}

/* 주소 정보 해제 함수.  */
void
freeaddrinfo (struct addrinfo *ai)
# undef freeaddrinfo
{
  freeaddrinfo (ai);
}

#else

# if defined _WIN32 && !defined __CYGWIN__
#  define WINDOWS_NATIVE
# endif

/* gl_sockets_startup */
# include "sockets.h"

# ifdef WINDOWS_NATIVE

/* UNICODE가 정의되지 않았다고 가정하지 않음.  */
#  undef GetModuleHandle
#  define GetModuleHandle GetModuleHandleA

#  if !(_WIN32_WINNT >= _WIN32_WINNT_WINXP)

/* gcc -Wcast-function-type에서 경고를 피하기 위해.  */
#   define GetProcAddress \
     (void *) GetProcAddress

/* 함수 포인터 정의.  */
typedef int (WSAAPI *getaddrinfo_func) (const char*, const char*,
                                        const struct addrinfo*,
                                        struct addrinfo**);
typedef void (WSAAPI *freeaddrinfo_func) (struct addrinfo*);
typedef int (WSAAPI *getnameinfo_func) (const struct sockaddr*,
                                        socklen_t, char*, DWORD,
                                        char*, DWORD, int);

/* 함수 포인터 초기화.  */
static getaddrinfo_func getaddrinfo_ptr = NULL;
static freeaddrinfo_func freeaddrinfo_ptr = NULL;
static getnameinfo_func getnameinfo_ptr = NULL;

/* Win32 함수 사용 여부 판단.  */
static int
use_win32_p (void)
{
  static int done = 0;
  HMODULE h;

  if (done)
    return getaddrinfo_ptr ? 1 : 0;

  done = 1;

  h = GetModuleHandle ("ws2_32.dll");

  if (h)
    {
      /* 함수 포인터 초기화.  */
      getaddrinfo_ptr = (getaddrinfo_func) GetProcAddress (h, "getaddrinfo");
      freeaddrinfo_ptr = (freeaddrinfo_func) GetProcAddress (h, "freeaddrinfo");
      getnameinfo_ptr = (getnameinfo_func) GetProcAddress (h, "getnameinfo");
    }

  /* 어떤 것이 없으면 이상함. */
  if (!getaddrinfo_ptr || !freeaddrinfo_ptr || !getnameinfo_ptr)
    {
      getaddrinfo_ptr = NULL;
      freeaddrinfo_ptr = NULL;
      getnameinfo_ptr = NULL;
      return 0;
    }

  gl_sockets_startup (SOCKETS_1_1);

  return 1;
}

#  else

/* Win32가 아닐 경우. */
static int
use_win32_p (void)
{
  static int done = 0;

  if (!done)
    {
      done = 1;

      gl_sockets_startup (SOCKETS_1_1);
    }

  return 1;
}

/* 함수 포인터를 직접 함수로 정의.  */
#   define getaddrinfo_ptr getaddrinfo
#   define freeaddrinfo_ptr freeaddrinfo
#   define getnameinfo_ptr getnameinfo

#  endif
# endif

/* 주소 패밀리 검증.  */
static bool
validate_family (int family)
{
  /* FIXME: 더 많은 패밀리 지원. */
# if HAVE_IPV4
     if (family == PF_INET)
       return true;
# endif
# if HAVE_IPV6
     if (family == PF_INET6)
       return true;
# endif
     if (family == PF_UNSPEC)
       return true;
     return false;
}

/* 서비스 위치의 이름을 번역하고 소켓 주소 세트를 설정. */
int
getaddrinfo (const char *restrict nodename,
             const char *restrict servname,
             const struct addrinfo *restrict hints,
             struct addrinfo **restrict res)
#undef getaddrinfo
{
  struct addrinfo *tmp;
  int port = 0;
  struct hostent *he; // 이 부분은 필요 없을 수 있음.
  void *storage;
  size_t size;
# if HAVE_IPV6
  struct v6_pair {
    struct addrinfo addrinfo;
    struct sockaddr_in6 sockaddr_in6;
  };
# endif
# if HAVE_IPV4
  struct v4_pair {
    struct addrinfo addrinfo;
    struct sockaddr_in sockaddr_in;
  };
# endif

# ifdef WINDOWS_NATIVE
  if (use_win32_p ())
    return getaddrinfo_ptr (nodename, servname, hints, res);
# endif

  /* flags 검증.  */
  if (hints && (hints->ai_flags & ~(AI_CANONNAME|AI_PASSIVE)))
    return EAI_BADFLAGS;

  /* family 검증.  */
  if (hints && !validate_family (hints->ai_family))
    return EAI_FAMILY;

  /* socket type 검증.  */
  if (hints &&
      hints->ai_socktype != SOCK_STREAM && hints->ai_socktype != SOCK_DGRAM)
    return EAI_SOCKTYPE; /* FIXME: 더 나은 반환 코드? */

  /* nodename이 NULL인 경우 처리.  */
  if (!nodename)
    {
      if (!(hints->ai_flags & AI_PASSIVE))
        return EAI_NONAME;

# ifdef HAVE_IPV6
      nodename = (hints->ai_family == AF_INET6) ? "::" : "0.0.0.0";
# else
      nodename = "0.0.0.0";
# endif
    }

  /* servname이 존재하는 경우 처리.  */
  if (servname)
    {
      struct servent *se = NULL;
      const char *proto =
        (hints && hints->ai_socktype == SOCK_DGRAM) ? "udp" : "tcp";

      if (hints == NULL || !(hints->ai_flags & AI_NUMERICSERV))
        /* FIXME: getservbyname_r 사용. */
        se = getservbyname (servname, proto);

      if (se)
        port = ntohs (se->s_port);
      else
        {
          char *endptr;
          long p = strtol (servname, &endptr, 10);
          if (endptr != servname && *endptr == '\0')
            {
              if (p < 0 || p > 65535)
                return EAI_SERVICE;
              port = (int) p;
            }
          else
            return EAI_SERVICE;
        }
    }

  /* tmp 주소 할당.  */
  tmp = (struct addrinfo *) calloc (1, sizeof (struct addrinfo));
  if (!tmp)
    return EAI_MEMORY;

  /* 부모 주소 설정.  */
  if (hints)
    memcpy (tmp, hints, sizeof (struct addrinfo));

  /* 주소 패밀리 및 소켓 타입 설정.  */
  if (hints)
    {
      tmp->ai_family = hints->ai_family;
      tmp->ai_socktype = hints->ai_socktype;
    }
  else
    {
      tmp->ai_family = PF_UNSPEC;
      tmp->ai_socktype = SOCK_STREAM;
    }

  /* 주소 집합 설정.  */
  tmp->ai_addr = (struct sockaddr *) &storage;
  if (tmp->ai_family == AF_INET)
    {
      size = sizeof (struct sockaddr_in);
      storage = calloc (1, sizeof (struct sockaddr_in));
      if (!storage)
        return EAI_MEMORY;

      struct sockaddr_in *addr = (struct sockaddr_in *) storage;
      addr->sin_family = AF_INET;
      addr->sin_port = htons (port);
      /* nodename을 문자열에서 주소로 변환.  */
      if (!inet_pton (AF_INET, nodename, &addr->sin_addr))
        {
          /* hostent 사용이 필요할 수 있음. */
          he = gethostbyname (nodename);
          if (!he)
            return EAI_NONAME;
          memcpy (&addr->sin_addr, he->h_addr_list[0], sizeof (struct in_addr));
        }
      size = sizeof (struct sockaddr_in);
      tmp->ai_addrlen = size;
    }
# if HAVE_IPV6
  else if (tmp->ai_family == AF_INET6)
    {
      size = sizeof (struct sockaddr_in6);
      storage = calloc (1, sizeof (struct sockaddr_in6));
      if (!storage)
        return EAI_MEMORY;

      struct sockaddr_in6 *addr6 = (struct sockaddr_in6 *) storage;
      addr6->sin6_family = AF_INET6;
      addr6->sin6_port = htons (port);
      if (!inet_pton (AF_INET6, nodename, &addr6->sin6_addr))
        {
          /* hostent 사용이 필요할 수 있음. */
          he = gethostbyname (nodename);
          if (!he)
            return EAI_NONAME;
          memcpy (&addr6->sin6_addr, he->h_addr_list[0], sizeof (struct in6_addr));
        }
      size = sizeof (struct sockaddr_in6);
      tmp->ai_addrlen = size;
    }
# endif
  else
    {
      free (tmp);
      return EAI_FAMILY;
    }

  /* 반환 주소 설정.  */
  tmp->ai_next = NULL;
  *res = tmp;
  return 0;
}

#endif
