#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>

#include "edf_controller.h"

#include "edf_reader_impl.h"
#include "request_transmitter.h"
#include "encoder.h"
#include "encoder_default.h"
#include "uri_encoder.h"

edf_controller::edf_controller(const input_stream* inputStream,
                               const output_stream* outputStream,
                               const connectable* Connectable,
                               const char* serverIp,
                               const char* serverPort,
                               const char* data_buffer,
                               const unsigned int encode_buff_size) {
    const char post_param[] = "EDF=";
    const unsigned int post_param_size = strlen(post_param);

    assert(inputStream != NULL
           && outputStream != NULL
           && Connectable != NULL
           && serverIp != NULL
           && serverPort != NULL
           && data_buffer != NULL
           && encode_buff_size > strlen(ENCODER_NOT_ENOUGH_FREE_SPACE_MSG) + post_param_size
           && encode_buff_size - post_param_size > 0);

    this->data_buffer = (char*) data_buffer;

    strcpy((char*) this->data_buffer, (char*) post_param);

    this->default_encoder = new encoder_default(data_buffer + post_param_size,
                                                encode_buff_size - post_param_size);

    // TODO : manque le port pour le header de la request post
    this->post_request = new uri_post_request("/",
                                              serverIp,
                                              "arduino/edf",
                                              "application/x-www-form-urlencoded",
                                              data_buffer,
                                              outputStream);

    this->an_encoder = (encoder*) new uri_encoder((encoder*) default_encoder);
    this->reader = (edf_reader*) new edf_reader_impl(inputStream, this->an_encoder);
    this->transmitter = (request_transmitter*) new request_transmitter(Connectable,
                                                                       serverIp,
                                                                       serverPort,
                                                                       (request*) post_request);
}

edf_controller::~edf_controller() {
    delete (this->reader);
    delete (this->transmitter);
    delete (this->an_encoder);
    delete (this->default_encoder);
    delete (this->post_request);
}

void edf_controller::run() {
    // a new frame is received
    if (this->reader->read()) {
        this->transmitter->transmit();
        this->an_encoder->reset();
    }
}

