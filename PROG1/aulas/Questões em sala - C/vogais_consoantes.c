#include <stdio.h>

int main()
{

    int vogais = 0, consoantes = 0;
    char caractere;

    printf("Entre com uma frase: ");
    caractere = getchar();

    while (caractere != '\n')
    {
        if (65 <= caractere && caractere <= 90)
        {
            caractere += 32;
        }
        if (caractere == 97 || caractere == 101 ||
            caractere == 105 || caractere == 111 || caractere == 117)
        {
            vogais++;
        }
        else if (97 <= caractere && caractere <= 122)
        {
            consoantes++;
        }
        caractere = getchar();
    }

    printf("Número de vogais: %d\nNúmero de consoantes: %d\n", vogais, consoantes);

    return 0;
}