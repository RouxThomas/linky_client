#ifndef TESTS_POST_REQUEST_ENCODER_H_
#define TESTS_POST_REQUEST_ENCODER_H_

#include "test.h"
#include "checker_str.h"
#include "uri_post_request.h"

class tests_uri_post_request: public test {
public:
    tests_uri_post_request(const char* test_name,
                           const char* buffer,
                           const uint16_t buffer_size,
                           const char* buffer2,
                           const uint16_t buffer2_size,
                           checker_str* str_checker);

    virtual ~tests_uri_post_request();
    void run();

private:
    checker_str* str_checker;

    const char* expected_request = NULL;
    const char* computed_request = NULL;
    const output_stream* an_printer = NULL;
    uri_post_request* sut = NULL;

    void build_expected_request(char* dest_buff, char* body, int data_size);
    void test_TRANSMIT();
};

#endif /* end of TESTS_POST_REQUEST_ENCODER_H_ */
