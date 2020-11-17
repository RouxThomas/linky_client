#ifndef EDF_READER_H_
#define EDF_READER_H_

#define START_FRAME_TAG 0x02
#define END_FRAME_TAG   0x03
#define INTERRUPT_TAG   0x04

class edf_reader {
public:

    virtual ~edf_reader() {
    }
    ;

    virtual bool read()=0;
    // REQ : N/A
    // ENS : true is returned if a trame is received, false otherwise
};

#endif /* EDF_READER_H_ */
