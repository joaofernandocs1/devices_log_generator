#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include "devices.h"

/*   

LOG STRUCTURE:   

"DEVICE_NAME   DATETIME   TENSAO   DB_SINAL   CONEXAO   TEMP   HUMID   GIRO   VIB"   */

// gera um arquivo de logs aleatorio
void genFullLog(char* start_date, char* end_date, const int* device, const int num_logs) {

/*

start_date = "DD/MM/AAAA hh:mm:ss"
end_date = "DD/MM/AAAA hh:mm:ss"
device = ESP32 || BROKER || SENSOR_1 || SENSOR_2 || SENSOR_3
num_logs = integer

*/ 

    // initialize the struct filled with zeros
    struct tm info_start = {0};
    // initialize the struct filled with zeros
    struct tm info_end = {0};

    const char date_delim[2] = "/";
    const char hour_delim[2] = ":";
    int cont = 0;
    
    char foo[3]; // random variable to init the pointers
    
    char* token_start_date = foo; // initialize the pointer with a valid address
    char* token_end_date = foo; // initialize the pointer with a valid address
    
    char* token_start_hour = foo;
    char* token_end_hour = foo;

    // extrai dia, mes e ano da data de inicio
    token_start_date = strtok(start_date, date_delim);
    info_start.tm_mday = atoi(token_start_date);
    printf("dia de inicio: %d\n", info_start.tm_mday);

    while (token_start_date != NULL) {
        if (cont == 0) {
            token_start_date = strtok(NULL, date_delim);
            info_start.tm_mon = atoi(token_start_date) - 1;
            printf("mes de inicio: %d\n", info_start.tm_mon);
            cont++;
            continue;

        } else if (cont == 1) {
            token_start_date = strtok(NULL, date_delim);
            info_start.tm_year = atoi(token_start_date) - 1900;
            printf("ano de inicio: %d\n", info_start.tm_year);
            //token_start_date = NULL;
            cont++;
            continue;

        } else if (cont == 2) {
            token_start_date += 5; // pula cinco caracteres na string (pular o ano e mais um espaco)
            token_start_hour = strtok(token_start_date, hour_delim);
            info_start.tm_hour = atoi(token_start_hour);
            printf("hora de inicio: %d\n", info_start.tm_hour);
            cont++;
            continue;

        } else if (cont == 3) {
            token_start_hour = strtok(NULL, hour_delim);
            info_start.tm_min = atoi(token_start_hour);
            printf("minuto de inicio: %d\n", info_start.tm_min);
            cont++;
            continue;

        } else if (cont == 4) {
            token_start_hour = strtok(NULL, hour_delim);
            info_start.tm_sec = atoi(token_start_hour);
            printf("segundo de inicio: %d\n", info_start.tm_sec);
            token_start_hour = NULL;
            cont++;
            break;

        }
 
    }
    cont = 0;

    // extrai dia, mes e ano da data de fim
    token_end_date = strtok(end_date, date_delim);
    info_end.tm_mday = atoi(token_end_date);
    printf("dia de fim: %d\n", info_end.tm_mday);

    while (token_end_date != NULL) {
        if (cont == 0) {
            token_end_date = strtok(NULL, date_delim);
            info_end.tm_mon = atoi(token_end_date) - 1;
            printf("mes de fim: %d\n", info_end.tm_mon);
            cont++;
            continue;

        } else if (cont == 1) {
            token_end_date = strtok(NULL, date_delim);
            info_end.tm_year = atoi(token_end_date) - 1900;
            printf("ano de fim: %d\n", info_end.tm_year);
            //token_end_date = NULL;
            cont++;
            continue;

        } else if (cont == 2) {
            token_end_date += 5; // pula cinco caracteres na string (pular o ano e mais um espaco)
            token_end_hour = strtok(token_end_date, hour_delim);
            info_end.tm_hour = atoi(token_end_hour);
            printf("hora de fim: %d\n", info_end.tm_hour);
            cont++;
            continue;

        } else if (cont == 3) {
            token_end_hour = strtok(NULL, hour_delim);
            info_end.tm_min = atoi(token_end_hour);
            printf("minuto de fim: %d\n", info_end.tm_min);
            cont++;
            continue;

        } else if (cont == 4) {
            token_end_hour = strtok(NULL, hour_delim);
            info_end.tm_sec = atoi(token_end_hour);
            printf("segundo de fim: %d\n", info_end.tm_sec);
            token_end_hour = NULL;
            cont++;
            break;

        }
 
    }
    cont = 0;

    // a cada iteração pega um valor aleatorio para o dispositivo escolhido
    //for (int i = 0; i < num_logs; i++) {

    writeEspLog(&info_start);
    writeEspLog(&info_end);

    //}

}

// busca o primeiro log no arquivo especificado
char getFirstLog(const char* filename) {

/*

filename = "/home/joaofernando/Documents/exercicios_c/udemy_c/sec11/logs_NUMLOGS_DEVICE_DATETIME.txt"

*/

}

// busca o ultimo log no arquivo especificado
char getLastLog(const char* filename) {



}

// busca um batch de logs entre as datas passadas para a funcao no arquivo
char getBatchLog(const char* filename, const char* datetime) {



}

// retorna um arquivo com os logs (de um device escolhido) contidos em um arquivo de log
FILE* getDeviceLog(const char* filename, const int device) {



}