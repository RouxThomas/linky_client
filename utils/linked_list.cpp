
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "linked_list.h"

linked_list::linked_list()
{
   this->first_node = NULL;
}

unsigned int linked_list::nb_elem()
{
   unsigned int nb_elem = 0;
   Node* node = this->first_node;
   while(node != NULL)
   {
      nb_elem++;
      node = node->next;
   };
   return nb_elem;
}

linked_list::Node* linked_list::getNode(unsigned int index)
{
   assert(index > 0 && index <= this->nb_elem());

   Node* node = this->first_node;
   for (unsigned int i=2; i <= index ; i++) {
      node = node->next;
   }
   return node;
}

void linked_list::append(void* elem)
{
   Node* lastNode = NULL;
   Node* newNode = new Node;
   newNode->next = NULL;
   newNode->elem = elem;

   if(this->nb_elem() == 0) {
      this->first_node = newNode;
   }
   else {
     lastNode = (Node*) this->getNode(this->nb_elem());
     lastNode->next = newNode;
   }   
}

void* linked_list::get(unsigned int index)
{
	assert(index > 0 && index <= this->nb_elem());
	return this->getNode(index)->elem;
}

void linked_list::insert_before(unsigned int index, void* elem)
{
	assert(index > 0 && index <= this->nb_elem());

	Node* newNode = new Node;
	newNode->elem = elem;

	if (index == 1)	{
		newNode->next = this->first_node;
		this->first_node = newNode;
	}
	else {
		Node* nodeBefore = (Node*) this->getNode(index-1);
		newNode->next = nodeBefore->next;
		nodeBefore->next = newNode;
	}
}

void linked_list::remove(unsigned int index)
{
	const unsigned int nb_elem = this->nb_elem();
	assert(nb_elem > 0 && index > 0 && index <= nb_elem);

	if (index == 1)	{
		this->first_node = this->first_node->next;
		//delete toRemove; not supported by avr-g++
	}
	else {
		Node* nodeBefore = (Node*) this->getNode(index-1);
		nodeBefore->next = nodeBefore->next->next;
		//delete toRemove; not supported by avr-g++
	}

}
