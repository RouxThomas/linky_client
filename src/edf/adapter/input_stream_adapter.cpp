#include "input_stream_adapter.h"

#include <stdlib.h>
#include <assert.h>

input_stream_adapter::input_stream_adapter(Stream* stream)
        : stream(stream) {
    assert(stream != NULL);
}

input_stream_adapter::~input_stream_adapter() {
}

int input_stream_adapter::available() {
    return this->stream->available();
}

int input_stream_adapter::read() {
    return this->stream->read();
}

