#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "buffer_tools.h"
#include "stub_output_stream.h"

stub_output_stream::stub_output_stream(char* buffer, unsigned int buffer_size)
        : buffer(buffer), buffer_size(buffer_size) {
    assert(buffer != NULL && buffer_size > 0);
    reset();
}

size_t stub_output_stream::write(const char* to_write) {
    strcat((char*) buffer, (char*) to_write);
    return strlen(to_write);
}

size_t stub_output_stream::writeln(const char* to_write) {
    write(to_write);
    strcat((char*) buffer, "\n");
    return strlen(to_write) + 1;
}

void stub_output_stream::reset() {
    buffer_tools::init((char*) buffer, buffer_size, '\0');
}

stub_output_stream::~stub_output_stream() {
}
