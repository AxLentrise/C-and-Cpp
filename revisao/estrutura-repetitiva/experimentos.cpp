#include <stdio.h>
#include <stdlib.h>

/*Problema "experiencias" (adaptado de URI 1094)
Maria acabou de iniciar seu curso de graduação na faculdade de medicina e precisa de sua ajuda para 
organizar os experimentos de um laboratório o qual ela é responsável. Ela quer saber no final do ano, 
quantas cobaias foram utilizadas no laboratório e o percentual de cada tipo de cobaia utilizada. Este 
laboratório em especial utiliza três tipos de cobaias: sapos, ratos e coelhos. Para obter estas 
informações, ela sabe exatamente o número de experimentos que foram realizados, o tipo de cobaia 
utilizada e a quantidade de cobaias utilizadas em cada experimento. Faça um programa que 
leia um valor inteiro N que indica os vários casos de teste que vem a seguir. Cada caso de teste contém um 
inteiro que representa a quantidade de cobaias utilizadas e uma letra ('C', 'R' ou 'S'), indicando o tipo 
de cobaia (R:Rato S:Sapo C:Coelho). Apresente o total de cobaias utilizadas, o total de cada tipo de 
cobaia utilizada e o percentual de cada uma em relação ao total de cobaias utilizadas, sendo que o 
percentual deve ser apresentado com dois dígitos após o ponto.*/

//-----------------------------------------------------------

int i, qntdCasos, qntdExperimentos, qntdTotal = 0, qntdC = 0, qntdR = 0, qntdS = 0;
char cdgImput;
float pctgmC, pctgmR, pctgmS;

//-----------------------------------------------------------

int main(void){
    printf("Digite quantos casos de experimentos serao realizados: ");
    fflush(stdin);
    scanf("%i", &qntdCasos);

    for(i = 0; i < qntdCasos; i++){
        printf("Digite quantos experimentos foram realizados: ");
        fflush(stdin);
        scanf("%i", &qntdExperimentos);
        qntdTotal += qntdExperimentos;
        printf("Digite qual cobaia foi utilizada:\n\n[C] - Coelho;\n[S] - Sapo;\n[R] - Rato;\n\nR: ");
        fflush(stdin);
        scanf("%c", &cdgImput);
        system("cls"); // cls for windows

        switch(cdgImput){
            case 'C': qntdC += qntdExperimentos; break;
            case 'S': qntdS += qntdExperimentos; break;
            case 'R': qntdR += qntdExperimentos; break;
        }
    }
    
    pctgmC = (float)(qntdC*100/qntdTotal);
    pctgmR = (float)(qntdR*100/qntdTotal);
    pctgmS = (float)(qntdS*100/qntdTotal);

    printf("Quantidade total de casos de testes realizados: %i\n", qntdCasos);
    printf("Quantidade total de experimentos realizados: %i\n\n", qntdTotal);
    if(qntdC > 0){
        printf("Experimentos em Coelhos: %3.0i - %.2f porcento\n", qntdC, pctgmC);
    }
    if(qntdR > 0){
        printf("Experimentos em Ratos:   %3.0i - %.2f porcento\n", qntdR, pctgmR);
    }
    if(qntdS > 0){
        printf("Experimentos em Sapos:   %3.0i - %.2f porcento\n", qntdS, pctgmS);
    }
    
    return 0;
}

