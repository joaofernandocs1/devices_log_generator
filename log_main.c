#include <stdio.h>
#include "log_handling.h"

int main () {

    char start_date[] = "25/08/2023";
    char end_date[] = "29/08/2023";
    int num_logs = 3;

    genFullLog(start_date, end_date, ESP32, num_logs);

}