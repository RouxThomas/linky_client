#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "test.h"

test::test(const char* test_name) {
    assert(test_name != NULL);
    this->test_name = new char[strlen(test_name) + 1];
    strcpy(this->test_name, (char*) test_name);
}

char* test::name() {
    assert(this->test_name != NULL);
    return this->test_name;
}

test::~test() {
    delete (this->test_name);
}
