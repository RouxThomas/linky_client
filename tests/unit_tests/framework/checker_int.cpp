
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>

#include "checker_int.h"

checker_int::checker_int(int_to_string* int_to_str, test_reporter* test_report, bool isVerbose) : checker(test_report, isVerbose)
{
	assert(int_to_str != NULL);
	this->int_to_str = int_to_str;
}

bool checker_int::compare(void* a, void* b)
{
	return (*(int*)a==*(int*)b) ? true : false ;
}

void checker_int::to_string(char* destination , void* a)
{
	this->int_to_str->to_str(destination, a);
}

void checker_int::int_are_equals(int expected, int computed, char* msg)
{
	this->are_equals((void*)&expected, (void*)&computed, msg);
}
