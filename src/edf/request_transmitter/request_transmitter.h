#ifndef REQUEST_TRANSMITTER_H_
#define REQUEST_TRANSMITTER_H_

#include "request.h"
#include "connectable.h"

class request_transmitter: public request {

public:
    request_transmitter(const connectable* Connectable,
                        const char* serverIp,
                        const char* serverPort,
                        const request* an_request);
    // REQ : not null inputs && serverPort > 0
    // ENS : object is ready for used

    virtual ~request_transmitter();

    virtual void transmit();

private:
    connectable* Connectable;
    const char* serverIp;
    const uint16_t serverPort;
    request* an_request;
};

#endif /* REQUEST_TRANSMITTER_H_ */
