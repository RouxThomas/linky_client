#ifndef REQUEST_H_
#define REQUEST_H_

class request {
public:
    virtual ~request() {
    }
    ;

    virtual void transmit()=0;
    // REQ : N/A
    // ENS : request is transmitted to remote

};

#endif /* EDF_REQUEST_TRANSMITTER_H_ */
