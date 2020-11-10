#include <stdio.h>
#include "uart.h"
#include "global_tests_suite.h"

int main(void) {
 
    FILE uart_output = FDEV_SETUP_STREAM(uart_putchar, NULL, _FDEV_SETUP_WRITE);
    FILE uart_input = FDEV_SETUP_STREAM(NULL, uart_getchar, _FDEV_SETUP_READ);

    uart_init();
    stdout = &uart_output;
    stderr = &uart_output;
    stdin  = &uart_input;

    //waiting 'S' start flag
    while(getchar() != 'S');

    run_global_tests_suite();

    fflush(stdout);
    printf("<end_of_ut>\n");
    
    return 0;
}
