#include "xstrdup.h"
#include <stdlib.h>  // for malloc, free
#include <string.h>  // for strlen, strcpy

// Function implementation for xstrdup
char *xstrdup(const char *s) {
    if (s == NULL) {
        return NULL;  // Handle NULL pointer input
    }

    // Allocate memory for the duplicated string
    char *dup = (char *)malloc(strlen(s) + 1);
    if (dup == NULL) {
        return NULL;  // Memory allocation failed
    }

    // Copy the string into the allocated memory
    strcpy(dup, s);
    return dup;
}
