/* unreachable.h */
#ifndef UNREACHABLE_H
#define UNREACHABLE_H

#if defined(__cplusplus)
extern "C" {
#endif

#include <stdlib.h>  // For abort()

_Noreturn void abort(void);  // Ensure abort() is declared

#if defined(__cplusplus)
}
#endif

#define unreachable() abort()  // Define the unreachable macro to call abort()

#endif /* UNREACHABLE_H */
