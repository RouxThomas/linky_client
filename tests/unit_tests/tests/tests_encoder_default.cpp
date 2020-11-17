#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include "buffer_tools.h"
#include "tests_encoder_default.h"

tests_encoder_default::tests_encoder_default(const char* test_name,
                                             const char* buffer,
                                             const int buffer_size,
                                             checker_str* str_checker)
        : test(test_name) {
    const int to_encode_size = strlen(ENCODER_NOT_ENOUGH_FREE_SPACE_MSG) + 1;
    assert(str_checker != NULL && to_encode_size < buffer_size);

    this->str_checker = str_checker;

    this->to_encode = (char*) buffer;
    this->to_encode_size = to_encode_size;

    //build sut
    this->sut = new encoder_default(this->to_encode, to_encode_size);
}

void tests_encoder_default::test_ENCODE() {
    buffer_tools::init(this->to_encode, this->to_encode_size, '\0');

    assert(this->sut != NULL);
    // testcase 1 : add 't'
    this->sut->encode('t');
    // test
    this->str_checker->str_are_equals("t", this->to_encode, "testcase 1");

    // testcase 2 : add 'z'
    this->sut->encode('z');
    // test
    this->str_checker->str_are_equals("tz", this->to_encode, "testcase 2");

    // testcase 3 : add 'm'
    this->sut->encode('m');
    // test
    this->str_checker->str_are_equals("tzm", this->to_encode, "testcase 3");

    // testcase 4 : add some 'p' but not enough free space in buffer
    for (int i = 0; i < this->to_encode_size + 1; i++) {
        this->sut->encode('p');
    }
    this->str_checker->str_are_equals(ENCODER_NOT_ENOUGH_FREE_SPACE_MSG,
                                      this->to_encode,
                                      "testcase 4");

    // testcase 5 : reset
    this->sut->reset();
    // test
    this->str_checker->str_are_equals("", this->to_encode, "testcase 5");


}

void tests_encoder_default::run() {
    assert(sut != NULL);
    test_ENCODE();
}

tests_encoder_default::~tests_encoder_default() {
    delete (this->sut);
}
