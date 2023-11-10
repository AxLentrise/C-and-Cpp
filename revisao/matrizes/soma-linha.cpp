#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 5
#define MAX_NUMBER 9

int numeros[N][N];
int i, j, soma[N];

int main(void){
    srand(time(NULL));
    for(i = 0; i < N; i++){
        soma[i] = 0;
        for(j = 0; j < N; j++){
            numeros[i][j] = rand()%MAX_NUMBER;
            soma[i] += numeros[i][j];
        }
    }

    for(i = 0; i < N; i++){
        printf("Numeros na linha: ");
        for(j = 0; j < N; j++){
            printf("[%i]", numeros[i][j]);
        }
        printf(" | Soma dos numeros: %i\n", soma[i]);
    }

    return 0;
}
