#include <stdio.h>
#include <math.h>

float hav(float theta)
{
    float resultado;

    resultado = pow(sin(theta / 2), 2);

    return resultado;
}
float graus2rad(float graus)
{
    float rad;

    rad = (3.1415 * graus) / 180;

    return rad;
}
float distancia_na_terra(float lat1, float lon1, float lat2, float lon2)
{
    float distancia;
    int rTerra;

    rTerra = 6371;

    float coslat1 = cos(lat1);
    float coslat2 = cos(lat2);
    float hav1 = hav(lat2 - lat1);
    float hav2 = hav(lon2 - lon1);

    distancia = 2 * rTerra * asin(sqrt(hav1 + coslat1 * coslat2 * hav2));

    return distancia;
}

int main()
{

    float theta, graus, d;
    int lat1, lon1, lat2, lon2;

    printf("Insira o primeiro ponto (lat lon):\n");
    scanf("%d %d", &lat1, &lon1);
    printf("Insira o segundo ponto (lat lon):\n");
    scanf("%d %d", &lat2, &lon2);

    d = distancia_na_terra(graus2rad(lat1), graus2rad(lon1), graus2rad(lat2), graus2rad(lon2));

    printf("Distância entre os pontos: %.2fkm\n", d);

    return 0;
}