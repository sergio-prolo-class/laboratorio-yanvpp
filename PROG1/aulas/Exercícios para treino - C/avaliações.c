#include <stdio.h>

int maximo(){
    float x,y;

    if (x>y){
        return x;
    }else{
        return y;
    }
}

int media(){
    float x, y, z;

    return ((x+y+z)/3);
}

int arredonda (){
    float x;

    return (int)(x + 0.5);
}

int main(){

    float x, y;
    float P1, P2, P3, R1, R2, R3;
    float frequencia;

    printf("Entre com P1 e R1: ");
    scanf("%f %f", &P1, &R1);

    printf("Entre com P2 e R2: ");
    scanf("%f %f", &P2, &R2);

    printf("Entre com P3 e R3: ");
    scanf("%f %f", &P3, &R3);



    return 0;
}