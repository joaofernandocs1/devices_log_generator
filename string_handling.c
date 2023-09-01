#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "string_handling.h"


// refatorar para aritmetica de ponteiros
void checkInside (const char* pStr1, size_t lenStr1, const char* pStr2, size_t lenStr2) {

    // i para iterar na string principal
    // j para iterar na string secundaria
    // i_aux para armazenar a posicao temporaria do caracter caso ele seja igual ao primeiro da string secundaria
    // cont para contar quantos caracteres foram iguais apos o primeiro

    printf("entrou aqui\n");
    int i = 0, i_aux, j, cont = 0;


    // enquanto a string principal nao termina
    while (*(pStr1+i) != '\0') {

        // checa se o caracter i da string principal e igual ao primeiro caracter da string secundaria
        if (*(pStr1+i) == *(pStr2)) {

            printf("%c e igual a %c\n", *(pStr1+i), *(pStr2));
            i_aux = i; // armazena a posicao do caracter que for igual
            // passa para a posicao seguinte
            //i++;
            // itera na string secundaria para testar se todos os caracteres subsequentes serao iguais ate o fim
            for (j = 0; j < lenStr2; j++) {

                if (*(pStr1+i) == *(pStr2+j)) {
                    printf("%c e igual a %c\n", pStr1[i], pStr2[j]);
                    cont++;

                } else {
                    break;

                }

                i++;
                
            }

            if (cont == lenStr2) {
                printf("%c esta contida em %c\n", *pStr2, *pStr1);

            } else {
                i = i_aux;

            }
            i++;

        } else if (*(pStr1+i) != *(pStr2)) {
            printf("%c e diferente de %c\n", *(pStr1+i), *(pStr2));
            i++;

        }
    }
}

struct tm* parseInputDate(char* date, const char* date_delim) {

    

}

struct tm* parseInputTime(char* time, const char* hour_delim) {

    
    
}

struct tm* parseInputDatetime(char* datetime, const char* date_delim, const char* hour_delim) {

/*
    start_date = "DD/MM/AAAA hh:mm:ss"
    end_date = "DD/MM/AAAA hh:mm:ss"
    date_delim = "/"
    hour_delim = ":"
*/ 

    // initialize the struct filled with zeros
    struct tm parsedDatetime = {0};
    struct tm* pParsedDatetime;
    pParsedDatetime = &parsedDatetime;
    
    char foo[3]; // random variable to init the pointers
    
    char* token_start_date = foo; // initialize the pointer with a valid address    
    char* token_start_hour = foo;
    int cont = 0;

    // extrai dia, mes e ano da data de inicio
    token_start_date = strtok(datetime, date_delim);
    parsedDatetime.tm_mday = atoi(token_start_date);
    //printf("dia de inicio: %d\n", parsedDatetime.tm_mday);

    while (token_start_date != NULL) {
        if (cont == 0) {
            token_start_date = strtok(NULL, date_delim);
            parsedDatetime.tm_mon = atoi(token_start_date) - 1;
            //printf("mes de inicio: %d\n", parsedDatetime.tm_mon);
            cont++;
            continue;

        } else if (cont == 1) {
            token_start_date = strtok(NULL, date_delim);
            parsedDatetime.tm_year = atoi(token_start_date) - 1900;
            //printf("ano de inicio: %d\n", parsedDatetime.tm_year);
            //token_start_date = NULL;
            cont++;
            continue;

        } else if (cont == 2) {
            token_start_date += 5; // pula cinco caracteres na string (pular o ano e mais um espaco)
            token_start_hour = strtok(token_start_date, hour_delim);
            parsedDatetime.tm_hour = atoi(token_start_hour);
            //printf("hora de inicio: %d\n", parsedDatetime.tm_hour);
            cont++;
            continue;

        } else if (cont == 3) {
            token_start_hour = strtok(NULL, hour_delim);
            parsedDatetime.tm_min = atoi(token_start_hour);
            //printf("minuto de inicio: %d\n", parsedDatetime.tm_min);
            cont++;
            continue;

        } else if (cont == 4) {
            token_start_hour = strtok(NULL, hour_delim);
            parsedDatetime.tm_sec = atoi(token_start_hour);
            //printf("segundo de inicio: %d\n", parsedDatetime.tm_sec);
            token_start_hour = NULL;
            cont++;
            break;

        }
 
    }
    cont = 0;

    // seta DST para desconhecido
    //pParsedDatetime->tm_isdst = -1;

    return pParsedDatetime;
}