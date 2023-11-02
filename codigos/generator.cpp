#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#define LEN 11
#define CONST 48
#define MAX_NUMBER 9

/*---------------------------------------------------------------------------------------*/

char entradaNaoTratada[LEN];
char entradaTratada[LEN];
int intCode, i, j = 0;
int numerosAleatorios[LEN], cpfCompleto[10][LEN];

/*---------------------------------------------------------------------------------------*/

float generator(int nothing){
    srand(time(NULL));
    while(j != 10){
        int multiplier = 10, sumRand = 0, modSum = 0;
        for(i = 0; i < 9; i++){
            numerosAleatorios[i] = ((rand()%MAX_NUMBER)+(rand()%MAX_NUMBER)+(rand()%MAX_NUMBER))/3;
        }
        for(i = 0; i < 9; i++){
            sumRand += numerosAleatorios[i]*multiplier;
            multiplier--;
        }
        modSum = sumRand%11;
        if(modSum <= 1){
            continue;
        }
        numerosAleatorios[9] = 11 - modSum;
        sumRand = 0;
        multiplier = 11;
        for(i = 0; i < 10; i++){
            sumRand += numerosAleatorios[i]*multiplier;
            multiplier--;
        }
        modSum = sumRand%11;
        if(modSum <= 1){
            continue;
        }
        numerosAleatorios[10] = 11 - modSum;
        for(i = 0; i < 11; i++){
            cpfCompleto[j][i] = numerosAleatorios[i];
        }
        j++;
    }
    return 0;
}

int main(void){
    while(1){
        printf("Choose one operation:\n\n[1] - To generate 10 CPFs;\n[2] - To verify one CPF;\n[3] - To end the application.\n\n");
        printf("Answer: ");
        fflush(stdin);
        fgets(entradaNaoTratada, LEN, stdin);
        if(strlen(entradaNaoTratada) > 2){
            system("clear"); // cls for windows
            continue;
        }
        if(isdigit(entradaNaoTratada[0])){
            intCode = ((int)entradaNaoTratada[0]-CONST);            
        }else{
            system("clear"); // cls for windows
            continue;
        }
        if(intCode != 1 && intCode != 2 && intCode != 3){
            system("clear"); // cls for windows
            continue;
        }

        system("clear"); // cls for winsdows

        switch(intCode){
            case 1:{
                generator(1);
                for(j = 0; j < 10; j++){
                    printf("CPF: ");
                    for(i = 0; i < LEN; i++){
                        printf("%i", cpfCompleto[j][i]);
                    }
                    printf("\n");
                }
            }; break;
            case 2:{}; break;
            case 3: break; break;
        }






    }

    
    return 0;
}

