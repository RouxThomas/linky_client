
#ifndef EDF_READER_IMPL_H_
#define EDF_READER_IMPL_H_

#include "../streams/input_stream.h"
#include "encoder.h"
#include "edf_reader.h"

class edf_reader_impl : public edf_reader {
public:
	edf_reader_impl(const input_stream* inputStream,
			        const encoder* an_encoder);
	// REQ : not null inputs
	// ENS : Object is initialized

	virtual ~edf_reader_impl();

	virtual bool read();

private:
	input_stream* inputStream;
	encoder* an_encoder;
};

#endif /* EDF_READER_IMPL_H_ */
