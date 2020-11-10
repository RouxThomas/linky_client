#ifndef CHECKER_JSON_ELEMENT_H_
#define CHECKER_JSON_ELEMENT_H_

#include "checker.h"
#include "test_reporter.h"
#include "json_item_to_string.h"
#include "linked_list_json.h"

class checker_json_item: public checker {
public:

	checker_json_item(json_item_to_string* json_item_to_str,
			test_reporter* test_report, bool isVerbose);
	// PRE  : not null inputs
	// POST : N/A

	void json_item_are_equals(linked_list_json::json_item* expected,
			linked_list_json::json_item* computed, char* msg);
	// PRE  : not null inputs
	// POST : if the test is KO, the log is written via test_reporter

private:

	json_item_to_string* json_item_to_str;
	bool compare(void* a, void* b);
	void to_string(char* destination, void* a);
};

#endif
