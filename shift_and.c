// Copyright (c) 2013 Peking University.
// Author: Xiaosong Rong (rongxiaosong@gmail.com)

#include <stdio.h>
#include <string.h>
#define MAXSIZE 200

void pre(const char *t, long B[])
{
    int i, c;
    for (i = 0; (c = t[i]) != '\0'; i++) {
        B[c] |= (1 << i);
    }
}

int shift_and_match(const char *s, const char *t, int res[])
{
    int i, c, k, m;
    long B[256] = {0}, D = 0;
    long mask;
    m = strlen(t);
    mask = 1 << (strlen(t) - 1);
    pre(t, B);
    for (i = 0, k = 0; (c = s[i]) != '\0'; i++) {
        D = ((D << 1) | 1) & B[c];
        if (D & mask)
            res[k++] = i - m + 1;
    }
    return k;
}

main()
{
    char s[MAXSIZE], t[MAXSIZE];
    int res[MAXSIZE], i, n;
    scanf("%s%s", s, t);
    n = shift_and_match(s, t, res);
    printf("Find %d positions:\n", n);
    for (i = 0; i < n; i++)
        printf("%d\n", res[i]);
}
