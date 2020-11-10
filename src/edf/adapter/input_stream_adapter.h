#ifndef INPUT_STREAM_ADAPTER_H_
#define INPUT_STREAM_ADAPTER_H_

#include <Stream.h>
#include "input_stream.h"

class input_stream_adapter : public input_stream {
public:

    input_stream_adapter(Stream* stream);
    virtual ~input_stream_adapter();

    virtual int available();
    virtual int read();

private:
    Stream* stream;
};

#endif /* INPUT_STREAM_ADAPTER_H_ */
