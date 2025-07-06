#include <stdio.h>

int main(){
    float comissao, valor_negociado;

    printf("Entre com o valor negociado: ");
    scanf("%f", &valor_negociado);

    if (valor_negociado<2500.0){
        comissao = 30.0 + (valor_negociado * 0.017);
    } else if (valor_negociado >= 2500.0 && valor_negociado < 6250.0){
        comissao = 56.0 + (valor_negociado * 0.0066);
    }else if (valor_negociado >= 6250.0 && valor_negociado < 20000.0){
        comissao = 76.0 + (valor_negociado*0.0034);
    }else if (valor_negociado >= 20000 && valor_negociado < 50000.0){
        comissao = 100.0 + (valor_negociado * 0.0022);
    }else if (valor_negociado >= 50000.0 && valor_negociado < 500000.0){
        comissao = 155.0 + (valor_negociado * 0.0011);
    }else{
        comissao = 255.0 + (valor_negociado * 0.0009);
    }

    if (comissao < 39.0){
        comissao = 39.0;
    }

    printf("Taxa de corretagem: $%.2f\n", comissao); 

    return 0;
}