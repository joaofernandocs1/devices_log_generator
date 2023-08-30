#include <stdio.h>
#include <time.h>


// gera um log do ESP32 na data especificada
void writeEspLog (struct tm_start *tm_datetime) {

    FILE* log;
    char filename[80];

    int ret = mktime(tm_datetime);
    
    if (ret == -1) {
        printf("Error: unable to make time using mktime\n");

    } else {
        strftime(filename, sizeof(filename), "%c", &tm_datetime );
        printf(filename);
    }

};

// gera um log do BROKER na data especificada
void writeBrokerLog (struct tm_start *tm_datetime) {



};

// gera um log do SENSOR_1 na data especificada
void writeSenOneLog (struct tm_start *tm_datetime) {



};

// gera um log do SENSOR_2 na data especificada
void writeSenTwoLog (struct tm_start *tm_datetime) {



};

// gera um log do SENSOR_3 na data especificada
void writeSenThreeLog (struct tm_start *tm_datetime) {



};