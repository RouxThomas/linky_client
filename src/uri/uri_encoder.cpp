#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include "uri_encoder.h"

#define MAX_ASCII_CHAR_SIZE_IN_BITE 4

uri_encoder::uri_encoder(encoder* an_encoder) {
    assert(an_encoder != NULL);
    this->an_encoder = an_encoder;
    this->buff_conv = new char[MAX_ASCII_CHAR_SIZE_IN_BITE];
    reset();
}

uri_encoder::~uri_encoder() {
}

void uri_encoder::reset() {
    this->an_encoder->reset();
}

bool is_unreserved_char(char to_encode) {
    return (to_encode >= '0' && to_encode <= '9')
           || (to_encode >= 'A' && to_encode <= 'Z')
           || (to_encode >= 'a' && to_encode <= 'z')
           || to_encode == '-'
           || to_encode == '.'
           || to_encode == '_'
           || to_encode == '~';
}

void uri_encoder::encode(char to_encode) {

    if (is_unreserved_char(to_encode)) {
        this->an_encoder->encode(to_encode);
    } else {
        snprintf(this->buff_conv, MAX_ASCII_CHAR_SIZE_IN_BITE, "%%%02X", to_encode);
        const int conv_size = strlen(this->buff_conv);
        for (int i = 0; i < conv_size; i++) {
            this->an_encoder->encode(this->buff_conv[i]);
        }
    }
}
