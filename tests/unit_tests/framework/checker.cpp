
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include "checker.h"

checker::checker(test_reporter* test_report, bool is_verbose)
{
   assert(test_report != NULL);
   this->is_verbose = is_verbose;
   this->test_report = test_report;
}

void checker::msg_formatter(void* expected, void* computed, char* msg)
{
	strcpy(this->global_buffer, msg);

	strcat(this->global_buffer, ", expected = ");
	this->to_string(this->to_string_buffer, expected);
	strcat(this->global_buffer, this->to_string_buffer);

	strcat(this->global_buffer, ", computed = ");
	this->to_string(this->to_string_buffer, computed);
	strcat(this->global_buffer, this->to_string_buffer);
}

void checker::are_equals(void* expected,
					     void* computed,
					     char* msg)
{
	assert(expected != NULL && computed != NULL && msg);

	if(!this->compare(expected, computed))
	{
		this->msg_formatter(expected, computed, msg);
		this->test_report->addFailure(this->global_buffer);
	}
	else if (this->is_verbose)
	{
		this->msg_formatter(expected, computed, msg);
		this->test_report->log(this->global_buffer);
	}
}

