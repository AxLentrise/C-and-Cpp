#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STRING_LEN 50

// ---------------------------------------------------------------------------

char nome[2][MAX_STRING_LEN], stringHolder[MAX_STRING_LEN];
int i, j, idade[2];
float media;

// ---------------------------------------------------------------------------

int main(void){
    for(i = 0; i < 2; i++) {
        printf("Digite o nome da %i pessoa: ", i+1);
        fflush(stdin);
        gets(nome[i]); // em linux, gets não é aceito, fgets precisa ser usado, entretanto, fgets adiciona um '\n' no final da string que precisa ser tratado, enquanto o gets não tem esse "problema"        printf("Digite a idade de %s: ", nome[i]);
        scanf("%i", &idade[i]);
        system("clear"); // cls for windows
    }

    media = (idade[0]+idade[1])/2;

    printf("A idade media de %s e %s eh de %.1f", nome[0], nome[1], media);

    return 0;
}