#include <stdio.h>

int main(){

    int n1, n2;
    char extenso1[10], extenso2[10];

    printf("Entre com um inteiro de 1 a 99: ");
    scanf("%1d%1d", &n1, &n2);

    if (n2 != 0){
        switch (n2){
            case 1: extenso2 == "Um";
            break;
            case 2: extenso2 == "Dois";
            break;
            case 3: extenso2 == "Três";
            break;
            case 4: extenso2 == "Quatro";
            break;
            case 5: extenso2 == "Cinco";
            break;
            case 6: extenso2 == "Seis";
            break;
            case 7: extenso2 == "Sete";
            break;
            case 8: extenso2 == "Oito";
            break;
            case 9: extenso2 == "Nove";
            break;
        }
    } else {
        extenso2 == "";
    }

    if (n1 < 1){
        extenso1 == "";
    }else{
        switch (n1){
            case 2: extenso1 == "Vinte";
            break;
            case 3: extenso1 == "Trinta";
            break;
            case 4: extenso1 == "Quarenta";
            break;
            case 5: extenso1 == "Cinquenta";
            break;
            case 6: extenso1 == "Sessenta";
            break;
            case 7: extenso1 == "Setenta";
            break;
            case 8: extenso1 == "Oitenta";
            break;
            case 9: extenso1 == "Noventa";
            break;
        }
    }

    if(n1 > 1 && n2 != 0){
    printf("Número por extenso: \"%c e %c\"", n1, n2); 
    }

    if (n1 == 1){
        if (n2 == 0){
            extenso1 == "Dez";
        }
        if (n2 == 1){
            extenso1 == "Onze";
        }
        if (n2 == 2){
            extenso1 == "Doze";
        }
        if (n2 == 3){
            extenso1 == "Treze";
        }
        if (n2 == 4){
            extenso1 == "Quatorze";
        }
        if (n2 == 5){
            extenso1 == "Quinze";
        }
        if (n2 == 6){
            extenso1 == "Dezesseis";
        }
        if (n2 == 7){
            extenso1 == "Dezessete";
        }
        if (n2 == 8){
            extenso1 == "Dezoito";
        }
        if (n2 == 9){
            extenso1 == "Dezenove";
        }
        printf("Número por extenso: \"%c\"\n", n1);
    }

    if (n1 > 1 && n2 == 0){
        printf("Número por extenso: \"%c\"\n", n1);
    }        

    return 0;
}