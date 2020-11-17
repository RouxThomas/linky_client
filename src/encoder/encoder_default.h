#ifndef ENCODER_DEFAULT_H_
#define ENCODER_DEFAULT_H_

#include <stdlib.h>
#include "encoder.h"

class encoder_default: public encoder {
public:

    encoder_default(const char* buff_to_encode, const unsigned int max_buffer_size_in_bytes);
    // REQ : max_buffer_size_in_bytes > strlen(ENCODER_NOT_ENOUGH_FREE_SPACE_MSG)
    // ENS : object is ready for use

    virtual ~encoder_default();

    virtual void reset();

    virtual void encode(char to_decode);

private:
    const char* buff_to_encode = NULL;
    const unsigned int max_buffer_size_in_bytes = 0;
    char* buff_cursor = NULL;
    bool is_buffer_overflow = false;
};

#endif /* ENCODER_DEFAULT_H_ */
