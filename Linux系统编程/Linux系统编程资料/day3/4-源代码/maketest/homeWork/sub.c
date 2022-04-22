#include <stdio.h>

int sub(int a, int b)
{
    return a-b;
}

int main(void)
{
    int a = 5; int b = 10;

    printf("%d-%d=%d\n", a, b, sub(a, b));

    return 0;
}

