#include "tests_edf_controller.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <string.h>
#include "buffer_tools.h"

#define SERVER_IP "127.0.0.1"
#define SERVER_PORT "3000"

#define CONNECTED   1
#define NOT_CONNECTED 0

#define LLT_EDF_PARAM_SIZE  4
#define LLT_START_FRAME_TAG 0x02
#define LLT_END_FRAME_TAG   0x03

#define EXPECTED_TRAME_FIRST_PART "POST / HTTP/1.1\nHost: 127.0.0.1\nUser-Agent: arduino/edf\nConnection: close\nContent-Type: application/x-www-form-urlencoded;\nContent-Length: 14\n\n"

tests_edf_controller::tests_edf_controller(const char* test_name,
                                           const char* buffer,
                                           const int buffer_size,
                                           const char* buffer2,
                                           const int buffer_size2,
                                           const char* buffer3,
                                           const int buffer_size3,
                                           checker_str* str_checker)
        : test(test_name) {
    assert(str_checker != NULL);

    this->str_checker = str_checker;
    this->output_stream_buff = (char*) buffer2;
    this->output_stream_buff_size = (unsigned int) buffer_size2;
    this->expected_buff = (char*) buffer3;
    this->expected_buff_size = buffer_size3;

    this->input_stub = new stub_input_stream();
    this->output_stub = new stub_output_stream((char*) buffer2, buffer_size2);
    this->connectable_stub = new stub_connectable();
    this->serverIp = new char[strlen(SERVER_IP) + 1];
    strcpy(this->serverIp, SERVER_IP);
    this->serverPort = new char[strlen(SERVER_PORT) + 1];
    strcpy(this->serverPort, SERVER_PORT);

    buffer_tools::init((char*) buffer, buffer_size, '\0');

    //build sut
    this->sut = new edf_controller((const input_stream*) this->input_stub,
                                   (const output_stream*) this->output_stub,
                                   (const connectable*) this->connectable_stub,
                                   (const char*) this->serverIp,
                                   (const char*) this->serverPort,
                                   buffer,
                                   buffer_size);

}

void tests_edf_controller::test_RUN() {
    const unsigned int input_size = 6;
    int input_data[input_size] = {
            LLT_START_FRAME_TAG, 'a', 'b', 'c', 'd', LLT_END_FRAME_TAG };
    char output_data_str[] = "EDF=abcd%03%00\n";

    this->input_stub->set_read_values(input_data, input_size);

    // cycle 1 : connected
    // setup
    this->connectable_stub->set_connexion(CONNECTED);
    this->output_stub->reset();
    strcpy(this->expected_buff, EXPECTED_TRAME_FIRST_PART);
    strcat(this->expected_buff, output_data_str);
    // exercize
    this->sut->run();
    // check
    this->str_checker->str_are_equals(this->expected_buff, this->output_stream_buff, "cycle 1");

    // cycle 2 : not connected
    this->input_stub->reset();
    this->output_stub->reset();
    this->connectable_stub->set_connexion(NOT_CONNECTED);
    // exercize
    this->sut->run();
    // check
    this->str_checker->str_are_equals("", this->output_stream_buff, "cycle 2");

    // cycle 3 : re-connected
    this->input_stub->reset();
    this->output_stub->reset();
    this->connectable_stub->set_connexion(CONNECTED);
    // exercize
    this->sut->run();
    // check
    this->str_checker->str_are_equals(this->expected_buff, this->output_stream_buff, "cycle 3");
}

void tests_edf_controller::run() {
//assert(sut != NULL);
    test_RUN();
}

tests_edf_controller::~tests_edf_controller() {
    delete (this->sut);
    delete (this->input_stub);
    delete (this->output_stub);
    delete (this->connectable_stub);
    delete (this->serverIp);
    delete (this->serverPort);
}
