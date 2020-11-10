#ifndef STUB_CLIENT_H_
#define STUB_CLIENT_H_

#include "Client.h"

class stub_client: public Client {
public:

    stub_client();
    virtual ~stub_client();

    virtual int connect(IPAddress ip, uint16_t port);
    virtual int connect(const char *host, uint16_t port);
    virtual size_t write(uint8_t);
    virtual size_t write(const uint8_t *buf, size_t size);
    virtual int available();
    virtual int read();
    virtual int read(uint8_t *buf, size_t size);
    virtual int peek();
    virtual void flush();
    virtual void stop();
    virtual uint8_t connected();
    virtual operator bool();

    void set_available(int how_many_available);
    void set_read_value(int read_value);
    void set_peek_value(int peek_value);

private:
    int how_many_available;
    int read_value;
    int peek_value;
};

#endif /* STUB_CLIENT_H_ */
