#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>

#include "buffer_tools.h"
#include "tests_uri_post_request.h"

#include "stubs/stub_output_stream.h"

#define REQUEST_PAGE                    "/"
#define REQUEST_HOST                    "192.168.1.50"
#define REQUEST_USER_AGENT              "arduino/edf"
#define REQUEST_CONTENT_TYPE            "application/x-www-form-urlencoded"
#define REQUEST_HEADER_BODY_SEPARATOR   ";"
#define REQUEST_BODYSIZE_BODY_SEPARATOR "\n"
#define REQUEST_BODY                    "this%20is%20the%20body"

tests_uri_post_request::tests_uri_post_request(const char* test_name,
                                               const char* buffer,
                                               const uint16_t buffer_size,
                                               const char* buffer2,
                                               const uint16_t buffer2_size,
                                               checker_str* str_checker)
        : test(test_name) {
    assert(buffer != NULL && buffer2 != NULL && str_checker != NULL);

    this->str_checker = str_checker;

    buffer_tools::init((char*) buffer, buffer_size, '\0');
    buffer_tools::init((char*) buffer2, buffer2_size, '\0');

    //build sut
    this->expected_request = buffer;
    this->computed_request = buffer2;

    this->an_printer = new stub_output_stream((char*) buffer2, buffer2_size);

    this->sut = new uri_post_request(REQUEST_PAGE,
                                     REQUEST_HOST,
                                     REQUEST_USER_AGENT,
                                     REQUEST_CONTENT_TYPE,
                                     REQUEST_BODY, (output_stream*) this->an_printer);
}

tests_uri_post_request::~tests_uri_post_request() {
    delete (this->sut);
}

void tests_uri_post_request::build_expected_request(char* dest_buff, char* body, int data_size) {
    char str_size[10] = {
            '\0' };
    snprintf(str_size, 10, "%d", data_size);

    strcpy(dest_buff, "POST ");
    strcat(dest_buff, REQUEST_PAGE);
    strcat(dest_buff, " HTTP/1.1\n");
    strcat(dest_buff, "Host: ");
    strcat(dest_buff, REQUEST_HOST);
    strcat(dest_buff, "\n");
    strcat(dest_buff, "User-Agent: ");
    strcat(dest_buff, REQUEST_USER_AGENT);
    strcat(dest_buff, "\n");
    strcat(dest_buff, "Connection: close\n");
    strcat(dest_buff, "Content-Type: ");
    strcat(dest_buff, REQUEST_CONTENT_TYPE);
    strcat(dest_buff, REQUEST_HEADER_BODY_SEPARATOR);
    strcat(dest_buff, "\n");
    strcat(dest_buff, "Content-Length: ");
    strcat(dest_buff, str_size);
    strcat(dest_buff, "\n");
    strcat(dest_buff, REQUEST_BODYSIZE_BODY_SEPARATOR);
    strcat(dest_buff, body);
    strcat(dest_buff, "\n");
}

void tests_uri_post_request::test_TRANSMIT() {
    assert(this->sut != NULL);

    // setup
    build_expected_request((char*) this->expected_request, REQUEST_BODY, strlen(REQUEST_BODY));

    // exercize
    this->sut->transmit();

    //checks
    this->str_checker->str_are_equals((char*) this->expected_request,
                                      (char*) this->computed_request,
                                      "transmit POST request");
}

void tests_uri_post_request::run() {
    assert(sut != NULL);
    test_TRANSMIT();
}
