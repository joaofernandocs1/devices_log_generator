#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>


// gera um log do ESP32 na data especificada
void writeEspLog (struct tm *tm_datetime) {

/*
"DEVICE_NAME DATETIME TENSAO[V] SINAL[dB] TEMP[°C] GIRO[Vx, Vy, Vz] VIB[Hz] CONEXAO[STATUS] HUMID[%]""
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

    // DEVICE_NAME
    memcpy(buffer, device_name, strlen(device_name)+1);
    
    // DATETIME
    strcat(buffer, filename);

    // TENSAO
    sprintf(val_buffer, "%dV ", getVoltage());
    strcat(buffer, val_buffer);
    
    // SINAL
    sprintf(val_buffer, "%ddB ", getWifiSignal());
    strcat(buffer, val_buffer);
    
    // TEMP
    sprintf(val_buffer, "%.2f°C ", getTemp());
    strcat(buffer, val_buffer);
    
    // GIRO
    sprintf(val_buffer, "[%.2f, %.2f, %.2f] m/s ", *(getGiro()), *(getGiro()+1), *(getGiro()+2));
    strcat(buffer, val_buffer);

    // VIB
    sprintf(val_buffer, "%.2f Hz", getFreqVib());
    strcat(buffer, val_buffer);

    // CONEXAO
    sprintf(val_buffer, "%d ", getConn());
    strcat(buffer, val_buffer);
    
    // HUMID
    sprintf(val_buffer, "%dp ", getHumid());
    strcat(buffer, val_buffer);

    strcat(filename, ".txt");

    log = fopen(filename, "a");

    fprintf(log, "%s", buffer);

    fclose(log);

};

float getVoltage () {

    float voltage = rand()%5;
    return voltage;
}

float getWifiSignal () {

    float wifi_signal = rand()%100;
    return wifi_signal;
}

int getConn () {

    int conn = rand()%50;

    /*if (conn <= 20) {
        conn == "WEAK";

    } else if (conn > 20 && conn <= 40) {
        conn == "OK";
        
    } else if (conn > 40) {
        conn == "STRONG";
    }*/

    return conn;
}

float getTemp () {

    float Temp = rand()%50;
    return Temp;
}

int getHumid () {

    int Humid = rand()%100;
    return Humid;
}

float* getGiro () {

    float Giro[3];

    Giro[0] = rand()%50;
    Giro[1] = rand()%50;
    Giro[2] = rand()%50;

    return Giro;
}

float getFreqVib () {

    float freqVib = rand()%5000;
    return freqVib;
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