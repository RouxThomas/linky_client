#include "request_transmitter.h"

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <math.h>

request_transmitter::request_transmitter(const connectable* Connectable,
                                         const char* serverIp,
                                         const char* serverPort,
                                         const request* an_request)
        : serverIp(serverIp),
          serverPort((uint16_t) atoi(serverPort)),
          an_request((request*) an_request) {
    assert(Connectable != NULL && serverIp != NULL && (atoi(serverPort) < pow(2, 16)) // to secure atoi convertion
           && an_request != NULL);
    this->Connectable = (connectable*) Connectable;
}

void request_transmitter::transmit() {
    if (!this->Connectable->connected()) {
        Connectable->connect(this->serverIp, this->serverPort);
    }

    if (this->Connectable->connected()) {
        this->an_request->transmit();
        this->Connectable->stop();
    }
}

request_transmitter::~request_transmitter() {
}
