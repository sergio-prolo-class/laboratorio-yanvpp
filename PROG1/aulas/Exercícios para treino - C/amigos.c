#include <stdio.h>
#include <stdbool.h>

int soma_divisores(int n){

    int soma = 0;

    for(int i = 1; i < n; i++){
        if (n % i == 0){
            soma += i;
        }
    }
    
    return soma;
}

bool sao_amigos(int a, int b){
    
    return (soma_divisores(a) == b) && (soma_divisores(b) == a);
}

int main(){

    int n1, n2;
    bool x;

    printf("Entre com dois inteiros positivos: ");
    scanf("%d %d", &n1, &n2);

    x = sao_amigos(n1, n2);

    //quando booleando, "v" = "v == true" // "!v" = "v == false"
    if (x){ 
        printf("Os números %d e %d são amigos\n", n1, n2);
    } else {
        printf("Os números %d e %d não são amigos\n", n1, n2);
    }

    return 0;
}