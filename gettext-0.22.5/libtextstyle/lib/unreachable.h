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

// Check if unreachable() is already defined to avoid redefinition
#ifndef unreachable
#define unreachable() abort()  // Define the unreachable macro to call abort()
#endif

#endif /* UNREACHABLE_H */
