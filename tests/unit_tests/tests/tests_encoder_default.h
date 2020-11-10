#ifndef TESTS_ENCODER_DEFAULT_H_
#define TESTS_ENCODER_DEFAULT_H_

#include "test.h"
#include "checker_bool.h"
#include "checker_str.h"
#include "encoder_default.h"

class tests_encoder_default: public test {
public:
    tests_encoder_default(const char* test_name,
                          const char* buffer,
                          const int buffer_size,
                          checker_bool* bool_checker,
                          checker_str* str_checker);
    virtual ~tests_encoder_default();

    void run();

private:
    checker_str* str_checker;
    checker_bool* bool_checker;

    char* to_encode;
    int to_encode_size;
    encoder_default* sut;

    void test_ENCODE();
};

#endif /* end of TESTS_ENCODER_DEFAULT_H_ */
