//
// Created by 12425 on 2025/5/1.
//
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

extern void SAFE_LOAD(void *ptr);
extern void UNSAFE_LOAD(void *ptr);

int main()
{
    char *a = NULL;
    char *b = (char *)malloc(20);
    if (b) {
        strcpy(b, "Hello");

        // Unsafe usage
        UNSAFE_LOAD(a);  // a is NULL — unsafe
        SAFE_LOAD(b);  // b is valid

        strcpy(a, b);  // Undefined behavior (null dereference)
    }
    free(b);
    return 0;
}