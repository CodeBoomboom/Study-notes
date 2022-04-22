#include "head.h"

int main(int argc, char *argv[])
{
    int a = 10; int b = 5;

    printf("%d+%d=%d\n", a, b, add(a, b));
    printf("%d-%d=%d\n", a, b, sub(a, b));
    printf("%d/%d=%d\n", a, b, div1(a, b));
    printf("%dx%d=%d\n", a, b, mul(a, b));

	return 0;
}
