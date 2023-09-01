#include <time.h>

// gera um log do ESP32 na data especificada
void writeEspLog (struct tm *tm_datetime);

// gera um log do BROKER na data especificada
void writeBrokerLog (struct tm *tm_datetime);

// gera um log do SENSOR_1 na data especificada
void writeSenOneLog (struct tm *tm_datetime);

// gera um log do SENSOR_2 na data especificada
void writeSenTwoLog (struct tm *tm_datetime);

// gera um log do SENSOR_3 na data especificada
void writeSenThreeLog (struct tm *tm_datetime);