
#include <stdio.h>
#include <string.h>
#include "int_to_string.h"

void int_to_string::to_str(char* destination, void* elem)
{
	snprintf(destination, 10, "%d", *(int*)elem);
};


void int_to_string:: type(char* destination)
{
	strcpy(destination, "int");
}
