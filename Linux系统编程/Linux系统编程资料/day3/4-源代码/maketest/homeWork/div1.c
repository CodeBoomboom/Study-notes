#include <stdio.h>

int div1(int a, int b)
{
    return a/b/2;
}

int main(void)
{
    int a = 5; int b = 10;

    printf("%d+%d=%d\n", a, b, div1(a, b));

    return 0;
}

