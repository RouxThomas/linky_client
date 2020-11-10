
#include <stdio.h>
#include <string.h>
#include "bool_to_string.h"

void bool_to_string::to_str(char* destination, void* elem)
{
	snprintf(destination, 6, "%s", *(bool*)elem ? "true" : "false");
};


void bool_to_string:: type(char* destination)
{
	strcpy(destination, "bool");
}
