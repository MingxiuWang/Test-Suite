#include <stdio.h>
#include <string.h>
#include <stdlib.h>

extern void SAFE_LOAD(void *ptr);
extern void UNSAFE_LOAD(void *ptr);


int main() {
    char *a = (char *)malloc(20);
    char *b = (char *)malloc(20);
    if (a && b) {
        strcpy(a, "Hello");
        strcpy(b, " World");

        // Safe usage
        SAFE_LOAD(a);  // Access before strcat
        SAFE_LOAD(b);

        strcat(a, b);  // Concatenate strings
    }
    free(a);
    free(b);
    return 0;
}
