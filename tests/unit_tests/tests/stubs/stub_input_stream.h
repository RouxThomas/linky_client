#ifndef STUB_INPUT_STREAM_H_
#define STUB_INPUT_STREAM_H_

#include <stdlib.h>
#include "input_stream.h"

class stub_input_stream : public input_stream {
public:

    stub_input_stream();
    virtual ~stub_input_stream();

    virtual int available();
    virtual int read();

    void reset();
    void set_read_values(int* read_values, unsigned int nb_values);

private:
    int* read_values;
    int  nb_values;
    int  read_values_offset;
    int  peek_value;
};

#endif /* STUB_INPUT_STREAM_H_ */
