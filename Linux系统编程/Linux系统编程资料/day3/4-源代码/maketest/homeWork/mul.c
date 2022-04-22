#include <stdio.h>

int mul(int a, int b)
{
    return a*b;
}

int main(void)
{
    int a = 5; int b = 10;

    printf("%dx%d=%d\n", a, b, mul(a, b));

    return 0;
}

