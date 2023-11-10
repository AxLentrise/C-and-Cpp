#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 5
#define MAX_NUMBER 9

int numeros[N][N];
int i, j, soma = 0;

int main(void){
    srand(time(NULL));
    for(i = 0; i < N; i++){
        for(j = 0; j < N; j++){
            numeros[i][j] = rand()%MAX_NUMBER;
        }
    }

    printf("Matriz completa:\n");
    for(i = 0; i < N; i++){
        for(j = 0; j < N; j++){
            printf("[%i] ", numeros[i][j]);
        }
        printf("\n");
    }
    printf("\n\n");
    printf("Diagonal superior:\n");
    for(i = 0; i < N; i++){
        for(j = i+1; j < N; j++){
            printf("[%i] ", numeros[i][j]);
            soma += numeros[i][j];
        }
        printf("\n");
    }

    printf("\nSoma da diagonal superior: %i\n\n\n", soma);
    return 0;
}
