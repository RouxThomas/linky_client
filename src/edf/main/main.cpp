#include <Arduino.h>

#include "Ethernet.h"
#include "edf_controller.h"
#include "SoftwareSerial.h"
#include "EthernetClient.h"
#include "input_stream_adapter.h"
#include "output_stream_adapter.h"
#include "connectable_adapter.h"

#define CLIENT_BUFF_SIZE_IN_BYTES 400

void initialize() {
    init(); // init for delay

    pinMode(2, INPUT);
    pinMode(13, OUTPUT);
    digitalWrite(2, HIGH);    // Enable pullup resistor
    sei();

    // Enable global interrupts
    EIMSK |= (1 << INT0);     // Enable external interrupt INT0
    EICRA |= (1 << ISC01);    // Trigger INT0 on falling edge

    // disable the SD card by switching pin 4 high
    // not using the SD card in this program, but if an SD card is left in the socket,
    // it may cause a problem with accessing the Ethernet chip, unless disabled
    pinMode(4, OUTPUT);
    digitalWrite(4, HIGH);
}

int main(void) {
    initialize();

    const uint8_t mac[] = {
            0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };
    const IPAddress localIp(192, 168, 1, 77);

    const char server_ip[] = "192.168.1.75";
    const char server_port[] = "3000";

    //************* TODO *************
    // - power optimization
    // - filter transmission according to '<' or 'IINST' see traces?

    const uint8_t pin_rx = 8;
    const uint8_t pin_tx = 9;
    const long int serial_speed_in_baud = 1200;
    SoftwareSerial* serialStream = new SoftwareSerial(pin_rx, pin_tx);

    const Client* client = (Client*) new EthernetClient();
    const char* client_buffer = new char[CLIENT_BUFF_SIZE_IN_BYTES];

    const input_stream* inputStream = new input_stream_adapter((Stream*) serialStream);
    const output_stream* outputStream = new output_stream_adapter((Client*) client);
    const connectable* connectableAdapter = new connectable_adapter((Client*) client);

    edf_controller* edf_ctrl = new edf_controller(inputStream,
                                                  outputStream,
                                                  connectableAdapter,
                                                  server_ip,
                                                  server_port,
                                                  client_buffer,
                                                  CLIENT_BUFF_SIZE_IN_BYTES);

    Ethernet.begin((uint8_t*) mac, localIp);
    delay(1000); // give time to init ethernet shield

    serialStream->begin(serial_speed_in_baud);

    while (true) {
        edf_ctrl->run();
        delay(1000);
    }

    return 0;
}

