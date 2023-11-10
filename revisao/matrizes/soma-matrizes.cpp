#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 5
#define MAX_NUMBER 9

int matriz1[N][N], matriz2[N][N], somaMatriz[N][N];
int i, j;

int main(void){
    srand(time(NULL));
    for(i = 0; i < N; i++){
        for(j = 0; j < N; j++){
            matriz1[i][j] = rand()%MAX_NUMBER;
            matriz2[i][j] = rand()%MAX_NUMBER;
            somaMatriz[i][j] = matriz1[i][j]+matriz2[i][j];
        }
    }

    printf("Soma das matrizes:\n");
    for(i = 0; i < N; i++){
        printf("Linha %i: ", i);
        for(j = 0; j < N; j++){
            printf("[%i] ", somaMatriz[i][j]);
        }
        printf("\n");
    }
    return 0;
}
