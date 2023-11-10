#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 5
#define MAX_NUMBER 15

int i, j;
int value[N][N];
int contNegativos = 0, negativos[N*N]; // sendo números pseudo-aleatórios, eu não consigo determinar a quantidade de números negativos, mas como é uma matriz quadrada, posso assumir que o valor máximo é equivalente a matriz inteira, então aloco espaço suficiente para tal

int main(void){
    srand(time(NULL));
    for(i = 0; i < N; i++){
        for(j = 0; j < N; j++){
            value[i][j] = (rand()%MAX_NUMBER)-5;
            printf("%3.0i ", value[i][j]);
            if(value[i][j] < 0){
                negativos[contNegativos] = value[i][j];
                contNegativos++;
            }
        }
        printf("\n");
    }
    printf("\n\nDiagonal principal: ");
    for(i = 0; i < N; i++){
        printf("[%i] ", value[i][i]);
    }
    printf("\n\nNumeros negativos registrados: ");
    for(i = 0; i < contNegativos; i++){
        printf("[%i] ", negativos[i]);
    }
    printf("\n\n\n");
    return 0;
}
