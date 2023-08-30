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

start_date = "HH/MM/AAAA"
end_date = "HH/MM/AAAA"
device = ESP32 || BROKER || SENSOR_1 || SENSOR_2 || SENSOR_3
num_logs = integer

*/ 

    // initialize the struct filled with zeros
    struct tm info_start = {0};
    // initialize the struct filled with zeros
    struct tm info_end = {0};

    const char delim[2] = "/";
    int cont = 0;
    char foo[3]; // random variable to init the pointers
    char* token_start = foo; // initialize the pointer with a valid address
    char* token_end = foo; // initialize the pointer with a valid address

    // extrai dia, mes e ano da data de inicio
    token_start = strtok(start_date, delim);
    info_start.tm_mday = atoi(token_start);
    printf("dia de inicio: %d\n", info_start.tm_mday);

    while (token_start != NULL) {
        if (cont == 0) {

            token_start = strtok(NULL, delim);
            info_start.tm_mon = atoi(token_start);
            printf("mes de inicio: %d\n", info_start.tm_mon);

        } else if (cont == 1) {
            token_start = strtok(NULL, delim);
            info_start.tm_year = atoi(token_start);
            printf("ano de inicio: %d\n", info_start.tm_year);
            token_start = NULL;

        }
        cont++;
    
    }
    cont = 0;

    // extrai dia, mes e ano da data de fim
    token_end = strtok(end_date, delim);
    info_end.tm_mday = atoi(token_end);
    printf("dia de fim: %d\n", info_end.tm_mday);

    while (token_end != NULL) {
        if (cont == 0) {
            token_end = strtok(NULL, delim);
            info_end.tm_mon = atoi(token_end);
            printf("mes de fim: %d\n", info_end.tm_mon);

        } else if (cont == 1) {
            token_end = strtok(NULL, delim);
            info_end.tm_year = atoi(token_end);
            printf("ano de fim: %d\n", info_end.tm_year);
            token_end = NULL;

        }
        cont++;
    
    }

    // a cada iteração pega um valor aleatorio para o dispositivo escolhido
    for (int i = 0; i < num_logs; i++) {

        writeEspLog(&info_start);

    }

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