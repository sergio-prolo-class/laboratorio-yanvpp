#include <stdio.h>

int main(){
    int n1; // primeira parte
    int n2, n3, n4, n5, n6, n7; // segunda parte
    int n8, n9, n10, n11, n12; // terceira parte
    int verificador; // dígito verificador

    printf("Entre com a primeira parte (1 dígito): ");
    scanf("%d", &n1);

    printf("Entre com a segunda parte (6 dígitos): ");
    scanf("%1d%1d%1d%1d%1d%1d", &n2, &n3, &n4, &n5, &n6, &n7);

    printf("Entre com a terceira parte, sem o dígito verificador (5 dígitos): ");
    scanf("%1d%1d%1d%1d%1d", &n8, &n9, &n10, &n11, &n12);

    verificador = (3*(n2+n4+n6+n8+n10+n12)+(n1+n5+n7+n9+n11)-1)%10;

    verificador = 9 - verificador;

    printf("Dígito verificador: %d\n", verificador);

    return 0;
}