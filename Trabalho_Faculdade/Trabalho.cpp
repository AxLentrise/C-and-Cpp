#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <locale.h>
#include <conio.h>

#define MAX 256
#define SMALL_INPUT 2
#define CONST 48

struct data{
    char doctor[10][MAX];
    char patient[10][MAX];
    char schedule[10][MAX];
};

/*---------------------------------------------------------------------------------*/

struct data hospital;
char notSafeInputData[MAX];
int safeInputData;
bool verif;
int i, j, control = 10;
int patientControl = 0, doctorControl = 0, scheduleControl = 0;

/*---------------------------------------------------------------------------------*/

int isDigitVerif(int nothing){
    if(isdigit(notSafeInputData[0])){
            verif = true;
        }
    return 0;
}

int charToInt(int nothing){
    safeInputData = ((int)notSafeInputData[0]-CONST);    
    return 0;
}

int dataInput(int selectDataDestiny){
	setlocale(LC_ALL, "Portuguese");
    system("cls");
    fflush(stdin);
    switch(selectDataDestiny){
        case 1:{
        	if(patientControl < 10){
        		printf("Digite o nome do paciente: ");
            	fgets(notSafeInputData, MAX, stdin);
            	for(i = 0; i < (strlen(notSafeInputData)-1); i++);{
                	hospital.patient[patientControl][i] = notSafeInputData[i];
            	}
            	patientControl++;	
			}else{
				printf("Máximo de pacientes registrados.\n\n");
				getch();
			}
            
        } break;
        case 2:{
        	if(doctorControl < 10){
        		printf("Digite o nome do médico: ");
            	fgets(notSafeInputData, MAX, stdin);
            	for(i = 0; i < (strlen(notSafeInputData)-1); i++){
                	hospital.doctor[doctorControl][i] = notSafeInputData[i];
            	}
            	doctorControl++;	
			}else{
				printf("Máximo de médicos registrados.\n\n");
				getch();	
			}
        } break;
        case 3:{
        	if(scheduleControl < 10){
        		printf("Digite o qual consulta deseja agendar: ");
            	fgets(notSafeInputData, MAX, stdin);
            	for(i = 0; i < (strlen(notSafeInputData)-1); i++){
                	hospital.schedule[scheduleControl][i] = notSafeInputData[i];
            	}
            	scheduleControl++;
			}else{
				printf("Máximo de consultas registradas.\n\n");
				getch();
			}
        } break;
    }
    return 0;
}

int dataOutput(int selectDataOutput){
	setlocale(LC_ALL, "Portuguese");
    system("cls");
    switch(selectDataOutput){
        case 1:{
            if(patientControl > 0){
                printf("Lista de pacientes cadastrados:\n\n");
                for(i = 0; i < patientControl; i++){
                    printf("[%i] - %s\n", i, hospital.patient[i]);
                }
                printf("\n\n");
                getch();
            }else{
                printf("Nenhum paciente cadastrado.\n\n");
                getch();
            }
        }; break;
        case 2:{
            if(doctorControl > 0){
                printf("Lista de médicos cadastrados:\n\n");
                for(i = 0; i < doctorControl; i++){
                    printf("[%i] - %s\n", i, hospital.doctor[i]);
                }
                printf("\n\n");
                getch();
            }else{
                printf("Nenhum médico cadastrado.\n\n");
                getch();
            }
        }; break;
        case 3:{
            if(scheduleControl > 0){
                printf("Lista de consultas agendadas:\n\n");
                for(i = 0; i < scheduleControl; i++){
                    printf("[%i] - %s\n", i, hospital.schedule[i]);
                }
                printf("\n\n");
                getch();
            }else{
                printf("Nenhuma consulta agendada.\n\n");
                getch();
            }
        }; break;
    }
    return 0;
}


int main(void){
	setlocale(LC_ALL, "Portuguese");
    while(control != 9){
        system("cls");
        printf("Insira um digito para escolher uma operação:\n\n"
               
                "[1] - Cadastrar paciente\n"
                "[2] - Cadastrar médico\n"
                "[3] - Agendar consulta\n"
                "[4] - Listar pacientes\n"
                "[5] - Listar médicos\n"
                "[6] - Listas consultas\n\n"
                
                "[9] - Sair\n\n"
                
                "R: ");

        fflush(stdin);
        fgets(notSafeInputData, SMALL_INPUT, stdin);
        isDigitVerif(1);
        if(verif){
            charToInt(1);
        }else{
            continue;
        }

        switch(safeInputData){
            case 1:{dataInput(1);} break;
            case 2:{dataInput(2);} break;
            case 3:{dataInput(3);} break;

            case 4:{dataOutput(1);} break;
            case 5:{dataOutput(2);} break;
            case 6:{dataOutput(3);} break;

            case 9:{
                system("cls");
                control = 9;
            } break;
            default:{continue;} break;
        }
    }
    printf("Aplicação encerrada com sucesso!\n\n");
    return 0;
}

