// Copyright (c) 2013 Peking University.
// Author: Xiaosong Rong (rongxiaosong@gmail.com)

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// typedef unsigned int size_t;
#define MAX_SIZE 500
#define swap(p, q, size) { \
    char *t; \
    t = malloc(size); \
    memcpy(t, p, size); \
    memcpy(p, q, size); \
    memcpy(q, t, size); \
    free(t); \
}

/*
void swap(const void *p, const void *q, size_t size)
{
    char *t;
    t = malloc(size);
    memcpy(t, p, size);
    memcpy((char *)p, q, size);
    memcpy((char *)q, t, size);
    free(t);
}
*/

void _qsort(void *base, size_t n, size_t size, int (*cmp)(const void *, const void *))
{
    char *p, *q, *hi, *lo;
    size_t i;
    if (n < 2)
        return ;
    if (n == 2) {
        p = (char *)base + size;
        if ((*cmp)(base, p) > 0)
            swap(base, p, size)
        return ;
    }
    lo = (char *)base;
    hi = (char *)base + size * (n - 1);
    p = lo + size;
    q = hi;
    while (1) {
        for (; p <= hi && (*cmp)(p, lo) < 0; p += size) ;
        for (; q > lo && (*cmp)(q, lo) > 0; q -= size) ;
        if (p < q)
            swap(p, q, size)
        else {
            if (q != lo)
                swap(lo, q, size)
            break;
        }
    }
    _qsort(lo, (q - lo) / size, size, cmp);
    _qsort(q + size, (hi - q) / size, size, cmp);
    return ;
}

int intcmp(const int *x, const int *y)
{
    return *x - *y;
}

#define STR_LEN 20
main()
{
    int i, n;
    // char base[MAX_SIZE][STR_LEN];
    int nums[MAX_SIZE];
    // for (i = 0; i < MAX_SIZE && scanf("%s", base[i]) != EOF; i++) ;
    for (i = 0; i < MAX_SIZE && scanf("%d", &nums[i]) != EOF; i++) ;
    n = i;
    for (i = 0; i < n; i++)
        printf("%d ", nums[i]);
    putchar('\n');

    // my _qsort function
    // _qsort(base, n, STR_LEN, (int (*)(const void *, const void *))strcmp);
    _qsort(nums, n, sizeof(int), (int (*)(const void *, const void *))intcmp);

    for (i = 0; i < n; i++)
        printf("%d ", nums[i]);
    putchar('\n');
}
