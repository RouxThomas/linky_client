#ifndef STUB_OUTPUT_STREAM_H_
#define STUB_OUTPUT_STREAM_H_

#include <stdlib.h>

#include "output_stream.h"

class stub_output_stream : public output_stream {
public:

    stub_output_stream(char* buffer,
                       unsigned int buffer_size);
    virtual ~stub_output_stream();

    virtual size_t write(const char* to_write);
    virtual size_t writeln(const char* to_write);


    virtual void reset();
private:
    const char* buffer;
    const unsigned int buffer_size;
};

#endif /* STUB_OUTPUT_STREAM_H_ */
