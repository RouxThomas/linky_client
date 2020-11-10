#include <Arduino.h>
#include "utils_memory_serial.h"
#include "utils_memory.h"

void utils_memory_serial::init(unsigned long serial_speed) {
    Serial.begin(serial_speed);
}

void utils_memory_serial::printFreeMemory(char* msg) {
    char buff[25];
    Serial.print(msg);
    Serial.flush();
    sprintf(buff, "free : %d\n", utils_memory::freeRamInByte());
    Serial.print(buff);
    Serial.flush();
    delay(100);
}
