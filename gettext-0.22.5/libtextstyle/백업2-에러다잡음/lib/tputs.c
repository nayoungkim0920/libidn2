#include "config.h"
/* Output of string from terminal descriptions.
   Copyright (C) 2006-2024 Free Software Foundation, Inc.

   This file is free software: you can redistribute it and/or modify
   it under the terms of the GNU Lesser General Public License as
   published by the Free Software Foundation, either version 3 of the
   License, or (at your option) any later version.

   This file is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

#include <config.h>

/* Specification in termcap.h or terminfo.h.  */
extern
#ifdef __cplusplus
"C"
#endif
void tputs (const char *cp, int affcnt, int (*outcharfun) (int));

#include "c-ctype.h"

void
tputs (const char *cp, int affcnt, int (*outcharfun) (int))
{
  while (c_isdigit (*cp))
    cp++;
  if (*cp == '.')
    {
      cp++;
      while (c_isdigit (*cp))
        cp++;
    }
  for (; *cp != '\0'; cp++)
    outcharfun (*cp);
}
