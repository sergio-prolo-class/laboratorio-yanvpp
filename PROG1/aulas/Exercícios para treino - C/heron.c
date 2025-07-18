#include <stdio.h>

double modulo(float x)
{
}

int main()
{
    float x;

    printf("Entre com a aproximação inicial: ");
    scanf("%1f", &x);

    while (((x / 2) + (1 / x)) > 1) {
        printf("");
    }

    return 0;
}