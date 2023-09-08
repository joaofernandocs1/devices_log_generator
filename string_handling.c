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

struct tm* parseInputDate(char* date) {

    

}

struct tm* parseInputTime(char* time) {

    
    
}

void parseInputDatetime(char* datetime, struct tm* pToParseDatetime) {
    
    char foo[3]; // random variable to init the pointers
    
    char* token_date = foo; // initialize the pointer with a valid address    
    char* token_hour = foo;
    int cont = 0;

    // extrai dia, mes e ano da data de inicio
    token_date = strtok(datetime, DATE_DELIM);
    pToParseDatetime->tm_mday = atoi(token_date);
    //printf("dia de inicio: %d\n", pToParseDatetime->tm_mday);

    while (token_date != NULL) {
        if (cont == 0) {
            token_date = strtok(NULL, DATE_DELIM);
            pToParseDatetime->tm_mon = atoi(token_date) - 1;
            //printf("mes de inicio: %d\n", pToParseDatetime->tm_mon);
            cont++;
            continue;

        } else if (cont == 1) {
            token_date = strtok(NULL, DATE_DELIM);
            pToParseDatetime->tm_year = atoi(token_date) - 1900;
            //printf("ano de inicio: %d\n", pToParseDatetime->tm_year);
            //token_date = NULL;
            cont++;
            continue;

        } else if (cont == 2) {
            token_date += 5; // pula cinco caracteres na string (pular o ano e mais um espaco)
            token_hour = strtok(token_date, HOUR_DELIM);
            pToParseDatetime->tm_hour = atoi(token_hour);
            //printf("hora de inicio: %d\n", pToParseDatetime->m_hour);
            cont++;
            continue;

        } else if (cont == 3) {
            token_hour = strtok(NULL, HOUR_DELIM);
            pToParseDatetime->tm_min = atoi(token_hour);
            //printf("minuto de inicio: %d\n", pToParseDatetime->tm_min);
            cont++;
            continue;

        } else if (cont == 4) {
            token_hour = strtok(NULL, HOUR_DELIM);
            pToParseDatetime->tm_sec = atoi(token_hour);
            //printf("segundo de inicio: %d\n", pToParseDatetime->tm_sec);
            token_hour = NULL;
            cont++;
            break;

        }
 
    }
    cont = 0;

}