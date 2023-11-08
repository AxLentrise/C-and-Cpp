#include <stdio.h>
#include <math.h>

//-------------------------------------------------------------------------------------------------

float a, b, c, delta;
float x1, x2;

//-------------------------------------------------------------------------------------------------

int main(void){
    printf("Variavel A: ");
    fflush(stdin);
    scanf("%f", &a);
    printf("Variavel B: ");
    fflush(stdin);
    scanf("%f", &b);
    printf("Variavel C: ");
    fflush(stdin);
    scanf("%f", &c);

    if(a == 0){
        printf("\n\nA = 0 <---------\nEncerrado devido a divisão por 0.");
        return 0;
    }

    delta = pow(b, 2)-(4*a*c);
    if(delta < 0){
        printf("\n\nDelta negativo <---------\nEssa expressão são tem raízes.");
        return 0;
    }

    x1 = ((-1*b)+sqrt(delta))/(2*a);
    x2 = ((-1*b)-sqrt(delta))/(2*a);

    printf("\n\nX1 = %.4f\n", x1);
    printf("X2 = %.4f\n", x2);

    return 0;
}