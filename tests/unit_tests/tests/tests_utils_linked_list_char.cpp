#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include "linked_list_char.h"
#include "tests_utils_linked_list_char.h"

tests_utils_linked_list_char::tests_utils_linked_list_char(const char* test_name,
                                                           checker_str* str_checker,
                                                           checker_int* int_checker) : test (test_name) {
    assert(str_checker != NULL && int_checker != NULL);
    this->str_checker = str_checker;
    this->int_checker = int_checker;
    this->sut = new linked_list_char();
}

tests_utils_linked_list_char::~tests_utils_linked_list_char() {
    delete (this->sut);
}

/* messages are static to limit stack load */
static char msgTestAdded1Elem[] = "test : 1 item added";
static char msgTestNbElement1[] = "test : nb element with 1 item added";
static char msgTestInsertBefore[] = "test : insert_before item 1";
static char msgTestRemove[] = "test : remove item 1";

static char elem0[] = "elem0";
static char elem1[] = "elem1";

void tests_utils_linked_list_char::tests_utils_linked_list_char_NB_ELEMENT_ADD_and_INSERT_and_NB_ELEMENT_REMOVE() {
    assert(sut != NULL);

    // expected [ elem1 ]
    sut->append(elem1);
    this->str_checker->str_are_equals(elem1, (char*) sut->get(1), msgTestAdded1Elem);

    this->int_checker->int_are_equals(1, sut->nb_elem(), msgTestNbElement1);

    // expected [ elem0 elem1 ]
    sut->insert_before(1, elem0);
    this->str_checker->str_are_equals(elem0, (char*) sut->get(1), msgTestInsertBefore);
    this->str_checker->str_are_equals(elem1, (char*) sut->get(2), msgTestInsertBefore);

    // expected [ elem1 ]
    sut->remove(1);
    this->str_checker->str_are_equals(elem1, (char*) sut->get(1), msgTestRemove);

}

void tests_utils_linked_list_char::tests_utils_linked_list_char::run() {
    linked_list_char* sut = new linked_list_char();
    assert(sut != NULL);
    tests_utils_linked_list_char_NB_ELEMENT_ADD_and_INSERT_and_NB_ELEMENT_REMOVE();
}

