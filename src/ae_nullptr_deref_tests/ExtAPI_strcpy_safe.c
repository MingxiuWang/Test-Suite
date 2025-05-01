#include <stdio.h>
#include <string.h>
#include <stdlib.h>

extern void SAFE_LOAD(void *ptr);
extern void UNSAFE_LOAD(void *ptr);



int main() {
    char *a = (char *)malloc(20);
    char *b = (char *)malloc(20);
    if (a && b) {
        strcpy(b, "Hello");

        // Safe usage
        SAFE_LOAD(a);
        SAFE_LOAD(b);

        strcpy(a, b);  // Copy b into a
    }
    free(a);
    free(b);
    return 0;
}
