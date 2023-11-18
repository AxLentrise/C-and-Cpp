#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <locale.h>
#include <conio.h>

#define MAX 256                 // Constante de m�ximos caracteres aceitos
#define SMALL_INPUT 2           // Entrada limitada para a fun��o main
#define CONST 48                // Constante de coer��o char -> int

/*_______________________________________ Vari�veis ____________________________________________________*/
                                                                                                        //
    char notSafeInputData[MAX]; // Vari�vel de entrada gen�rica, segura os dados para serem tratados    //
    int mainControl = 10;       // Vari�vel tratada de controle da fun��o main                          //
    int patientControl = 0;     // Vari�vel iniciada para controle de aloca��o de dados                 //
    int doctorControl = 0;      // Vari�vel iniciada para controle de aloca��o de dados                 //
    int scheduleControl = 0;    // Vari�vel iniciada para controle de aloca��o de dados                 //
    int i;                      // Vari�vel padr�o de controle de repeti��o                             //
                                                                                                        //
/*______________________________________________________________________________________________________*/
    // Explicando a escolha de vari�veis em ingl�s: para separar o que � c�digo e o que � output

struct IO_DATA{
    char patient[10][MAX];      // Vari�vel para armazenar pacientes
    char doctor[10][MAX];       // Vari�vel para armazenar m�dicos
    char schedule[10][MAX];     // Vari�vel para armazenar agendamentos
    
    /*______________________________________ Fun��o InputData __________________________________________*/
    
    //  Objetivo: Receber dados e redirecion�-los a suas respectivas vari�veis
    //  Utiliza um m�todo de aloca��o baseada em um c�digo "code", que determina o direcionamento
    //  Mensagem generalista que aceita um par�metro "message" a fim de exibir corretamente 
    //  a mensagem sem adicionar linhas de c�digo repetidas para isso
    //  
    //  Tentei fazer o mesmo para alocar os dados, por�m pointers s�o chatos de mecher

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
                    printf("N�mero m�ximo de pacientes cadastrados!\n\n");
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
                    printf("N�mero m�ximo de m�dicos cadastrados!\n\n");
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
                    printf("N�mero m�ximo de consultas cadastradas!\n\n");
                    getch();
                }
                break;
        }
        return 0;
    }

 /*________________________________________ Fun��o OutputData __________________________________________*/
    
    //  Objetivo: Exibir os dados recebidos (se ouver)
    //  Utiliza um m�todo de sele��o identico a fun��o InputData, simples, feio, mas eficaz
    //  N�o cont�m mensagem generalista, uma vez que s�o muitas condicionais nesse caso 
    //  
    //  Com certeza tem como fazer uma fun��o din�mica, mas � muito trabalho para o mesmo resultado

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
                    printf("M�dicos cadastrados: \n\n");
                    for(i = 0; i < doctorControl; i++){
                        printf("[%i] - %s\n", i, doctor[i]);
                    }
                    getch();
                }else{
                    printf("Nenhum m�dico cadastrado!\n\n");
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
    
    //  Objetivo: Receber dados, valid�-los e retornar um c�digo seguro
    //  IsDigit verifica se o primeiro char digitado � um n�mero inteiro de [0-9] e retorna um bool
    //  �til para n�o quebrar o algoritmo caso uma entada inv�lida seja digitada
    //
    //  CharToInt faz o que o nome sugere, converte um '0' char para um 0 int 
    //  Isso � feito aplicando a CONST de coer��o
    //  Uma vez que '0' = 48, '1' = 49, '2' = 50 e assim sucessivamente
    //  Isso tem rela��o com o sistema ASCII


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
    struct Control Control;  // Estrutura de controle de dados, usada apenas para a fun��o main

/*______________________________________________________________________________________________________*/

int main(void){
    setlocale(LC_ALL, "Portuguese");
    while(mainControl != 9){
        system("cls");
        printf("Insira qual opera��o deseja fazer:\n\n"
               
               "[1] - Cadastrar paciente\n"
               "[2] - Cadastrar m�dico\n"
               "[3] - Agendar consulta\n"
               "[4] - Exibir pacientes cadastados\n"
               "[5] - Exibir m�dicos cadastrados\n"
               "[6] - Exibir consultas agendadas\n\n"
               
               "[9] - Encerrar aplica��o\n\n"

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
            case 2: IO.InputData(2, "o nome do m�dico"); break;
            case 3: IO.InputData(3, "o tipo de consulta"); break;
            case 4: IO.OutputData(4); break;
            case 5: IO.OutputData(5); break;
            case 6: IO.OutputData(6); break;

            case 9: continue;
            default: continue;
        }
    }
    // Pensei em colocar uma exibi��o no enceramento, mostrando tudo oque foi
    // registrado, mas nah, j� tem essa op��o, ficaria polu�do demais
    system("cls");
    printf("--------------------------------\n"
           "Encerrado com sucesso!\n"
           "--------------------------------\n"        
           );
    return 0;
}

