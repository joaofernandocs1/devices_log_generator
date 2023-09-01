#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include "devices.h"
#include "string_handling.h"

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

    const char date_delim[2] = "/";
    const char hour_delim[2] = ":";

    struct tm *pParsedDatetime = {0};
    pParsedDatetime = parseInputDatetime(start_date, date_delim, hour_delim);
    writeEspLog(pParsedDatetime);

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