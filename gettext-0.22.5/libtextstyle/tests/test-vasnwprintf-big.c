/* Test of [v]asnwprintf() with big results.
   Copyright (C) 2024 Free Software Foundation, Inc.

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

/* Written by Bruno Haible <bruno@clisp.org>, 2024.  */

#include <config.h>

#include "vasnwprintf.h"

#include "physmem.h"

/* Get INT_MAX.  */
#include <limits.h>

/* Get PTRDIFF_MAX.  */
#include <stdint.h>

#include <errno.h>
#include <stdio.h>
#include <string.h>
#include <wchar.h>

#if HAVE_SETRLIMIT
# include <sys/types.h>
# include <sys/time.h>
# include <sys/resource.h>
#endif

#include "macros.h"

int
main ()
{
#if PTRDIFF_MAX == INT_MAX
  fputs ("Skipping test: ptrdiff_t is not 64-bits wide\n", stderr);
  return 77;
#else
  bool skipped = false;
  /* Disable core files that would be huge.  */
# if HAVE_SETRLIMIT && defined RLIMIT_CORE
  struct rlimit rl;
  rl.rlim_cur = rl.rlim_max = 0;
  setrlimit (RLIMIT_CORE, &rl);
# endif
  /* The test below needs about 40 GiB of memory:
       $ time /usr/bin/time -f "Max RSS: %M KiB" ./test-vasnwprintf-big
       Max RSS: 41944784 KiB
       real    5m8,508s
       user    4m38,035s
       sys     0m30,456s
     5 GiB for the inputs in the %s tests,
     or 20 GiB for the inputs in the %ls tests,
     and up to 20 GiB for temporary output buffers.  */
  double needed = 40.0 * 1024 * 1024 * 1024;
  double avail = physmem_claimable (1.0);
  printf ("memory needed = %g MiB, available = %g MiB\n",
          needed / 1024 / 1024, avail / 1024 / 1024);
  if (avail >= needed)
    {
      /* Note: The malloc() calls can fail, due to ulimit of RLIMIT_DATA.
         For example, on OpenBSD 7.5, the soft limit is 1.0 GiB or 1.5 GiB,
         and you need "ulimit -d 42991616".  */

      /* Verify that asnwprintf() can return a string of size > 4 GiB.  */
      {
        size_t n1 = 3 * (INT_MAX / 4) + 10;
        size_t n2 = 3 * (INT_MAX / 4) + 20;
        char *s1;
        char *s2;

        s1 = (char *) malloc (n1 + 1);
        if (s1 != NULL)
          {
            memset (s1, 'a', n1);
            s1[n1] = '\0';

            s2 = (char *) malloc (n2 + 1);
            if (s2 != NULL)
              {
                memset (s2, 'b', n2);
                s1[n1] = '\0';

                size_t len;
                wchar_t *s = asnwprintf (NULL, &len, L"x%sy%sz", s1, s2);
                if (s == NULL)
                  {
                    ASSERT (errno == ENOMEM);
                    skipped = true;
                  }
                else
                  {
                    ASSERT (wcslen (s) == len);
                    ASSERT (len == n1 + n2 + 3);
                    size_t i;
                    for (i = 0; i <= len; i++)
                      s[i] = (i == 0 ? 'x' :
                              i <= n1 ? 'a' :
                              i == n1 + 1 ? 'y' :
                              i <= n1 + n2 + 1 ? 'b' :
                              i == n1 + n2 + 2 ? 'z' :
                              '\0');
                    free (s);
                  }
                free (s2);
              }
            free (s1);
          }
      }

      /* Verify that asnwprintf() can take a string of size > 2 GiB, < 4 GiB
         as argument.  */
      {
        size_t n1 = 3 * (size_t) (INT_MAX / 2) + 10;
        char *s1;

        s1 = (char *) malloc (n1 + 1);
        if (s1 != NULL)
          {
            memset (s1, 'a', n1);
            s1[n1] = '\0';

            size_t len;
            wchar_t *s = asnwprintf (NULL, &len, L"x%sy", s1);
            if (s == NULL)
              {
                ASSERT (errno == ENOMEM);
                skipped = true;
              }
            else
              {
                ASSERT (wcslen (s) == len);
                ASSERT (len == n1 + 2);
                size_t i;
                for (i = 0; i <= len; i++)
                  s[i] = (i == 0 ? 'x' :
                          i <= n1 ? 'a' :
                          i == n1 + 1 ? 'y' :
                          '\0');
                free (s);
              }
            free (s1);
          }
      }

      /* Verify that asnwprintf() can take a string of size > 4 GiB
         as argument.  */
      {
        size_t n1 = 5 * (size_t) (INT_MAX / 2) + 10;
        if (n1 > (size_t) INT_MAX)
          {
            char *s1;

            s1 = (char *) malloc (n1 + 1);
            if (s1 != NULL)
              {
                memset (s1, 'a', n1);
                s1[n1] = '\0';

                size_t len;
                wchar_t *s = asnwprintf (NULL, &len, L"x%sy", s1);
                if (s == NULL)
                  {
                    ASSERT (errno == ENOMEM);
                    skipped = true;
                  }
                else
                  {
                    ASSERT (wcslen (s) == len);
                    ASSERT (len == n1 + 2);
                    size_t i;
                    for (i = 0; i <= len; i++)
                      s[i] = (i == 0 ? 'x' :
                              i <= n1 ? 'a' :
                              i == n1 + 1 ? 'y' :
                              '\0');
                    free (s);
                  }
                free (s1);
              }
          }
      }

      /* Verify that asnwprintf() can take a wide string with an element count
         > 2^31, < 2^32 as argument.  */
      {
        size_t n1 = 3 * (size_t) (INT_MAX / 2) + 10;
        wchar_t *s1;

        s1 = (wchar_t *) malloc ((n1 + 1) * sizeof (wchar_t));
        if (s1 != NULL)
          {
            wmemset (s1, L'a', n1);
            s1[n1] = L'\0';

            size_t len;
            wchar_t *s = asnwprintf (NULL, &len, L"x%lsy", s1);
            if (s == NULL)
              {
                ASSERT (errno == ENOMEM);
                skipped = true;
              }
            else
              {
                ASSERT (wcslen (s) == len);
                ASSERT (len == n1 + 2);
                size_t i;
                for (i = 0; i <= len; i++)
                  s[i] = (i == 0 ? 'x' :
                          i <= n1 ? 'a' :
                          i == n1 + 1 ? 'y' :
                          '\0');
                free (s);
              }
            free (s1);
          }
      }

      /* Verify that asnwprintf() can take a wide string with an element count
         > 2^32 as argument.  */
      {
        size_t n1 = 5 * (size_t) (INT_MAX / 2) + 10;
        if (n1 > (size_t) INT_MAX)
          {
            wchar_t *s1;

            s1 = (wchar_t *) malloc ((n1 + 1) * sizeof (wchar_t));
            if (s1 != NULL)
              {
                wmemset (s1, L'a', n1);
                s1[n1] = L'\0';

                size_t len;
                wchar_t *s = asnwprintf (NULL, &len, L"x%lsy", s1);
                if (s == NULL)
                  {
                    ASSERT (errno == ENOMEM);
                    skipped = true;
                  }
                else
                  {
                    ASSERT (wcslen (s) == len);
                    ASSERT (len == n1 + 2);
                    size_t i;
                    for (i = 0; i <= len; i++)
                      s[i] = (i == 0 ? 'x' :
                              i <= n1 ? 'a' :
                              i == n1 + 1 ? 'y' :
                              '\0');
                    free (s);
                  }
                free (s1);
              }
          }
      }
    }
  else
    skipped = true;

  if (test_exit_status != EXIT_SUCCESS)
    return test_exit_status;
  if (skipped)
    {
      fputs ("Skipping test: not enough memory available\n", stderr);
      return 77;
    }
  return 0;
#endif
}
