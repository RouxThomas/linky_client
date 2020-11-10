
#include <stdlib.h>
#include <stdio.h>
#include "linked_list_char.h"

linked_list_char::linked_list_char()
{
   this->list = new linked_list();
}

unsigned int linked_list_char::nb_elem()
{
	return this->list->nb_elem();
}

void linked_list_char::append(char* elem)
{
	this->list->append((void*)elem);
}

char* linked_list_char::get(unsigned int index)
{
	return (char*)this->list->get(index);
}

void linked_list_char::insert_before(unsigned int index, char* elem)
{
	this->list->insert_before(index, (void*) elem);
}

void linked_list_char::remove(unsigned int index)
{
	this->list->remove(index);
}
