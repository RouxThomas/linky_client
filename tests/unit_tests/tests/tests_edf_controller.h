#ifndef TESTS_EDF_CONTROLLER_H_
#define TESTS_EDF_CONTROLLER_H_

#include "test.h"
#include "checker_str.h"
#include "edf_controller.h"

#include "stub_input_stream.h"
#include "stub_output_stream.h"
#include "stub_connectable.h"

class tests_edf_controller: public test {
public:
    tests_edf_controller(const char* test_name,
                         const char* buffer,
                         const int buffer_size,
                         const char* buffer2,
                         const int buffer_size2,
                         const char* buffer3,
                         const int buffer_size3,
                         checker_str* str_checker);
    virtual ~tests_edf_controller();

    void run();

private:
    checker_str* str_checker;

    char* output_stream_buff;
    unsigned int output_stream_buff_size;
    char* expected_buff;
    unsigned int expected_buff_size;
    stub_input_stream* input_stub;
    stub_output_stream* output_stub;
    stub_connectable* connectable_stub;
    char* serverIp;
    char* serverPort;

    edf_controller* sut;

    void test_RUN();
};

#endif /* end of TESTS_EDF_CONTROLLER_H_ */
