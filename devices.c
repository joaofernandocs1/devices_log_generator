#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>


// gera um log do ESP32 na data especificada
void writeEspLog (struct tm *tm_datetime) {

/*
"DEVICE_NAME DATETIME TENSAO[V] SINAL[dB] CONEXAO[STATUS] TEMP[°C] HUMID[%] GIRO[Vx, Vy, Vz] VIB[Hz]"
*/

    FILE* log;
    char filename[30];
    char buffer[100];
    char val_buffer[20];
    char device_name[] = "ESP32";

    // esta linha esta alterando outros parametros a struct tm_datetime e distorcendo a data final
    int ret = mktime(tm_datetime); 
    
    if (ret == -1) {
        printf("Error: unable to make time using mktime\n");

    } else {
        // DATETIME: DD/MM/AAAA HH:MM:SS
        // formatacao errada dos segundos esta nessa linha
        strftime(filename, sizeof(filename), "%d%m%Y_%H-%M-%S", tm_datetime);
        printf("%s\n", filename);
    }

    memcpy(buffer, device_name, strlen(device_name)+1);
    strcat(buffer, filename);

    sprintf(val_buffer, "%d V", rand()%5);
    strcat(buffer, val_buffer);
    
    sprintf(val_buffer, "%d dB", rand()%100);
    strcat(buffer, val_buffer);
    
    sprintf(val_buffer, "%d OK", rand()%50);
    strcat(buffer, val_buffer);
    
    sprintf(val_buffer, "%d °C", rand()%35);
    strcat(buffer, val_buffer);
    
    sprintf(val_buffer, "%dp", rand()%100);
    strcat(buffer, val_buffer);
    
    sprintf(val_buffer, "[%d, %d, %d] m/s", rand()%50, rand()%50, rand()%50);
    strcat(buffer, val_buffer);
    
    sprintf(val_buffer, "%d Hz", rand()%5000);
    strcat(buffer, val_buffer);

    strcat(filename, ".txt");

    log = fopen(filename, "w+");

    fprintf(log, "%s", buffer);

    fclose(log);

};

// gera um log do BROKER na data especificada
void writeBrokerLog (struct tm* tm_datetime) {



};

// gera um log do SENSOR_1 na data especificada
void writeSenOneLog (struct tm* tm_datetime) {



};

// gera um log do SENSOR_2 na data especificada
void writeSenTwoLog (struct tm* tm_datetime) {



};

// gera um log do SENSOR_3 na data especificada
void writeSenThreeLog (struct tm* tm_datetime) {



};