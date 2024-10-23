#include <stdlib.h>
int main(void) {
    void* ptr = aligned_alloc(16, 16);
    free(ptr);
    return 0;
}
