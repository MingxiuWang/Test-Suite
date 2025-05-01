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
    int *a = NULL;

    UNSAFE_LOAD(a);  // a is NULL — unsafe

    memset(a, 0, 5 * sizeof(int));  // Undefined behavior
    return 0;
}