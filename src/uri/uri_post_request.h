#ifndef URI_POST_REQUEST_H_
#define URI_POST_REQUEST_H_

#include <stdint.h>
#include "output_stream.h"
#include "encoder.h"

class uri_post_request {
public:

    uri_post_request(const char* header_param_page,
                     const char* header_param_host,
                     const char* header_param_user_agent,
                     const char* header_param_content_type,
                     const char* request_body,
                     const output_stream* outputStream);
    // PRE  : all inputs contents shall be URI string encoding compliant.
    // POST : object is ready for use

    virtual ~uri_post_request();

    virtual void transmit();
    // PRE  : N/A
    // POST : encoding POST request using an_encoder

private:
    const char* header_param_page;
    const char* header_param_host;
    const char* header_param_user_agent;
    const char* header_param_content_type;
    const char* request_body;
    output_stream* outputStream;
};

#endif /* URI_POST_REQUEST_H_ */
