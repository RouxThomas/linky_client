
#include "linked_list_json.h"

linked_list_json::linked_list_json()
{
   this->list = new linked_list();
}

unsigned int linked_list_json::nb_elem()
{
	return this->list->nb_elem();
}

void linked_list_json::append(json_item* elem)
{
	this->list->append((void*)elem);
}

char* linked_list_json::get(unsigned int index)
{
	return (char*)this->list->get(index);
}

void linked_list_json::insert_before(unsigned int index, json_item* elem)
{
	this->list->insert_before(index, (void*) elem);
}

void linked_list_json::remove(unsigned int index)
{
	this->list->remove(index);
}
