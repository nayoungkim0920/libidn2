/*netdb->winsock2 수정*/
#ifdef _WIN32
#include <winsock2.h>
#include <ws2tcpip.h>
#else
#include <netdb.h>
#endif

#include <stdio.h>
#include <string.h>
#include <errno.h>

#include "sockets.h"

static int simple (char const *host, char const *service)
{
  char buf[BUFSIZ];
  struct addrinfo hints;
  struct addrinfo *ai0, *ai;
  int res;

  memset (&hints, 0, sizeof (hints));
  hints.ai_flags = AI_CANONNAME;
  hints.ai_family = AF_UNSPEC;
  hints.ai_socktype = SOCK_STREAM;

  res = getaddrinfo (host, service, &hints, &ai0);
  
  if (res != 0) {
      fprintf(stderr, "getaddrinfo error: %s\n", gai_strerror(res));
      return 1;
  }

  for (ai = ai0; ai; ai = ai->ai_next) {
      struct sockaddr_in *sock_addr = (struct sockaddr_in *)ai->ai_addr;
      inet_ntop(ai->ai_family, &sock_addr->sin_addr, buf, sizeof(buf));
      printf("Found IP: %s\n", buf);
      if (ai->ai_canonname) {
          printf("Canonical Name: %s\n", ai->ai_canonname);
      }
  }

  freeaddrinfo(ai0);
  return 0;
}

#define HOST1 "www.gnu.org"
#define SERV1 "http"

int main(void) {
  return simple(HOST1, SERV1);
}
