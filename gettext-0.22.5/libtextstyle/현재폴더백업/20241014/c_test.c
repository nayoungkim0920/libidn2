#include <stdio.h>

int main(void) {
    printf("Current C standard version: %ld\n", __STDC_VERSION__);

    #if __STDC_VERSION__ >= 202300L
        printf("C23 is supported!\n");
    #elif __STDC_VERSION__ >= 202000L
        printf("C2x is supported (this may become C23).\n");
    #elif __STDC_VERSION__ >= 201112L
        printf("C11 is supported.\n");
    #elif __STDC_VERSION__ >= 199901L
        printf("C99 is supported.\n");
    #elif __STDC_VERSION__ >= 199409L
        printf("C94 is supported.\n");
    #elif __STDC_VERSION__ >= 198900L
        printf("C89 is supported.\n");
    #else
        printf("Older C standard is in use.\n");
    #endif

    return 0;
}
