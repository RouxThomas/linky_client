#include <assert.h>
#include "edf_reader_impl.h"

edf_reader_impl::edf_reader_impl(const input_stream* inputStream, const encoder* an_encoder)
        : inputStream((input_stream*) inputStream), an_encoder((encoder*) an_encoder) {
    assert(inputStream != NULL && an_encoder != NULL);
}

edf_reader_impl::~edf_reader_impl() {
}

bool edf_reader_impl::read() {
    bool is_frame_received = false;
    char charIn = 0;

    if (this->inputStream->available() && (this->inputStream->read() & 0x7F) == START_FRAME_TAG) {
        while (charIn != END_FRAME_TAG) {

            if (this->inputStream->available()) {
                charIn = this->inputStream->read() & 0x7F;

                if (charIn != INTERRUPT_TAG && charIn != START_FRAME_TAG) {
                    this->an_encoder->encode(charIn);
                }
            }
        }
        this->an_encoder->encode('\0');
        is_frame_received = true;
    }

    return is_frame_received;
}

