
#include <stdio.h>
#include <string.h>

#include "json_item_to_string.h"
#include "linked_list_json.h"

void json_item_to_string::to_str(char* destination, void* elem)
{
	linked_list_json::json_item* item = (linked_list_json::json_item*)elem;
	char header[] = "{ element : ";
	strcpy(destination, header);
	item->formatter->to_str(destination + strlen(destination), item->element);
	strcat(destination, ", formatter : ");
	item->formatter->type(destination + strlen(destination));
	strcat(destination, " }");
};

void json_item_to_string:: type(char* destination)
{
	strcpy(destination, "json");
}
