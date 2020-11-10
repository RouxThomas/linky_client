#ifndef CONNECTABLE_ADAPTER_H_
#define CONNECTABLE_ADAPTER_H_

#include <Client.h>
#include "connectable.h"

class connectable_adapter: public connectable {
public:

    connectable_adapter(Client* client);
    virtual ~connectable_adapter();

    virtual uint8_t connected();
    virtual int connect(const char *host, uint16_t port);
    virtual void stop();

private:
    Client* client;
};

#endif /* CONNECTABLE_ADAPTER_H_ */
