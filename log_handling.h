#include <stdio.h>
#include <stdlib.h>

typedef struct st_CharLog {
    char device_name[10];
    char datetime[20];

} CharLog;

typedef struct st_FloatLog {
    float voltage;
    float wifi_signal;
    float temp;
    float xGiro;
    float yGiro;
    float zGiro;
    float freqVib;

} FloatLog;

typedef struct st_IntLog {
    int conn;
    int humid;


} IntLog;

/*
"DEVICE_NAME DATETIME TENSAO[V] SINAL[dB] TEMP[°C] GIRO[Vx, Vy, Vz] VIB[Hz] CONEXAO[STATUS] HUMID[%]""
*/

// gera um arquivo de logs aleatorio
void genFullLog(char* start_date, char* end_date, const char* device, const int num_logs);

// busca o primeiro log no arquivo especificado
char getFirstLog(const char* filename);

// busca o ultimo log no arquivo especificado
char getLastLog(const char* filename);

// busca um log qualquer no arquivo
char getBatchLog(const char* filename, char* start_date, char* end_date);

// retorna um arquivo com os logs (de um device escolhido) contidos em um arquivo de log
FILE* getDeviceLog(const char* filename, const int device);