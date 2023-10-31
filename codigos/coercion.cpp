#include <stdio.h>            // Biblioteca de entrada e saída;
#include <string.h>           // Biblioteca de manipulação de strings; para usar fgets e strlen;
#include <ctype.h>            // Biblioteca de manipulação de tipos; usando para a função isdigit;
#include <stdlib.h>           // Biblioteca de funções padrão; usando para função system();
#include <math.h>             // Biblioteca de matemática; usando para fazer potenciação;
//#include <conio.h>          // Windows only;
#define MAX 256               // Constante de tamanho máximo de entrada;
#define CONST 48              // Constante de Conversão -- Seguindo a fórmula de '0' = 48; logo, para obter '0' = 0, é necessário fazer a operação '0' = ('0'- CONST);
char stringToInt[MAX];        // Variável que será usada para receber os dados da userImput, após serem tratados;

double coercion(int len){     // Função que pega os números digitados em char, e converte para double - Usar inteiro não funcionava devido ao tamanho máximo;
    double converted_numbers = 0;
    int i,  coercion_tax;
    coercion_tax = len;       // coercion_tax = Representa o nível de potência dos números a serem convertidos, uma vez que o índice [0] representa o maior número;
    for(i = 0; i < len; i++){
        coercion_tax--;       // Taxa de decaimento da potência;
        converted_numbers += ((int)stringToInt[i]-CONST)*pow(10, coercion_tax); // converte o char do número e aplica a constante, depois, aplica a potência do número;
    }
    return converted_numbers; // Retorna o número convertido para uma variável na Função principal;
}

int main(void){
    char userImput[MAX];      // Variável para obter a string tratada, que depois será copiada em outra variável para controle fino;
    int i, check, len;
    double numbers;
    while(1){
        printf("Digite apenas numeros inteiros: ");
        fflush(stdin);
        fgets(userImput, MAX, stdin);
        len = strlen(userImput);

        for(i = 0; i < len; i++){
            if(isdigit(userImput[i]) || userImput[i] == '\n'){
                check = 1;
                continue;
            }else{
                check = 0;
                break;
            }
        }

        if(check == 1){
            system("clear"); // "cls" for windows;
            break;
        }else{
            system("clear"); // "cls" for windows;
            printf("Voce digitou um caractere invalido;  ");
            continue;
        }        
    }
    
    for(i = 0; i < len - 1; i++){
        stringToInt[i] = userImput[i];
    }

    numbers = coercion(len - 1);
    printf("Numero digitado: %.0f\n\n", numbers);
    //getch(); // Windowns only; conio.h header
    return 0;
}
