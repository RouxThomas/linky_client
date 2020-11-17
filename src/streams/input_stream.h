#ifndef INPUT_STREAM_H_
#define INPUT_STREAM_H_

class input_stream {
public:
    virtual ~input_stream() {
    }
    ;

    virtual int available() = 0;
    // PRE  : N/A
    // POST : return the number of available data

    virtual int read() = 0;
    // PRE  : N/A
    // POST : return one data
};

#endif /* INPUT_STREAM_H_ */
