#ifndef CONNECTABLE_H_
#define CONNECTABLE_H_

#include <stdint.h>

class connectable {
public:

    virtual ~connectable() {
    }
    ;

    virtual uint8_t connected() = 0;
    // PRE  : N/A
    // POST : return 0 if not connected, != 0 otherwise

    virtual int connect(const char *host, uint16_t port) =0;
    // PRE  : not null inputs
    // POST : return 1 if connected, != 0 otherwise

    virtual void stop() = 0;
    // PRE  : N/A
    // POST : connection is stopped
};

#endif /* CONNECTABLE_H_ */
