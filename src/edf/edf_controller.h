#ifndef EDF_CONTROLLER_H_
#define EDF_CONTROLLER_H_

#include "edf_reader.h"
#include "encoder.h"
#include "request.h"
#include "request_transmitter.h"
#include "input_stream.h"
#include "output_stream.h"
#include "uri_post_request.h"
#include "connectable.h"
#include "encoder_default.h"

class edf_controller {
public:
    edf_controller(const input_stream* inputStream,
                   const output_stream* outputStream,
                   const connectable* Connectable,
                   const char* serverIp,
                   const char* serverPort,
                   const char* data_buffer,
                   const unsigned int encode_buff_size);
    // REQ : not null inputs
    // ENS : object is ready initialized

    virtual ~edf_controller();

    void run();
    // REQ : N/A
    // ENS : cyclic entry point

private:
    edf_reader* reader;
    encoder* an_encoder;
    request_transmitter* transmitter;
    encoder_default* default_encoder;
    uri_post_request* post_request;
    char* data_buffer;

};

#endif /* DECODER_STATE_FACTORY_H_ */
