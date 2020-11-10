#include <stdlib.h>

#include "global_tests_suite.h"
#include "linked_list.h"
#include "bool_to_string.h"
#include "int_to_string.h"
#include "json_item_to_string.h"
#include "checker_bool.h"
#include "checker_int.h"
#include "checker_str.h"
#include "checker_json_item.h"
#include "text_test_reporter.h"

#include "tests_encoder_default.h"
#include "tests_utils_linked_list.h"
#include "tests_utils_linked_list_char.h"
#include "tests_utils_linked_list_json.h"
#include "tests_uri_encoder.h"
#include "tests_uri_post_request.h"
#include "tests_edf_controller.h"

#ifdef __cplusplus
extern "C" {
#else
#include <new.h>
#endif

#define VERBOSE true
#define NOT_VERBOSE false
#define BUFFER_SIZE_IN_BYTE 300

// C functions that are able to call C++ code

void run_global_tests_suite() {
    bool is_verbose = NOT_VERBOSE;
    text_test_reporter* test_report = new text_test_reporter();
    //-----------------------------------------------------
    bool_to_string* bool_to_str = new bool_to_string();
    int_to_string* int_to_str = new int_to_string();
    json_item_to_string* json_to_str = new json_item_to_string();
    //-----------------------------------------------------
    checker_bool* bool_check = new checker_bool(bool_to_str, test_report, is_verbose);
    checker_int* int_check = new checker_int(int_to_str, test_report, is_verbose);
    checker_json_item* json_item_check = new checker_json_item(json_to_str,
                                                               test_report,
                                                               is_verbose);
    checker_str* str_check = new checker_str(test_report, is_verbose);
    //-----------------------------------------------------
    char* buffer1_for_tests = new char[BUFFER_SIZE_IN_BYTE];
    char* buffer2_for_tests = new char[BUFFER_SIZE_IN_BYTE];
    char* buffer3_for_edf = new char[BUFFER_SIZE_IN_BYTE];
    //-----------------------------------------------------
    linked_list* globalSuite = new linked_list();

    // register tests
    globalSuite->append((void*) new tests_utils_linked_list("tests_utils_linked_list", int_check));
    globalSuite->append((void*) new tests_utils_linked_list_char("tests_utils_linked_list_char",
                                                                 str_check,
                                                                 int_check));
    globalSuite->append((void*) new tests_utils_linked_list_json("tests_utils_linked_list_json",
                                                                 int_to_str,
                                                                 str_check,
                                                                 int_check,
                                                                 json_item_check,
                                                                 json_to_str));
    globalSuite->append((void*) new tests_encoder_default("tests_encoder_default",
                                                          buffer1_for_tests,
                                                          BUFFER_SIZE_IN_BYTE,
                                                          bool_check,
                                                          str_check));
    globalSuite->append((void*) new tests_uri_encoder("tests_uri_encoder", buffer1_for_tests,
    BUFFER_SIZE_IN_BYTE,
                                                      int_check, str_check));
    globalSuite->append((void*) new tests_uri_post_request("tests_post_request_encoder",
                                                           buffer1_for_tests,
                                                           BUFFER_SIZE_IN_BYTE,
                                                           buffer2_for_tests,
                                                           BUFFER_SIZE_IN_BYTE,
                                                           bool_check,
                                                           str_check));
    globalSuite->append((void*) new tests_edf_controller("tests_edf_controller",
                                                         buffer3_for_edf,
                                                         BUFFER_SIZE_IN_BYTE,
                                                         buffer1_for_tests,
                                                         BUFFER_SIZE_IN_BYTE,
                                                         buffer2_for_tests,
                                                         BUFFER_SIZE_IN_BYTE,
                                                         str_check));

    // run all tests
    const unsigned int nb_tests = globalSuite->nb_elem();
    test* aTest = NULL;
    for (unsigned int index = 1; index <= nb_tests; index++) {
        aTest = (test*) globalSuite->get(index);
        test_report->start(aTest->name());
        aTest->run();
        test_report->end(aTest->name());
        delete (aTest);
    }
}

#ifdef __cplusplus
}
#endif
