#ifndef TESTS_CHAR_ENCODER_URI_H_
#define TESTS_CHAR_ENCODER_URI_H_

#include "encoder_default.h"
#include "test.h"
#include "checker_int.h"
#include "checker_str.h"
#include "uri_encoder.h"

class tests_uri_encoder: public test {
public:
    tests_uri_encoder(const char* test_name,
                      const char* buffer,
                      const int buffer_size,
                      checker_int* int_checker,
                      checker_str* str_checker);
    virtual ~tests_uri_encoder();

    void run();

private:
    checker_str* str_checker;
    checker_int* int_checker;

    char* to_encode;
    encoder_default* encoder_stub;
    uri_encoder* sut;

    void test_ENCODE_unreserved_characters();
    void test_ENCODE_reserved_characters();
    void test_ENCODE_a_real_string();
};

#endif /* end of TESTS_CHAR_ENCODER_URI_H_ */
