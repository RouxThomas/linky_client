#ifndef STUB_CONNECTABLE_H_
#define STUB_CONNECTABLE_H_

#include <stdint.h>

#include "connectable.h"

class stub_connectable: public connectable {
public:

    stub_connectable();
    virtual ~stub_connectable();

    virtual uint8_t connected();
    virtual int connect(const char *host, uint16_t port);
    virtual void stop();

    void set_connexion(uint8_t connexion_status);
private:
    uint8_t connexion_status;
};

#endif /* STUB_CONNECTABLE_H_ */
