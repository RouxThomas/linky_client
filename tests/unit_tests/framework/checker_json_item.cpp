#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <string.h>

#include "checker_json_item.h"

checker_json_item::checker_json_item(json_item_to_string* json_item_to_str,
		test_reporter* test_report, bool isVerbose) :
		checker(test_report, isVerbose) {
	assert(json_item_to_str != NULL);
	this->json_item_to_str = json_item_to_str;
}

bool checker_json_item::compare(void* a, void* b) {
	char str_a[70];
	char str_b[70];

	this->json_item_to_str->to_str(str_a, a);
	this->json_item_to_str->to_str(str_b, b);

	return strcmp(str_a, str_b) == 0;
}

void checker_json_item::to_string(char* destination, void* a) {
	this->json_item_to_str->to_str(destination, a);
}

void checker_json_item::json_item_are_equals(
		linked_list_json::json_item* expected,
		linked_list_json::json_item* computed, char* msg) {
	this->are_equals((void*) expected, (void*) computed, msg);
}
