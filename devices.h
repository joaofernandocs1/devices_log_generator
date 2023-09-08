#include <time.h>

#if !defined (ESP32_N)  || !defined (BROKER_N) || !defined (SENSOR_1_N) || !defined (SENSOR_2_N) || !defined (SENSOR_3_N)
    #define ESP32_N       "ESP32"
    #define BROKER_N      "BROKER"
    #define SENSOR_1_N    "SENSOR_1"
    #define SENSOR_2_N    "SENSOR_2"
    #define SENSOR_3_N    "SENSOR_3"
#endif

#if !defined (ESP32_IND)  || !defined (BROKER_IND) || !defined (SENSOR_1_IND) || !defined (SENSOR_2_IND) || !defined (SENSOR_3_IND)
    #define ESP32_IND       1
    #define BROKER_IND      2
    #define SENSOR_1_IND    3
    #define SENSOR_2_IND    4
    #define SENSOR_3_IND    5
#endif

float getVoltage();
float getWifiSignal();
float getTemp();
void getGiro(float* giro);
float getFreqVib();
int getConn();
int getHumid();

// gera um log do ESP32 na data especificada
void writeEspLog (const char* datetime, FILE* logFile);

// gera um log do BROKER na data especificada
void writeBrokerLog (struct tm *tm_datetime);

// gera um log do SENSOR_1 na data especificada
void writeSenOneLog (struct tm *tm_datetime);

// gera um log do SENSOR_2 na data especificada
void writeSenTwoLog (struct tm *tm_datetime);

// gera um log do SENSOR_3 na data especificada
void writeSenThreeLog (struct tm *tm_datetime);