#include <stdio.h>
#include <stdlib.h>

#if  !defined (ESP32)  || !defined (BROKER) || !defined (SENSOR_1) || !defined (SENSOR_2) || !defined (SENSOR_3)
    #define ESP32       1
    #define BROKER      2
    #define SENSOR_1    3
    #define SENSOR_2    4
    #define SENSOR_3    5
#endif

/*   LOG: DEVICE_NAME DATETIME TENSAO DB_SINAL CONEXAO TEMP HUMID   */

// gera um arquivo de logs aleatorio
void genFullLog(char* start_date, char* end_date, const int device, const int num_logs);

// busca o primeiro log no arquivo especificado
char getFirstLog(const char* filename);

// busca o ultimo log no arquivo especificado
char getLastLog(const char* filename);

// busca um log qualquer no arquivo
char getBatchLog(const char* filename, char* start_date, char* end_date);

// retorna um arquivo com os logs (de um device escolhido) contidos em um arquivo de log
FILE* getDeviceLog(const char* filename, const int device);