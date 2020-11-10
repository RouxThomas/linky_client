#ifndef TESTS_UTILS_LINKED_LIST_CHAR_H
#define TESTS_UTILS_LINKED_LIST_CHAR_H

#include "linked_list_char.h"
#include "test.h"
#include "checker_str.h"
#include "checker_int.h"

class tests_utils_linked_list_char: public test {
public:
    tests_utils_linked_list_char(const char* test_name,
                                 checker_str* str_checker,
                                 checker_int* int_checker);
    ~tests_utils_linked_list_char();

    void run();

private:
    linked_list_char * sut;
    checker_str* str_checker;
    checker_int* int_checker;

    void tests_utils_linked_list_char_NB_ELEMENT_ADD_and_INSERT_and_NB_ELEMENT_REMOVE();
};

#endif
