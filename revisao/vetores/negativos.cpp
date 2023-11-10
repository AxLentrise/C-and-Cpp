#include <stdio.h>
#include <stdlib.h>

int i, N, number[10];

int main(void){
    printf("Digite quantos numeros deseja registrar: ");
    fflush(stdin);
    scanf("%i", &N);
    for(i = 0; i < N; i++){
        printf("Digite o %i numero: ", i+1);
        fflush(stdin);
        scanf("%i", &number[i]);
        system("clear"); // cls for windows
    }

    printf("Numeros negativos registrados: ");
    for(i = 0; i < N; i++){
        if(number[i] < 0){
            printf("[%i], ", number[i]);
        }
    }
    return 0;
}

