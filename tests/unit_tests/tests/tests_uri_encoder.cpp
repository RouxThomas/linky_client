#include "tests_uri_encoder.h"

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>

#define TEST_NB_UNRESERVED_CHAR      66
#define TEST_NB_RESERVED_CHAR        18

tests_uri_encoder::tests_uri_encoder(const char* test_name,
                                     const char* buffer,
                                     const int buffer_size,
                                     checker_int* int_checker,
                                     checker_str* str_checker)
        : test(test_name) {
    assert(int_checker
           != NULL&& str_checker != NULL && buffer_size > TEST_NB_UNRESERVED_CHAR && buffer_size > TEST_NB_RESERVED_CHAR);

    this->int_checker = int_checker;
    this->str_checker = str_checker;
    this->to_encode = (char*) buffer;

    //build sut
    this->encoder_stub = new encoder_default(buffer, buffer_size);
    this->sut = new uri_encoder(this->encoder_stub);
}

void tests_uri_encoder::test_ENCODE_unreserved_characters() {
    assert(this->sut != NULL);
    const char unreserved_characters[TEST_NB_UNRESERVED_CHAR] = {
            'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q',
            'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h',
            'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y',
            'z', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '-', '_', '.', '~' };

    for (int i = 0; i < TEST_NB_UNRESERVED_CHAR; i++) {
        this->sut->encode(unreserved_characters[i]);
        this->int_checker->int_are_equals((int) unreserved_characters[i],
                                          (int) *this->to_encode,
                                          "unreserved characters");
        this->sut->reset();
    }
}

void tests_uri_encoder::test_ENCODE_reserved_characters() {
    assert(this->sut != NULL);
    char reserved_characters[TEST_NB_RESERVED_CHAR] = {
            '!', '*', '\'', '(', ')', ';', ':', '@', '&', '=', '+', '$', ',', '/', '?', '#', '[',
            ']' };
    char* expected_converted_characters[TEST_NB_RESERVED_CHAR] = {
            "%21", "%2A", "%27", "%28", "%29", "%3B", "%3A", "%40", "%26", "%3D", "%2B", "%24",
            "%2C", "%2F", "%3F", "%23", "%5B", "%5D" };

    for (int i = 0; i < TEST_NB_RESERVED_CHAR; i++) {
        this->sut->encode(reserved_characters[i]);
        this->str_checker->str_are_equals(expected_converted_characters[i],
                                          this->to_encode,
                                          "reserved characters");
        this->sut->reset();
    }
}

void tests_uri_encoder::test_ENCODE_a_real_string() {
    char input[] =
            "ADCO 031528092771 D OPTARIF BASE 0 ISOUSC 60 < BASE 012102794 % PTEC TH.. $ IINST 004 [ IMAX 035 G PAPP 01010 # MOTDETAT 000000 B";
    char expected[] =
            "ADCO%20031528092771%20D%20OPTARIF%20BASE%200%20ISOUSC%2060%20%3C%20BASE%20012102794%20%25%20PTEC%20TH..%20%24%20IINST%20004%20%5B%20IMAX%20035%20G%20PAPP%2001010%20%23%20MOTDETAT%20000000%20B";
    const int input_size_in_bytes = strlen(input);

    for (int i = 0; i < input_size_in_bytes; i++) {
        this->sut->encode(input[i]);
    }

    this->str_checker->str_are_equals(expected, this->to_encode, "encode real input");
    this->sut->reset();
}

void tests_uri_encoder::run() {
    assert(sut != NULL);
    test_ENCODE_unreserved_characters();
    test_ENCODE_reserved_characters();
    test_ENCODE_a_real_string();
}

tests_uri_encoder::~tests_uri_encoder() {
    delete (this->sut);
}
