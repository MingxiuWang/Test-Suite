#include <stdio.h>
#include <string.h>
#include <stdlib.h>

extern void SAFE_LOAD(void *ptr);
extern void UNSAFE_LOAD(void *ptr);

int main() {
    int *a = (int *)malloc(5 * sizeof(int));
    int *b = (int *)malloc(5 * sizeof(int));
    if (a && b) {
        for (int i = 0; i < 5; ++i) {
            b[i] = i;
        }

        SAFE_LOAD(a);
        SAFE_LOAD(b);

        memcpy(a, b, 5 * sizeof(int));  // Safe copy of 5 integers
    }
    free(a);
    free(b);
    return 0;
}
