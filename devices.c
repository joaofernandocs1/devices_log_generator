#include <stdio.h>
#include <time.h>


// gera um log do ESP32 na data especificada
void writeEspLog (struct tm *tm_datetime) {

    FILE* log;
    char filename[80];

    // esta linha esta alterando outros parametros a struct tm_datetime e distorcendo a data final
    int ret = mktime(tm_datetime); 
    
    if (ret == -1) {
        printf("Error: unable to make time using mktime\n");

    } else {
        // DATETIME: DD/MM/AAAA HH:MM:SS
        strftime(filename, sizeof(filename), "%d/%m/%Y %X", tm_datetime );
        printf("%s\n", filename);
    }

};

// gera um log do BROKER na data especificada
void writeBrokerLog (struct tm *tm_datetime) {



};

// gera um log do SENSOR_1 na data especificada
void writeSenOneLog (struct tm *tm_datetime) {



};

// gera um log do SENSOR_2 na data especificada
void writeSenTwoLog (struct tm *tm_datetime) {



};

// gera um log do SENSOR_3 na data especificada
void writeSenThreeLog (struct tm *tm_datetime) {



};