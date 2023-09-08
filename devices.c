#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "devices.h"


// gera um log do ESP32 na data especificada
void writeEspLog (struct tm *tm_datetime) {

/*
"DEVICE_NAME DATETIME TENSAO[V] SINAL[dB] TEMP[°C] GIRO[Vx, Vy, Vz] VIB[Hz] CONEXAO[STATUS] HUMID[%]""
*/

    FILE* log;
    char filename[30];
    char buffer[100];
    //char val_buffer[20];
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

    float voltage = getVoltage();
    float signal = getWifiSignal();
    float temp = getTemp();
    float giro[3];
    float freq = getFreqVib();
    int conn = getConn();
    int humid = getHumid();

    strcat(filename, ".txt");

    log = fopen(filename, "a");

    // erro na linha abaixo
    fprintf(log, "%s %.2fV %.2fdB %.2f°C [%.2f, %.2f, %.2f] m/s %.2f Hz %d W %dp ", filename, voltage, signal, temp, *(giro), *(giro+1), *(giro+2), freq, conn, humid);

    fclose(log);

};

float getVoltage () {

    float a = 5.0;

    float voltage = (float)rand()/(float)(RAND_MAX)*a;
    return voltage;
}

float getWifiSignal () {

    float a = 100.0;

    float wifi_signal = (float)rand()/(float)(RAND_MAX)*a;
    return wifi_signal;
}

float getTemp () {

    float a = 50.0;

    float Temp = (float)rand()/(float)(RAND_MAX)*a;
    return Temp;
}

void getGiro (float* giro) {

    float a = 50.0;

    *(giro) = (float)rand()/(float)(RAND_MAX)*a;
    *(giro+1) = (float)rand()/(float)(RAND_MAX)*a;
    *(giro+2) = (float)rand()/(float)(RAND_MAX)*a;

}

float getFreqVib () {

    float a = 5000.0;

    float freqVib = (float)rand()/(float)(RAND_MAX)*a;
    return freqVib;
}

int getConn () {

    float a = 50.0;

    int conn = (float)rand()/(float)(RAND_MAX)*a;

    /*if (conn <= 20) {
        conn == "WEAK";

    } else if (conn > 20 && conn <= 40) {
        conn == "OK";
        
    } else if (conn > 40) {
        conn == "STRONG";
    }*/

    return conn;
}

int getHumid () {

    int Humid = rand()%100;
    return Humid;
}


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