#include <stdio.h>

int main()
{
    int x;
    int y;
    int *p;

    x = 42;
    y = -5;
    p = &x;

    printf("%p %d\n", &x, x);
    printf("%p %d\n", &y, y);
    printf("%p %d\n", &p, p);

    printf("%d\n", *p);
    x = 100;
    printf("%d\n", x);
    printf("%d\n", *p);

    *p = 200;
    printf("%d\n", x);
    printf("%d\n", *p);

    p = &y;
    y = 10 * *p;  // What!?
    printf("%d\n", *p);
    printf("%d\n", y);
    printf("%d\n", x);

    return 0;
}