#include <stdio.h>

/*---------------------------*/

float x, y;

/*---------------------------*/

int main(void){
    printf("Digite o valor de X: ");
    fflush(stdin);
    scanf("%f", &x);
    printf("Digite o valor de Y: ");
    fflush(stdin);
    scanf("%f", &y);

    if((x > 0) && (y > 0)){
        printf("\nQ1\n\n");
    }
    if((x < 0) && (y > 0)){
        printf("\nQ2\n\n");
    }
    if((x < 0) && (y < 0)){
        printf("\nQ3\n\n");
    }
    if((x > 0) && (y < 0)){
        printf("\nQ4\n\n");
    }
    return 0;
}

