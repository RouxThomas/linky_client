#ifndef OUTPUT_STREAM_H_
#define OUTPUT_STREAM_H_

class output_stream {
public:

    virtual ~output_stream() {
    }
    ;

    virtual size_t write(const char* to_write)=0;
    // PRE  : not null an_encoder
    // POST : to_print is printed

    virtual size_t writeln(const char* to_write)=0;
    // PRE  : not null an_encoder
    // POST : to_print is printed with an end of line
};

#endif /* OUTPUT_STREAM_H_ */
