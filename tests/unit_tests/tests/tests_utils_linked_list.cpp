#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include "linked_list.h"
#include "tests_utils_linked_list.h"

tests_utils_linked_list::tests_utils_linked_list(const char* test_name, checker_int* int_checker)
        : test(test_name) {
    assert(int_checker != NULL);
    this->int_checker = int_checker;
    this->sut = new linked_list();
}

tests_utils_linked_list::~tests_utils_linked_list() {
    delete (this->sut);
}

void tests_utils_linked_list::tests_utils_linked_list_default_NB_ELEMENTS() {
    assert(sut != NULL);
    char msg[] = "test : default nb elements";
    this->int_checker->int_are_equals(sut->nb_elem(), 0, msg);
}

/* messages are static to limit stack load */
static char msgTestNbElement1[] = "test : nb element with 1 item added";
static char msgTestNbElement2[] = "test : nb element with 2 item added";
static char msgTestNbElement3[] = "test : nb element with 3 item added";
static char msgTest1[] = "test : check 1st added item";
static char msgTest2[] = "test : check 2nd added item";
static char msgTest3[] = "test : check 3th added item";
static char msgTest4[] = "test : check insert item at index 1";
static char msgTest5[] = "test : check insert item at last index";
static char msgTest6[] = "test : check remove item at index 1";
static char msgTest7[] = "test : check remove item at index 2";
static char msgTest8[] = "test : check remove last item";

void tests_utils_linked_list::tests_utils_linked_list_ADD_and_INSERT_and_NB_ELEMENT_REMOVE() {
    assert(sut != NULL);
    void* getValue = NULL;

    int elem1 = 10;
    int elem2 = 20;
    int elem3 = 30;
    int elem4 = 40;
    int elem5 = 50;

    // expected [ 10 ]
    sut->append((void*) &elem1);
    this->int_checker->int_are_equals(1, (int) sut->nb_elem(), msgTestNbElement1);

    // expected [ 10 20 ]
    sut->append((void*) &elem2);
    this->int_checker->int_are_equals(2, (int) sut->nb_elem(), msgTestNbElement2);

    // expected [ 10 20 30 ]
    sut->append((void*) &elem3);
    this->int_checker->int_are_equals(3, (int) sut->nb_elem(), msgTestNbElement3);

    getValue = sut->get(1);
    assert(getValue != NULL);
    this->int_checker->int_are_equals(elem1, *(int*) getValue, msgTest1);

    getValue = sut->get(2);
    assert(getValue != NULL);
    this->int_checker->int_are_equals(elem2, *(int*) getValue, msgTest2);

    getValue = sut->get(3);
    assert(getValue != NULL);
    this->int_checker->int_are_equals(elem3, *(int*) getValue, msgTest3);

    // expected [ 40 10 20 30 ]
    sut->insert_before(1, (void*) &elem4);
    getValue = sut->get(1);
    assert(getValue != NULL);
    this->int_checker->int_are_equals(elem4, *(int*) getValue, msgTest4);
    getValue = sut->get(2);
    assert(getValue != NULL);
    this->int_checker->int_are_equals(elem1, *(int*) getValue, msgTest4);

    // expected [ 40 10 20 50 30 ]
    sut->insert_before(sut->nb_elem(), (void*) &elem5);
    getValue = sut->get(sut->nb_elem());
    assert(getValue != NULL);
    this->int_checker->int_are_equals(elem3, *(int*) getValue, msgTest5);
    getValue = sut->get(sut->nb_elem() - 1);
    assert(getValue != NULL);
    this->int_checker->int_are_equals(elem5, *(int*) getValue, msgTest5);

    // expected [ 10 20 50 30 ]
    sut->remove(1);
    this->int_checker->int_are_equals(4, sut->nb_elem(), msgTest6);
    getValue = sut->get(1);
    assert(getValue != NULL);
    this->int_checker->int_are_equals(elem1, *(int*) getValue, msgTest6);

    sut->remove(2);
    this->int_checker->int_are_equals(3, sut->nb_elem(), msgTest7);
    getValue = sut->get(2);
    assert(getValue != NULL);
    this->int_checker->int_are_equals(elem5, *(int*) getValue, msgTest7);

    sut->remove(sut->nb_elem());
    this->int_checker->int_are_equals(2, sut->nb_elem(), msgTest7);
    getValue = sut->get(sut->nb_elem());
    assert(getValue != NULL);
    this->int_checker->int_are_equals(elem5, *(int*) getValue, msgTest8);

}

void tests_utils_linked_list::run() {
    assert(sut != NULL);
    tests_utils_linked_list_default_NB_ELEMENTS();
    tests_utils_linked_list_ADD_and_INSERT_and_NB_ELEMENT_REMOVE();
}

