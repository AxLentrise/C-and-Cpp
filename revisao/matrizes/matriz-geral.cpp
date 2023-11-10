#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define N 5
#define MAX_NUMBER 100

int i, j;
int num[N][N];
int soma = 0, imput;

int main(void){
    srand(time(NULL));
    printf("Matriz gerada: \n\n");
    for(i = 0; i < N; i++){
        for(j = 0; j < N; j++){
            num[i][j] = (rand()%MAX_NUMBER)-(rand()%MAX_NUMBER);
            printf("[%3.i] ", num[i][j]);
        }
        printf("\n\n");
    }

    /*------------- Calcular e exibir a soma de todos os numeros positivos -------------*/
    printf("Soma de todos os positivos: 0");
    for(i = 0; i < N; i++){
        for(j = 0; j < N; j++){
            if(num[i][j] > 0){
                printf("+%i", num[i][j]);
                soma += num[i][j];
            }
        }
    }
    printf(" | Soma: %i\n\n", soma);

    /*------------- Exibir uma linha específica da matriz --------------------*/
    printf("Digite qual linha deseja exibir: ");
    fflush(stdin);
    scanf("%i", &imput);
    printf("Linha %i: ", imput);
    for(i = 0; i < N; i++){
        printf("[%i] ", num[imput-1][i]);
    }
    printf("\n\n");

    /*------------- Exibir uma coluna específica da matriz --------------------*/
    printf("Digite qual coluna deseja exibir: ");
    fflush(stdin);
    scanf("%i", &imput);
    printf("Coluna %i: ", imput);
    for(i = 0; i < N; i++){
        printf("[%i] ", num[i][imput-1]);
    }
    printf("\n\n");

    /*------------- Todos os elementos da diagonal principal --------------------*/
    printf("Todos os elementos da diagonal principal: ");
    for(i = 0; i < N; i++){
        printf("[%i] ", num[i][i]);
    }
    printf("\n\n");

    /*------------- Elevar ao quadrado todos os numeros negativos da matriz e modifica-la --------------------*/
    printf("Elevando todos os numeros negativos ao quadrado:\n\n");
    for(i = 0; i < N; i++){
        for(j = 0; j < N; j++){
            if(num[i][j] < 0){
                num[i][j] = pow(num[i][j], 2);
            }
            printf("[%4.i] ", num[i][j]);
        }
        printf("\n\n");
    }

    printf("\n\n\n");
    return 0;
}
