#ifndef TEST_H_
#define TEST_H_

#include "runnable.h"

class test: public runnable {
public:

    test(const char* test_name);
    virtual ~test();

    virtual char* name();
    // PRE  : not null res
    // POST : N/A

private:
    char* test_name;
};

#endif
