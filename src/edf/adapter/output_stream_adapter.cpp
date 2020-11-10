#include <assert.h>

#include "output_stream_adapter.h"

output_stream_adapter::output_stream_adapter(Stream* stream)
        : stream(stream) {
    assert(stream != NULL);
}

output_stream_adapter::~output_stream_adapter() {
}

size_t output_stream_adapter::write(const char* to_write) {
    return this->stream->print(to_write);
}

size_t output_stream_adapter::writeln(const char* to_write) {
    return this->stream->println(to_write);
}

