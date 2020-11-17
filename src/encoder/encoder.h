#ifndef ENCODER_H_
#define ENCODER_H_

#include <stdlib.h>

#define ENCODER_NOT_ENOUGH_FREE_SPACE_MSG "encoder : NOT ENOUGH FREE SPACE"

class encoder {
public:

    virtual ~encoder() {
    }
    ;

    virtual void reset()=0;
    // PRE  : N/A
    // POST : nb char encoded is set to 0

    virtual void encode(char to_decode)=0;
    // PRE  : N/A
    // POST : char is encoded
};

#endif /* CHAR_ENCODER_H_ */
