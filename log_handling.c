#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include "devices.h"
#include "string_handling.h"
#include "log_handling.h"

/*   

LOG STRUCTURE:   

"DEVICE_NAME DATETIME TENSAO[V] SINAL[dB] TEMP[°C] GIRO[Vx, Vy, Vz] VIB[Hz] HUMID[%] CONEXAO[0-10]"   

*/

// gera um arquivo de logs aleatorio
void genFullLog(char* start_date, char* end_date, const char* device, const int num_logs) {

/*

start_date = "DD/MM/AAAA hh:mm:ss"
end_date = "DD/MM/AAAA hh:mm:ss"
device = ESP32 || BROKER || SENSOR_1 || SENSOR_2 || SENSOR_3
num_logs = integer

*/ 
    char filename[30], datetime[30], file_ext[5] = ".txt";

    struct tm parsedStartDatetime = {0};
    struct tm parsedEndDatetime = {0};
    struct tm *pParsedStartDatetime = &parsedStartDatetime; 
    struct tm *pParsedEndDatetime = &parsedEndDatetime; 

    parseInputDatetime(start_date, pParsedStartDatetime);
    parseInputDatetime(end_date, pParsedEndDatetime);

    int ret_s = mktime(pParsedStartDatetime);
    int ret_e = mktime(pParsedEndDatetime);

    if (ret_s == -1 || ret_e == -1) {
        printf("Erro ao converter uma datas structs em time_t\n");
    } else {
        // nome do arquivo de log leva a data de INICIO dos logs
        strftime(datetime, sizeof(datetime), "%d%m%Y_%H-%M-%S", pParsedStartDatetime);
        printf("%s\n", datetime);
    }

    memcpy(filename, datetime, strlen(datetime)+1);
    strcat(filename, file_ext);

    FILE* log;
    log = fopen(filename, "a");

    double logs_interval = difftime(mktime(pParsedEndDatetime), mktime(pParsedStartDatetime));
    logs_interval /= num_logs;

    for (int i = 0; i < num_logs; i++) {
        pParsedStartDatetime += (int)logs_interval;
        writeEspLog(datetime, log);

    }

    fclose(log);

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
char getBatchLog(const char* filename, char* start_date, char* end_date) {



}

// retorna um arquivo com os logs (de um device escolhido) contidos em um arquivo de log
FILE* getDeviceLog(const char* filename, const int device) {



}