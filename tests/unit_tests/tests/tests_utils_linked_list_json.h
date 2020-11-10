#ifndef TESTS_UTILS_LINKED_LIST_JSON_H
#define TESTS_UTILS_LINKED_LIST_JSON_H

#include "test.h"
#include "checker_str.h"
#include "checker_int.h"
#include "int_to_string.h"
#include "checker_json_item.h"
#include "json_item_to_string.h"
#include "linked_list_json.h"

class tests_utils_linked_list_json: public test {
public:
    tests_utils_linked_list_json(const char* test_name,
                                 int_to_string* int_to_str,
                                 checker_str* str_checker,
                                 checker_int* int_checker,
                                 checker_json_item* json_item_checker,
                                 json_item_to_string* json_to_str);
    virtual ~tests_utils_linked_list_json();
    void run();

private:
    linked_list_json * sut;
    checker_str* str_checker;
    checker_int* int_checker;
    checker_json_item* json_item_checker;

    int_to_string* int_to_str;
    json_item_to_string* json_item_to_str;

    void tests_utils_linked_list_json_NB_ELEMENT_ADD_and_INSERT_and_NB_ELEMENT_REMOVE();
};

#endif
