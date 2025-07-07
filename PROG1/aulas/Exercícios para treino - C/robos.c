#include <stdio.h>
#include <math.h>

typedef struct {
    float x, y;
} Ponto;

void mover_ponto(Ponto *p, char direcao, float distancia)
{
    switch (direcao) {
        case 'N':
            p->y += distancia;
            break;
        case 'S':
            p->y -= distancia;
            break;
        case 'L':
            p->x += distancia;
            break;
        case 'O':
            p->x -= distancia;
            break;
        default:
            printf("ERRO: Direção inválida.");
            break;
    }
}

float calcular_distancia(Ponto p1, Ponto p2)
{
    return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}

int main()
{
    Ponto robo1 = {0, 0};
    Ponto robo2 = {10, 10};
    char direcao;
    float distancia;

    printf("Entre com os movimentos do robô 1: ");

    for (int i = 3; i > 0; i--) {
        scanf(" %c %f", &direcao, &distancia);
        mover_ponto(&robo1, direcao, distancia);
    }

    printf("Entre com os movimentos do robô 2: ");

    for (int i = 3; i > 0; i--) {
        scanf(" %c %f", &direcao, &distancia);
        mover_ponto(&robo2, direcao, distancia);
    }

    printf("Posição final robô 1: (%f; %f)\n", robo1.x, robo1.y);
    printf("Posição final robô 2: (%f; %f)\n", robo2.x, robo2.y);

    printf("Distância final entre os robôs: %.2f\n", calcular_distancia(robo1, robo2));

    return 0;
}