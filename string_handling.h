#include <stdio.h>
#include <time.h>

#define DATE_DELIM "/"
#define HOUR_DELIM ":"


// se string2 esta em string1
void checkInside(const char* pStr1, size_t lenStr1, const char* pStr2, size_t lenStr2);

// processa uma string com data recebendo as mesmas e seus delimitadores
// retorna um ponteiro para uma struct tm com os valores de dia, mes e ano 
struct tm* parseInputDate(char* date);

// processa uma string com horario recebendo as mesmas e seus delimitadores
// retorna um ponteiro para uma struct tm com os valores de hora, minuto e segundp
struct tm* parseInputTime(char* time);

// processa um string contendo data e horario recebendo as mesmas e seus delimitadores
// retorna um ponteiro para uma struct tm com todos os valores processados
void parseInputDatetime(char* datetime, struct tm* pToParsedDatetime);