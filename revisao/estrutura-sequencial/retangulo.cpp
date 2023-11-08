#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// --------------------------------------------------------

float base, altura, area, perimetro, diagonal;

// --------------------------------------------------------

int main(void){
    printf("Digite a base do retangulo: ");
    fflush(stdin);
    scanf("%f", &base);
    printf("Digite a altura do retangulo: ");
    fflush(stdin);
    scanf("%f", &altura);
    printf("\n");

    area = base*altura;
    perimetro = (2*base)+(2*altura);
    diagonal = sqrt(pow(base, 2)+pow(altura, 2));

    printf("Area: %.4f\n", area);
    printf("Perimetro: %.4f\n", perimetro);
    printf("Diagonal: %.4f\n\n\n", diagonal);

    return 0;
}