#ifndef URI_ENCODER_H_
#define URI_ENCODER_H_

#include "encoder.h"

class uri_encoder: public encoder {
public:

    uri_encoder(encoder* an_encoder);
    // PRE  : not null an_encoder
    // POST : object is initialized

    virtual ~uri_encoder();

    virtual void reset();

    virtual void encode(char to_decode);

private:
    encoder* an_encoder;
    char* buff_conv;
};

#endif /* URI_ENCODER_H_ */
