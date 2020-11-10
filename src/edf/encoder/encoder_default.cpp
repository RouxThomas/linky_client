#include "encoder_default.h"

#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "encoder.h"
#include "buffer_tools.h"

encoder_default::encoder_default(const char* buff_to_encode,
                                 const unsigned int max_buffer_size_in_bytes)
        : buff_to_encode(buff_to_encode), max_buffer_size_in_bytes(max_buffer_size_in_bytes) {
    assert(buff_to_encode != NULL
           && max_buffer_size_in_bytes > 0
           && max_buffer_size_in_bytes > strlen(ENCODER_NOT_ENOUGH_FREE_SPACE_MSG));
    reset();
}

encoder_default::~encoder_default() {
}

void encoder_default::reset() {
    buffer_tools::init((char*) this->buff_to_encode, this->max_buffer_size_in_bytes, '\0');
    this->buff_cursor = (char*) this->buff_to_encode;
    this->is_buffer_overflow = false;
}

void encoder_default::encode(char to_encode) {
    bool is_enough_free_space = !this->is_buffer_overflow && ((this->buff_cursor + 1 - this->buff_to_encode)
                                < (int) this->max_buffer_size_in_bytes) ? true : false;

    if (is_enough_free_space) {
        *this->buff_cursor = to_encode;
        this->buff_cursor++;
    } else {
        if (!this->is_buffer_overflow) {
            this->reset();
            strcpy((char*) this->buff_to_encode, ENCODER_NOT_ENOUGH_FREE_SPACE_MSG);
            this->is_buffer_overflow = true;
        }
    }
}
