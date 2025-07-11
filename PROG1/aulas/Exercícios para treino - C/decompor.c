#include <stdio.h>

char decompor(float n, int *parte_int, float *parte_fra)
{
    if (n > 0) {
        *parte_int = (int)n;
        *parte_fra = n - *parte_int;
        return '+';
    } else if (n < 0) {
        *parte_int = (int)(-n);
        *parte_fra = -n - *parte_int;
        return '-';
    } else {
        *parte_int = 0;
        *parte_fra = 0;
        return ' ';
    }
}

int main()
{
    int parte_int;
    float n, parte_fra;
    char sinal;

    printf("Entre com um número real: ");
    scanf("%f", &n);

    sinal = decompor(n, &parte_int, &parte_fra);

    printf("Sinal: %c\nParte inteira: %d\nParte fracionária: %.2f\n", sinal, parte_int, parte_fra);

    return 0;
}