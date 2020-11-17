#ifndef OUTPUT_STREAM_ADAPTER_H_
#define OUTPUT_STREAM_ADAPTER_H_

#include <Stream.h>
#include "output_stream.h"

class output_stream_adapter: public output_stream {
public:

    output_stream_adapter(Stream* stream);
    virtual ~output_stream_adapter();

    virtual size_t write(const char* to_write);
    virtual size_t writeln(const char* to_write);

private:
    Stream* stream;
};

#endif /* URI_ENCODER_H_ */
