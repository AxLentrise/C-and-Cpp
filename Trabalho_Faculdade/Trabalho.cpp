#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <locale.h>
#include <conio.h>

#define MAX 256                 // Constante de máximos caracteres aceitos
#define SMALL_INPUT 2           // Entrada limitada para a função main
#define CONST 48                // Constante de coerção char -> int

/*_______________________________________ Variáveis ____________________________________________________*/
                                                                                                        //
    char notSafeInputData[MAX]; // Variável de entrada genérica, segura os dados para serem tratados    //
    int mainControl = 10;       // Variável tratada de controle da função main                          //
    int patientControl = 0;     // Variável iniciada para controle de alocação de dados                 //
    int doctorControl = 0;      // Variável iniciada para controle de alocação de dados                 //
    int scheduleControl = 0;    // Variável iniciada para controle de alocação de dados                 //
    int i;                      // Variável padrão de controle de repetição                             //
                                                                                                        //
/*______________________________________________________________________________________________________*/
    // Explicando a escolha de variáveis em inglês: para separar o que é código e o que é output

struct IO_DATA{
    char patient[10][MAX];      // Variável para armazenar pacientes
    char doctor[10][MAX];       // Variável para armazenar médicos
    char schedule[10][MAX];     // Variável para armazenar agendamentos
    
    /*______________________________________ Função InputData __________________________________________*/
    
    //  Objetivo: Receber dados e redirecioná-los a suas respectivas variáveis
    //  Utiliza um método de alocação baseada em um código "code", que determina o direcionamento
    //  Mensagem generalista que aceita um parâmetro "message" a fim de exibir corretamente 
    //  a mensagem sem adicionar linhas de código repetidas para isso
    //  
    //  Tentei fazer o mesmo para alocar os dados, porém pointers são chatos de mecher

    int InputData(int code, char message[MAX]){
        system("cls");
        printf("Insira %s: ", message);
        fflush(stdin);
        switch(code){
            case 1:
                if(patientControl < 10){
                    if((fgets(patient[patientControl], sizeof patient[patientControl], stdin) != NULL)){
                        patient[patientControl][strlen(patient[patientControl])-1] = '\0';
                    }
                    patientControl++;
                }else{
                	system("cls");
                    printf("Número máximo de pacientes cadastrados!\n\n");
                    getch();
                }
                break;
            case 2: 
                if(doctorControl < 10){
                    if((fgets(doctor[doctorControl], sizeof doctor[doctorControl], stdin) != NULL)){
                        doctor[doctorControl][strlen(doctor[doctorControl])-1] = '\0';
                    }
                    doctorControl++;
                }else{
                	system("cls");
                    printf("Número máximo de médicos cadastrados!\n\n");
                    getch();
                }
                break;
            case 3: 
                if(scheduleControl < 10){
                    if((fgets(schedule[scheduleControl], sizeof schedule[scheduleControl], stdin) != NULL)){
                        schedule[scheduleControl][strlen(schedule[scheduleControl])-1] = '\0';
                    }
                    scheduleControl++;
                }else{
                	system("cls");
                    printf("Número máximo de consultas cadastradas!\n\n");
                    getch();
                }
                break;
        }
        return 0;
    }

 /*________________________________________ Função OutputData __________________________________________*/
    
    //  Objetivo: Exibir os dados recebidos (se ouver)
    //  Utiliza um método de seleção identico a função InputData, simples, feio, mas eficaz
    //  Não contém mensagem generalista, uma vez que são muitas condicionais nesse caso 
    //  
    //  Com certeza tem como fazer uma função dinâmica, mas é muito trabalho para o mesmo resultado

    int OutputData(int code){
        system("cls");
        switch(code){
            case 4: 
                if(patientControl != 0){
                    printf("Pacientes cadastrados: \n\n");
                    for(i = 0; i < patientControl; i++){
                        printf("[%i] - %s\n", i, patient[i]);
                    }
                    getch();
                }else{
                    printf("Nenhum paciente cadastrado!\n\n");
                    getch();
                }               
                break;
            case 5: 
                if(doctorControl != 0){
                    printf("Médicos cadastrados: \n\n");
                    for(i = 0; i < doctorControl; i++){
                        printf("[%i] - %s\n", i, doctor[i]);
                    }
                    getch();
                }else{
                    printf("Nenhum médico cadastrado!\n\n");
                    getch();
                }
                break;
            case 6: 
                if(scheduleControl != 0){
                    printf("Consultas cadastrados: \n\n");
                    for(i = 0; i < scheduleControl; i++){
                        printf("[%i] - %s\n", i, schedule[i]);
                    }
                    getch();
                }else{
                    printf("Nenhuma consulta cadastrada!\n\n");
                    getch();
                }
                break;
        }
        return 0;
    }
};

 /*_________________________________________ Classe Control ____________________________________________*/
    
    //  Objetivo: Receber dados, validá-los e retornar um código seguro
    //  IsDigit verifica se o primeiro char digitado é um número inteiro de [0-9] e retorna um bool
    //  Útil para não quebrar o algoritmo caso uma entada inválida seja digitada
    //
    //  CharToInt faz o que o nome sugere, converte um '0' char para um 0 int 
    //  Isso é feito aplicando a CONST de coerção
    //  Uma vez que '0' = 48, '1' = 49, '2' = 50 e assim sucessivamente
    //  Isso tem relação com o sistema ASCII


struct Control{
    bool IsDigit(int nothing){
        return isdigit(notSafeInputData[0]);
    }
    int CharToInt(int nothing){
        return ((int)notSafeInputData[0]-CONST);
    }
};

/*______________________________________________________________________________________________________*/

    struct IO_DATA IO;       // Estrutura de I/O complexa, para os dados inseridos
    struct Control Control;  // Estrutura de controle de dados, usada apenas para a função main

/*______________________________________________________________________________________________________*/

int main(void){
    setlocale(LC_ALL, "Portuguese");
    while(mainControl != 9){
        system("cls");
        printf("Insira qual operação deseja fazer:\n\n"
               
               "[1] - Cadastrar paciente\n"
               "[2] - Cadastrar médico\n"
               "[3] - Agendar consulta\n"
               "[4] - Exibir pacientes cadastados\n"
               "[5] - Exibir médicos cadastrados\n"
               "[6] - Exibir consultas agendadas\n\n"
               
               "[9] - Encerrar aplicação\n\n"

               "Resposta: "
               );
        fflush(stdin);
        fgets(notSafeInputData, SMALL_INPUT, stdin);       
        if(Control.IsDigit(1)){
            mainControl = Control.CharToInt(1);
        }else{
            continue;
        }

        switch(mainControl){
            case 1: IO.InputData(1, "o nome do paciente"); break;
            case 2: IO.InputData(2, "o nome do médico"); break;
            case 3: IO.InputData(3, "o tipo de consulta"); break;
            case 4: IO.OutputData(4); break;
            case 5: IO.OutputData(5); break;
            case 6: IO.OutputData(6); break;

            case 9: continue;
            default: continue;
        }
    }
    // Pensei em colocar uma exibição no enceramento, mostrando tudo oque foi
    // registrado, mas nah, já tem essa opção, ficaria poluído demais
    system("cls");
    printf("--------------------------------\n"
           "Encerrado com sucesso!\n"
           "--------------------------------\n"        
           );
    return 0;
}

