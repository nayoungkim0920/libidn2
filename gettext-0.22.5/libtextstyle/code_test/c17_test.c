#include <stdlib.h>
#include <stdio.h>

int main(void) {
    void *ptr = aligned_alloc(16, 16); // C17에서 추가된 함수
    if (ptr == NULL) {
        perror("Memory allocation failed");
        return 1;
    }

    printf("Allocated memory at: %p\n", ptr);

    free(ptr);
    return 0;
}
