#include <stdio.h>
#include "devices.h"
#include "string_handling.h"
#include "log_handling.h"

int main () {

    char start_date[] = "25/08/2023 22:45:13";
    char end_date[] = "29/08/2023 07:01:56";

    int num_logs = 15;

    genFullLog(start_date, end_date, ESP32_N, num_logs);

}