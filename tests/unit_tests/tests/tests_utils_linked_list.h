#ifndef TESTS_UTILS_LINKED_LIST_H
#define TESTS_UTILS_LINKED_LIST_H

#include "linked_list.h"
#include "test.h"
#include "checker_int.h"

class tests_utils_linked_list: public test {
public:
    tests_utils_linked_list(const char* test_name, checker_int* int_checker);
    virtual ~tests_utils_linked_list();
    void run();

private:
    checker_int* int_checker;
    linked_list* sut;

    void tests_utils_linked_list_default_NB_ELEMENTS();
    void tests_utils_linked_list_ADD_and_INSERT_and_NB_ELEMENT_REMOVE();

};

#endif
