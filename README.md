# Linky client

![Linky client logo](resources/enedis-linky-erdf.jpg)

## Description
The Lynky client project objectives are :
 * To be abble to received Linky informations according to [Enedis-NOI-CPT_54E](resources/Enedis-Linky-NOI-CPT_54E.pdf) specifications
 * To transmit received informations to a web server via a [POST http request](https://en.wikipedia.org/wiki/POST_(HTTP))
 
## Hardware
An [arduino Uno](https://www.arduino.cc/en/Guide/ArduinoUno) with its [Ethernet shield 2](https://www.arduino.cc/en/Guide/ArduinoEthernetShield) are used.

## Software
 * Default IDE and toolchain are not used here.
 * Toolchain has been rewitten ([GNU make](https://www.gnu.org/software/make/manual/make.html)) to be able to 
    * build on multiple platforms (native, avr etc...)
    * compute code coverage with [lcov](https://wiki.documentfoundation.org/Development/Lcov) tool.
   
#### Dependencies
 * Compilators :
    * [gcc](https://gcc.gnu.org/) : x86 plateform
    * [avr-gcc](https://gcc.gnu.org/wiki/avr-gcc) : arduino platform

 * Tools :
    * [GNU make](https://www.gnu.org/software/make/manual/make.html)
    * [lcov](https://wiki.documentfoundation.org/Development/Lcov)
    
#### Configuration
 * followings [ git subrepo](https://github.com/ingydotnet/git-subrepo) are used
    * [ArduinoCore-avr](https://github.com/arduino/ArduinoCore-avr.git) : in directory arduino_core_avr
    * [Ethernet](https://github.com/arduino-libraries/Ethernet.git) : in directory arduino_libraries/ethernet
