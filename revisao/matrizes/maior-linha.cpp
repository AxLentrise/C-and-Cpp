#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 5
#define MAX_NUMBER 9

int num[N][N];
int i, j, maior[N];

int main(void){
    srand(time(NULL));
    for(i = 0; i < N; i++){
        maior[i] = 0;
        for(j = 0; j < N; j++){
            num[i][j] = rand()%MAX_NUMBER;
            if(num[i][j] > maior[i]){
                maior[i] = num[i][j];
            }
        }
    }

    for(i = 0; i < N; i++){
        printf("Numeros da linha: ");
        for(j = 0; j < N; j++){
            printf("[%i] ", num[i][j]);
        }
        printf("| Maior desses numeros: [%i]\n", maior[i]);
    }

    return 0;
}
