
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>

#include "checker_bool.h"

checker_bool::checker_bool(bool_to_string* bool_to_str, test_reporter* test_report, bool isVerbose) : checker(test_report, isVerbose)
{
	assert(bool_to_str != NULL);
	this->bool_to_str = bool_to_str;
}

bool checker_bool::compare(void* a, void* b)
{
	return (*(bool*)a==*(bool*)b) ? true : false ;
}

void checker_bool::to_string(char* destination , void* a)
{
	this->bool_to_str->to_str(destination, a);
}

void checker_bool::bool_are_equals(bool expected, bool computed, char* msg)
{
	this->are_equals((void*)&expected, (void*)&computed, msg);
}
