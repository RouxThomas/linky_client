#include "stub_input_stream.h"
#include <assert.h>
#include <stdlib.h>

stub_input_stream::stub_input_stream() {
    this->read_values = 0;
    this->nb_values = 0;
    this->read_values_offset = 0;
    this->peek_value = 0;
}

int stub_input_stream::available() {
    const int result = nb_values - read_values_offset;
    assert(result >= 0);
    return result;
}

int stub_input_stream::read() {
    assert(available() > 0);
    const int value = *(read_values + read_values_offset);
    read_values_offset++;
    return value;
}

void stub_input_stream::set_read_values(int* read_values, unsigned int nb_values) {
    assert(read_values != 0 && nb_values >= 0);
    this->read_values = read_values;
    this->nb_values = nb_values;
}

void stub_input_stream::reset() {
    read_values_offset = 0;
}

stub_input_stream::~stub_input_stream() {
}
