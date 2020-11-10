
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>

#include "checker_str.h"

checker_str::checker_str(test_reporter* test_report, bool isVerbose) : checker(test_report, isVerbose)
{
}

bool checker_str::compare(void* a, void* b)
{
	return strcmp((char*)a, (char*)b) == 0 ? true : false;
}

void checker_str::to_string(char* destination , void* a)
{

	strcpy(destination, (char*)a);
}

void checker_str::str_are_equals(char* expected, char* computed, char* msg)
{
	this->are_equals((void*)expected, (void*)computed, msg);
}
