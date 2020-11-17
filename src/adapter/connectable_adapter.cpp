#include "connectable_adapter.h"

#include <stdlib.h>
#include <assert.h>

connectable_adapter::connectable_adapter(Client* client)
        : client(client) {
    assert(client != NULL);
}

connectable_adapter::~connectable_adapter() {
}

uint8_t connectable_adapter::connected() {
    return this->client->connected();
}

int connectable_adapter::connect(const char *host, uint16_t port) {
    return this->client->connect(host, port);
}

void connectable_adapter::stop() {
    return this->client->stop();
}

