#include <stdio.h>

int main()
{
    char caractere = ' ';
    int vogais = 0, consoantes = 0;

    printf("Entre com uma frase: ");

    for (int i = 0; caractere != '\n'; i++) {
        scanf("%c", &caractere);

        if (caractere >= 65 && caractere <= 90) {
            caractere += 32;
        }

        if (caractere >= 97 && caractere <= 122) {
            if (caractere == 'a' || caractere == 'e' || caractere == 'i' || caractere == 'o' || caractere == 'u') {
                vogais++;
            } else {
                consoantes++;
            }
        }
    }

    printf("Número de vogais: %d\nNúmero de consoantes: %d\n", vogais, consoantes);

    return 0;
}