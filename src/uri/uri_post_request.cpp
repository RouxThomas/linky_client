#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>

#include "encoder_default.h"
#include "uri_encoder.h"
#include "uri_post_request.h"

#define MAX_ASCII_CHAR_SIZE_IN_BITE 4

uri_post_request::uri_post_request(const char* header_param_page,
                                   const char* header_param_host,
                                   const char* header_param_user_agent,
                                   const char* header_param_content_type,
                                   const char* request_body,
                                   const output_stream* outputStream)
        :
          header_param_page(header_param_page),
          header_param_host(header_param_host),
          header_param_user_agent(header_param_user_agent),
          header_param_content_type(header_param_content_type),
          request_body(request_body){
    assert(header_param_page != NULL
           && header_param_host != NULL
           && header_param_user_agent != NULL
           && header_param_content_type != NULL
           && request_body != NULL
           && outputStream != NULL);
    this->outputStream = (output_stream*) outputStream;
}

uri_post_request::~uri_post_request() {
}

void uri_post_request::transmit() {
    const unsigned int request_body_size = strlen(request_body);
    assert(request_body_size > 0);
    char body_size[10] = {
            '\0' };
    snprintf(body_size, 10, "%d", request_body_size);

    this->outputStream->write("POST ");
    this->outputStream->write((const char *) header_param_page);
    this->outputStream->writeln(" HTTP/1.1");

    this->outputStream->write("Host: ");
    this->outputStream->writeln(header_param_host);

    this->outputStream->write("User-Agent: ");
    this->outputStream->writeln(header_param_user_agent);

    this->outputStream->writeln("Connection: close");

    this->outputStream->write("Content-Type: ");
    this->outputStream->write(header_param_content_type);
    this->outputStream->writeln(";");

    this->outputStream->write("Content-Length: ");
    this->outputStream->writeln(body_size);

    this->outputStream->writeln("");

    this->outputStream->writeln(request_body);
}

