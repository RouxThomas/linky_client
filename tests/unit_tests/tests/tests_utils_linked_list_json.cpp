#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include "linked_list_json.h"
#include "tests_utils_linked_list_json.h"

tests_utils_linked_list_json::tests_utils_linked_list_json(const char* test_name,
                                                           int_to_string* int_to_str,
                                                           checker_str* str_checker,
                                                           checker_int* int_checker,
                                                           checker_json_item* json_item_checker,
                                                           json_item_to_string* json_to_str)
        : test(test_name) {
    assert(str_checker != NULL && int_checker != NULL && json_item_checker != NULL);
    this->str_checker = str_checker;
    this->int_checker = int_checker;
    this->json_item_checker = json_item_checker;
    this->int_to_str = int_to_str;
    this->json_item_to_str = json_to_str;
    this->sut = new linked_list_json();
}

tests_utils_linked_list_json::~tests_utils_linked_list_json() {
    delete (this->sut);
}

/* messages are static to limit stack load */
static char msgTestAdded1Elem[] = "test : 1 item added";
static char msgTestNbElement1[] = "test : nb element with 1 item added";
static char msgTestInsertBefore[] = "test : insert_before item 1";
static char msgTestRemove[] = "test : remove item 1";
static char msgTestAdded1ElemJson[] = "test : 1 item added (json)";

void tests_utils_linked_list_json::tests_utils_linked_list_json_NB_ELEMENT_ADD_and_INSERT_and_NB_ELEMENT_REMOVE() {
    assert(sut != NULL);

    int elem0_element = 0;
    int elem1_element = 1;
    int elem2_element = 2;
    linked_list_json::json_item elem0 = {
            (void*) &elem0_element, this->int_to_str };
    linked_list_json::json_item elem1 = {
            (void*) &elem1_element, this->int_to_str };

    linked_list_json::json_item elem2 = {
            (void*) &elem2_element, this->int_to_str };
    linked_list_json::json_item elem3 = {
            (void*) &elem2, this->json_item_to_str };

    // expected [ elem1 ]
    sut->append(&elem1);
    this->json_item_checker->json_item_are_equals(&elem1,
                                                  (linked_list_json::json_item*) sut->get(1),
                                                  msgTestAdded1Elem);

    this->int_checker->int_are_equals(1, sut->nb_elem(), msgTestNbElement1);

    // expected [ elem0 elem1 ]
    sut->insert_before(1, &elem0);
    this->json_item_checker->json_item_are_equals(&elem0,
                                                  (linked_list_json::json_item*) sut->get(1),
                                                  msgTestInsertBefore);
    this->json_item_checker->json_item_are_equals(&elem1,
                                                  (linked_list_json::json_item*) sut->get(2),
                                                  msgTestInsertBefore);

    // expected [ elem1 ]
    sut->remove(1);
    this->json_item_checker->json_item_are_equals(&elem1,
                                                  (linked_list_json::json_item*) sut->get(1),
                                                  msgTestRemove);

    // expected [ elem1 elem3]
    sut->append(&elem3);
    this->json_item_checker->json_item_are_equals(&elem3,
                                                  (linked_list_json::json_item*) sut->get(2),
                                                  msgTestAdded1ElemJson);
}

void tests_utils_linked_list_json::tests_utils_linked_list_json::run() {
    assert(this->sut != NULL);
    tests_utils_linked_list_json_NB_ELEMENT_ADD_and_INSERT_and_NB_ELEMENT_REMOVE();
}

