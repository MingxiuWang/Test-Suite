#include <stdio.h>
#include <string.h>
#include <stdlib.h>

extern void SAFE_LOAD(void *ptr);
extern void UNSAFE_LOAD(void *ptr);



int main() {
    int *a = (int *)malloc(5 * sizeof(int));
    if (a) {
        SAFE_LOAD(a);
        memset(a, 0, 5 * sizeof(int));  // Safe memset of 5 integers
    }
    free(a);
    return 0;
}
