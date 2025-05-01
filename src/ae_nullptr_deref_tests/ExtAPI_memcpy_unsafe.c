//
// Created by 12425 on 2025/5/1.
//
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
extern void SAFE_LOAD(void *ptr);
extern void UNSAFE_LOAD(void *ptr);

int main() {
    int *a = NULL;
    int *b = (int *)malloc(5 * sizeof(int));
    if (b) {
        for (int i = 0; i < 5; ++i) {
            b[i] = i;
        }
        // Unsafe usage
        UNSAFE_LOAD(a);  // a is NULL — unsafe
        SAFE_LOAD(b);  // b is valid

        memcpy(a, b, 5 * sizeof(int));  // Undefined behavior (null dereference)
    }
    free(b);
    return 0;
}